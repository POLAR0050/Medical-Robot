#include <avr/io.h>

#include "UART.h"
#include "BIT_MATH.h"

/* Baud Rate = 9600 @ F_CPU = 8MHz -> UBRR = 51 */
#define UART_UBRR_VALUE 51

void UART_Init(void)
{
	UCSRA = 0x00;

	/* ????? ????????? (RXEN) */
	SET_BIT(UCSRB, RXEN);

	/* ????? ??????? (TXEN) */
	SET_BIT(UCSRB, TXEN);

	/* URSEL ???? = 1 ???? ???? ??? UCSRC (?? UBRRH) - ?????? ???? ?? ATmega32 */
	SET_BIT(UCSRC, URSEL);

	/* UCSZ1 + UCSZ0 = 1 -> ??? ???????? 8-bit */
	SET_BIT(UCSRC, UCSZ1);
	SET_BIT(UCSRC, UCSZ0);

	UBRRH = 0;
	UBRRL = UART_UBRR_VALUE;
}

void UART_SendChar(u8 data)
{
	while(GET_BIT(UCSRA, UDRE) == 0);

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
	while(GET_BIT(UCSRA, RXC) == 0);

	return UDR;
}