/*
 * PasswordSystem_Interface.h
 *
 *  Created on: Sep 15, 2026
 *      Author: mahmo
 */

#ifndef APP_PASSWORDSYSTEM_PASSWORDSYSTEM_INTERFACE_H_
#define APP_PASSWORDSYSTEM_PASSWORDSYSTEM_INTERFACE_H_

#include "../../Hal/LCD/LCD_Interface.h"
#include "../../Hal/KPD/KPD_Interface.h"
#include "../../Hal/LED/Led_Interface.h"
#include "../../Hal/Buzzer/Buzzer_Interface.h"
#include <util/delay.h>

#include "PasswordSystem_Private.h"
#include "PasswordSystem_Config.h"

void PasswordSystem_Init();
void PasswordSystem_Run();



#endif /* APP_PASSWORDSYSTEM_PASSWORDSYSTEM_INTERFACE_H_ */
