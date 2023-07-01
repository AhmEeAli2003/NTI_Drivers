/*
 * LED_config.c
 *
 *  Created on: ٠١‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */


#include "LED_config.h"
#include "LED_private.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"

LED_t LED_AstrLedConfiguration[LED_NUM]=
{
		{DIO_u8PORTA, DIO_u8PIN0, LED_u8SINK, LED_u8OFF},
		{DIO_u8PORTB, DIO_u8PIN0, LED_u8SOURCE, LED_u8ON},
		{DIO_u8PORTC, DIO_u8PIN0, LED_u8SOURCE, LED_u8OFF}
};
