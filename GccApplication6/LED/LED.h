/*
 * IncFile1.h
 *
 * Created: 5/3/2025 12:32:25 PM
 *  Author: emb-1
 */ 


#ifndef LED_H_
#define LED_H_

#include <avr/io.h>
#include "../LCD/LCD.h"

void LED_Init(void);

void LED_control(unsigned char key);


#endif
