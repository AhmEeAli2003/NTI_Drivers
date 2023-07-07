/**
 *******************************************************************************************
 *   @file          : SSD_private.h
 *   @author        : Ahmed Ali
 *   @brief         : Seven Segment Private Definitions.
 *	 @date			: 2 / 7 / 2023
 *******************************************************************************************
*/

#ifndef HAL_SSD_SSD_PRIVATE_H_
#define HAL_SSD_SSD_PRIVATE_H_
/***********************	Macros Section Start		***********************/
#define COMMON_ANODE 		0
#define COMMON_CATHODE 		1
#define NOT_CONNECTED       2
/***********************	Macros Section End			***********************/

/***********************	Definitions Section Start		***********************/
u8 SSD_Au8ComCathodeNumDisplay[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66,
									 0x6D, 0x7D, 0x07, 0x7F, 0x6F
									};
/***********************	Definitions Section End		***********************/
#endif /* HAL_SSD_SSD_PRIVATE_H_ */
