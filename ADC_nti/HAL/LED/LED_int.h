/**
 ****************************************************************************************
 *   @file          : LED_int.h
 *   @author        : Ahmed Ali
 *   @brief         : LED Interface file consists prototypes of LED APIs
 *	 @date			: 1 / 7 / 2023
 ****************************************************************************************
*/

#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_

/***********************	Includes Section Start	***********************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"
#include "LED_private.h"
/***********************	Includes Section End	***********************/
/***********************	Prototypes Section Start	***********************/
/**
 ****************************************************************************************
 *	@name			: LED_enuInit
 *  @brief          : Initialize LED Module.
 *  @param          : LED_t * Copy_pstrLedConfiguration
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t LED_enuInit(LED_t * Copy_pstrLedConfiguration);

/**
 ****************************************************************************************
 *	@name			: LED_enuTurnON
 *  @brief          : Turn ON LED.
 *  @param          : LED_t * Copy_pstrLedID
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t LED_enuTurnON(LED_t * Copy_pstrLedID);

/**
 ****************************************************************************************
 *	@name			: LED_enuTurnOFF
 *  @brief          : Turn OFF LED.
 *  @param          : LED_t * Copy_pstrLedID
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t LED_enuTurnOFF(LED_t * Copy_pstrLedID);

/***********************	Prototypes Section End   	***********************/

#endif /* HAL_LED_LED_INT_H_ */
