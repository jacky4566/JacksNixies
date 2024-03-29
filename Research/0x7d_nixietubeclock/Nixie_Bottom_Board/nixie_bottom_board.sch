EESchema Schematic File Version 4
LIBS:nixie_bottom_board-cache
EELAYER 26 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 2
Title "Bottom PCB"
Date ""
Rev "B"
Comp "Nixie Tube Clock"
Comment1 "https://0x7d.com/2017/nixie-tube-clock"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 8200 1550 650  400 
U 5B07197A
F0 "HV Power Supply" 60
F1 "hv_power_supply.sch" 60
F2 "VIN" I L 8200 1650 60 
F3 "EN" I L 8200 1750 60 
F4 "GND" I L 8200 1850 60 
F5 "VOUT" I R 8850 1650 60 
F6 "GND" I R 8850 1750 60 
$EndSheet
Text Label 6800 5850 0    50   ~ 0
VDD
Text Label 6800 5250 0    50   ~ 0
SWDIO
Text Label 6800 5150 0    50   ~ 0
SWCLK
Text Label 6800 4950 0    50   ~ 0
SWO
Text Label 1600 5050 2    50   ~ 0
SWO
Text Label 1600 4850 2    50   ~ 0
SWCLK
Text Label 1600 4950 2    50   ~ 0
SWDIO
Text Label 2100 5050 0    50   ~ 0
NRST
Text Label 6800 5450 0    50   ~ 0
USB_N
Text Label 6800 5350 0    50   ~ 0
USB_P
Text Label 2100 6250 0    50   ~ 0
SCL
Text Label 2100 6350 0    50   ~ 0
SDA
Text Label 1600 5500 2    50   ~ 0
HV_OUT
Text Label 1600 6150 2    50   ~ 0
VNIXIE
Text Label 5400 5350 2    50   ~ 0
DAC
Text Label 6800 5650 0    50   ~ 0
SCL
Text Label 6800 5550 0    50   ~ 0
SDA
Text Label 8100 1750 2    50   ~ 0
HV_EN
$Comp
L Device:R R2
U 1 1 5B08854F
P 7150 4250
F 0 "R2" V 7230 4250 50  0000 C CNN
F 1 "1M" V 7050 4250 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 7080 4250 50  0001 C CNN
F 3 "" H 7150 4250 50  0001 C CNN
	1    7150 4250
	-1   0    0    1   
$EndComp
Text Label 8950 1650 0    50   ~ 0
HV_OUT
Text Label 5400 5050 2    50   ~ 0
HV_EN
Text Label 2300 1850 0    50   ~ 0
CC1
Text Label 2300 1950 0    50   ~ 0
CC2
Text Label 2300 2150 0    50   ~ 0
USB_N
Text Label 2300 2450 0    50   ~ 0
USB_P
$Comp
L Device:R R1
U 1 1 5B096154
P 3150 3250
F 0 "R1" V 3230 3250 50  0000 C CNN
F 1 "900k" V 3050 3250 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 3080 3250 50  0001 C CNN
F 3 "" H 3150 3250 50  0001 C CNN
	1    3150 3250
	-1   0    0    1   
$EndComp
Text Label 3100 3450 2    50   ~ 0
VBUS
Text Label 4400 3300 0    50   ~ 0
SCL
Text Label 4400 3400 0    50   ~ 0
SDA
$Comp
L Device:R R4
U 1 1 5B0B7874
P 7300 5350
F 0 "R4" V 7380 5350 50  0000 C CNN
F 1 "10k" V 7200 5350 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 7230 5350 50  0001 C CNN
F 3 "" H 7300 5350 50  0001 C CNN
	1    7300 5350
	-1   0    0    1   
$EndComp
$Comp
L Device:R R5
U 1 1 5B0B79AE
P 7600 5350
F 0 "R5" V 7680 5350 50  0000 C CNN
F 1 "10k" V 7500 5350 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 7530 5350 50  0001 C CNN
F 3 "" H 7600 5350 50  0001 C CNN
	1    7600 5350
	-1   0    0    1   
$EndComp
Text Notes 3700 3550 0    60   ~ 0
ADDR: 0x47
Text Notes 1400 6550 0    60   ~ 0
ADDR: 0x70-0x73
Text Label 5400 4350 2    50   ~ 0
VDD
Text Label 5400 4750 2    50   ~ 0
VDD
Text Label 4400 2900 0    50   ~ 0
VDD
Text Label 2100 4850 0    50   ~ 0
VDD
Text Label 6500 2700 0    50   ~ 0
VDD
$Comp
L Device:L_Small L1
U 1 1 5B16755A
P 5350 2800
F 0 "L1" H 5380 2840 50  0000 L CNN
F 1 "1uH" H 5380 2760 50  0000 L CNN
F 2 "Custom Parts:Inductor_4.1x4.1mm" H 5350 2800 50  0001 C CNN
F 3 "" H 5350 2800 50  0001 C CNN
	1    5350 2800
	-1   0    0    1   
$EndComp
Text Label 9100 4050 0    50   ~ 0
VDD
Text Label 8300 4250 2    50   ~ 0
DAC
Text Label 8300 4050 2    50   ~ 0
VNIXIE
Text Label 9100 4250 0    50   ~ 0
VNIXIE
Wire Wire Line
	3500 3000 3400 3000
Wire Wire Line
	3400 2900 3500 2900
Wire Wire Line
	8950 1750 8850 1750
