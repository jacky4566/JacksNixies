EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:R_Small R44
U 1 1 5CE5BEE6
P 3625 5450
F 0 "R44" V 3550 5325 50  0000 C CNN
F 1 "86.6K" V 3550 5525 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3625 5450 50  0001 C CNN
F 3 "~" H 3625 5450 50  0001 C CNN
	1    3625 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3625 5350 3725 5350
Wire Wire Line
	3625 5550 3625 5650
Wire Wire Line
	3625 5650 3725 5650
$Comp
L Device:C_Small C11
U 1 1 5CE5BEEF
P 3450 5350
F 0 "C11" V 3625 5525 50  0000 L CNN
F 1 "150nF" V 3500 5400 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3450 5350 50  0001 C CNN
F 3 "~" H 3450 5350 50  0001 C CNN
	1    3450 5350
	-1   0    0    1   
$EndComp
Wire Wire Line
	3450 5250 3725 5250
Wire Wire Line
	3450 5450 3450 5650
Wire Wire Line
	3450 5650 3625 5650
Connection ~ 3625 5650
$Comp
L Device:R_Small R43
U 1 1 5CE5BEF9
P 3550 5150
F 0 "R43" V 3400 5150 50  0000 C CNN
F 1 "300k" V 3475 5150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3550 5150 50  0001 C CNN
F 3 "~" H 3550 5150 50  0001 C CNN
	1    3550 5150
	0    1    1    0   
$EndComp
Wire Wire Line
	3325 5650 3450 5650
Connection ~ 3450 5650
Wire Wire Line
	3650 5150 3725 5150
Wire Wire Line
	3325 5350 3325 5650
$Comp
L Device:C_Small C9
U 1 1 5CE5BF03
P 3325 5250
F 0 "C9" V 3500 5200 50  0000 L CNN
F 1 "560pF" V 3425 5150 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3325 5250 50  0001 C CNN
F 3 "~" H 3325 5250 50  0001 C CNN
	1    3325 5250
	-1   0    0    1   
$EndComp
Wire Wire Line
	3450 5150 3325 5150
Text GLabel 3400 5050 0    50   Input ~ 0
BOOSTEN
Wire Wire Line
	3400 5050 3725 5050
$Comp
L Device:C_Small C12
U 1 1 5CE5BF1E
P 4675 5050
F 0 "C12" H 4450 5050 50  0000 L CNN
F 1 "0.1uF" H 4400 5125 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4675 5050 50  0001 C CNN
F 3 "~" H 4675 5050 50  0001 C CNN
	1    4675 5050
	0    1    1    0   
$EndComp
$Comp
L Transistor_FET:PSMN5R2-60YL Q43
U 1 1 5CE5BF2A
P 5375 5350
F 0 "Q43" H 5581 5396 50  0000 L CNN
F 1 "PSMN5R2-60YL" H 5575 5300 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:LFPAK56" H 5525 5350 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/PSMN5R2-60YL.pdf" H 5375 5350 50  0001 C CNN
	1    5375 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R48
U 1 1 5CE5BF30
P 5475 5750
F 0 "R48" V 5325 5750 50  0000 C CNN
F 1 "10m" V 5400 5750 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" H 5475 5750 50  0001 C CNN
F 3 "~" H 5475 5750 50  0001 C CNN
	1    5475 5750
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR068
U 1 1 5CE5BF36
P 5475 5850
F 0 "#PWR068" H 5475 5600 50  0001 C CNN
F 1 "GND" H 5480 5677 50  0000 C CNN
F 2 "" H 5475 5850 50  0001 C CNN
F 3 "" H 5475 5850 50  0001 C CNN
	1    5475 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4575 5250 5175 5250
Wire Wire Line
	5175 5250 5175 5350
$Comp
L PCBV2-rescue:LT3759-VeridianDesigns U5
U 1 1 5CE5BF44
P 3825 5700
F 0 "U5" H 3875 6550 50  0000 C CNN
F 1 "LT3759" H 3950 6475 50  0000 C CNN
F 2 "Package_SO:MSOP-12-1EP_3x4mm_P0.65mm_EP1.65x2.85mm_ThermalVias" H 3825 5700 50  0001 C CNN
F 3 "" H 3825 5700 50  0001 C CNN
	1    3825 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5475 5550 5125 5550
