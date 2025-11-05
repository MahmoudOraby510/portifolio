/*
 * CFile1.c
 *
 * Created: 4/26/2025 2:39:55 PM
 *  Author: emb-1
 */

#include "./password.h"


int current_key = 0, old_key = 0;
int counter = 0;

static void PASS_manPass(unsigned char key)
{
	if (counter < 4)
	{
		current_key = key - '0'; // convert char to a number
		old_key = old_key * 10 + current_key;
		counter++;
	}
}

static int PASS_retPass(void)
{

	return old_key;
}
 void PASS_Reset(void)
{
	old_key = 0;
	current_key = 0;
	counter = 0;
}

void Password_input(unsigned char key)
{

	if (key != 0xff) // key is pressed
	{
		
		if (key == '*')
		{
			lcd_string_Out(LCD_LINE1, "Manual Mode");
			_delay_ms(2000);
			MODE = MANUAL_MODE;
		}
		else if (key == '#')
		{
			int user_pass = PASS_retPass();
			 char_Out(user_pass);
			_delay_ms(500);
			if (counter == 4 && password == PASS_retPass())
			{
				LCD_clear();
				lcd_string_Out(LCD_LINE1, "Correct Password");
				_delay_ms(1000);
				LCD_clear();
				lcd_string_Out(LCD_LINE1, "   RESET Mode");
				MODE = RESET_MODE;
			}
			else
			{
				try_no++;
				PASS_Reset();

				if (try_no <= 3)
				{
					lcd_string_Out(LCD_LINE1, "Wrong pass");
					_delay_ms(1000);
					lcd_string_Out(LCD_LINE1, "try again!");
				}
				else
				{
					try_no = 0;
					lcd_string_Out(LCD_LINE1, "Wait 30 SEC");
					_delay_ms(1000);
				}
			}
		}
		else
		{
			char_Out(key);
			PASS_manPass(key);
		}
	}
}