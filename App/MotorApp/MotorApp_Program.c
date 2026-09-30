/*
 * MotorApp_Program.c
 *
 *  Created on: Sep 27, 2026
 *      Author: mahmo
 */
#include "MotorApp_Interface.h"

static DC_Config_t Motor;

void MotorApp_Init()
{
	Motor.ControlType = MotorApp_ControlType;
	Motor.ConnectionType = MotorApp_ConnectionType;
	Motor.DC_M1Group = MotorApp_M1Group;
	Motor.DC_M1Pin   = MotorApp_M1Pin;
	Motor.DC_M2Group = MotorApp_M2Group;
	Motor.DC_M2Pin   = MotorApp_M2Pin;

	DC_Init(&Motor);
	DC_Off(&Motor);
}

void MotorApp_Run()
{
	DC_OnCW(&Motor);
	_delay_ms(MotorApp_RunTimeMs);

	DC_Off(&Motor);
	_delay_ms(MotorApp_StopTimeMs);

	DC_OnCCW(&Motor);
	_delay_ms(MotorApp_RunTimeMs);

	DC_Off(&Motor);
	_delay_ms(MotorApp_StopTimeMs);
}
