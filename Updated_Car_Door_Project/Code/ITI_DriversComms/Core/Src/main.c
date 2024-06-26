/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : APPLICATION
File    : Main File
Version : 1.0
Date	: 14/8/2023
********************************************************************************************************
********************************************************************************************************/

/*******************************************************************************************************/
/**************************************** DRIVER INCLUDES **********************************************/
/*******************************************************************************************************/

#include "HAL/Buzzer_Control/Buzzer_Control.h"
#include "HAL/DC_Motor/DC_Motor.h"
#include "HAL/Comms/Communication.h"
#include "HAL/LED_Control/LED_Control.h"
#include "HAL/PB_Control/PB_Control.h"

/*******************************************************************************************************/
/**************************************** GLOBAL VARIABLES *********************************************/
/*******************************************************************************************************/

u8 g_DoorOpen = 1;

/*******************************************************************************************************/
/***************************************** MAIN FUNCTIONS **********************************************/
/*******************************************************************************************************/

void PB_vPressed(void){
	g_DoorOpen = 0;
}

int main(void)
{
	u8 Data_Received;

	/************ Clock Initialization ****************/

	MRCC_vInit();

	/************* PB Initialization *****************/

	PB_InterruptInit(PORT_A, PIN_0, PULL_UP, FALLING_TRIGGER, PB_vPressed, 0, 0);

	/************* LED Initialization *****************/

	LED_init(PORT_A, PIN_1);

	/************* LED Initialization *****************/

	Buzzer_init(PORT_A, PIN_4);

	/************* USART Configuration ****************/

	Comms_Init(USART_1, 9600);

	while (1){
		Data_Received = Comms_Read_Write(USART_1, 0, 1, 0, READ);
		if((Data_Received == 2) && (g_DoorOpen == 1)){
			LED_ON(PORT_A, PIN_1);
			Buzzer_ON(PORT_A, PIN_4);
		}
		else{
			LED_OFF(PORT_A, PIN_1);
			Buzzer_OFF(PORT_A, PIN_4);
		}
		if(PB_Read(PORT_A, PIN_0)){
			g_DoorOpen = 1;
		}
	}
}
