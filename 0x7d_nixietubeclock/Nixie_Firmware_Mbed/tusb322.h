#ifndef _TUSB_322_H_
#define _TUSB_322_H_

#define TUSB322_ADDR 0x47 

typedef union {
    struct {
        char ACTIVE_CABLE      : 1;
        char ACCESSORY         : 3;
        char CURRENT_DETECT    : 2;
        char CURRENT_ADVERTISE : 2;
    };
    char AS_BYTE;
} CONN_STATUS1;

typedef union {
    struct {
        char UFP_ACCESSORY  : 1;
        char DRP_DUTY_CYCLE : 2;
        char VCONN_FAULT    : 1;
        char INTERRUPT      : 1;
        char CABLE_DIR      : 1;
        char ATTACHED_STATE : 2;
    };
    char AS_BYTE;
} CONN_STATUS2;

typedef union {
    struct {
        char DISABLE_TERM : 1;
        char SOURCE_PERF  : 2;
        char RESET        : 1;
        char MODE_SELECT  : 2;
        char DEBOUNCE     : 2;
    };
    char AS_BYTE;
} CTRL;

typedef union {
    struct {
        char      ID[8];          // +0x00
        CONN_STATUS1 Status1;        // +0x08
        CONN_STATUS2 Status2;        // +0x09
        CTRL         Control;        // +0x0A
    };
    char AS_BYTE[0xB];
} TUSB322_REGS;

void TUSB322_Init(void);

#endif
