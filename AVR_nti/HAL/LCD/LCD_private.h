/*
 * LCD_private.h
 *
 *  Created on: ٠٦‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

#define EIGHT_BIT   5
#define FOUR_BIT    6

static void LCD_voidLatch(u8 Copy_u8Data);
static inline void LCD_invoidSendCommand(u8 Copy_u8Command);


#endif /* HAL_LCD_LCD_PRIVATE_H_ */
