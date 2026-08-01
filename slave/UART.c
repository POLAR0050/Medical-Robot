#include <avr/io.h>

#include "UART.h"

/* Baud = 9600 @ F_CPU = 8MHz -> UBRR = 51 (??? ???? ??????? ??????) */

void UART_Init(void)
{
	UCSRA = 0x00;

	UCSRB = (1<<RXEN) | (1<<TXEN);

	UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);

	UBRRH = 0;
	UBRRL = 51;
}

void UART_SendChar(u8 data)
{
	while(!(UCSRA & (1<<UDRE)));

	UDR = data;
}

void UART_SendString(u8 *str)
{
	while(*str)
	{
		UART_SendChar(*str++);
	}
}

u8 UART_ReceiveChar(void)
{
	while(!(UCSRA & (1<<RXC)));

	return UDR;
}

u8 UART_DataAvailable(void)
{
	return (UCSRA & (1<<RXC)) ? 1 : 0;
}