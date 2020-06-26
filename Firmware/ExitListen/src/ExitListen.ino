#include "Particle.h"
#include "dct.h"

SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() {
  WiFi.on();
  WiFi.listen(false);
  WiFi.setCredentials("MeszarosShaw", "MasterCraftx7");
  Particle.connect();
}

void loop() {

}