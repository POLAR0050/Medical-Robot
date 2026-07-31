#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"
#include <util/delay.h>

void Keypad_Init(void);
char Keypad_GetKey(void);

#endif
