#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <avr/io.h>

/*
 ATtiny412 8-Pin SOIC

     VDD | 1    8 | GND
 DAC PA6 | 2    7 | PB2
 RX  PA7 | 3    6 | PA0 /RST,UPDI
     PA1 | 4    5 | PA2
*/

// #define LED_bm     ( 1<<2 ) // PA2
// #define LED_OUT    PORTA.DIRSET = LED_bm
// #define LED_IN     PORTA.DIRCLR = LED_bm
// #define LED_PULLUP PORTA.PIN2CTRL |= PORT_PULLUPEN_bm
// #define LED_H      PORTA.OUTSET = LED_bm
// #define LED_L      PORTA.OUTCLR = LED_bm
// #define LED_I      PORTA.OUTTGL = LED_bm
// #define LED_IS_H    ( PORTA.IN & LED_bm )
// #define LED_IS_L   !( PORTA.IN & LED_bm )

#define DAC_bm (1<<6) // DAC: PA6
#define USART0_RX_Pin_bm (1<<7) // Rx: PA7

#endif