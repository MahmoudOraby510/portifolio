// adc_driver.c

#include "adc.h"

volatile unsigned int ADC_DATA_H;
volatile unsigned int ADC_DATA_L;
volatile unsigned char adc_flag;

ISR(ADC_vect)
{
	cli();
	ADC_DATA_L = ADCL;
	ADC_DATA_H = ADCH;
	adc_flag = 1;
	sei();
}

void ADC_startConversion(unsigned char channel)
{
	ADCSRA = 0x9E;
	ADMUX = 0x40 | channel;

	sei();
	adc_flag = 0;

	ADCSRA |= 0x40; // Start conversion
	while (!adc_flag)
	; // Wait for ISR to finish

	cli();
	ADCSRA = 0; // Disable ADC
	sei();
}

void ADC_Init()
{
	DDRF &= ~0x03;
}

unsigned int ADC_getValue()
{
	
	unsigned int sensor_value = (ADC_DATA_H << 8) | ADC_DATA_L;
	return sensor_value;
}

unsigned int ADC_getValueStr(char *arr)
{
	unsigned int sensor_value = ADC_getValue();
	sprintf(arr, "%02d", sensor_value);
	
	return sensor_value;
}