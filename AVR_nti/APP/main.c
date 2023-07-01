/*
 * main.c
 *
 *  Created on: ٢٦‏/٠٦‏/٢٠٢٣
 *      Author: Ahmed
 */


/** Main of LED **/
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

