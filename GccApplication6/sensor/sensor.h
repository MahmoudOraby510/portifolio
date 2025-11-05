

#ifndef SENSOR_H_
#define SENSOR_H_

#include <avr/io.h>
#include <util/delay.h>


void init_ADC();
uint16_t read_ADC_m();
void displayNumber(uint8_t number);



 

 

#endif
