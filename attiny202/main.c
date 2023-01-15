#include "main.h"
#include "config.h"

#include <avr/io.h> 
#include <util/delay.h>
#include <stdlib.h>	
#include <avr/interrupt.h>

// 入力した0~9までの値と同じ数だけLEDを点滅させる

#define USART0_BAUD_RATE(BAUD_RATE) ((float)(F_CPU * 64 / (16 * (float)BAUD_RATE)) + 0.5)

// RX割込
ISR(USART0_RXC_vect) {
}

// USART0初期化
void USART0_init() {
	// ボーレート設定
	USART0.BAUD = (uint16_t)USART0_BAUD_RATE(115200);
	PORTMUX.CTRLB |= PORTMUX_USART0_DEFAULT_gc;
	USART0.CTRLA |= USART_RXCIE_bm;
	USART0.CTRLB |= USART_RXEN_bm; 
	while(USART0.STATUS & USART_RXCIF_bm) { USART0.RXDATAL; }
	sei();
}

void PWM_init() {
	PORTA.DIRSET = (1<<3); // PA3(WO0)
    TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP0EN_bm            // enable compare channel 0 
                      | TCA_SINGLE_WGMODE_DSBOTTOM_gc;  // set dual-slope PWM mode
    TCA0.SINGLE.EVCTRL &= ~(TCA_SINGLE_CNTEI_bm);       // disable event counting
    
    /* set PWM frequency and duty cycle */
	// f = (20M / (2 * 2 * PERBUF))
    TCA0.SINGLE.PERBUF  = 32; // PERIOD_EXAMPLE_VALUE
    TCA0.SINGLE.CMP0BUF = 16; // DUTY_CYCLE_EXAMPLE_VALUE(PERBUF/2=50%)
     
    TCA0.SINGLE.CTRLA = TCA_SINGLE_CLKSEL_DIV2_gc // set clock source (sys_clk/2)
                      | TCA_SINGLE_ENABLE_bm;     // start timer

}

int main(void) {
	_PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, 0);
	USART0_init();
	PWM_init();
	LED_OUT;
	LED_L;

	TCA0.SINGLE.PERBUF  = 100;
	TCA0.SINGLE.CMP0BUF = 50;

    while (1) {
		loop();
	}
    return 0;
}

void loop() {

	if(USART0.STATUS & USART_RXCIF_bm) {
		uint8_t code=USART0.RXDATAL;
		if((code >=48) && (code <=57)) { // 0~9
			uint8_t num=code-48;
			TCA0.SINGLE.CMP0BUF = num*10;
		} else if((code == 0x2D)) { // -
			TCA0.SINGLE.CMP0BUF = 100;
		}
		while(USART0.STATUS & USART_RXCIF_bm) { USART0.RXDATAL; }
	}
	_delay_ms(10);
}
