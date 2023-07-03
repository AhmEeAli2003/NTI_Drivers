/*
 * SSD_int.h
 *
 *  Created on: ٠٢‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"

ES_t SSD_enuInit(void);

ES_t SSD_enuDisplayNum(u8 Copy_u8Number);

ES_t SSD_enuEnableCommon(void);

ES_t SSD_enuDisableCommon(void);

ES_t SSD_enuEnableDot(void);

ES_t SSD_enuDisableDot(void);

ES_t SSD_enuClearDisplay(void);

#endif /* HAL_SSD_SSD_INT_H_ */
