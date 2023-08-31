/*
 * TIM_private.h
 *
 *  Created on: ٣٠‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef MCAL_TIM_TIM_PRIVATE_H_
#define MCAL_TIM_TIM_PRIVATE_H_

#define OVF    0
#define DISCONNECTED  0

#define TIMSK     *((u8*) 0x59)
#define TIFR      *((u8*) 0x58)

#define TCCR0     *((u8*) 0x53)
#define TCNT0     *((u8*) 0x52)


#endif /* MCAL_TIM_TIM_PRIVATE_H_ */
