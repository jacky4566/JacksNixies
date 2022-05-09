#ifndef _DS_3231_H_
#define _DS_3231_H_

#define DS3231_ADDR 0x68

typedef union {
    struct {
        char Value : 7;
        char       : 1;
    };
    char AS_BYTE;
} T_SECOND;

typedef union {
    struct {
        char Value : 7;
        char       : 1;
    };
    char AS_BYTE;
} T_MINUTE;

typedef union {
    struct {
        char Value : 6;
        char n24   : 1;
        char       : 1;
    };
    char AS_BYTE;
} T_HOUR;

typedef union {
    struct {
        char Value : 3;
        char       : 5;
    };
    char AS_BYTE;
} T_DAY;

typedef union {
    struct {
        char Value : 6;
        char       : 2;
    };
    char AS_BYTE;
} T_DATE;

typedef union {
    struct {
        char Value   : 5;
        char         : 2;
        char Century : 1;
    };
    char AS_BYTE;
} T_MONTH;

typedef union {
    struct {
        char Value : 8;
    };
    char AS_BYTE;
} T_YEAR;

typedef union {
    struct {
        char Value : 7;
        char M1    : 1;
    };
    char AS_BYTE;
} A_SECOND;

typedef union {
    struct {
        char Value : 7;
        char M2    : 1;
    };
    char AS_BYTE;
} A_MINUTE;

typedef union {
    struct {
        char Value : 6;
        char n24   : 1;
        char M3    : 1;
    };
    char AS_BYTE;
} A_HOUR;

typedef union {
    struct {
        char Value : 6;
        char nDT   : 1;
        char M4    : 1;
    };
    char AS_BYTE;
} A_DAY_DATE;

typedef union {
    struct {
        char A1IE  : 1;
        char A2IE  : 1;
        char INTCN : 1;
        char RS1   : 1;
        char RS2   : 1;
        char CONV  : 1;
        char BBSQW : 1;
        char nEOSC : 1;
    };
    char AS_BYTE;
} CONTROL_1;

typedef union {
    struct {
        char A1F     : 1;
        char A2F     : 1;
        char BSY     : 1;
        char EN32KHZ : 1;
        char         : 3;
        char OSF     : 1;
    };
    char AS_BYTE;
} CONTROL_2;

typedef union {
    struct {
        char Value : 7;
        char Sign  : 1;
    };
    char AS_BYTE;
} AGING_OFFSET;

typedef union {
    struct {
        char Value : 7;
        char Sign  : 1;
    };
    char AS_BYTE;
} TEMP_MSB;

typedef union {
    struct {
        char       : 6;
        char Value : 2;
    };
    char AS_BYTE;
} TEMP_LSB;

typedef union {
    struct {
        T_SECOND Second;            // 0x00
        T_MINUTE Minute;            // 0x01
        T_HOUR Hour;                // 0x02
        T_DAY Day;                  // 0x03
        T_DATE Date;                // 0x04
        T_MONTH Month;              // 0x05
        T_YEAR Year;                // 0x06
        A_SECOND A1_Second;         // 0x07
        A_MINUTE A1_Minute;         // 0x08
        A_HOUR A1_Hour;             // 0x09
        A_DAY_DATE A1_Day_Date;     // 0x0A
        A_MINUTE A2_Minute;         // 0x0B
        A_HOUR A2_Hour;             // 0x0C
        A_DAY_DATE A2_Day_Date;     // 0x0D
        CONTROL_1 Control_1;        // 0x0E
        CONTROL_2 Control_2;        // 0x0F
        AGING_OFFSET Aging_Offset;  // 0x10
        TEMP_MSB Temp_MSB;          // 0x11
        TEMP_LSB Temp_LSB;          // 0x12
    };
    char AS_BYTE[0x13];
} DS3231_REGS;

enum {
    SUNDAY      = 0,
    MONDAY      = 1,
    TUESDAY     = 2,
    WEDNESDAY   = 3,
    THURSDAY    = 4,
    FRIDAY      = 5,
    SATURDAY    = 6
};

void DS3231_Init(void (*Callback)());
void DS3231_SetTime(int Second, int Minute, int Hour);
void DS3231_SetDate(int Day, int Date, int Month, int Year, int Century);
void DS3231_GetTime(int *Second, int *Minute, int *Hour);
void DS3231_GetDate(int *Day, int *Date, int *Month, int *Year);
bool IsDst(int Day, int Date, int Month, int Hour_24);

#endif
