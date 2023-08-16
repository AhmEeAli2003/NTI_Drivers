/*
 * multi_operands.c
 *
 *  Created on: ١٤‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */
/*********************      Includes Section Start    *********************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/ERROR_STATE.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/Keypad/Keypad_int.h"
#include "calculator.h"
#include <util/delay.h>
/*********************      Includes Section End    *********************/


int main(void)
{
	u8 Local_u8KeyPressed = CALC_ZERO, Local_u8OperandIndex = CALC_ZERO, Local_u8OeratorIndex = CALC_ZERO, Local_u8CharCounter = CALC_ZERO;

	FLAGS_t my_flags = {.Flag_1BitIsFirstDigit = CALC_ONE, .Flag_1BitIsFirstPressed = CALC_ONE, .Flag_1BitIsLineTwoUsed = CALC_ZERO};
	LCD_enuInit();
	KPAD_enuInit();

	LCD_enuSendCommand(LCD_u8HIDE_CURSOR_AND_BLINKING);
	LCD_enuSendString((u8 *) "Multi operands");
	LCD_enuSetPosition(LCD_u8SECOND_ROW, LCD_u8COL_6);
	LCD_enuSendString((u8 *) "Mode");
	DELAY_ONE_SECOND;
	LCD_enuSendCommand(LCD_u8CLEAR_LCD);



	while(CALC_ONE)
	{
		calc_voidGetOperandsNum();
		while(CALC_ONE)
		{
			/* Polling (Stop every thing in application until keypad pressed)*/
			do
			{
				KPAD_enuGetPassedKey(&Local_u8KeyPressed);

			}while(Local_u8KeyPressed == KPAD_u8NO_KEY_PRESSED); //there isn't any Key pressed


			if(Local_u8KeyPressed == 'c')
			{
				LCD_enuSendCommand(LCD_u8CLEAR_LCD);
			}
			else if(Local_u8KeyPressed >= CALC_ZERO && Local_u8KeyPressed <= CALC_NINE)
			{
				LCD_enuDisplayNumber(Local_u8KeyPressed);
				Local_u8CharCounter++;


				if(my_flags.Flag_1BitIsFirstDigit)
				{
					Calc_u32InputNum = Local_u8KeyPressed;
					my_flags.Flag_1BitIsFirstDigit = CALC_ZERO;
				}
				else
				{
					Calc_u32InputNum = (Calc_u32InputNum * CALC_TEN) + Local_u8KeyPressed;
				}

			}
			else if((Local_u8KeyPressed >= '*' && Local_u8KeyPressed <= '/') || Local_u8KeyPressed == '=')
			{
				Local_u8CharCounter++;
				LCD_enuDisplayChar(Local_u8KeyPressed);
				Calc_Au32NumArr[Local_u8OperandIndex] = Calc_u32InputNum;
				if(Local_u8KeyPressed != '=')
					Calc_Au8Op_Arr[Local_u8OeratorIndex] = Local_u8KeyPressed;

				Local_u8OeratorIndex++;
				Local_u8OperandIndex++;
				my_flags.Flag_1BitIsFirstDigit = CALC_ONE;
			}


			if(Local_u8CharCounter == CALC_SIXTEEN)
			{
				LCD_enuSendCommand(LCD_u8GO_TO_SECOND_LINE);
				my_flags.Flag_1BitIsLineTwoUsed = CALC_ONE;
			}

			if(Local_u8OperandIndex == Calc_u8OperandsNum) break;
		}

		calc_voidCalculation();
		if(!my_flags.Flag_1BitIsLineTwoUsed)
		{
			LCD_enuSetPosition(LCD_u8SECOND_ROW, LCD_u8COL_1);
			LCD_enuDisplayChar('=');
		}

		LCD_enuDisplayNumber(Calc_Au32NumArr[CALC_ZERO]);



		while(CALC_ONE)
		{
		/* Polling (Stop every thing in application until keypad pressed)*/
		do
		{
				KPAD_enuGetPassedKey(&Local_u8KeyPressed);

		}while(Local_u8KeyPressed == KPAD_u8NO_KEY_PRESSED); //there isn't any Key pressed

		if(Local_u8KeyPressed == 'c')
		{
			LCD_enuSendCommand(LCD_u8CLEAR_LCD);
			Local_u8CharCounter = CALC_ZERO;
			Local_u8OeratorIndex = CALC_ZERO;
			Local_u8OperandIndex = CALC_ZERO;

			break;
		}
		else
		{
			if(my_flags.Flag_1BitIsFirstPressed)
			{
				LCD_enuSetPosition(LCD_u8FIRST_ROW, LCD_u8COL_1);
				LCD_enuSendString((u8 *)"Press ON/C to clear display!");
				my_flags.Flag_1BitIsFirstPressed = CALC_ZERO;
			}
		}
		}

	}

	return CALC_ZERO;
}

