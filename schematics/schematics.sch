EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L Connector:Conn_01x03_Male J1
U 1 1 6010D8EE
P 1800 1450
F 0 "J1" H 1900 1650 50  0000 R CNN
F 1 "UPDI" H 1950 1250 50  0000 R CNN
F 2 "" H 1800 1450 50  0001 C CNN
F 3 "~" H 1800 1450 50  0001 C CNN
	1    1800 1450
	-1   0    0    -1  
$EndComp
$Comp
L mamemomonga:CP2102-Module U2
U 1 1 6010F250
P 1950 2150
F 0 "U2" H 1522 2059 50  0000 R CNN
F 1 "CP2102-Module" H 1522 2150 50  0000 R CNN
F 2 "" H 1900 1650 50  0001 C CNN
F 3 "" H 1900 1650 50  0001 C CNN
	1    1950 2150
	-1   0    0    1   
$EndComp
$Comp
L Device:Amperemeter_DC MES1
U 1 1 6011097C
P 4300 4200
F 0 "MES1" H 4453 4246 50  0000 L CNN
F 1 "100uA" H 4453 4155 50  0000 L CNN
F 2 "" V 4300 4300 50  0001 C CNN
F 3 "~" V 4300 4300 50  0001 C CNN
	1    4300 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV1
U 1 1 60112323
P 4300 3600
F 0 "RV1" V 4093 3600 50  0000 C CNN
F 1 "50K" V 4184 3600 50  0000 C CNN
F 2 "" H 4300 3600 50  0001 C CNN
F 3 "~" H 4300 3600 50  0001 C CNN
	1    4300 3600
	0    -1   1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 601169C8
P 3750 3600
F 0 "R2" V 3957 3600 50  0000 C CNN
F 1 "10K" V 3866 3600 50  0000 C CNN
F 2 "" V 3680 3600 50  0001 C CNN
F 3 "~" H 3750 3600 50  0001 C CNN
	1    3750 3600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3900 3600 4150 3600
Wire Wire Line
	4300 3750 4300 4000
NoConn ~ 4450 3600
$Comp
L power:GND #PWR010
U 1 1 601185FA
P 4300 4600
F 0 "#PWR010" H 4300 4350 50  0001 C CNN
F 1 "GND" H 4305 4427 50  0000 C CNN
F 2 "" H 4300 4600 50  0001 C CNN
F 3 "" H 4300 4600 50  0001 C CNN
	1    4300 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 4400 4300 4600
$Comp
L power:+5V #PWR09
U 1 1 6011905A
P 1500 1200
F 0 "#PWR09" H 1500 1050 50  0001 C CNN
F 1 "+5V" H 1515 1373 50  0000 C CNN
F 2 "" H 1500 1200 50  0001 C CNN
F 3 "" H 1500 1200 50  0001 C CNN
	1    1500 1200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR07
U 1 1 60119E24
P 1400 2500
F 0 "#PWR07" H 1400 2250 50  0001 C CNN
F 1 "GND" H 1405 2327 50  0000 C CNN
F 2 "" H 1400 2500 50  0001 C CNN
F 3 "" H 1400 2500 50  0001 C CNN
	1    1400 2500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 6011F768
P 3850 2800
F 0 "#PWR04" H 3850 2550 50  0001 C CNN
F 1 "GND" H 3855 2627 50  0000 C CNN
F 2 "" H 3850 2800 50  0001 C CNN
F 3 "" H 3850 2800 50  0001 C CNN
	1    3850 2800
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR03
U 1 1 6012074E
P 3850 1000
F 0 "#PWR03" H 3850 850 50  0001 C CNN
F 1 "+5V" H 3865 1173 50  0000 C CNN
F 2 "" H 3850 1000 50  0001 C CNN
F 3 "" H 3850 1000 50  0001 C CNN
	1    3850 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 1000 3850 1150
Text Label 1850 1350 0    50   ~ 0
+5V
Text Label 1850 1450 0    50   ~ 0
UPDI
Text Label 1850 1550 0    50   ~ 0
GND
NoConn ~ 1600 2150
NoConn ~ 1600 2250
NoConn ~ 1600 2350
$Comp
L power:+5V #PWR05
U 1 1 60123A80
P 5050 1550
F 0 "#PWR05" H 5050 1400 50  0001 C CNN
F 1 "+5V" H 5065 1723 50  0000 C CNN
F 2 "" H 5050 1550 50  0001 C CNN
F 3 "" H 5050 1550 50  0001 C CNN
	1    5050 1550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 60124252
