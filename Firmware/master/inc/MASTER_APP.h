#ifndef MASTER_APP_H_
#define MASTER_APP_H_

#include "STD_TYPES.h"

void MASTER_Init(void);

void MASTER_Welcome(void);

void MASTER_SelectRoom(void);

void MASTER_SelectMedicine(void);

void MASTER_StartMission(void);

void MASTER_WaitResponse(void);

u16 MASTER_ReadNumber(void);

#endif
