/*
 * MRCC_Prog.c
 *
 *  Created on: Aug 10, 2023
 *      Author: Mostafa Ashraf
 */

#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_Math.h"

#include "MRCC_Int.h"
#include "MRCC_Private.h"
#include "MRCC_Config.h"

void MRCC_vInit(void)
{
	/*1- CSS (ON/OFF) */

	/*2- HSE_BYP CLR->Oscillator Enable not bypassed, SET->Oscillator Disable bypassed */
	CLR_BIT(RCC -> CR, HSEBYP);

	/*3- select clock switch (HSI/HSE/PLL) */
	SET_BIT(RCC -> CFGR, SW0);

	/*4- Bus prescalers   */

	/*5- PLL configuration */

	/*6- Enable the selected clock (HSI ON / HSE ON / PLL ON)*/
#if RCC_HSE_ENABLE == ENABLE
	SET_BIT(RCC->CR, HSEON);
#endif
#if RCC_HSI_ENABLE == ENABLE
	SET_BIT(RCC->CR, HSION);
#endif
#if RCC_PLL_ENABLE == ENABLE
	SET_BIT(RCC->CR, PLLON);
#endif

}

void MRCC_vEnableClock(RCC_ENR REG, RCC_Peripheral PER)
{
/******************** Assignment *******************************/
	switch(REG){
	case AHB1:
		SET_BIT(RCC -> AHB1ENR ,  PER);
		break;
	case AHB2:
		SET_BIT(RCC -> AHB2ENR ,  PER);
		break;
	case APB1:
		SET_BIT(RCC -> APB1ENR ,  PER);
		break;
	case APB2:
		SET_BIT(RCC -> APB2ENR ,  PER);
		break;
	default:
		break;
	}
}

void MRCC_vDisableClock(RCC_ENR REG, RCC_Peripheral PER)
{
/******************** Assignment *******************************/
	switch(REG){
	case AHB1:
		SET_BIT(RCC -> AHB1ENR ,  PER);
		break;
	case AHB2:
		SET_BIT(RCC -> AHB2ENR ,  PER);
		break;
	case APB1:
		SET_BIT(RCC -> APB1ENR ,  PER);
		break;
	case APB2:
		SET_BIT(RCC -> APB2ENR ,  PER);
		break;
	default:
		break;
	}
}
