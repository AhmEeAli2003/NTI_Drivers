/*
 * MOTOR_private.h
 *
 *  Created on: ٠٥‏/٠٩‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef HAL_MOTOR_MOTOR_PRIVATE_H_
#define HAL_MOTOR_MOTOR_PRIVATE_H_

typedef struct
{
	u8 MOTOR_u8OCPin;
	u8 MOTOR_u8InitSpeedRatio;
}MOTOR_t;

#define MOTOR_OC0     0
#define MOTOR_OC1A    1
#define MOTOR_OC1B    2
#define MOTOR_OC2     3

#endif /* HAL_MOTOR_MOTOR_PRIVATE_H_ */
