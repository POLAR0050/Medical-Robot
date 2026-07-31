#define F_CPU 8000000UL

#include <util/delay.h>

#include "MASTER_APP.h"

int main(void)
{
	MASTER_Init();

	while(1)
	{
		MASTER_Welcome();

		MASTER_SelectRoom();

		MASTER_SelectMedicine();

		MASTER_StartMission();

		MASTER_WaitResponse();
	}
}