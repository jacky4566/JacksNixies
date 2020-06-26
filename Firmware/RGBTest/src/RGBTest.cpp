/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#line 1 "c:/Users/jwiebe/OneDrive/CiruitProjects/JacksNixies/Firmware/RGBTest/src/RGBTest.ino"
#include "Particle.h"
#include "neopixel.h"
#include "math.h"

void setup();
void loop();
uint8_t red(uint32_t c);
uint8_t green(uint32_t c);
uint8_t blue(uint32_t c);
void colorWipe(uint32_t c, uint8_t wait);
void pulseWhite(uint8_t timer);
void whiteOverRainbow(uint8_t wait, uint8_t whiteSpeed, uint8_t whiteLength );
void fullWhite();
void rainbowCycle(uint8_t wait);
#line 5 "c:/Users/jwiebe/OneDrive/CiruitProjects/JacksNixies/Firmware/RGBTest/src/RGBTest.ino"
SYSTEM_THREAD(ENABLED);

#define PIXEL_TYPE SK6812RGBW
#define PI 3.1415926535897932384626433832795
const int PIXEL_PIN = D2;
const int PIXEL_COUNT = 4;  

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// Prototypes for local build, ok to leave in for Build IDE
void rainbow(uint8_t wait);
uint32_t Wheel(byte WheelPos);

void setup() {
  strip.setBrightness(50);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Some example procedures showing how to display to the pixels:
  // Do not run more than 15 seconds of these, or the b/g tasks
  // will be blocked.
  // --------------------------------------------------------------
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
  colorWipe(strip.Color(0, 0, 0, 255), 50); // White

  whiteOverRainbow(20,75,5);

  pulseWhite(5000);

  // fullWhite();
  // delay(2000);
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

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void pulseWhite(uint8_t timer) {
  uint32_t start = millis();
  do{
    for(int j = 0; j < 256 ; j++) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        float pulseval = (exp(sin(millis()/2000.0*PI)) - 0.36787944)*108.0;
        strip.setPixelColor(i, strip.Color(0,0,0, (uint8_t)pulseval ) );
      }
      strip.show();
    }
  }while(millis() < start + timer);
}

void whiteOverRainbow(uint8_t wait, uint8_t whiteSpeed, uint8_t whiteLength ) {

  if(whiteLength >= strip.numPixels()) whiteLength = strip.numPixels() - 1;

  int head = whiteLength - 1;
  int tail = 0;
  int loops = 3;
  int loopNum = 0;
  static unsigned long lastTime = 0;

  while(true) {
    for(int j=0; j<256; j++) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
        if( (i >= tail && i <= head)
          || (tail > head && i >= tail)
          || (tail > head && i <= head) ) {
          strip.setPixelColor(i, strip.Color(0,0,0, 255 ) );
        } else {
          strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
        }
      }

      if(millis() - lastTime > whiteSpeed) {
        head++;
        tail++;
        if(head == strip.numPixels()) {
          loopNum++;
        }
        lastTime = millis();
      }

      if(loopNum == loops) return;

      head %= strip.numPixels();
      tail %= strip.numPixels();
      strip.show();
      delay(wait);
    }
  }

}

void fullWhite() {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0,0,0, 255 ) );
  }
  strip.show();
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256 * 5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

