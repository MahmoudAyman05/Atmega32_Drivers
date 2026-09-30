/*
 * MotorApp_Interface.h
 *
 *  Created on: Sep 27, 2026
 *      Author: mahmo
 */

#ifndef APP_MOTORAPP_MOTORAPP_INTERFACE_H_
#define APP_MOTORAPP_MOTORAPP_INTERFACE_H_

#include "../../Hal/DCMotor/DC_Interface.h"
#include <util/delay.h>

#include "MotorApp_Private.h"
#include "MotorApp_Config.h"

void MotorApp_Init();
void MotorApp_Run();

#endif /* APP_MOTORAPP_MOTORAPP_INTERFACE_H_ */
