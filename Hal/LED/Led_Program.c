/*
 * Led_Program.h
 *
 *  Created on: Aug 22, 2026
 *      Author: mahmo
 */

#ifndef HAL_LED_LED_PROGRAM_C_
#define HAL_LED_LED_PROGRAM_C_

#include "Led_Interface.h"

void Led_Init(uint8_t GroupName, uint8_t PinNo)
{
	DIO_DirectionSetForPin(GroupName, PinNo, DIO_Output);
}

void Led_On(uint8_t GroupName, uint8_t PinNo, uint8_t ConnectionType)
{
	if(ConnectionType==Led_SourceConnection)
	{
		DIO_WriteValueForPin(GroupName, PinNo, DIO_High);
	}
	if(ConnectionType==Led_SinkConnection)
	{
		DIO_WriteValueForPin(GroupName, PinNo, DIO_Low);
	}
}

void Led_Off(uint8_t GroupName, uint8_t PinNo, uint8_t ConnectionType)
{
	if(ConnectionType==Led_SourceConnection)
		{
			DIO_WriteValueForPin(GroupName, PinNo, DIO_Low);
		}
		if(ConnectionType==Led_SinkConnection)
		{
			DIO_WriteValueForPin(GroupName, PinNo, DIO_High);
		}
}

void Led_Toggle(uint8_t GroupName, uint8_t PinNo)
{
	DIO_ToggleValueForPin(GroupName,PinNo);
}

#endif /* HAL_LED_LED_PROGRAM_C_ */