Wire Wire Line
	8200 1850 8100 1850
Wire Wire Line
	5600 2700 5350 2700
Wire Wire Line
	8100 1750 8200 1750
$Comp
L Custom_Parts:STM32L432K U2
U 1 1 5B622DF7
P 6100 5100
F 0 "U2" H 6100 6097 60  0000 C CNN
F 1 "STM32L432K" H 6100 5991 60  0000 C CNN
F 2 "Housings_DFN_QFN:QFN-32-1EP_5x5mm_Pitch0.5mm" H 6100 5550 60  0001 C CNN
F 3 "" H 6100 5550 60  0001 C CNN
	1    6100 5100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J5
U 1 1 5B649686
P 3050 4500
F 0 "J5" H 3077 4526 50  0000 L CNN
F 1 "MCO" H 3077 4435 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.5mm" H 3050 4500 50  0001 C CNN
F 3 "~" H 3050 4500 50  0001 C CNN
	1    3050 4500
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5B64A44F
P 4900 4750
F 0 "SW1" H 4900 5035 50  0000 C CNN
F 1 "NRST" H 4900 4944 50  0000 C CNN
F 2 "Custom Parts:EVQP2" H 4900 4950 50  0001 C CNN
F 3 "" H 4900 4950 50  0001 C CNN
	1    4900 4750
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J2
U 1 1 5B693D84
P 1800 4950
F 0 "J2" H 1850 5267 50  0000 C CNN
F 1 "SWD" H 1850 5176 50  0000 C CNN
F 2 "Tag Connect:TC2030-MCP-NL" H 1800 4950 50  0001 C CNN
F 3 "~" H 1800 4950 50  0001 C CNN
	1    1800 4950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J3
U 1 1 5B6941D3
P 1800 5600
F 0 "J3" H 1850 5917 50  0000 C CNN
F 1 "Nixie_HV" H 1850 5826 50  0000 C CNN
F 2 "Custom Parts:Pin_Header_Harwin_2x03_Pitch2.00mm" H 1800 5600 50  0001 C CNN
F 3 "~" H 1800 5600 50  0001 C CNN
	1    1800 5600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J4
U 1 1 5B694500
P 1800 6250
F 0 "J4" H 1850 6567 50  0000 C CNN
F 1 "Nixie_CTRL" H 1850 6476 50  0000 C CNN
F 2 "Custom Parts:Pin_Header_Harwin_2x03_Pitch2.00mm" H 1800 6250 50  0001 C CNN
F 3 "~" H 1800 6250 50  0001 C CNN
	1    1800 6250
	1    0    0    -1  
$EndComp
$Comp
L Custom_Parts:ESD122 D2
U 1 1 5B916041
P 4050 1600
F 0 "D2" H 4050 1965 50  0000 C CNN
F 1 "ESD122" H 4050 1874 50  0000 C CNN
F 2 "Custom Parts:DMX0003A" H 4050 1600 50  0001 C CNN
F 3 "" H 4050 1600 50  0001 C CNN
	1    4050 1600
	1    0    0    -1  
$EndComp
Text Label 3400 3000 2    50   ~ 0
CC1
Text Label 3400 2900 2    50   ~ 0
CC2
Text Label 3700 1700 2    50   ~ 0
CC2
Text Label 3700 1500 2    50   ~ 0
CC1
Wire Wire Line
	8100 1650 8200 1650
$Comp
L Custom_Parts:ESD122 D3
U 1 1 5BA1CDBE
P 4050 2300
F 0 "D3" H 4050 2665 50  0000 C CNN
F 1 "ESD122" H 4050 2574 50  0000 C CNN
F 2 "Custom Parts:DMX0003A" H 4050 2300 50  0001 C CNN
F 3 "" H 4050 2300 50  0001 C CNN
	1    4050 2300
	1    0    0    -1  
$EndComp
Text Label 3700 2400 2    50   ~ 0
USB_N
Text Label 3700 2200 2    50   ~ 0
USB_P
$Comp
L Device:D D1
U 1 1 5B902F50
P 2850 1650
F 0 "D1" H 2850 1866 50  0000 C CNN
F 1 "D_VBUS" H 2850 1775 50  0000 C CNN
F 2 "Custom Parts:X1SON" H 2850 1650 50  0001 C CNN
F 3 "~" H 2850 1650 50  0001 C CNN
	1    2850 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 5BA7F4A1
P 9450 3050
F 0 "BT1" H 9568 3146 50  0000 L CNN
F 1 "CR1620" H 9568 3055 50  0000 L CNN
F 2 "Custom Parts:CR1620_Holder_TH" V 9450 3110 50  0001 C CNN
F 3 "~" V 9450 3110 50  0001 C CNN
	1    9450 3050
	1    0    0    -1  
$EndComp
$Comp
L Custom_Parts:DS3231 U4
U 1 1 5BAADC28
P 8700 3000
F 0 "U4" H 8700 3575 50  0000 C CNN
F 1 "DS3231" H 8700 3484 50  0000 C CNN
F 2 "Housings_SOIC:SOIC-16W_7.5x10.3mm_Pitch1.27mm" H 8700 3000 50  0001 C CNN
F 3 "" H 8700 3000 50  0001 C CNN
	1    8700 3000
	1    0    0    -1  
