#include"Mcal/DIO/DIO_Interface.h"
#include"Hal/LED/Led_Interface.h"
#include"Hal/Buzzer/Buzzer_Interface.h"
#include"Hal/Button/Button_Interface.h"

void main()
{
	uint8_t BtnState = PullDown_NotPressed;

	Led_Init(DIO_GroupA, DIO_Pin0);
	Btn_Init(DIO_GroupB, DIO_Pin0, Btn_ExternalPullDown);
	Buzzer_Init(DIO_GroupC, DIO_Pin0);

	while(1)
	{
		BtnState = Btn_IsPressed(DIO_GroupB, DIO_Pin0,Btn_ExternalPullDown);
		if(BtnState == PullDown_Pressed)
		{
			Led_On(DIO_GroupA, DIO_Pin0,Led_SourceConnection);
			Buzzer_On(DIO_GroupC, DIO_Pin0);
		}
		else
		{
			Led_Off(DIO_GroupA, DIO_Pin0,Led_SourceConnection);
			Buzzer_Off(DIO_GroupC, DIO_Pin0);
		}
	}
}
