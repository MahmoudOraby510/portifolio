/*
 * CFile1.c
 *
 * Created: 5/3/2025 2:09:34 PM
 *  Author: emb-1
 */ 
#include "motor.h"


/*
void motor_Init(void){
	DDRC |= (1 << PB0);
}

void motor_control( unsigned char key) {
	switch(key) {
		
		case '3':
		PORTC |= (1 << PC0);
		PORTC &= ~(1 << PC0);
		_delay_ms(1000);
		
		PORTC&= ~((1 << PC0) | (1 << PC0));
		break;
		case '4':
		PORTC|= (1 << PC0);
		PORTC&= ~(1 << PC0);
		_delay_ms(1000);
		
		PORTC&= ~((1 << PC0) | (1 << PC0));
		break;
		default:
		PORTC&= ~((1 << PC0) | (1 << PC0));
	}
}
*/




/*******************************************************************************
* STEP_MOTOR.c *
********************************************************************************/






#define	DIR_CCW		1
#define	DIR_CW		2

volatile unsigned char	phase = 0;
volatile unsigned char	mot_dir = 0;
volatile unsigned short angle_pulse_cnt = 0;

const char	mot_step[8] = {0x10,0x30,0x20,0x60,0x40,0xC0,0x80,0x90};

volatile unsigned char	motor_rotation_count = 0;
volatile unsigned char 	setup_rotation_count = 0;


/*******************************************************************************
* Function Name  : ISR(TIMER0_OVF_vect)
*******************************************************************************/

void motor_Init(void)
{
	
	PORTD	= 0x00;
	DDRD	= 0xF0;

	TCNT0 	= 22;
	TIFR	|= (1<<TOV0);
	TIMSK 	|= (1<<TOIE0);
	TCCR0 = (7<<CS00);

	sei();
	
}

void motor_control(unsigned char key)
{
	if(key == '3'){
		LCD_clear();
		lcd_string_Out(LCD_LINE1, "DOOR is Opened");
		motor_rotation_count=1;
		mot_dir = DIR_CW;
	}else if(key == '4'){
		 LCD_clear();
		 lcd_string_Out(LCD_LINE1, "DOOR is Closed");
		motor_rotation_count=1;
		mot_dir = DIR_CCW;
	}
}
 void motor(unsigned char key)
 {
	 if(key == '7'){
		 LCD_clear();
		 lcd_string_Out(LCD_LINE1, "FAN is ON");
		 motor_rotation_count=100;
		 mot_dir = DIR_CW;
		 }else if(key == '8'){
			LCD_clear();
			lcd_string_Out(LCD_LINE1, "FAN is OFF");
		 motor_rotation_count=0;
		 mot_dir = DIR_CCW;
	 }
 }




ISR(TIMER0_OVF_vect)
{
	cli();

	TCNT0 	= 22;

	if(motor_rotation_count)
	{
		if(angle_pulse_cnt < 95)
		{
			angle_pulse_cnt++;
		}
		else
		{
			angle_pulse_cnt = 0;
			motor_rotation_count--;
		}

		if ((mot_dir == DIR_CW))
		{
			phase = angle_pulse_cnt % 8;
		}
		else
		{
			phase = 7 - (angle_pulse_cnt % 8);
		}
		
		PORTD &= ~0xF0;
		PORTD |= mot_step[phase];
	}
	
	

	sei();
}








