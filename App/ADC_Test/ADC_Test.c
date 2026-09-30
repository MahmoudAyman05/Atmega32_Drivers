/*
 * ADC_Test.c
 *
 *  Created on: Sep 30, 2026
 *      Author: mahmo
 */
#include "ADC_Test.h"
#include <util/delay.h>

void ADCTest_Init()
{
	ADC_Init();
	LCD_Init();

	LCD_SendInstruction(0x0C);

	LCD_SendInstruction(Lcd_ClearDisplay);
	_delay_ms(2);
}

void ADCTest_Runner()
{
	uint16_t RawValue = 0;
	uint16_t Millivolts = 0;
	Adc_Status_t Status;

	Status = ADC_GetDigitalValue(Adc_Channel3, &RawValue);

	if (Status == Adc_Ok)
	{
		ADC_GetDigitalVolt(Adc_Channel3, &Millivolts);
		LCD_MoveTo(Lcd_Line1, 0);
		LCD_WriteString((uint8_t *)"Raw: ");
		LCD_WriteNumber(RawValue);
		LCD_WriteString((uint8_t *)"   ");

		LCD_MoveTo(Lcd_Line2, 0);
		LCD_WriteString((uint8_t *)"Volt: ");
		LCD_WriteNumber(Millivolts);
		LCD_WriteString((uint8_t *)"mV   ");
	}
	else if (Status == Adc_ErrorTimeout)
	{
		LCD_MoveTo(Lcd_Line1, 0);
		LCD_WriteString((uint8_t *)"ADC Timeout     ");
		LCD_MoveTo(Lcd_Line2, 0);
		LCD_WriteString((uint8_t *)"                ");
	}
	else
	{
		LCD_MoveTo(Lcd_Line1, 0);
		LCD_WriteString((uint8_t *)"ADC Error       ");
		LCD_MoveTo(Lcd_Line2, 0);
		LCD_WriteString((uint8_t *)"                ");
	}

	_delay_ms(500);
}
