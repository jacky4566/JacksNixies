#include "Particle.h"
#include "Wire.h"
#include "nixie_driver.h"
#include "elapsedMillis.h"
#include "neopixel.h"

//Particle Mode
SYSTEM_THREAD(ENABLED);

//Nixies
nixie_driver myNixieDriver;
const int fadetime = 10000;
const int boostEN = 19;

//Neopixels
#define NUM_LEDS    4       // how many leds are being adderessed 
Adafruit_NeoPixel strip(NUM_LEDS, D2, SK6812RGBW);

void setup() {
  Serial.begin(9600);
  pinMode(boostEN, OUTPUT);
  //WiFi.setCredentials("MeszarosShaw", "MasterCraftx7");
  delay(10);
  //turn off status LED for LED_SIGNAL_CLOUD_CONNECTED
  LEDSystemTheme theme;
  theme.setColor(LED_SIGNAL_CLOUD_CONNECTED, 0);
  theme.apply();
  //LED Stuff
  strip.begin();
  for(int k = 0 ; k < strip.numPixels() ; k ++) {
    strip.setPixelColor(k, 0,0,0,0);//default colour
    strip.show(); // Initialize all pixels to 'off'
  }
  //Time
  waitFor(Time.isValid, 60000);
  timeZoneUpdate();
  //startup
  myNixieDriver.init();
  //scrambleDigits();
  //rainbowFade2White(3,4,1);
  //printTime();


}

void loop() {
  Particle.process();
  timeZoneUpdate();
  if (Time.minute() == 59 && Time.second() == (60 - fadetime / 2000)){ //top of the hour
    scrambleDigits();
    printTime();
  }else if (Time.second() == (60 - fadetime / 2000) && !goDark()){ //on the minute
    printTime();
  }
  nixieFlame(1);
}

void timeZoneUpdate(){
  static uint32_t zoneTimer = 0;
  if (millis() > zoneTimer){ 
    if ((Time.month() < 3) || ((Time.month() == 3) && (Time.day() <= 8)) || (Time.month() > 11) || ((Time.month() == 11) && (Time.day() >= 1))){ //daylight savings in effect
      Time.zone(-7);
    }
    else{
      Time.zone(-6);
    }
    zoneTimer = millis() + (1 * 60 * 60 * 1000);
  }
}

boolean goDark(){
  static boolean returnValue = false;
  static uint32_t darkTimer = 0;
  if (millis() > darkTimer){ //look for my computer
    const IPAddress jacksonIP(192,168,0,69);
    if (WiFi.ping(jacksonIP, 1) == 0){
      if (Time.hour() < 7 || Time.hour() >= 22){ //else use a time based backup
        returnValue = true;
      }else {
        returnValue = false;
      }
    }else {
      returnValue = false;
    }
    darkTimer = millis() + 10000;
  }
  return returnValue;
}

float photoDiode(){
  const int photoDiodePin = A0;
  const int photoDiodeMax = 3820; //raw analog values, dimmest value, varies per device
  const int photoDiodeMin = 3700; //raw analog values, brightest value, varies per device
  const float bias = 0.05;
  static uint32_t timer = 0;
  static uint32_t pubishTimer = 0;
  static float photoDiodeValue = 0.5;
  if (millis() > timer){
    photoDiodeValue = ((float)map(constrain(analogRead(photoDiodePin), photoDiodeMin, photoDiodeMax), photoDiodeMax, photoDiodeMin, 8, 100) / 100.0) * bias + (photoDiodeValue * (1.0-bias));
    timer = millis() + 100;
  }
  if (millis() > pubishTimer && false){
    String line;
    line.concat(photoDiodeValue);
    line.concat("%, RAW:");
    line.concat(analogRead(photoDiodePin));
    Particle.publish("photoDiode", line, PRIVATE);
    pubishTimer = millis() + 1000;
  }
  return photoDiodeValue;
}

void printTime(){
  #define PI 3.1415926535897932384626433832795
  #define mathE 2.71828
  elapsedMillis timeElapsed;
  nixieFlame(0);
  digitalWrite(boostEN, HIGH);
  //Fade ON
  while (timeElapsed < fadetime / 2){
    //float pulseval = 4096.0 * sin((float)timeElapsed / (float)fadetime * PI); //regular sin wave
    float pulseval = 2384.0 * (pow(mathE,sin((float)timeElapsed / (float)fadetime * PI)) - 1); //better "breathing" wave
    myNixieDriver.setTube(0, myNixieDriver.getTubevalue(0), (int)pulseval);
    myNixieDriver.setTube(1, myNixieDriver.getTubevalue(1), (int)pulseval);
    myNixieDriver.setTube(2, myNixieDriver.getTubevalue(2), (int)pulseval);
    myNixieDriver.setTube(3, myNixieDriver.getTubevalue(3), (int)pulseval);
    Particle.process();
  }
  //Fade OFF
  while (timeElapsed < fadetime){
    //float pulseval = 4096.0 * sin((float)timeElapsed / (float)fadetime * PI); //regular sin wave
    float pulseval = 2384.0 * (pow(mathE,sin((float)timeElapsed / (float)fadetime * PI)) - 1); //better "breathing" wave
    myNixieDriver.setTube(0, Time.hour() / 10, (int)pulseval);
    myNixieDriver.setTube(1, Time.hour() % 10, (int)pulseval);
    myNixieDriver.setTube(2, Time.minute() / 10, (int)pulseval);
    myNixieDriver.setTube(3, Time.minute() % 10, (int)pulseval);
    Particle.process();
  }
  digitalWrite(boostEN, LOW);
  delay(500);
  for(float i = 0; i < photoDiode(); i = i + 0.001) {
      nixieFlame(i);
      delay(10);
  }
}

