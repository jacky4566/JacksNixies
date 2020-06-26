#include "mbed.h"
#include "main.h"
#include "SWO.h"
#include "pca9685.h"
#include "tusb322.h"
#include "ds3231.h"
#include "ioc.h"
#include "animation.h"

I2C i2c(PA_10, PA_9);
// SWO_Channel swo("swo");
#ifdef REVISION_B
Serial serial(PB_6, PB_7);
#endif

typedef enum {
    Decrementing = 0,
    Incrementing = 1,
} DigitState;

typedef struct {
    DigitState CurrentState;
    int Value;
    bool Updated;
} Digit;

typedef struct {
    Digit Digits[NUM_DIGITS];
    int LastActiveDigit;
    int RefreshLastDigit;
    bool RefreshActive;
    int FadeDuration;
} Tube;

Tube Tubes[NUM_TUBES];  // Active per-tube configuration
Digit Dot;

Timeout DotUpdateTimeout;
void DotUpdateCallback(void) {
    int ticks = DOT_FADE_DURATION_US / REFRESH_RATE_US;
    int step = ((DOT_MAX - DOT_MIN) + ticks - 1) / ticks;
    if (Dot.CurrentState == Incrementing && Dot.Value < DOT_MAX) {
        Dot.Value = (Dot.Value + step >= DOT_MAX) ? DOT_MAX : Dot.Value + step;
    } else if (Dot.CurrentState == Decrementing && Dot.Value > DOT_MIN) {
        Dot.Value = (Dot.Value - step <= DOT_MIN) ? DOT_MIN : Dot.Value - step;
    }
    Dot.Updated = true;

    if (Dot.Value != DOT_MAX && Dot.Value != DOT_MIN) {
        DotUpdateTimeout.attach_us(DotUpdateCallback, REFRESH_RATE_US);
    } 
}

// Macro the per-tube callback function as each callback needs to be defined as
// a unique function (callbacks cannot have arguments and are not reentrant)
#define TUBE_CALLBACK(x) \
void Tube##x##UpdateCallback(void) { \
    int ticks = Tubes[x].FadeDuration / REFRESH_RATE_US; \
    int step = ((DIGIT_MAX - DIGIT_MIN) + ticks - 1) / ticks; \
    bool activeTube = false; \
    for (int i = 0; i < NUM_DIGITS; i++) { \
        Digit *digit = &Tubes[x].Digits[i]; \
        if (digit->CurrentState == Incrementing && digit->Value <= DIGIT_MAX) { \
            digit->Value = (digit->Value + step >= DIGIT_MAX) ? DIGIT_MAX : digit->Value + step; \
            digit->Updated = true; \
        } else if (digit->CurrentState == Decrementing && digit->Value >= DIGIT_MIN) { \
            digit->Value = (digit->Value - step <= DIGIT_MIN) ? DIGIT_MIN : digit->Value - step; \
            digit->Updated = true; \
        } \
        activeTube |= (digit->Value != DIGIT_MAX && digit->Value != DIGIT_MIN); \
    } \
    if (activeTube) { \
        Tube##x##UpdateTimeout.attach_us(Tube##x##UpdateCallback, REFRESH_RATE_US); \
    } \
} 

Timeout Tube0UpdateTimeout;
TUBE_CALLBACK(0)
Timeout Tube1UpdateTimeout;
TUBE_CALLBACK(1)
Timeout Tube2UpdateTimeout;
TUBE_CALLBACK(2)
Timeout Tube3UpdateTimeout;
TUBE_CALLBACK(3)

void FadeInOutDigit(int T, int D, int Duration, bool RngUpdate = false) {

    // If the tube is in the middle of a refresh sequence and a call comes 
    // in to update the tube digit (for time), override the last value of 
    // the refresh sequence with the new digit.
    if (Tubes[T].RefreshActive && !RngUpdate) {
        Tubes[T].RefreshLastDigit = D;
    }

    // Dont update if actively refreshing tube unless RngUpdate is set
    if ((!RngUpdate && !Tubes[T].RefreshActive) || (RngUpdate)) {
        for (int i = 0; i < NUM_DIGITS; i++) {
            Tubes[T].Digits[i].CurrentState = Decrementing;
        }
        if (D != -1) {
            Tubes[T].Digits[D].CurrentState = Incrementing;
        }

        Tubes[T].FadeDuration = Duration;
        Tubes[T].LastActiveDigit = D;

        if (T == 0) {
            Tube0UpdateTimeout.attach_us(Tube0UpdateCallback, REFRESH_RATE_US);
        } else if (T == 1) {
            Tube1UpdateTimeout.attach_us(Tube1UpdateCallback, REFRESH_RATE_US);
        } else if (T == 2) {
            Tube2UpdateTimeout.attach_us(Tube2UpdateCallback, REFRESH_RATE_US);
        } else if (T == 3) {
            Tube3UpdateTimeout.attach_us(Tube3UpdateCallback, REFRESH_RATE_US);
        } 
    }
}

