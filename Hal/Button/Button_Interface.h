/*
 * Button_Interface.h
 *
 *  Created on: Aug 22, 2026
 *      Author: mahmo
 */

#ifndef HAL_BUTTON_BUTTON_INTERFACE_H_
#define HAL_BUTTON_BUTTON_INTERFACE_H_

#include <stdint.h>
#include"../../Common/BitMath.h"
#include"../../Common/Definition.h"
#include "../../Mcal/DIO/DIO_Interface.h"
#include"Button_Config.h"
#include"Button_Private.h"


// API To Initialize the Button Pin as Input with Internal PullUp
void Btn_Init(uint8_t GroupName, uint8_t PinNo,uint8_t BtnConnection);
// API To Get the Current State of the Button
uint8_t Btn_IsPressed(uint8_t GroupName, uint8_t PinNo, uint8_t BtnConnection);


#endif /* HAL_BUTTON_BUTTON_INTERFACE_H_ */
