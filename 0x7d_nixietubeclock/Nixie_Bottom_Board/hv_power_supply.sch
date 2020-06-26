EESchema Schematic File Version 4
LIBS:nixie_bottom_board-cache
EELAYER 26 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 2 2
Title "Bottom PCB"
Date ""
Rev "B"
Comp "Nixie Tube Clock"
Comment1 "https://0x7d.com/2017/nixie-tube-clock"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Custom_Parts:Wurth_Transformer_10.16x13.36mm T1
U 1 1 5A6B88EA
P 6450 3150
F 0 "T1" H 6450 3475 60  0000 C CNN
F 1 "Wurth_Transformer_10.16x13.36mm" H 6450 3575 60  0000 C CNN
F 2 "Custom Parts:Wurth_WE-FB_10.18x13.36mm_Reverse" H 6450 3575 60  0001 C CNN
F 3 "" H 6450 3575 60  0001 C CNN
	1    6450 3150
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 5A6B8978
P 3650 4000
F 0 "R7" V 3730 4000 50  0000 C CNN
F 1 "R_VC" V 3550 4000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 3580 4000 50  0001 C CNN
F 3 "" H 3650 4000 50  0001 C CNN
	1    3650 4000
	0    1    1    0   
$EndComp
$Comp
L Device:C C5
U 1 1 5A6B89DB
P 3100 4300
F 0 "C5" H 3125 4400 50  0000 L CNN
F 1 "C_VC" H 3125 4200 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3138 4150 50  0001 C CNN
F 3 "" H 3100 4300 50  0001 C CNN
	1    3100 4300
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_DGS Q1
U 1 1 5A6B8B05
P 5950 3750
F 0 "Q1" H 6150 3800 50  0000 L CNN
F 1 "Q_SWITCH" H 6150 3700 50  0000 L CNN
F 2 "Custom Parts:SOT-669_LFPAK" H 6150 3850 50  0001 C CNN
F 3 "" H 5950 3750 50  0001 C CNN
	1    5950 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R11
U 1 1 5A6B8B69
P 6800 4000
F 0 "R11" V 6880 4000 50  0000 C CNN
F 1 "R_SENSE" V 6700 4000 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 6730 4000 50  0001 C CNN
F 3 "" H 6800 4000 50  0001 C CNN
	1    6800 4000
	0    1    1    0   
$EndComp
$Comp
L Device:D D4
U 1 1 5A6B91C6
P 7100 3350
F 0 "D4" H 7100 3450 50  0000 C CNN
F 1 "D_RECT" H 7100 3250 50  0000 C CNN
F 2 "Custom Parts:SOD-123W" H 7100 3350 50  0001 C CNN
F 3 "" H 7100 3350 50  0001 C CNN
	1    7100 3350
	-1   0    0    1   
$EndComp
$Comp
L Device:C C8
U 1 1 5A6B92D0
P 7400 3150
F 0 "C8" H 7425 3250 50  0000 L CNN
F 1 "C_OUT" H 7425 3050 50  0000 L CNN
F 2 "Capacitors_SMD:C_2220" H 7438 3000 50  0001 C CNN
F 3 "" H 7400 3150 50  0001 C CNN
	1    7400 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C9
U 1 1 5A6B93C6
P 7700 3150
F 0 "C9" H 7725 3250 50  0000 L CNN
F 1 "C_OUT" H 7725 3050 50  0000 L CNN
F 2 "Capacitors_SMD:C_1812" H 7738 3000 50  0001 C CNN
F 3 "" H 7700 3150 50  0001 C CNN
	1    7700 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R10
U 1 1 5A6B9F37
P 6500 4300
F 0 "R10" V 6580 4300 50  0000 C CNN
F 1 "R_FB" V 6400 4300 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6430 4300 50  0001 C CNN
F 3 "" H 6500 4300 50  0001 C CNN
	1    6500 4300
	0    1    1    0   
$EndComp
$Comp
L Device:R R9
U 1 1 5A6B9FBA
P 6150 4700
F 0 "R9" V 6230 4700 50  0000 C CNN
F 1 "R_BIAS" V 6050 4700 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6080 4700 50  0001 C CNN
F 3 "" H 6150 4700 50  0001 C CNN
	1    6150 4700
	-1   0    0    1   
$EndComp
$Comp
L Device:C C7
U 1 1 5A6BA4CA
P 5700 4700
F 0 "C7" H 5725 4800 50  0000 L CNN
F 1 "C_BP" H 5725 4600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5738 4550 50  0001 C CNN
F 3 "" H 5700 4700 50  0001 C CNN
	1    5700 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5A6BAAF4
P 3450 4500
F 0 "R6" V 3530 4500 50  0000 C CNN
F 1 "R_FREQ" V 3350 4500 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 3380 4500 50  0001 C CNN
F 3 "" H 3450 4500 50  0001 C CNN
	1    3450 4500
	-1   0    0    1   
$EndComp
$Comp
L Device:C C4
U 1 1 5A6C0FBE
P 4000 3150
F 0 "C4" H 4025 3250 50  0000 L CNN
F 1 "C_IN" H 4025 3050 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 4038 3000 50  0001 C CNN
F 3 "" H 4000 3150 50  0001 C CNN
	1    4000 3150
	-1   0    0    1   
$EndComp
NoConn ~ 6850 3150
$Comp
L Device:C C6
U 1 1 5A6C6769
P 3700 4700
F 0 "C6" H 3725 4800 50  0000 L CNN
F 1 "C_SS" H 3725 4600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3738 4550 50  0001 C CNN
F 3 "" H 3700 4700 50  0001 C CNN
	1    3700 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 5A8E442D
