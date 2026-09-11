/*
 * LcdNameApp_Program.c
 *
 *  Created on: Sep 11, 2026
 *      Author: mahmo
 */

#include "LcdNameApp_Interface.h"

//Special Letter M
static uint8_t UpperFirstCharBitmap[8] =
{
	0b10001,
	0b11011,
	0b10101,
	0b10001,
	0b10001,
	0b10001,
	0b10001,
	0b00000
};

//Special Letter m
static uint8_t LowerFirstCharBitmap[8] =
{
	0b00000,
	0b00000,
	0b00000,
	0b11010,
	0b10101,
	0b10101,
	0b10101,
	0b00000
};

void LcdNameApp_Init()
{
	LCD_Init();

	LCD_StoreSpecialCharacter(UpperFirstCharBitmap, LcdNameApp_UpperCharLocation);
	LCD_StoreSpecialCharacter(LowerFirstCharBitmap, LcdNameApp_LowerCharLocation);
}

void DisplaySpecialCharecter(uint8_t LocationNo)
{
	LCD_WriteCharacter(LocationNo);
}


void LcdNameApp_DisplayNameSinusoidal(void)
{
	uint8_t Name[] = LcdNameApp_Name;
	uint8_t Name_Len = sizeof(Name) - 1;
	uint8_t Max = LcdNameApp_LcdColumns - Name_Len;
	static uint8_t mover = 0;

		if (mover > Max)
		{
			mover = 0;
		}

		LCD_SendInstruction(Lcd_ClearDisplay);
		_delay_ms(2);
		LCD_MoveTo(Lcd_Line2, mover++);
		LCD_WriteString(Name);
		_delay_ms(LcdNameApp_ToggleDelayMs);

		LCD_SendInstruction(Lcd_ClearDisplay);
		_delay_ms(2);
		LCD_MoveTo(Lcd_Line1, mover++);
		LCD_WriteString(Name);
		_delay_ms(LcdNameApp_ToggleDelayMs);
}

void LcdNameApp_DisplayFirstCharBothCases(void)
{
	LCD_SendInstruction(Lcd_ClearDisplay);
	_delay_ms(2);

	LCD_MoveTo(Lcd_Line1, 0);
	DisplaySpecialCharecter(LcdNameApp_UpperCharLocation);

	LCD_MoveTo(Lcd_Line1, 1);
	DisplaySpecialCharecter(LcdNameApp_LowerCharLocation);
}