Wire Wire Line
	5125 5550 5125 5350
Wire Wire Line
	5125 5350 4575 5350
$Comp
L Device:R_Small R47
U 1 1 5CE5BF4E
P 6675 5700
F 0 "R47" V 6600 5700 50  0000 C CNN
F 1 "13k" V 6750 5700 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 6675 5700 50  0001 C CNN
F 3 "~" H 6675 5700 50  0001 C CNN
	1    6675 5700
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R49
U 1 1 5CE5BF54
P 6675 5250
F 0 "R49" V 6500 5225 50  0000 C CNN
F 1 "1.6M" V 6575 5200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 6675 5250 50  0001 C CNN
F 3 "~" H 6675 5250 50  0001 C CNN
	1    6675 5250
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C13
U 1 1 5CE5BF5A
P 4575 5750
F 0 "C13" H 4275 5750 50  0000 L CNN
F 1 "100nF" H 4200 5825 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4575 5750 50  0001 C CNN
F 3 "~" H 4575 5750 50  0001 C CNN
	1    4575 5750
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR066
U 1 1 5CE5BF60
P 4575 5850
F 0 "#PWR066" H 4575 5600 50  0001 C CNN
F 1 "GND" H 4580 5677 50  0000 C CNN
F 2 "" H 4575 5850 50  0001 C CNN
F 3 "" H 4575 5850 50  0001 C CNN
	1    4575 5850
	1    0    0    -1  
$EndComp
NoConn ~ 6225 5000
$Comp
L Device:D_Small D6
U 1 1 5CE5BF6C
P 6575 5150
F 0 "D6" H 6575 4945 50  0000 C CNN
F 1 "D_Small" H 6575 5036 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" V 6575 5150 50  0001 C CNN
F 3 "~" V 6575 5150 50  0001 C CNN
F 4 "UF1GLWHRVGCT-ND" H 6575 5150 50  0001 C CNN "Part"
	1    6575 5150
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR072
U 1 1 5CE5BF75
P 6500 4850
F 0 "#PWR072" H 6500 4600 50  0001 C CNN
F 1 "GND" V 6505 4722 50  0000 R CNN
F 2 "" H 6500 4850 50  0001 C CNN
F 3 "" H 6500 4850 50  0001 C CNN
	1    6500 4850
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C17
U 1 1 5CE5BF81
P 7050 5250
F 0 "C17" H 6950 4950 50  0000 L CNN
F 1 "2.2uF" H 6875 5025 50  0000 L CNN
F 2 "Capacitor_SMD:C_2220_5650Metric" H 7050 5250 50  0001 C CNN
F 3 "~" H 7050 5250 50  0001 C CNN
	1    7050 5250
	-1   0    0    1   
$EndComp
Text GLabel 7625 5150 2    50   Input ~ 0
ANODE
Wire Wire Line
	6675 5350 6675 5600
Wire Wire Line
	5475 4750 5475 4850
$Comp
L PCBV2-rescue:750312367-VeridianDesigns T1
U 1 1 5CAC51EF
P 6225 5200
F 0 "T1" H 6375 5800 50  0000 C CNN
F 1 "750312367" H 6675 5800 50  0000 C CNN
F 2 "VeridianDesigns:750312367" H 6225 5250 50  0001 C CNN
F 3 "" H 6225 5250 50  0001 C CNN
F 4 "Wurth Electronics Midcom" H 6500 5700 50  0000 C CNN "Manufacture"
F 5 "750312367" H 6675 5800 50  0000 C CNN "Manufacturer Part Number"
	1    6225 5200
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4575 4750 4575 5050
Wire Wire Line
	3725 5450 3725 5550
Wire Wire Line
	6225 4850 6500 4850
$Comp
L power:GND #PWR073
U 1 1 5CB5A333
P 7050 5350
F 0 "#PWR073" H 7050 5100 50  0001 C CNN
F 1 "GND" V 7055 5222 50  0000 R CNN
F 2 "" H 7050 5350 50  0001 C CNN
F 3 "" H 7050 5350 50  0001 C CNN
	1    7050 5350
	1    0    0    -1  
$EndComp
Connection ~ 5125 4750
Wire Wire Line
	5125 4750 4975 4750
