#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <avr/io.h>

/*
 ATtiny412 8-Pin SOIC

     VDD | 1    8 | GND
 DAC PA6 | 2    7 | PA3 SCK
 RX  PA7 | 3    6 | PA0 /RST,UPDI
MOSI PA1 | 4    5 | PA2 SS
*/

#define DAC_bm ( 1<<6 ) // DAC: PA6
#define USART0_RX_Pin_bm ( 1<<7 ) // Rx: PA7

#define SS_bm     ( 1<<2 ) // PA2
#define SS_OUT    PORTA.DIRSET = SS_bm
#define SS_H      PORTA.OUTSET = SS_bm
#define SS_L      PORTA.OUTCLR = SS_bm

#define SCK_bm    ( 1<<3 ) // PA3
#define SCK_OUT   PORTA.DIRSET = SCK_bm
#define SCK_H     PORTA.OUTSET = SCK_bm
#define SCK_L     PORTA.OUTCLR = SCK_bm

#define MOSI_bm   ( 1<<1 ) // PA1
#define MOSI_OUT  PORTA.DIRSET = MOSI_bm
#define MOSI_H    PORTA.OUTSET = MOSI_bm
#define MOSI_L    PORTA.OUTCLR = MOSI_bm


#endif
