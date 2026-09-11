/*
 * SevSeg_Program.h
 *
 *  Created on: Aug 22, 2026
 *      Author: mahmo
 */

#ifndef HAL_SEVSEG_SEVSEG_PROGRAM_C_
#define HAL_SEVSEG_SEVSEG_PROGRAM_C_

#include "SSD_Interface.h"

static uint8_t SSDNumber[SSD_A_MaxSize]=
{
	    SSD_A_Zero,
		SSD_A_One,
		SSD_A_Two,
		SSD_A_Three,
		SSD_A_Four,
		SSD_A_Five,
		SSD_A_Six,
		SSD_A_Seven,
		SSD_A_Eight,
		SSD_A_Nine,
};
void SSD_Init(uint8_t GroupName)
{
	DIO_DirectionSetForGroup(GroupName, SSDOutput);
}
void SSD_DisplayNumber1Digit(uint8_t GroupName,uint8_t Number,uint8_t SSDType)
{
	if(SSDType == SSD_Anode)
	{
		DIO_WriteValueForGroup(GroupName, SSDNumber[Number]);
	}
	else if(SSDType == SSD_Cathode)
	{
		DIO_WriteValueForGroup(GroupName, ~SSDNumber[Number]);
	}
}

#endif /* HAL_SEVSEG_SEVSEG_PROGRAM_C_ */
