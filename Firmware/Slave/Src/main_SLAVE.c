/*
 * Medical_Robot_Slave.c
 *
 * Created: 7/31/2026 11:11:05 AM
 * Author : User
 */

#define F_CPU 8000000UL

#include "SLAVE_APP.h"

int main(void)
{
	u16 Room;
	u8 Medicine;
	u8 Result;

	SLAVE_Init();

	while(1)
	{
		SLAVE_WaitCommand(&Room, &Medicine);

		Result = SLAVE_ExecuteMission(Room, Medicine);

		SLAVE_SendResult(Result);
	}
}
