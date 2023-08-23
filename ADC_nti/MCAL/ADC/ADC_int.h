/*
 * ADC_int.h
 *
 *  Created on: ٠٩‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

#define ADC_u8ADC0		   0
#define ADC_u8ADC1		   1
#define ADC_u8ADC2		   2
#define ADC_u8ADC3		   3
#define ADC_u8ADC4		   4
#define ADC_u8ADC5		   5
#define ADC_u8ADC6		   6
#define ADC_u8ADC7		   7


#define ADC_u8FREE_RUNNING        90
#define ADC_u8EXTI_0_TRIG         80
#define ADC_u8ANALOG_COMP         70
#define ADC_u8TIM0_CTC            60
#define ADC_u8TIM0_OV             50
#define ADC_u8TIM1_CTCB           40
#define ADC_u8TIM1_OV             30
#define ADC_u8TIM1_CAPTUR         20

#define ADC_u8AREF_VREF      0
#define ADC_u8AVCC_VREF      1
#define ADC_u8INTERNAL_VREF  2

ES_t ADC_enuInit(void);

ES_t ADC_enuEnable(void);

ES_t ADC_enuDisble(void);

ES_t ADC_enuSetVref(u8 Copy_u8Source);

ES_t ADC_enuStartConversion(void);

ES_t ADC_enuPollingSystem(void);

ES_t ADC_enuReadHighValue(u8 *Copy_pu8Value);

ES_t ADC_enuADCRead(u16 *Copy_pu16Result);

ES_t ADC_enuCallBack(void (*Copy_pfunAppFun)(void *), void *Copy_pvoidAppParam);

ES_t ADC_enuSelectChannel(u8 Copy_u8ChannelID);

ES_t ADC_enuEnableTriggeringMode(u8 Copy_u8TriggeringSource);

ES_t ADC_enuDisableTriggeringMode(void);

ES_t ADC_enuEnableINTMode(void);

ES_t ADC_enuDisbleINTMode(void);

#endif /* MCAL_ADC_ADC_INT_H_ */
