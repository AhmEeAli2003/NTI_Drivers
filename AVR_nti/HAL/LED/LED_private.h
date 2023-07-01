/*
 * LED_private.h
 *
 *  Created on: ٠١‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef HAL_LED_LED_PRIVATE_H_
#define HAL_LED_LED_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

typedef struct
{
	u8 LED_u8PortID;
	u8 LED_u8PinID;
	u8 LED_u8Connection;
	u8 LED_u8InitState;
}LED_t;

/**
 * Any Numbers for only distinction.
 * not preferred Zero because in config.c if user not initialize
 * any member in array of struct will be Zero by default.
 * This may cause Confusion.
 * */
#define LED_u8SINK    8
#define LED_u8SOURCE  9

#define LED_u8ON      10
#define LED_u8OFF     11
#endif /* HAL_LED_LED_PRIVATE_H_ */
