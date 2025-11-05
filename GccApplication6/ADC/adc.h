#ifndef ADC_H_
#define ADC_H_

// adc_driver.c

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>

#define CDS_CHANNEL 0
#define THERMISTOR_CHANNEL 1

void ADC_startConversion(unsigned char channel);

void ADC_Init();

unsigned int ADC_getValue();

unsigned int ADC_getValueStr(char *arr);

#endif