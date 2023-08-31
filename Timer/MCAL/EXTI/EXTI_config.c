/*
 * EXTI_config.c
 *
 *  Created on: ٢٨‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"

#include "EXTI_private.h"
#include "EXTI_config.h"

EXTI_t EXTI_AstrEXTIConfig[3] =
{
		{ACTIVE, FALLING_EDGE}, //INT0
		{DEACTIVE}, //INT1
		{DEACTIVE}  //INT2
};
