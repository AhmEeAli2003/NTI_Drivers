/*
 * main.c
 *
 *  Created on: ٢٩‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/ERROR_STATE.h"

#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/TIM/TIM_int.h"

int main(void)
{
	DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8OUTPUT);

	TIM_enuInut();

	GIE_enuEnable();
	while(1)
	{
		DIO_enuTogPinValue(DIO_u8PORTA, DIO_u8PIN0);
		TIM_enuSetSynchDelay(1000);
	}
	return 0;
}
