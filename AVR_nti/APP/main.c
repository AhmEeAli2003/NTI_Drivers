
/** 	Main of LCD 	**/
#include "../LIB/STD_TYPES.h"
#include "../LIB/ERROR_STATE.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LCD/LCD_int.h"
#include <util/delay.h>

int main(void)
{
	LCD_enuInit();
	/*
	LCD_enuDisplayChar('A');
	LCD_enuDisplayChar('h');
	LCD_enuDisplayChar('m');
	LCD_enuDisplayChar('e');
	LCD_enuDisplayChar('d');
	*/
	LCD_enuSetPosition(6,1);
	LCD_enuSendString((u8 *)"Ahmed"); //To avoid warning
	LCD_enuSetPosition(7,2);
	LCD_enuSendString((u8 *)"Ali");
	_delay_ms(3000);
	LCD_enuSendCommand(0x01); //Clear Display

	while(1);
	return 0;
}