void nixieDefault(float dimmer){
  if (goDark()){
    for(int k = 0 ; k < strip.numPixels() ; k ++) {
      strip.setPixelColor(k, 0,0,0,0);//default colour
    }
  }else{
    if (dimmer == 1.0){dimmer = photoDiode();}
    //float pulseval = (exp(sin(millis() / 4000.0 * PI)) - 0.36787944)*108.0;
    strip.setBrightness(dimmer * 255.0);
    float pulseval =(sin((millis()/12000.0)*PI)+1)*127.5;
    for(int k = 0 ; k < strip.numPixels() ; k ++) {
      uint32_t newColor = Wheel((byte)(pulseval + (k * 9)) & 0xff);
      strip.setPixelColor(k, newColor);
    }
  }
  strip.show();
}

void nixieFlame(float dimmer){
  static uint32_t flameUpdate = 0;
  static int heatTarget[NUM_LEDS];
  static int heatmap[NUM_LEDS];
  if (goDark()){
    for(int k = 0 ; k < strip.numPixels() ; k ++) {
      strip.setPixelColor(k, 0,0,0,0);//default colour
    }
  }else{
    if (dimmer == 1.0){dimmer = photoDiode();}
    if (flameUpdate < millis()){
      for ( int j = 0; j < NUM_LEDS; j++) {

        //set new target
        if (abs(heatmap[j] - heatTarget[j]) < 2){
          heatTarget[j] = random(0,255);
        }

        if(heatmap[j] < heatTarget[j]){
          heatmap[j] = heatmap[j] + random(0, 6);
        }else{
          heatmap[j] = heatmap[j] - random(0, 6);
        }

        byte newHeat = constrain(heatmap[j], 0, 255);
        strip.setPixelColor(j, strip.Color(newHeat/12,newHeat, 0 ,0));//Candle effect
        //strip.setPixelColor(j, Wheel(newHeat));//rando rainbow
      }
      flameUpdate = millis() + 30;
    }
  }
  strip.show();
}

void cycleDigits(){
  digitalWrite(boostEN, HIGH);
  int i = 0;
  for (; i <= 9; i++){
    myNixieDriver.setTube(3, i, 4096);
    myNixieDriver.setTube(2, i, 4096);
    myNixieDriver.setTube(1, i, 4096);
    myNixieDriver.setTube(0, i, 4096);
    delay(200);
  }
  digitalWrite(boostEN, LOW);
}

void scrambleDigits(){
  elapsedMillis timeElapsed;
  nixieFlame(0);
  digitalWrite(boostEN, HIGH);
  for(int i = 0; i < 24; i++) {
    myNixieDriver.setTube(0, random(0, 10), 4096);
    delay(random(5,80));
    myNixieDriver.setTube(1, random(0, 10), 4096);
    delay(random(5,80));
    myNixieDriver.setTube(2, random(0, 10), 4096);
    delay(random(5,80));
    myNixieDriver.setTube(3, random(0, 10), 4096);
    delay(random(5,80));
  }
  digitalWrite(boostEN, LOW);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3,0);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3,0);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0,0);
}

uint8_t red(uint32_t c) {
  return (c >> 8);
}
uint8_t green(uint32_t c) {
  return (c >> 16);
}
uint8_t blue(uint32_t c) {
  return (c);
}


void rainbowFade2White(uint8_t wait, int rainbowLoops, int whiteLoops) {
  const int gammatable[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };
  float fadeMax = 100.0;
  int fadeVal = 0;
  uint32_t wheelVal;
  int redVal, greenVal, blueVal;

  for(int k = 0 ; k < rainbowLoops ; k ++) {
    for(int j=0; j<256; j++) { // 5 cycles of all colors on wheel
      for(int i=0; i< strip.numPixels(); i++) {
        wheelVal = Wheel(((i * 256 / strip.numPixels()) + j) & 255);

        redVal = red(wheelVal) * float(fadeVal/fadeMax);
        greenVal = green(wheelVal) * float(fadeVal/fadeMax);
        blueVal = blue(wheelVal) * float(fadeVal/fadeMax);

        strip.setPixelColor( i, strip.Color( redVal, greenVal, blueVal ) );
      }

      // First loop, fade in!
      if(k == 0 && fadeVal < fadeMax-1) {
        fadeVal++;
      }
      // Last loop, fade out!
      else if(k == rainbowLoops - 1 && j > 255 - fadeMax ) {
        fadeVal--;
      }

      strip.show();
      delay(wait);
    }
  }

  for(int k = 0 ; k < whiteLoops ; k ++) {
    for(int j = 0; j < 256 ; j++) {
      for(uint16_t i=0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(0,0,0, gammatable[j] ) );
      }
      delay(wait);
      strip.show();
    }

    for(int j = 255; j >= 0 ; j--) {
      for(uint16_t i=0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(0,0,0, gammatable[j] ) );
      }
      delay(wait);
      strip.show();
    }
  }
}