Connection ~ 3725 5550
Wire Wire Line
	3725 5550 3725 5650
Connection ~ 4575 5050
Wire Wire Line
	4575 5050 4575 5150
$Comp
L power:GND #PWR065
U 1 1 5CBBD355
P 4775 5050
F 0 "#PWR065" H 4775 4800 50  0001 C CNN
F 1 "GND" H 4780 4877 50  0000 C CNN
F 2 "" H 4775 5050 50  0001 C CNN
F 3 "" H 4775 5050 50  0001 C CNN
	1    4775 5050
	0    -1   -1   0   
$EndComp
$Comp
L Device:Ferrite_Bead_Small FB1
U 1 1 5CBD12C0
P 4475 4750
F 0 "FB1" V 4238 4750 50  0000 C CNN
F 1 "Ferrite_Bead_Small" V 4325 4500 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4405 4750 50  0001 C CNN
F 3 "~" H 4475 4750 50  0001 C CNN
	1    4475 4750
	0    1    1    0   
$EndComp
Text GLabel 4375 4750 0    50   Input ~ 0
VUSB
Connection ~ 4575 4750
$Comp
L Device:C_Small C15
U 1 1 5CBDEC46
P 5125 4650
F 0 "C15" H 4900 4625 50  0000 L CNN
F 1 "10uF" H 4850 4700 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5125 4650 50  0001 C CNN
F 3 "~" H 5125 4650 50  0001 C CNN
	1    5125 4650
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR067
U 1 1 5CBDF1DD
P 5125 4550
F 0 "#PWR067" H 5125 4300 50  0001 C CNN
F 1 "GND" H 5130 4377 50  0000 C CNN
F 2 "" H 5125 4550 50  0001 C CNN
F 3 "" H 5125 4550 50  0001 C CNN
	1    5125 4550
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C14
U 1 1 5CCC6E3B
P 4975 4650
F 0 "C14" H 5075 4600 50  0000 L CNN
F 1 "100uF" H 5050 4675 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 4975 4650 50  0001 C CNN
F 3 "~" H 4975 4650 50  0001 C CNN
	1    4975 4650
	-1   0    0    1   
$EndComp
Wire Wire Line
	5125 4750 5475 4750
Connection ~ 4975 4750
Wire Wire Line
	4975 4750 4575 4750
Wire Wire Line
	4975 4550 5125 4550
Connection ~ 5125 4550
Text Label 4575 5250 0    50   ~ 0
Gate
Text Label 4575 5350 0    50   ~ 0
Sense
Text Label 4575 5450 0    50   ~ 0
FBx
Connection ~ 3725 5650
Text Label 4575 4750 0    50   ~ 0
V5F
Wire Wire Line
	6475 5150 6225 5150
Text GLabel 6000 1775 1    50   Input ~ 0
VUSB
Text GLabel 6500 2775 2    50   Input ~ 0
SDA
Text GLabel 6500 2675 2    50   Input ~ 0
SCL
Text GLabel 5700 1975 0    50   Input ~ 0
BOOSTEN
Text GLabel 6500 2575 2    50   Input ~ 0
Pixel_Data
$Comp
L power:+3.3V #PWR058
U 1 1 5E0B24F2
P 6100 1775
F 0 "#PWR058" H 6100 1625 50  0001 C CNN
F 1 "+3.3V" H 6115 1948 50  0000 C CNN
F 2 "" H 6100 1775 50  0001 C CNN
F 3 "" H 6100 1775 50  0001 C CNN
	1    6100 1775
	1    0    0    -1  
