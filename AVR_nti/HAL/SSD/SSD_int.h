/**
 *******************************************************************************************
 *   @file          : SSD_int.h
 *   @author        : Ahmed Ali
 *   @brief         : Seven Segment Display Interface file consists prototypes of SSD APIs
 *   				  Precompiled Configuration Mode.
 *	 @date			: 2 / 7 / 2023
 *******************************************************************************************
*/

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_

/***********************	Prototypes Section Start	***********************/

/**
 ****************************************************************************************
 *	@name			: SSD_enuInit
 *  @brief          : Initialize Seven Segment Display.
 *  @param          : void
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t SSD_enuInit(void);

/**
 ****************************************************************************************
 *	@name			: SSD_enuDisplayNum
 *  @brief          : Display number on SSD.
 *  @param          : u8 Copy_u8Number
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t SSD_enuDisplayNum(u8 Copy_u8Number);

/**
 ****************************************************************************************
 *	@name			: SSD_enuEnableCommon
 *  @brief          : Turn ON SSD Common if needed.
 *  @param          : void
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t SSD_enuEnableCommon(void);

/**
 ****************************************************************************************
 *	@name			: SSD_enuDisableCommon
 *  @brief          : Turn OFF SSD Common if not needed.
 *  @param          : void
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t SSD_enuDisableCommon(void);

/**
 ****************************************************************************************
 *	@name			: SSD_enuEnableDot
 *  @brief          : Turn ON SSD DOT if there exist & needed it.
 *  @param          : void
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t SSD_enuEnableDot(void);

/**
 ****************************************************************************************
 *	@name			: SSD_enuDisableDot
 *  @brief          : Turn OFF SSD DOT if not there exist or not needed it.
 *  @param          : void
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t SSD_enuDisableDot(void);

/**
 ****************************************************************************************
 *	@name			: SSD_enuClearDisplay
 *  @brief          : Clear Seven Segment Display [DOT with cleared too].
 *  @param          : void
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t SSD_enuClearDisplay(void);

/***********************	Prototypes Section End		***********************/

#endif /* HAL_SSD_SSD_INT_H_ */
