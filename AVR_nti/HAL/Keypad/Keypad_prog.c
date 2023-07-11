/*
 * Keypad_prog.c
 *
 *  Created on: ٠٩‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "Keypad_private.h"
#include "Keypad_config.h"

ES_t KPAD_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Iterator = KPAD_ZERO;
	u32 Local_u32Check = KPAD_ZERO;

	Local_u32Check |= (DIO_enuSetPinDirection(ROW1_PORT, ROW1_PIN, DIO_u8INPUT) << KPAD_SHIFTBIT_ZERO);
	Local_u32Check |= (DIO_enuSetPinDirection(ROW2_PORT, ROW2_PIN, DIO_u8INPUT) << KPAD_SHIFTBIT_THREE);
	Local_u32Check |= (DIO_enuSetPinDirection(ROW3_PORT, ROW3_PIN, DIO_u8INPUT) << KPAD_SHIFTBIT_SIX);
	Local_u32Check |= (DIO_enuSetPinDirection(ROW4_PORT, ROW4_PIN, DIO_u8INPUT) << KPAD_SHIFTBIT_NINE);

	Local_u32Check |= (DIO_enuSetPinValue(ROW1_PORT, ROW1_PIN, DIO_u8PULL_UP) << KPAD_SHIFTBIT_TWELVE);
	Local_u32Check |= (((u32)DIO_enuSetPinValue(ROW2_PORT, ROW2_PIN, DIO_u8PULL_UP)) << KPAD_SHIFTBIT_FIFTEEN);
	Local_u32Check |= (((u32)DIO_enuSetPinValue(ROW3_PORT, ROW3_PIN, DIO_u8PULL_UP)) << KPAD_SHIFTBIT_EIGHTEEN);
	Local_u32Check |= (((u32)DIO_enuSetPinValue(ROW4_PORT, ROW4_PIN, DIO_u8PULL_UP)) << KPAD_SHIFTBIT_TWENTYONE);

	for(Local_u8Iterator = KPAD_ZERO; Local_u8Iterator < KPAD_TWENTYFOUR; Local_u8Iterator += KPAD_THREE)
	{
		if( ( ( (Local_u32Check)>>Local_u8Iterator) & KPAD_SEVEN) != ES_OK)
		{
			return Local_enuErrorState;
		}
	}
	Local_u32Check = KPAD_ZERO;

	Local_u32Check |= (DIO_enuSetPinDirection(COL1_PORT, COL1_PIN, DIO_u8OUTPUT) << KPAD_SHIFTBIT_ZERO);
	Local_u32Check |= (DIO_enuSetPinDirection(COL2_PORT, COL2_PIN, DIO_u8OUTPUT) << KPAD_SHIFTBIT_THREE);
	Local_u32Check |= (DIO_enuSetPinDirection(COL3_PORT, COL3_PIN, DIO_u8OUTPUT) << KPAD_SHIFTBIT_SIX);
	Local_u32Check |= (DIO_enuSetPinDirection(COL4_PORT, COL4_PIN, DIO_u8OUTPUT) << KPAD_SHIFTBIT_NINE);

	Local_u32Check |= (DIO_enuSetPinValue(COL1_PORT, COL1_PIN, DIO_u8HIGH) << KPAD_SHIFTBIT_TWELVE);
	Local_u32Check |= (((u32)DIO_enuSetPinValue(COL2_PORT, COL2_PIN, DIO_u8HIGH)) << KPAD_SHIFTBIT_FIFTEEN);
	Local_u32Check |= (((u32)DIO_enuSetPinValue(COL3_PORT, COL3_PIN, DIO_u8HIGH)) << KPAD_SHIFTBIT_EIGHTEEN);
	Local_u32Check |= (((u32)DIO_enuSetPinValue(COL4_PORT, COL4_PIN, DIO_u8HIGH)) << KPAD_SHIFTBIT_TWENTYONE);

	for(Local_u8Iterator = KPAD_ZERO; Local_u8Iterator < KPAD_TWENTYFOUR; Local_u8Iterator += KPAD_THREE)
	{
		if( ( ( (Local_u32Check)>>Local_u8Iterator) & KPAD_SEVEN) != ES_OK)
		{
			return Local_enuErrorState;
		}
	}

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t KPAD_enuGetPassedKey(u8 *Copy_pu8KeyNumber)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_u8ColIndex = KPAD_ZERO, Local_u8RowIndex = KPAD_ZERO, Local_u8KeyState = KPAD_ZERO;
	u8 Local_u8Iterator = KPAD_ZERO;
	u32 Local_u32Check = KPAD_ZERO;

	static u8 Local_u8AKPADColButtons[KPAD_COLNUM][KPAD_TWO] = {
			{COL1_PORT, COL1_PIN},
			{COL2_PORT, COL2_PIN},
			{COL3_PORT, COL3_PIN},
			{COL4_PORT, COL4_PIN}
	};

	static u8 Local_u8AKPADRowButtons[KPAD_ROWNUM][KPAD_TWO] = {
			{ROW1_PORT, ROW1_PIN},
			{ROW2_PORT, ROW2_PIN},
			{ROW3_PORT, ROW3_PIN},
			{ROW4_PORT, ROW4_PIN}
	};


	static u8 Local_u8AKPADARR[KPAD_ROWNUM][KPAD_COLNUM] = KPAD_ARR_VAL;

	/* Initial value of key pressed */
	if(Copy_pu8KeyNumber != NULL)
	{
		*Copy_pu8KeyNumber = NO_PRESSED_KEY;
	}
	else
	{
		return ES_NULL_POINTER;
	}

	for(Local_u8ColIndex = KPAD_ZERO; Local_u8ColIndex < KPAD_COLNUM; Local_u8ColIndex++)
	{
		/* Activate Column */
		Local_u32Check |= (DIO_enuSetPinValue(Local_u8AKPADColButtons[Local_u8ColIndex][KPAD_ZERO],
						   Local_u8AKPADColButtons[Local_u8ColIndex][KPAD_ONE], DIO_u8LOW) << KPAD_SHIFTBIT_ZERO);

		for(Local_u8RowIndex = KPAD_ZERO; Local_u8RowIndex < KPAD_ROWNUM; Local_u8RowIndex++)
		{
			/* Read the current row */
			 Local_u32Check |= (DIO_enuGetPinValue(Local_u8AKPADRowButtons[Local_u8RowIndex][KPAD_ZERO],
													Local_u8AKPADRowButtons[Local_u8RowIndex][KPAD_ONE], &Local_u8KeyState) << KPAD_SHIFTBIT_THREE);
			 if(DIO_u8LOW == Local_u8KeyState)
			 {
				 /* Polling (Busy waiting until the key is released) */
				 while(DIO_u8LOW == Local_u8KeyState)
				 {
					 Local_u32Check |= (DIO_enuGetPinValue(Local_u8AKPADRowButtons[Local_u8RowIndex][KPAD_ZERO],
															Local_u8AKPADRowButtons[Local_u8RowIndex][KPAD_ONE], &Local_u8KeyState) << KPAD_SHIFTBIT_SIX);
				 }

				 *Copy_pu8KeyNumber = Local_u8AKPADARR[Local_u8RowIndex][Local_u8ColIndex];
				 break;
			 }
		}

		/* Deactivate Column */
		Local_u32Check |= (DIO_enuSetPinValue(Local_u8AKPADColButtons[Local_u8ColIndex][KPAD_ZERO],
						   	   	   	   	   	   Local_u8AKPADColButtons[Local_u8ColIndex][KPAD_ONE], DIO_u8HIGH) << KPAD_SHIFTBIT_NINE);
	}

	for(Local_u8Iterator = KPAD_ZERO; Local_u8Iterator < KPAD_TWELVE; Local_u8Iterator += KPAD_THREE)
	{
		if( ( ( (Local_u32Check)>>Local_u8Iterator) & KPAD_SEVEN) != ES_OK)
		{
			return Local_enuErrorState;
		}
	}
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
