/*
 * MOTOR_int.h
 *
 *  Created on: ٠٥‏/٠٩‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef HAL_MOTOR_MOTOR_INT_H_
#define HAL_MOTOR_MOTOR_INT_H_

#include "MOTOR_private.h"

ES_t MOTOR_enuInit(MOTOR_t *Copy_pAstrMotorConfig);

ES_t MOTOR_enuSetSpeedRatio(MOTOR_t *Copy_pstrMotorID, u8 Copy_u8SpeedRatio);

#endif /* HAL_MOTOR_MOTOR_INT_H_ */
