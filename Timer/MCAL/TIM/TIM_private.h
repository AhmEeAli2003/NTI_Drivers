/*
 * TIM_private.h
 *
 *  Created on: ٣٠‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef MCAL_TIM_TIM_PRIVATE_H_
#define MCAL_TIM_TIM_PRIVATE_H_

#define OVF       			0
#define CTC       			1
#define FAST_PWM  			2
#define PHASE_CORRECT_PWM   3

#define DISCONNECTED  0
#define TOG_OC		  1
#define CLR_OC		  2
#define SET_OC        3

#define TIMSK     *((u8*) 0x59)
#define TIFR      *((u8*) 0x58)

#define TCCR0     *((u8*) 0x53)
#define TCNT0     *((u8*) 0x52)
#define OCR0     *((u8*) 0x5C)

#endif /* MCAL_TIM_TIM_PRIVATE_H_ */
