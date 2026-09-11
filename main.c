/*
 * main.c
 *
 *  Created on: Aug 28, 2026
 *      Author: mahmo
 */

#include "App/LcdNameApp/LcdNameApp_Interface.h"
#include "App/KpdLedApp/KpdLedApp_Interface.h"

void main()
{
	//LcdNameApp_Init();
	KpdLedApp_Init();
    //LcdNameApp_DisplayFirstCharBothCases();  //(1.2)
	while(1)
	{
		//LcdNameApp_DisplayNameSinusoidal(); //(1.1)
		KpdLedApp_Run();                       //(2)
	}
}
/*use(1.1) or (1.2) alone not together in the same build in lcd assignment*/
