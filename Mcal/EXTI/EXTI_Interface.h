/*
 * EXTI_Interface.h
 *
 *  Created on: Sep 27, 2026
 *      Author: mahmo
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"
#include "../Atmega32Register.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"

/*PostBuild*/
/*EXTI0*/
void EXTI0_Init(uint8_t SensControl);
void EXTI0_Enable();
void EXTI0_CallBackFunction(void (*PF)(void));
void EXTI0_Disable();
/***************************/
/*EXTI1*/
void EXTI1_Init(uint8_t SensControl);
void EXTI1_Enable();
void EXTI1_CallBackFunction(void (*PF)(void));
void EXTI1_Disable();
/***************************/
/*EXTI2*/
void EXTI2_Init(uint8_t SensControl);
void EXTI2_Enable();
void EXTI2_CallBackFunction(void (*PF)(void));
void EXTI2_Disable();
/***************************/


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
