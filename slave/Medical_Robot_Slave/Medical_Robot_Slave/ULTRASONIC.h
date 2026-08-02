#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "STD_TYPES.h"

/*
 * ==========================================================
 *  ULTRASONIC (HC-SR04) PIN MAPPING
 * ==========================================================
 *  Trigger : PC0
 *  Echo    : PD2 (INT0)
 * ==========================================================
 */

void ULTRASONIC_Init(void);

/* ????? ??????? ?????????? */
u16 ULTRASONIC_GetDistance(void);

#endif