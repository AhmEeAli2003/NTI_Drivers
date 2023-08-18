/**
 ****************************************************************************************
 *   @file          : LED_prog.c
 *   @author        : Ahmed Ali
 *   @brief         : LED APIs implementation
 *	 @date			: 1 / 7 / 2023
 ****************************************************************************************
*/

/***********************	Includes Section Start	***********************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "LED_private.h"
#include "LED_config.h"
/***********************	Includes Section End	***********************/

ES_t LED_enuInit(LED_t * Copy_pstrLedConfiguration)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pstrLedConfiguration != NULL)
	{
		u8 Local_u8Iterator = 0;

		for(Local_u8Iterator = 0; Local_u8Iterator < LED_NUM; Local_u8Iterator++)
		{
			Local_enuErrorState = DIO_enuSetPinDirection(Copy_pstrLedConfiguration[Local_u8Iterator].LED_u8PortID,
														 Copy_pstrLedConfiguration[Local_u8Iterator].LED_u8PinID,
														 DIO_u8OUTPUT
														);

			if(Copy_pstrLedConfiguration[Local_u8Iterator].LED_u8Connection == LED_u8SINK)
			{
				if(Copy_pstrLedConfiguration[Local_u8Iterator].LED_u8InitState == LED_u8ON)
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedConfiguration[Local_u8Iterator].LED_u8PortID,
							           	   	   	   	   	     Copy_pstrLedConfiguration[Local_u8Iterator].LED_u8PinID,
															 DIO_u8LOW);

				}
				else if(Copy_pstrLedConfiguration[Local_u8Iterator].LED_u8InitState == LED_u8OFF)
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedConfiguration[Local_u8Iterator].LED_u8PortID,
							           	   	   	   	   	   	 Copy_pstrLedConfiguration[Local_u8Iterator].LED_u8PinID,
															 DIO_u8HIGH);
				}
				else
				{
					return ES_OUT_OF_RANGE;
				}
			}
			else if(Copy_pstrLedConfiguration[Local_u8Iterator].LED_u8Connection == LED_u8SOURCE)
			{
				if(Copy_pstrLedConfiguration[Local_u8Iterator].LED_u8InitState == LED_u8ON)
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedConfiguration[Local_u8Iterator].LED_u8PortID,
							           	   	   	   	   	     Copy_pstrLedConfiguration[Local_u8Iterator].LED_u8PinID,
															 DIO_u8HIGH);

				}
				else if(Copy_pstrLedConfiguration[Local_u8Iterator].LED_u8InitState == LED_u8OFF)
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedConfiguration[Local_u8Iterator].LED_u8PortID,
							           	   	   	   	   	   	 Copy_pstrLedConfiguration[Local_u8Iterator].LED_u8PinID,
															 DIO_u8LOW);
				}
				else
				{
					return ES_OUT_OF_RANGE;
				}
			}
			else
			{
				return ES_OUT_OF_RANGE;
			}
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t LED_enuTurnON(LED_t * Copy_pstrLedID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pstrLedID != NULL)
	{
		if(Copy_pstrLedID->LED_u8Connection == LED_u8SINK)
		{
			Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID, Copy_pstrLedID->LED_u8PinID, DIO_u8LOW);
		}
		else if(Copy_pstrLedID->LED_u8Connection == LED_u8SOURCE)
		{
			Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID, Copy_pstrLedID->LED_u8PinID, DIO_u8HIGH);
		}
		else
		{
			return ES_OUT_OF_RANGE;
		}
	}
	else
	{
		return ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t LED_enuTurnOFF(LED_t * Copy_pstrLedID)
{
	ES_t Local_enuErrorState = ES_NOK;


	if(Copy_pstrLedID != NULL)
	{
		if(Copy_pstrLedID->LED_u8Connection == LED_u8SINK)
		{
			Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID, Copy_pstrLedID->LED_u8PinID, DIO_u8HIGH);
		}
		else if(Copy_pstrLedID->LED_u8Connection == LED_u8SOURCE)
		{
			Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID, Copy_pstrLedID->LED_u8PinID, DIO_u8LOW);
		}
		else
		{
			return ES_OUT_OF_RANGE;
		}
	}
	else
	{
		return ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

