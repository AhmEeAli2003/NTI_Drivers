/*
 * THERMO_prog.c
 *
 *  Created on: ٢٣‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/ADC/ADC_int.h"

#include "THERM_private.h"

extern u8 therm_num;

ES_t THERM_enuInit(THERM_t * Copy_pAstrThermistorConfig)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Iter = 0;

	if(Copy_pAstrThermistorConfig != NULL)
	{
		for(Local_u8Iter = 0; Local_u8Iter < therm_num; Local_u8Iter++)
		{
			if(Copy_pAstrThermistorConfig[Local_u8Iter].THERM_u8NegativeChannel != NOT_CONNECTED)
			{
				DIO_enuSetPinDirection(DIO_u8PORTA, Copy_pAstrThermistorConfig[Local_u8Iter].THERM_u8NegativeChannel, DIO_u8INPUT);
			}

			if(Copy_pAstrThermistorConfig[Local_u8Iter].THERM_u8PositiveChannel != NOT_CONNECTED)
			{
				DIO_enuSetPinDirection(DIO_u8PORTA, Copy_pAstrThermistorConfig[Local_u8Iter].THERM_u8PositiveChannel, DIO_u8INPUT);
			}
		}
	}
	else
	{
		return ES_NULL_POINTER;
	}

	ADC_enuInit();
	ADC_enuDisableTriggeringMode();
	ADC_enuDisbleINTMode();
	ADC_enuSetVref(ADC_u8AVCC_VREF);
	ADC_enuEnable();

	return Local_enuErrorState;
}

ES_t THERM_enuGetTemp(THERM_t *Copy_pstrID, f32 * Copy_pf32Temp)
{
	ES_t Local_enuErrorState = ES_NOK;
	u16 Local_u16ADCRead = 0;

	if(Copy_pf32Temp != NULL)
	{
		if(Copy_pstrID->THERM_u8PositiveChannel <= ADC_u8ADC7)
		{
			ADC_enuSelectChannel(Copy_pstrID->THERM_u8PositiveChannel);
			ADC_enuStartConversion();
			ADC_enuADCRead(&Local_u16ADCRead);
			*Copy_pf32Temp = (Local_u16ADCRead * 4.88) / 10.0;
		}
		else if(Copy_pstrID->THERM_u8PositiveChannel != NOT_CONNECTED)
		{
			Local_enuErrorState = ES_NOK;
		}
	}
	else
	{
		return ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
