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
#include <util/delay.h>
/*********************      Includes Section End    *********************/

/*********************      Globals Section Start    *********************/
typedef struct
{
	u8 Flag_1BitIsFirstDigit:1;
	u8 Flag_1BitIsFirstPressed:1;
	u8 Flag_1BitIsLineTwoUsed:1;
	u8 Flag_1BitIsUpperTwo:1;
}FLAGS_t;

u8  Calc_u8OperandsNum, Calc_u8OperatorsNum, Calc_Au8Op_Arr[8];
u32 Calc_Au32NumArr[9], Calc_u32InputNum;
/*********************      Globals Section End    *********************/

/*********************      Prototypes Section Start    *********************/
void getOperandsNum(void);
void calculation(void);
void shift_num(unsigned int pos);
void shift_op(unsigned int pos);
/*********************      Prototypes Section Start    *********************/

int main(void)
{
	u8 Local_u8KeyPressed = 0, Local_u8OperandIndex = 0, Local_u8OeratorIndex = 0, Local_u8CharCounter = 0;

	FLAGS_t my_flags = {.Flag_1BitIsFirstDigit = 1, .Flag_1BitIsFirstPressed = 1, .Flag_1BitIsLineTwoUsed = 0};
	LCD_enuInit();
	KPAD_enuInit();

	LCD_enuSendCommand(0x0C); //Hide Cursor
	LCD_enuSendString((u8 *) "Multi operands");
	LCD_enuSetPosition(2, 6);
	LCD_enuSendString((u8 *) "Mode");
	_delay_ms(1000);
	LCD_enuSendCommand(0x01); //Clear LCD



	while(1)
	{
		getOperandsNum();
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


				if(my_flags.Flag_1BitIsFirstDigit)
				{
					Calc_u32InputNum = Local_u8KeyPressed;
					my_flags.Flag_1BitIsFirstDigit = 0;
				}
				else
				{
					Calc_u32InputNum = (Calc_u32InputNum * 10) + Local_u8KeyPressed;
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
				my_flags.Flag_1BitIsFirstDigit = 1;
			}


			if(Local_u8CharCounter == 16)
			{
				LCD_enuSendCommand(0xC0); //Go to second line
				my_flags.Flag_1BitIsLineTwoUsed = 1;
			}

			if(Local_u8OperandIndex == Calc_u8OperandsNum) break;
		}

		calculation();
		if(!my_flags.Flag_1BitIsLineTwoUsed)
		{
			LCD_enuSetPosition(2, 1);
			LCD_enuDisplayChar('=');
		}

		LCD_enuDisplayNumber(Calc_Au32NumArr[0]);

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
			Local_u8CharCounter = 0;
			Local_u8OeratorIndex = 0;
			Local_u8OperandIndex = 0;

			break;
		}
		else
		{
			if(my_flags.Flag_1BitIsFirstPressed)
			{
				LCD_enuSetPosition(1, 1);
				LCD_enuSendString((u8 *)"Press ON/C to clear display!");
				my_flags.Flag_1BitIsFirstPressed = 0;
			}
		}
		}

	}

	return 0;
}

void getOperandsNum(void)
{
	u8 Local_u8KeyPressed = 0;

	LCD_enuSendCommand(0x01);
	LCD_enuSendString((u8 *) "Enter No.Operands");
	LCD_enuSetPosition(2, 1);
	LCD_enuSendString((u8 *) "up to 9: ");
	/* Polling (Stop every thing in application until keypad pressed)*/
	do
	{
		KPAD_enuGetPassedKey(&Local_u8KeyPressed);

	}while(Local_u8KeyPressed == 0xFF); //there isn't any Key pressed

	if(Local_u8KeyPressed >= 2 && Local_u8KeyPressed <= 9)
	{
		LCD_enuDisplayNumber(Local_u8KeyPressed);
		_delay_ms(250);
		Calc_u8OperandsNum = Local_u8KeyPressed;
		Calc_u8OperatorsNum = Calc_u8OperandsNum - 1;
	}
	else
	{
		LCD_enuSendCommand(0x01);
		LCD_enuSendString((u8 *) "Invalid Input!");
		_delay_ms(1000);
		getOperandsNum();
	}
	LCD_enuSendCommand(0x01);
}

void calculation(void)
{
	u8 Local_u8iter = 0;
	while(Calc_u8OperandsNum > 1)
	{
	/* Multiply Operations */
	for(Local_u8iter = 0; Local_u8iter < Calc_u8OperatorsNum;)
	{
		if(Calc_Au8Op_Arr[Local_u8iter] == '*')
		{
			Calc_Au32NumArr[Local_u8iter] = Calc_Au32NumArr[Local_u8iter] * Calc_Au32NumArr[Local_u8iter+1];
			if(Calc_u8OperandsNum > 1)
			{
				shift_num(Local_u8iter+1);
				shift_op(Local_u8iter);
				Local_u8iter = 0;
			}
		}

		if(Calc_Au8Op_Arr[Local_u8iter] == '/')
		{
			if(Calc_Au32NumArr[Local_u8iter+1] != 0)
			{
				Calc_Au32NumArr[Local_u8iter] = Calc_Au32NumArr[Local_u8iter] / Calc_Au32NumArr[Local_u8iter+1];
			}
			else
			{
				LCD_enuSetPosition(2, 1);
				LCD_enuSendString((u8 *)"Math Error!");
				_delay_ms(500);
				main();
			}

			if(Calc_u8OperandsNum > 1)
			{
				shift_num(Local_u8iter+1);
				shift_op(Local_u8iter);
				Local_u8iter = 0;
			}
		}

		if(Calc_Au8Op_Arr[Local_u8iter] != '*' && Calc_Au8Op_Arr[Local_u8iter] != '/')
			Local_u8iter++;
	}

	for(Local_u8iter = 0; Local_u8iter < Calc_u8OperatorsNum;)
	{
		if(Calc_Au8Op_Arr[Local_u8iter] == '+')
		{
			Calc_Au32NumArr[Local_u8iter] = Calc_Au32NumArr[Local_u8iter] + Calc_Au32NumArr[Local_u8iter+1];
			if(Calc_u8OperandsNum > 1)
			{
				shift_num(Local_u8iter+1);
				shift_op(Local_u8iter);
				Local_u8iter = 0;
			}
		}

		if(Calc_Au8Op_Arr[Local_u8iter] == '-')
		{
			Calc_Au32NumArr[Local_u8iter] = Calc_Au32NumArr[Local_u8iter] - Calc_Au32NumArr[Local_u8iter+1];
			if(Calc_u8OperandsNum > 1)
			{
				shift_num(Local_u8iter+1);
				shift_op(Local_u8iter);
				Local_u8iter = 0;
			}
		}

		if(Calc_Au8Op_Arr[Local_u8iter] != '+' && Calc_Au8Op_Arr[Local_u8iter] != '-')
			Local_u8iter++;
	}
	}

}


void shift_num(unsigned int pos)
{
	int i;
	for(i = pos; i < Calc_u8OperandsNum - 1; i++)
	{
		Calc_Au32NumArr[i] = Calc_Au32NumArr[i+1];
	}
	Calc_u8OperandsNum--;
}

void shift_op(unsigned int pos)
{
	int i;
	for(i = pos; i < Calc_u8OperatorsNum - 1; i++)
	{
		Calc_Au8Op_Arr[i] = Calc_Au8Op_Arr[i+1];
	}
	Calc_u8OperatorsNum--;
}
