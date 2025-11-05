
#ifndef AC_H_
#define AC_H_

#include "avr/io.h"
#include "../LCD/LCD.h"
#include <avr/interrupt.h>

void AC_Init(void);

void relay(unsigned char key) ;


#endif
