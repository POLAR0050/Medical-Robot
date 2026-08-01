#ifndef LED_H_
#define LED_H_

#include "STD_TYPES.h"

/*
 * ==========================================================
 *  LED PIN MAPPING
 * ==========================================================
 *  Signal : PC1
 * ==========================================================
 */

void LED_Init(void);
void LED_On(void);
void LED_Off(void);
void LED_Toggle(void);

#endif