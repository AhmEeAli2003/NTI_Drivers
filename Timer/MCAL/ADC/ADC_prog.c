/*
 * ADC_prog.c
 *
 *  Created on: ٠٩‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"
#include "../interrupt.h"
#include "ADC_private.h"
#include "ADC_config.h"

static void (*ADC_PfunISRFun)(void *) = NULL;
static void * ADC_pvoidISRParam = NULL;

ES_t ADC_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	//You need mask here
	ADMUX &= 0x3F;
	/* Reference Configuration */
	#if ADC_VREF_SOURCE == ADC_AREF_VREF
		ADMUX &= ~(3<<6);
	#elif ADC_VREF_SOURCE == ADC_AVCC_VREF
		ADMUX |= (1<<6);
	#elif ADC_VREF_SOURCE == ADC_INTERNAL_VREF
		ADMUX |= (3<<6);
		#warning "A 100nf Capacitor must be connected at AREF Pin"
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


	/* Mask Register */
	ADCSRA &= 0xF8;
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

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}
ES_t ADC_enuEnable(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* ADC Enable */
	ADCSRA |= (1<<7);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t ADC_enuDisble(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* ADC Disable */
	ADCSRA &= ~(1<<7);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t ADC_enuSetVref(u8 Copy_u8Source)
{
	ES_t Local_enuErrorState = ES_NOK;

	ADMUX &= 0x3F;

	if(Copy_u8Source < 3)
	{
		switch(Copy_u8Source)
		{
		case 0:
			ADMUX &= ~(3<<6);
			break;
		case 1:
			ADMUX |= (1<<6);
			break;
		case 2:
			ADMUX |= (3<<6);
			break;
		}
	}
	else
	{
		return ES_OUT_OF_RANGE;
	}

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}
ES_t ADC_enuStartConversion(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	ADCSRA |= (1<<6);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t ADC_enuPollingSystem(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	while(((ADCSRA>>4) & 1) == 0);

	ADCSRA |= (1<<4);

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t ADC_enuReadHighValue(u8 *Copy_pu8Value)
{
	ES_t Local_enuErrorState = ES_NOK;

#if ADC_ADJUST == ADC_RIGHT_ADJUST
	*Copy_pu8Value = (ADCL >> 2);
	*Copy_pu8Value |= (ADCH << 6);
#elif ADC_ADJUST == ADC_LEFT_ADJUST
	*Copy_pu8Value = ADCH;
#else
	#error "Invalid Adjustment Selection!"
#endif

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t ADC_enuADCRead(u16 *Copy_pu16Result)
{
	ES_t Local_enuErrorState = ES_NOK;

#if ADC_ADJUST == ADC_RIGHT_ADJUST
	*Copy_pu16Result = ADCL;
	*Copy_pu16Result |= ((u16)ADCH << 8);
#elif ADC_ADJUST == ADC_LEFT_ADJUST
	*Copy_pu16Result = (ADCL >> 6);
	*Copy_pu16Result |= (ADCH << 2);
#else
	#error "Invalid Adjustment Selection!"
#endif

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t ADC_enuCallBack(void (*Copy_pfunAppFun)(void *), void *Copy_pvoidAppParam)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pfunAppFun != NULL)
	{
		ADC_PfunISRFun = Copy_pfunAppFun;
		ADC_pvoidISRParam = Copy_pvoidAppParam;
	}
	else
	{
		return ES_NULL_POINTER;
	}

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t ADC_enuSelectChannel(u8 Copy_u8ChannelID)
{
	ES_t Local_enuErrorState = ES_NOK;
	/* Mask Register */
	ADMUX &= 0xE0;
	/* Set Channel */
	if(Copy_u8ChannelID < 32)
	{
		ADMUX |= Copy_u8ChannelID;
	}
	else
	{
		return ES_OUT_OF_RANGE;
	}

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t ADC_enuEnableTriggeringMode(u8 Copy_u8TriggeringSource)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* For Safety from interrupt */
	ADCSRA &= ~(1<<5);
	switch(Copy_u8TriggeringSource)
	{
	case ADC_FREE_RUNNING:
		SFIOR &= ~(1<<5);
		SFIOR &= ~(1<<6);
		SFIOR &= ~(1<<7);
		break;
	case ADC_ANALOG_COMP:
		SFIOR |= (1<<5);
		SFIOR &= ~(1<<6);
		SFIOR &= ~(1<<7);
		break;
	case ADC_EXTI_0_TRIG:
		SFIOR &= ~(1<<5);
		SFIOR |= (1<<6);
		SFIOR &= ~(1<<7);
		break;
	case ADC_TIM0_CTC:
		SFIOR |= (1<<5);
		SFIOR |= (1<<6);
		SFIOR &= ~(1<<7);
		break;
	case ADC_TIM0_OV:
		SFIOR &= ~(1<<5);
		SFIOR &= ~(1<<6);
		SFIOR |= (1<<7);
		break;
	case ADC_TIM1_CTCB:
		SFIOR |= (1<<5);
		SFIOR &= ~(1<<6);
		SFIOR |= (1<<7);
		break;
	case ADC_TIM1_OV:
		SFIOR &= ~(1<<5);
		SFIOR |= (1<<6);
		SFIOR |= (1<<7);
		break;
	case ADC_TIM1_CAPTUR:
		SFIOR |= (1<<5);
		SFIOR |= (1<<6);
		SFIOR |= (1<<7);
		break;
	default:
		return ES_OUT_OF_RANGE;
	}
	/* Enable Triggering Source */
	ADCSRA |= (1<<5);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t ADC_enuDisableTriggeringMode(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	ADCSRA &= ~(1<<5);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t ADC_enuEnableINTMode(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	ADCSRA |= (1<<3);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t ADC_enuDisbleINTMode(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	ADCSRA &= ~(1<<3);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ISR(VECT_ADC)
{
	if(ADC_PfunISRFun != NULL)
	{
		ADC_PfunISRFun(ADC_pvoidISRParam);
	}
}
