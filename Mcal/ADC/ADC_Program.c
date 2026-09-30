/*
 * ADC_Program.c
 *
 *  Created on: Sep 29, 2026
 *      Author: mahmo
 */

#include "ADC_Interface.h"

static void (*Adc_CallBack)(uint16_t) = Null;
static volatile uint8_t Adc_Busy = 0;

/**< @brief Read ADCL before ADCH -- the datasheet requires this order,
 * since reading ADCL locks the result registers until ADCH is read
 * too, guaranteeing an atomic 10-bit read. */
static uint16_t Adc_ReadResult(void)
{
	uint16_t Result;

	if (ADC_AdjustConfigured == Adc_RightAdjust)
	{
		Result = ADCL_Reg;
		Result |= (uint16_t)ADCH_Reg << 8;
	}
	else
	{
		(void)ADCL_Reg;
		Result = ADCH_Reg;
	}
	return Result;
}

void ADC_Init(void)
{
	/**< @brief Select the voltage reference and result adjustment
	 * @details ADMUX -> REFS1, REFS0, ADLAR
	 * Bits 5,6,7 , Mask = 1110 0000 */
	ADMUX_Reg = (ADMUX_Reg & ~0xE0)
	          | (ADC_VrefConfigured << REFS0)
	          | (ADC_AdjustConfigured << ADLAR);

	/**< @brief Select the prescaler (ADC clock divider)
	 * @details ADCSRA -> ADPS2, ADPS1, ADPS0
	 * Bits 0,1,2 , Mask = 0000 0111 */
	ADCSRA_Reg = (ADCSRA_Reg & ~0x07) | (ADC_PrescalerConfigured << ADPS0);

	/**< @brief Enable the ADC
	 * @details ADCSRA -> ADEN -> 1*/
	SetBit(ADCSRA_Reg, ADEN);
}

void ADC_Disable(void)
{
	ClearBit(ADCSRA_Reg, ADEN);
}

Adc_Status_t ADC_GetDigitalValue(Adc_Channel_t ChannelNo, uint16_t *Result)
{
	uint32_t Counter = 0;

	if (Result == Null)              { return Adc_ErrorNullPointer; }
	if (ChannelNo > Adc_Channel7)    { return Adc_ErrorInvalidChannel; }
	if (Adc_Busy == 1)               { return Adc_ErrorBusy; }

	Adc_Busy = 1;

	/**< @brief Select the channel
	 * @details ADMUX -> MUX4:MUX0
	 * Bits 0-4 , Mask = 0001 1111 */
	ADMUX_Reg = (ADMUX_Reg & ~0x1F) | ((uint8_t)ChannelNo & 0x1F);

	SetBit(ADCSRA_Reg, ADIF);  /* clear any stale flag before starting */
	SetBit(ADCSRA_Reg, ADSC);  /* start conversion */

	while (ReadBit(ADCSRA_Reg, ADIF) == 0)
	{
		Counter++;
		if (Counter >= ADC_TimeoutConfigured)
		{
			Adc_Busy = 0;
			return Adc_ErrorTimeout;
		}
	}

	SetBit(ADCSRA_Reg, ADIF);  /* clear the flag (written with logic 1) */
	*Result = Adc_ReadResult();

	Adc_Busy = 0;
	return Adc_Ok;
}

Adc_Status_t ADC_GetDigitalVolt(Adc_Channel_t ChannelNo, uint16_t *Millivolts)
{
	uint16_t Digital = 0;
	Adc_Status_t Status;

	if (Millivolts == Null) { return Adc_ErrorNullPointer; }

	Status = ADC_GetDigitalValue(ChannelNo, &Digital);
	if (Status != Adc_Ok) { return Status; }

	if (ADC_AdjustConfigured == Adc_RightAdjust)
	{
		*Millivolts = (uint16_t)(((uint32_t)Digital * ADC_VrefMillivolts) / 1024UL);
	}
	else
	{
		*Millivolts = (uint16_t)(((uint32_t)Digital * ADC_VrefMillivolts) / 256UL);
	}
	return Adc_Ok;
}

Adc_Status_t ADC_StartConversionAsync(Adc_Channel_t ChannelNo, void (*CallBack)(uint16_t))
{
	if (CallBack == Null)         { return Adc_ErrorNullPointer; }
	if (ChannelNo > Adc_Channel7) { return Adc_ErrorInvalidChannel; }
	if (Adc_Busy == 1)            { return Adc_ErrorBusy; }

	Adc_Busy = 1;
	Adc_CallBack = CallBack;

	ADMUX_Reg = (ADMUX_Reg & ~0x1F) | ((uint8_t)ChannelNo & 0x1F);

	SetBit(ADCSRA_Reg, ADIF);  /* clear any stale flag */
	SetBit(ADCSRA_Reg, ADIE);  /* enable the ADC interrupt */
	SetBit(ADCSRA_Reg, ADSC);  /* start conversion */

	return Adc_Ok;
}

/**< @brief ADC Conversion Complete interrupt -- vector 16 on the
 * ATmega32 (verified against avr-libc's iom32.h: ATmega32 has an
 * extra TIMER0_COMP vector at position 10 that isn't present on
 * every AVR, which shifts ADC from 15 to 16). */
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	uint16_t Result = Adc_ReadResult();

	ClearBit(ADCSRA_Reg, ADIE);  /* one-shot until the next request */
	Adc_Busy = 0;

	if (Adc_CallBack != Null)
	{
		Adc_CallBack(Result);
	}
}
