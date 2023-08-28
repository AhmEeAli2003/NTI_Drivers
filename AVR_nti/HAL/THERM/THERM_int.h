/*
 * THERMO_int.h
 *
 *  Created on: ٢٣‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef HAL_THERM_THERM_INT_H_
#define HAL_THERM_THERM_INT_H_

#include "THERM_private.h"

ES_t THERM_enuInit(THERM_t * Copy_pAstrThermistorConfig);

ES_t THERM_enuGetTemp(u8 Copy_u8ID, f32 * Copy_pf32Temp);

#endif /* HAL_THERM_THERM_INT_H_ */
