/*
 * LCD_int.h
 *
 *  Created on: ٠٦‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

ES_t LCD_enuInit(void);

ES_t LCD_enuDisplayChar(u8 Copy_u8Char);

ES_t LCD_enuSendCommand(u8 Copy_u8Command);

ES_t LCD_enuSendString(u8 *Copy_pu8string);

ES_t LCD_enuSetPosition(u8 Copy_u8Column, u8 Copy_u8Row);

#endif /* HAL_LCD_LCD_INT_H_ */
