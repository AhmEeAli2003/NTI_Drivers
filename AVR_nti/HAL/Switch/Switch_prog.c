/**
 ****************************************************************************************
 *   @file          : Switch_prog.c
 *   @author        : Ahmed Ali
 *   @brief         : Switch APIs Implementation.  [Linking Time Configuration]
 *	 @date			: 1 / 7 / 2023
 ****************************************************************************************
*/

/***********************	Includes Section Start	***********************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "Switch_private.h"
#include "Switch_config.h"
/***********************	Includes Section End	***********************/

ES_t Switch_enuInit(SW_t * Copy_pAstrSwitches)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pAstrSwitches != NULL)
	{
		u8 Local_u8Iterator = 0;

		for(Local_u8Iterator = 0; Local_u8Iterator < SW_NUM; Local_u8Iterator++)
		{
			Local_enuErrorState = DIO_enuSetPinDirection(Copy_pAstrSwitches[Local_u8Iterator].SW_u8PortID,
								   	   	   	   	   	     Copy_pAstrSwitches[Local_u8Iterator].SW_u8PinID,
														 DIO_u8INPUT);
			Local_enuErrorState = DIO_enuSetPinValue(Copy_pAstrSwitches[Local_u8Iterator].SW_u8PortID,
							   	   	   	   	   	     Copy_pAstrSwitches[Local_u8Iterator].SW_u8PinID,
													 Copy_pAstrSwitches[Local_u8Iterator].SW_u8Status);
			/**
			 * Note: we use (.) operator not (->) operator because an argument is pointer to struct, so subscriptor
			 * make dereference to the element 0 then 1 then 2 ...etc directly.
			 * If we define argument as Copy_pAstrSwitches[] we will need arrow operator.
			 * */
		}

	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t Switch_enuGetState(SW_t * Copy_pstrSwitches, u8 * Copy_pu8SwState)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pstrSwitches != NULL && Copy_pu8SwState != NULL)
	{
		Local_enuErrorState = DIO_enuGetPinValue(Copy_pstrSwitches->SW_u8PortID,
												 Copy_pstrSwitches->SW_u8PinID,
												 Copy_pu8SwState);
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
