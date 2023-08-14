/*
 * main.c
 *
 *  Created on: ٢٦‏/٠٦‏/٢٠٢٣
 *      Author: Ahmed
 */

/** main of DIO **/
/*
#include "../MCAL/DIO/DIO_int.h"
#include <util/delay.h>

int main(void)
{
	u8 common_cathode_numbers_arr[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
									   0x6D, 0x7D, 0x07, 0x7F, 0x6F
									  }, i, j;
	DIO_enuInit();

	while(1)
	{
		for(i = 0; i < 10; i++)
		{
			DIO_enuSetPortValue(DIO_u8PORTB, common_cathode_numbers_arr[0]);
			DIO_enuSetPortValue(DIO_u8PORTA, common_cathode_numbers_arr[i]);

			for(j = 0; j < 10; j++)
			{
				DIO_enuSetPortValue(DIO_u8PORTB, common_cathode_numbers_arr[j]);
				_delay_ms(500);
			}

		}
	}

	return 0;
}
*/
/** main of switch **/
/*
#include "../HAL/Switch/Switch_int.h"
#include "../HAL/Switch/Switch_config.h"
#include "../MCAL/DIO/DIO_int.h"


extern SW_t Switch_AstrSwitchState[SW_NUM];

int main(void)
{
	DIO_enuInit();
	Switch_enuInit(Switch_AstrSwitchState);
	u8 Local_u8pinState = 0;

	while(1)
	{
		Switch_enuGetState(&Switch_AstrSwitchState[1], &Local_u8pinState);

		if(Local_u8pinState == 0)
		{
			DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8HIGH);
		}
		else
		{
			DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8LOW);
		}
	}
	return 0;
}
*/
/** Main of LED **/
/*
#include "../LIB/STD_TYPES.h"
#include "../LIB/ERROR_STATE.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LED/LED_int.h"
#include "../HAL/LED/LED_config.h"
#include "../HAL/Switch/Switch_config.h"
#include "../HAL/Switch/Switch_int.h"
#include <util/delay.h>

extern LED_t LED_AstrLedConfiguration[LED_NUM];
extern SW_t Switch_AstrSwitchState[SW_NUM];

int main(void)
{
	DIO_enuInit();
	LED_enuInit(LED_AstrLedConfiguration);
	Switch_enuInit(Switch_AstrSwitchState);
	//_delay_ms(2000); //For Debug init state

	u8 Local_u8PinState = 0;

	while(1)
	{
		Switch_enuGetState(&Switch_AstrSwitchState[1], &Local_u8PinState);

		if(Local_u8PinState == 0)
		{
			LED_enuTurnON(&LED_AstrLedConfiguration[0]);
			LED_enuTurnOFF(&LED_AstrLedConfiguration[1]);
		}
		else
		{
			LED_enuTurnOFF(&LED_AstrLedConfiguration[0]);
			LED_enuTurnON(&LED_AstrLedConfiguration[1]);
		}
	}

	return 0;
}
*/
/** main of SSD Pre Compile configuration **/
/*
#include "../LIB/STD_TYPES.h"
#include "../LIB/ERROR_STATE.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/SSD/SSD_int.h"
#include <util/delay.h>

int main(void)
{
	u8 Local_u8Iterator = 0;
	ES_t Local_enuSSDErrorRet;
	DIO_enuInit();
	Local_enuSSDErrorRet = SSD_enuInit();


	while(1)
	{

		if(Local_enuSSDErrorRet == ES_OK) //For Debug Init Function
		{
			for(Local_u8Iterator = 0; Local_u8Iterator < 10; Local_u8Iterator++)
			{
				SSD_enuDisplayNum(Local_u8Iterator);
				_delay_ms(500);
				if(SSD_enuClearDisplay() == ES_OK) //For Debug Clear Function
				{
					_delay_ms(500);
				}
			}
		}

	}
	return 0;
}
*/
/** main of SSD Linking Time configuration **/
/*
#include "../LIB/STD_TYPES.h"
#include "../LIB/ERROR_STATE.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/SSD_LT/SSDLT_int.h"
#include "../HAL/SSD_LT/SSDLT_config.h"
#include "../HAL/SSD_LT/SSDLT_private.h"
#include <util/delay.h>

extern SEG_t SSD_AstrSegConfig[SEG_NUM];

int main(void)
{
	ES_t Local_u8CheckError = ES_NOK;
	ES_t Local_u8CheckError_1 = ES_NOK;
	DIO_enuInit();
	Local_u8CheckError = SSDLT_enuInit(SSD_AstrSegConfig);
	SSDLT_enuEnableDot(1);


	while(1)
	{
		//Comment This
		if(Local_u8CheckError == ES_OK)
		{
		for(u8 i = 0; i < 10; i++)
		{
			SSDLT_enuDisplayNum(1, i);

			for(u8 j = 0; j < 10; j++)
			{
				SSDLT_enuDisplayNum(0, j);
				_delay_ms(300);
			}
			Local_u8CheckError_1 = SSDLT_enuClearDisplay(1); //This will disable DOT as low level design for it
			_delay_ms(500);
			if(Local_u8CheckError_1 == ES_OK)
			{
				SSDLT_enuDisplayNum(1, i+1);
				_delay_ms(500);
				SSDLT_enuClearDisplay(1);
				_delay_ms(500);
			}
		}
		}
		//or comment this
		//POV (96) On two SSD
		SSDLT_enuDisableCommon(0);
		SSDLT_enuDisplayNum(0, 9);
		SSDLT_enuEnableCommon(0);
		_delay_ms(10);

		SSDLT_enuDisableCommon(0);
		SSDLT_enuDisplayNum(1, 6);
		SSDLT_enuEnableCommon(1);
		_delay_ms(10);
		SSDLT_enuDisableCommon(1);




	}
	return 0;
}
*/

