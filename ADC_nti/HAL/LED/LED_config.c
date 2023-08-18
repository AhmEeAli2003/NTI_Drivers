/**
 ****************************************************************************************
 *   @file          : LED_config.c
 *   @author        : Ahmed Ali
 *   @brief         : LED Configuration Source File
 *	 @date			: 1 / 7 / 2023
 ****************************************************************************************
*/

/***********************	Includes Section Start	***********************/
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "LED_config.h"
#include "LED_private.h"
/***********************	Includes Section End	***********************/

/***********************	Configuration Section Start	***********************/
LED_t LED_AstrLedConfiguration[LED_NUM]=
{
		{DIO_u8PORTD, DIO_u8PIN0, LED_u8SOURCE, LED_u8OFF},
		{DIO_u8PORTD, DIO_u8PIN1, LED_u8SOURCE, LED_u8OFF}
};
/***********************	Configuration Section End	***********************/
