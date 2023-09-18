/**
 ****************************************************************************************
 *   @file          : LCD_private.h
 *   @author        : Ahmed Ali
 *   @brief         : LCD private file.
 *	 @date			: 6 / 7 / 2023
 ****************************************************************************************
*/

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

/***********************	Macros Section	Start	***********************/
#define EIGHT_BIT   5
#define FOUR_BIT    6
/***********************	Macros Section	End		***********************/

/***********************	Local Prototypes Section Start	***********************/
/**
 ****************************************************************************************
 *	@name			: LCD_voidLatch
 *  @brief          : Local function using to help another function (APIs).
 *  				  Usage: Write on LCD either data or command after configure RS.
 *  @param          : u8 Copy_u8Data
 *  @return         : void
 ****************************************************************************************
*/
static void LCD_voidLatch(u8 Copy_u8Data);

/**
 ****************************************************************************************
 *	@name			: LCD_voidGetLog10
 *  @brief          : Local function using to get log10 of number.
 *  				  Usage: get log10 of number.
 *  @param          : s32 Copy_s32Number, s32 *Copy_ps32Result
 *  @return         : void
 ****************************************************************************************
*/
static void LCD_voidGetLog10(s32 Copy_s32Number, s32 *Copy_ps32Result);

/**
 ****************************************************************************************
 *	@name			: LCD_voidPower
 *  @brief          : Local function using to calculate power.
 *  				  Usage: Calculate Power.
 *  @param          : s32 Copy_s32Base, s32 Copy_s32Exponent, s32 *Copy_ps32Result
 *  @return         : void
 ****************************************************************************************
*/
static void LCD_voidPower(s32 Copy_s32Base, s32 Copy_s32Exponent, s32 *Copy_ps32Result);
/**
 ****************************************************************************************
 *	@name			: LCD_invoidSendCommand
 *  @brief          : Local function using to help another function (APIs).
 *  				  Usage: Send Command to LCD in low level. [for developer only]
 *  @param          : u8 Copy_u8Command
 *  @return         :  void
 ****************************************************************************************
*/
static inline void LCD_invoidSendCommand(u8 Copy_u8Command);

/**
 ****************************************************************************************
 *	@name			: LCD_enuLocalGoToXY
 *  @brief          : Local function using to help another function (APIs).
 *  				  Usage: Set position to write something on LCD.
 *  @param          : u8 Copy_u8Row, u8 Copy_u8Column
 *  @return         : ES_t
 ****************************************************************************************
*/
static ES_t LCD_enuLocalGoToXY(u8 Copy_u8Row, u8 Copy_u8Column);
/***********************	Local Prototypes Section End	***********************/


#endif /* HAL_LCD_LCD_PRIVATE_H_ */
