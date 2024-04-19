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

#define DC_MOTOR_PORT 			_GPIOA_PORT

#define DC_MOTOR_PIN_IN1		_PIN_1
#define DC_MOTOR_PIN_IN2		_PIN_2
#define DC_MOTOR_PIN_EN1		_PIN_3

void DC_Motor_Init(void);

void DC_Motor_Rotate(DC_Mode Mode);

#endif /* DC_MOTOR_H_ */
