/*
 * THERMO_private.h
 *
 *  Created on: ٢٣‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef HAL_THERM_THERM_PRIVATE_H_
#define HAL_THERM_THERM_PRIVATE_H_
#include "../../LIB/STD_TYPES.h"

typedef struct
{
	u8 THERM_u8PositiveChannel;
	u8 THERM_u8NegativeChannel;
}THERM_t;

#define ADC_u8ADC0		   0
#define ADC_u8ADC1		   1
#define ADC_u8ADC2		   2
#define ADC_u8ADC3		   3
#define ADC_u8ADC4		   4
#define ADC_u8ADC5		   5
#define ADC_u8ADC6		   6
#define ADC_u8ADC7		   7

#define NOT_CONNECTED      15

#endif /* HAL_THERM_THERM_PRIVATE_H_ */