$EndComp
$Comp
L dk_RF-Evaluation-and-Development-Kits-Boards:PHOTONH A1
U 1 1 5E0BA3A2
P 6100 2375
F 0 "A1" H 6375 2950 60  0000 C CNN
F 1 "PHOTONH" H 6650 1675 60  0000 C CNN
F 2 "digikey-footprints:Particle_Photon" H 6300 2575 60  0001 L CNN
F 3 "https://docs.particle.io/datasheets/photon-(wifi)/photon-datasheet/" H 6300 2675 60  0001 L CNN
F 4 "1878-1000-ND" H 6300 2775 60  0001 L CNN "Digi-Key_PN"
F 5 "PHOTONH" H 6300 2875 60  0001 L CNN "MPN"
F 6 "RF/IF and RFID" H 6300 2975 60  0001 L CNN "Category"
F 7 "RF Evaluation and Development Kits, Boards" H 6300 3075 60  0001 L CNN "Family"
F 8 "https://docs.particle.io/datasheets/photon-(wifi)/photon-datasheet/" H 6300 3175 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/particle-industries-inc/PHOTONH/1878-1000-ND/7896991" H 6300 3275 60  0001 L CNN "DK_Detail_Page"
F 10 "PHOTON WITH HEADERS" H 6300 3375 60  0001 L CNN "Description"
F 11 "Particle Industries, Inc." H 6300 3475 60  0001 L CNN "Manufacturer"
F 12 "Active" H 6300 3575 60  0001 L CNN "Status"
	1    6100 2375
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR059
U 1 1 5E0C2AF5
P 6100 3175
F 0 "#PWR059" H 6100 2925 50  0001 C CNN
F 1 "GND" H 6100 3025 50  0000 C CNN
F 2 "" H 6100 3175 50  0001 C CNN
F 3 "" H 6100 3175 50  0001 C CNN
	1    6100 3175
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3175 6100 3175
Connection ~ 6100 3175
Text GLabel 7300 3075 3    50   Input ~ 0
SDA
Text GLabel 7400 3075 3    50   Input ~ 0
SCL
$Comp
L Device:R_Small R45
U 1 1 5E0E12E1
P 7400 2975
F 0 "R45" H 7525 3025 50  0000 C CNN
F 1 "4.7k" H 7525 2950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 7400 2975 50  0001 C CNN
F 3 "~" H 7400 2975 50  0001 C CNN
	1    7400 2975
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R42
U 1 1 5E0E215D
P 7300 2975
F 0 "R42" H 7425 3025 50  0000 C CNN
F 1 "4.7k" H 7425 2950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 7300 2975 50  0001 C CNN
F 3 "~" H 7300 2975 50  0001 C CNN
	1    7300 2975
	-1   0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR075
U 1 1 5E0E240B
P 7300 2875
F 0 "#PWR075" H 7300 2725 50  0001 C CNN
F 1 "+3.3V" H 7315 3048 50  0000 C CNN
F 2 "" H 7300 2875 50  0001 C CNN
F 3 "" H 7300 2875 50  0001 C CNN
	1    7300 2875
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 2875 7400 2875
Connection ~ 7300 2875
$Comp
L Connector:USB_B_Micro J1
U 1 1 5E15F674
P 2250 2400
F 0 "J1" H 2307 2867 50  0000 C CNN
F 1 "USB_B_Micro" H 2307 2776 50  0000 C CNN
F 2 "Connector_USB:USB_Micro-B_GCT_USB3076-30-A" H 2400 2350 50  0001 C CNN
F 3 "~" H 2400 2350 50  0001 C CNN
	1    2250 2400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5E160558
P 2250 2800
F 0 "#PWR0101" H 2250 2550 50  0001 C CNN
F 1 "GND" H 2255 2627 50  0000 C CNN
F 2 "" H 2250 2800 50  0001 C CNN
F 3 "" H 2250 2800 50  0001 C CNN
	1    2250 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 2800 2150 2800
Connection ~ 2250 2800
Wire Wire Line
	2550 2400 2925 2400
Wire Wire Line
	2925 2500 2550 2500
$Comp
L power:GND #PWR0102
U 1 1 5E17A951
P 3525 2800
F 0 "#PWR0102" H 3525 2550 50  0001 C CNN
F 1 "GND" H 3530 2627 50  0000 C CNN
F 2 "" H 3525 2800 50  0001 C CNN
F 3 "" H 3525 2800 50  0001 C CNN
	1    3525 2800
	1    0    0    -1  
$EndComp
Text GLabel 3850 2200 2    50   Input ~ 0
VUSB
Text Label 6225 5150 0    50   ~ 0
T_HIGH
$Comp
L power:GND #PWR086
U 1 1 5E2EB194
P 6675 5800
F 0 "#PWR086" H 6675 5550 50  0001 C CNN
F 1 "GND" H 6680 5627 50  0000 C CNN
F 2 "" H 6675 5800 50  0001 C CNN
F 3 "" H 6675 5800 50  0001 C CNN
	1    6675 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4575 5450 5025 5450
