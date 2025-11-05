/*
 * ac.c
 *
 * Created: 5/6/2025 8:20:54 AM
 *  Author: emb-1
 */ 

 #include "ac.h"

void AC_Init(void) {
	DDRB |= (1 << PB6);
	DDRB |= (1 << PB7);
}

unsigned char flag_op = 2;

void relay(unsigned char key) {
	cli();
	
	if (key == '9' && flag_op == 2) { 
		LCD_clear();
		lcd_string_Out(LCD_LINE1, "AC is ON");
		PORTB |= (1 << PB6);
		PORTB |= (1 << PB7);
		flag_op = 1;
	} else if(key == '0' && flag_op == 1){ 
		LCD_clear();
		lcd_string_Out(LCD_LINE1, "AC is OFF");
		PORTB &= ~(1 << PB6);
		PORTB &= ~(1 << PB7);
		flag_op = 2;
	}
	sei();
}