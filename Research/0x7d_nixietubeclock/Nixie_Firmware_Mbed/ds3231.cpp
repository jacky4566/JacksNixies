#include "mbed.h"
#include "main.h"
#include "ds3231.h"

InterruptIn IO_Rtc(PB_5);

#define BCDToDecimal(x) (((x >> 4) * 10) + (x & 0xF))
#define DecimalToBCD(x) (((x / 10) << 4) | (x % 10))

void DS3231_Init(void (*Callback)()) {
    DS3231_REGS regs = {0};

    regs.Control_1.nEOSC = 0;  // Enable internal oscillator on VBAT
    regs.Control_1.BBSQW = 0;  // Disable outputs on VBAT
    regs.Control_1.RS1 = 0;    // Set square wave output to 1Hz
    regs.Control_1.RS2 = 0;    // Set square wave output tp 1Hz
    regs.Control_1.INTCN = 0;  // Enable square wave output
    regs.Control_1.A1IE = 0;   // Disable alarm 1
    regs.Control_1.A2IE = 0;   // Disable alarm 2

    regs.Control_2.EN32KHZ = 0;   // Disable 32kHz output

    I2C_Write(DS3231_ADDR, FIELD_OFFSET(DS3231_REGS, Control_1),
        regs.AS_BYTE + FIELD_OFFSET(DS3231_REGS, Control_1),
        FIELD_SIZE_THROUGH(DS3231_REGS, Control_1, Control_2));

    IO_Rtc.rise(Callback);
}

void DS3231_SetTime(int Second, int Minute, int Hour) {
    DS3231_REGS regs = {0};

    regs.Second.Value = DecimalToBCD(Second);
    regs.Minute.Value = DecimalToBCD(Minute);
    regs.Hour.Value = DecimalToBCD(Hour);
    regs.Hour.n24 = 0;

    I2C_Write(DS3231_ADDR, FIELD_OFFSET(DS3231_REGS, Second),
        regs.AS_BYTE + FIELD_OFFSET(DS3231_REGS, Second),
        FIELD_SIZE_THROUGH(DS3231_REGS, Second, Hour));
}

void DS3231_SetDate(int Day, int Date, int Month, int Year, int Century) {
    DS3231_REGS regs = {0};

    regs.Day.Value = DecimalToBCD(Day);
    regs.Date.Value = DecimalToBCD(Date);
    regs.Month.Value = DecimalToBCD(Month);
    regs.Month.Century = DecimalToBCD(Century);
    regs.Year.Value = DecimalToBCD(Year);

    I2C_Write(DS3231_ADDR, FIELD_OFFSET(DS3231_REGS, Day),
        regs.AS_BYTE + FIELD_OFFSET(DS3231_REGS, Day),
        FIELD_SIZE_THROUGH(DS3231_REGS, Day, Year));
}

void DS3231_GetTime(int *Second, int *Minute, int *Hour) {
    DS3231_REGS regs = {0};

    I2C_Read(DS3231_ADDR, FIELD_OFFSET(DS3231_REGS, Second),
        regs.AS_BYTE + FIELD_OFFSET(DS3231_REGS, Second),
        FIELD_SIZE_THROUGH(DS3231_REGS, Second, Hour));

    *Second = BCDToDecimal(regs.Second.Value);
    *Minute = BCDToDecimal(regs.Minute.Value);
    *Hour = BCDToDecimal(regs.Hour.Value);
}

void DS3231_GetDate(int *Day, int *Date, int *Month, int *Year) {
    DS3231_REGS regs = {0};

    I2C_Read(DS3231_ADDR, FIELD_OFFSET(DS3231_REGS, Day),
        regs.AS_BYTE + FIELD_OFFSET(DS3231_REGS, Day),
        FIELD_SIZE_THROUGH(DS3231_REGS, Day, Year));

    *Day = BCDToDecimal(regs.Day.Value);
    *Date = BCDToDecimal(regs.Date.Value);
    *Month = BCDToDecimal(regs.Month.Value);
    *Year = BCDToDecimal(regs.Year.Value);
}

bool IsDst(int Day, int Date, int Month, int Hour_24) {
    // December through Feburary are always outside DST
    if (Month < 3 || Month > 11) return false;
    // April through October are always in DST
    if (Month > 3 && Month < 11) return true;

    int prevSunday = Date - Day;
    // In March, in DST if previous sunday is between 8th and 14th
    if (Month == 3) {
        if (prevSunday < 8) return false;
        if (prevSunday > 14) return true;
        return (Date == prevSunday) ? Hour_24 >= 2 : true;
    } 
    // In November, in DST if before the first Sunday           
    if (prevSunday <= 0) return true;
    return (prevSunday == Date && Date <= 7) ? (Hour_24 < 2) : false;
}
