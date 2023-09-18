/*
 * MOTOR_config.c
 *
 *  Created on: ٠٥‏/٠٩‏/٢٠٢٣
 *      Author: Ahmed
 */
#include "../../LIB/STD_TYPES.h"
#include "MOTOR_config.h"
#include "MOTOR_private.h"

u8 Motors_num = MOTORS_NUM;

MOTOR_t MOTOR_AstrMotorConfig[MOTORS_NUM] =
{
		{MOTOR_OC0, 100}
};