P 5600 3750
F 0 "R8" V 5680 3750 50  0000 C CNN
F 1 "R_GATE" V 5500 3750 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 5530 3750 50  0001 C CNN
F 3 "" H 5600 3750 50  0001 C CNN
	1    5600 3750
	0    1    1    0   
$EndComp
Wire Wire Line
	6950 4000 7050 4000
Connection ~ 6150 4300
Wire Wire Line
	6150 4300 6150 4550
Wire Wire Line
	5450 4300 6150 4300
Wire Wire Line
	6150 4950 6150 4850
Connection ~ 3850 3550
Wire Wire Line
	3850 3550 3950 3550
Wire Wire Line
	3850 3700 3950 3700
Wire Wire Line
	3950 3850 3050 3850
Connection ~ 3100 4950
Connection ~ 3450 4950
Wire Wire Line
	3100 4950 3100 4450
Wire Wire Line
	3100 4000 3100 4150
Wire Wire Line
	3500 4000 3100 4000
Wire Wire Line
	3950 4000 3800 4000
Wire Wire Line
	3450 4150 3950 4150
Wire Wire Line
	3450 4350 3450 4150
Connection ~ 3700 4950
Wire Wire Line
	3450 4950 3450 4650
Connection ~ 3950 4950
Wire Wire Line
	3700 4950 3700 4850
Wire Wire Line
	3700 4300 3950 4300
Wire Wire Line
	3700 4550 3700 4300
Connection ~ 5700 4950
Wire Wire Line
	3950 4950 3950 4450
Wire Wire Line
	5700 4850 5700 4950
Wire Wire Line
	3050 4950 3100 4950
Wire Wire Line
	5700 4450 5700 4550
Wire Wire Line
	7400 4300 6650 4300
Connection ~ 4650 2950
Connection ~ 4800 2950
Wire Wire Line
	4650 2950 4650 3150
Wire Wire Line
	4800 2950 4800 3150
Connection ~ 6050 4000
Wire Wire Line
	5450 4000 6050 4000
Wire Wire Line
	6050 3950 6050 4000
Connection ~ 7700 3350
Connection ~ 7400 3350
Wire Wire Line
	7700 3350 7700 3300
Wire Wire Line
	7400 3300 7400 3350
Wire Wire Line
	7250 3350 7400 3350
Wire Wire Line
	6850 3350 6950 3350
Connection ~ 7400 2950
Wire Wire Line
	7400 2950 7400 3000
Connection ~ 7700 2950
Wire Wire Line
	7700 2950 7700 3000
Wire Wire Line
	6050 3350 6050 3550
Wire Wire Line
	5700 4450 5450 4450
$Comp
L Custom_Parts:LTC3759 U6
U 1 1 5A6BF1D9
P 4700 4000
F 0 "U6" H 4700 4000 60  0000 C CNN
F 1 "LTC3759" H 4700 3900 60  0000 C CNN
F 2 "Housings_SSOP:MSOP-12-1EP_3x4mm_Pitch0.65mm" H 4700 4100 60  0001 C CNN
F 3 "" H 4700 4100 60  0001 C CNN
	1    4700 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 3000 4000 2950
Connection ~ 4000 2950
Wire Wire Line
	4000 3350 4000 3300
Text HLabel 3050 2950 0    60   Input ~ 0
VIN
Text HLabel 3050 3850 0    60   Input ~ 0
EN
Text HLabel 3050 4950 0    60   Input ~ 0
GND
Text HLabel 8200 2950 2    60   Input ~ 0
GND
Text HLabel 8200 3350 2    60   Input ~ 0
VOUT
Wire Wire Line
	6150 4300 6350 4300
Wire Wire Line
	3850 3550 3850 3700
Wire Wire Line
	3850 3350 3850 3550
Wire Wire Line
	3100 4950 3450 4950
Wire Wire Line
	3450 4950 3700 4950
Wire Wire Line
	3700 4950 3950 4950
Wire Wire Line
	3950 4950 5700 4950
Wire Wire Line
	5700 4950 6150 4950
Wire Wire Line
	4650 2950 4800 2950
Wire Wire Line
	4800 2950 6050 2950
Wire Wire Line
	6050 4000 6650 4000
Wire Wire Line
	7700 3350 8000 3350
Wire Wire Line
	7400 3350 7400 4300
Wire Wire Line
	7400 3350 7700 3350
Wire Wire Line
	7400 2950 7700 2950
Wire Wire Line
	7700 2950 8000 2950
Wire Wire Line
	4000 2950 4650 2950
$Comp
L Device:C C10
U 1 1 5B6DF384
P 8000 3150
F 0 "C10" H 8025 3250 50  0000 L CNN
F 1 "C_OUT" H 8025 3050 50  0000 L CNN
F 2 "Capacitors_SMD:C_2220" H 8038 3000 50  0001 C CNN
F 3 "" H 8000 3150 50  0001 C CNN
	1    8000 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 3000 8000 2950
Connection ~ 8000 2950
Wire Wire Line
	8000 2950 8200 2950
Wire Wire Line
	8000 3300 8000 3350
Connection ~ 8000 3350
Wire Wire Line
	8000 3350 8200 3350
Text Label 3750 3350 2    60   ~ 0
GND
Text Label 5650 4950 2    60   ~ 0
GND
Wire Wire Line
	6850 2950 7400 2950
Text Label 7450 2950 0    60   ~ 0
GND
Wire Wire Line
	3050 2950 4000 2950
Wire Wire Line
	3850 3350 4000 3350
Connection ~ 3850 3350
Wire Wire Line
	3750 3350 3850 3350
Text Label 7050 4000 0    60   ~ 0
GND
$EndSCHEMATC
