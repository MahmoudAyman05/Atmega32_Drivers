/*
 * LCDNameApp_Interface.h
 *
 *  Created on: Sep 11, 2026
 *      Author: mahmo
 */


#ifndef APP_LCDNAMEAPP_LCDNAMEAPP_INTERFACE_H_
#define APP_LCDNAMEAPP_LCDNAMEAPP_INTERFACE_H_

#include "../../Hal/LCD/LCD_Interface.h"
#include <util/delay.h>

#include "LcdNameApp_Private.h"
#include "LcdNameApp_Config.h"

void LcdNameApp_Init();
void LcdNameApp_DisplayNameSinusoidal();
void LcdNameApp_DisplayFirstCharBothCases();
void DisplaySpecialCharecter(uint8_t LocationNo);

#endif /* APP_LCDNAMEAPP_LCDNAMEAPP_INTERFACE_H_ */
