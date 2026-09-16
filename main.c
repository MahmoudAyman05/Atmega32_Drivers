/*
 * main.c
 *
 *  Created on: Aug 28, 2026
 *      Author: mahmo
 */

#include "App/LcdNameApp/LcdNameApp_Interface.h"

void main()
{
	PasswordSystem_Init();
	while(1)
	{
		PasswordSystem_Run();
	}
}