$EndComp
Text Label 9150 2750 0    50   ~ 0
SDA
Text Label 9150 2650 0    50   ~ 0
SCL
Text Label 8250 2750 2    50   ~ 0
VDD
Text Label 6500 3300 0    50   ~ 0
VBUS
Text Label 8100 1650 2    50   ~ 0
HV_IN
$Comp
L Custom_Parts:TPS2595x0 U7
U 1 1 5BA21006
P 6100 1800
F 0 "U7" H 6100 2175 50  0000 C CNN
F 1 "TPS2595x0" H 6100 2084 50  0000 C CNN
F 2 "Housings_SON:WSON-8_1EP_2x2mm_Pitch0.5mm" H 6100 1800 50  0001 C CNN
F 3 "" H 6100 1800 50  0001 C CNN
	1    6100 1800
	1    0    0    -1  
$EndComp
Text Label 6550 1950 0    50   ~ 0
HV_IN
$Comp
L Device:R R14
U 1 1 5BA6BB6E
P 6900 1600
F 0 "R14" V 6980 1600 50  0000 C CNN
F 1 "680" V 6800 1600 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6830 1600 50  0001 C CNN
F 3 "" H 6900 1600 50  0001 C CNN
	1    6900 1600
	-1   0    0    1   
$EndComp
Text Label 6550 1850 0    50   ~ 0
FAULT
Text Label 5400 5150 2    50   ~ 0
FAULT
Text Label 8250 2850 2    50   ~ 0
RTC
Text Label 6800 4750 0    50   ~ 0
RTC
Text Label 8250 2650 2    50   ~ 0
32kHz
Text Label 5400 4450 2    50   ~ 0
32kHz
Text Label 3500 3400 2    50   ~ 0
USB
Text Label 5400 4650 2    50   ~ 0
NRST
Text Label 2300 2650 0    50   ~ 0
GND
Text Label 4400 1600 0    50   ~ 0
GND
Text Label 4400 2300 0    50   ~ 0
GND
Text Label 4400 3000 0    50   ~ 0
GND
Text Label 4400 3100 0    50   ~ 0
GND
Text Label 5700 2300 0    50   ~ 0
GND
Text Label 6550 1650 0    50   ~ 0
GND
Text Label 6900 1450 0    50   ~ 0
GND
Text Label 8100 1850 2    50   ~ 0
GND
Text Label 8950 1750 0    50   ~ 0
GND
Text Label 8300 4150 2    50   ~ 0
GND
Text Label 6500 3100 0    50   ~ 0
GND
Text Label 5600 2800 2    50   ~ 0
GND
Wire Wire Line
	5350 2900 5600 2900
Text Label 6800 4350 0    50   ~ 0
GND
Text Label 7150 4100 2    50   ~ 0
GND
Text Label 5400 5850 2    50   ~ 0
GND
Text Label 2100 4950 0    50   ~ 0
GND
Text Label 1600 5600 2    50   ~ 0
HV_OUT
Text Label 1600 5700 2    50   ~ 0
HV_OUT
Text Label 2100 5600 0    50   ~ 0
GND
Text Label 2100 5500 0    50   ~ 0
GND
Text Label 2100 5700 0    60   ~ 0
GND
Text Label 2100 6150 0    50   ~ 0
GND
Text Label 1600 6250 2    50   ~ 0
GND
Text Label 2300 2750 0    50   ~ 0
GND
Text Label 2300 2950 0    50   ~ 0
GND
Text Label 2300 3050 0    50   ~ 0
GND
Text Label 2300 3250 0    50   ~ 0
GND
Text Label 2300 3350 0    50   ~ 0
GND
Text Label 2300 3550 0    50   ~ 0
GND
Text Label 2300 3650 0    50   ~ 0
GND
Text Label 2300 3850 0    50   ~ 0
GND
Text Label 2300 3950 0    50   ~ 0
GND
Text Label 1700 4250 3    50   ~ 0
GND
Text Label 1400 4250 3    50   ~ 0
GND
Text Label 2300 2250 0    50   ~ 0
USB_N
Text Label 2300 2350 0    50   ~ 0
USB_P
Text Label 2300 1650 0    50   ~ 0
VBUS
Text Label 5600 3300 2    50   ~ 0
VBUS
Text Label 5600 3200 2    50   ~ 0
VBUS
Text Label 5600 3100 2    50   ~ 0
VBUS
Text Label 5600 3000 2    50   ~ 0
VBUS
$Comp
L Custom_Parts:TPS63025X U3
U 1 1 5B1672A1
P 6050 2900
F 0 "U3" H 6050 3300 60  0000 C CNN
F 1 "TPS63025X" H 6050 3200 60  0000 C CNN
F 2 "Custom Parts:VQFN-14_2.5x3mm_Pitch0.5mm" H 6050 2900 50  0001 C CNN
F 3 "" H 6050 2900 60  0001 C CNN
	1    6050 2900
	1    0    0    -1  
$EndComp
Text Label 6500 2800 0    50   ~ 0
VDD
Text Label 6500 2900 0    50   ~ 0
VDD
Text Label 6950 2700 0    50   ~ 0
VDD
Text Label 6500 3200 0    50   ~ 0
GND
Text Label 5650 1850 2    50   ~ 0
VBUS
Text Label 5650 1950 2    50   ~ 0
VBUS
$Comp
L Device:R R15
U 1 1 5BB93CD7
P 7000 2000
F 0 "R15" V 7080 2000 50  0000 C CNN
F 1 "20k" V 6900 2000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6930 2000 50  0001 C CNN
F 3 "" H 7000 2000 50  0001 C CNN
	1    7000 2000
	-1   0    0    1   
