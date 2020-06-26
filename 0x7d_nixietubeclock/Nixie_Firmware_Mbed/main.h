#ifndef _MAIN_H_
#define _MAIN_H_

// #define REVISION_A
#define REVISION_B

// Calculate the byte offset of a field in a structure of type type.
#define FIELD_OFFSET(type, field) ((uint32_t)(uint32_t*)&(((type *)0)->field))

// Calculate the size of a field in a structure of type type 
#define FIELD_SIZE(type, field) (sizeof(((type *)0)->field))

// Calculate the size from field1 to field2 (inclusive)
#define FIELD_SIZE_THROUGH(type, field1, field2) \
    (FIELD_OFFSET(type, field2) + FIELD_SIZE(type, field2) - FIELD_OFFSET(type, field1))

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#define I2C_MAX_BUFFER 20

#define NUM_TUBES 4
#define NUM_DIGITS 10

#define REFRESH_RATE_US 1000  

#define DOT_MIN 256
#define DOT_MAX 640
#define DOT_FADE_DURATION_US 1000000

#define DIGIT_MIN PCA9685_Min_Brightness
#define DIGIT_MAX PCA9685_Max_Brightness
#define DIGIT_FADE_DURATION_US 1000000

#define DIGIT_RNG_FADE_DURATION_US 200000
#define DIGIT_RNG_FADE_ITERATIONS 20
#define DIGIT_RNG_REFRESH_INTERVAL 60 
#define DIGIT_RNG_REFRESH_VARIANCE 30

#define REFRESH_SEQUENTIAL
// #define REFRESH_RANDOM

void I2C_Write(int DeviceAddress, char RegAddress, char *Data, int Length);
void I2C_Read(int DeviceAddress, char RegAddress, char *Data, int Length);

#endif
