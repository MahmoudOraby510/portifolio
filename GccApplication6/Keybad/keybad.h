/*
 * IncFile1.h
 *
 * Created: 4/19/2025 4:36:16 PM
 *  Author: emb-1
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

/*
 * IncFile1.h
 *
 * Created: 4/19/2025 4:00:14 PM
 *  Author: emb-1
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

extern unsigned char PUSHED_KEY;

void init_Keypad();
unsigned char mapKeyValue(unsigned char key);
unsigned char getPressedKey();

#endif /* INCFILE1_H_ */