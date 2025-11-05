/*
 * Temp_LDR.h
 *
 * Created: 5/17/2025 12:12:46 PM
 *  Author: emb-1
 */ 


#ifndef TEMP_LDR_H_
#define TEMP_LDR_H_

 

#include <math.h>
#include "../ADC/adc.h"

float getTemperatureFromADC(unsigned char channel);
int getLightPercentage(unsigned char channel);
 



#endif /* TEMP_LDR_H_ */