
#ifndef __RESET_H__
#define __RESET_H__

#include <util/delay.h>
#include "../LCD/LCD.h"
#include "../main.h"

 
#define LIGHT (char)1
#define TEMP (char)2 

extern int light_threshold;
extern int temp_threshold ;
extern int MODE;

void Setup_Control(unsigned char key);

#endif /* __RESET_H__ */
