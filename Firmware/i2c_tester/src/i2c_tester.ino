SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

//tried 43



void setup() {
  pinMode(TX, OUTPUT);
  Serial.begin(9600);
  delay(5000);
  Serial.println("ready");
  Wire.setSpeed(CLOCK_SPEED_400KHZ);
  Wire.begin();
  digitalWrite(TX, HIGH);

  int addr = 0x41;
  for (;addr <= 0x43; addr++){
    Serial.print("Addressing: 0x");Serial.println(addr, HEX);
    Serial.flush();
    Wire.beginTransmission(addr);
    Wire.write(0xFE); //request address
    Wire.write(0x03); //write data
    Wire.endTransmission(); 
    delay(1);//wait

    Wire.beginTransmission(addr);
    Wire.write(0x00); //request address
    Wire.write(0x00); //write data
    Wire.endTransmission(); 
    delay(1);//wait

    int LED = 0;
    for (int digit = 0x09; digit <= 0x45; digit = digit + 4){
      if (LED <=9){Serial.print("0");}
      Serial.print(LED); Serial.print(":0x"); Serial.println(digit, HEX);
      Wire.beginTransmission(addr);
      Wire.write(digit); //request address
      Wire.write(0x0f); //write data
      Wire.endTransmission(); 
      delay(500);
      Wire.beginTransmission(addr);
      Wire.write(digit); //request address
      Wire.write(0x10); //Digit off
      Wire.endTransmission(); 
      LED++;
    }
  }

  digitalWrite(TX, LOW);

  Serial.println("DONE");
  delay(1);//wait
  System.dfu();
}

void loop() {

}
