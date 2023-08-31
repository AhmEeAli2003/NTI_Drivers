/*
 * ADC_config.h
 *
 *  Created on: ٠٩‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

/**
 * Select Option:
 * - ADC_AREF_VREF
 * - ADC_AVCC_VREF
 * - ADC_INTERNAL_VREF
 */
#define ADC_VREF_SOURCE   ADC_AVCC_VREF

/**
 * Select Option:
 * - ADC_LEFT_ADJUST
 * - ADC_RIGHT_ADJUST
 */
#define ADC_ADJUST        ADC_RIGHT_ADJUST

/**
 * Select Option:
 *  - ADC_PRESCALER_2
 *	- ADC_PRESCALER_4
 *	- ADC_PRESCALER_8
 *	- ADC_PRESCALER_16
 *	- ADC_PRESCALER_32
 *	- ADC_PRESCALER_64
 *	- ADC_PRESCALER_128
 */
#define	ADC_PRESCALER	  ADC_PRESCALER_8


#endif /* MCAL_ADC_ADC_CONFIG_H_ */
