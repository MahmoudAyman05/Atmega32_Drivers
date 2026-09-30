/*
 * main.c
 *
 *  Created on: Aug 28, 2026
 *      Author: mahmo
 */

#include "App/ADC_Test/ADC_Test.h"

void main()
{
	ADCTest_Init();
	while (1)
	{
		ADCTest_Runner();
	}
}


