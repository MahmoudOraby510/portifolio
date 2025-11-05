/*
 * IncFile1.h
 *
 * Created: 4/19/2025 3:28:24 PM
 *  Author: emb-1
 */ 


#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#include <avr/delay.h>




#define LCD_ENABLE       PORTG |= 0x10;
#define LCD_DISABLE      PORTG &= ~0x10;

#define LCD_CONTROL_REGISTER_SELECT       PORTE &= ~0x04;
#define LCD_DATA_REGISTER_SELECT          PORTE |= 0x04;

#define LCD_DATA_READ       PORTE |= 0x08;
#define LCD_DATA_WRITE      PORTE &= ~0x08;

#define LCD_LINE1   0x80  // set DD RAM Address Command : 0x80 | Position (1,0) DD RAM Address : 0x00
#define LCD_LINE2   0xC0  // set DD RAM Address Command : 0x80 | Position (2,0) DD RAM Address : 0x40

void instruction_Out(unsigned char data);

void char_Out(unsigned char data);

void lcd_string_Out(unsigned char line_sel, char* str);

void init_LCD();

void LCD_gotoLine(unsigned char line);

void LCD_clear();

void LCD_cursor(unsigned char line, unsigned char pos);

void LCD_displayInt(unsigned char line, unsigned char pos, int value);

void lcd_Number_Out( char* str);

#endif /* INCFILE1_H_ */