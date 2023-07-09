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

	DIO_enuSetPinDirection(ROW1_PORT, ROW1_PIN, DIO_u8INPUT);
	DIO_enuSetPinDirection(ROW2_PORT, ROW2_PIN, DIO_u8INPUT);
	DIO_enuSetPinDirection(ROW3_PORT, ROW3_PIN, DIO_u8INPUT);
	DIO_enuSetPinDirection(ROW4_PORT, ROW4_PIN, DIO_u8INPUT);

	DIO_enuSetPinValue(ROW1_PORT, ROW1_PIN, DIO_u8PULL_UP);
	DIO_enuSetPinValue(ROW2_PORT, ROW2_PIN, DIO_u8PULL_UP);
	DIO_enuSetPinValue(ROW3_PORT, ROW3_PIN, DIO_u8PULL_UP);
	DIO_enuSetPinValue(ROW4_PORT, ROW4_PIN, DIO_u8PULL_UP);

	DIO_enuSetPinDirection(COL1_PORT, COL1_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(COL2_PORT, COL2_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(COL3_PORT, COL3_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(COL4_PORT, COL4_PIN, DIO_u8OUTPUT);

	DIO_enuSetPinValue(COL1_PORT, COL1_PIN, DIO_u8HIGH);
	DIO_enuSetPinValue(COL2_PORT, COL2_PIN, DIO_u8HIGH);
	DIO_enuSetPinValue(COL3_PORT, COL3_PIN, DIO_u8HIGH);
	DIO_enuSetPinValue(COL4_PORT, COL4_PIN, DIO_u8HIGH);

	return Local_enuErrorState;
}

ES_t KPAD_enuGetPassedKey(u8 *Copy_pu8KeyNumber)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_u8ColIndex = 0, Local_u8RowIndex = 0, Local_u8KeyState = 0;
	static u8 Local_u8AKPADColButtons[4][2] = {
			{COL1_PORT, COL1_PIN},
			{COL2_PORT, COL2_PIN},
			{COL3_PORT, COL3_PIN},
			{COL4_PORT, COL4_PIN}
	};

	static u8 Local_u8AKPADRowButtons[4][2] = {
			{ROW1_PORT, ROW1_PIN},
			{ROW2_PORT, ROW2_PIN},
			{ROW3_PORT, ROW3_PIN},
			{ROW4_PORT, ROW4_PIN}
	};


	static u8 Local_u8AKPADARR[4][4] = KPAD_ARR_VAL;

	/* Initial value of key pressed */
	if(Copy_pu8KeyNumber != NULL)
	{
		*Copy_pu8KeyNumber = NO_PRESSED_KEY;
	}
	else
	{
		return ES_NULL_POINTER;
	}

	for(Local_u8ColIndex = 0; Local_u8ColIndex < 4; Local_u8ColIndex++)
	{
		/* Activate Column */
		DIO_enuSetPinValue(Local_u8AKPADColButtons[Local_u8ColIndex][0],
						   Local_u8AKPADColButtons[Local_u8ColIndex][1], DIO_u8LOW);

		for(Local_u8RowIndex = 0; Local_u8RowIndex < 4; Local_u8RowIndex++)
		{
			/* Read the current row */
			 DIO_enuGetPinValue(Local_u8AKPADRowButtons[Local_u8RowIndex][0],
													Local_u8AKPADRowButtons[Local_u8RowIndex][1], &Local_u8KeyState);
			 if(DIO_u8LOW == Local_u8KeyState)
			 {
				 /* Polling (Busy waiting until the key is released) */
				 while(DIO_u8LOW == Local_u8KeyState)
				 {
					 DIO_enuGetPinValue(Local_u8AKPADRowButtons[Local_u8RowIndex][0],
															Local_u8AKPADRowButtons[Local_u8RowIndex][1], &Local_u8KeyState);
				 }

				 *Copy_pu8KeyNumber = Local_u8AKPADARR[Local_u8RowIndex][Local_u8ColIndex];
				 break;
			 }
		}

		/* Deactivate Column */
		DIO_enuSetPinValue(Local_u8AKPADColButtons[Local_u8ColIndex][0],
						   Local_u8AKPADColButtons[Local_u8ColIndex][1], DIO_u8HIGH);
	}

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