P 5050 1850
F 0 "#PWR06" H 5050 1600 50  0001 C CNN
F 1 "GND" H 5055 1677 50  0000 C CNN
F 2 "" H 5050 1850 50  0001 C CNN
F 3 "" H 5050 1850 50  0001 C CNN
	1    5050 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 601247B5
P 5050 1700
F 0 "C2" H 5165 1746 50  0000 L CNN
F 1 "0.1u" H 5165 1655 50  0000 L CNN
F 2 "" H 5088 1550 50  0001 C CNN
F 3 "~" H 5050 1700 50  0001 C CNN
	1    5050 1700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 601258B0
P 2050 3950
F 0 "#PWR01" H 2050 3800 50  0001 C CNN
F 1 "+5V" H 2065 4123 50  0000 C CNN
F 2 "" H 2050 3950 50  0001 C CNN
F 3 "" H 2050 3950 50  0001 C CNN
	1    2050 3950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 601258B6
P 2050 4250
F 0 "#PWR02" H 2050 4000 50  0001 C CNN
F 1 "GND" H 2055 4077 50  0000 C CNN
F 2 "" H 2050 4250 50  0001 C CNN
F 3 "" H 2050 4250 50  0001 C CNN
	1    2050 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C1
U 1 1 601261B7
P 2050 4100
F 0 "C1" H 2168 4146 50  0000 L CNN
F 1 "10uF" H 2168 4055 50  0000 L CNN
F 2 "" H 2088 3950 50  0001 C CNN
F 3 "~" H 2050 4100 50  0001 C CNN
	1    2050 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 2350 3850 2800
$Comp
L mamemomonga:AE-7SEG-BOARD U?
U 1 1 6015CB97
P 6850 3500
F 0 "U?" H 6850 3965 50  0000 C CNN
F 1 "AE-7SEG-BOARD" H 6850 3874 50  0000 C CNN
F 2 "" H 6850 3100 50  0001 C CNN
F 3 "" H 6850 3100 50  0001 C CNN
	1    6850 3500
	1    0    0    -1  
$EndComp
Text GLabel 4550 1750 2    50   Input ~ 0
SCK
Wire Wire Line
	4450 1650 4550 1650
Text GLabel 4550 1450 2    50   Input ~ 0
UPDI
$Comp
L MCU_Microchip_ATtiny:ATtiny412-SS U1
U 1 1 6010C951
P 3850 1750
F 0 "U1" H 3321 1796 50  0000 R CNN
F 1 "ATtiny412-SS" H 3321 1705 50  0000 R CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 3850 1750 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/40001911A.pdf" H 3850 1750 50  0001 C CNN
	1    3850 1750
	1    0    0    -1  
$EndComp
Text GLabel 4550 1550 2    50   Input ~ 0
MOSI
Text GLabel 4550 1650 2    50   Input ~ 0
SS
Text GLabel 4550 1850 2    50   Input ~ 0
DAC
Text GLabel 4550 1950 2    50   Input ~ 0
RX
Wire Wire Line
	4450 1450 4550 1450
Wire Wire Line
	4450 1550 4550 1550
Wire Wire Line
	4450 1750 4550 1750
Wire Wire Line
	4450 1850 4550 1850
Wire Wire Line
	4450 1950 4550 1950
Text GLabel 3450 3600 0    50   Input ~ 0
DAC
Wire Wire Line
	3450 3600 3600 3600
Wire Wire Line
	1600 1950 1400 1950
Wire Wire Line
	1400 1950 1400 2500
Wire Wire Line
	1600 2050 1250 2050
Text GLabel 1250 2050 0    50   Input ~ 0
RX
Wire Wire Line
	1600 1550 1400 1550
Wire Wire Line
	1400 1550 1400 1950
Connection ~ 1400 1950
Wire Wire Line
	1600 1850 1500 1850
Wire Wire Line
	1500 1850 1500 1350
Wire Wire Line
	1500 1350 1600 1350
