/*
 * main.c
 *
 *  Created on: ٢٩‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/ERROR_STATE.h"

#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/TIM/TIM_int.h"
#include "../MCAL/interrupt.h"
#include "../MCAL/EXTI/EXTI_config.h"
#include "../MCAL/EXTI/EXTI_int.h"

#include "../HAL/MOTOR/MOTOR_int.h"
#include "../HAL/LCD/LCD_int.h"

#define TCCR0     *((u8*) 0x53)
#define OCR0      *((u8*) 0x5C)
#define TIMSK     *((u8*) 0x59)
#define TCCR1A    *((u8 *) 0x4F)
#define TCCR1B    *((u8 *) 0x4E)
#define ICR1L     *((u8 *) 0x46)
#define ICR1H     *((u8 *) 0x47)
#define TCNT1L	  *((u8 *) 0x4C)
#define TCNT1H	  *((u8 *) 0x4D)
#define DDRB      *((u8 *) 0x37)


/*
enum
{
	start,
	on,
	off,
	end,
	disable
}state = start;

u16 timeon = 0, total = 0;

int main(void)
{
	LCD_enuInit();
	DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN6, DIO_u8INPUT);
	TCCR1A = 0x00;
	TCCR1B = 0x45;
	ICR1H = 0;
	ICR1L = 0;
	TCNT1H = 0;
	TCNT1L = 0;
	TIMSK |= (1<<5);
	GIE_enuEnable();

	while(1)
	{
		if(state == end)
		{
			f32 duty = (f32)timeon / total;
			f32 time = (f32)total * 1024.0 / 1000000UL;
			f32 freq = 1.0 / time;
			LCD_enuDisplayFloat(duty);
			LCD_enuSendCommand(LCD_u8GO_TO_SECOND_LINE);
			LCD_enuDisplayFloat(freq);
			state = disable;
		}
	}
	return 0;
}

ISR(VECT_TIMER1_CAPT)
{
	if(state == start)
	{
		ICR1H = 0;
		ICR1L = 0;
		TCNT1H = 0;
		TCNT1L = 0;
		TCCR1B = 0x05;
		state = on;
	}
	else if(state == on)
	{
		timeon = ICR1L;
		timeon |= ((u16)ICR1H << 8);
		TCCR1B = 0x45;
		state = off;
	}
	else if(state == off)
	{
		total = ICR1L;
		total |= ((u16)ICR1H << 8);
		TCCR1B = 0x00;
		state = end;
	}
}

*/