$EndComp
Text Label 7100 1750 0    50   ~ 0
ILM
Text Label 5400 4850 2    50   ~ 0
ILM
Text Label 6800 4850 0    50   ~ 0
USB
$Comp
L Device:R R3
U 1 1 5BB9C8D3
P 3250 3550
F 0 "R3" V 3330 3550 50  0000 C CNN
F 1 "20k" V 3150 3550 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 3180 3550 50  0001 C CNN
F 3 "" H 3250 3550 50  0001 C CNN
	1    3250 3550
	-1   0    0    1   
$EndComp
Text Label 3300 3750 0    50   ~ 0
VDD
$Comp
L Device:C C2
U 1 1 5BB9F4F9
P 5650 2100
F 0 "C2" H 5535 2054 50  0000 R CNN
F 1 "0.1uF" H 5535 2145 50  0000 R CNN
F 2 "Capacitors_SMD:C_0603" H 5688 1950 50  0001 C CNN
F 3 "~" H 5650 2100 50  0001 C CNN
	1    5650 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5BBA0E2E
P 5600 3450
F 0 "C3" H 5485 3404 50  0000 R CNN
F 1 "10uF" H 5485 3495 50  0000 R CNN
F 2 "Capacitors_SMD:C_0603" H 5638 3300 50  0001 C CNN
F 3 "~" H 5600 3450 50  0001 C CNN
	1    5600 3450
	1    0    0    -1  
$EndComp
Text Label 9150 2950 0    50   ~ 0
GND
Text Label 9500 3200 0    50   ~ 0
GND
$Comp
L Device:C C11
U 1 1 5BBA5067
P 7200 3000
F 0 "C11" H 7085 2954 50  0000 R CNN
F 1 "220uF" H 7085 3045 50  0000 R CNN
F 2 "Capacitors_SMD:C_1210" H 7238 2850 50  0001 C CNN
F 3 "~" H 7200 3000 50  0001 C CNN
	1    7200 3000
	-1   0    0    1   
$EndComp
$Comp
L Device:C C13
U 1 1 5BBA50C7
P 4650 4200
F 0 "C13" H 4535 4154 50  0000 R CNN
F 1 "4.7uF" H 4535 4245 50  0000 R CNN
F 2 "Capacitors_SMD:C_0603" H 4688 4050 50  0001 C CNN
F 3 "~" H 4650 4200 50  0001 C CNN
	1    4650 4200
	-1   0    0    1   
$EndComp
$Comp
L Device:C C12
U 1 1 5BBA51A2
P 5050 4050
F 0 "C12" H 4935 4004 50  0000 R CNN
F 1 "0.1uF" H 4935 4095 50  0000 R CNN
F 2 "Capacitors_SMD:C_0603" H 5088 3900 50  0001 C CNN
F 3 "~" H 5050 4050 50  0001 C CNN
	1    5050 4050
	-1   0    0    1   
$EndComp
$Comp
L Custom_Parts:AD8591 U5
U 1 1 5BBE6227
P 8700 4150
F 0 "U5" H 8700 4475 50  0000 C CNN
F 1 "AD8591" H 8700 4384 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-6" H 8700 4150 50  0001 C CNN
F 3 "" H 8700 4150 50  0001 C CNN
	1    8700 4150
	1    0    0    -1  
$EndComp
Text Label 9100 4150 0    50   ~ 0
AMP_EN
$Comp
L Device:C C1
U 1 1 5BA4D5A1
P 6550 2100
F 0 "C1" H 6435 2054 50  0000 R CNN
F 1 "330uF" H 6435 2145 50  0000 R CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-X_EIA-7343-43_Reflow" H 6588 1950 50  0001 C CNN
F 3 "~" H 6550 2100 50  0001 C CNN
	1    6550 2100
	-1   0    0    1   
$EndComp
$Comp
L Mechanical:MountingHole_Pad MH1
U 1 1 5BA440F1
P 8450 4900
F 0 "MH1" V 8404 5050 50  0000 L CNN
F 1 "MountingHole_Pad" V 8495 5050 50  0000 L CNN
F 2 "Custom Parts:MountingHole_2.5mm_Pad_Via" H 8450 4900 50  0001 C CNN
F 3 "~" H 8450 4900 50  0001 C CNN
	1    8450 4900
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad MH2
U 1 1 5BA441AA
P 8450 5100
F 0 "MH2" V 8404 5250 50  0000 L CNN
F 1 "MountingHole_Pad" V 8495 5250 50  0000 L CNN
F 2 "Custom Parts:MountingHole_2.5mm_Pad_Via" H 8450 5100 50  0001 C CNN
F 3 "~" H 8450 5100 50  0001 C CNN
	1    8450 5100
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad MH3
U 1 1 5BA44208
P 8450 5300
F 0 "MH3" V 8404 5450 50  0000 L CNN
F 1 "MountingHole_Pad" V 8495 5450 50  0000 L CNN
F 2 "Custom Parts:MountingHole_2.5mm_Pad_Via" H 8450 5300 50  0001 C CNN
F 3 "~" H 8450 5300 50  0001 C CNN
	1    8450 5300
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad MH4
U 1 1 5BA44262
P 8450 5500
F 0 "MH4" V 8404 5650 50  0000 L CNN
F 1 "MountingHole_Pad" V 8495 5650 50  0000 L CNN
F 2 "Custom Parts:MountingHole_2.5mm_Pad_Via" H 8450 5500 50  0001 C CNN
F 3 "~" H 8450 5500 50  0001 C CNN
	1    8450 5500
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad MH5
U 1 1 5BA442D8
P 8450 5700
F 0 "MH5" V 8404 5850 50  0000 L CNN
F 1 "MountingHole_Pad" V 8495 5850 50  0000 L CNN
F 2 "Mounting_Holes:MountingHole_2.5mm_Pad_Via" H 8450 5700 50  0001 C CNN
F 3 "~" H 8450 5700 50  0001 C CNN
	1    8450 5700
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad MH6
U 1 1 5BA44348
P 8450 5900
F 0 "MH6" V 8404 6050 50  0000 L CNN
F 1 "MountingHole_Pad" V 8495 6050 50  0000 L CNN
F 2 "Mounting_Holes:MountingHole_2.5mm_Pad_Via" H 8450 5900 50  0001 C CNN
F 3 "~" H 8450 5900 50  0001 C CNN
	1    8450 5900
	0    1    1    0   
