/*
 * interrupt.h
 *
 *  Created on: ٢٨‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef MCAL_INTERRUPT_H_
#define MCAL_INTERRUPT_H_

#define ISR(VECT_NUM)	void VECT_NUM (void)__attribute__((signal));\
						void VECT_NUM (void)

#define VECT_INT0 			__vector_1
#define VECT_INT1 			__vector_2
#define VECT_INT2 			__vector_3
#define VECT_TIMER2_COMP	__vector_4
#define VECT_TIMER2_OVF     __vector_5
#define VECT_TIMER1_CAPT    __vector_6
#define VECT_TIMER1_COMAPA  __vector_7
#define VECT_TIMER1_COMAPB  __vector_8
#define VECT_TIMER1_OVF     __vector_9
#define VECT_TIMER0_COMP    __vector_10
#define VECT_TIMER0_OVF     __vector_11
#define VECT_SPI_STC        __vector_12
#define VECT_USART_RXC      __vector_13
#define VECT_USART_UDRE     __vector_14
#define VECT_USART_TXC      __vector_15
#define VECT_ADC            __vector_16
#define VECT_EE_RDY         __vector_17
#define VECT_ANA_COMP       __vector_18
#define VECT_TWI            __vector_19
#define VECT_SPM_RDY        __vector_20


#endif /* MCAL_INTERRUPT_H_ */
