
#include "main.h"

int MODE = MANUAL_MODE;
int password = 1234;
int try_no = 1;
int light_threshold=60;
int temp_threshold = 25;




int main(void)
{
	LED_Init();
	motor_Init();
	
	init_LCD();
	init_Keypad();
	ADC_Init();
	AC_Init();
	
	FND_Init();
	
	
 
	
	LCD_clear();
	lcd_string_Out(LCD_LINE1, " Welcome To Our");
	lcd_string_Out(LCD_LINE2, "   Smart Home");
	_delay_ms(2000);
	
	//lcd_string_Out(LCD_LINE1, "Enter Password");
	 

	PASS_Reset();

	while (1)
	{
		
		
		
		unsigned char key = getPressedKey();
		
		if (key != 0xFF)
		{	
		
			if (MODE == PASSWORD_MODE)
			{
				Password_input(key);
			}
			  if (MODE == MANUAL_MODE)
			{
				Manual_Control(key);
			}
			  if (MODE == RESET_MODE)
			{
				
				Setup_Control(key);
			}
			
		}
		auto_control();
		
		_delay_ms(100);
	}
	
	
	
	 


	return 0;
}


void auto_control()
{
	
	
	unsigned int light =  getLightPercentage(CDS_CHANNEL);
	unsigned int temp =  getTemperatureFromADC(THERMISTOR_CHANNEL);
	if(temp <= 1500){
		temp = (1500 - temp ) / 27;
		temp  += 6;
	}else{
		temp = 0;
	}
	 
	 
	FND_SetNumber(temp, light);
	
	APP_control_AC(temp);
	
	APP_control_light(light);
	
	 
	
	
}


void APP_control_AC(int temp){
	 
	
	
	if(temp >= temp_threshold)
	{
		relay('9'); 
		
	}else{
		relay('0');  
	}
	
	
}

void APP_control_light(int light){
	 
	
	if(light >= light_threshold){
		//there is light
		PORTC &= ~ (1 << PC7);  
		
		}else{
		//there is no light
		PORTC |= (1 << PC7); 
	}
	
}

