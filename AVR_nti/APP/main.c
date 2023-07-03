
/** main of SSD Linking Time configuration **/

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
		/*
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
		}*/
		/** POV (96) On two SSD**/
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
