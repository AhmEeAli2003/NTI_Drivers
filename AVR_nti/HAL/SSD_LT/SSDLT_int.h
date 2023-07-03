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
#include "SSDLT_private.h"

ES_t SSDLT_enuInit(SEG_t * Copy_pstrSegConfig);

ES_t SSDLT_enuDisplayNum(u8 Copy_u8SegID, u8 Copy_u8Number);

ES_t SSDLT_enuEnableCommon(u8 Copy_u8SegID);

ES_t SSDLT_enuDisableCommon(u8 Copy_u8SegID);

ES_t SSDLT_enuEnableDot(u8 Copy_u8SegID);

ES_t SSDLT_enuDisableDot(u8 Copy_u8SegID);

ES_t SSDLT_enuClearDisplay(u8 Copy_u8SegID);

#endif /* HAL_SSD_SSD_INT_H_ */
