#ifndef _PCA_9685_H_
#define _PCA_9685_H_

#define PCA9685_ADDR_1     0x41
#define PCA9685_ADDR_2     0x42
#define PCA9685_ADDR_3     0x43

// Hardcoded addresses available on powerup
#define PCA9685_All_Call   0x70     // Default enabled
#define PCA9685_Sub_Call_1 0x71     // Default disabled
#define PCA9685_Sub_Call_2 0x72     // Default disabled
#define PCA9685_Sub_Call_3 0x73     // Default disabled
#define PCA9685_Reset      0x03     // Default enabled?

#define PCA9685_Max_Brightness 4096
#define PCA9685_Min_Brightness 0

typedef union {
    struct {
        char ALLCALL : 1;
        char SUB3    : 1;
        char SUB2    : 1;
        char SUB1    : 1;
        char SLEEP   : 1;
        char AI      : 1;
        char EXTCLK  : 1;
        char RESTART : 1;
    };
    char AS_BYTE;
} REG_MODE1;

typedef union {
    struct {
        char OUTNE  : 2;
        char OUTDRV : 1;
        char OCH    : 1;
        char INVRT  : 1;
        char        : 3;
    };
    char AS_BYTE;
} REG_MODE2;

typedef union {
    struct {
        ushort ON       : 12;
        ushort ON_FULL  : 1;
        ushort          : 3;
        ushort OFF      : 12;
        ushort OFF_FULL : 1;
        ushort          : 3;
    };
    char AS_BYTE[4];
} LED_CTRL;

typedef union {
    struct {
        ushort ON       : 12;
        ushort ON_FULL  : 1;
        ushort          : 3;
        ushort OFF      : 12;
        ushort OFF_FULL : 1;
        ushort          : 3;
    };
    char AS_BYTE[4];
} ALL_LED_CTRL;
 
typedef union {
    struct {
        REG_MODE1       MODE1;          // +0x00
        REG_MODE2       MODE2;          // +0x01
        char            SUBADR1;        // +0x02
        char            SUBADR2;        // +0x03
        char            SUBADR3;        // +0x04
        char            ALLCALLADR;     // +0x05
        LED_CTRL        LED0;           // +0x06
        LED_CTRL        LED1;           // +0x0A
        LED_CTRL        LED2;           // +0x0E
        LED_CTRL        LED3;           // +0x12
        LED_CTRL        LED4;           // +0x16
        LED_CTRL        LED5;           // +0x1A
        LED_CTRL        LED6;           // +0x1E
        LED_CTRL        LED7;           // +0x22
        LED_CTRL        LED8;           // +0x26
        LED_CTRL        LED9;           // +0x2A
        LED_CTRL        LED10;          // +0x2E
        LED_CTRL        LED11;          // +0x32
        LED_CTRL        LED12;          // +0x36
        LED_CTRL        LED13;          // +0x3A
        LED_CTRL        LED14;          // +0x3E
        LED_CTRL        LED15;          // +0x42
        char            RESERVED[180];  // +0x46
        ALL_LED_CTRL    ALL_LED;        // +0xFA
        char            PRE_SCALE;      // +0xFE
        char            TestMode;       // +0xFF
    };
    char AS_BYTE[0x100];
} PCA9685_REGS;

#define TUBE_DOT_ADDR PCA9685_ADDR_2
#define TUBE_DOT_PIN LED15

#define MAP_ADDR 0
#define MAP_PIN  1

const char Tube_Mapping[4][10][2] = 
    { { 
        { PCA9685_ADDR_1, 8  },     // Tube 0 Digit 0
        { PCA9685_ADDR_1, 9  },     // Tube 0 Digit 1
        { PCA9685_ADDR_1, 10 },     // Tube 0 Digit 2
        { PCA9685_ADDR_1, 12 },     // Tube 0 Digit 3
        { PCA9685_ADDR_1, 15 },     // Tube 0 Digit 4
        { PCA9685_ADDR_1, 14 },     // Tube 0 Digit 5
        { PCA9685_ADDR_1, 11 },     // Tube 0 Digit 6
        { PCA9685_ADDR_1, 0  },     // Tube 0 Digit 7
        { PCA9685_ADDR_1, 1  },     // Tube 0 Digit 8
        { PCA9685_ADDR_1, 13 },     // Tube 0 Digit 9
      },   

      { 
        { PCA9685_ADDR_1, 5  },     // Tube 1 Digit 0
        { PCA9685_ADDR_1, 6  },     // Tube 1 Digit 1
        { PCA9685_ADDR_1, 7  },     // Tube 1 Digit 2
        { PCA9685_ADDR_1, 2  },     // Tube 1 Digit 3
        { PCA9685_ADDR_2, 4  },     // Tube 1 Digit 4
        { PCA9685_ADDR_2, 1  },     // Tube 1 Digit 5
        { PCA9685_ADDR_1, 4  },     // Tube 1 Digit 6
        { PCA9685_ADDR_2, 2  },     // Tube 1 Digit 7
        { PCA9685_ADDR_2, 3  },     // Tube 1 Digit 8
        { PCA9685_ADDR_1, 3  },     // Tube 1 Digit 9
      },   

      { 
        { PCA9685_ADDR_3, 8  },     // Tube 2 Digit 0
        { PCA9685_ADDR_3, 9  },     // Tube 2 Digit 1
        { PCA9685_ADDR_3, 10 },     // Tube 2 Digit 2
        { PCA9685_ADDR_3, 12 },     // Tube 2 Digit 3
        { PCA9685_ADDR_2, 12 },     // Tube 2 Digit 4
        { PCA9685_ADDR_2, 13 },     // Tube 2 Digit 5
        { PCA9685_ADDR_3, 11 },     // Tube 2 Digit 6
        { PCA9685_ADDR_2, 14 },     // Tube 2 Digit 7
        { PCA9685_ADDR_2, 11 },     // Tube 2 Digit 8
        { PCA9685_ADDR_3, 13 },     // Tube 2 Digit 9
      },

      { 
        { PCA9685_ADDR_3, 5  },     // Tube 3 Digit 0
        { PCA9685_ADDR_3, 6  },     // Tube 3 Digit 1
        { PCA9685_ADDR_3, 7  },     // Tube 3 Digit 2
        { PCA9685_ADDR_3, 2  },     // Tube 3 Digit 3
        { PCA9685_ADDR_3, 14 },     // Tube 3 Digit 4
        { PCA9685_ADDR_3, 15 },     // Tube 3 Digit 5
        { PCA9685_ADDR_3, 4  },     // Tube 3 Digit 6
        { PCA9685_ADDR_3, 1  },     // Tube 3 Digit 7
        { PCA9685_ADDR_3, 0  },     // Tube 3 Digit 8
        { PCA9685_ADDR_3, 3  },     // Tube 3 Digit 9
      } };

void PCA9685_Init(void);
void PCA9685_SetVoltage(float Percent);
void PCA9685_SetDigit(int Tube, int Digit, int Brightness);
void PCA9685_SetDot(int Brightness);
void PCA9685_EnableOutput(bool Enabled);

#endif
