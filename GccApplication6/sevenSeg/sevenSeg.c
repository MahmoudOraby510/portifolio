/*
 * CFile1.c
 *
 * Created: 5/11/2025 2:52:43 PM
 *  Author: emb-1
 */ 
#include "sevenSeg.h"

 

/*



void SSeg_displayNumber(uint8_t number) {
	uint8_t tens = number / 10;
	uint8_t ones = number % 10;

	PORTB = (1 << PB0);
	PORTA = FND_NUMBER[tens];
	_delay_ms(1000);

	PORTB = (1 << PB1);
	PORTA = FND_NUMBER[ones];
	_delay_ms(1000);
}


void init_7seg(void) {
	
	
	
	

	DDRB  = 0x0F; // control pins
	DDRA = 0xFF;	//seven seg data pins
	PORTA = 0x00;
	
	PORTB = (1 << PB0) | (1 << PB1);
}
*/
 




#define FND_MASK 0b11110000 // Mask for FND (7-segment display) pins

const uint8_t FND_NUMBER[10] = {
	0x3F, 0x06, 0x5B, 0x4F, 0x66,
	0x6D, 0x7D, 0x07, 0x7F, 0x6F
};

/*
static const unsigned char FND_NUMBER[10] = {
	0b00111111, // 0
	0b00000110, // 1
	0b01011011, // 2
	0b01001111, // 3
	0b01100110, // 4
	0b01101101, // 5
	0b01111101, // 6
	0b00100111, // 7
	0b01111111, // 8
	0b01101111  // 9
};
*/

// Global variables to hold the current number and digit to display
volatile unsigned char currentNumber ;
volatile unsigned char  tempTens = 0 ;
volatile unsigned char  tempUnits = 0;
volatile unsigned char  lightTens = 0;
volatile unsigned char  lightUnits  = 0;

volatile unsigned char currentDigit = 0; // 0 = right digit, 1 = left digit
volatile unsigned char isChanged = 0;    // Flag to indicate if the number has changed

volatile unsigned int temperature = 0 ;
volatile unsigned int lightIntensity = 0  ;

// Function to initialize FND (7-segment displays)
void FND_Init()
{
	DDRA |= 0xFF; // Segment lines (PORTA)
	PORTA = 0x00;

	DDRB |= 0x0f; // Digit select (PB0 for right digit, PB1 for left digit)
	PORTB = 0x00;

	// Set up Timer1 to trigger an interrupt every 5 ms
	TCCR1B |= (1 << WGM12);              // CTC mode (Clear Timer on Compare Match)
	OCR1A = 100;                         // Set compare value for 5ms delay (with 1024 prescaler)
	TCCR1B |= (1 << CS12) | (1 << CS10); // Prescaler 1024
	TIMSK |= (1 << OCIE1A);             // Enable Timer1 Compare Match A interrupt
	sei();                               // Enable global interrupts
}

// Timer1 ISR - Interrupt Service Routine

// Function to set the current number to be displayed
// Timer1 ISR - Interrupt Service Routine

ISR(TIMER1_COMPA_vect)
{
	cli();
	if (isChanged)
	{
		// Update the display only if the number has changed
		tempTens = temperature / 10;
		tempUnits = temperature % 10;
		lightTens = (lightIntensity / 10);
		lightUnits = (lightIntensity % 10);

		isChanged = 0; // Reset the flag after displaying
	}
	// Update tens and units digits for both values

	PORTB &= 0xF0; // Clear the digit select lines
	// Toggle the current digit to display
	if (currentDigit == 0)
	{
		// Display the first digit of temperature (tens)

		PORTB |= (1 << 0);            // Enable first digit of temp (left)
		PORTA = FND_NUMBER[tempTens]; // Display temperature tens digit
		currentDigit = 1;             // Switch to second digit of temp
	}
	else if (currentDigit == 1)
	{
		PORTB |= (1 << 1);              // Enable second digit of temp (right)
		PORTA = FND_NUMBER[tempUnits]; // Display temperature units digit
		currentDigit = 2;              // Switch to first digit of light intensity
	}
	else if (currentDigit == 2)
	{
		PORTB |= (1 << 2);              // Enable first digit of light intensity (left)
		PORTA = FND_NUMBER[lightTens]; // Display light intensity tens digit
		currentDigit = 3;              // Switch to second digit of light intensity
	}
	else if(currentDigit == 3)
	{
		PORTB |= (1 << 3);               // Enable second digit of light intensity (right)
		PORTA = FND_NUMBER[lightUnits]; // Display light intensity units digit
		currentDigit = 0;               // Reset to first digit of temp for the next cycle
	}
	sei();
}


// Function to set the temperature and light intensity values to be displayed
void FND_SetNumber(unsigned int temp, unsigned int light)
{
	cli();
	temperature = temp;
	lightIntensity = light;
	isChanged = 1; // Set the flag to indicate that the number has changed
	sei();
}
