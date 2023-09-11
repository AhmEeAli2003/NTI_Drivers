/*
 * TIM_int.h
 *
 *  Created on: ٣٠‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef MCAL_TIM_TIM_INT_H_
#define MCAL_TIM_TIM_INT_H_

ES_t TIM_enuInut(void);

ES_t TIM_enuSetPreload(u8 Copy_u8Preload);

ES_t TIM_enuSetAsynchDelay(u32 Copy_u32Time, void (*Copy_pfunApp)(void *), void *CopypvoidPara); //AsynchDelay : depends on ISR

ES_t TIM_enuSetSynchDelayms(u32 Copy_u32Time); //Synch : Depends on polling

ES_t TIM_enuSetSynchDelayus(u32 Copy_u32Time);

#endif /* MCAL_TIM_TIM_INT_H_ */
