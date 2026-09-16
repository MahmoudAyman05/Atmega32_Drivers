/*
 * PasswordSystem_Program.c
 *
 *  Created on: Sep 15, 2026
 *      Author: mahmo
 */

#include "PasswordSystem_Interface.h"

static uint8_t CheckResetPressed(void)
{
	uint8_t KeyValue = Kpd_BtnValueNotPressed;
	KPD_GetKPDValue(&KeyValue);
	return (KeyValue == ResetKey);
}

static uint8_t PlayBuzzerTone(uint8_t HalfPeriodMs, uint16_t DurationMs)
{
	uint16_t Elapsed = 0;

	while (Elapsed < DurationMs)
	{
		if (CheckResetPressed())
		{
			return 1;
		}
		Buzzer_Toggle(BuzzerGroup, BuzzerPin);
		_delay_ms(HalfPeriodMs);
		Elapsed += HalfPeriodMs;
	}

	return 0;
}

static void RunLockedAlarm(void)
{
	while (1)
	{
		if (PlayBuzzerTone(BuzzerToneAHalfPeriodMs, BuzzerToneDurationMs))
		{
			return;
		}
		if (PlayBuzzerTone(BuzzerToneBHalfPeriodMs, BuzzerToneDurationMs))
		{
			return;
		}
	}
}

static uint8_t PasswordMatches(uint8_t *Entered)
{
	uint8_t Reference[] = Password;
	uint8_t i;

	for (i = 0; i < PasswordLength; i++)
	{
		if (Entered[i] != Reference[i])
		{
			return 0;
		}
	}
	return 1;
}

static uint8_t ReadPassword(uint8_t *Password_Entered, uint8_t TriesLeft)
{
	uint8_t EnteredDigits = 0;
	uint8_t KeyValue;
	uint8_t LabelText[] = "Password:";
	uint8_t LabelLength = sizeof(LabelText) - 1;

	LCD_SendInstruction(Lcd_ClearDisplay);
	_delay_ms(2);
	LCD_MoveTo(Lcd_Line1, 0);
	LCD_WriteString(LabelText);

	LCD_MoveTo(Lcd_Line2, 0);
	LCD_WriteNumber(TriesLeft);
	LCD_WriteString(" Tries Left");

	LCD_MoveTo(Lcd_Line1, LabelLength);

	while (EnteredDigits < PasswordLength)
	{
		KeyValue = Kpd_BtnValueNotPressed;
		KPD_GetKPDValue(&KeyValue);

		if (KeyValue == ResetKey)
		{
			return ResetRequested;
		}
		else if (KeyValue >= '0' && KeyValue <= '9')
		{
			Password_Entered[EnteredDigits] = KeyValue;
			LCD_MoveTo(Lcd_Line1, LabelLength + EnteredDigits);
			LCD_WriteCharacter('*');
			EnteredDigits++;
		}
	}

	return PasswordEntered;
}

void PasswordSystem_Init(void)
{
	LCD_Init();
	KPD_Init();

	Led_Init(GreenLedGroup, GreenLedPin);
	Led_Init(RedLedGroup, RedLedPin);
	Buzzer_Init(BuzzerGroup, BuzzerPin);

	Led_Off(GreenLedGroup, GreenLedPin, LedConnectionType);
	Led_Off(RedLedGroup, RedLedPin, LedConnectionType);
	Buzzer_Off(BuzzerGroup, BuzzerPin);
}

void PasswordSystem_Run(void)
{
	uint8_t Password_Entered[PasswordLength];
	uint8_t Attempts = 0;
	uint8_t ReadResult;

	LCD_SendInstruction(Lcd_ClearDisplay);
	_delay_ms(2);
	LCD_MoveTo(Lcd_Line1, 0);
	LCD_WriteString("System Loading..");
	_delay_ms(LoadingDelayMs);

	while (Attempts < MaxAttempts)
	{
		ReadResult = ReadPassword(Password_Entered, MaxAttempts - Attempts);

		if (ReadResult == ResetRequested)
		{
			return;
		}

		if (PasswordMatches(Password_Entered))
		{
			LCD_SendInstruction(Lcd_ClearDisplay);
			_delay_ms(2);
			LCD_MoveTo(Lcd_Line1, 0);
			LCD_WriteString("System Open...");
			Led_On(GreenLedGroup, GreenLedPin, LedConnectionType);

			while (!CheckResetPressed());

			Led_Off(GreenLedGroup, GreenLedPin, LedConnectionType);
			return;
		}

		Attempts++;
	}

	LCD_SendInstruction(Lcd_ClearDisplay);
	_delay_ms(2);
	LCD_MoveTo(Lcd_Line1, 0);
	LCD_WriteString("System Locked..");
	Led_On(RedLedGroup, RedLedPin, LedConnectionType);

	RunLockedAlarm();

	Buzzer_Off(BuzzerGroup, BuzzerPin);
	Led_Off(RedLedGroup, RedLedPin, LedConnectionType);
}
