#include "manual.h"



void Manual_Control(unsigned char key)
{


	if (key != 0xFF) // key is pressed
	{
		//char_Out(key);
		if (key == '*')
		{
			LCD_clear();
			lcd_string_Out(LCD_LINE1, " Password Mode");
			_delay_ms(2000);
			LCD_clear();
			lcd_string_Out(LCD_LINE1, "Enter Password:");
			LCD_gotoLine(LCD_LINE2);
			
			MODE = PASSWORD_MODE;
		}
		else if (key == '#')
		{
			lcd_string_Out(LCD_LINE1, "Reset Mode");
			_delay_ms(1000);
			MODE = RESET_MODE;
		}
		else if (key == '1' || key == '2')
		{
			//LED control
			
			LED_control(key);
			
		}
		else if (key == '3' || key == '4')
		{
			//Door control
			motor_control(key);
		}
		else if (key == '5' || key == '6')
		{
			//fan control
	        LED_control(key);
		}
		else if (key == '7' || key == '8')
		{
			motor(key);
			// FAN_control
			//FAN_control (key);
		}else if (key == '9'|| key == '0' )
		{
			
	       // AC
	        relay(key);
			
		}

	}

}