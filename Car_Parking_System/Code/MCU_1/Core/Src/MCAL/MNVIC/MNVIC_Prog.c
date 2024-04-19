/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : NVIC_Driver
File    : Program File
Version : 1.0
Date	: 13/8/2023
********************************************************************************************************
********************************************************************************************************/

/************************** Includes *****************************/
/*****************************************************************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "MNVIC_Config.h"
#include "MNVIC_Int.h"
#include "MNVIC_Private.h"

/********************** Global Variables *************************/
/*****************************************************************/

u32 Global_u32SetGroupPriority;

/******************** Function Definitions ***********************/
/*****************************************************************/

/*
 * Function: 	Enable External Interrupts
 * Inputs: 		Interrupt ID
 * Outputs:		None
 */

void MNVIC_vInterruptSetEnable(u8 Copy_u8InterruptID){
	NVIC -> ISER[Copy_u8InterruptID / REGISTER_BITS] |= (1<<(Copy_u8InterruptID % REGISTER_BITS));
}

/*
 * Function: 	Disable External Interrupts
 * Inputs: 		Interrupt ID
 * Outputs:		None
 */

void MNVIC_vInterruptClearEnable(u8 Copy_u8InterruptID){
	NVIC -> ICER[Copy_u8InterruptID / REGISTER_BITS] |= (1<<(Copy_u8InterruptID % REGISTER_BITS));
}

/*
 * Function: 	Set Group Mode in SCB (AIRCR)
 * Inputs: 		Group Mode
 * Outputs:		None
 */

void MNVIC_vSetGroupMode(Group_Mode Copy_GroupMode){
	Global_u32SetGroupPriority = VECTKEY | (Copy_GroupMode << 8);
	AIRCR = Global_u32SetGroupPriority;
}

/*
 * Function: 	Set Interrupt Software Priority
 * Inputs: 		1- Interrupt ID
 * 				2- Group ID
 * 				3- Subgroup ID
 * Outputs:		None
 */

void MNVIC_vSetInterruptPriority(u8 Copy_u8InterruptID, u8 Copy_GroupID, u8 Copy_SubGroupID){
	u8 u8_PrioValue = 0;
	switch (Global_u32SetGroupPriority){
	case MNVIC_G16_SG0: u8_PrioValue = Copy_GroupID; break;
	case MNVIC_G8_SG2: 	u8_PrioValue = (Copy_GroupID << 1) | Copy_SubGroupID; break;
	case MNVIC_G4_SG4: 	u8_PrioValue = (Copy_GroupID << 2) | Copy_SubGroupID; break;
	case MNVIC_G2_SG8: 	u8_PrioValue = (Copy_GroupID << 3) | Copy_SubGroupID; break;
	case MNVIC_G0_SG16: u8_PrioValue = Copy_SubGroupID; break;
	}
	NVIC -> IPR [Copy_u8InterruptID] = (u8_PrioValue << 4);
}

void MNVIC_voidDisableInterruptPending(u8 Copy_u8InterruptID){
	NVIC->ICPR[Copy_u8InterruptID / 32] = (1U << Copy_u8InterruptID % 32);
}


