/*
 * CFile1.c
 *
 * Created: 4/19/2025 3:47:58 PM
 *  Author: emb-1
 */ 


#include "./LCD.h"

char lcd_str1[17] = "  **Text LCD**  ";
char lcd_str2[17] = "  Test Program  ";


void instruction_Out(unsigned char data)
{
	LCD_CONTROL_REGISTER_SELECT;
	LCD_DATA_WRITE;

	LCD_ENABLE;
	PORTF &= ~0xF0;
	PORTF |= data & 0xF0;
	LCD_DISABLE;
	

	LCD_ENABLE;
	PORTF &= ~0xF0;
	PORTF |= (data << 4) & 0xF0;
	LCD_DISABLE;
	
	_delay_ms(1);
}


void char_Out(unsigned char data)
{
	LCD_DATA_REGISTER_SELECT;
	LCD_DATA_WRITE;
	
	LCD_ENABLE;
	PORTF &= ~0xF0;
	PORTF |= data & 0xF0;
	LCD_DISABLE;
	

	LCD_ENABLE;
	PORTF &= ~0xF0;
	PORTF |= (data << 4) & 0xF0;
	LCD_DISABLE;
	
	_delay_ms(1);
}


void lcd_string_Out(unsigned char line_sel, char* str)
{
	unsigned char i = 0;
	unsigned char count = 0;
	
	instruction_Out(line_sel);
	
	do{
		char_Out(str[i]);
		count++;
	}while(str[++i]!='\0');
	
	for(i = (16 - count); i < 16; i++)
	{
		char_Out(' ');
	}
}


void lcd_Number_Out( char* str)
{
	unsigned char i = 0;
	unsigned char count = 0;
	
 
	
	do{
		char_Out(str[i]);
		count++;
	}while(str[++i]!='\0');
	
	for(i = (16 - count); i < 16; i++)
	{
		char_Out(' ');
	}
}

void init_LCD()
{
	DDRE |= 0x0C;
	DDRF |= 0xF0;
	DDRG |= 0x10;
	
	LCD_DISABLE;

	_delay_ms(100);
	instruction_Out(0x28);             // LCD FUNCTION SET(16*2LINE, 4BIT, 5*8DOT)
	_delay_ms(100);
	instruction_Out(0x28);             // LCD FUNCTION SET(16*2LINE, 4BIT, 5*8DOT)
	_delay_ms(100);
	instruction_Out(0x0c);             // LCD DISPLAY ON,CURSOR OFF,BLINK OFF
	_delay_ms(100);
	instruction_Out(0x01);             // LCD CLEAR
	_delay_ms(100);
	instruction_Out(0x06);             // LCD ENTRY MODE SET
	_delay_ms(100);
	instruction_Out(0x02);             // RETURN HOME
}


void LCD_clear()
{
		instruction_Out(0x01);             // LCD CLEAR
		_delay_ms(100);
}
void LCD_gotoLine(unsigned char line){
	instruction_Out(line);
}




// Set cursor to specific line and position (0-indexed)
void LCD_cursor(unsigned char line, unsigned char pos)
{
	unsigned char address;

	// Ensure position is within 0–15
	if (pos > 15) pos = 15;

	// Determine DDRAM address based on line
	if (line == LCD_LINE1)
	address = 0x00 + pos;  // Line 1 starts at 0x00
	else if (line == LCD_LINE2)
	address = 0x40 + pos;  // Line 2 starts at 0x40
	else
	address = 0x00;        // Default to beginning if invalid line

	instruction_Out(0x80 | address); // 0x80 is the command for setting DDRAM address
}



// Displays an integer at a specified line and column on the LCD
void LCD_displayInt(unsigned char line, unsigned char pos, int value)
{
	char str[17];  // LCD line buffer (max 16 characters + null terminator)
	snprintf(str, sizeof(str), "%d", value);  // Convert int to string
	LCD_cursor(line, pos);   // Set LCD cursor to desired position
	lcd_Number_Out(str);         // Print the string on LCD
}