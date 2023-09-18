/*
 * TIM_prog.c
 *
 *  Created on: ٣٠‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"

#include "../interrupt.h"

#include "TIM_private.h"
#include "TIM_config.h"

static u32 TIM_Num_OVF = 0;
static u32 TIM_Preload = 0;

static void (*gptr)(void*) = NULL;
static void *gpara = NULL;

ES_t TIM_enuInut(void)
{
	ES_t Local_enuErrorState = ES_NOK;
#if TIM_PRES == 1024
	TCCR0 &= 0xF8; //Mask

	TCCR0 |= 0x05;
#elif TIM_PRES == 64
	TCCR0 &= 0xF8; //Mask

	TCCR0 |= 0x03;
#endif

#if TIM_MODE == OVF
	TCCR0 &= ~(1<<3);
	TCCR0 &= ~(1<<6);
#elif TIM_MODE == CTC
	TCCR0 |=  (1<<3);
	TCCR0 &= ~(1<<6);
#elif TIM_MODE == FAST_PWM
	TCCR0 |= (1<<3);
	TCCR0 |= (1<<6);
#elif TIM_MODE == PHASE_CORRECT_PWM
	TCCR0 &= ~(1<<3);
	TCCR0 |= (1<<6);
#endif

#if OC_MODE == DISCONNECTED
	TCCR0 &= ~(1<<4);
	TCCR0 &= ~(1<<5);
#elif OC_MODE == TOG_OC && TIM_MODE == CTC
	TCCR0 |=  (1<<4);
	TCCR0 &= ~(1<<5);
#elif OC_MODE == CLR_OC && (TIM_MODE == FAST_PWM || TIM_MODE == PHASE_CORRECT_PWM)
	TCCR0 &=  ~(1<<4);
	TCCR0 |= (1<<5);
#elif OC_MODE == SET_OC && (TIM_MODE == FAST_PWM || TIM_MODE == PHASE_CORRECT_PWM)
	TCCR0 |= (1<<4);
	TCCR0 |= (1<<5);
#endif

	return Local_enuErrorState;
}

ES_t TIM_enuSetPreload(u8 Copy_u8Preload)
{
	ES_t Local_enuErrorState = ES_NOK;

	TCNT0 = Copy_u8Preload;

	return Local_enuErrorState;
}

ES_t TIM_enuSetAsynchDelayms(u32 Copy_u32Time, void (*Copy_pfunApp)(void *), void *CopypvoidPara)
{
	ES_t Local_enuErrorState = ES_NOK;

	f32 Local_f32ovfTime = 256 * ((f32) TIM_PRES / TIM_F_CPU);

	f32 Local_f32NumOVF = (Copy_u32Time / Local_f32ovfTime);

	if ((Local_f32NumOVF - (u32)Local_f32NumOVF) != 0.0)
	{
		u32 Local_u32NumOVF_int = (u32)Local_f32NumOVF + 1;
		Local_f32NumOVF = Local_f32NumOVF - (u32) Local_f32NumOVF;
		u32 Local_u32Preload = 256 - (Local_f32NumOVF * 256);
		TIM_Num_OVF = Local_u32NumOVF_int;
		TIM_Preload = Local_u32Preload;
		TCNT0 = TIM_Preload;
	}
	else
	{
		TIM_Num_OVF = (u32)Local_f32NumOVF;
	}

	if(Copy_pfunApp != NULL)
	{
		gptr = Copy_pfunApp;
		gpara = CopypvoidPara;
	}

	TIMSK |= (1<<0);

	return Local_enuErrorState;
}

ES_t TIM_enuSetSynchDelayms(u32 Copy_u32Time)
{
	ES_t Local_enuErrorState = ES_NOK;

	TIMSK &= ~(1<<0); //Disable INT

	f32 Local_f32ovfTime = 256 * ((f32) TIM_PRES / TIM_F_CPU);

	f32 Local_f32NumOVF = (Copy_u32Time / Local_f32ovfTime);

	u32 Local_u32NumOVF_int = 0;

	if ((Local_f32NumOVF - (u32)Local_f32NumOVF) != 0.0)
	{
		Local_u32NumOVF_int = (u32)Local_f32NumOVF + 1;
		Local_f32NumOVF = Local_f32NumOVF - (u32) Local_f32NumOVF;
		u32 Local_u32Preload = 256 - (Local_f32NumOVF * 256);
		TCNT0 = Local_u32Preload;
		while(Local_u32NumOVF_int > 0)
		{
			while(((TIFR>>0) & 0x01) == 0);
			TIFR |= (1<<0); //Clear Flag
			Local_u32NumOVF_int--;
		}
	}
	else
	{
		while(Local_u32NumOVF_int > 0)
		{
			while(((TIFR>>0) & 0x01) == 0);
			TIFR |= (1<<0); //Clear Flag
			Local_u32NumOVF_int--;
		}
	}

	return Local_enuErrorState;
}

ES_t TIM_enuSetSynchDelayus(u32 Copy_u32Time)
{
	ES_t Local_enuErrorState = ES_NOK;

	TIMSK &= ~(1<<1); //Disable INT

	f32 Local_f32ovfTime = 256 * ((f32) TIM_PRES / TIM_F_CPU);

	f32 Local_f32Ratio = ((Copy_u32Time / 1000) / Local_f32ovfTime);

	u8 Local_u8OCRCounts = Local_f32Ratio * 256;

	OCR0 = Local_u8OCRCounts;

	return Local_enuErrorState;
}

ES_t TIM_enuSetAsynchDelayus(u32 Copy_u32Time, void (*Copy_pfunApp)(void *), void *CopypvoidPara)
{
	ES_t Local_enuErrorState = ES_NOK;

	f32 Local_f32ovfTime = 256 * ((f32) TIM_PRES / TIM_F_CPU);

	f32 Local_f32Ratio = ((Copy_u32Time / 1000) / Local_f32ovfTime);

	u8 Local_u8OCRCounts = Local_f32Ratio * 256;

	OCR0 = Local_u8OCRCounts;

	if(Copy_pfunApp != NULL)
	{
		gptr = Copy_pfunApp;
		gpara = CopypvoidPara;
	}

	TIMSK |= (1<<1); //Enable INT

	return Local_enuErrorState;
}

ES_t TIM_enuGenerateFastPWM(u8 Copy_u8DutyRatio)
{
	ES_t Local_enuErrorState = ES_NOK;

#if OC_MODE == CLR_OC
	OCR0 = (Copy_u8DutyRatio / 100.0) * 256;
#elif OC_MODE == SET_OC
	OCR0 = 255 - ((Copy_u8DutyRatio / 100.0) * 256);
#endif
	return Local_enuErrorState;
}

ES_t TIM_enuGeneratePhaseCorrectPWM(u8 Copy_u8DutyRatio)
{
	ES_t Local_enuErrorState = ES_NOK;

#if OC_MODE == CLR_OC
	OCR0 = (Copy_u8DutyRatio / 100.0) * 255;
#elif OC_MODE == SET_OC
	OCR0 = ((100 - Copy_u8DutyRatio) / 100.0) * 255;
#endif

	return Local_enuErrorState;
}
ISR(VECT_TIMER0_OVF)
{
	if(gptr != NULL)
	{
		static u32 counts = 0;
		counts++;
		if(counts == TIM_Num_OVF)
		{
			TCNT0 = TIM_Preload;
			gptr(gpara);
			counts = 0;
		}
	}
}

ISR(VECT_TIMER0_COMP)
{
	if(gptr != NULL)
	{
		gptr(gpara);
	}
}
