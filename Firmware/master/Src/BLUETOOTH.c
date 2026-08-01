

#include "BLUETOOTH.h"

#include "UART.h"

void BT_Init(void)
{
	UART_Init();
}

void BT_Send(u8 *str)
{
	UART_SendString(str);
}

u8 BT_Read(void)
{
	return UART_ReceiveChar();
}
