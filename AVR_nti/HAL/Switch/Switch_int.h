/**
 ****************************************************************************************
 *   @file          : Switch_int.h
 *   @author        : Ahmed Ali
 *   @brief         : Switch Interface file consists prototypes of Switch APIs.
 *   				  Linking Time Configuration.
 *	 @date			: 1 / 7 / 2023
 ****************************************************************************************
*/

#ifndef HAL_SWITCH_SWITCH_INT_H_
#define HAL_SWITCH_SWITCH_INT_H_

/***********************	Includes Section Start	***********************/
#include "../../LIB/ERROR_STATE.h"
#include "../../LIB/STD_TYPES.h"
#include "Switch_private.h"
/***********************	Includes Section End	***********************/

/***********************	Prototypes Section Start	***********************/
ES_t Switch_enuInit(SW_t * Copy_pAstrSwitches); /*pointer to an array of struct*/

ES_t Switch_enuGetState(SW_t * Copy_pstrSwitches, u8 * Copy_pu8SwState);
/***********************	Prototypes Section End		***********************/

#endif /* HAL_SWITCH_SWITCH_INT_H_ */
