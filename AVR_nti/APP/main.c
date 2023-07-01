/*
 * main.c
 *
 *  Created on: ٢٦‏/٠٦‏/٢٠٢٣
 *      Author: Ahmed
 */

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

