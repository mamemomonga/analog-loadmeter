#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <avr/io.h>

/*
 ATtiny202 8-Pin SOIC

     VDD | 1    8 | GND
TXD  PA6 | 2    7 | PA3 MES
RXD  PA7 | 3    6 | PA0 UPDI
LED1 PA1 | 4    5 | PA2 LED2
*/

/*
#define LED_bm     ( 1<<2 ) // PA2
#define LED_CTRL   PORTA.PIN2CTRL |= PORT_PULLUPEN_bm | PORT_ISC_FALLING_gc
#define LED_OUT    PORTA.DIRSET = LED_bm
#define LED_IN     PORTA.DIRCLR = LED_bm
#define LED_H      PORTA.OUTSET = LED_bm
#define LED_L      PORTA.OUTCLR = LED_bm
#define LED_I      PORTA.OUTTGL = LED_bm
#define LED_IS_H    ( PORTA.IN &  LED_bm )
#define LED_IS_L   !( PORTA.IN &  LED_bm )
*/

#define LED1_bm     ( 1<<1 ) // PA1
#define LED1_OUT    PORTA.DIRSET = LED1_bm
#define LED1_H      PORTA.OUTSET = LED1_bm
#define LED1_L      PORTA.OUTCLR = LED1_bm
#define LED1_I      PORTA.OUTTGL = LED1_bm

#define LED2_bm     ( 1<<2 ) // PA2
#define LED2_OUT    PORTA.DIRSET = LED2_bm
#define LED2_H      PORTA.OUTSET = LED2_bm
#define LED2_L      PORTA.OUTCLR = LED2_bm
#define LED2_I      PORTA.OUTTGL = LED2_bm

#define CMD_CPU_LOAD 0x01
#define CFG_SMOOTH 20

#endif
