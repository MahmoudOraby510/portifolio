/*
 * IncFile1.h
 *
 * Created: 4/26/2025 2:59:20 PM
 *  Author: emb-1
 */

#ifndef INCFILE1_H_
#define INCFILE1_H_

#include "../LCD/LCD.h"
#include "../Keybad/keybad.h"
#include "../main.h"

static void PASS_manPass(unsigned char key);

static int PASS_retPass(void);
void PASS_Reset(void);

void Password_input(unsigned char key);

#endif /* INCFILE1_H_ */