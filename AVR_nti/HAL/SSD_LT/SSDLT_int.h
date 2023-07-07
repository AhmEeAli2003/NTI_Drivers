/**
 *******************************************************************************************
 *   @file          : SSDLT_int.h
 *   @author        : Ahmed Ali
 *   @brief         : Seven Segment Display Interface file consists prototypes of SSD APIs
 *   				  Linking Time Configuration Mode.
 *	 @date			: 2 / 7 / 2023
 *******************************************************************************************
*/

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_
/***********************	Includes Section Start	***********************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"
#include "SSDLT_private.h"
/***********************	Includes Section End	***********************/

/***********************	Prototypes Section Start	***********************/
/**
 ****************************************************************************************
 *	@name			: SSDLT_enuInit
 *  @brief          : Initialize Seven Segment Display.
 *  @param          : SEG_t * Copy_pstrSegConfig
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t SSDLT_enuInit(SEG_t * Copy_pstrSegConfig);

/**
 ****************************************************************************************
 *	@name			: SSDLT_enuDisplayNum
 *  @brief          : Display number on SSD.
 *  @param          : u8 Copy_u8SegID, u8 Copy_u8Number
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t SSDLT_enuDisplayNum(u8 Copy_u8SegID, u8 Copy_u8Number);

/**
 ****************************************************************************************
 *	@name			: SSDLT_enuEnableCommon
 *  @brief          : Turn ON SSD Common if needed.
 *  @param          : u8 Copy_u8SegID
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t SSDLT_enuEnableCommon(u8 Copy_u8SegID);

/**
 ****************************************************************************************
 *	@name			: SSDLT_enuDisableCommon
 *  @brief          : Turn OFF SSD Common if not needed.
 *  @param          : u8 Copy_u8SegID
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t SSDLT_enuDisableCommon(u8 Copy_u8SegID);

/**
 ****************************************************************************************
 *	@name			: SSDLT_enuEnableDot
 *  @brief          : Turn ON SSD DOT if there exist & needed it.
 *  @param          : u8 Copy_u8SegID
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t SSDLT_enuEnableDot(u8 Copy_u8SegID);

/**
 ****************************************************************************************
 *	@name			: SSDLT_enuDisableDot
 *  @brief          : Turn OFF SSD DOT if not there exist or not needed it.
 *  @param          : u8 Copy_u8SegID
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t SSDLT_enuDisableDot(u8 Copy_u8SegID);

/**
 ****************************************************************************************
 *	@name			: SSDLT_enuClearDisplay
 *  @brief          : Clear Seven Segment Display [DOT with cleared too].
 *  @param          : u8 Copy_u8SegID
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t SSDLT_enuClearDisplay(u8 Copy_u8SegID);
/***********************	Prototypes Section End	***********************/
#endif /* HAL_SSD_SSD_INT_H_ */
