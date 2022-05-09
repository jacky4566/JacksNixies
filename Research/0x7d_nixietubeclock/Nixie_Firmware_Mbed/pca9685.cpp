#include "mbed.h"
#include "main.h"
#include "pca9685.h"

DigitalOut PCA9685_PWM_nEN(PA_7);
DigitalOut PCA9685_VIN_EN(PB_1);
AnalogOut  PCA9685_VIN(PA_5);

void PCA9685_Init(void) {
    PCA9685_REGS regs = {0};
    
    // Power up PCA9685 at full voltage with outputs disabled
    PCA9685_VIN.write(1);
    PCA9685_VIN_EN.write(1);
    PCA9685_PWM_nEN.write(1);

    regs.MODE1.AI = 1;         // Turn on autoincrement
    regs.MODE1.SLEEP = 1;      // Start disabled
    regs.MODE1.ALLCALL = 1;    // Enable response to all call address
    
    regs.MODE2.OUTDRV = 1;     // Configure output for totem pole drive
    
    I2C_Write(PCA9685_All_Call, FIELD_OFFSET(PCA9685_REGS, MODE1), 
        regs.AS_BYTE + FIELD_OFFSET(PCA9685_REGS, MODE1),
        FIELD_SIZE_THROUGH(PCA9685_REGS, MODE1, MODE2));
    
    regs.PRE_SCALE = 0x03;      // Set PWM frequency to 1526Hz

    I2C_Write(PCA9685_All_Call, FIELD_OFFSET(PCA9685_REGS, PRE_SCALE), 
        regs.AS_BYTE + FIELD_OFFSET(PCA9685_REGS, PRE_SCALE),
        FIELD_SIZE_THROUGH(PCA9685_REGS, PRE_SCALE, PRE_SCALE));
    
    PCA9685_SetDot(0);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            PCA9685_SetDigit(i, j, 0);
        }
    }
    
    regs.MODE1.SLEEP = 0;       // Re-enable outputs
    
    I2C_Write(PCA9685_All_Call, FIELD_OFFSET(PCA9685_REGS, MODE1), 
        regs.AS_BYTE + FIELD_OFFSET(PCA9685_REGS, MODE1),
        FIELD_SIZE_THROUGH(PCA9685_REGS, MODE1, MODE1));

    // Enable outputs after configuration has been completed
    PCA9685_PWM_nEN.write(0);
}

void PCA9685_SetVoltage(float Percent) {
    Percent = Percent * 0.6;
    PCA9685_VIN.write(Percent);
}

void PCA9685_SetDigit(int Tube, int Digit, int Brightness) {
    LED_CTRL reg = {0};

    if (Brightness >= PCA9685_Max_Brightness) {
        reg.ON_FULL = 1;
    } else if (Brightness == 0) {
        reg.OFF_FULL = 1;
    } else {
        reg.OFF = Brightness;
    }

    I2C_Write(Tube_Mapping[Tube][Digit][MAP_ADDR],
        FIELD_OFFSET(PCA9685_REGS, LED0) + (Tube_Mapping[Tube][Digit][MAP_PIN] * sizeof(LED_CTRL)),
        reg.AS_BYTE, sizeof(LED_CTRL));
}

void PCA9685_SetDot(int Brightness) {
    LED_CTRL reg = {0};

    if (Brightness >= PCA9685_Max_Brightness) {
        reg.ON_FULL = 1;
    } else if (Brightness == 0) {
        reg.OFF_FULL = 1;
    } else {
        reg.OFF = Brightness;
    }

    I2C_Write(TUBE_DOT_ADDR, FIELD_OFFSET(PCA9685_REGS, TUBE_DOT_PIN), reg.AS_BYTE, sizeof(LED_CTRL));
}

void PCA9685_EnableOutput(bool Enabled) {
    if (Enabled) {
        PCA9685_PWM_nEN.write(0);
    } else {
        PCA9685_PWM_nEN.write(1);
    }
}
