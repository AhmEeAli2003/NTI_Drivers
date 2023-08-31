/*
 * EXTI_int.h
 *
 *  Created on: ٢٨‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

ES_t EXTI_enuInit(EXTI_t * Copy_pstrEXTIConfig);

ES_t EXTI_enuSetSenceMode(u8 Copy_u8EXTI_ID, u8 Copy_u8SenceLevel);

ES_t EXTI_enuEnableINT(u8 Copy_u8EXTI_ID);

ES_t EXTI_enuDisableINT(u8 Copy_u8EXTI_ID);

ES_t EXTI_enuCallBack(volatile void (*Copy_pfunAppFun)(volatile void *), void * Copy_pvoidParameter, u8 Copy_u8EXTI_ID);
#endif /* MCAL_EXTI_EXTI_INT_H_ */
