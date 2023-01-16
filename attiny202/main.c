#include "main.h"
#include "config.h"

#include <avr/io.h> 
#include <util/delay.h>
#include <stdlib.h>	
#include <avr/interrupt.h>

#define USART0_BAUD_RATE(BAUD_RATE) ((float)(F_CPU * 64 / (16 * (float)BAUD_RATE)) + 0.5)

uint8_t cpuVal;
float curVal;

// RX割込
ISR(USART0_RXC_vect) {
}

void USART0_init() {
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

	TCA0.SINGLE.PERBUF  = 0xFF;
	TCA0.SINGLE.CMP0BUF = 0xFF;
	_delay_ms(1000);
	TCA0.SINGLE.CMP0BUF = 0x00;
	_delay_ms(1000);

    while(1) loop();
    return 0;
}

void usart_read() {
	if(!(USART0.STATUS & USART_RXCIF_bm)) return;
	// コマンドの取得
	uint8_t cmd=USART0.RXDATAL;
	for(uint8_t i=0;i<100;i++) {
		if(USART0.STATUS & USART_RXCIF_bm) break;
		_delay_ms(10);
	}
	// データの取得
	uint8_t val=USART0.RXDATAL;
	while(USART0.STATUS & USART_RXCIF_bm) { USART0.RXDATAL; }

	switch(cmd) {
		case CMD_CPU_LOAD:
			cpuVal = val;
			break;
		default:
			break;
	}
}

void loop() {
	usart_read();
	float cpu=((float)cpuVal/0xFF)*0xFFFF;
    if(curVal < cpu) {
        curVal=curVal+(cpu-curVal)/CFG_SMOOTH;
    } else if (curVal > cpu) {
        curVal=curVal-(curVal-cpu)/CFG_SMOOTH;
    }
	TCA0.SINGLE.CMP0BUF = (uint8_t)((curVal/0xFFFF)*0xFF);
	_delay_ms(50);
}
