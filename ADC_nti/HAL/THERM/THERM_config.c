/*
 * THERMO_config.c
 *
 *  Created on: ٢٣‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */
#include "THERM_config.h"
#include "THERM_private.h"

u8 therm_num = THERM_NUM;

THERM_t THERM_AstrThermistorsConfig[THERM_NUM] =
{
		{ADC_u8ADC2, NOT_CONNECTED},
		{ADC_u8ADC3, NOT_CONNECTED}
};
