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
#include "HAL/LCD/LCD.h"
#include "HAL/KEYPAD/Keypad.h"
#include "HAL/Comms/Communication.h"

/*******************************************************************************************************/
/**************************************** GLOBAL VARIABLES *********************************************/
/*******************************************************************************************************/

s32 Price[3] = {0};

u8 dummy_comms_val = 0;

u8 success = 2;

u8 g_rec_flag = 0;

u8 g_get_amount = 0;

/*******************************************************************************************************/
/*************************************** CALLBACK FUNCTIONS ********************************************/
/*******************************************************************************************************/

void Parking_3(void){
	if(Price[2] != 0){
		LCD_displayStringRowColumn(0, 0, "Please Pay: ");
		LCD_moveCursor(1, 0);
		LCD_intgerToString(Price[2]);
		LCD_displayString(" LE");
		LCD_displayStringRowColumn(0, 0, "Amount Paid: ");
		g_get_amount = 3;
	}
}

void Parking_2(void){
	if(Price[1] != 0){
		LCD_displayStringRowColumn(0, 0, "Please Pay: ");
		LCD_moveCursor(1, 0);
		LCD_intgerToString(Price[1]);
		LCD_displayString(" LE");
		LCD_displayStringRowColumn(0, 0, "Amount Paid: ");
		g_get_amount = 2;
	}
}

void Parking_1(void){
	if(Price[0] != 0){
		LCD_displayStringRowColumn(0, 0, "Please Pay: ");
		LCD_moveCursor(1, 0);
		LCD_intgerToString(Price[0]);
		LCD_displayString(" LE");
		LCD_displayStringRowColumn(0, 0, "Amount Paid: ");
		g_get_amount = 1;
	}
}

void SaveData(void){
	volatile static u8 Park_ID;
	if(g_rec_flag == 0){
		Park_ID = 0;
		Park_ID = Comms_Read_Write(USART_1, &dummy_comms_val, 1, READ);
		g_rec_flag = 1;
	}
	else if(g_rec_flag == 1){
		Price[Park_ID - 1] = Comms_Read_Write(USART_1, &dummy_comms_val, 1, READ);
		g_rec_flag = 0;
	}
}

/*******************************************************************************************************/
/************************************** ADDITIONAL FUNCTIONS *******************************************/
/*******************************************************************************************************/

void Give_LeftOver(s32 Amount){
	LCD_clearScreen();
	LCD_displayStringRowColumn(0, 0, "Take Change: ");
	LCD_moveCursor(1, 0);
	LCD_intgerToString(Amount);
	LCD_displayString(" LE");
	_delay_ms(500);
	LCD_clearScreen();
}

s32 Get_Amount(u8 Park_No){
	s32 total = 0;
	s32 net = 0;
	LCD_displayStringRowColumn(1, 0, "             ");
	LCD_moveCursor(1, 0);
	while(1){
		s32 key =0;
		key = KEYPAD_getPressedKey();
		if(key == '='){
			break;
		}
		LCD_intgerToString(key);
		total = (total * 10) + key;
		_delay_ms(500);
	}
	if(Price[Park_No - 1] > 0){
		net = (total - Price[Park_No - 1]);
	}
	else{
		net = (total + Price[Park_No - 1]);
	}
	if(net < 0){
		Price[Park_No -1] = net;
	}
	else{
		g_get_amount = 0;
		Price[Park_No -1] = 0;
	}
	return net;
}

/*******************************************************************************************************/
/***************************************** MAIN FUNCTIONS **********************************************/
/*******************************************************************************************************/

int main(void)
{
	s32 amount_left = -1;
	/************ Clock Initialization ****************/

	MRCC_vInit();

	/************* PB Initialization *****************/

	PB_InterruptInit(PORT_A, PIN_0, PULL_UP, FALLING_TRIGGER, Parking_1, 0, 0);					/* 1 PB */
	PB_InterruptInit(PORT_A, PIN_1, PULL_UP, FALLING_TRIGGER, Parking_2, 0, 0);					/* 2 PB */
	PB_InterruptInit(PORT_A, PIN_2, PULL_UP, FALLING_TRIGGER, Parking_3, 0, 0);					/* 3 PB */

	/************* LCD Initialization ****************/

	LCD_init();

	/*************** UART Initialization *************/

	Comms_Init(USART_1, 9600);
	Comms_Enable_Disable(USART_1, ENABLE);
	Comms_SetCallBack(USART_1, SaveData);

	while (1)
	{
    	if(g_get_amount){
    		amount_left = Get_Amount(g_get_amount);
    		if(amount_left == 0){
    			LCD_clearScreen();
    			LCD_displayStringRowColumn(0, 0, "Thank You");
    			Comms_Read_Write(USART_1, &success, 1, WRITE);
    			amount_left = -1;
    			_delay_ms(500);
    			LCD_clearScreen();
    		}
    		else if(amount_left > 0){
    			Give_LeftOver(amount_left);
    			Comms_Read_Write(USART_1, &success, 1, WRITE);
    			amount_left = -1;
    		}
    		else if (amount_left < 0 && g_get_amount){
    			LCD_moveCursor(1, 0);
    			LCD_intgerToString(amount_left);
    			LCD_displayString(" LE Left");
    		}
    	}
	}

}
