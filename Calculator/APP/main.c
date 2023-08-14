/**
 ****************************************************************************************
 *   @file          : main.c
 *   @author        : Ahmed Ali
 *   @brief         : main of Calculator Project.
 *	 @date			: 10 / 7 / 2023
 ****************************************************************************************
*/

#include "../LIB/STD_TYPES.h"
#include "../LIB/ERROR_STATE.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/Keypad/Keypad_int.h"
#include <util/delay.h>

void calculate(void);
u32 Calc_u32FirstNum, Calc_u32SecondNum;
f32 Calc_u32Result;
u8 Calc_u8Operator;

typedef struct
{
	u8 Flag_1BitOperatorFlag:1;
	u8 Flag_1BitIsFirstDigit:1;
	u8 Flag_1BitIsFirstPressed:1;
	u8 Flag_1BitIsLineTwoUsed:1;
	u8 Flag_1BitIsUpperTwo:1;
}FLAGS_t;

int fun(void)
{
	u8 Local_u8KeyPressed = 0, Local_u8CharCounter = 0, Local_u8OpCounter = 0;

	FLAGS_t my_flags = {.Flag_1BitOperatorFlag = 0, .Flag_1BitIsFirstDigit = 1, .Flag_1BitIsFirstPressed = 1,
						.Flag_1BitIsLineTwoUsed = 0, .Flag_1BitIsUpperTwo = 0};
	//u32 Calc_u32FirstNum = 0, Calc_u32SecondNum = 0, Calc_u32Result = 0;


	LCD_enuInit();
	KPAD_enuInit();

	LCD_enuSendCommand(0x0C); //Hide Cursor
	LCD_enuSendString((u8 *) "2 operands Mode");
	LCD_enuSetPosition(2, 1);
	LCD_enuSendString((u8 *) "Unsigned Numbers");
	_delay_ms(1000);
	LCD_enuSendCommand(0x01); //Clear LCD
	LCD_enuSendString((u8 *) "Above 2 operands");
	LCD_enuSetPosition(2, 1);
	LCD_enuSendString((u8 *) "for the same op");
	_delay_ms(1000);
	LCD_enuSendCommand(0x01);
	LCD_enuSendString((u8 *) "Otherwise, user must arrange EQ");
	_delay_ms(1000);
	LCD_enuSendCommand(0x01);

	while(1)
	{
		/* Polling (Stop every thing in application until keypad pressed)*/
		do
		{
			KPAD_enuGetPassedKey(&Local_u8KeyPressed);

		}while(Local_u8KeyPressed == 0xFF); //there isn't any Key pressed


		if(Local_u8KeyPressed == 'c')
		{
			LCD_enuSendCommand(0x01); //Clear Display
		}
		else if(Local_u8KeyPressed >= 0 && Local_u8KeyPressed <= 9)
		{
			LCD_enuDisplayNumber(Local_u8KeyPressed);
			Local_u8CharCounter++;

			if(my_flags.Flag_1BitOperatorFlag == 0)
			{
				if(my_flags.Flag_1BitIsFirstDigit)
				{
					Calc_u32FirstNum = Local_u8KeyPressed;
					my_flags.Flag_1BitIsFirstDigit = 0;
				}
				else
				{
					Calc_u32FirstNum = (Calc_u32FirstNum * 10) + Local_u8KeyPressed;
				}
			}
			else
			{
				if(my_flags.Flag_1BitIsUpperTwo)
				{
				    Calc_u32FirstNum = Calc_u32Result;
				    my_flags.Flag_1BitIsUpperTwo = 0;
				}

					if(my_flags.Flag_1BitIsFirstDigit)
					{
						Calc_u32SecondNum = Local_u8KeyPressed;
						my_flags.Flag_1BitIsFirstDigit = 0;
					}
					else
					{
						Calc_u32SecondNum = (Calc_u32SecondNum * 10) + Local_u8KeyPressed;
					}

			}
		}
		else if((Local_u8KeyPressed >= '*' && Local_u8KeyPressed <= '/') || Local_u8KeyPressed == '=')
		{

			Local_u8CharCounter++;

			if(Local_u8KeyPressed != '=')
			{
				LCD_enuDisplayChar(Local_u8KeyPressed);

				my_flags.Flag_1BitOperatorFlag = 1;
				Local_u8OpCounter++;
				if(Local_u8OpCounter > 1)
				{
					my_flags.Flag_1BitIsUpperTwo = 1;
					calculate();
				}

				Calc_u8Operator = Local_u8KeyPressed;
				my_flags.Flag_1BitIsFirstDigit = 1;

			}
			else
			{
					if(my_flags.Flag_1BitIsLineTwoUsed)
					{
						LCD_enuSendCommand(0x01); //Clear LCD
						LCD_enuDisplayChar(Local_u8KeyPressed);
					}
					else
					{
						LCD_enuSetPosition(2, 1);
						LCD_enuDisplayChar(Local_u8KeyPressed);
					}
					//Calculate Result
					calculate();

					if(Calc_u32SecondNum != 0)
					{
						LCD_enuDisplayNumber(Calc_u32Result);
						if(Calc_u8Operator == '/')
						{
							LCD_enuDisplayChar('.');
							LCD_enuDisplayNumber((Calc_u32Result - ((u32)Calc_u32Result)) * 1000);
						}
					}
					else
					{
						if(Calc_u8Operator != '/')
						{
							LCD_enuDisplayNumber(Calc_u32Result);
						}

					}

					/* Polling (Stop every thing in application until ON/C key pressed)*/
					do
					{
						KPAD_enuGetPassedKey(&Local_u8KeyPressed);
						if(Local_u8KeyPressed != 0xFF && Local_u8KeyPressed != 'c' && my_flags.Flag_1BitIsFirstPressed)
						{
							LCD_enuSetPosition(1, 1);
							LCD_enuSendString((u8 *) "Please Press ON/c key to release");
							my_flags.Flag_1BitIsFirstPressed = 0;
						}

					}while(Local_u8KeyPressed != 'c');
					/* If ON/C key pressed clear all variables and LCD*/
					Calc_u32FirstNum = Calc_u32SecondNum = Calc_u32Result = 0;
					Local_u8CharCounter = my_flags.Flag_1BitOperatorFlag = 0;
					my_flags.Flag_1BitIsFirstDigit = my_flags.Flag_1BitIsFirstPressed = 1;
					Local_u8OpCounter = my_flags.Flag_1BitIsUpperTwo = 0;
					LCD_enuSendCommand(0x01); //Clear Display
			}
		}

		if(Local_u8CharCounter == 16)
		{
			LCD_enuSendCommand(0xC0); //Go to second line
			my_flags.Flag_1BitIsLineTwoUsed = 1;
		}
	}

	return 0;
}

void calculate(void)
{
	switch(Calc_u8Operator)
	{
	case '+':
		Calc_u32Result = Calc_u32FirstNum + Calc_u32SecondNum;
		break;
	case '-':
		Calc_u32Result = Calc_u32FirstNum - Calc_u32SecondNum;
		break;
	case '*':
		Calc_u32Result = Calc_u32FirstNum * Calc_u32SecondNum;
		break;
	case '/':
		if(Calc_u32SecondNum != 0)
		{
			Calc_u32Result = (float) Calc_u32FirstNum / Calc_u32SecondNum;
		}
		else
		{
			LCD_enuSetPosition(2, 1);
			LCD_enuSendString((u8 *) "Math Error!");
		}
		break;
	}
}
