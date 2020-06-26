#ifndef _IOC_H_
#define _IOC_H_

void IO_Init(void);
void HV_EnableOutput(bool Enable);
void LED_SetOutput(bool Value);
void LED_Fault(char Pattern);

#endif
