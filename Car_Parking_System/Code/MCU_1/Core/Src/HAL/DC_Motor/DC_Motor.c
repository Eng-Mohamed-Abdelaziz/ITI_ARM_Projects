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
	MGPIO_voidSetPinMode(GATE_IN_MOTOR_PORT,  GATE_IN_MOTOR_IN1, _MODE_OUTPUT);
	MGPIO_voidSetPinMode(GATE_IN_MOTOR_PORT,  GATE_IN_MOTOR_IN2, _MODE_OUTPUT);
	MGPIO_voidSetPinMode(GATE_IN_MOTOR_PORT,  GATE_IN_MOTOR_EN1, _MODE_OUTPUT);

	MGPIO_voidSetPinMode(GATE_OUT_MOTOR_PORT,  GATE_OUT_MOTOR_IN1, _MODE_OUTPUT);
	MGPIO_voidSetPinMode(GATE_OUT_MOTOR_PORT,  GATE_OUT_MOTOR_IN2, _MODE_OUTPUT);
	MGPIO_voidSetPinMode(GATE_OUT_MOTOR_PORT,  GATE_OUT_MOTOR_EN1, _MODE_OUTPUT);
}

void DC_Motor_Rotate(u8 Gate, DC_Mode Mode){
	switch(Gate){
	case GATE_IN:
		switch(Mode){
		case CW:
			MGPIO_voidWriteData(GATE_IN_MOTOR_PORT, GATE_IN_MOTOR_IN1, _HIGH);
			MGPIO_voidWriteData(GATE_IN_MOTOR_PORT, GATE_IN_MOTOR_IN2, _LOW);
			MGPIO_voidWriteData(GATE_IN_MOTOR_PORT, GATE_IN_MOTOR_EN1, _HIGH);
			break;
		case A_CW:
			MGPIO_voidWriteData(GATE_IN_MOTOR_PORT, GATE_IN_MOTOR_IN1, _LOW);
			MGPIO_voidWriteData(GATE_IN_MOTOR_PORT, GATE_IN_MOTOR_IN2, _HIGH);
			MGPIO_voidWriteData(GATE_IN_MOTOR_PORT, GATE_IN_MOTOR_EN1, _HIGH);
			break;
		case STOP:
			MGPIO_voidWriteData(GATE_IN_MOTOR_PORT, GATE_IN_MOTOR_IN1, _LOW);
			MGPIO_voidWriteData(GATE_IN_MOTOR_PORT, GATE_IN_MOTOR_IN2, _LOW);
			MGPIO_voidWriteData(GATE_IN_MOTOR_PORT, GATE_IN_MOTOR_EN1, _LOW);
			break;
		default:
			break;
		}
		break;
	case GATE_OUT:
		switch(Mode){
		case CW:
			MGPIO_voidWriteData(GATE_OUT_MOTOR_PORT, GATE_OUT_MOTOR_IN1, _HIGH);
			MGPIO_voidWriteData(GATE_OUT_MOTOR_PORT, GATE_OUT_MOTOR_IN2, _LOW);
			MGPIO_voidWriteData(GATE_OUT_MOTOR_PORT, GATE_OUT_MOTOR_EN1, _HIGH);
			break;
		case A_CW:
			MGPIO_voidWriteData(GATE_OUT_MOTOR_PORT, GATE_OUT_MOTOR_IN1, _LOW);
			MGPIO_voidWriteData(GATE_OUT_MOTOR_PORT, GATE_OUT_MOTOR_IN2, _HIGH);
			MGPIO_voidWriteData(GATE_OUT_MOTOR_PORT, GATE_OUT_MOTOR_EN1, _HIGH);
			break;
		case STOP:
			MGPIO_voidWriteData(GATE_OUT_MOTOR_PORT, GATE_OUT_MOTOR_IN1, _LOW);
			MGPIO_voidWriteData(GATE_OUT_MOTOR_PORT, GATE_OUT_MOTOR_IN2, _LOW);
			MGPIO_voidWriteData(GATE_OUT_MOTOR_PORT, GATE_OUT_MOTOR_EN1, _LOW);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