bool RtcTick, RefreshTick, RngTick;
Ticker RefreshTicker;
Timeout RngRefreshTimeout;

// Callback from DS3231 interrupt (1Hz)
void RtcInterruptCallback(void) {
    RtcTick = true;
}

// Callback from RefreshTicker (REFRESH_RATE_US)
void RefreshTickerCallback(void) {
    RefreshTick = true;
}

void RngTickerCallback(void) {
    RngTick = true;
}

Timeout RngUpdateTimeout;
int RngUpdateIteration;
void RngUpdateCallback(void) {
    int newfadeDuration = DIGIT_FADE_DURATION_US - RngUpdateIteration * DIGIT_RNG_FADE_DURATION_US;
    if (newfadeDuration <= DIGIT_RNG_FADE_DURATION_US) newfadeDuration = DIGIT_RNG_FADE_DURATION_US;
    for (int i = 0; i < NUM_TUBES; i++) {
        if (Tubes[i].RefreshActive) {
            if (RngUpdateIteration) {
                int nextDigit;
#ifdef REFRESH_SEQUENTIAL
                nextDigit = (Tubes[i].LastActiveDigit >= 9 || Tubes[i].LastActiveDigit < 0) ? 
                    0 : Tubes[i].LastActiveDigit + 1;;
#endif
#ifdef REFRESH_RANDOM
                do {
                    nextDigit = rand() % NUM_DIGITS;
                } while (nextDigit == Tubes[i].LastActiveDigit || 
                    (RngUpdateIteration == 1 && nextDigit == Tubes[i].RefreshLastDigit));
#endif
                FadeInOutDigit(i, nextDigit, newfadeDuration, true);
            } else {
                FadeInOutDigit(i, Tubes[i].RefreshLastDigit, newfadeDuration, true);
                Tubes[i].RefreshActive = false;
            }
        }
    }
    if (RngUpdateIteration-- != 0) {
        RngUpdateTimeout.attach_us(RngUpdateCallback, newfadeDuration);
    }
}