$EndComp
Text Label 8350 4900 2    50   ~ 0
GND
Text Label 8350 5100 2    50   ~ 0
GND
Text Label 8350 5300 2    50   ~ 0
GND
Text Label 8350 5500 2    50   ~ 0
GND
Text Label 8350 5700 2    50   ~ 0
GND
Text Label 8350 5900 2    50   ~ 0
GND
$Comp
L Device:R R16
U 1 1 5BA5D464
P 6900 2850
F 0 "R16" V 6980 2850 50  0000 C CNN
F 1 "560k" V 6800 2850 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6830 2850 50  0001 C CNN
F 3 "" H 6900 2850 50  0001 C CNN
	1    6900 2850
	-1   0    0    1   
$EndComp
$Comp
L Device:R R17
U 1 1 5BA5D560
P 6900 3150
F 0 "R17" V 6980 3150 50  0000 C CNN
F 1 "180k" V 6800 3150 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6830 3150 50  0001 C CNN
F 3 "" H 6900 3150 50  0001 C CNN
	1    6900 3150
	-1   0    0    1   
$EndComp
Text Label 6950 3350 0    50   ~ 0
GND
Wire Wire Line
	6900 3300 6900 3350
Wire Wire Line
	6900 3000 6500 3000
Connection ~ 6900 3000
Text Label 1600 6350 2    50   ~ 0
NIXIE_EN
Text Label 5400 5550 2    50   ~ 0
NIXIE_EN
$Comp
L Switch:SW_Push SW2
U 1 1 5BA5FF24
P 7400 4450
F 0 "SW2" H 7400 4735 50  0000 C CNN
F 1 "DFU" H 7400 4644 50  0000 C CNN
F 2 "Custom Parts:EVQP2" H 7400 4650 50  0001 C CNN
F 3 "" H 7400 4650 50  0001 C CNN
	1    7400 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 4450 7150 4450
Wire Wire Line
	7150 4450 6800 4450
Connection ~ 7150 4450
Text Label 7600 4450 0    50   ~ 0
VDD
Text Label 4750 3900 0    50   ~ 0
GND
Wire Wire Line
	2300 1650 2700 1650
Text Label 6500 2300 2    50   ~ 0
GND
Wire Wire Line
	6900 2700 7200 2700
Wire Wire Line
	7200 2700 7200 2850
Wire Wire Line
	7200 3150 7200 3350
Wire Wire Line
	6900 3350 7200 3350
Wire Wire Line
	4650 4350 5050 4350
Wire Wire Line
	5050 4200 5050 4350
Connection ~ 5050 4350
Wire Wire Line
	5050 4350 5400 4350
Wire Wire Line
	4650 3900 4650 4050
Wire Wire Line
	5600 3600 5600 3650
Wire Wire Line
	5600 3650 5650 3650
Text Label 5650 3650 0    50   ~ 0
GND
Wire Wire Line
	6800 5550 7300 5550
Wire Wire Line
	7300 5550 7300 5500
Wire Wire Line
	6800 5650 7600 5650
Wire Wire Line
	7600 5650 7600 5500
Text Label 7300 5200 0    50   ~ 0
VDD
Text Label 7600 5200 0    50   ~ 0
VDD
Wire Wire Line
	6550 1750 6900 1750
Wire Wire Line
	6550 1850 7000 1850
Wire Wire Line
	7000 2150 7000 2200
Wire Wire Line
	7000 2200 7050 2200
Text Label 7050 2200 0    50   ~ 0
VDD
Wire Wire Line
	3500 3400 3250 3400
Wire Wire Line
	3250 3700 3250 3750
Wire Wire Line
	3250 3750 3300 3750
Text Label 3000 1650 0    50   ~ 0
GND
Wire Wire Line
	9150 2850 9450 2850
Wire Wire Line
	9450 3150 9450 3200
Wire Wire Line
	9450 3200 9500 3200
Text Label 4700 4750 2    50   ~ 0
GND
$Comp
L Device:R R18
U 1 1 5BAE3A6C
P 7800 2600
F 0 "R18" V 7880 2600 50  0000 C CNN
F 1 "10k" V 7700 2600 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 7730 2600 50  0001 C CNN
F 3 "" H 7800 2600 50  0001 C CNN
	1    7800 2600
	-1   0    0    1   
