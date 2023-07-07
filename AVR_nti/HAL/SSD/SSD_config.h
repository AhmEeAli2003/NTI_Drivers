/**
 *******************************************************************************************
 *   @file          : SSD_config.h
 *   @author        : Ahmed Ali
 *   @brief         : Seven Segment Display Configuration settings.
 *   				  Precompiled Configuration Mode.
 *	 @date			: 2 / 7 / 2023
 *******************************************************************************************
*/

#ifndef HAL_SSD_SSD_CONFIG_H_
#define HAL_SSD_SSD_CONFIG_H_
/***********************	Macros Section Start		***********************/

/********************************************************
 * Choose port & pin for each segments:
 * 		-> SEG_xPIN:  Pin of segment x.
 * 		-> SEG_xPORT: Port of segment x.
 * 	Options for ports:
 * 		-> DIO_u8PORTA
 * 		-> DIO_u8PORTB
 * 		-> DIO_u8PORTC
 * 		-> DIO_u8PORTD
 * 	Options for pins:
 * 		-> DIO_u8PIN0
 * 		-> DIO_u8PIN1
 * 		-> DIO_u8PIN2
 * 		-> DIO_u8PIN3
 * 		-> DIO_u8PIN4
 * 		-> DIO_u8PIN5
 * 		-> DIO_u8PIN6
 * 		-> DIO_u8PIN7
 * 	Additional option for SEG_CMN_PIN, SEG_CMN_PORT,
 * 						  SEG_DOT_PIN and SEG_DOT_PORT
 * 	This option is NOT_CONNECTED if you don't need enable
 * 	Dot nor Common.
 * 	*******************************************************
 * */

#define SEG_APIN    	DIO_u8PIN0
#define SEG_APORT   	DIO_u8PORTA

#define SEG_BPIN    	DIO_u8PIN1
#define SEG_BPORT		DIO_u8PORTA

#define SEG_CPIN		DIO_u8PIN2
#define SEG_CPORT		DIO_u8PORTA

#define SEG_DPIN		DIO_u8PIN0
#define SEG_DPORT		DIO_u8PORTB

#define SEG_EPIN		DIO_u8PIN1
#define SEG_EPORT		DIO_u8PORTB

#define SEG_FPIN		DIO_u8PIN2
#define SEG_FPORT		DIO_u8PORTB

#define SEG_GPIN		DIO_u8PIN3
#define SEG_GPORT		DIO_u8PORTB

#define SEG_DOT_PIN		NOT_CONNECTED
#define SEG_DOT_PORT	NOT_CONNECTED

#define SEG_CMN_PIN		NOT_CONNECTED
#define SEG_CMN_PORT	NOT_CONNECTED

/**
 * Choose type of seven segment:
 * 		-> COMMON_ANODE
 * 		-> COMMON_CATHODE
 * */
#define SEG_TYPE		COMMON_CATHODE
/***********************	Macros Section End		***********************/

#endif /* HAL_SSD_SSD_CONFIG_H_ */
