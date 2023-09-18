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
		Local_enuErrorState = ES_OUT_Of_RANGE;
		#error "Invalid LCD Mode"
	#endif

		_delay_ms(1);
		/* Display ON Cursor Blink*/
		LCD_invoidSendCommand(0x0F);
		_delay_ms(1);
		/* Clear Display */
		LCD_invoidSendCommand(0x01);
		_delay_ms(2);
		/* Entry Mode */
		LCD_invoidSendCommand(0x06);

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

ES_t LCD_enuDisplayChar(u8 Copy_u8Char)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* Set RS as DATA */
	DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8HIGH);

	LCD_voidLatch(Copy_u8Char);

	return Local_enuErrorState;
}

ES_t LCD_enuDisplayNumber(s32 Copy_s32Number)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Digit = 0;
	s32 Local_s32NumbersOfDigits = 0, Local_s32Power = 0;

	/* Set RS as DATA */
	DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8HIGH);

	if(Copy_s32Number < 0)
	{
		Copy_s32Number *= -1;
		LCD_voidLatch('-');
	}

	if(Copy_s32Number < 10)
	{
		Copy_s32Number += 48;
		LCD_voidLatch((u8)Copy_s32Number);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		LCD_voidGetLog10(Copy_s32Number, &Local_s32NumbersOfDigits);
		LCD_voidPower(10, Local_s32NumbersOfDigits, &Local_s32Power);
		while(Local_s32NumbersOfDigits > 0)
		{
			Local_u8Digit = (u8)(Copy_s32Number / Local_s32Power);
			Copy_s32Number -= ((u32)(Local_u8Digit * Local_s32Power));
			Local_u8Digit += 48;
			Local_s32NumbersOfDigits--;
			Local_s32Power /= 10;

			LCD_voidLatch(Local_u8Digit);
		}
		Local_enuErrorState = ES_OK;
	}


	return Local_enuErrorState;
}

ES_t LCD_enuDisplayFloat(f32 Copy_f32Number)
{
	ES_t Local_enuErrorState = ES_NOK;


	s32 Local_s32IntPart = 0;
	s32 Local_s32FractionPart = 0;
	s32 Local_s32NumbersOfDigits = 0, Local_s32Power = 0;
	u8 Local_u8Digit = 0;
	/* Set RS as DATA */
	DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8HIGH);

	if(Copy_f32Number <  0.0)
	{
		Copy_f32Number *= -1.0;
		LCD_voidLatch('-');
	}

	Local_s32IntPart = (s32) Copy_f32Number;
	Local_s32FractionPart = (s32)((Copy_f32Number - Local_s32IntPart) * 1000);

	if(Local_s32IntPart < 10)
	{
		Local_s32IntPart += 48;
		LCD_voidLatch((u8)Local_s32IntPart);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		LCD_voidGetLog10(Local_s32IntPart, &Local_s32NumbersOfDigits);
		LCD_voidPower(10, Local_s32NumbersOfDigits, &Local_s32Power);
		while(Local_s32NumbersOfDigits > 0)
		{
			Local_u8Digit = (u8)(Local_s32IntPart / Local_s32Power);
			Local_s32IntPart -= ((u32)(Local_u8Digit * Local_s32Power));
			Local_u8Digit += 48;
			Local_s32NumbersOfDigits--;
			Local_s32Power /= 10;

			LCD_voidLatch(Local_u8Digit);
		}
	}

	LCD_voidLatch('.');
	if(Local_s32FractionPart < 10)
	{
		Local_s32FractionPart += 48;
		LCD_voidLatch((u8)Local_s32FractionPart);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		LCD_voidGetLog10(Local_s32FractionPart, &Local_s32NumbersOfDigits);
		LCD_voidPower(10, Local_s32NumbersOfDigits, &Local_s32Power);
		while(Local_s32NumbersOfDigits > 0)
		{
			Local_u8Digit = (u8)(Local_s32FractionPart / Local_s32Power);
			Local_s32FractionPart -= ((u32)(Local_u8Digit * Local_s32Power));
			Local_u8Digit += 48;
			Local_s32NumbersOfDigits--;
			Local_s32Power /= 10;

			LCD_voidLatch(Local_u8Digit);
		}
	}

	return Local_enuErrorState;
}
ES_t LCD_enuDisplaySpecialChar(u8 Copy_u8RowPosition , u8 Copy_u8ColPosition, u8 *Copy_pu8ExtraChar)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Iterator = 0;

		LCD_invoidSendCommand(0x40);

		/* Set RS as DATA */
		DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8HIGH);

		for(Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++)
		{
			LCD_voidLatch(Copy_pu8ExtraChar[Local_u8Iterator]);
		}

		LCD_enuLocalGoToXY(Copy_u8RowPosition, Copy_u8ColPosition);

		DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8HIGH);
		LCD_voidLatch(0);

	return Local_enuErrorState;
}



