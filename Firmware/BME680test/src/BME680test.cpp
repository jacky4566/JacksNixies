/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#line 1 "c:/Users/jwiebe/OneDrive/CiruitProjects/JacksNixies/Firmware/BME680test/src/BME680test.ino"
#include "Particle.h"
#include "bme680.h"

void setup();
void loop();
#line 4 "c:/Users/jwiebe/OneDrive/CiruitProjects/JacksNixies/Firmware/BME680test/src/BME680test.ino"
SYSTEM_THREAD(ENABLED);

bme680 sensor(A2);

void setup() {
  Serial.begin(9600);
  delay(5000);
  Serial.println(sensor.begin());
  sensor.printCalib();
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  /*
  Serial.println();
  Serial.print("Time "); Serial.println(millis());
  sensor.performReading();
  Serial.print("Temp "); Serial.println(sensor.temperature);
  delay(3000);
  */
}