/*
 * KPDLedApp_Interface.h
 *
 *  Created on: Sep 11, 2026
 *      Author: mahmo
 */

#ifndef APP_KPDLEDAPP_KPDLEDAPP_INTERFACE_H_
#define APP_KPDLEDAPP_KPDLEDAPP_INTERFACE_H_

#include "../../Hal/KPD/KPD_Interface.h"
#include "../../Hal/Led/Led_Interface.h"
#include <util/delay.h>

#include "KpdLedApp_Private.h"
#include "KpdLedApp_Config.h"

void KpdLedApp_Init();
void KpdLedApp_Run();   // Super loop

#endif /* APP_KPDLEDAPP_KPDLEDAPP_INTERFACE_H_ */
