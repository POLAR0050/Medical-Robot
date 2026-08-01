#ifndef LCD_H_
#define LCD_H_

#include "STD_TYPES.h"

void LCD_Init(void);

void LCD_SendCommand(u8 command);

void LCD_SendData(u8 data);

void LCD_SendString(u8 *str);

void LCD_GoTo(u8 row,u8 column);

void LCD_Clear(void);

void LCD_SendNumber(s32 number);

#endif
