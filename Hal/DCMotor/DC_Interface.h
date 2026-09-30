/*
 * DC_Interface.h
 *
 *  Created on: Sep 27, 2026
 *      Author: mahmo
 */

#ifndef HAL_DCMOTOR_DC_INTERFACE_H_
#define HAL_DCMOTOR_DC_INTERFACE_H_
#include  "../../Common/BitMath.h"
#include  "../../Common/Definition.h"
#include  "../../Common/StdTypes.h"

#include "../../Mcal/DIO/DIO_Interface.h"
#include "DC_Private.h"
#include "DC_Config.h"

/**
 *
 * @param MyConfig
 */
void DC_Init(DC_Config_t * MyConfig);
void DC_Off(DC_Config_t *MyConfig);

/*API Control On/Off Only */
/**
 * @fn      DC_On
 * @brief
 * @param 	MyConfig
 */
void DC_On(DC_Config_t *MyConfig);


/*API Control Direction and Off */
/**
 *
 * @param MyConfig
 */
void DC_OnCW(DC_Config_t *MyConfig);
void DC_OnCCW(DC_Config_t *MyConfig);


#endif /* HAL_DCMOTOR_DC_INTERFACE_H_ */
