/*
 * Button_Program.h
 *
 *  Created on: Aug 22, 2026
 *      Author: mahmo
 */

#ifndef HAL_BUTTON_BUTTON_PROGRAM_C_
#define HAL_BUTTON_BUTTON_PROGRAM_C_

#include "Button_Interface.h"

void Btn_Init(uint8_t GroupName, uint8_t PinNo,uint8_t BtnConnection)
{
	DIO_DirectionSetForPin(GroupName, PinNo, DIO_Input);
	if(BtnConnection==Btn_InternalPullUp)
	{
		DIO_InternalPullUpControlForPin(GroupName, PinNo, DIO_High);
	}
	else
	{
		DIO_InternalPullUpControlForPin(GroupName, PinNo, DIO_Low);
	}
}


uint8_t Btn_IsPressed(uint8_t GroupName, uint8_t PinNo,uint8_t BtnConnection)
{
	uint8_t State;
    State = DIO_ReadStateInputForPin(GroupName,PinNo);
	return State;
}

#endif /* HAL_BUTTON_BUTTON_PROGRAM_C_ */
