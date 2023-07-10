/*
 * Keypad_config.h
 *
 *  Created on: ٠٩‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

/** Set values of keypad **/
#define KPAD_ARR_VAL {{7,8,9,'/'},{4,5,6,'*'},{1,2,3,'-'},{'c',0,'=','+'}}
/** Set value to return it when no key pressed [must be greater than 16]**/

#define NO_PRESSED_KEY  0xFF

#define ROW1_PORT	DIO_u8PORTA
#define ROW1_PIN	DIO_u8PIN4

#define ROW2_PORT	DIO_u8PORTA
#define ROW2_PIN	DIO_u8PIN5

#define ROW3_PORT	DIO_u8PORTA
#define ROW3_PIN	DIO_u8PIN6

#define ROW4_PORT	DIO_u8PORTA
#define ROW4_PIN	DIO_u8PIN7

#define COL1_PORT	DIO_u8PORTB
#define COL1_PIN	DIO_u8PIN0

#define COL2_PORT	DIO_u8PORTB
#define COL2_PIN	DIO_u8PIN1

#define COL3_PORT	DIO_u8PORTB
#define COL3_PIN	DIO_u8PIN2

#define COL4_PORT	DIO_u8PORTB
#define COL4_PIN	DIO_u8PIN3


#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
