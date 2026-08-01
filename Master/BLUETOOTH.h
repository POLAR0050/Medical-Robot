#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "STD_TYPES.h"

void BT_Init(void);

void BT_Send(u8 *str);

u8 BT_Read(void);

#endif