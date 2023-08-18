/*
 * ADC_prog.c
 *
 *  Created on: ٠٩‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"
#include "../DIO/DIO_int.h"
#include "ADC_private.h"
#include "ADC_config.h"

ES_t ADC_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* Reference Configuration */
	#if ADC_VREF_SOURCE == ADC_AREF_VREF
		ADMUX &= ~(3<<6);
	#elif ADC_VREF_SOURCE == ADC_AVCC_VREF
		ADMUX |= (1<<6);
	#elif ADC_VREF_SOURCE == ADC_INTERNAL_VREF
		ADMUX |= (3<<6);
	#else
		#error "Invalid Voltage Reference selection!"
	#endif


	/* Adjustment Configuration */
	#if ADC_ADJUST == ADC_RIGHT_ADJUST
		ADMUX &= ~(1<<5);
	#elif ADC_ADJUST == ADC_LEFT_ADJUST
		ADMUX |= (1<<5);
	#else
		#error "Invalid Adjustment Selection!"
	#endif

	/* ADC Channel Configuration */
	#if ADC_CHANNEL == ADC_ADC0
		ADMUX &= ~(0x1F<<0);
		Local_enuErrorState = DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8INPUT);
		Local_enuErrorState &= DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8FLOAT);
	#elif ADC_CHANNEL == ADC_ADC1
		ADMUX |= (1<<0);
		Local_enuErrorState = DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN1, DIO_u8INPUT);
		Local_enuErrorState &= DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN1, DIO_u8FLOAT);
	#elif ADC_CHANNEL == ADC_ADC2
		ADMUX |= (2<<0);
		Local_enuErrorState = DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN2, DIO_u8INPUT);
		Local_enuErrorState &= DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN2, DIO_u8FLOAT);
	#elif ADC_CHANNEL == ADC_ADC3
		ADMUX |= (3<<0);
		Local_enuErrorState = DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN3, DIO_u8INPUT);
		Local_enuErrorState &= DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN3, DIO_u8FLOAT);
	#elif ADC_CHANNEL == ADC_ADC4
		ADMUX |= (4<<0);
		Local_enuErrorState = DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN4, DIO_u8INPUT);
		Local_enuErrorState &= DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN4, DIO_u8FLOAT);
	#elif ADC_CHANNEL == ADC_ADC5
		ADMUX |= (5<<0);
		Local_enuErrorState = DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN5, DIO_u8INPUT);
		Local_enuErrorState &= DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN5, DIO_u8FLOAT);
	#elif ADC_CHANNEL == ADC_ADC6
		ADMUX |= (6<<0)
		Local_enuErrorState = DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN6, DIO_u8INPUT);
		Local_enuErrorState &= DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN6, DIO_u8FLOAT);
	#elif ADC_CHANNEL == ADC_ADC7
		ADMUX |= (7<<0);
		Local_enuErrorState = DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN7, DIO_u8INPUT);
		Local_enuErrorState &= DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN7, DIO_u8FLOAT);
	#else
		#error "Invalid Channel Selection!"
	#endif

	/* Prescaler Configuration */
	#if ADC_PRESCALER == ADC_PRESCALER_2
		ADCSRA |= (1<<0);
	#elif ADC_PRESCALER == ADC_PRESCALER_4
		ADCSRA |= (1<<1);
	#elif ADC_PRESCALER == ADC_PRESCALER_8
		ADCSRA |= (3<<0);
	#elif ADC_PRESCALER == ADC_PRESCALER_16
		ADCSRA |= (1<<2);
	#elif ADC_PRESCALER == ADC_PRESCALER_32
		ADCSRA |= (5<<0);
	#elif ADC_PRESCALER == ADC_PRESCALER_64
		ADCSRA |= (6<<0);
	#elif ADC_PRESCALER == ADC_PRESCALER_128
		ADCSRA |= (7<<0);
	#else
		#error "Invalid Prescaler Selection!"
	#endif

	/* ADC Enable */
	ADCSRA |= (1<<7);
	return Local_enuErrorState;
}

ES_t ADC_enuADCRead(u16 *Copy_pu16Result)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* Start Conversion */
	ADCSRA |= (1<<6);

	/* Polling: Wait until flag is set*/
	while(((ADCSRA >> 4) & 1) == 0);

	/* Clear Flag */
	ADCSRA &= ~(1<<4);

	/* Return Result*/
	*Copy_pu16Result = ADC_DATA;

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
