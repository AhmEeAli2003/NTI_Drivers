/*
 * EXTI_int.h
 *
 *  Created on: ٢٨‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

#include "EXTI_config.h"

ES_t EXTI_enuInit(EXTI_t * Copy_pstrEXTIConfig);

ES_t EXTI_enuSetSenceMode(u8 Copy_u8EXTI_ID, u8 Copy_u8SenceLevel);

ES_t EXTI_enuEnableINT(u8 Copy_u8EXTI_ID);

ES_t EXTI_enuDisableINT(u8 Copy_u8EXTI_ID);

ES_t EXTI_enuCallBack(void (*Copy_pfunAppFun)(void *), void * Copy_pvoidParameter, u8 Copy_u8EXTI_ID);


#define EXTI_RISING_EDGE	 1
#define EXTI_FALLING_EDGE    2
#define EXTI_ANY_LOGIC       3
#define EXTI_LOW_LEVEL       4

#define EXTI_INT0     0
#define EXTI_INT1     1
#define EXTI_INT2     2
#endif /* MCAL_EXTI_EXTI_INT_H_ */
