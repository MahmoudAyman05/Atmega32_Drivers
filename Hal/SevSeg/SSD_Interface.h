/*
 * SevSeg_Interface.h
 *
 *  Created on: Aug 22, 2026
 *      Author: mahmo
 */

#ifndef HAL_SEVSEG_SSD_INTERFACE_H_
#define HAL_SEVSEG_SSD_INTERFACE_H_

#include <stdint.h>
#include "../../Mcal/DIO/DIO_Interface.h"
#include"SSD_Config.h"
#include"SSD_Private.h"

void SSD_Init(uint8_t GroupName);
void SSD_DisplayNumber1Digit(uint8_t GroupName,uint8_t Number,uint8_t SSDType);

#endif /* HAL_SEVSEG_SSD_INTERFACE_H_ */
