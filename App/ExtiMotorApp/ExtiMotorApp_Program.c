/*
 * ExitMotorApp_Program.c
 *
 *  Created on: Sep 27, 2026
 *      Author: mahmo
 */
#include "ExtiMotorApp_Interface.h"

static DC_Config_t Motor;
static uint8_t MotorState = ExtiMotorApp_MotorOff;
static volatile uint8_t ButtonPressedFlag = 0;

static void ExtiMotorApp_ButtonISR(void)
{
	ButtonPressedFlag = 1;
}

void ExtiMotorApp_Init()
{
	Motor.ControlType    = ExtiMotorApp_ControlType;
	Motor.ConnectionType = ExtiMotorApp_ConnectionType;
	Motor.DC_M1Group = ExtiMotorApp_MotorGroup;
	Motor.DC_M1Pin   = ExtiMotorApp_MotorPin;

	DC_Init(&Motor);
	DC_Off(&Motor);

	Btn_Init(ExtiMotorApp_BtnGroup, ExtiMotorApp_BtnPin, Btn_InternalPullUp);

	EXTI0_Init(Exti_Falling);
	EXTI0_CallBackFunction(ExtiMotorApp_ButtonISR);
	EXTI0_Enable();

	GIE_Enable();
}

void ExtiMotorApp_Run()
{
	if (ButtonPressedFlag == 1)
	{
		ButtonPressedFlag = 0;
		_delay_ms(ExtiMotorApp_DebounceMs);

		if (MotorState == ExtiMotorApp_MotorOff)
		{
			DC_On(&Motor);
			MotorState = ExtiMotorApp_MotorOn;
		}
		else
		{
			DC_Off(&Motor);
			MotorState = ExtiMotorApp_MotorOff;
		}
	}
}
