/*
 * IncFile1.h
 *
 * Created: 5/3/2025 2:09:49 PM
 *  Author: emb-1
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include <avr/io.h>
#include <avr/delay.h>


#include <avr/interrupt.h>
#include "../LCD/LCD.h"


void motor_Init(void);

void motor_control(unsigned char key);

void motor(unsigned char key);
 

#endif /* INCFILE1_H_ */