Wire Wire Line
	6675 5600 5025 5600
Connection ~ 6675 5600
Wire Wire Line
	5025 5600 5025 5450
Wire Wire Line
	5475 5550 5475 5650
Connection ~ 5475 5550
$Comp
L power:GND #PWR064
U 1 1 5CE5BEDF
P 3725 5650
F 0 "#PWR064" H 3725 5400 50  0001 C CNN
F 1 "GND" H 3730 5477 50  0000 C CNN
F 2 "" H 3725 5650 50  0001 C CNN
F 3 "" H 3725 5650 50  0001 C CNN
	1    3725 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3525 2200 2550 2200
NoConn ~ 2550 2600
$Comp
L Device:C_Small C20
U 1 1 5E326663
P 7250 1825
F 0 "C20" H 7025 1800 50  0000 L CNN
F 1 "10uF" H 6975 1875 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 7250 1825 50  0001 C CNN
F 3 "~" H 7250 1825 50  0001 C CNN
	1    7250 1825
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01
U 1 1 5E327B2D
P 7250 1725
F 0 "#PWR01" H 7250 1575 50  0001 C CNN
F 1 "+3.3V" H 7265 1898 50  0000 C CNN
F 2 "" H 7250 1725 50  0001 C CNN
F 3 "" H 7250 1725 50  0001 C CNN
	1    7250 1725
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5E3282D1
P 7250 1925
F 0 "#PWR02" H 7250 1675 50  0001 C CNN
F 1 "GND" H 7250 1775 50  0000 C CNN
F 2 "" H 7250 1925 50  0001 C CNN
F 3 "" H 7250 1925 50  0001 C CNN
	1    7250 1925
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J2
U 1 1 5E333862
P 8875 2525
F 0 "J2" H 8925 2525 50  0000 C CNN
F 1 "Conn_01x02_Female" H 9275 2450 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8875 2525 50  0001 C CNN
F 3 "~" H 8875 2525 50  0001 C CNN
	1    8875 2525
	-1   0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0108
U 1 1 5E3344E2
P 9075 2525
F 0 "#PWR0108" H 9075 2375 50  0001 C CNN
F 1 "+3.3V" H 9090 2698 50  0000 C CNN
F 2 "" H 9075 2525 50  0001 C CNN
F 3 "" H 9075 2525 50  0001 C CNN
	1    9075 2525
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R51
U 1 1 5E334B35
P 9075 2725
F 0 "R51" H 9200 2775 50  0000 C CNN
F 1 "4.7k" H 9200 2700 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 9075 2725 50  0001 C CNN
F 3 "~" H 9075 2725 50  0001 C CNN
	1    9075 2725
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5E337A52
P 9075 2825
F 0 "#PWR0109" H 9075 2575 50  0001 C CNN
F 1 "GND" H 9080 2652 50  0000 C CNN
F 2 "" H 9075 2825 50  0001 C CNN
F 3 "" H 9075 2825 50  0001 C CNN
	1    9075 2825
	1    0    0    -1  
$EndComp
Text GLabel 9500 2625 2    50   Input ~ 0
Ambient
Wire Wire Line
	9075 2625 9375 2625
Connection ~ 9075 2625
$Comp
L Device:C_Small C?
U 1 1 5E34AAA7
P 9375 2725
AR Path="/5E34AAA7" Ref="C?"  Part="1" 
AR Path="/5DA61620/5E34AAA7" Ref="C21"  Part="1" 
F 0 "C21" H 9075 2725 50  0000 L CNN
F 1 "0.1uF" H 9025 2800 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9375 2725 50  0001 C CNN
F 3 "~" H 9375 2725 50  0001 C CNN
	1    9375 2725
	-1   0    0    1   
$EndComp
Connection ~ 9375 2625
Wire Wire Line
	9375 2625 9500 2625
Wire Wire Line
	9375 2825 9075 2825
Connection ~ 9075 2825
Wire Wire Line
	3525 2400 3525 2200
