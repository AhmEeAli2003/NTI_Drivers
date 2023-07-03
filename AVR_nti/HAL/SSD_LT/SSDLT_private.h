/*
 * SSD_private.h
 *
 *  Created on: ٠٢‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef HAL_SSD_SSD_PRIVATE_H_
#define HAL_SSD_SSD_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

#define COMMON_ANODE 		0
#define COMMON_CATHODE 		1
#define NOT_CONNECTED       2

static u8 SSDLT_Au8ComCathodeNumDisplay[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66,
									 0x6D, 0x7D, 0x07, 0x7F, 0x6F
									 };
typedef struct
{
	u8 SEG_u8APort;
	u8 SEG_u8APin;

	u8 SEG_u8BPort;
	u8 SEG_u8BPin;

	u8 SEG_u8CPort;
	u8 SEG_u8CPin;

	u8 SEG_u8DPort;
	u8 SEG_u8DPin;

	u8 SEG_u8EPort;
	u8 SEG_u8EPin;

	u8 SEG_u8FPort;
	u8 SEG_u8FPin;

	u8 SEG_u8GPort;
	u8 SEG_u8GPin;

	u8 SEG_u8CMN_Port;
	u8 SEG_u8CMN_Pin;

	u8 SEG_u8DOT_Port;
	u8 SEG_u8DOT_Pin;

	u8 SEG_u8Type;

}SEG_t;


#endif /* HAL_SSD_SSD_PRIVATE_H_ */
