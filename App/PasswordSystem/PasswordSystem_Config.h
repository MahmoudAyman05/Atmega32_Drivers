/*
 * PasswordSystem_Config.h
 *
 *  Created on: Sep 15, 2026
 *      Author: mahmo
 */

#ifndef APP_PASSWORDSYSTEM_PASSWORDSYSTEM_CONFIG_H_
#define APP_PASSWORDSYSTEM_PASSWORDSYSTEM_CONFIG_H_

#define Password            "1234"
#define PasswordLength      4
#define MaxAttempts         3

#define ResetKey            'C'

#define LoadingDelayMs      2000

#define GreenLedGroup   DIO_GroupD
#define GreenLedPin     DIO_Pin0

#define RedLedGroup     DIO_GroupD
#define RedLedPin       DIO_Pin1

#define LedConnectionType  Led_SourceConnection

#define BuzzerGroup        DIO_GroupD
#define BuzzerPin         DIO_Pin2

#define BuzzerToneAHalfPeriodMs      2
#define BuzzerToneBHalfPeriodMs      4
#define BuzzerToneDurationMs         300

#endif /* APP_PASSWORDSYSTEM_PASSWORDSYSTEM_CONFIG_H_ */
