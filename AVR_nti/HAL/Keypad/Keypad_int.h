/*
 * Keypad_int.h
 *
 *  Created on: ٠٩‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef HAL_KEYPAD_KEYPAD_INT_H_
#define HAL_KEYPAD_KEYPAD_INT_H_

ES_t KPAD_enuInit(void);

ES_t KPAD_enuGetPassedKey(u8 *Copy_pu8KeyNumber);

#define KPAD_u8NO_KEY_PRESSED      0xFF

#endif /* HAL_KEYPAD_KEYPAD_INT_H_ */
