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
#define ADC_DATA 	*((volatile u16*) 0x24)

#define ADC_AREF_VREF      1
#define ADC_AVCC_VREF      2
#define ADC_INTERNAL_VREF  3

#define ADC_RIGHT_ADJUST   1
#define ADC_LEFT_ADJUST    2

#define ADC_ADC0		   1
#define ADC_ADC1		   2
#define ADC_ADC2		   3
#define ADC_ADC3		   4
#define ADC_ADC4		   5
#define ADC_ADC5		   6
#define ADC_ADC6		   7
#define ADC_ADC7		   8

#define ADC_PRESCALER_2			1
#define ADC_PRESCALER_4			2
#define ADC_PRESCALER_8			3
#define ADC_PRESCALER_16		4
#define ADC_PRESCALER_32        5
#define ADC_PRESCALER_64        6
#define ADC_PRESCALER_128       7

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
