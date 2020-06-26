#include "Particle.h"
#include "bme680.h"

SYSTEM_THREAD(ENABLED);

bme680 sensor(A2);

void setup() {
  Serial.begin(9600);
  delay(3000);
  Serial.println(sensor.begin());
  sensor.printCalib();
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  Serial.println();
  Serial.print("Time "); Serial.println(millis());
  sensor.performReading();
  Serial.print("Temperature "); Serial.println(sensor.temperature);
  Serial.print("Hummidity "); Serial.println(sensor.humidity);
  Serial.print("Pressure "); Serial.println(sensor.pressure);
  delay(3000);
}