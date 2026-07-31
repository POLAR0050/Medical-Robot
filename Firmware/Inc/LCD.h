#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#include <util/delay.h>
#include <stdlib.h>


#define LCD_D0 PORT_D,PIN0
#define LCD_D1 PORT_D,PIN1
#define LCD_D2 PORT_D,PIN2
#define LCD_D3 PORT_D,PIN3
#define LCD_D4 PORT_D,PIN4
#define LCD_D5 PORT_D,PIN5
#define LCD_D6 PORT_D,PIN6
#define LCD_D7 PORT_D,PIN7


#define LCD_RS PORT_C,PIN5
#define LCD_RW PORT_C,PIN6
#define LCD_EN PORT_C,PIN7

void LCD_Init(void);
void LCD_Command(unsigned char cmd);
void LCD_Char(unsigned char data);
void LCD_String(char *str);
void LCD_Clear(void);
void LCD_Goto(unsigned char row,unsigned char col);
void LCD_Number(long num);

#endif
