/*
 * EXTI_prog.c
 *
 *  Created on: ٢٨‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"

#include "EXTI_private.h"
#include "EXTI_config.h"

#include "../interrupt.h"

static volatile void (*EXTI_ApfunINTFun[3])(void *) = {NULL, NULL, NULL}; //Volatile because it is call from ISR
void * EXTI_ApvoidGenericparameter[3] = {NULL, NULL, NULL};

ES_t EXTI_enuInit(EXTI_t * Copy_pstrEXTIConfig)
{
	ES_t Local_enuErrorState = ES_NOK;


	if(NULL != Copy_pstrEXTIConfig)
	{
		u8 Local_u8Iter = 0;
		for(Local_u8Iter = 0; Local_u8Iter < 3; Local_u8Iter++)
		{
			if(Copy_pstrEXTIConfig[Local_u8Iter].EXTI_u8State == ACTIVE)
			{
				switch(Local_u8Iter)
				{
				case 0:
					GICR |= (1<<6);

					/*
					 * Mask first 2 bits
					 * MCUCR &= ~(0x0f << 0)
					 *            -> 0000 0011
					 *           -> 1111 1100
					 * MCUCR  &= 1111 1100
					 * */

					MCUCR &= ~(0x03 << 0);

					//Check Sense Mode
					switch(Copy_pstrEXTIConfig[Local_u8Iter].EXTI_u8SenceLevel)
					{
					case RISING_EDGE:
						MCUCR |= (3 << 0);
						Local_enuErrorState = ES_OK;
						break;
					case FALLING_EDGE:
						MCUCR |= (1 << 1);
						Local_enuErrorState = ES_OK;
						break;
					case ANY_LOGIC:
						MCUCR |= (1 << 0);
						Local_enuErrorState = ES_OK;
						break;
					case LOW_LEVEL:
						Local_enuErrorState = ES_OK;
						break;
					default:
						Local_enuErrorState = ES_OUT_OF_RANGE;
					}
					break;

				case 1:
					GICR |= (1<<7);
					MCUCR &= ~(3<<2); //Mask second 2 bits
					switch(Copy_pstrEXTIConfig[Local_u8Iter].EXTI_u8SenceLevel)
					{
					case RISING_EDGE:
						MCUCR |= (3 << 2);
						Local_enuErrorState = ES_OK;
						break;
					case FALLING_EDGE:
						MCUCR |= (1 << 3);
						Local_enuErrorState = ES_OK;
						break;
					case ANY_LOGIC:
						MCUCR |= (1 << 2);
						Local_enuErrorState = ES_OK;
						break;
					case LOW_LEVEL:
						Local_enuErrorState = ES_OK;
						break;
					default:
						Local_enuErrorState = ES_OUT_OF_RANGE;
					}
					break;

				case 2:
					GICR |= (1<<5);
					MCUCSR &= ~(1<<6); //Mask its control sense bit

					switch(Copy_pstrEXTIConfig[Local_u8Iter].EXTI_u8SenceLevel)
					{
					case RISING_EDGE:
						MCUCSR |= (1 << 6);
						Local_enuErrorState = ES_OK;
						break;
					case FALLING_EDGE:
						Local_enuErrorState = ES_OK;
						break;
					default:
						Local_enuErrorState = ES_OUT_OF_RANGE;
					}
					break;
				}
			}
		}
	}
	else
	{
		return ES_NULL_POINTER;
	}


	return Local_enuErrorState;
}

