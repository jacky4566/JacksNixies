#include "mbed.h"
#include "main.h"
#include "tusb322.h"

InterruptIn IO_Usb(PB_4);

void UsbInterrupt(void) {
    // No real uses for this at the moment
}

void TUSB322_Init(void) {
    TUSB322_REGS regs = {0};
    
    IO_Usb.fall(UsbInterrupt);

    // Disable UFP accessory support (otherwise IC stays in DRP mode)
    regs.Status2.UFP_ACCESSORY = 0x1;

    // Disable CC termination to change to UFP mode
    regs.Control.DISABLE_TERM = 0x1;

    // For operation in UFP mode
    regs.Control.MODE_SELECT = 0x01;

    I2C_Write(TUSB322_ADDR, FIELD_OFFSET(TUSB322_REGS, Status2), 
        regs.AS_BYTE + FIELD_OFFSET(TUSB322_REGS, Status2),
        FIELD_SIZE_THROUGH(TUSB322_REGS, Status2, Control));

    // Reenable CC termination
    regs.Control.DISABLE_TERM = 0x0;

    I2C_Write(TUSB322_ADDR, FIELD_OFFSET(TUSB322_REGS, Control), 
        regs.AS_BYTE + FIELD_OFFSET(TUSB322_REGS, Control),
        FIELD_SIZE_THROUGH(TUSB322_REGS, Control, Control));
}
