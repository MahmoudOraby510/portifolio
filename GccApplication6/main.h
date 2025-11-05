/*
 * main.h
 *
 * Created: 4/27/2025 2:48:53 PM
 *  Author: emb-1
 */ 



#ifndef MAIN_H_
#define MAIN_H_

#include "./LCD/LCD.h"
#include "./ADC/adc.h"
#include "./LED/LED.h"
#include "./motor/motor.h"
#include "./AC/ac.h"
#include "ADC/adc.h"
#include "./sevenSeg/sevenSeg.h"
#include "./Temp_LDR/Temp_LDR.h"
#include "./Reset/reset.h"
 

// Modes
// macro
#define MANUAL_MODE (int)1
#define PASSWORD_MODE (int)2
#define RESET_MODE (int)3

extern int MODE;
extern int try_no;
extern int password;

void auto_control();


void APP_control_AC(int temp);

void APP_control_light(int light);

#endif