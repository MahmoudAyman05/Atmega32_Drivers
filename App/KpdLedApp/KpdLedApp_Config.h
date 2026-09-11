/*
 * KPDLedApp_Config.h
 *
 *  Created on: Sep 11, 2026
 *      Author: mahmo
 */

#ifndef APP_KPDLEDAPP_KPDLEDAPP_CONFIG_H_
#define APP_KPDLEDAPP_KPDLEDAPP_CONFIG_H_

#define Led_ConnectionTypeConfigured   Led_SourceConnection

/* All 8 LEDs sit on the same port, so one group is enough. */
#define KpdLedApp_LedGroupConfigured   DIO_GroupD

#define KpdLedApp_LedPinsConfigured    {DIO_Pin0,DIO_Pin1,DIO_Pin2,DIO_Pin3,\
                                         DIO_Pin4,DIO_Pin5,DIO_Pin6,DIO_Pin7}

#endif /* APP_KPDLEDAPP_KPDLEDAPP_CONFIG_H_ */