ES_t EXTI_enuSetSenceMode(u8 Copy_u8EXTI_ID, u8 Copy_u8SenceLevel)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8EXTI_ID < 3)
	{
		switch(Copy_u8EXTI_ID)
		{
		case 0:
			MCUCR &= ~(0x03 << 0);
			//Check Sense Mode
			switch(Copy_u8SenceLevel)
			{
			case RISING_EDGE:
				MCUCR |= (3 << 0);
				Local_enuErrorState = ES_OK;
				break;
			case FALLING_EDGE:
				MCUCR |= (1 << 1);
				Local_enuErrorState = ES_OK;
				break;
			case ANY_LOGIC:
				MCUCR |= (1 << 0);
				Local_enuErrorState = ES_OK;
				break;
			case LOW_LEVEL:
				Local_enuErrorState = ES_OK;
				break;
			default:
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
			break;

		case 1:
			MCUCR &= ~(3<<2); //Mask second 2 bits
			switch(Copy_u8SenceLevel)
			{
			case RISING_EDGE:
				MCUCR |= (3 << 2);
				Local_enuErrorState = ES_OK;
				break;
			case FALLING_EDGE:
				MCUCR |= (1 << 3);
				Local_enuErrorState = ES_OK;
				break;
			case ANY_LOGIC:
				MCUCR |= (1 << 2);
				Local_enuErrorState = ES_OK;
				break;
			case LOW_LEVEL:
				Local_enuErrorState = ES_OK;
				break;
			default:
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
			break;

		case 2:
			MCUCSR &= ~(1<<6); //Mask its control sense bit

			switch(Copy_u8SenceLevel)
			{
			case RISING_EDGE:
				MCUCSR |= (1 << 6);
				Local_enuErrorState = ES_OK;
				break;
			case FALLING_EDGE:
				Local_enuErrorState = ES_OK;
				break;
			default:
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
			break;

		}
	}
	else
	{
		return ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t EXTI_enuEnableINT(u8 Copy_u8EXTI_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8EXTI_ID < 3)
	{
		switch(Copy_u8EXTI_ID)
		{
		case 0:
			GICR |= (1<<6);
			Local_enuErrorState = ES_OK;
			break;

		case 1:
			GICR |= (1<<7);
			Local_enuErrorState = ES_OK;
			break;

		case 2:
			GICR |= (1<<5);
			Local_enuErrorState = ES_OK;
			break;
		}
	}
	else
	{
		return ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t EXTI_enuDisableINT(u8 Copy_u8EXTI_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8EXTI_ID < 3)
	{
		switch(Copy_u8EXTI_ID)
		{
		case 0:
			GICR &= ~(1<<6);
			Local_enuErrorState = ES_OK;
			break;

		case 1:
			GICR &= ~(1<<7);
			Local_enuErrorState = ES_OK;
			break;

		case 2:
			GICR &= ~(1<<5);
			Local_enuErrorState = ES_OK;
			break;
		}
	}
	else
	{
		return ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t EXTI_enuCallBack(void (*Copy_pfunAppFun)(void), void * Copy_pvoidParameter, u8 Copy_u8EXTI_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8EXTI_ID < 3)
	{
		if(Copy_pfunAppFun != NULL)
		{
			EXTI_ApfunINTFun[Copy_u8EXTI_ID] = Copy_pfunAppFun;
			EXTI_ApvoidGenericparameter[Copy_u8EXTI_ID] = Copy_pvoidParameter;
		}
		else
		{
			Local_enuErrorState = ES_NULL_POINTER;
		}
	}
	else
	{
		return ES_OUT_OF_RANGE;
	}

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ISR(VECT_INT0)
{
	if(EXTI_ApfunINTFun[0] != NULL)
	{
		/* Two approaches working well*/
		(*EXTI_ApfunINTFun[0])(EXTI_ApvoidGenericparameter[0]);
		//(*EXTI_ApfunINTFun[0])(EXTI_ApvoidGenericparameter[0]);
	}
}

ISR(VECT_INT1)
{
	if(EXTI_ApfunINTFun[1] != NULL)
	{
		(*EXTI_ApfunINTFun[1])(EXTI_ApvoidGenericparameter[1]);
	}
}

ISR(VECT_INT2)
{
	if(EXTI_ApfunINTFun[2] != NULL)
	{
		(*EXTI_ApfunINTFun[2])(EXTI_ApvoidGenericparameter[2]);
	}
}
