/*
 * Switch_private.h
 *
 *  Created on: ٠١‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef HAL_SWITCH_SWITCH_PRIVATE_H_
#define HAL_SWITCH_SWITCH_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

typedef struct
{
	u8 SW_u8PortID;
	u8 SW_u8PinID;
	u8 SW_u8Status;
}SW_t;

#endif /* HAL_SWITCH_SWITCH_PRIVATE_H_ */
