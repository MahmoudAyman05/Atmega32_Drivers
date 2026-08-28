/*
 * Buzzer_Interface.h
 *
 *  Created on: Aug 22, 2026
 *      Author: mahmo
 */

#ifndef HAL_BUZZER_BUZZER_INTERFACE_H_
#define HAL_BUZZER_BUZZER_INTERFACE_H_


#include <stdint.h>
#include "../../Mcal/DIO/DIO_Interface.h"
#include "Buzzer_Private.h"
#include "Buzzer_Config.h"

// API To Initialize the Buzzer Pin as Output
void Buzzer_Init(uint8_t GroupName, uint8_t PinNo);
// API To Turn the Buzzer On
void Buzzer_On(uint8_t GroupName, uint8_t PinNo);
// API To Turn the Buzzer Off
void Buzzer_Off(uint8_t GroupName, uint8_t PinNo);
// API To Pulse the Buzzer On/Off RepeatCount times
void Buzzer_Toggle(uint8_t GroupName, uint8_t PinNo);

#endif /* HAL_BUZZER_BUZZER_INTERFACE_H_ */
