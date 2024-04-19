/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : EXTI_Driver
File    : Program File
Version : 1.0
Date	: 13/8/2023
********************************************************************************************************
********************************************************************************************************/

/************************** Includes *****************************/
/*****************************************************************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "MEXTI_Config.h"
#include "MEXTI_Int.h"
#include "MEXTI_Private.h"

/********************** Callback Functions ***********************/
/*****************************************************************/

static void (* EXTI0_Callback)(void) = NULL_ptr;
static void (* EXTI1_Callback)(void) = NULL_ptr;

/******************** Function Definitions ***********************/
/*****************************************************************/


/*******************************************************************************************************/
/*                                  01- MEXTI_vHWInterruptEnable                                       */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to Set the Interrupt mask on for the required Line              */
/* 2- Function Input       -> LINE                                                                     */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MEXTI_vHWInterruptEnable(EXTI_Line_x LINE){
	SET_BIT(EXTI -> IMR , LINE);
}

/*******************************************************************************************************/
/*                                  02- MEXTI_vHWInterruptDisable                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to Set the Interrupt mask off for the required Line             */
/* 2- Function Input       -> LINE                         											   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MEXTI_vHWInterruptDisable(EXTI_Line_x LINE){
	CLR_BIT(EXTI -> IMR , LINE);
}

/*******************************************************************************************************/
/*                                   03- MEXTI_vHWEventEnable                                          */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to Set the Event mask on for the required Line                  */
/* 2- Function Input       -> LINE                                                                     */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MEXTI_vHWEventEnable(EXTI_Line_x LINE){
	SET_BIT(EXTI -> EMR , LINE);
}

/*******************************************************************************************************/
/*                               	   04- MEXTI_vHWEventDisable                                       */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to Set the Event mask off for the required Line                 */
/* 2- Function Input       -> LINE                     												   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MEXTI_vHWEventDisable(EXTI_Line_x LINE){
	CLR_BIT(EXTI -> EMR , LINE);
}

/*******************************************************************************************************/
/*                                  05- MEXTI_vSoftwareInterrupt                                       */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to activate Software Interrupt 					               */
/* 2- Function Input       -> LINE              											           */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MEXTI_vSoftwareInterrupt(EXTI_Line_x LINE){
	SET_BIT(EXTI -> SWIER , LINE);
}

/*******************************************************************************************************/
/*                                    06- MEXTI_vSetTriggerType                                        */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to set the trigger type the interrupt/event will activate on    */
/* 2- Function Input       -> LINE, Trigger              											   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MEXTI_vSetTriggerType(EXTI_Line_x LINE, EXTI_Trigger Trigger){
	switch (Trigger){
	case Rising:
		SET_BIT(EXTI -> RSTR , LINE);
		break;
	case Falling:
		SET_BIT(EXTI -> FSTR , LINE);
		break;
	case Any_Change:
		SET_BIT(EXTI -> RSTR , LINE);
		SET_BIT(EXTI -> FSTR , LINE);
		break;
	default:
		break;
	}
}

/*******************************************************************************************************/
/*                                     07- MEXTI_vSetExtiConfig                                        */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to configure the external interrupt to a port in the            */
/*                            system configuration                                                     */
/* 2- Function Input       -> LINE, PORT              											       */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MEXTI_vSetExtiConfig(EXTI_Line_x LINE, SYSCFG_Port PORT){
	u8 CRx  = LINE / 4;
	u8 line = LINE % 4;
	switch (CRx) {
	case 0:
		switch (line){
		case 0:
			SYSCFG -> EXTICR1 &= EXTI_CONFG_MASK1;
			SYSCFG -> EXTICR1 |= PORT;
			break;
		case 1:
			SYSCFG -> EXTICR1 &= EXTI_CONFG_MASK2;
			SYSCFG -> EXTICR1 |= (PORT <<4);
			break;
		case 2:
			SYSCFG -> EXTICR1 &= EXTI_CONFG_MASK3;
			SYSCFG -> EXTICR1 |= (PORT << 8);
			break;
		case 3:
			SYSCFG -> EXTICR1 &= EXTI_CONFG_MASK4;
			SYSCFG -> EXTICR1 |= (PORT << 12);
			break;
		default:
			break;
		}
		break;
	case 1:
		switch (line){
		case 0:
			SYSCFG -> EXTICR2 &= EXTI_CONFG_MASK1;
			SYSCFG -> EXTICR2 |= PORT;
			break;
		case 1:
			SYSCFG -> EXTICR2 &= EXTI_CONFG_MASK2;
			SYSCFG -> EXTICR2 |= (PORT <<4);
			break;
		case 2:
			SYSCFG -> EXTICR2 &= EXTI_CONFG_MASK3;
			SYSCFG -> EXTICR2 |= (PORT << 8);
			break;
		case 3:
			SYSCFG -> EXTICR2 &= EXTI_CONFG_MASK4;
			SYSCFG -> EXTICR2 |= (PORT << 12);
			break;
		default:
			break;
		}
		break;
	case 2:
		switch (line){
		case 0:
			SYSCFG -> EXTICR3 &= EXTI_CONFG_MASK1;
			SYSCFG -> EXTICR3 |= PORT;
			break;
		case 1:
			SYSCFG -> EXTICR3 &= EXTI_CONFG_MASK2;
			SYSCFG -> EXTICR3 |= (PORT <<4);
			break;
		case 2:
			SYSCFG -> EXTICR3 &= EXTI_CONFG_MASK3;
			SYSCFG -> EXTICR3 |= (PORT << 8);
			break;
		case 3:
			SYSCFG -> EXTICR3 &= EXTI_CONFG_MASK4;
			SYSCFG -> EXTICR3 |= (PORT << 12);
			break;
		default:
			break;
		}
		break;
	case 3:
		switch (line){
		case 0:
			SYSCFG -> EXTICR4 &= EXTI_CONFG_MASK1;
			SYSCFG -> EXTICR4 |= PORT;
			break;
		case 1:
			SYSCFG -> EXTICR4 &= EXTI_CONFG_MASK2;
			SYSCFG -> EXTICR4 |= (PORT <<4);
			break;
		case 2:
			SYSCFG -> EXTICR4 &= EXTI_CONFG_MASK3;
			SYSCFG -> EXTICR4 |= (PORT << 8);
			break;
		case 3:
			SYSCFG -> EXTICR4 &= EXTI_CONFG_MASK4;
			SYSCFG -> EXTICR4 |= (PORT << 12);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

/*******************************************************************************************************/
/*                                     08- MEXTI_vSetCallback                                          */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to set the callback function to the line it will correspond to  */
/* 2- Function Input       -> LINE, *ptr()              											   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MEXTI_vSetCallback(EXTI_Line_x LINE, void(*ptr)(void)){
	switch (LINE) {
	case EXTI_Line_0:
		EXTI0_Callback =ptr;
		break;
	case EXTI_Line_1:
		EXTI1_Callback =ptr;
		break;
	default:
		break;
	}
}

void EXTI0_IRQHandler(void){
	EXTI0_Callback();
	SET_BIT(EXTI -> PR, EXTI_Line_0);
}

void EXTI1_IRQHandler(void){
	EXTI1_Callback();
	SET_BIT(EXTI -> PR, EXTI_Line_1);
}

