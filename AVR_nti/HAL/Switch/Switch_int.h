/*
 * Switch_int.h
 *
 *  Created on: ٠١‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef HAL_SWITCH_SWITCH_INT_H_
#define HAL_SWITCH_SWITCH_INT_H_

#include "../../LIB/ERROR_STATE.h"
#include "../../LIB/STD_TYPES.h"
#include "Switch_private.h"

ES_t Switch_enuInit(SW_t * Copy_pAstrSwitches); //pointer to an array of struct

ES_t Switch_enuGetState(SW_t * Copy_pstrSwitches, u8 * Copy_pu8SwState);


#endif /* HAL_SWITCH_SWITCH_INT_H_ */
