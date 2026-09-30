/*
 * GIE_Program.c
 *
 *  Created on: Sep 27, 2026
 *      Author: mahmo
 */
#include "GIE_Interface.h"
/**
 * @fn
 * @brief
 */
void GIE_Enable()
{
	/*SREG Bit No 7 write Logic One */
	SetBit(SREG_Reg, 7);
}
/**
 * @fn
 * @brief
 */
void GIE_Disable()
{
	ClearBit(SREG_Reg,7);

}