void calc_voidGetOperandsNum(void)
{
	u8 Local_u8KeyPressed = CALC_ZERO;

	LCD_enuSendCommand(LCD_u8CLEAR_LCD);
	LCD_enuSendString((u8 *) "Enter No.Operands");
	LCD_enuSetPosition(LCD_u8SECOND_ROW, LCD_u8COL_1);
	LCD_enuSendString((u8 *) "up to 9: ");
	/* Polling (Stop every thing in application until keypad pressed)*/
	do
	{
		KPAD_enuGetPassedKey(&Local_u8KeyPressed);

	}while(Local_u8KeyPressed == KPAD_u8NO_KEY_PRESSED); //there isn't any Key pressed

	if(Local_u8KeyPressed >= CALC_TWO && Local_u8KeyPressed <= CALC_NINE)
	{
		LCD_enuDisplayNumber(Local_u8KeyPressed);
		DELAY_QUARTER_OF_SECOND;
		Calc_u8OperandsNum = Local_u8KeyPressed;
		Calc_u8OperatorsNum = Calc_u8OperandsNum - CALC_ONE;
	}
	else
	{
		LCD_enuSendCommand(LCD_u8CLEAR_LCD);
		LCD_enuSendString((u8 *) "Invalid Input!");
		DELAY_ONE_SECOND;
		calc_voidGetOperandsNum();
	}
	LCD_enuSendCommand(LCD_u8CLEAR_LCD);
}

void calc_voidCalculation(void)
{
	u8 Local_u8iter = CALC_ZERO;
	while(Calc_u8OperandsNum > CALC_ONE)
	{
	/* Multiply Operations */
	for(Local_u8iter = CALC_ZERO; Local_u8iter < Calc_u8OperatorsNum;)
	{
		if(Calc_Au8Op_Arr[Local_u8iter] == '*')
		{
			Calc_Au32NumArr[Local_u8iter] = Calc_Au32NumArr[Local_u8iter] * Calc_Au32NumArr[Local_u8iter+CALC_ONE];
			if(Calc_u8OperandsNum > CALC_ONE)
			{
				calc_voidShift_num(Local_u8iter+CALC_ONE);
				calc_voidShift_op(Local_u8iter);
				Local_u8iter = CALC_ZERO;
			}
		}

		if(Calc_Au8Op_Arr[Local_u8iter] == '/')
		{
			if(Calc_Au32NumArr[Local_u8iter+CALC_ONE] != CALC_ZERO)
			{
				Calc_Au32NumArr[Local_u8iter] = Calc_Au32NumArr[Local_u8iter] / Calc_Au32NumArr[Local_u8iter+CALC_ONE];
			}
			else
			{
				LCD_enuSetPosition(LCD_u8SECOND_ROW, LCD_u8COL_1);
				LCD_enuSendString((u8 *)"Math Error!");
				DELAY_HALF_OF_SECOND;
				main();
			}

			if(Calc_u8OperandsNum > CALC_ONE)
			{
				calc_voidShift_num(Local_u8iter+CALC_ONE);
				calc_voidShift_op(Local_u8iter);
				Local_u8iter = CALC_ZERO;
			}
		}

		if(Calc_Au8Op_Arr[Local_u8iter] != '*' && Calc_Au8Op_Arr[Local_u8iter] != '/')
			Local_u8iter++;
	}

	for(Local_u8iter = CALC_ZERO; Local_u8iter < Calc_u8OperatorsNum;)
	{
		if(Calc_Au8Op_Arr[Local_u8iter] == '+')
		{
			Calc_Au32NumArr[Local_u8iter] = Calc_Au32NumArr[Local_u8iter] + Calc_Au32NumArr[Local_u8iter+CALC_ONE];
			if(Calc_u8OperandsNum > CALC_ONE)
			{
				calc_voidShift_num(Local_u8iter+CALC_ONE);
				calc_voidShift_op(Local_u8iter);
				Local_u8iter = CALC_ZERO;
			}
		}

		if(Calc_Au8Op_Arr[Local_u8iter] == '-')
		{
			Calc_Au32NumArr[Local_u8iter] = Calc_Au32NumArr[Local_u8iter] - Calc_Au32NumArr[Local_u8iter+CALC_ONE];
			if(Calc_u8OperandsNum > CALC_ONE)
			{
				calc_voidShift_num(Local_u8iter+CALC_ONE);
				calc_voidShift_op(Local_u8iter);
				Local_u8iter = CALC_ZERO;
			}
		}

		if(Calc_Au8Op_Arr[Local_u8iter] != '+' && Calc_Au8Op_Arr[Local_u8iter] != '-')
			Local_u8iter++;
	}
	}

}


void calc_voidShift_num(u8 Copy_u8Position)
{
	int iter;
	for(iter = Copy_u8Position; iter < Calc_u8OperandsNum - CALC_ONE; iter++)
	{
		Calc_Au32NumArr[iter] = Calc_Au32NumArr[iter+CALC_ONE];
	}
	Calc_u8OperandsNum--;
}

void calc_voidShift_op(u8 Copy_u8Position)
{
	int iter;
	for(iter = Copy_u8Position; iter < Calc_u8OperatorsNum - CALC_ONE; iter++)
	{
		Calc_Au8Op_Arr[iter] = Calc_Au8Op_Arr[iter+CALC_ONE];
	}
	Calc_u8OperatorsNum--;
}
