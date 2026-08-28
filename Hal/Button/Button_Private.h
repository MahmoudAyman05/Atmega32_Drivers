/*
 * Button_Private.h
 *
 *  Created on: Aug 22, 2026
 *      Author: mahmo
 */

#ifndef HAL_BUTTON_BUTTON_PRIVATE_H_
#define HAL_BUTTON_BUTTON_PRIVATE_H_

typedef enum
{
	Btn_InternalPullUp,
	Btn_ExternalPullUp,
	Btn_ExternalPullDown,
}Btn_ConnectionType_t;

typedef enum
{
	PullUp_Pressed,
	PullUp_NotPressed,
	PullDown_NotPressed=0,
	PullDown_Pressed,
}Btn_PressingState_t;
#endif /* HAL_BUTTON_BUTTON_PRIVATE_H_ */
