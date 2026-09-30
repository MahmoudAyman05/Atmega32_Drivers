/*
 * ADC_Config.h
 *
 *  Created on: Sep 29, 2026
 *      Author: mahmo
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

#define ADC_VrefConfigured       Adc_Vref_AVCC
#define ADC_PrescalerConfigured  Adc_Prescaler_64
#define ADC_AdjustConfigured     Adc_RightAdjust

/* Must match ADC_VrefConfigured: 5000 for AVCC=5V, 2560 for internal */
#define ADC_VrefMillivolts       5000UL

/* Polling loop iterations before ADC_GetDigitalValue gives up and
 * returns Adc_ErrorTimeout, instead of hanging forever if the ADC
 * hardware never sets ADIF */
#define ADC_TimeoutConfigured    50000UL


#endif /* MCAL_ADC_ADC_CONFIG_H_ */
