/*
 * CFile1.c
 *
 * Created: 5/3/2025 12:32:00 PM
 *  Author: emb-1
 */ 

#include "LED.h"

void LED_Init(void){
	DDRC |= (1 << PC0);
	DDRC |= (1<<PC1);
	DDRC |= (1<<PC2);
	DDRC |= (1<<PC7);
	PORTC |= (1 << PC7);
}

	

void LED_control(unsigned char key)
{
	if (key == '1')
	{
		 LCD_clear();
		 lcd_string_Out(LCD_LINE1, "LED is ON");
		PORTC |= (1 << PC0); 
	}
	else if (key == '2')
	{
		 LCD_clear();
		 lcd_string_Out(LCD_LINE1, "LED is OFF");
		PORTC &= ~(1 << PC0);
	}
	
	else if (key == '5')
	{
		 LCD_clear();
		 lcd_string_Out(LCD_LINE1, "Curtains opened");
		PORTC |= (1 << PC1);
	}
	else if (key == '6')
	{
		LCD_clear();
		lcd_string_Out(LCD_LINE1, "Curtains closed");
		PORTC &= ~(1 << PC1);
	}


	

}