/*
 * SSD_prog.c
 *
 *  Created on: ٠٢‏/٠٧‏/٢٠٢٣
 *      Author: Ahmed
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "SSDLT_private.h"
#include "SSDLT_config.h"

extern SEG_t SSD_AstrSegConfig[SEG_NUM];



ES_t SSDLT_enuInit(SEG_t * Copy_pstrSegConfig)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Iterator = 0;
	u8 Local_u8LastBit  = 0;
	u32 Local_u32Check  = 0;

	if(Copy_pstrSegConfig != NULL)
	{
		for(Local_u8Iterator = 0; Local_u8Iterator < SEG_NUM; Local_u8Iterator++)
		{
			Local_u32Check |= (DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iterator].SEG_u8APort,
													  Copy_pstrSegConfig[Local_u8Iterator].SEG_u8APin, DIO_u8OUTPUT) << 0);

			Local_u32Check |= (DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iterator].SEG_u8BPort,
													  Copy_pstrSegConfig[Local_u8Iterator].SEG_u8BPin, DIO_u8OUTPUT) << 3);

			Local_u32Check |= (DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iterator].SEG_u8CPort,
													  Copy_pstrSegConfig[Local_u8Iterator].SEG_u8CPin, DIO_u8OUTPUT) << 6);

			Local_u32Check |= (DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iterator].SEG_u8DPort,
													  Copy_pstrSegConfig[Local_u8Iterator].SEG_u8DPin, DIO_u8OUTPUT) << 9);

			Local_u32Check |= (DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iterator].SEG_u8EPort,
													  Copy_pstrSegConfig[Local_u8Iterator].SEG_u8EPin, DIO_u8OUTPUT) << 12);

			Local_u32Check |= (((u32)DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iterator].SEG_u8FPort,
													 Copy_pstrSegConfig[Local_u8Iterator].SEG_u8FPin, DIO_u8OUTPUT)) << 15);

			Local_u32Check |= (((u32)DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iterator].SEG_u8GPort,
													 Copy_pstrSegConfig[Local_u8Iterator].SEG_u8GPin, DIO_u8OUTPUT)) << 18);
			Local_u8LastBit = 21;

			if(Copy_pstrSegConfig[Local_u8Iterator].SEG_u8CMN_Port != NOT_CONNECTED ||
			   Copy_pstrSegConfig[Local_u8Iterator].SEG_u8CMN_Pin != NOT_CONNECTED)
			{
				Local_u32Check |= (((u32)DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iterator].SEG_u8CMN_Port,
												   Copy_pstrSegConfig[Local_u8Iterator].SEG_u8CMN_Pin, DIO_u8OUTPUT) << Local_u8LastBit));
				Local_u8LastBit += 3;
			}

			if(Copy_pstrSegConfig[Local_u8Iterator].SEG_u8DOT_Port != NOT_CONNECTED ||
			   Copy_pstrSegConfig[Local_u8Iterator].SEG_u8DOT_Pin != NOT_CONNECTED)
			{
				Local_u32Check |= (((u32)DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iterator].SEG_u8DOT_Port,
												   Copy_pstrSegConfig[Local_u8Iterator].SEG_u8DOT_Pin, DIO_u8OUTPUT) << Local_u8LastBit));
				Local_u8LastBit += 3;
			}

		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}


	for(Local_u8Iterator = 0; Local_u8Iterator < Local_u8LastBit; Local_u8Iterator += 3)
	{
		if( ( ( (Local_u32Check)>>Local_u8Iterator) & 7) != ES_OK)
		{
			return Local_enuErrorState;
		}
	}
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t SSDLT_enuDisplayNum(u8 Copy_u8SegID, u8 Copy_u8Number)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Iterator = 0;
	u32 Local_u32Check = 0;

	if(Copy_u8Number < 10 && Copy_u8SegID < SEG_NUM)
	{
		if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
		{
			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8APort,
							   	   	   	   	      SSD_AstrSegConfig[Copy_u8SegID].SEG_u8APin,
											   	  ((SSDLT_Au8ComCathodeNumDisplay[Copy_u8Number]>>0) & 1)) << 0);

			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8BPort,
							   	   	   	   	   	  SSD_AstrSegConfig[Copy_u8SegID].SEG_u8BPin,
												  ((SSDLT_Au8ComCathodeNumDisplay[Copy_u8Number]>>1) & 1)) << 3);

			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CPort,
							   	   	   	   	   	  SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CPin,
												  ((SSDLT_Au8ComCathodeNumDisplay[Copy_u8Number]>>2) & 1)) << 6);

			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DPort,
							   	   	   	   	   	  SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DPin,
												  ((SSDLT_Au8ComCathodeNumDisplay[Copy_u8Number]>>3) & 1)) << 9) ;

			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8EPort,
							   	   	   	   	   	  SSD_AstrSegConfig[Copy_u8SegID].SEG_u8EPin,
												  ((SSDLT_Au8ComCathodeNumDisplay[Copy_u8Number]>>4) & 1)) << 12);

			Local_u32Check |= (((u32)DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8FPort,
							   	   	   	   	   	  SSD_AstrSegConfig[Copy_u8SegID].SEG_u8FPin,
												  ((SSDLT_Au8ComCathodeNumDisplay[Copy_u8Number]>>5) & 1)) << 15));

			Local_u32Check |= (((u32)DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8GPort,
							   	   	   	   	   	  SSD_AstrSegConfig[Copy_u8SegID].SEG_u8GPin,
												  ((SSDLT_Au8ComCathodeNumDisplay[Copy_u8Number]>>6) & 1)) << 18));

		}
		else if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
		{
			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8APort,
							   SSD_AstrSegConfig[Copy_u8SegID].SEG_u8APin,
							   (!((SSDLT_Au8ComCathodeNumDisplay[Copy_u8Number]>>0) & 1))) << 0);

			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8BPort,
							   SSD_AstrSegConfig[Copy_u8SegID].SEG_u8BPin,
							   (!((SSDLT_Au8ComCathodeNumDisplay[Copy_u8Number]>>1) & 1))) << 3);

			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CPort,
							   SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CPin,
							   (!((SSDLT_Au8ComCathodeNumDisplay[Copy_u8Number]>>2) & 1))) << 6);

			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DPort,
							   SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DPin,
							   (!((SSDLT_Au8ComCathodeNumDisplay[Copy_u8Number]>>3) & 1))) << 9);

			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8EPort,
							   SSD_AstrSegConfig[Copy_u8SegID].SEG_u8EPin,
							   (!((SSDLT_Au8ComCathodeNumDisplay[Copy_u8Number]>>4) & 1))) << 12);

			Local_u32Check |= (((u32)DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8FPort,
							   SSD_AstrSegConfig[Copy_u8SegID].SEG_u8FPin,
							   (!((SSDLT_Au8ComCathodeNumDisplay[Copy_u8Number]>>5) & 1))) << 15));

			Local_u32Check |= (((u32)DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8GPort,
							   SSD_AstrSegConfig[Copy_u8SegID].SEG_u8GPin,
							   (!((SSDLT_Au8ComCathodeNumDisplay[Copy_u8Number]>>6) & 1))) << 18));
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
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

ES_t SSDLT_enuEnableCommon(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8SegID < SEG_NUM)
	{
		if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port != NOT_CONNECTED ||
				SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin != NOT_CONNECTED)
		{
			if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
			{
				Local_enuErrorState = DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port,
														 SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin, DIO_u8LOW);
			}
			else if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
			{
				Local_enuErrorState = DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port,
														SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin, DIO_u8HIGH);
			}
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}

ES_t SSDLT_enuDisableCommon(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8SegID < SEG_NUM)
	{
		if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port != NOT_CONNECTED ||
				SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin != NOT_CONNECTED)
		{
			if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
			{
				Local_enuErrorState = DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port,
														 SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin, DIO_u8HIGH);
			}
			else if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
			{
				Local_enuErrorState = DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port,
														SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin, DIO_u8LOW);
			}
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}

ES_t SSDLT_enuEnableDot(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8SegID < SEG_NUM)
	{
		if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port != NOT_CONNECTED ||
				SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin != NOT_CONNECTED)
		{
			if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
			{
				Local_enuErrorState = DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port,
														 SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin, DIO_u8HIGH);
			}
			else if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
			{
				Local_enuErrorState = DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port,
														SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin, DIO_u8LOW);
			}
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}

ES_t SSDLT_enuDisableDot(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8SegID < SEG_NUM)
	{
		if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port != NOT_CONNECTED ||
				SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin != NOT_CONNECTED)
		{
			if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
			{
				Local_enuErrorState = DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port,
														 SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin, DIO_u8LOW);
			}
			else if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
			{
				Local_enuErrorState = DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port,
														SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin, DIO_u8HIGH);
			}
			else
			{
				return ES_OUT_OF_RANGE;
			}
		}
	}
	else
	{
		return ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}

ES_t SSDLT_enuClearDisplay(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Iterator = 0;
	u8 Local_u8LastBit = 0;
	u32 Local_u32Check = 0;

	if(Copy_u8SegID < SEG_NUM)
	{
		if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
		{
			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8APort,
							   	   	   	   	      SSD_AstrSegConfig[Copy_u8SegID].SEG_u8APin,
											   	  DIO_u8LOW) << 0);

			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8BPort,
							   	   	   	   	   	  SSD_AstrSegConfig[Copy_u8SegID].SEG_u8BPin,
												  DIO_u8LOW) << 3);

			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CPort,
							   	   	   	   	   	  SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CPin,
												  DIO_u8LOW) << 6);

			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DPort,
							   	   	   	   	   	  SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DPin,
												  DIO_u8LOW) << 9) ;

			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8EPort,
							   	   	   	   	   	  SSD_AstrSegConfig[Copy_u8SegID].SEG_u8EPin,
												  DIO_u8LOW) << 12);

			Local_u32Check |= (((u32)DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8FPort,
							   	   	   	   	   	  SSD_AstrSegConfig[Copy_u8SegID].SEG_u8FPin,
												  DIO_u8LOW) << 15));

			Local_u32Check |= (((u32)DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8GPort,
							   	   	   	   	   	  SSD_AstrSegConfig[Copy_u8SegID].SEG_u8GPin,
												  DIO_u8LOW) << 18));
			Local_u8LastBit = 21;
		}
		else if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
		{
			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8APort,
							   	   	   	   	      SSD_AstrSegConfig[Copy_u8SegID].SEG_u8APin,
											   	  DIO_u8HIGH) << 0);

			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8BPort,
							   	   	   	   	   	  SSD_AstrSegConfig[Copy_u8SegID].SEG_u8BPin,
												  DIO_u8HIGH) << 3);

			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CPort,
							   	   	   	   	   	  SSD_AstrSegConfig[Copy_u8SegID].SEG_u8CPin,
												  DIO_u8HIGH) << 6);

			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DPort,
							   	   	   	   	   	  SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DPin,
												  DIO_u8HIGH) << 9) ;

			Local_u32Check |= (DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8EPort,
							   	   	   	   	   	  SSD_AstrSegConfig[Copy_u8SegID].SEG_u8EPin,
												  DIO_u8HIGH) << 12);

			Local_u32Check |= (((u32)DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8FPort,
							   	   	   	   	   	  SSD_AstrSegConfig[Copy_u8SegID].SEG_u8FPin,
												  DIO_u8HIGH) << 15));

			Local_u32Check |= (((u32)DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8GPort,
							   	   	   	   	   	  SSD_AstrSegConfig[Copy_u8SegID].SEG_u8GPin,
												  DIO_u8HIGH) << 18));
			Local_u8LastBit = 21;
		}
		else
		{
			return ES_OUT_OF_RANGE;
		}
	}
	else
	{
		return ES_OUT_OF_RANGE;
	}

	if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port != NOT_CONNECTED ||
		SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin != NOT_CONNECTED)
	{
		if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
		{
			Local_enuErrorState |= (((u32)DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port,
													 SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin, DIO_u8LOW) << Local_u8LastBit));
			Local_u8LastBit += 3;
		}
		else if(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
		{
			Local_enuErrorState |= (((u32)DIO_enuSetPinValue(SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port,
													SSD_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin, DIO_u8HIGH) << Local_u8LastBit));
			Local_u8LastBit += 3;
		}
		else
		{
			return ES_OUT_OF_RANGE;
		}

	}
	else
	{
		return ES_OUT_OF_RANGE;
	}

	for(Local_u8Iterator = 0; Local_u8Iterator < Local_u8LastBit; Local_u8Iterator += 3)
	{
		if( ( ( (Local_u32Check)>>Local_u8Iterator) & 7) != ES_OK)
		{
			return Local_enuErrorState;
		}
	}

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
