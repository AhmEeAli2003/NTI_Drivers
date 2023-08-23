/*
 * GIE_prog.c
 *
 *  Created on: ٢١‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"
#include "GIE_private.h"

ES_t GIE_enuEnable(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	SREG |= (1<<7);

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t GIE_enuDisable(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	SREG &= ~(1<<7);

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;

}
