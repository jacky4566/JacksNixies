#include "mbed.h"
#include "main.h"
#include "ioc.h"

InterruptIn IO_nFault(PA_3);
DigitalOut  IO_HvEn(PA_2);
#ifdef REVISION_A
DigitalOut  IO_LED(PB_6);
#else
DigitalOut  IO_LED(PC_15);
#endif
AnalogIn    IO_Imon(PA_0);
AnalogIn    IO_Vout(PA_1);

void InterruptFault(void) {
    IO_LED.write(1);
    while(1);
}

void IO_Init(void) {
    IO_nFault.fall(&InterruptFault);
}

void HV_EnableOutput(bool Enable) {
    IO_HvEn.write(Enable);
}

void LED_SetOutput(bool Value) {
    IO_LED.write(Value);
}

void LED_Fault(char Pattern) {
    LED_SetOutput(true);
    while(1);
}
