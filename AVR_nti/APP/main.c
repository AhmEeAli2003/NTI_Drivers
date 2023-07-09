
/** Main of Keypad **/
#include "../LIB/STD_TYPES.h"
#include "../LIB/ERROR_STATE.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/Keypad/Keypad_int.h"
#include "../HAL/LCD/LCD_int.h"

int main(void)
{
	u8 Local_u8KeyPressed = 0, Local_u8Counter = 0;
	LCD_enuInit();
	KPAD_enuInit();

	while(1)
	{
		/* Polling (Stop every thing in application until keypad pressed)*/
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
	return 0;
}
