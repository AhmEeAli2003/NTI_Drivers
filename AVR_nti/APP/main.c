/*
 * main.c
 *
 *  Created on: ٢٦‏/٠٦‏/٢٠٢٣
 *      Author: Ahmed
 */

/** main of SSD Pre Compile configuration **/
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




