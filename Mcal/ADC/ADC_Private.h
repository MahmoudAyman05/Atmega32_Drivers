/*
 * ADC_Private.h
 *
 *  Created on: Sep 29, 2026
 *      Author: mahmo
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

/**< @brief BitName */
typedef enum
{
	/*ADMUX*/
	MUX0,
	MUX1,
	MUX2,
	MUX3,
	MUX4,
	ADLAR,
	REFS0,
	REFS1,
	/*ADCSRA*/
	ADPS0=0,
	ADPS1,
	ADPS2,
	ADIE,
	ADIF,
	ADATE,
	ADSC,
	ADEN,
}Adc_BitName_t;

/**< @brief Voltage reference selection -- REFS1:REFS0 in ADMUX */
typedef enum
{
	Adc_Vref_AREF     = 0, /**< AREF pin, internal Vref off */
	Adc_Vref_AVCC     = 1, /**< AVCC with external cap at AREF pin */
	Adc_Vref_Internal = 3, /**< Internal 2.56V reference */
}Adc_Vref_t;

/**< @brief Prescaler selection -- ADPS2:0 in ADCSRA (division factor) */
typedef enum
{
	Adc_Prescaler_2   = 1,
	Adc_Prescaler_4   = 2,
	Adc_Prescaler_8   = 3,
	Adc_Prescaler_16  = 4,
	Adc_Prescaler_32  = 5,
	Adc_Prescaler_64  = 6,
	Adc_Prescaler_128 = 7,
}Adc_Prescaler_t;

/**< @brief Result adjustment -- ADLAR in ADMUX */
typedef enum
{
	Adc_RightAdjust, /**< 10-bit result across ADCL + low 2 bits of ADCH */
	Adc_LeftAdjust,  /**< 8-bit result readable from ADCH alone */
}Adc_Adjust_t;

/**< @brief ADC input channel, 0-7 */
typedef enum
{
	Adc_Channel0,
	Adc_Channel1,
	Adc_Channel2,
	Adc_Channel3,
	Adc_Channel4,
	Adc_Channel5,
	Adc_Channel6,
	Adc_Channel7,
}Adc_Channel_t;

/**< @brief Return status for every public function */
typedef enum
{
	Adc_Ok,
	Adc_ErrorNullPointer,
	Adc_ErrorInvalidChannel,
	Adc_ErrorTimeout,
	Adc_ErrorBusy,
}Adc_Status_t;

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
