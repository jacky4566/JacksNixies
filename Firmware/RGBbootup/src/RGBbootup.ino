#include "Particle.h"
#include "neopixel.h"
#include "math.h"
#define PI 3.1415926535897932

SYSTEM_THREAD(ENABLED);

#define PIXEL_TYPE SK6812RGBW
const int PIXEL_PIN = D2;
const int PIXEL_COUNT = 4;
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

uint32_t targetcolor;

void setup() {
  strip.begin();
  strip.show();
  targetcolor = strip.Color(30,255,0,0);
  startColor(targetcolor, 255); //fade in to orange at target brightness
  //Green, Red, Blue
}

void loop() {
  breathingCode();
}

void startColor(uint32_t c, int targetbrightness) {
  for(int j = 0; j <= targetbrightness; j++){
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.setBrightness(j);
      strip.show();
    }
    delay(16);
  }
}

void breathingCode(){
  float pulseval = (exp(sin(millis()/4000.0*PI)) - 0.36787944)*108.0;
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, targetcolor);
  }
  strip.setBrightness((uint8_t)pulseval);
  strip.show();
}

