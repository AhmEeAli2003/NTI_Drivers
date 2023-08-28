/*
 * ADC_private.h
 *
 *  Created on: ٠٩‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define ADMUX		*((volatile u8*) 0x27)
#define ADCSRA  	*((volatile u8*) 0x26)
#define ADCH        *((volatile u8*) 0x25)
#define ADCL        *((volatile u8*) 0x24)
#define SFIOR       *((volatile u8*) 0x50)

#define ADC_AREF_VREF      0
#define ADC_AVCC_VREF      1
#define ADC_INTERNAL_VREF  2

#define ADC_RIGHT_ADJUST   1
#define ADC_LEFT_ADJUST    2

#define ADC_ADC0		   0
#define ADC_ADC1		   1
#define ADC_ADC2		   2
#define ADC_ADC3		   3
#define ADC_ADC4		   4
#define ADC_ADC5		   5
#define ADC_ADC6		   6
#define ADC_ADC7		   7

#define ADC_PRESCALER_2			1
#define ADC_PRESCALER_4			2
#define ADC_PRESCALER_8			3
#define ADC_PRESCALER_16		4
#define ADC_PRESCALER_32        5
#define ADC_PRESCALER_64        6
#define ADC_PRESCALER_128       7

#define ADC_FREE_RUNNING        90
#define ADC_EXTI_0_TRIG         80
#define ADC_ANALOG_COMP         70
#define ADC_TIM0_CTC            60
#define ADC_TIM0_OV             50
#define ADC_TIM1_CTCB           40
#define ADC_TIM1_OV             30
#define ADC_TIM1_CAPTUR         20



#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
