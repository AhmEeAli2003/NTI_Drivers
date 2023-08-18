/*
 * EXTI_private.h
 *
 *  Created on: ٢٨‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#define ACTIVE     5
#define DEACTIVE   6


#define RISING_EDGE		1
#define FALLING_EDGE    2
#define ANY_LOGIC       3
#define LOW_LEVEL       4

#define MCUCR            *((u8*) 0x55)
#define MCUCSR           *((u8*) 0x54)
#define GICR             *((u8*) 0x5B)
#define GIFR             *((u8*) 0x5A)

#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
