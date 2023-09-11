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


#define TCCR0     *((u8*) 0x53)
#define OCR0     *((u8*) 0x5C)
#define TIMSK     *((u8*) 0x59)

/*
void Inc_OCR(void *);
extern EXTI_t EXTI_AstrEXTIConfig[];
*/

int main(void)
{
	/*
	u8 Local_u8OCRVal = 25;

	DIO_enuSetPinDirection(DIO_u8PORTB, DIO_u8PIN3, DIO_u8OUTPUT); //OC0 Pin
	EXTI_enuInit(EXTI_AstrEXTIConfig);
	EXTI_enuCallBack(Inc_OCR, &Local_u8OCRVal, 0);

	TCCR0 = 0x63;

	EXTI_enuEnableINT(0);
	GIE_enuEnable();
	*/
	TIM_enuInut();
	DIO_enuSetPinDirection(DIO_u8PORTB, DIO_u8PIN3, DIO_u8OUTPUT);
	while(1)
	{

		TIM_enuSetSynchDelayus(100000);
	}
	return 0;
}
/*
void Inc_OCR(void *param)
{
	if(*((u8*)param) < 250)
	{
		*((u8*)param) += 25;
	}
	else
	{
		*((u8*)param) = 25;
	}
}
*/