$EndComp
Text Label 8250 2950 2    50   ~ 0
NRST
$Comp
L Device:R R19
U 1 1 5BAE5355
P 7800 2900
F 0 "R19" V 7880 2900 50  0000 C CNN
F 1 "20k" V 7700 2900 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 7730 2900 50  0001 C CNN
F 3 "" H 7800 2900 50  0001 C CNN
	1    7800 2900
	-1   0    0    1   
$EndComp
Wire Wire Line
	8250 2650 7950 2650
Wire Wire Line
	7950 2650 7950 2450
Wire Wire Line
	7950 2450 7800 2450
Wire Wire Line
	8250 2850 7950 2850
Wire Wire Line
	7950 2850 7950 3050
Wire Wire Line
	7950 3050 7800 3050
Wire Wire Line
	8250 2750 7800 2750
Connection ~ 7800 2750
$Comp
L Custom_Parts:TUSB322 U1
U 1 1 5BAF8A3A
P 3950 3000
F 0 "U1" H 3950 3325 50  0000 C CNN
F 1 "TUSB322" H 3950 3234 50  0000 C CNN
F 2 "Custom Parts:X2QFN-12_1.6x1.6mm_Pitch0.4mm" H 3950 3000 50  0001 C CNN
F 3 "" H 3950 3000 50  0001 C CNN
	1    3950 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 3100 3150 3100
NoConn ~ 3500 3200
Text Label 3500 3300 2    50   ~ 0
GND
NoConn ~ 4400 3200
Wire Wire Line
	3150 3400 3150 3450
Wire Wire Line
	3150 3450 3100 3450
Connection ~ 6900 1750
Text Label 5400 5750 2    50   ~ 0
AMP_EN
$Comp
L Device:C C15
U 1 1 5BB2A736
P 7050 6000
F 0 "C15" H 6935 5954 50  0000 R CNN
F 1 "0.1uF" H 6935 6045 50  0000 R CNN
F 2 "Capacitors_SMD:C_0603" H 7088 5850 50  0001 C CNN
F 3 "~" H 7050 6000 50  0001 C CNN
	1    7050 6000
	-1   0    0    1   
$EndComp
Wire Wire Line
	7050 5850 6800 5850
Wire Wire Line
	7050 6150 7050 6200
Wire Wire Line
	7050 6200 7000 6200
Text Label 7000 6200 2    50   ~ 0
GND
Text Label 5650 1750 2    50   ~ 0
HV_EN
$Comp
L Device:R R12
U 1 1 5BB3910C
P 5250 1600
F 0 "R12" V 5330 1600 50  0000 C CNN
F 1 "20k" V 5150 1600 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 5180 1600 50  0001 C CNN
F 3 "" H 5250 1600 50  0001 C CNN
	1    5250 1600
	-1   0    0    1   
$EndComp
Wire Wire Line
	5650 2250 5650 2300
Wire Wire Line
	5650 2300 5700 2300
Text Label 5250 1450 2    50   ~ 0
GND
Wire Wire Line
	6550 2250 6550 2300
Wire Wire Line
	6550 2300 6500 2300
Text Label 4800 3250 0    50   ~ 0
GND
Wire Wire Line
	4750 3250 4800 3250
Wire Wire Line
	4750 3200 4750 3250
Wire Wire Line
	4400 2900 4750 2900
$Comp
L Device:C C14
U 1 1 5BAF2024
P 4750 3050
F 0 "C14" H 4635 3004 50  0000 R CNN
F 1 "0.1uF" H 4635 3095 50  0000 R CNN
F 2 "Capacitors_SMD:C_0603" H 4788 2900 50  0001 C CNN
F 3 "~" H 4750 3050 50  0001 C CNN
	1    4750 3050
	-1   0    0    1   
$EndComp
$Comp
L Device:C C16
U 1 1 5BA9CB71
P 9350 3850
F 0 "C16" H 9235 3804 50  0000 R CNN
F 1 "1uF" H 9235 3895 50  0000 R CNN
F 2 "Capacitors_SMD:C_0603" H 9388 3700 50  0001 C CNN
F 3 "~" H 9350 3850 50  0001 C CNN
	1    9350 3850
	-1   0    0    1   
$EndComp
Wire Wire Line
	9350 4000 9350 4050
Wire Wire Line
	9350 4050 9100 4050
Text Label 9350 3700 0    50   ~ 0
GND
$Comp
L Connector:Conn_01x01_Female J7
U 1 1 5BA9F87B
P 3050 4900
F 0 "J7" H 3077 4926 50  0000 L CNN
F 1 "HV_EN" H 3077 4835 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.5mm" H 3050 4900 50  0001 C CNN
F 3 "~" H 3050 4900 50  0001 C CNN
	1    3050 4900
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J6
U 1 1 5BAA5791
P 3050 4700
F 0 "J6" H 3077 4726 50  0000 L CNN
F 1 "ILM" H 3077 4635 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.5mm" H 3050 4700 50  0001 C CNN
F 3 "~" H 3050 4700 50  0001 C CNN
	1    3050 4700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J13
U 1 1 5BAB0421
P 3850 4900
F 0 "J13" H 3877 4926 50  0000 L CNN
F 1 "DAC" H 3877 4835 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.5mm" H 3850 4900 50  0001 C CNN
F 3 "~" H 3850 4900 50  0001 C CNN
	1    3850 4900
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J14
U 1 1 5BAB2A61
P 3850 5100
F 0 "J14" H 3877 5126 50  0000 L CNN
F 1 "VDD" H 3877 5035 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.5mm" H 3850 5100 50  0001 C CNN
F 3 "~" H 3850 5100 50  0001 C CNN
	1    3850 5100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J8
