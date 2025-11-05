/*
 * IncFile1.h
 *
 * Created: 5/11/2025 2:52:36 PM
 *  Author: emb-1
 */ 


#ifndef SEVENSSEG_H_
#define SEVENSSEG_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "../LCD/LCD.h"







 


void FND_Init(void);
void FND_SetNumber(unsigned int temp, unsigned int light);

#endif

 