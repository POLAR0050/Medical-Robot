#ifndef BUZZER_H_
#define BUZZER_H_

#include "STD_TYPES.h"

/*
 * ==========================================================
 *  BUZZER PIN MAPPING
 * ==========================================================
 *  Signal : PC2
 * ==========================================================
 */

void BUZZER_Init(void);
void BUZZER_On(void);
void BUZZER_Off(void);

#endif