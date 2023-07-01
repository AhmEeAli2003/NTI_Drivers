/*
 * LED_int.h
 *
 *  Created on: ٠١‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"
#include "LED_private.h"

ES_t LED_enuInit(LED_t * Copy_pstrLedConfiguration);

ES_t LED_enuTurnON(LED_t * Copy_pstrLedID);

ES_t LED_enuTurnOFF(LED_t * Copy_pstrLedID);

#endif /* HAL_LED_LED_INT_H_ */
