#include "mbed.h"
#include "main.h"
#include "pca9685.h"
#include "animation.h"

void Animate_Cycle_Basic(int iterations) {

    PCA9685_SetVoltage(1.0);

    // Switch each digit from 0 to 100%
    for (int i = 0; i < iterations; i++) {
        if (i % 2 == 0) {
            PCA9685_SetDot(PCA9685_Min_Brightness);
        } else {
            PCA9685_SetDot(PCA9685_Max_Brightness);
        }
        
        for (int j = 0; j < 4; j++) {
            PCA9685_SetDigit(j, i, PCA9685_Max_Brightness);
        }      
        
        wait(0.5);
        
        for (int j = 0; j < 4; j++) {
            PCA9685_SetDigit(j, i, PCA9685_Min_Brightness);
        }
    }
}

void Animate_Cycle_Analog(int iterations) {

    for (int i = 0; i < iterations; i++) {
        
        PCA9685_EnableOutput(false);
        float minVoltage = 0.10;
        
        for (int j = 0; j < 4; j++) {    
            PCA9685_SetDigit(j, i, PCA9685_Max_Brightness);
            PCA9685_SetDot(PCA9685_Max_Brightness);
        }
        
        // Slowly drop the voltage to the minimum level
        for (double k = 1; k >= minVoltage; k -= 0.001) {
            PCA9685_SetVoltage(k);
            wait(0.001);
        }
        
        PCA9685_EnableOutput(true);
        
        for (double k = minVoltage; k <= 1; k += 0.0001) {
            PCA9685_SetVoltage(k);
            wait(0.0002);
        }
        for (double k = 1; k >= minVoltage; k -= 0.0001) {
            PCA9685_SetVoltage(k);
            wait(0.0002);
        }

        PCA9685_EnableOutput(false);

        // Slowly raise the voltage to the maximum level
        for (double k = minVoltage; k <= 1; k += 0.01) {
            PCA9685_SetVoltage(k);
            wait(0.001);
        }
        
        for (int j = 0; j < 4; j++) {
            PCA9685_SetDigit(j, i, PCA9685_Min_Brightness);
            PCA9685_SetDot(PCA9685_Min_Brightness);
        }
    }
        
    PCA9685_EnableOutput(true);
}

void Animate_Cycle_Low_Pwm(int iterations) {

    PCA9685_SetVoltage(1.0);
    PCA9685_SetDot(PCA9685_Min_Brightness);

    int pwmMaxBrightness = 300;
    for (int i = 0; i < iterations; i++) {
        for (int k = PCA9685_Min_Brightness; k <= pwmMaxBrightness; k++) {
            for (int j = 0; j < 4; j++) {
                PCA9685_SetDigit(j, i, k);
                PCA9685_SetDot(k);
            }
            wait(0.005);
        }      
        for (int k = PCA9685_Min_Brightness; k <= pwmMaxBrightness; k++) {
            for (int j = 0; j < 4; j++) {
                PCA9685_SetDigit(j, i, pwmMaxBrightness-k);
                PCA9685_SetDot(pwmMaxBrightness-k);;
            }
            wait(0.005);
        }      
        wait(0.2);
    }
}

void Animate_Cycle_Pwm(int iterations) {

    PCA9685_SetVoltage(1.0);
    PCA9685_SetDot(PCA9685_Min_Brightness);

    for (int i = 0; i < iterations; i++) {
        for (int k = PCA9685_Min_Brightness; k <= PCA9685_Max_Brightness; k += 4) {
            for (int j = 0; j < 4; j++) {
                PCA9685_SetDigit(j, i, k);
                PCA9685_SetDot(k);
            }
            wait(0.00001);
        }      
        for (int k = PCA9685_Min_Brightness; k <= PCA9685_Max_Brightness; k += 4) {
            for (int j = 0; j < 4; j++) {
                PCA9685_SetDigit(j, i, PCA9685_Max_Brightness-k);
                PCA9685_SetDot(PCA9685_Max_Brightness-k);;
            }
            wait(0.00001);
        }      
        wait(0.2);
    }
}

