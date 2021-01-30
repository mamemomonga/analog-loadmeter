#include "main.h"
#include "config.h"
#include "SRbitbang.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>

#define USART0_BAUD_RATE(BAUD_RATE) ((float)(F_CPU * 64 / (16 * (float)BAUD_RATE)) + 0.5)

// --------------------
// USART0
// --------------------
void USARTinit() {
	// ボーレート設定
	USART0.BAUD = (uint16_t)USART0_BAUD_RATE(115200);
	// TX:PA6 / RX:PA7
	PORTMUX.CTRLB |= PORTMUX_USART0_DEFAULT_gc;
	// RX割込有効
	USART0.CTRLA |= USART_RXCIE_bm;
	// RX有効
	USART0.CTRLB |= USART_RXEN_bm; 
	// while(USART0.STATUS & USART_RXCIF_bm) { USART0.RXDATAL; }
	sei();
}

// --------------------
// DAC0
// --------------------
void DACinit() {
	PORTA.DIRSET = DAC_bm;
	PORTA.OUTCLR = DAC_bm;
	VREF.CTRLA = VREF_DAC0REFSEL_2V5_gc;
	VREF.CTRLB = VREF_DAC0REFEN_bm;
	DAC0.CTRLA = DAC_RUNSTDBY_bm | DAC_ENABLE_bm;
}

void DACset(uint8_t val) {
	DAC0.CTRLA = DAC_RUNSTDBY_bm | DAC_ENABLE_bm;
	DAC0.DATA  = val;
	DAC0.CTRLA = DAC_OUTEN_bm | DAC_ENABLE_bm;
}


// --------------------
void proc_serial() {
	if(USART0.STATUS & USART_RXCIF_bm) {
		// コマンドの取得
		uint8_t cmd=USART0.RXDATAL;
		for(uint8_t i=0;i<100;i++) {
			if(USART0.STATUS & USART_RXCIF_bm) break;
			_delay_ms(10);
		}
		uint8_t val=USART0.RXDATAL;
		while(USART0.STATUS & USART_RXCIF_bm) { USART0.RXDATAL; }
		switch(cmd) {
			case CMD_CPULOAD:
				if(val > 170) {
					LED_OFF; LED3_ON;
					SRapply();
				} else if ( val > 85 ) {
					LED_OFF; LED2_ON;
					SRapply();
				} else {
					LED_OFF; LED1_ON;
					SRapply();
				}
				DACset(val);
				break;
			case CMD_SEGCHAR:
				SR7segSetChar(val);
				SRapply();
				break;
		}
	}
}

int main(void) {

	// Prescaler Division: 2
	_PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, 0);

	USARTinit();
	DACinit();
	SRinit();

	SRval = 0b00000111; SRapply();

    while (1) {
		proc_serial();
//		SRdemo();
	}

    return 0;
}
