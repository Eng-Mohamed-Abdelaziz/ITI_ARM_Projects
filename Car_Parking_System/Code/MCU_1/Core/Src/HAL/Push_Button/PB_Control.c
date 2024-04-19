/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
LAYER   : HAL
DRIVER  : PB Control Driver
File    : Source File
Version : 1.0
Date	: 23/8/2023
********************************************************************************************************
********************************************************************************************************/

#include "../Push_Button/PB_Control.h"

void PB_Init(u8 PORT, u8 PIN, u8 PULL){
	MRCC_vEnableClock(AHB1, PORT);
	MGPIO_voidSetPinMode(PORT, PIN, _MODE_INPUT);
	MGPIO_voidSetPullType(PORT, PIN, PULL);
}

void PB_InterruptInit(u8 PORT, u8 PIN, u8 PULL, u8 TRIGGER, void (*PB_ptr)(void), u8 IntGroup_ID, u8 IntPriority_ID){
	MRCC_vEnableClock(AHB1, PORT);
	MRCC_vEnableClock(APB2, RCC_SYSCFG_EN);
	MGPIO_voidSetPinMode(PORT, PIN, _MODE_INPUT);
	MGPIO_voidSetPullType(PORT, PIN, PULL);
	MNVIC_vSetGroupMode(MNVIC_G4_SG4);
	if(PIN < 5){
		MNVIC_vInterruptSetEnable(PIN + 6);
		MNVIC_vSetInterruptPriority(PIN + 6, IntGroup_ID, IntPriority_ID);
	}
	else if(PIN < 10){
		/* EXTI5-9 are at Position 23*/
		MNVIC_vInterruptSetEnable(23);
		MNVIC_vSetInterruptPriority(23, IntGroup_ID, IntPriority_ID);
	}
	else if (PIN < 16){
		/* EXTI10-15 are at Position 40*/
		MNVIC_vInterruptSetEnable(40);
		MNVIC_vSetInterruptPriority(40, IntGroup_ID, IntPriority_ID);
	}
	MEXTI_vHWInterruptEnable(PIN);
	MEXTI_vSetTriggerType(PIN, TRIGGER);
	MEXTI_vSetExtiConfig(PIN, ((PORT == _GPIOH_PORT)? PORT += 2 : PORT) );
	MEXTI_vSetCallback(PIN, PB_ptr);
}

u8 PB_Read(u8 PORT, u8 PIN){
	return MGPIO_u8ReadData(PORT, PIN);
}
