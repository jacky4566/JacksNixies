#ifndef nixi_driver_h_
#define nixi_driver_h_

#include "Particle.h"

#define PCA9685_ADDR_1     0x41
#define PCA9685_ADDR_2     0x42
#define PCA9685_ADDR_3     0x43
#define PCA9685_All_Call   0x70     // Default enabled

typedef union {
    struct {
        ushort ON       : 12;
        ushort ON_FULL  : 1;
        ushort          : 3;
        ushort OFF      : 12;
        ushort OFF_FULL : 1;
        ushort          : 3;
    };
    byte AS_BYTE[4];
} LED_CTRL;
 
typedef union {
    struct {
        byte            MODE1;          // +0x00
        byte            MODE2;          // +0x01
        byte            SUBADR1;        // +0x02
        byte            SUBADR2;        // +0x03
        byte            SUBADR3;        // +0x04
        byte            ALLCALLADR;     // +0x05
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
        byte            RESERVED[180];  // +0x46
        byte            ALL_LED[4];        // +0xFA
        byte            PRE_SCALE;      // +0xFE
        byte            TestMode;       // +0xFF
    };
    byte AS_BYTE[0x100];
} PCA9685_REGS;

#define PCA9685_Max_Brightness 4096
#define PCA9685_Min_Brightness 0

#define MAP_ADDR 0
#define MAP_PIN  1

const byte Tube_Mapping[4][10][2] = 
{ 
	 { 
        { PCA9685_ADDR_3, 11 },   // Tube 1 Digit 0
        { PCA9685_ADDR_3, 9  },   // Tube 1 Digit 1
        { PCA9685_ADDR_3, 8  },   // Tube 1 Digit 2
        { PCA9685_ADDR_3, 7  },   // Tube 1 Digit 3
        { PCA9685_ADDR_3, 6  },   // Tube 1 Digit 4
        { PCA9685_ADDR_3, 2  },   // Tube 1 Digit 5
        { PCA9685_ADDR_3, 1  },   // Tube 1 Digit 6
        { PCA9685_ADDR_3, 3  },   // Tube 1 Digit 7
        { PCA9685_ADDR_3, 5  },   // Tube 1 Digit 8
        { PCA9685_ADDR_3, 10 },   // Tube 1 Digit 9
      },
	  { 
        { PCA9685_ADDR_2, 6  },   // Tube 2 Digit 0
        { PCA9685_ADDR_3, 15 },   // Tube 2 Digit 1 
        { PCA9685_ADDR_3, 14 },   // Tube 2 Digit 2
        { PCA9685_ADDR_3, 13 },   // Tube 2 Digit 3
        { PCA9685_ADDR_2, 0  },   // Tube 2 Digit 4
        { PCA9685_ADDR_2, 1  },   // Tube 2 Digit 5
        { PCA9685_ADDR_2, 2  },   // Tube 2 Digit 6
        { PCA9685_ADDR_2, 3  },   // Tube 2 Digit 7
        { PCA9685_ADDR_2, 4  },   // Tube 2 Digit 8
        { PCA9685_ADDR_2, 5  },   // Tube 2 Digit 9
      },
	  { 
        { PCA9685_ADDR_1, 5 },      // Tube 3 Digit 0
        { PCA9685_ADDR_2, 10 },     // Tube 3 Digit 1
        { PCA9685_ADDR_2, 11  },     // Tube 3 Digit 2
        { PCA9685_ADDR_2, 12  },     // Tube 3 Digit 3
        { PCA9685_ADDR_2, 13  },     // Tube 3 Digit 4
        { PCA9685_ADDR_2, 14 },     // Tube 3 Digit 5
        { PCA9685_ADDR_2, 15 },     // Tube 3 Digit 6
        { PCA9685_ADDR_1, 3 },     // Tube 3 Digit 7
        { PCA9685_ADDR_1, 2 },     // Tube 3 Digit 8
        { PCA9685_ADDR_1, 4 },     // Tube 3 Digit 9
      },
	  { 
        { PCA9685_ADDR_1, 7  },     // Tube 4 Digit 0
        { PCA9685_ADDR_1, 6  },     // Tube 4 Digit 1
        { PCA9685_ADDR_1, 8  },     // Tube 4 Digit 2
        { PCA9685_ADDR_1, 11 },     // Tube 4 Digit 3
        { PCA9685_ADDR_1, 12 },     // Tube 4 Digit 4
        { PCA9685_ADDR_1, 13 },     // Tube 4 Digit 5
        { PCA9685_ADDR_1, 15 },     // Tube 4 Digit 6
        { PCA9685_ADDR_1, 14 },     // Tube 4 Digit 7
        { PCA9685_ADDR_1, 10 },     // Tube 4 Digit 8
        { PCA9685_ADDR_1, 9  },     // Tube 4 Digit 9
      }  
    };

class nixie_driver{
    public:
        void init();
        void setTube(int Tube, int Digit, int Brightness);	//Set new digit
        void ledWriter(int addr, int led, int Brightness); //used for pin testing the PCA driver chip
        void clearTube(int Tube);
        int getTubevalue(int Tube);
	private:
		int currentTubeValue[4] = {0,0,0,0};
};

#endif