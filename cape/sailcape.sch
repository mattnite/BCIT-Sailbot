EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:sailcape-cache
EELAYER 25 0
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
L ATMEGA328P-A IC?
U 1 1 597B5A3F
P 4250 3050
F 0 "IC?" H 3500 4300 50  0000 L BNN
F 1 "ATMEGA328P-A" H 4650 1650 50  0000 L BNN
F 2 "TQFP32" H 4250 3050 50  0000 C CIN
F 3 "" H 4250 3050 50  0000 C CNN
	1    4250 3050
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X23 P8
U 1 1 597BA15D
P 1500 4450
F 0 "P8" H 1500 5650 50  0000 C CNN
F 1 "CONN_02X23" V 1500 4450 50  0000 C CNN
F 2 "" H 1500 3600 50  0000 C CNN
F 3 "" H 1500 3600 50  0000 C CNN
	1    1500 4450
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X23 P9
U 1 1 597BA24C
P 1500 1900
F 0 "P9" H 1500 3100 50  0000 C CNN
F 1 "CONN_02X23" V 1500 1900 50  0000 C CNN
F 2 "" H 1500 1050 50  0000 C CNN
F 3 "" H 1500 1050 50  0000 C CNN
	1    1500 1900
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR?
U 1 1 597BA958
P 1050 900
F 0 "#PWR?" H 1050 650 50  0001 C CNN
F 1 "GNDD" H 1050 750 50  0000 C CNN
F 2 "" H 1050 900 50  0000 C CNN
F 3 "" H 1050 900 50  0000 C CNN
	1    1050 900 
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 597BA972
P 1850 700
F 0 "#PWR?" H 1850 550 50  0001 C CNN
F 1 "+3.3V" H 1850 840 50  0000 C CNN
F 2 "" H 1850 700 50  0000 C CNN
F 3 "" H 1850 700 50  0000 C CNN
	1    1850 700 
	1    0    0    -1  
$EndComp
Text Label 2350 1700 2    60   ~ 0
I2C2_SDA
Text Label 2350 1800 2    60   ~ 0
SPI0_SCLK
Text Label 2350 1900 2    60   ~ 0
UART1_TXD
Text Label 2350 2000 2    60   ~ 0
UART1_RXD
Text Label 2350 1600 2    60   ~ 0
SPI0_D1
Text Label 600  1800 0    60   ~ 0
SPI0_D0
Text Label 600  1700 0    60   ~ 0
I2C2_SCL
Text Label 600  1900 0    60   ~ 0
AVR_RESET_N
$Comp
L +3.3V #PWR?
U 1 1 597BB49D
P 3250 1750
F 0 "#PWR?" H 3250 1600 50  0001 C CNN
F 1 "+3.3V" H 3250 1890 50  0000 C CNN
F 2 "" H 3250 1750 50  0000 C CNN
F 3 "" H 3250 1750 50  0000 C CNN
	1    3250 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 900  1050 800 
Wire Wire Line
	1050 800  1250 800 
Wire Wire Line
	1850 700  1850 900 
Wire Wire Line
	1850 900  1750 900 
Wire Wire Line
	1750 1600 2350 1600
Wire Wire Line
	1750 1700 2350 1700
Wire Wire Line
	1750 1800 2350 1800
Wire Wire Line
	1750 1900 2350 1900
Wire Wire Line
	1750 2000 2350 2000
Wire Wire Line
	1250 1700 600  1700
Wire Wire Line
	1250 1800 600  1800
Wire Wire Line
	1250 1900 600  1900
$Comp
L GNDD #PWR?
U 1 1 597BB571
P 3250 4450
F 0 "#PWR?" H 3250 4200 50  0001 C CNN
F 1 "GNDD" H 3250 4300 50  0000 C CNN
F 2 "" H 3250 4450 50  0000 C CNN
F 3 "" H 3250 4450 50  0000 C CNN
	1    3250 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 4050 3250 4050
Wire Wire Line
	3250 4050 3250 4450
Wire Wire Line
	3350 4150 3250 4150
Connection ~ 3250 4150
Wire Wire Line
	3350 4250 3250 4250
Connection ~ 3250 4250
Wire Wire Line
	3350 2050 3250 2050
Wire Wire Line
	3250 1750 3250 2250
Wire Wire Line
	3350 1950 3250 1950
Connection ~ 3250 1950
Text Label 5950 2250 2    60   ~ 0
SPI0_D1
Text Label 5950 2450 2    60   ~ 0
SPI0_SCLK
Text Label 5950 2350 2    60   ~ 0
SPI0_D0
Text Label 5950 3400 2    60   ~ 0
AVR_RESET_N
Wire Wire Line
	5250 2250 5950 2250
Wire Wire Line
	5250 2350 5950 2350
Wire Wire Line
	5250 2450 5950 2450
Wire Wire Line
	5250 3400 5950 3400
Wire Wire Line
	3250 2250 3350 2250
Connection ~ 3250 2050
$EndSCHEMATC