Wire Wire Line
	1500 1350 1500 1200
Connection ~ 1500 1350
Text GLabel 1250 1450 0    50   Input ~ 0
UPDI
Wire Wire Line
	1250 1450 1600 1450
Text GLabel 6200 1450 0    50   Input ~ 0
SCK
Text GLabel 6200 1250 0    50   Input ~ 0
MOSI
Text GLabel 6200 1750 0    50   Input ~ 0
SS
Wire Wire Line
	6200 1250 6450 1250
Wire Wire Line
	6450 1450 6200 1450
Wire Wire Line
	6200 1750 6450 1750
Wire Wire Line
	6450 1550 6350 1550
Wire Wire Line
	6350 1550 6350 1050
Wire Wire Line
	6350 1050 6850 1050
$Comp
L power:+5V #PWR?
U 1 1 6017EB32
P 6350 900
F 0 "#PWR?" H 6350 750 50  0001 C CNN
F 1 "+5V" H 6365 1073 50  0000 C CNN
F 2 "" H 6350 900 50  0001 C CNN
F 3 "" H 6350 900 50  0001 C CNN
	1    6350 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 900  6350 1050
Connection ~ 6350 1050
Wire Wire Line
	6850 2350 6350 2350
Wire Wire Line
	6350 2350 6350 1850
Wire Wire Line
	6350 1850 6450 1850
$Comp
L power:GND #PWR?
U 1 1 60181D6D
P 6350 2500
F 0 "#PWR?" H 6350 2250 50  0001 C CNN
F 1 "GND" H 6355 2327 50  0000 C CNN
F 2 "" H 6350 2500 50  0001 C CNN
F 3 "" H 6350 2500 50  0001 C CNN
	1    6350 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 2350 6350 2500
Connection ~ 6350 2350
$Comp
L Device:R R?
U 1 1 601839E2
P 7950 1250
F 0 "R?" V 8157 1250 50  0000 C CNN
F 1 "1K" V 8066 1250 50  0000 C CNN
F 2 "" V 7880 1250 50  0001 C CNN
F 3 "~" H 7950 1250 50  0001 C CNN
	1    7950 1250
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D?
U 1 1 60184571
P 8350 1250
F 0 "D?" H 8343 995 50  0000 C CNN
F 1 "GREEN" H 8343 1086 50  0000 C CNN
F 2 "" H 8350 1250 50  0001 C CNN
F 3 "~" H 8350 1250 50  0001 C CNN
	1    8350 1250
	-1   0    0    1   
$EndComp
Wire Wire Line
	8100 1250 8200 1250
Wire Wire Line
	8100 1650 8200 1650
$Comp
L Device:LED D?
U 1 1 6018D41F
P 8350 1650
F 0 "D?" H 8343 1395 50  0000 C CNN
F 1 "YELLOW" H 8343 1486 50  0000 C CNN
F 2 "" H 8350 1650 50  0001 C CNN
F 3 "~" H 8350 1650 50  0001 C CNN
	1    8350 1650
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 6018D419
P 7950 1650
F 0 "R?" V 8157 1650 50  0000 C CNN
F 1 "1K" V 8066 1650 50  0000 C CNN
F 2 "" V 7880 1650 50  0001 C CNN
F 3 "~" H 7950 1650 50  0001 C CNN
	1    7950 1650
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 601911AF
P 7950 2050
F 0 "R?" V 8157 2050 50  0000 C CNN
F 1 "1K" V 8066 2050 50  0000 C CNN
F 2 "" V 7880 2050 50  0001 C CNN
F 3 "~" H 7950 2050 50  0001 C CNN
	1    7950 2050
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D?
U 1 1 601911B5
P 8350 2050
F 0 "D?" H 8343 1795 50  0000 C CNN
F 1 "RED" H 8343 1886 50  0000 C CNN
F 2 "" H 8350 2050 50  0001 C CNN
F 3 "~" H 8350 2050 50  0001 C CNN
	1    8350 2050
	-1   0    0    1   
$EndComp
Wire Wire Line
	8100 2050 8200 2050
Wire Wire Line
	8500 1250 8700 1250
Wire Wire Line
	8700 1250 8700 1650
Wire Wire Line
	8500 2050 8700 2050
