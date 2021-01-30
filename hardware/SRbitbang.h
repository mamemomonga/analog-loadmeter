#ifndef _SRBITBANG_H_

#include <avr/io.h>

void SRinit();
void SRapply();
void SRdemo();

uint8_t SRval;
uint8_t SR7seg;

#define LED_ON    SRval = 0xFF
#define LED_OFF   SRval = 0x00
#define LED1_ON  ( SRval |=  1 )
#define LED1_OFF ( SRval &=~ 1 )
#define LED2_ON  ( SRval |=  (1<<1) )
#define LED2_OFF ( SRval &=~ (1<<1) )
#define LED3_ON  ( SRval |=  (1<<2) )
#define LED3_OFF ( SRval &=~ (1<<2) )

#define SEG_OFF       SR7seg = 0
#define SEG_DP_ON     ( SR7segDP |= (1<<7) )
#define SEG_DP_OFF    ( SR7segDP &-~ (1<<7) )

#endif