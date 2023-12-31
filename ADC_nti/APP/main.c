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
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/EXTI/EXTI_int.h"

#include "../HAL/LCD/LCD_int.h"
#include "../HAL/LED/LED_config.h"
#include "../HAL/LED/LED_int.h"
#include "../HAL/THERM/THERM_config.h"
#include "../HAL/THERM/THERM_int.h"
#include <util/delay.h>

/** LM35 Sensor Code before edit Driver **/
/*
extern LED_t LED_AstrLedConfiguration[LED_NUM];

int main(void)
{
	u16 Local_ADC_DATA = 0;
	f32 Local_DATA_Modifided = 0;

	ADC_enuInit();
	LCD_enuInit();
	LED_enuInit(LED_AstrLedConfiguration);

	DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8INPUT);
	DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8FLOAT);

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

		if(Local_DATA_Modifided > 2500.0f && Local_DATA_Modifided < 5000.0f)
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
/** Test ADC driver after updates **/
/*
extern EXTI_t EXTI_AstrEXTIConfig[3];

u8 flag;

void Read(void *p)
{
	ADC_enuADCRead((u16 *) p);
	flag = 1;
}
int main(void)
{
	u8 Local_ADCRead = 0;
	u16 Local_ADC16 = 0;

	//DIO_enuSetPortDirection(DIO_u8PORTC, 0xff);
	//DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN2, DIO_u8INPUT);
	LCD_enuInit();
	DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN2, DIO_u8INPUT);

	EXTI_enuInit(EXTI_AstrEXTIConfig);
	EXTI_enuSetSenceMode(EXTI_INT0, EXTI_FALLING_EDGE);
	EXTI_enuEnableINT(EXTI_INT0);

	ADC_enuInit();
	ADC_enuSelectChannel(ADC_u8ADC2);
	ADC_enuEnableTriggeringMode(ADC_u8EXTI_0_TRIG);
	ADC_enuEnableINTMode();
	ADC_enuCallBack(Read, &Local_ADC16);
	ADC_enuEnable();
	ADC_enuStartConversion();

	GIE_enuEnable();

	while(1)
	{
		if(flag == 1)
		{
			LCD_enuSendCommand(LCD_u8CLEAR_LCD);
			LCD_enuDisplayNumber((Local_ADC16 * 4.88) / 10);
			flag = 0;
		}
	}
	return 0;
}
*/

/** Test THERM Driver */
extern THERM_t THERM_AstrThermistorsConfig[THERM_NUM];

int main(void)
{
	f32 Local_f32Read = 0, Local_f32Read_1 = 0;

	THERM_enuInit(THERM_AstrThermistorsConfig);
	LCD_enuInit();
	LCD_enuSendCommand(LCD_u8HIDE_CURSOR_AND_BLINKING);

	while(1)
	{
		THERM_enuGetTemp(&THERM_AstrThermistorsConfig[0], &Local_f32Read);
		THERM_enuGetTemp(&THERM_AstrThermistorsConfig[1], &Local_f32Read_1);

		LCD_enuSendCommand(LCD_u8CLEAR_LCD);

		LCD_enuDisplayNumber(Local_f32Read - Local_f32Read_1);
	}
	return 0;
}