int main() {

#ifdef REVISION_B
    serial.baud(115200);
#endif

    // Initialize pointers in global data structure
    for (int i = 0; i < NUM_TUBES; i++) {
        for (int j = 0; j < NUM_DIGITS; j++) {
            Tubes[i].Digits[j].CurrentState = Decrementing;
            Tubes[i].Digits[j].Value = DIGIT_MIN;
            Tubes[i].Digits[j].Updated = false;
        }
        Tubes[i].LastActiveDigit = -1;
        Tubes[i].RefreshLastDigit = -1;
        Tubes[i].RefreshActive = true;
        Tubes[i].FadeDuration = 0;
    }

    Dot.CurrentState = Decrementing;
    Dot.Value = DOT_MIN;
    Dot.Updated = false;

    RtcTick = false;
    RefreshTick = false;
    RngTick = false;

    int nextSecond, nextMinute, nextHour;
    int prevMinute, prevHour;
    int day, date, month, year;
    bool startup = true;
    
    // Start I2C at 400kHz for DS3231 
    i2c.frequency(400000);
    
    // Start with HV PSU disabled
    HV_EnableOutput(false);
    
    TUSB322_Init();
    PCA9685_Init();
    DS3231_Init(RtcInterruptCallback);

    // Enable HV PSU
    HV_EnableOutput(true);
    
    // Set PCA9685 input voltage to highest possible
    PCA9685_SetVoltage(1.0);
    
    // swo.printf("CPU SystemCoreClock is %d Hz\r\n", SystemCoreClock);
    
    // Bump I2C frequency to 1MHz
    // i2c.frequency(1000000);

    // Animate_Cycle_Basic(10);
    // Animate_Cycle_Analog(10);
    // Animate_Cycle_Low_Pwm(10);
    // Animate_Cycle_Pwm(10);
    // Animate_Cycle_Fade(10);
    // Animate_Cycle_Fade_Random(10);
    // Animate_Cycle_Fast(10);
    // Animate_Cycle_Fast_Random(100);

    // wait(3);
        
    // DS3231_SetTime(00, 05, 00);
    // DS3231_SetDate(FRIDAY, 15, 3, 19, 0);

    // Setup a ticker to refresh the display at 1kHz
    RefreshTicker.attach_us(RefreshTickerCallback, REFRESH_RATE_US);

    // Kick off the RNG timeout animation on startup
    int nextRngTimeout = DIGIT_RNG_REFRESH_INTERVAL + (rand() % DIGIT_RNG_REFRESH_VARIANCE);
    RngRefreshTimeout.attach(RngTickerCallback, nextRngTimeout);

    RngUpdateIteration = DIGIT_RNG_FADE_ITERATIONS;
    RngUpdateCallback();

    while(1) {

        // On every refresh tick, update the display with new values
        if (RefreshTick) {
            RefreshTick = false;

            for (int i = 0; i < NUM_TUBES; i++) {
                for (int j = 0; j < NUM_DIGITS; j++) {
                    if (Tubes[i].Digits[j].Updated) {
                        PCA9685_SetDigit(i, j, Tubes[i].Digits[j].Value);
                        Tubes[i].Digits[j].Updated = false;
                    }
                }
            }

            if (Dot.Updated) {
                PCA9685_SetDot(Dot.Value);
                Dot.Updated = false;
            }
        }

        // On every RTC tick, read and process the current time
        if (RtcTick) {
            RtcTick = false;

            // Save the previous time to check if digit(s) has changed
            prevMinute = nextMinute;
            prevHour = nextHour;

            DS3231_GetTime(&nextSecond, &nextMinute, &nextHour);
            DS3231_GetDate(&day, &date, &month, &year);

            // Compensate for daylight savings time
            nextHour = IsDst(day, date, month, nextHour) ? (nextHour + 1) % 12 : nextHour % 12;
            if (nextHour == 0) nextHour = 12;

            // Update the display configuration based on the new/previous time
            if (startup || prevHour / 10 != nextHour / 10) {
                FadeInOutDigit(0, (nextHour / 10 != 0) ? nextHour / 10 : -1 , DIGIT_FADE_DURATION_US);
            } 
            if (startup || prevHour % 10 != nextHour % 10) {
                FadeInOutDigit(1, nextHour % 10, DIGIT_FADE_DURATION_US);
            } 
            if (startup || prevMinute / 10 != nextMinute / 10) {
                FadeInOutDigit(2, nextMinute / 10, DIGIT_FADE_DURATION_US);
            } 
            if (startup || prevMinute % 10 != nextMinute % 10) {
                FadeInOutDigit(3, nextMinute % 10, DIGIT_FADE_DURATION_US);
            }

            Dot.CurrentState = (Dot.CurrentState == Decrementing) ? Incrementing : Decrementing;
            DotUpdateTimeout.attach_us(DotUpdateCallback, DOT_FADE_DURATION_US / REFRESH_RATE_US);

            // Clear the startup run-once flag after the first iteration
            startup = false;
        }

        if (RngTick) {
            RngTick = false;

            int refreshTube = rand() % NUM_TUBES; 
            Tubes[refreshTube].RefreshLastDigit = Tubes[refreshTube].LastActiveDigit;
            Tubes[refreshTube].RefreshActive = true;

            RngUpdateIteration = DIGIT_RNG_FADE_ITERATIONS;
            RngUpdateCallback();

            nextRngTimeout = DIGIT_RNG_REFRESH_INTERVAL + (rand() % DIGIT_RNG_REFRESH_VARIANCE);
            RngRefreshTimeout.attach(RngTickerCallback, nextRngTimeout);
        }
    }
}

void I2C_Write(int DeviceAddress, char RegAddress, char *Data, int Length) {
    char buffer[I2C_MAX_BUFFER+1] = {0};

    if (Length > I2C_MAX_BUFFER) LED_Fault(1);

    buffer[0] = RegAddress;
    memcpy(&buffer[1], Data, Length);

    i2c.write(DeviceAddress << 1, buffer, Length + 1);
}

void I2C_Read(int DeviceAddress, char RegAddress, char *Data, int Length) {
    
    i2c.write(DeviceAddress << 1, &RegAddress, 1);
    i2c.read(DeviceAddress << 1, Data, Length);
}
