/**
 ****************************************************************************************
 *   @file          : DIO_int.h
 *   @author        : Ahmed Ali
 *   @brief         : DIO Interface file consists prototypes of DIO APIs
 *	 @date			: 26 / 6 / 2023
 ****************************************************************************************
*/

#ifndef MCAL_DIO_INT_H_
#define MCAL_DIO_INT_H_

#include "../../LIB/ERROR_STATE.h"
#include "../../LIB/STD_TYPES.h"

#define DIO_u8PORTA		0
#define DIO_u8PORTB		1
#define DIO_u8PORTC		2
#define DIO_u8PORTD		3

#define DIO_u8PIN0		0
#define DIO_u8PIN1		1
#define DIO_u8PIN2		2
#define DIO_u8PIN3		3
#define DIO_u8PIN4		4
#define DIO_u8PIN5		5
#define DIO_u8PIN6		6
#define DIO_u8PIN7		7

#define DIO_u8OUTPUT    1
#define DIO_u8INPUT     0

#define DIO_u8LOW		0
#define DIO_u8HIGH		1
#define DIO_u8FLOAT		0
#define DIO_u8PULL_UP 	1
/**
 ****************************************************************************************
 *	@name			: DIO_enuInit
 *  @brief          : Initialize DIO.
 *  @param          : void
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t DIO_enuInit(void);

/**
 ****************************************************************************************
 *	@name			: DIO_enuSetPortDirection
 *  @brief          : Direction for all port pins.
 *  @param          : u8 Copy_u8PortID, u8 Copy_u8Value
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t DIO_enuSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8Value);

/**
 ****************************************************************************************
 *	@name			: DIO_enuSetPortValue
 *  @brief          : Set value for all pins of port.
 *  @param          : u8 Copy_u8PortID, u8 Copy_u8Value
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t DIO_enuSetPortValue(u8 Copy_u8PortID, u8 Copy_u8Value);

/**
 ****************************************************************************************
 *	@name			: DIO_enuTogPort
 *  @brief          : Toggle case of all pins in port.
 *  @param          : u8 Copy_u8PortID
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t DIO_enuTogPortValue(u8 Copy_u8PortID);

/**
 ****************************************************************************************
 *	@name			: DIO_enuGetPortValue
 *  @brief          : Get port value and store it in variable passed by address.
 *  @param          : u8 Copy_u8PortID, u8 * Copy_u8Value
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t DIO_enuGetPortValue(u8 Copy_u8PortID, u8 * Copy_u8Value);

/**
 ****************************************************************************************
 *	@name			: DIO_enuSetPinDirection
 *  @brief          : Set direction of pin.
 *  @param          : u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t DIO_enuSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value);

/**
 ****************************************************************************************
 *	@name			: DIO_enuSetPinValue
 *  @brief          : Set value of pin.
 *  @param          : u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t DIO_enuSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value);

/**
 ****************************************************************************************
 *	@name			: DIO_enuTogPin
 *  @brief          : Toggle value of pin.
 *  @param          : u8 Copy_u8PortID, u8 Copy_u8PinID
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t DIO_enuTogPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID);

/**
 ****************************************************************************************
 *	@name			: DIO_enuGetPinValue
 *  @brief          : Get value of pin and store it in variable passed by address.
 *  @param          : u8 Copy_u8PortID, u8 Copy_u8PinID
 *  @return         : ES_t
 ****************************************************************************************
*/
ES_t DIO_enuGetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 * Copy_u8Value);

/**
 * Note: We can deal with functions of pin without port ID by define macros or enums
 * for AVR 32 pins and deal with number of pin directly.
 */

#endif /* MCAL_DIO_INT_H_ */
