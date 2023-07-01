/*
 * main.c
 *
 *  Created on: ٢٦‏/٠٦‏/٢٠٢٣
 *      Author: Ahmed
 */

#include "../HAL/Switch/Switch_int.h"
#include "../HAL/Switch/Switch_config.h"
#include "../MCAL/DIO/DIO_int.h"


extern SW_t Switch_AstrSwitchState[SW_NUM];

int main(void)
{
	DIO_enuInit();
	Switch_enuInit(Switch_AstrSwitchState);
	u8 Local_u8pinState = 0;

	while(1)
	{
		Switch_enuGetState(&Switch_AstrSwitchState[1], &Local_u8pinState);

		if(Local_u8pinState == 0)
		{
			DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8HIGH);
		}
		else
		{
			DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8LOW);
		}
	}
	return 0;
}