$Comp
L Interface_USB:TPS2514 U7
U 1 1 5E1673CF
P 3225 2600
F 0 "U7" H 3525 2625 50  0000 C CNN
F 1 "TPS2514" H 3600 2500 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 3225 2200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tps2513.pdf" H 3225 2650 50  0001 C CNN
	1    3225 2600
	-1   0    0    -1  
$EndComp
$Comp
L Device:D_Schottky D7
U 1 1 5E35E0EC
P 3700 2350
F 0 "D7" V 3654 2429 50  0000 L CNN
F 1 "D_Schottky" V 3745 2429 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 3700 2350 50  0001 C CNN
F 3 "~" H 3700 2350 50  0001 C CNN
	1    3700 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	3525 2200 3700 2200
Connection ~ 3525 2200
Connection ~ 3700 2200
Wire Wire Line
	3525 2800 3700 2800
Wire Wire Line
	3700 2800 3700 2500
Connection ~ 3525 2800
NoConn ~ 5700 2075
NoConn ~ 5700 2175
NoConn ~ 5700 2275
NoConn ~ 6500 2175
NoConn ~ 6500 2275
NoConn ~ 5700 2775
NoConn ~ 5700 2975
NoConn ~ 6200 1775
$Comp
L Device:C_Small C16
U 1 1 5E37D933
P 3850 2600
F 0 "C16" H 3625 2575 50  0000 L CNN
F 1 "10uF" H 3575 2650 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3850 2600 50  0001 C CNN
F 3 "~" H 3850 2600 50  0001 C CNN
	1    3850 2600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3700 2800 3850 2800
Wire Wire Line
	3850 2800 3850 2700
Connection ~ 3700 2800
Wire Wire Line
	3850 2500 3850 2200
Wire Wire Line
	3700 2200 3850 2200
Text GLabel 6500 2475 2    50   Input ~ 0
PCA_OE
Text Label 3450 5250 0    50   ~ 0
SS
Connection ~ 6675 5150
$Comp
L power:GND #PWR0110
U 1 1 5E6B62D3
P 7325 5350
F 0 "#PWR0110" H 7325 5100 50  0001 C CNN
F 1 "GND" V 7330 5222 50  0000 R CNN
F 2 "" H 7325 5350 50  0001 C CNN
F 3 "" H 7325 5350 50  0001 C CNN
	1    7325 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C19
U 1 1 5E6B8646
P 7325 5250
F 0 "C19" H 7275 4950 50  0000 L CNN
F 1 "2.2uF" H 7150 5025 50  0000 L CNN
F 2 "Capacitor_SMD:C_2220_5650Metric" H 7325 5250 50  0001 C CNN
F 3 "~" H 7325 5250 50  0001 C CNN
	1    7325 5250
	-1   0    0    1   
$EndComp
Wire Wire Line
	6675 5150 6850 5150
$Comp
L Device:C_Small C18
U 1 1 5E6BD3A9
P 6850 5250
F 0 "C18" H 6825 4950 50  0000 L CNN
F 1 "100nF" H 6700 5025 50  0000 L CNN
F 2 "Capacitor_SMD:C_1210_3225Metric" H 6850 5250 50  0001 C CNN
F 3 "~" H 6850 5250 50  0001 C CNN
	1    6850 5250
	-1   0    0    1   
$EndComp
Connection ~ 6850 5150
Wire Wire Line
	6850 5150 7050 5150
$Comp
L power:GND #PWR0111
U 1 1 5E6BDBE6
P 6850 5350
F 0 "#PWR0111" H 6850 5100 50  0001 C CNN
F 1 "GND" V 6855 5222 50  0000 R CNN
F 2 "" H 6850 5350 50  0001 C CNN
F 3 "" H 6850 5350 50  0001 C CNN
	1    6850 5350
	1    0    0    -1  
$EndComp
Connection ~ 7050 5150
Connection ~ 7325 5150
Wire Wire Line
	7325 5150 7625 5150
Wire Wire Line
	7050 5150 7325 5150
Text GLabel 5700 2875 0    50   Input ~ 0
Ambient
NoConn ~ 5700 2375
NoConn ~ 5700 2475
NoConn ~ 5700 2575
NoConn ~ 5700 2675
NoConn ~ 6500 2375
NoConn ~ 6500 2075
$EndSCHEMATC