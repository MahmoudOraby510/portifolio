/*
 * Temp_LDR.c
 *
 * Created: 5/17/2025 12:13:02 PM
 *  Author: emb-1
 */ 




#include "./Temp_LDR.h"


#define R_FIXED 360.0     // 360? resistor
#define VREF 5.0            // Reference voltage
#define ADC_MAX 1023.0      // 10-bit ADC max value

// Convert ADC reading to temperature in Celsius
float getTemperatureFromADC(unsigned char channel)
{
	ADC_startConversion(channel);
	unsigned int adcValue = ADC_getValue();

	// Convert ADC value to voltage
	float Vout = (adcValue / ADC_MAX) * VREF;

	// Calculate thermistor resistance
	float Rt = R_FIXED * ((VREF - Vout) / Vout);

	

	return Rt;
}




// Convert ADC reading to light percentage (0% = dark, 100% = bright)
int getLightPercentage(unsigned char channel)
{
	ADC_startConversion(channel);
	unsigned int adcValue = ADC_getValue();
	float value = ((float)adcValue * 1024 ) / 680;

	// Map 0–1023 to 0–100% (inverse: high ADC = bright light)
	float lightPercent = ((float)value / 1023.0f) * 100.0f;

	return ((int)lightPercent);
}