/*
 * main.c
 *
 *  Created on: ١٢‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/ERROR_STATE.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/LED/LED_config.h"
#include "../HAL/LED/LED_int.h"
#include <util/delay.h>

extern LED_t LED_AstrLedConfiguration[LED_NUM];

int main(void)
{
	u16 Local_ADC_DATA = 0;
	f32 Local_DATA_Modifided = 0;

	ADC_enuInit();
	LCD_enuInit();
	LED_enuInit(LED_AstrLedConfiguration);

	LCD_enuSendCommand(0x0C); //Hide Cursor and turn off blinking of cursor position
	LCD_enuSendString((u8 *) "Temp: ");
	LCD_enuSetPosition(1, 12);
	LCD_enuDisplayChar('C');

	while(1)
	{
		ADC_enuADCRead(&Local_ADC_DATA);

		Local_DATA_Modifided = (Local_ADC_DATA * (5000UL)) / 1024.0f;


		LCD_enuSetPosition(1, 7);

		LCD_enuDisplayNumber((u32)Local_DATA_Modifided / 10);
		LCD_enuDisplayChar('.');
		LCD_enuDisplayNumber((u32)Local_DATA_Modifided % 10);

		//_delay_ms(250);

		//LCD_enuSendCommand(0x01);

		//Condition of LM35
		DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN5, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN4, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN3, DIO_u8OUTPUT);

		if(Local_DATA_Modifided / 10 <= 30)
		{
			DIO_enuSetPinValue(DIO_u8PORTD, DIO_u8PIN5, DIO_u8HIGH);
			DIO_enuSetPinValue(DIO_u8PORTD, DIO_u8PIN4, DIO_u8LOW);
			DIO_enuSetPinValue(DIO_u8PORTD, DIO_u8PIN3, DIO_u8LOW);
		}
		else if(Local_DATA_Modifided / 10 > 30 && Local_DATA_Modifided / 10 <= 60)
		{
			DIO_enuSetPinValue(DIO_u8PORTD, DIO_u8PIN5, DIO_u8LOW);
			DIO_enuSetPinValue(DIO_u8PORTD, DIO_u8PIN4, DIO_u8HIGH);
			DIO_enuSetPinValue(DIO_u8PORTD, DIO_u8PIN3, DIO_u8LOW);
		}
		else
		{
			DIO_enuSetPinValue(DIO_u8PORTD, DIO_u8PIN5, DIO_u8LOW);
			DIO_enuSetPinValue(DIO_u8PORTD, DIO_u8PIN4, DIO_u8LOW);
			DIO_enuSetPinValue(DIO_u8PORTD, DIO_u8PIN3, DIO_u8HIGH);
		}
		//Condition of potentiometer
		/*
		if(Local_DATA_Modifided > 2500.0f && Local_DATA_Modifided < 5000.0f)
		{
			LED_enuTurnON(&LED_AstrLedConfiguration[0]);
			LED_enuTurnOFF(&LED_AstrLedConfiguration[1]);
		}
		else
		{
			LED_enuTurnOFF(&LED_AstrLedConfiguration[0]);
			LED_enuTurnON(&LED_AstrLedConfiguration[1]);
		}*/

	}

	return 0;
}