/** 	Main of LCD 	**/

#include "../LIB/STD_TYPES.h"
#include "../LIB/ERROR_STATE.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LCD/LCD_int.h"
#include <util/delay.h>

int main(void)
{
	//u8 custom_char[8] = {0x07, 0x0E, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04}; //'أ'
	u8 custom_char_1[8] = {0x0E,  0x0A, 0x11, 0x11, 0x11, 0x11, 0x1F, 0x00};
	u8 custom_char_2[8] = {0x0E,  0x0A, 0x11, 0x11, 0x11, 0x1F, 0x1F, 0x00};
	u8 custom_char_3[8] = {0x0E,  0x0A, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x00};
	u8 custom_char_4[8] = {0x0E,  0x0A, 0x11, 0x1F, 0x1F, 0x1F, 0x1F, 0x00};
	u8 custom_char_5[8] = {0x0E,  0x0A, 0x11, 0x1F, 0x1F, 0x1F, 0x1F, 0x00};
	u8 custom_char_6[8] = {0x0E,  0x0A, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00};
	u8 custom_char_7[8] = {0x0E,  0x0E, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00};
	LCD_enuInit();

	LCD_enuDisplayChar('A');
	LCD_enuDisplayChar('h');
	LCD_enuDisplayChar('m');
	LCD_enuDisplayChar('e');
	LCD_enuDisplayChar('d');

	LCD_enuSetPosition(1,1);
	LCD_enuSendString((u8 *)"Ahmed Ali Yusuf Abdulfattah"); //To avoid warning
	LCD_enuSetPosition(2,13);
	LCD_enuSendString((u8 *)"Ali");
	_delay_ms(3000);
	LCD_enuSendCommand(0x01); //Clear Display
	LCD_enuDisplayNumber(0);
	LCD_enuDisplayNumber(1);
	LCD_enuDisplayNumber(9);
	LCD_enuSetPosition(1,7);
	LCD_enuDisplayNumber(1004);
	_delay_ms(1000);
	LCD_enuSetPosition(2,1);
	LCD_enuDisplayNumber(4294967295);
	LCD_enuSendCommand(0x01); //Clear Display



	LCD_enuSendCommand(0x0c); //Cursor OFF

	LCD_enuSetPosition(2, 8);
	LCD_enuSendString((u8 *) "^_^");

	LCD_enuSetPosition(1, 15);
	_delay_ms(200);
	LCD_enuDisplayChar('%');
	_delay_ms(200);

	while(1)
	{
		LCD_enuDisplaySpecialChar(1, 16, custom_char_1);
		LCD_enuSetPosition(1, 13);
		LCD_enuSendString((u8 *) "00");
		_delay_ms(200);

		LCD_enuDisplaySpecialChar(1, 16, custom_char_2);
		LCD_enuSetPosition(1, 13);
		LCD_enuDisplayNumber(15);
		_delay_ms(200);

		LCD_enuDisplaySpecialChar(1, 16, custom_char_3);
		LCD_enuSetPosition(1, 13);
		LCD_enuDisplayNumber(30);
		_delay_ms(200);

		LCD_enuDisplaySpecialChar(1, 16, custom_char_4);
		LCD_enuSetPosition(1, 13);
		LCD_enuDisplayNumber(45);
		_delay_ms(200);

		LCD_enuDisplaySpecialChar(1, 16, custom_char_5);
		LCD_enuSetPosition(1, 13);
		LCD_enuDisplayNumber(60);
		_delay_ms(200);

		LCD_enuDisplaySpecialChar(1, 16, custom_char_6);
		LCD_enuSetPosition(1, 13);
		LCD_enuDisplayNumber(75);
		_delay_ms(200);

		LCD_enuDisplaySpecialChar(1, 16, custom_char_7);
		LCD_enuSetPosition(1, 13);
		LCD_enuDisplayNumber(99);
		_delay_ms(200);


	}
	return 0;
}


