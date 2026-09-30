/*
 * ADC_Interface.h
 *
 *  Created on: Sep 29, 2026
 *      Author: mahmo
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_


#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"
#include "../Atmega32Register.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

void ADC_Init(void);
void ADC_Disable(void);

/**
 * @brief Blocking single-conversion read on one channel
 * @param ChannelNo   Adc_Channel0 .. Adc_Channel7
 * @param Result      out: raw value, 0-1023 (right-adjust) or 0-255 (left-adjust)
 * @return Adc_Ok, Adc_ErrorNullPointer, Adc_ErrorInvalidChannel,
 *         Adc_ErrorBusy, or Adc_ErrorTimeout
 */
Adc_Status_t ADC_GetDigitalValue(Adc_Channel_t ChannelNo, uint16_t *Result);

/**
 * @brief Blocking read, converted to millivolts using ADC_VrefMillivolts
 */
Adc_Status_t ADC_GetDigitalVolt(Adc_Channel_t ChannelNo, uint16_t *Millivolts);

/**
 * @brief Non-blocking: starts a conversion and returns immediately.
 *        CallBack is invoked from the ADC ISR once the result is ready.
 *        Caller must have called GIE_Enable() beforehand.
 */
Adc_Status_t ADC_StartConversionAsync(Adc_Channel_t ChannelNo, void (*CallBack)(uint16_t));

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