Connection ~ 8700 2050
Wire Wire Line
	8500 1650 8700 1650
Connection ~ 8700 1650
Wire Wire Line
	8700 1650 8700 2050
Wire Wire Line
	7250 1250 7800 1250
Wire Wire Line
	7800 1350 7800 1650
Wire Wire Line
	7250 1350 7800 1350
$Comp
L 74xx:74HC595 U?
U 1 1 6015E47A
P 6850 1650
F 0 "U?" H 6850 2431 50  0000 C CNN
F 1 "74HC595" H 6850 2340 50  0000 C CNN
F 2 "" H 6850 1650 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 6850 1650 50  0001 C CNN
	1    6850 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 1450 7700 1450
Wire Wire Line
	7700 1450 7700 2050
Wire Wire Line
	7700 2050 7800 2050
$Comp
L power:GND #PWR?
U 1 1 601A39BD
P 8700 2550
F 0 "#PWR?" H 8700 2300 50  0001 C CNN
F 1 "GND" H 8705 2377 50  0000 C CNN
F 2 "" H 8700 2550 50  0001 C CNN
F 3 "" H 8700 2550 50  0001 C CNN
	1    8700 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 2050 8700 2550
Wire Wire Line
	7250 2150 7450 2150
Wire Wire Line
	7450 2150 7450 2800
Wire Wire Line
	7450 2800 6100 2800
Wire Wire Line
	6100 2800 6100 3400
Wire Wire Line
	6100 3400 6400 3400
Text GLabel 6200 3500 0    50   Input ~ 0
SCK
Wire Wire Line
	6200 3500 6400 3500
Text GLabel 7600 3600 2    50   Input ~ 0
SS
Wire Wire Line
	7300 3600 7600 3600
$Comp
L power:+5V #PWR?
U 1 1 601B6226
P 5900 3050
F 0 "#PWR?" H 5900 2900 50  0001 C CNN
F 1 "+5V" H 5915 3223 50  0000 C CNN
F 2 "" H 5900 3050 50  0001 C CNN
F 3 "" H 5900 3050 50  0001 C CNN
	1    5900 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 3050 5900 3700
Wire Wire Line
	6400 3600 6300 3600
Wire Wire Line
	6300 3600 6300 3900
$Comp
L power:GND #PWR?
U 1 1 601B9D1B
P 6300 4100
F 0 "#PWR?" H 6300 3850 50  0001 C CNN
F 1 "GND" H 6305 3927 50  0000 C CNN
F 2 "" H 6300 4100 50  0001 C CNN
F 3 "" H 6300 4100 50  0001 C CNN
	1    6300 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 3700 6400 3700
NoConn ~ 6400 3300
NoConn ~ 7300 3300
NoConn ~ 7300 3400
NoConn ~ 7300 3700
Wire Wire Line
	7300 3500 7450 3500
Wire Wire Line
	7450 3500 7450 3900
Wire Wire Line
	7450 3900 6300 3900
Connection ~ 6300 3900
Wire Wire Line
	6300 3900 6300 4100
$Comp
L power:+5V #PWR?
U 1 1 601D4088
P 5700 1550
F 0 "#PWR?" H 5700 1400 50  0001 C CNN
F 1 "+5V" H 5715 1723 50  0000 C CNN
F 2 "" H 5700 1550 50  0001 C CNN
F 3 "" H 5700 1550 50  0001 C CNN
	1    5700 1550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 601D408E
P 5700 1850
F 0 "#PWR?" H 5700 1600 50  0001 C CNN
F 1 "GND" H 5705 1677 50  0000 C CNN
F 2 "" H 5700 1850 50  0001 C CNN
F 3 "" H 5700 1850 50  0001 C CNN
	1    5700 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 601D4094
P 5700 1700
F 0 "C?" H 5815 1746 50  0000 L CNN
F 1 "0.1u" H 5815 1655 50  0000 L CNN
F 2 "" H 5738 1550 50  0001 C CNN
F 3 "~" H 5700 1700 50  0001 C CNN
	1    5700 1700
	1    0    0    -1  
$EndComp
NoConn ~ 7250 1550
NoConn ~ 7250 1650
NoConn ~ 7250 1750
NoConn ~ 7250 1850
NoConn ~ 7250 1950
$EndSCHEMATC
