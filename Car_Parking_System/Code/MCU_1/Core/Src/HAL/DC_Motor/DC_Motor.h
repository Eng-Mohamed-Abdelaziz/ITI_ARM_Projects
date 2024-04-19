/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
LAYER   : HAL
DRIVER  : DC Motor Driver
File    : Header File
Version : 1.0
Date	: 23/8/2023
********************************************************************************************************
********************************************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

/************************** Includes *****************************/
/*****************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/MGPIO/MGPIO_Interface.h"

typedef enum{
	CW,
	A_CW,
	STOP
}DC_Mode;

#define GATE_IN					0

#define GATE_IN_MOTOR_PORT 		_GPIOA_PORT

#define GATE_IN_MOTOR_IN1		_PIN_1
#define GATE_IN_MOTOR_IN2		_PIN_2
#define GATE_IN_MOTOR_EN1		_PIN_3

#define GATE_OUT				1

#define GATE_OUT_MOTOR_PORT 	_GPIOA_PORT

#define GATE_OUT_MOTOR_IN1		_PIN_11
#define GATE_OUT_MOTOR_IN2		_PIN_12
#define GATE_OUT_MOTOR_EN1		_PIN_8

void DC_Motor_Init(void);

void DC_Motor_Rotate(u8 Gate, DC_Mode Mode);

#endif /* DC_MOTOR_H_ */
