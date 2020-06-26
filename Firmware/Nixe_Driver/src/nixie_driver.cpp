#include "nixie_driver.h"
#include "Wire.h"
#include <stdint.h>

void nixie_driver::init() {
	byte datatowrite;
    Wire.setSpeed(CLOCK_SPEED_400KHZ); //go faster!
    Wire.begin();
	
    // Auto-Increment, Sleep, Enable all call
	Wire.beginTransmission(PCA9685_All_Call);
    datatowrite = 0x31; 
	Wire.write((byte)offsetof(PCA9685_REGS, MODE1)); //address
	Wire.write(datatowrite); //data
	Wire.endTransmission(); 

    // Set PWM frequency to 1526Hz
	Wire.beginTransmission(PCA9685_All_Call);
    datatowrite = 0x03; 
	Wire.write((byte)offsetof(PCA9685_REGS, PRE_SCALE)); //address
	Wire.write(datatowrite); //data
    Wire.endTransmission();

    // Auto-Increment, Sleep OFF, Enable all call
	Wire.beginTransmission(PCA9685_All_Call);
    datatowrite = 0x21; 
	Wire.write((byte)offsetof(PCA9685_REGS, MODE1)); //address
	Wire.write(datatowrite); //data
    Wire.endTransmission();
}

void nixie_driver::setTube(int Tube, int Digit, int Brightness) {
    if (currentTubeValue[Tube] != Digit){//if new tube does not match old tube. clear it old value. 
        clearTube(Tube);
    }
    LED_CTRL targetDigit = {0};
    if (Brightness >= PCA9685_Max_Brightness) {
        targetDigit.ON_FULL = 1;
    } else if (Brightness == 0) {
        targetDigit.OFF_FULL = 1;
    } else {
        targetDigit.OFF = Brightness & 0x0fff;
    }
	Wire.beginTransmission(Tube_Mapping[Tube][Digit][MAP_ADDR]);
	Wire.write((byte)(offsetof(PCA9685_REGS, LED0) + (Tube_Mapping[Tube][Digit][MAP_PIN] * sizeof(LED_CTRL) ) ) );
	Wire.write(targetDigit.AS_BYTE, (byte)sizeof(targetDigit));
	Wire.endTransmission();
	currentTubeValue[Tube] = Digit;
}

void nixie_driver::clearTube(int Tube){
	LED_CTRL targetDigit = {0};
    targetDigit.OFF_FULL = 1;
	Wire.beginTransmission(Tube_Mapping[Tube][currentTubeValue[Tube]][MAP_ADDR]);
	Wire.write((byte)(offsetof(PCA9685_REGS, LED0) + (Tube_Mapping[Tube][currentTubeValue[Tube]][MAP_PIN] * sizeof(LED_CTRL) ) ) );
	Wire.write(targetDigit.AS_BYTE, (byte)sizeof(targetDigit));
	Wire.endTransmission();
}

void nixie_driver::ledWriter(int addr, int led, int Brightness){
    LED_CTRL targetDigit = {0};

    if (Brightness >= PCA9685_Max_Brightness) {
        targetDigit.ON_FULL = 1;
    } else if (Brightness == 0) {
        targetDigit.OFF_FULL = 1;
    } else {
        targetDigit.OFF = Brightness;
    }

    Wire.beginTransmission(addr);
	Wire.write((byte)(offsetof(PCA9685_REGS, LED0) + (led * sizeof(LED_CTRL) ) ) );
	Wire.write(targetDigit.AS_BYTE, (byte)sizeof(targetDigit));
	Wire.endTransmission();
}

int nixie_driver::getTubevalue(int Tube){
	return currentTubeValue[Tube];
}