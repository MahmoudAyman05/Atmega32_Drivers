/*
 * KPDLedApp_Program.c
 *
 *  Created on: Sep 11, 2026
 *      Author: mahmo
 */

#include "KpdLedApp_Interface.h"

static uint8_t LedGroup = KpdLedApp_LedGroupConfigured;
static uint8_t LedPins[KpdLedApp_LedCount] = KpdLedApp_LedPinsConfigured;

//led funcs
static void AllLedsOff(void)
{
	for (uint8_t i = 0; i < KpdLedApp_LedCount; i++)
	{
		Led_Off(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
	}
}

static void AllLedsOn(void)
{
	for (uint8_t i = 0; i < KpdLedApp_LedCount; i++)
	{
		Led_On(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
	}
}

//Animations
static void Animation_BlinkAll(void)
{
	for (uint8_t i = 0; i < 5; i++)
	{
		AllLedsOn();
		_delay_ms(200);
		AllLedsOff();
		_delay_ms(200);
	}
}

static void Animation_ChaseRight(void)
{
	for (uint8_t Round = 0; Round < 3; Round++)
	{
		for (uint8_t i = 0; i < KpdLedApp_LedCount; i++)
		{
			Led_On(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
			_delay_ms(100);
			Led_Off(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
		}
	}
}

static void Animation_ChaseLeft(void)
{
	for (uint8_t Round = 0; Round < 3; Round++)
	{
		for (int8_t i = KpdLedApp_LedCount - 1; i >= 0; i--)
		{
			Led_On(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
			_delay_ms(100);
			Led_Off(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
		}
	}
}

static void Animation_PingPong(void)
{
	for (uint8_t Round = 0; Round < 2; Round++)
	{
		for (uint8_t i = 0; i < KpdLedApp_LedCount; i++)
		{
			Led_On(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
			_delay_ms(80);
			Led_Off(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
		}
		for (int8_t i = KpdLedApp_LedCount - 1; i >= 0; i--)
		{
			Led_On(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
			_delay_ms(80);
			Led_Off(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
		}
	}
}

static void Animation_FillUp(void)
{
	for (uint8_t Round = 0; Round < 2; Round++)
	{
		for (uint8_t i = 0; i < KpdLedApp_LedCount; i++)
		{
			Led_On(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
			_delay_ms(120);
		}
		_delay_ms(300);
		AllLedsOff();
		_delay_ms(200);
	}
}

static void Animation_FillDown(void)
{
	for (uint8_t Round = 0; Round < 2; Round++)
	{
		for (uint8_t i = 0; i < KpdLedApp_LedCount; i++)
		{
			Led_On(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
			_delay_ms(80);
		}
		for (int8_t i = KpdLedApp_LedCount - 1; i >= 0; i--)
		{
			Led_Off(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
			_delay_ms(80);
		}
	}
}

static void Animation_AlternateOddEven(void)
{
	for (uint8_t Round = 0; Round < 5; Round++)
	{
		for (uint8_t i = 0; i < KpdLedApp_LedCount; i++)
		{
			if ((i % 2) == 0)
			{
				Led_On(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
			}
			else
			{
				Led_Off(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
			}
		}
		_delay_ms(300);
		for (uint8_t i = 0; i < KpdLedApp_LedCount; i++)
		{
			if ((i % 2) == 0)
			{
				Led_Off(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
			}
			else
			{
				Led_On(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
			}
		}
		_delay_ms(300);
	}
	AllLedsOff();
}

static void Animation_KnightRider(void)
{
	for (uint8_t Round = 0; Round < 3; Round++)
	{
		for (uint8_t i = 0; i < KpdLedApp_LedCount - 1; i++)
		{
			Led_On(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
			Led_On(LedGroup, LedPins[i + 1], Led_ConnectionTypeConfigured);
			_delay_ms(90);
			Led_Off(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
			Led_Off(LedGroup, LedPins[i + 1], Led_ConnectionTypeConfigured);
		}
		for (int8_t i = KpdLedApp_LedCount - 1; i > 0; i--)
		{
			Led_On(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
			Led_On(LedGroup, LedPins[i - 1], Led_ConnectionTypeConfigured);
			_delay_ms(90);
			Led_Off(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
			Led_Off(LedGroup, LedPins[i - 1], Led_ConnectionTypeConfigured);
		}
	}
}

static void Animation_BinaryCounter(void)
{
	for (uint16_t Count = 0; Count < 256; Count++)
	{
		for (uint8_t i = 0; i < KpdLedApp_LedCount; i++)
		{
			if (Count & (1 << i))
			{
				Led_On(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
			}
			else
			{
				Led_Off(LedGroup, LedPins[i], Led_ConnectionTypeConfigured);
			}
		}
		_delay_ms(60);
	}
	AllLedsOff();
}

//run func
void KpdLedApp_Init()
{
	KPD_Init();
	for (uint8_t i = 0; i < KpdLedApp_LedCount; i++)
	{
		Led_Init(LedGroup, LedPins[i]);
	}
	AllLedsOff();
}

void KpdLedApp_Run()
{
	uint8_t KeyValue = Kpd_BtnValueNotPressed;

	KPD_GetKPDValue(&KeyValue);

	if (KeyValue != Kpd_BtnValueNotPressed)
	{
		switch (KeyValue)
		{
			case '1': Animation_BlinkAll();        break;
			case '2': Animation_ChaseRight();       break;
			case '3': Animation_ChaseLeft();        break;
			case '4': Animation_PingPong();         break;
			case '5': Animation_FillUp();           break;
			case '6': Animation_FillDown();         break;
			case '7': Animation_AlternateOddEven(); break;
			case '8': Animation_KnightRider();      break;
			case '9': Animation_BinaryCounter();    break;
			default: break;
		}
		AllLedsOff();
	}
}
