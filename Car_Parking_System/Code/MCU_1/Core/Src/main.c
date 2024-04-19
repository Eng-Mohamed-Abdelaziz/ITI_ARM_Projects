/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : APPLICATION
File    : Main File
Version : 1.0
Date	: 11/9/2023
********************************************************************************************************
********************************************************************************************************/

/*******************************************************************************************************/
/**************************************** DRIVER INCLUDES **********************************************/
/*******************************************************************************************************/

#include "HAL/Push_Button/PB_Control.h"
#include "HAL/DC_Motor/DC_Motor.h"
#include "HAL/IR/IR_Control.h"
#include "HAL/Comms/Communication.h"
#include "MCAL/MSTK/MSTK_Int.h"

/*******************************************************************************************************/
/**************************************** GLOBAL VARIABLES *********************************************/
/*******************************************************************************************************/

u8 park_1 = 0;

u8 park_2 = 0;

u8 park_3 = 0;

u8 g_rec_p1 = 0;

u8 g_rec_p2 = 0;

u8 g_rec_p3 = 0;

u8 dummy_comms_val = 0;

u8 g_gate_in = 0;

u8 g_gate_out = 0;

/*******************************************************************************************************/
/*************************************** CALLBACK FUNCTIONS ********************************************/
/*******************************************************************************************************/

void Parking_3(void){
	u8 Park_ID = 3;
	if(g_rec_p3 == 0){
		park_3 = 0;
		if(MSTK_u8IsON() == 0){
			MSTK_voidStart(1000);
		}
		g_rec_p3 = 1;
	}
	else if(g_rec_p3 == 1){
		u8 Price = ((10.0) * park_3) / 10.0;
		Comms_Read_Write(USART_1, &Park_ID, 1, WRITE);
		Comms_Read_Write(USART_1, &Price, 1, WRITE);
		g_rec_p3 = 0;
	}
}

void Parking_2(void){
	u8 Park_ID = 2;
	if(g_rec_p2 == 0){
		park_2 = 0;
		if(MSTK_u8IsON() == 0){
			MSTK_voidStart(1000);
		}
		g_rec_p2 = 1;
	}
	else if(g_rec_p2 == 1){
		u8 Price = ((10.0) * park_2) / 10.0;
		Comms_Read_Write(USART_1, &Park_ID, 1, WRITE);
		Comms_Read_Write(USART_1, &Price, 1, WRITE);
		g_rec_p2 = 0;
	}
}

void Parking_1(void){
	u8 Park_ID = 1;
	if(g_rec_p1 == 0){
		park_1 = 0;
		if(MSTK_u8IsON() == 0){
			MSTK_voidStart(1000);
		}
		g_rec_p1 = 1;
	}
	else if(g_rec_p1 == 1){
		u8 Price = ((10.0) * park_1) / 10.0;
		Comms_Read_Write(USART_1, &Park_ID, 1, WRITE);
		Comms_Read_Write(USART_1, &Price, 1, WRITE);
		g_rec_p1 = 0;
	}
}

void Gate_OUT_Open(void){
	if(Comms_Read_Write(USART_1, &dummy_comms_val, 1, READ) == 2){
		g_gate_out = 1;
	}
}

void Gate_OUT_Close(void){
	g_gate_out = 2;
}

void Gate_IN_Close(void){
	g_gate_in = 2;
}

void Gate_IN_Open(void){
		g_gate_in = 1;
}

void Gate_Time(void){
	if(g_rec_p1 == 1){
		park_1 ++;
	}
	if(g_rec_p2 == 1){
		park_2 ++;
	}
	if(g_rec_p3 == 1){
		park_3 ++;
	}
}

/*******************************************************************************************************/
/***************************************** MAIN FUNCTIONS **********************************************/
/*******************************************************************************************************/

int main(void)
{
	/************ Clock Initialization ****************/

	MRCC_vInit();

	/************* PB/IR Initialization ***************/

	/* Gate In PB/IR */

	PB_InterruptInit(PORT_A, PIN_0, PULL_UP, FALLING_TRIGGER, Gate_IN_Open, 0, 0);
	IR_InterruptInit(PORT_A, PIN_4, PULL_UP, RISING_TRIGGER, Gate_IN_Close, 0, 0);

	PB_Init(PORT_A, PIN_6, PULL_UP);
	PB_Init(PORT_A, PIN_7, PULL_UP);

	/* Gate Out IR */

	IR_InterruptInit(PORT_A, PIN_5, PULL_UP, RISING_TRIGGER, Gate_OUT_Close, 0, 0);

	/* Parking Spots IR */

	IR_InterruptInit(PORT_B, PIN_6, PULL_UP, RISING_TRIGGER, Parking_1, 0, 0);
	IR_InterruptInit(PORT_B, PIN_7, PULL_UP, RISING_TRIGGER, Parking_2, 0, 0);
	IR_InterruptInit(PORT_B, PIN_8, PULL_UP, RISING_TRIGGER, Parking_3, 0, 0);

	/************* DC Motor Initialization ***********/

	DC_Motor_Init();

	/************* SysTick Initialization ************/

	MSTK_voidInit();
	MSTK_voidIntState();
	CALLBACKSYS(Gate_Time);

	/*************** UART Initialization *************/

	Comms_Init(USART_1, 9600);
	Comms_Enable_Disable(USART_1, ENABLE);
	Comms_SetCallBack(USART_1, Gate_OUT_Open);

	while (1)
	{
		if((g_gate_in == 1) && (PB_Read(PORT_A, PIN_6) == 1)){
			DC_Motor_Rotate(GATE_IN, CW);
		}
		else if((g_gate_in == 2) && (PB_Read(PORT_A, PIN_7) == 1)){
			DC_Motor_Rotate(GATE_IN, A_CW);
		}
		else if((PB_Read(PORT_A, PIN_6) == 0) || (PB_Read(PORT_A, PIN_7) == 0)){
			g_gate_in = 0;
			DC_Motor_Rotate(GATE_IN, STOP);
		}
		if(g_gate_out == 1){
			DC_Motor_Rotate(GATE_OUT, CW);
		}
		else if(g_gate_out == 2){
			DC_Motor_Rotate(GATE_OUT, A_CW);
		}
	}

}
