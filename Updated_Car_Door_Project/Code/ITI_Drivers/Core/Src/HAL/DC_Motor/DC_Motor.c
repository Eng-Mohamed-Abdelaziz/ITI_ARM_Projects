/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
LAYER   : HAL
DRIVER  : DC Motor Driver
File    : Source File
Version : 1.0
Date	: 23/8/2023
********************************************************************************************************
********************************************************************************************************/

#include "DC_Motor.h"

void DC_Motor_Init(void){
	MGPIO_voidSetPinMode(DC_MOTOR_PORT,  DC_MOTOR_PIN_IN1, _MODE_OUTPUT);
	MGPIO_voidSetPinMode(DC_MOTOR_PORT,  DC_MOTOR_PIN_IN2, _MODE_OUTPUT);
	MGPIO_voidSetPinMode(DC_MOTOR_PORT,  DC_MOTOR_PIN_EN1, _MODE_OUTPUT);
}

void DC_Motor_Rotate(DC_Mode Mode){
	switch(Mode){
	case CW:
		MGPIO_voidWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_IN1, _HIGH);
		MGPIO_voidWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_IN2, _LOW);
		MGPIO_voidWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_EN1, _HIGH);
		break;
	case A_CW:
		MGPIO_voidWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_IN1, _LOW);
		MGPIO_voidWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_IN2, _HIGH);
		MGPIO_voidWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_EN1, _HIGH);
		break;
	case STOP:
		MGPIO_voidWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_IN1, _LOW);
		MGPIO_voidWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_IN2, _LOW);
		MGPIO_voidWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_EN1, _LOW);
		break;
	default:
		break;
	}
}
