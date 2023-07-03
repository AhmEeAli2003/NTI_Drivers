/*
 * SSD_config.c
 *
 *  Created on: ٠٣‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "SSDLT_private.h"
#include "SSDLT_config.h"

SEG_t SSD_AstrSegConfig[SEG_NUM] =
{
		{
				DIO_u8PORTA, DIO_u8PIN0, //pin a
				DIO_u8PORTA, DIO_u8PIN1, //pin b
				DIO_u8PORTA, DIO_u8PIN2, //pin c
				DIO_u8PORTB, DIO_u8PIN0, //pin d
				DIO_u8PORTB, DIO_u8PIN1, //pin e
				DIO_u8PORTB, DIO_u8PIN2, //pin f
				DIO_u8PORTB, DIO_u8PIN3, //pin g
				DIO_u8PORTB, DIO_u8PIN4, // Common
				NOT_CONNECTED, NOT_CONNECTED, //DOT
				COMMON_CATHODE //Type
		},

		{
				DIO_u8PORTC, DIO_u8PIN0, //pin a
				DIO_u8PORTC, DIO_u8PIN1, //pin b
				DIO_u8PORTC, DIO_u8PIN2, //pin c
				DIO_u8PORTC, DIO_u8PIN3, //pin d
				DIO_u8PORTC, DIO_u8PIN4, //pin e
				DIO_u8PORTD, DIO_u8PIN0, //pin f
				DIO_u8PORTD, DIO_u8PIN1, //pin g
				DIO_u8PORTD, DIO_u8PIN3, // Common
				DIO_u8PORTD, DIO_u8PIN2, //DOT
				COMMON_ANODE //Type
		}

};