/** Main of Keypad **/
/*
#include "../LIB/STD_TYPES.h"
#include "../LIB/ERROR_STATE.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/Keypad/Keypad_int.h"
#include "../HAL/LCD/LCD_int.h"


int main(void)
{
	u8 Local_u8KeyPressed = 0, Local_u8Counter = 0, Local_u8Check = 0;
	LCD_enuInit();
	Local_u8Check = KPAD_enuInit();

	while(1)
	{
		if(Local_u8Check)
		{
		// Polling (Stop every thing in application until keypad pressed)
		do
		{
			KPAD_enuGetPassedKey(&Local_u8KeyPressed);


		}while(Local_u8KeyPressed == 0xff); //Key Not pressed


		if(Local_u8KeyPressed == 'c')
		{
			LCD_enuSendCommand(0x01); //Clear Display
			Local_u8Counter++;
		}
		else if(Local_u8KeyPressed >= 0 && Local_u8KeyPressed <= 9)
		{
			LCD_enuDisplayNumber(Local_u8KeyPressed);
			Local_u8Counter++;
		}
		else if((Local_u8KeyPressed >= '*' && Local_u8KeyPressed <= '/') || Local_u8KeyPressed == '=')
		{
			LCD_enuDisplayChar(Local_u8KeyPressed);
			Local_u8Counter++;
		}

		if(Local_u8Counter == 16)
		{
			LCD_enuSendCommand(0xC0); //Go to second line
		}
		}
	}
	return 0;
}

*/
/** Main of Interrupt**/
/*
#include "../LIB/STD_TYPES.h"
#include "../LIB/ERROR_STATE.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EXTI/EXTI_config.h"
#include "../MCAL/EXTI/EXTI_int.h"

void tog(void *Copy_pvoidParam);
extern EXTI_t EXTI_AstrEXTIConfig[3];
#define SREG  (*(volatile u8*) 0x5F)

int main(void)
{
	DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN2, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN2, DIO_u8INPUT);
	DIO_enuSetPinValue(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PULL_UP);

	u8 Local_u8Pin = DIO_u8PIN3;
	EXTI_enuCallBack(tog, &Local_u8Pin, 0);
	EXTI_enuInit(EXTI_AstrEXTIConfig);

	SREG |= (1<<7);

	while(1);

	return 0;
}

void tog(void *Copy_pvoidParam)
{
	DIO_enuSetPinDirection(DIO_u8PORTA, *((u8*)Copy_pvoidParam), DIO_u8OUTPUT);
	DIO_enuTogPinValue(DIO_u8PORTA, *((u8*)Copy_pvoidParam));
}
*/

