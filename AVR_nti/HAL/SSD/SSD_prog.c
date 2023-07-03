/*
 * SSD_prog.c
 *
 *  Created on: ٠٢‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "SSD_config.h"
#include "SSD_private.h"

ES_t SSD_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	u32 Local_u32Check = 0;
	u8 Local_u8Iterator = 0;

	Local_u32Check |= (DIO_enuSetPinDirection(SEG_APORT, SEG_APIN, DIO_u8OUTPUT) << 0);
	Local_u32Check |= (DIO_enuSetPinDirection(SEG_BPORT, SEG_BPIN, DIO_u8OUTPUT) << 3);
	Local_u32Check |= (DIO_enuSetPinDirection(SEG_CPORT, SEG_CPIN, DIO_u8OUTPUT) << 6);
	Local_u32Check |= (DIO_enuSetPinDirection(SEG_DPORT, SEG_DPIN, DIO_u8OUTPUT) << 9);
	Local_u32Check |= (DIO_enuSetPinDirection(SEG_EPORT, SEG_EPIN, DIO_u8OUTPUT) << 12);
	Local_u32Check |= (((u32)DIO_enuSetPinDirection(SEG_GPORT, SEG_GPIN, DIO_u8OUTPUT)) << 15);
	Local_u32Check |= (((u32)DIO_enuSetPinDirection(SEG_GPORT, SEG_GPIN, DIO_u8OUTPUT)) << 18);

	/**
	 * ATTENTION: This casting is very important, because without it will cause
	 * Warning: left shift count >= width of type
	 * which is happening because compiler deal with return of function (enum) as int, so
	 * will Causes an error in the value after the 15th bit, because 16th bit is the middle
	 * of u32 data type.
	 * Casting the return as u32 will fix this issue.
	 *  Value of (Local_u32Check) variable before casting is:
	 *  	1111 1111 1111 1111 1001 0010 0100 1001
	 *  As you look from 16th bit all bits will set as 1
	 *  but ideal state which will be the value of variable after casting is:
	 *  	0000 0000 0000 0100 1001 0010 0100 1001
	 * */

	//Because we work as pre compile config we will use #if
	#if SEG_CMN_PIN <= DIO_u8PIN7 && SEG_CMN_PORT <= DIO_u8PORTD
		Local_u32Check |= (((u32)DIO_enuSetPinDirection(SEG_CMN_PORT, SEG_CMN_PIN, DIO_u8OUTPUT)) << 21);
	#elif SEG_CMN_PIN == NOT_CONNECTED || SEG_CMN_PORT == NOT_CONNECTED

	#else
		#error "Your Common pin has a wrong selection!"
	#endif

	#if SEG_DOT_PIN <= DIO_u8PIN7 && SEG_DOT_PORT <= DIO_u8PORTD
		Local_u32Check |= (((u32)DIO_enuSetPinDirection(SEG_DOT_PORT, SEG_DOT_PIN, DIO_u8OUTPUT)) << 24);
	#elif SEG_DOT_PIN == NOT_CONNECTED || SEG_DOT_PORT == NOT_CONNECTED

	#else
		#error "Your DOT pin has a wrong selection!"
	#endif


	for(Local_u8Iterator = 0; Local_u8Iterator < 27; Local_u8Iterator += 3)
	{
		if( ( ( (Local_u32Check)>>Local_u8Iterator) & 7) != ES_OK)
		{
			return Local_enuErrorState;
		}
	}

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t SSD_enuDisplayNum(u8 Copy_u8Number)
{
	ES_t Local_enuErrorState = ES_NOK;

	u32 Local_u32Check = 0;
	u8 Local_u8Iterator = 0;

	if(Copy_u8Number < 10)
	{
		#if SEG_TYPE == COMMON_CATHODE
			Local_u32Check |= (DIO_enuSetPinValue(SEG_APORT, SEG_APIN,((SSD_Au8ComCathodeNumDisplay[Copy_u8Number] >> 0) & 1)) << 0);
			Local_u32Check |= (DIO_enuSetPinValue(SEG_BPORT, SEG_BPIN,((SSD_Au8ComCathodeNumDisplay[Copy_u8Number] >> 1) & 1)) << 3);
			Local_u32Check |= (DIO_enuSetPinValue(SEG_CPORT, SEG_CPIN,((SSD_Au8ComCathodeNumDisplay[Copy_u8Number] >> 2) & 1)) << 6);
			Local_u32Check |= (DIO_enuSetPinValue(SEG_DPORT, SEG_DPIN,((SSD_Au8ComCathodeNumDisplay[Copy_u8Number] >> 3) & 1)) << 9);
			Local_u32Check |= (DIO_enuSetPinValue(SEG_EPORT, SEG_EPIN,((SSD_Au8ComCathodeNumDisplay[Copy_u8Number] >> 4) & 1)) << 12);
			Local_u32Check |= (((u32)DIO_enuSetPinValue(SEG_FPORT, SEG_FPIN,((SSD_Au8ComCathodeNumDisplay[Copy_u8Number] >> 5) & 1))) << 15);
			Local_u32Check |= (((u32)DIO_enuSetPinValue(SEG_GPORT, SEG_GPIN,((SSD_Au8ComCathodeNumDisplay[Copy_u8Number] >> 6) & 1))) << 18);
		#elif SEG_TYPE == COMMON_ANODE
			Local_u32Check |= (DIO_enuSetPinValue(SEG_APORT, SEG_APIN,!((SSD_Au8ComCathodeNumDisplay[Copy_u8Number] >> 0) & 1)) << 0);
			Local_u32Check |= (DIO_enuSetPinValue(SEG_BPORT, SEG_BPIN,!((SSD_Au8ComCathodeNumDisplay[Copy_u8Number] >> 1) & 1)) << 3);
			Local_u32Check |= (DIO_enuSetPinValue(SEG_CPORT, SEG_CPIN,!((SSD_Au8ComCathodeNumDisplay[Copy_u8Number] >> 2) & 1)) << 6);
			Local_u32Check |= (DIO_enuSetPinValue(SEG_DPORT, SEG_DPIN,!((SSD_Au8ComCathodeNumDisplay[Copy_u8Number] >> 3) & 1)) << 9);
			Local_u32Check |= (DIO_enuSetPinValue(SEG_EPORT, SEG_EPIN,!((SSD_Au8ComCathodeNumDisplay[Copy_u8Number] >> 4) & 1)) << 12);
			Local_u32Check |= (((u32)DIO_enuSetPinValue(SEG_FPORT, SEG_FPIN,!((SSD_Au8ComCathodeNumDisplay[Copy_u8Number] >> 5) & 1))) << 15);
			Local_u32Check |= (((u32)DIO_enuSetPinValue(SEG_GPORT, SEG_GPIN,!((SSD_Au8ComCathodeNumDisplay[Copy_u8Number] >> 6) & 1))) << 18);
		#else
			#error "Your type selection is invalid!"
		#endif
	}
	else
	{
		return ES_OUT_OF_RANGE;
	}

	for(Local_u8Iterator = 0; Local_u8Iterator < 21; Local_u8Iterator += 3)
	{
		if( ( ( (Local_u32Check)>>Local_u8Iterator) & 7) != ES_OK)
		{
			return Local_enuErrorState;
		}
	}

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t SSD_enuEnableCommon(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	#if SEG_CMN_PIN <= DIO_u8PIN7 && SEG_CMN_PORT <= DIO_u8PORTD
		#if SEG_TYPE == COMMON_CATHODE
			Local_enuErrorState = DIO_enuSetPinValue(SEG_CMN_PORT, SEG_CMN_PIN, DIO_u8LOW);
		#elif  SEG_TYPE == COMMON_ANODE
			Local_enuErrorState = DIO_enuSetPinValue(SEG_CMN_PORT, SEG_CMN_PIN, DIO_u8HIGH);
		#else
			#error "Your Common Selection is invalid!"
		#endif
	#elif SEG_CMN_PIN == NOT_CONNECTED || SEG_CMN_PORT == NOT_CONNECTED

	#else
		#error "Your Common pin has a wrong selection!"
	#endif

	return Local_enuErrorState;
}

ES_t SSD_enuDisableCommon(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	#if SEG_CMN_PIN <= DIO_u8PIN7 && SEG_CMN_PORT <= DIO_u8PORTD
		#if SEG_TYPE == COMMON_CATHODE
			Local_enuErrorState = DIO_enuSetPinValue(SEG_CMN_PORT, SEG_CMN_PIN, DIO_u8HIGH);
		#elif  SEG_TYPE == COMMON_ANODE
			Local_enuErrorState = DIO_enuSetPinValue(SEG_CMN_PORT, SEG_CMN_PIN, DIO_u8LOW);
		#else
			#error "Your Common Selection is invalid!"
		#endif
	#elif SEG_CMN_PIN == NOT_CONNECTED || SEG_CMN_PORT == NOT_CONNECTED

	#else
		#error "Your Common pin has a wrong selection!"
	#endif

	return Local_enuErrorState;
}

ES_t SSD_enuEnableDot(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	#if SEG_DOT_PIN <= DIO_u8PIN7 && SEG_DOT_PORT <= DIO_u8PORTD
		#if SEG_TYPE == COMMON_CATHODE
			Local_enuErrorState = DIO_enuSetPinValue(SEG_DOT_PORT, SEG_DOT_PIN, DIO_u8HIGH);
		#elif  SEG_TYPE == COMMON_ANODE
			Local_enuErrorState = DIO_enuSetPinValue(SEG_DOT_PORT, SEG_DOT_PIN, DIO_u8LOW);
		#else
			#error "Your Common Selection is invalid!"
		#endif
	#elif SEG_DOT_PIN == NOT_CONNECTED || SEG_DOT_PORT == NOT_CONNECTED

	#else
		#error "Your DOT pin has a wrong selection!"
	#endif

	return Local_enuErrorState;
}

ES_t SSD_enuDisableDot(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	#if SEG_DOT_PIN <= DIO_u8PIN7 && SEG_DOT_PORT <= DIO_u8PORTD
		#if SEG_TYPE == COMMON_CATHODE
			Local_enuErrorState = DIO_enuSetPinValue(SEG_DOT_PORT, SEG_DOT_PIN, DIO_u8LOW);
		#elif  SEG_TYPE == COMMON_ANODE
			Local_enuErrorState = DIO_enuSetPinValue(SEG_DOT_PORT, SEG_DOT_PIN, DIO_u8HIGH);
		#else
			#error "Your Common Selection is invalid!"
		#endif
	#elif SEG_DOT_PIN == NOT_CONNECTED || SEG_DOT_PORT == NOT_CONNECTED

	#else
		#error "Your DOT pin has a wrong selection!"
	#endif

	return Local_enuErrorState;
}

ES_t SSD_enuClearDisplay(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	u32 Local_u32Check = 0;
	u8 Local_u8Iterator = 0;

	#if SEG_TYPE == COMMON_CATHODE
		Local_u32Check |= (DIO_enuSetPinValue(SEG_APORT, SEG_APIN,DIO_u8LOW) << 0);
		Local_u32Check |= (DIO_enuSetPinValue(SEG_BPORT, SEG_BPIN,DIO_u8LOW) << 3);
		Local_u32Check |= (DIO_enuSetPinValue(SEG_CPORT, SEG_CPIN,DIO_u8LOW) << 6);
		Local_u32Check |= (DIO_enuSetPinValue(SEG_DPORT, SEG_DPIN,DIO_u8LOW) << 9);
		Local_u32Check |= (DIO_enuSetPinValue(SEG_EPORT, SEG_EPIN,DIO_u8LOW) << 12);
		Local_u32Check |= (((u32)DIO_enuSetPinValue(SEG_FPORT, SEG_FPIN,DIO_u8LOW)) << 15);
		Local_u32Check |= (((u32)DIO_enuSetPinValue(SEG_GPORT, SEG_GPIN,DIO_u8LOW)) << 18);
	#elif SEG_TYPE == COMMON_ANODE
		Local_u32Check |= (DIO_enuSetPinValue(SEG_APORT, SEG_APIN,DIO_u8HIGH) << 0);
		Local_u32Check |= (DIO_enuSetPinValue(SEG_BPORT, SEG_BPIN,DIO_u8HIGH) << 3);
		Local_u32Check |= (DIO_enuSetPinValue(SEG_CPORT, SEG_CPIN,DIO_u8HIGH) << 6);
		Local_u32Check |= (DIO_enuSetPinValue(SEG_DPORT, SEG_DPIN,DIO_u8HIGH) << 9);
		Local_u32Check |= (DIO_enuSetPinValue(SEG_EPORT, SEG_EPIN,DIO_u8HIGH) << 12);
		Local_u32Check |= (((u32)DIO_enuSetPinValue(SEG_FPORT, SEG_FPIN,DIO_u8HIGH)) << 15);
		Local_u32Check |= (((u32)DIO_enuSetPinValue(SEG_GPORT, SEG_GPIN,DIO_u8HIGH)) << 18);
	#else
		#error "Your type selection is invalid!"
	#endif

	for(Local_u8Iterator = 0; Local_u8Iterator < 21; Local_u8Iterator += 3)
	{
		if( ( ( (Local_u32Check)>>Local_u8Iterator) & 7) != ES_OK)
		{
			return Local_enuErrorState;
		}
	}

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}
