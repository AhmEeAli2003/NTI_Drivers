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
 *	@name			: LCD_enuDisplayNumber
 *  @brief          : Display Number on LCD. from -2147483647 to 2147483647
 *  @param          : s32 Copy_s32Number
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t LCD_enuDisplayNumber(s32 Copy_s32Number);

/**
 ****************************************************************************************
 *	@name			: LCD_enuDisplaySpecialChar
 *  @brief          : Display Special Character on LCD.
 *  @param          : u32 Copy_u32HighPattern, u32 Copy_u32LowPattern
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t LCD_enuDisplaySpecialChar(u8 Copy_u8RowPosition , u8 Copy_u8ColPosition, u8 *Copy_pu8ExtraChar);

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
 *  @param          : u8 Copy_u8Row, u8 Copy_u8Column
 *  					Column Range (1->16) | Row Range (1&2)
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t LCD_enuSetPosition(u8 Copy_u8Row, u8 Copy_u8Column);

/***********************	Prototypes Section	End		***********************/


/***********************	Macros Section	Start	***********************/
#define LCD_u8HIDE_CURSOR_AND_BLINKING   0x0C
#define LCD_u8GO_TO_SECOND_LINE          0xC0
#define LCD_u8CLEAR_LCD					 0x01

#define LCD_u8FIRST_ROW					 1
#define LCD_u8SECOND_ROW				 2

#define LCD_u8COL_1						 1
#define LCD_u8COL_2                      2
#define LCD_u8COL_3                      3
#define LCD_u8COL_4                      4
#define LCD_u8COL_5                      5
#define LCD_u8COL_6                      6
#define LCD_u8COL_7                      7
#define LCD_u8COL_8                      8
#define LCD_u8COL_9                      9
#define LCD_u8COL_10                     10
#define LCD_u8COL_11                     11
#define LCD_u8COL_12                     12
#define LCD_u8COL_13                     13
#define LCD_u8COL_14                     14
#define LCD_u8COL_15                     15
#define LCD_u8COL_16                     16


/***********************	Macros Section	End	***********************/

#endif /* HAL_LCD_LCD_INT_H_ */