U 1 1 5BAB35ED
P 3050 5100
F 0 "J8" H 3077 5126 50  0000 L CNN
F 1 "HV_OUT" H 3077 5035 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.5mm" H 3050 5100 50  0001 C CNN
F 3 "~" H 3050 5100 50  0001 C CNN
	1    3050 5100
	1    0    0    -1  
$EndComp
Text Label 2850 4700 2    50   ~ 0
ILM
Wire Wire Line
	6900 1750 7100 1750
Wire Wire Line
	8950 1650 8850 1650
Text Label 2850 4900 2    50   ~ 0
HV_EN
Wire Wire Line
	5250 1750 5650 1750
Text Label 3650 5100 2    50   ~ 0
VDD
Text Label 3650 4900 2    50   ~ 0
DAC
Text Label 6800 5750 0    50   ~ 0
MCO
Text Label 2850 4500 2    50   ~ 0
MCO
Text Label 2850 5100 2    50   ~ 0
HV_OUT
$Comp
L Connector:Conn_01x01_Female J11
U 1 1 5BAC8048
P 3850 4500
F 0 "J11" H 3877 4526 50  0000 L CNN
F 1 "SCL" H 3877 4435 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.5mm" H 3850 4500 50  0001 C CNN
F 3 "~" H 3850 4500 50  0001 C CNN
	1    3850 4500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J12
U 1 1 5BAC80D4
P 3850 4700
F 0 "J12" H 3877 4726 50  0000 L CNN
F 1 "SDA" H 3877 4635 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.5mm" H 3850 4700 50  0001 C CNN
F 3 "~" H 3850 4700 50  0001 C CNN
	1    3850 4700
	1    0    0    -1  
$EndComp
Text Label 3650 4500 2    50   ~ 0
SCL
Text Label 3650 4700 2    50   ~ 0
SDA
$Comp
L Connector:Conn_01x01_Female J9
U 1 1 5BAC83B4
P 3050 5300
F 0 "J9" H 3077 5326 50  0000 L CNN
F 1 "AMP_EN" H 3077 5235 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.5mm" H 3050 5300 50  0001 C CNN
F 3 "~" H 3050 5300 50  0001 C CNN
	1    3050 5300
	1    0    0    -1  
$EndComp
Text Label 2850 5300 2    50   ~ 0
AMP_EN
$Comp
L Connector:Conn_01x01_Female J10
U 1 1 5BAC8BC2
P 3050 5500
F 0 "J10" H 3077 5526 50  0000 L CNN
F 1 "32kHz" H 3077 5435 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.5mm" H 3050 5500 50  0001 C CNN
F 3 "~" H 3050 5500 50  0001 C CNN
	1    3050 5500
	1    0    0    -1  
$EndComp
Text Label 2850 5500 2    50   ~ 0
32kHz
Text Label 3650 5300 2    50   ~ 0
VNIXIE
$Comp
L Connector:Conn_01x01_Female J15
U 1 1 5BAF3226
P 3850 5300
F 0 "J15" H 3877 5326 50  0000 L CNN
F 1 "VNIXIE" H 3877 5235 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.5mm" H 3850 5300 50  0001 C CNN
F 3 "~" H 3850 5300 50  0001 C CNN
	1    3850 5300
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J16
U 1 1 5BAD1FCF
P 3850 5500
F 0 "J16" H 3877 5526 50  0000 L CNN
F 1 "VBUS" H 3877 5435 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.5mm" H 3850 5500 50  0001 C CNN
F 3 "~" H 3850 5500 50  0001 C CNN
	1    3850 5500
	1    0    0    -1  
$EndComp
Text Label 3650 5500 2    50   ~ 0
VBUS
$Comp
L Device:LED D5
U 1 1 5BADCAA0
P 3200 6300
F 0 "D5" H 3191 6516 50  0000 C CNN
F 1 "LED" H 3191 6425 50  0000 C CNN
F 2 "LEDs:LED_0603" H 3200 6300 50  0001 C CNN
F 3 "~" H 3200 6300 50  0001 C CNN
	1    3200 6300
	-1   0    0    1   
$EndComp
$Comp
L Device:R R13
U 1 1 5BADE6EA
P 2900 6300
F 0 "R13" V 2980 6300 50  0000 C CNN
F 1 "10k" V 2800 6300 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 2830 6300 50  0001 C CNN
F 3 "" H 2900 6300 50  0001 C CNN
	1    2900 6300
	0    -1   -1   0   
$EndComp
Text Label 3400 6300 0    50   ~ 0
GND
Wire Wire Line
	5400 4650 5150 4650
Wire Wire Line
	5150 4650 5150 4750
Wire Wire Line
	5150 4750 5100 4750
$Comp
L Device:C C17
U 1 1 5BAFD7B9
P 5500 1500
F 0 "C17" H 5385 1454 50  0000 R CNN
F 1 "SLEW" H 5385 1545 50  0000 R CNN
F 2 "Capacitors_SMD:C_0603" H 5538 1350 50  0001 C CNN
F 3 "~" H 5500 1500 50  0001 C CNN
	1    5500 1500
	-1   0    0    1   
$EndComp
Wire Wire Line
	5650 1650 5500 1650
