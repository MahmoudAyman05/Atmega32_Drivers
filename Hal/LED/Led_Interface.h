/*
 * Led_Interface.h
 *
 *  Created on: Aug 22, 2026
 *      Author: mahmo
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#include <stdint.h>
#include"../../Mcal/DIO/DIO_Interface.h"
#include"LED_Config.h"
#include"LED_Private.h"

// API To Initialize the Led Pin as Output
void Led_Init(uint8_t GroupName, uint8_t PinNo);
// API To Turn the Led On
void Led_On(uint8_t GroupName, uint8_t PinNo,uint8_t ConnectionType);
// API To Turn the Led Off
void Led_Off(uint8_t GroupName, uint8_t PinNo,uint8_t ConnectionType);
// API To Toggle the Led
void Led_Toggle(uint8_t GroupName, uint8_t PinNo);

#endif /* HAL_LED_LED_INTERFACE_H_ */
