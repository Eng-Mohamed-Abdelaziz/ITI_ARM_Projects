/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
LAYER   : HAL
DRIVER  : Buzzer Control Driver
File    : Source File
Version : 1.0
Date	: 23/8/2023
********************************************************************************************************
********************************************************************************************************/

#include "../Buzzer/Buzzer_Control.h"

void Buzzer_init(u8 PORT, u8 PIN){
	MRCC_vEnableClock(AHB1, PORT);
	MGPIO_voidSetPinMode(PORT,  PIN, _MODE_OUTPUT);
}

void Buzzer_ON(u8 PORT, u8 PIN){
	MGPIO_voidWriteData(PORT, PIN, _HIGH);
}

void Buzzer_OFF(u8 PORT, u8 PIN){
	MGPIO_voidWriteData(PORT, PIN, _LOW);
}
