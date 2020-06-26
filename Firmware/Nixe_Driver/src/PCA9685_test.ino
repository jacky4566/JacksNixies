#include "Particle.h"
#include "Wire.h"
#include "nixie_driver.h"
#include "neopixel.h"

SYSTEM_THREAD(ENABLED);

nixie_driver myDriver;

const int boostEN = TX;

#define PIXEL_TYPE SK6812RGBW
const int PIXEL_PIN = D2;
const int PIXEL_COUNT = 4; 
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup() {
  strip.begin();
    for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);
  pinMode(boostEN, OUTPUT);
  myDriver.init();
  digitalWrite(boostEN, HIGH);
}

void loop() {
if (0){
    myDriver.setTube(3, 1, 3000);
    delay(1000);
    myDriver.setTube(3, 2, 3000);
    delay(1000);
 }else{
    for (int i = 0 ; i < 10 ; i++){
      myDriver.setTube(0, i, 3000);
      myDriver.setTube(1, i, 3000);
      myDriver.setTube(2, i, 3000);
      myDriver.setTube(3, i, 3000);
      delay(1000);
    }
  } 
}
