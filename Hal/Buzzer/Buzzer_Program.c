/*
 * Buzzer_Program.h
 *
 *  Created on: Aug 22, 2026
 *      Author: mahmo
 */

#ifndef HAL_BUZZER_BUZZER_PROGRAM_C_
#define HAL_BUZZER_BUZZER_PROGRAM_C_
#include "Buzzer_Interface.h"

void Buzzer_Init(uint8_t GroupName, uint8_t PinNo)
{
	DIO_DirectionSetForPin(GroupName, PinNo, DIO_Output);
	DIO_WriteValueForPin(GroupName, PinNo, DIO_Low);
}

void Buzzer_On(uint8_t GroupName, uint8_t PinNo)
{
	DIO_WriteValueForPin(GroupName, PinNo, DIO_High);
}

void Buzzer_Off(uint8_t GroupName, uint8_t PinNo)
{
	DIO_WriteValueForPin(GroupName, PinNo, DIO_Low);
}

void Buzzer_Toggle(uint8_t GroupName, uint8_t PinNo)
{
	void DIO_ToggleValueForPin(uint8_t GroupName, uint8_t PinNo);
}


#endif /* HAL_BUZZER_BUZZER_PROGRAM_C_ */
