/**
 ****************************************************************************************
 *   @file          : Switch_private.h
 *   @author        : Ahmed Ali
 *   @brief         : Switch private Header File.
 *	 @date			: 1 / 7 / 2023
 ****************************************************************************************
*/

#ifndef HAL_SWITCH_SWITCH_PRIVATE_H_
#define HAL_SWITCH_SWITCH_PRIVATE_H_

/***********************	Includes Section Start	***********************/
#include "../../LIB/STD_TYPES.h"
/***********************	Includes Section End	***********************/

/***********************	Definitions Section Start	***********************/
typedef struct
{
	u8 SW_u8PortID;
	u8 SW_u8PinID;
	u8 SW_u8Status;
}SW_t;
/***********************	Definitions Section End		***********************/

#endif /* HAL_SWITCH_SWITCH_PRIVATE_H_ */
