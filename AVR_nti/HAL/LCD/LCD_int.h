/**
 ****************************************************************************************
 *   @file          : LCD_int.h
 *   @author        : Ahmed Ali
 *   @brief         : LCD Interface file consists prototypes of LCD APIs
 *	 @date			: 6 / 7 / 2023
 ****************************************************************************************
*/

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

/***********************	Prototypes Section	Start	***********************/
/**
 ****************************************************************************************
 *	@name			: LCD_enuInit
 *  @brief          : Initialize LCD.
 *  @param          : void
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t LCD_enuInit(void);

/**
 ****************************************************************************************
 *	@name			: LCD_enuDisplayChar
 *  @brief          : Display Char on LCD.
 *  @param          : u8 Copy_u8Char
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t LCD_enuDisplayChar(u8 Copy_u8Char);

/**
 ****************************************************************************************
 *	@name			: LCD_enuSendCommand
 *  @brief          : Send Command to LCD.
 *  @param          : u8 Copy_u8Command
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t LCD_enuSendCommand(u8 Copy_u8Command);

/**
 ****************************************************************************************
 *	@name			: LCD_enuSendString
 *  @brief          : Send String to LCD.
 *  @param          : u8 *Copy_pu8string
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t LCD_enuSendString(u8 *Copy_pu8string);

/**
 ****************************************************************************************
 *	@name			: LCD_enuSetPosition
 *  @brief          : Set position on LCD Screen.
 *  @param          : u8 Copy_u8Column, u8 Copy_u8Row
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t LCD_enuSetPosition(u8 Copy_u8Column, u8 Copy_u8Row);

/***********************	Prototypes Section	End		***********************/

#endif /* HAL_LCD_LCD_INT_H_ */
