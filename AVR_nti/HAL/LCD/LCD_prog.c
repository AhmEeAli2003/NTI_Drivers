/**
 ****************************************************************************************
 *   @file          : LCD_prog.c
 *   @author        : Ahmed Ali
 *   @brief         : ADC APIs Implementation.
 *	 @date			: 6 / 7 / 2023
 ****************************************************************************************
*/

/***********************	Includes Section Start	***********************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "LCD_config.h"
#include "LCD_private.h"
#include <util/delay.h>
/***********************	Includes Section End	***********************/

ES_t LCD_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* Shared configuration in two LCD modes */
	DIO_enuSetPinDirection(RS_PORT, RS_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(RW_PORT, RW_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(EN_PORT, EN_PIN, DIO_u8OUTPUT);

	DIO_enuSetPinDirection(D7_PORT, D7_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D6_PORT, D6_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D5_PORT, D5_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D4_PORT, D4_PIN, DIO_u8OUTPUT);

	_delay_ms(35);


	#if LCD_MODE == EIGHT_BIT
		DIO_enuSetPinDirection(D3_PORT, D3_PIN, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(D2_PORT, D2_PIN, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(D1_PORT, D1_PIN, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(D0_PORT, D0_PIN, DIO_u8OUTPUT);

		/* Function Set */
		LCD_invoidSendCommand(0x38);
	#elif LCD_MODE == FOUR_BIT
		LCD_invoidSendCommand(0x28);
	#else
		#error "Invalid LCD Mode"
	#endif

		_delay_ms(1);
		/* Display ON */
		LCD_invoidSendCommand(0x0F);
		_delay_ms(1);
		/* Display Clear */
		LCD_invoidSendCommand(0x01);
		_delay_ms(2);
		/* Entry Mode */
		LCD_invoidSendCommand(0x06);

	return Local_enuErrorState;
}

ES_t LCD_enuDisplayChar(u8 Copy_u8Char)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* Set RS as DATA */
	DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8HIGH);

	LCD_voidLatch(Copy_u8Char);

	return Local_enuErrorState;
}

ES_t LCD_enuSendCommand(u8 Copy_u8Command)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* Set RS as Command */
	DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8LOW);

	LCD_voidLatch(Copy_u8Command);

	return Local_enuErrorState;
}

ES_t LCD_enuSendString(u8 *Copy_pu8string)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* Set RS as DATA */
	DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8HIGH);

	if(Copy_pu8string != NULL)
	{
		while(*Copy_pu8string)
		{
			LCD_voidLatch(*Copy_pu8string);
			Copy_pu8string++;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t LCD_enuSetPosition(u8 Copy_u8Column, u8 Copy_u8Row)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8StartFirstCol = 0x80;
	u8 Local_u8StartSecondCol = 0xC0;

	/* Set RS as Command */
	DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8LOW);

	if(Copy_u8Column >= 1 && Copy_u8Column <= 16)
	{
		if(Copy_u8Row == 1)
		{
			Copy_u8Column--;
			Local_u8StartFirstCol += Copy_u8Column;
			LCD_voidLatch(Local_u8StartFirstCol);
			Local_enuErrorState = ES_OK;
		}
		else if(Copy_u8Row == 2)
		{
			Copy_u8Column--;
			Local_u8StartSecondCol += Copy_u8Column;
			LCD_voidLatch(Local_u8StartSecondCol);
			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

static void LCD_voidLatch(u8 Copy_u8Data)
{
	/* Set RW as write operation, EN is Low */
	DIO_enuSetPinValue(RW_PORT, RW_PIN, DIO_u8LOW);
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);
	/* Write Command */
	DIO_enuSetPinValue(D7_PORT, D7_PIN, ((Copy_u8Data >> 7) & 1));
	DIO_enuSetPinValue(D6_PORT, D6_PIN, ((Copy_u8Data >> 6) & 1));
	DIO_enuSetPinValue(D5_PORT, D5_PIN, ((Copy_u8Data >> 5) & 1));
	DIO_enuSetPinValue(D4_PORT, D4_PIN, ((Copy_u8Data >> 4) & 1));
	#if LCD_MODE == EIGHT_BIT
		DIO_enuSetPinValue(D3_PORT, D3_PIN, ((Copy_u8Data >> 3) & 1));
		DIO_enuSetPinValue(D2_PORT, D2_PIN, ((Copy_u8Data >> 2) & 1));
		DIO_enuSetPinValue(D1_PORT, D1_PIN, ((Copy_u8Data >> 1) & 1));
		DIO_enuSetPinValue(D0_PORT, D0_PIN, ((Copy_u8Data >> 0) & 1));
	#elif LCD_MODE == FOUR_BIT

	#endif
	/* Enable Latch "EN is High" because latch happen in rising edge*/
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8HIGH);
	_delay_ms(10); /* Garbage Number */
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);

	_delay_ms(10); //For speed difference between MC and LCD.
}
static inline void LCD_invoidSendCommand(u8 Copy_u8Command)
{

	/* Set RS as Command, EN is Low */
	DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8LOW);
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);
	/* Set RW as write operation */
	DIO_enuSetPinValue(RW_PORT, RW_PIN, DIO_u8LOW);
	/* Write Command */
	DIO_enuSetPinValue(D7_PORT, D7_PIN, ((Copy_u8Command >> 7) & 1));
	DIO_enuSetPinValue(D6_PORT, D6_PIN, ((Copy_u8Command >> 6) & 1));
	DIO_enuSetPinValue(D5_PORT, D5_PIN, ((Copy_u8Command >> 5) & 1));
	DIO_enuSetPinValue(D4_PORT, D4_PIN, ((Copy_u8Command >> 4) & 1));
	DIO_enuSetPinValue(D3_PORT, D3_PIN, ((Copy_u8Command >> 3) & 1));
	DIO_enuSetPinValue(D2_PORT, D2_PIN, ((Copy_u8Command >> 2) & 1));
	DIO_enuSetPinValue(D1_PORT, D1_PIN, ((Copy_u8Command >> 1) & 1));
	DIO_enuSetPinValue(D0_PORT, D0_PIN, ((Copy_u8Command >> 0) & 1));
	/* Enable Latch "EN is High" because latch happen in rising edge*/
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8HIGH);
	_delay_ms(10); /* Garbage Number */
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);
	_delay_ms(10); //For speed difference between MC and LCD.
}
