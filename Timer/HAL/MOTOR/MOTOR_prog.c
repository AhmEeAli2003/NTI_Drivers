/*
 * MOTOR_prog.c
 *
 *  Created on: ٠٥‏/٠٩‏/٢٠٢٣
 *      Author: Ahmed
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/TIM/TIM_int.h"

#include "MOTOR_config.h"
#include "MOTOR_private.h"

extern u8 Motors_num;

ES_t MOTOR_enuInit(MOTOR_t *Copy_pAstrMotorConfig)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_u8Iter = 0;

	if(Copy_pAstrMotorConfig != NULL)
	{
		for(Local_u8Iter = 0; Local_u8Iter < Motors_num; Local_u8Iter++)
		{
			switch(Copy_pAstrMotorConfig[Local_u8Iter].MOTOR_u8OCPin)
			{
			case MOTOR_OC0:
				DIO_enuSetPinDirection(DIO_u8PORTB, DIO_u8PIN3, DIO_u8OUTPUT);
				break;
			case MOTOR_OC1A:
				DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN5, DIO_u8OUTPUT);
				break;
			case MOTOR_OC1B:
				DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN4, DIO_u8OUTPUT);
				break;
			case MOTOR_OC2:
				DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN7, DIO_u8OUTPUT);
				break;
			default:
				return ES_OUT_OF_RANGE;
			}
		}
	}
	else
	{
		return ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}

ES_t MOTOR_enuSetSpeedRatio(MOTOR_t *Copy_pstrMotorID, u8 Copy_u8SpeedRatio)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pstrMotorID != NULL)
	{
		TIM_enuGeneratePhaseCorrectPWM(Copy_u8SpeedRatio);
	}
	return Local_enuErrorState;
}

