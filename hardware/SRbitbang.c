#include "SRbitbang.h"
#include "config.h"
#include <util/delay.h>
#include "char2seg.h"

// --------------------
// 74HC595 BitBang
// --------------------

void SRinit() {
	MOSI_OUT; MOSI_L;
	SCK_OUT;  SCK_H;
	SS_OUT;   SS_H;
	SRval  = 0;
	SR7seg = 0;
	SRapply();
}

static void srSend(uint8_t b) {
	for(uint8_t i=0;i<8;i++) {
		SCK_L;
		if( ( b >> (7-i) ) & 1 ) {
			MOSI_H;
		} else {
			MOSI_L;
		}
		asm volatile("nop");
		SCK_H;
		_delay_us(1);
	}
}

// MSBFirst
void SRapply() {
	SS_L;
	srSend(SR7seg);
	srSend(SRval);
	MOSI_L; SCK_H;
	SS_H;
}

// --------------------

void SR7segSetChar(char c) {
	SR7seg = pgm_read_byte_near(char2seg + c);
}

void SRdemo() {
	LED1_ON;  SR7segSetChar('0'); SRapply(); _delay_ms(100);
	LED1_OFF; SR7segSetChar('1'); SRapply(); _delay_ms(100);
	LED1_ON;  SR7segSetChar('2'); SRapply(); _delay_ms(100);
	LED1_OFF; SR7segSetChar('3'); SRapply(); _delay_ms(100);
	LED2_ON;  SR7segSetChar('4'); SRapply(); _delay_ms(100);
	LED2_OFF; SR7segSetChar('5'); SRapply(); _delay_ms(100);
	LED2_ON;  SR7segSetChar('6'); SRapply(); _delay_ms(100);
	LED2_OFF; SR7segSetChar('7'); SRapply(); _delay_ms(100);
	LED3_ON;  SR7segSetChar('8'); SRapply(); _delay_ms(100);
	LED3_OFF; SR7segSetChar('9'); SRapply(); _delay_ms(100);
	LED3_ON;  SR7segSetChar('a'); SRapply(); _delay_ms(100);
	LED3_OFF; SR7segSetChar('b'); SRapply(); _delay_ms(100);
	LED_ON;   SR7segSetChar('c'); SRapply(); _delay_ms(100);
	LED_OFF;  SR7segSetChar('d'); SRapply(); _delay_ms(100);
	LED_ON;   SR7segSetChar('e'); SRapply(); _delay_ms(100);
	LED_OFF;  SR7segSetChar('f'); SRapply(); _delay_ms(100);
}