void Animate_Cycle_Fade(int iterations) {

    PCA9685_SetVoltage(1.0);
    PCA9685_SetDot(PCA9685_Min_Brightness);
    
    for (int k = PCA9685_Min_Brightness; k <= PCA9685_Max_Brightness; k += 4) {
        for (int j = 0; j < 4; j++) {
            PCA9685_SetDigit(j, 0, k);
        }
        wait(0.00001);
    }

    for (int i = 0; i < iterations; i++) {
        int i_next = (i == 9) ? 0 : i+1;
        for (int k = PCA9685_Min_Brightness; k <= PCA9685_Max_Brightness; k += 4) {
            for (int j = 0; j < 4; j++) {
                PCA9685_SetDigit(j, i, PCA9685_Max_Brightness-k);
                PCA9685_SetDigit(j, i_next, k);
            }
            if (i % 2 == 0) {
                PCA9685_SetDot(k);
            } else {
                PCA9685_SetDot(PCA9685_Max_Brightness-k);
            }
            wait(0.00005);
        }        
        wait(0.2);
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            PCA9685_SetDigit(i, j, PCA9685_Min_Brightness);
        }
    }
}

void Animate_Cycle_Fade_Random(int iterations) {

    int i_curr[4];
    int i_next[4];

    PCA9685_SetVoltage(1.0);
    PCA9685_SetDot(PCA9685_Min_Brightness);
    
    for (int i = 0; i < 4; i++) {
        i_curr[i] = rand() % 10;
    }
    
    for (int k = PCA9685_Min_Brightness; k <= PCA9685_Max_Brightness; k += 4) {
        for (int j = 0; j < 4; j++) {
            PCA9685_SetDigit(j, i_curr[j], k);
        }
        wait(0.00001);
    }
        
    for (int iter = 0; iter < iterations; iter++) {
        
        for (int i = 0; i < 4; i++) {
            do {
                i_next[i] = rand() % 10;
            } while (i_next[i] == i_curr[i]);
        }
        
        for (int k = PCA9685_Min_Brightness; k <= PCA9685_Max_Brightness; k += 4) {
            for (int j = 0; j < 4; j++) {
                PCA9685_SetDigit(j, i_curr[j], PCA9685_Max_Brightness-k);
                PCA9685_SetDigit(j, i_next[j], k);
            }
            if (iter % 2 == 0) {
                PCA9685_SetDot(k);
            } else {
                PCA9685_SetDot(PCA9685_Max_Brightness-k);
            }
            wait(0.00001);
        }
        wait(0.2);
        
        for (int i = 0; i < 4; i++) {
            i_curr[i] = i_next[i];
        }
    }
    for (int k = PCA9685_Max_Brightness; k >= PCA9685_Min_Brightness; k -= 4) {
        for (int j = 0; j < 4; j++) {
            PCA9685_SetDigit(j, i_curr[j], k);
        }
        wait(0.00001);
    }
}

void Animate_Cycle_Fast(int iterations) {

    PCA9685_SetVoltage(1.0);
    PCA9685_SetDot(PCA9685_Min_Brightness);

    for (int k = 0; k < iterations; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 4; j++) {
                PCA9685_SetDigit(j, i, PCA9685_Max_Brightness);
            }
            if (i % 2 == 0) {
                PCA9685_SetDot(PCA9685_Max_Brightness);
            } else {
                PCA9685_SetDot(PCA9685_Min_Brightness);
            }
            wait(0.1);
            for (int j = 0; j < 4; j++) {
                PCA9685_SetDigit(j, i, PCA9685_Min_Brightness);
            }
        }
    }
}

void Animate_Cycle_Fast_Random(int iterations) {

    int i_curr[4];
    int i_next[4];

    PCA9685_SetVoltage(1.0);
    PCA9685_SetDot(PCA9685_Min_Brightness);
    
    for (int i = 0; i < 4; i++) {
        i_curr[i] = rand() % 10;
    }

    for (int k = 0; k < iterations; k++) {
        
        for (int i = 0; i < 4; i++) {
            do {
                i_next[i] = rand() % 10;
            } while (i_next[i] == i_curr[i]);
        }
        
        for (int j = 0; j < 4; j++) {
            PCA9685_SetDigit(j, i_next[j], PCA9685_Max_Brightness);
        }
        
        if (k % 2 == 0) {
            PCA9685_SetDot(PCA9685_Max_Brightness);
        } else {
            PCA9685_SetDot(PCA9685_Min_Brightness);
        }
        
        wait(0.1);
        for (int j = 0; j < 4; j++) {
            PCA9685_SetDigit(j, i_next[j], PCA9685_Min_Brightness);
        }
        
        for (int i = 0; i < 4; i++) {
            i_curr[i] = i_next[i];
        }
    }
}
