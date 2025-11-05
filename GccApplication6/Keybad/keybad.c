/*
 * CFile1.c
 *
 * Created: 4/19/2025 3:59:32 PM
 *  Author: emb-1
 */ 

#include "./keybad.h"

unsigned char PUSHED_KEY = 0xFF;

ISR(INT0_vect)
{
	
	PUSHED_KEY = PINE & 0xF0;
	PUSHED_KEY = PUSHED_KEY >> 4;
}

// Initialize keypad and INT0
void init_Keypad()
{
	DDRD &= ~(1 << PD0);   // INT0 as input
	EICRA |= (1 << ISC01); // Falling edge for INT0
	EIMSK |= (1 << INT0);  // Enable INT0 interrupt
	EIFR  |= (1 << INTF0); // Clear interrupt flag
	DDRE  &= ~0xF0;        // PORTE4–7 as input
	sei();                 // Enable global interrupts
}

// Map the nibble value to actual keypad character
unsigned char mapKeyValue(unsigned char key)
{
	switch (key)
	{
		
		case 0x00:	return '1';
		case 0x01:	return '2';
		case 0x02:	return '3';
		case 0x03:	return '4';
		case 0x04:	return '5';
		case 0x05:	return '6';
		case 0x06:	return '7';
		case 0x07:	return '8';
		case 0x08:	return '9';
		case 0x09:	return '*';
		case 0xA:	return '0';
		case 0xB:	return '#';
		default:	return 0xFF; // Unknown key
	}
}

// Get last pressed key
unsigned char getPressedKey()
{
	if (PUSHED_KEY != 0xFF)
	{
		unsigned char key = mapKeyValue(PUSHED_KEY);
		PUSHED_KEY = 0xFF; // Reset after reading
		return key;
	}
	return 0xFF; // No key pressed
}