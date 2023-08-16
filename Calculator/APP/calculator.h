/*
 * calculator.h
 *
 *  Created on: ١٦‏/٠٨‏/٢٠٢٣
 *      Author: Ahmed
 */

#ifndef APP_CALCULATOR_H_
#define APP_CALCULATOR_H_

/*********************      Macros Section Start    *********************/
#define CALC_ZERO		0
#define CALC_ONE		1
#define CALC_TWO		2
#define CALC_THREE		3
#define CALC_FOUR		4
#define CALC_FIVE		5
#define CALC_SIX		6
#define CALC_SEVEN		7
#define CALC_EIGHT		8
#define CALC_NINE		9
#define CALC_TEN		10
#define CALC_SIXTEEN	16

#define DELAY_ONE_SECOND       		_delay_ms(1000)
#define DELAY_HALF_OF_SECOND   		_delay_ms(500)
#define DELAY_QUARTER_OF_SECOND 	_delay_ms(250)
/*********************      Macros Section End    *********************/

/*********************      Globals Section Start    *********************/
typedef struct
{
	u8 Flag_1BitIsFirstDigit:CALC_ONE;
	u8 Flag_1BitIsFirstPressed:CALC_ONE;
	u8 Flag_1BitIsLineTwoUsed:CALC_ONE;
	u8 Flag_1BitIsUpperTwo:CALC_ONE;
}FLAGS_t;

u8  Calc_u8OperandsNum, Calc_u8OperatorsNum, Calc_Au8Op_Arr[CALC_EIGHT];
u32 Calc_Au32NumArr[CALC_NINE];
u32 Calc_u32InputNum;
/*********************      Globals Section End    *********************/

/*********************      Prototypes Section Start    *********************/
void calc_voidGetOperandsNum(void);
void calc_voidCalculation(void);
void calc_voidShift_num(u8 Copy_u8Position);
void calc_voidShift_op(u8 Copy_u8Position);
/*********************      Prototypes Section Start    *********************/


#endif /* APP_CALCULATOR_H_ */