Text Label 5500 1350 2    50   ~ 0
GND
Text Label 3650 5700 2    50   ~ 0
SWO
$Comp
L Connector:Conn_01x01_Female J17
U 1 1 5BAE0437
P 3850 5700
F 0 "J17" H 3877 5726 50  0000 L CNN
F 1 "SWO" H 3877 5635 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.5mm" H 3850 5700 50  0001 C CNN
F 3 "~" H 3850 5700 50  0001 C CNN
	1    3850 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 3900 4650 3900
Text Label 9150 3050 0    50   ~ 0
GND
Text Label 9150 3150 0    50   ~ 0
GND
Text Label 9150 3250 0    50   ~ 0
GND
Text Label 9150 3350 0    50   ~ 0
GND
Text Label 8250 3050 2    50   ~ 0
GND
Text Label 8250 3150 2    50   ~ 0
GND
Text Label 8250 3250 2    50   ~ 0
GND
Text Label 8250 3350 2    50   ~ 0
GND
NoConn ~ 6800 5050
NoConn ~ 5400 5250
NoConn ~ 5400 5450
NoConn ~ 5400 5650
$Comp
L Connector:Conn_01x01_Female J18
U 1 1 5BB2EA59
P 3050 5700
F 0 "J18" H 3077 5726 50  0000 L CNN
F 1 "NRST" H 3077 5635 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.5mm" H 3050 5700 50  0001 C CNN
F 3 "~" H 3050 5700 50  0001 C CNN
	1    3050 5700
	1    0    0    -1  
$EndComp
Text Label 2850 5700 2    50   ~ 0
NRST
Wire Wire Line
	7150 4400 7150 4450
Wire Wire Line
	3400 6300 3350 6300
$Comp
L Device:R R20
U 1 1 5BB58A31
P 4650 5200
F 0 "R20" V 4730 5200 50  0000 C CNN
F 1 "1M" V 4550 5200 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4580 5200 50  0001 C CNN
F 3 "" H 4650 5200 50  0001 C CNN
	1    4650 5200
	-1   0    0    1   
$EndComp
$Comp
L Device:R R21
U 1 1 5BB58B15
P 4950 5200
F 0 "R21" V 5030 5200 50  0000 C CNN
F 1 "15k" V 4850 5200 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4880 5200 50  0001 C CNN
F 3 "" H 4950 5200 50  0001 C CNN
	1    4950 5200
	-1   0    0    1   
$EndComp
Wire Wire Line
	4950 5350 4950 5400
Wire Wire Line
	4950 5400 4900 5400
Wire Wire Line
	4650 5350 4650 5400
Wire Wire Line
	4650 5400 4600 5400
Text Label 4600 5400 2    50   ~ 0
HV_OUT
Text Label 4900 5400 2    50   ~ 0
GND
Wire Wire Line
	4650 4950 4950 4950
Wire Wire Line
	4650 4950 4650 5050
Wire Wire Line
	4950 5050 4950 4950
Connection ~ 4950 4950
Wire Wire Line
	4950 4950 5400 4950
$Comp
L Connector:USB_C_Receptacle J1
U 1 1 5C65F90A
P 1700 2650
F 0 "J1" H 1805 3917 50  0000 C CNN
F 1 "USB_C_Receptacle" H 1805 3826 50  0000 C CNN
F 2 "Custom Parts:USB_C_Receptacle_Circular_Holes" H 1850 2650 50  0001 C CNN
F 3 "https://www.usb.org/sites/default/files/documents/usb_type-c.zip" H 1850 2650 50  0001 C CNN
	1    1700 2650
	1    0    0    -1  
$EndComp
Text Label 2750 6300 2    50   ~ 0
LED
Text Label 6800 4650 0    50   ~ 0
UART_TX
Text Label 6800 4550 0    50   ~ 0
UART_RX
Text Label 5400 4550 2    50   ~ 0
LED
Text Label 3650 5900 2    50   ~ 0
UART_RX
Text Label 2850 5900 2    50   ~ 0
UART_TX
$Comp
L Connector:Conn_01x01_Female J19
U 1 1 5C68D771
P 3050 5900
F 0 "J19" H 3077 5926 50  0000 L CNN
F 1 "TX" H 3077 5835 50  0000 L CNN
F 2 "TestPoint:TestPoint_THTPad_D1.5mm_Drill0.7mm" H 3050 5900 50  0001 C CNN
F 3 "~" H 3050 5900 50  0001 C CNN
	1    3050 5900
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J20
U 1 1 5C68D805
P 3850 5900
F 0 "J20" H 3877 5926 50  0000 L CNN
F 1 "RX" H 3877 5835 50  0000 L CNN
F 2 "TestPoint:TestPoint_THTPad_D1.5mm_Drill0.7mm" H 3850 5900 50  0001 C CNN
F 3 "~" H 3850 5900 50  0001 C CNN
	1    3850 5900
	1    0    0    -1  
$EndComp
Text Label 3650 6100 2    50   ~ 0
GND
$Comp
L Connector:Conn_01x01_Female J21
U 1 1 5C6A9997
P 3850 6100
F 0 "J21" H 3877 6126 50  0000 L CNN
F 1 "GND" H 3877 6035 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.5mm" H 3850 6100 50  0001 C CNN
F 3 "~" H 3850 6100 50  0001 C CNN
	1    3850 6100
	1    0    0    -1  
$EndComp
$EndSCHEMATC
