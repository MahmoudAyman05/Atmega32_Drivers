/*
 * ExitMotorApp_Interface.h
 *
 *  Created on: Sep 27, 2026
 *      Author: mahmo
 */

#ifndef APP_EXTIMOTORAPP_EXTIMOTORAPP_INTERFACE_H_
#define APP_EXTIMOTORAPP_EXTIMOTORAPP_INTERFACE_H_

#include "../../Mcal/EXTI/EXTI_Interface.h"
#include "../../Mcal/GIE/GIE_Interface.h"
#include "../../Hal/DCMotor/DC_Interface.h"
#include "../../Hal/Button/Button_Interface.h"
#include <util/delay.h>

#include "ExtiMotorApp_Private.h"
#include "ExtiMotorApp_Config.h"

void ExtiMotorApp_Init();
void ExtiMotorApp_Run();

#endif /* APP_EXTIMOTORAPP_EXTIMOTORAPP_INTERFACE_H_ */