ES_t LCD_enuSendString(u8 *Copy_pu8string)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Counter = 0;
	/* Set RS as DATA */
	DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8HIGH);

	if(Copy_pu8string != NULL)
	{
		while(*Copy_pu8string)
		{
			LCD_voidLatch(*Copy_pu8string);
			Copy_pu8string++;
			Local_u8Counter++;

			/* Go to Second Line */
			if(Local_u8Counter == 16)
			{
				LCD_invoidSendCommand(0xC0);
				DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8HIGH);
			}
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t LCD_enuSetPosition(u8 Copy_u8Row, u8 Copy_u8Column)
{
	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = LCD_enuLocalGoToXY(Copy_u8Row, Copy_u8Column);

	return Local_enuErrorState;
}

static ES_t LCD_enuLocalGoToXY(u8 Copy_u8Row, u8 Copy_u8Column)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8RowLocation [] = {0x80 , 0xC0};
	LCD_enuSendCommand(Local_u8RowLocation [Copy_u8Row-1]+(Copy_u8Column-1));

	return Local_enuErrorState;
}
static void LCD_voidLatch(u8 Copy_u8Data)
{

	// Set RW as write operation, EN is Low
	DIO_enuSetPinValue(RW_PORT, RW_PIN, DIO_u8LOW);
	//DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);
	// Write Command or Data
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
		// Enable Latch "EN is High" because latch happen in rising edge
		DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8HIGH);
		_delay_ms(10); // Garbage Number
		DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);

		_delay_ms(50);

		DIO_enuSetPinValue(D7_PORT, D7_PIN, ((Copy_u8Data >> 3) & 1));
		DIO_enuSetPinValue(D6_PORT, D6_PIN, ((Copy_u8Data >> 2) & 1));
		DIO_enuSetPinValue(D5_PORT, D5_PIN, ((Copy_u8Data >> 1) & 1));
		DIO_enuSetPinValue(D4_PORT, D4_PIN, ((Copy_u8Data >> 0) & 1));
	#endif
	//Enable Latch "EN is High" because latch happen in rising edge
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8HIGH);
	_delay_ms(10); // Garbage Number
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);

	_delay_ms(10); //For speed difference between MC and LCD.

}
static inline void LCD_invoidSendCommand(u8 Copy_u8Command)
{

	/* Set RS as Command, EN is Low */
	DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8LOW);
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);

	if(Copy_u8Command == 0x28)
	{
		DIO_enuSetPinValue(D7_PORT , D7_PIN , ((Copy_u8Command >> 7) & 1));
		DIO_enuSetPinValue(D6_PORT , D6_PIN , ((Copy_u8Command >> 6) & 1));
		DIO_enuSetPinValue(D5_PORT , D5_PIN , ((Copy_u8Command >> 5) & 1));
		DIO_enuSetPinValue(D4_PORT , D4_PIN , ((Copy_u8Command >> 4) & 1));

		// Enable Latch "EN is High" because latch happen in rising edge
		DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8HIGH);
		_delay_ms(10); // Garbage Number
		DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);

		_delay_ms(50);
	}

	LCD_voidLatch(Copy_u8Command);

}

static void LCD_voidGetLog10(s32 Copy_s32Number, s32 *Copy_ps32Result)
{
	s32 Local_s32NumberOfDigits = 0;
	f64 Local_f64NumberOfDigitsFactor = 1;
	while(Local_f64NumberOfDigitsFactor <= Copy_s32Number)
	{
		Local_f64NumberOfDigitsFactor *= 10;
	}
	Local_f64NumberOfDigitsFactor /= 10;

	while(Local_f64NumberOfDigitsFactor >= 1)
	{
		Local_s32NumberOfDigits++;
		Local_f64NumberOfDigitsFactor /= 10;
	}

	*Copy_ps32Result = Local_s32NumberOfDigits;
}

static void LCD_voidPower(s32 Copy_s32Base, s32 Copy_s32Exponent, s32 *Copy_ps32Result)
{
	*Copy_ps32Result = 1;

	while(Copy_s32Exponent > 1)
	{
		*Copy_ps32Result *= Copy_s32Base;
		Copy_s32Exponent--;
	}
}
