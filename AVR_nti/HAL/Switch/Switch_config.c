/*
 * Switch_config.c
 *
 *  Created on: ٠١‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#include "Switch_private.h"
#include "Switch_config.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../LIB/STD_TYPES.h"

 //A -> Array, str -> struct
SW_t Switch_AstrSwitchState[SW_NUM] =
	{
			{DIO_u8PORTA, DIO_u8PIN4, DIO_u8FLOAT},
			{DIO_u8PORTB, DIO_u8PIN4, DIO_u8PULL_UP},
			{DIO_u8PORTC, DIO_u8PIN4, DIO_u8PULL_UP}
	};


