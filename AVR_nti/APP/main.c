
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
	/*
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

	*/

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
