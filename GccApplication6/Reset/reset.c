#include "Reset.h"

unsigned char option = 0;  
unsigned char flag = 0;

void Setup_Control(unsigned char key)
{
	 

	if(key == '#' && flag == 0){
		LCD_clear();
		lcd_string_Out(LCD_LINE1,"Select an option");
		_delay_ms(2000);
		LCD_clear();
		lcd_string_Out(LCD_LINE1,"1. Reset Temp");
		lcd_string_Out(LCD_LINE2,"2. Reset Light");
		 

		flag = 1;
	}
	else if(key == '1'){
		LCD_clear();
		lcd_string_Out(LCD_LINE1,"Set Temp :");
		option = TEMP;
	}
	else if(key == '2'){
		LCD_clear();
		lcd_string_Out(LCD_LINE1,"Set Light :");
		option = LIGHT;
	} 
	else if(key == '5'){
		if(option == TEMP)
		{
			LCD_clear();
			lcd_string_Out(LCD_LINE1,"increment temp");
			LCD_displayInt(LCD_LINE2,1,temp_threshold);
			_delay_ms(1000);
			temp_threshold++;
			LCD_displayInt(LCD_LINE2,1,temp_threshold);
			_delay_ms(1000);
		}
		else if(option == LIGHT)
		{
			LCD_clear();
			lcd_string_Out(LCD_LINE1,"increment light");
			LCD_displayInt(LCD_LINE2,1,light_threshold);
			_delay_ms(1000);
			light_threshold++;
			LCD_displayInt(LCD_LINE2,1,light_threshold);
			_delay_ms(1000);
		}
		 
	}else if(key == '8'){
		if(option == TEMP)
		{
			LCD_clear();
			lcd_string_Out(LCD_LINE1,"decrement temp");
			LCD_displayInt(LCD_LINE2,1,temp_threshold);
			_delay_ms(1000);
			temp_threshold--;
			LCD_displayInt(LCD_LINE2,1,temp_threshold);
			_delay_ms(1000);
		}
		else if(option == LIGHT)
		{
			LCD_clear();
			lcd_string_Out(LCD_LINE1,"decrement light");
			LCD_displayInt(LCD_LINE2,1,light_threshold);
			_delay_ms(1000);
			light_threshold--;
			LCD_displayInt(LCD_LINE2,1,light_threshold);
			_delay_ms(1000);
		}
		 
	}else if(key == '#' && flag == 1){
		LCD_clear();
		lcd_string_Out(LCD_LINE1,"  Manual Mode");
		MODE = MANUAL_MODE;
	
		flag = 0;
	}
	/*
	else if(key == '9'){ // ????? ???????
		if(option == LIGHT){
			LCD_clear();
			lcd_string_Out(LCD_LINE1, "Light ON");
			PORTD |= (1 << LIGHT_PIN);
			_delay_ms(1000);
		}
	}
	else if(key == '0'){ // ????? ???????
		if(option == LIGHT){
			LCD_clear();
			lcd_string_Out(LCD_LINE1, "Light OFF");
			PORTD &= ~(1 << LIGHT_PIN);
			_delay_ms(1000);
		}
	}
	*/
}
