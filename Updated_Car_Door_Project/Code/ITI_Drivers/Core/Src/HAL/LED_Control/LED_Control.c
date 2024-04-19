/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
LAYER   : HAL
DRIVER  : LED Control Driver
File    : Source File
Version : 1.0
Date	: 23/8/2023
********************************************************************************************************
********************************************************************************************************/

#include "LED_Control.h"

void LED_init(u8 PORT, u8 PIN){
	MRCC_vEnableClock(AHB1, PORT);
	MGPIO_voidSetPinMode(PORT,  PIN, _MODE_OUTPUT);
}

void LED_ON(u8 PORT, u8 PIN){
	MGPIO_voidWriteData(PORT, PIN, _HIGH);
}

void LED_OFF(u8 PORT, u8 PIN){
	MGPIO_voidWriteData(PORT, PIN, _LOW);
}
