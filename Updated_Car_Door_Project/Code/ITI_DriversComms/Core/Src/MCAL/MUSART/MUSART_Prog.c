/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : USART_Driver
File    : Program File
Version : 1.0
Date	: 23/8/2023
********************************************************************************************************
********************************************************************************************************/

/************************** Includes *****************************/
/*****************************************************************/

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "MUSART_Config.h"
#include "MUSART_Interface.h"
#include "MUSART_Private.h"

/********************** Callback Functions ***********************/
/*****************************************************************/

static void (* USART1_Callback)(void) = NULL_ptr;

static void (* USART2_Callback)(void) = NULL_ptr;

static void (* USART6_Callback)(void) = NULL_ptr;

/******************** Function Definitions ***********************/
/*****************************************************************/

/*******************************************************************************************************/
/*                                       01- MUSART_voidInit                                           */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to initialize USART with specified Baud rate		               */
/* 2- Function Input       -> 1- USART Number          												   */
/* 							  2- Baud Rate                                                             */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MUSART_voidInit(USARTx X, u16 Copy_u8BaudRate){
	float BRR_floatvalue, BRR_fractionvalue;
	u16 BRR_value;
	u8  BRR_Fraction;
#ifdef UART_HSI
	BRR_floatvalue = SYSCLK_HSI / (16 * Copy_u8BaudRate);
#endif
#ifdef UART_HSE
	BRR_floatvalue = SYSCLK_HSE / (16 * Copy_u8BaudRate);
#endif
	BRR_value = (u16) BRR_floatvalue;
	BRR_fractionvalue = BRR_floatvalue - BRR_value;
	BRR_Fraction = BRR_fractionvalue * 16;
	switch(X){
	case USART1:
		MUSART1 -> BRR = (BRR_value << 4) | (BRR_Fraction);

		MUSART1 -> CR1.OVER8 = 0;

		MUSART1 -> CR1.M = 0;

		MUSART1 -> CR1.PCE = 0;

		CLR_BIT(MUSART1 -> CR2, 12);
		CLR_BIT(MUSART1 -> CR2, 13);

		MUSART1 -> CR1.TE = 1;

		MUSART1 -> CR1.RE = 1;

		MUSART1 -> CR1.RXNEIE = 0;
		break;
	case USART2:
		MUSART2 -> BRR = (BRR_value << 4) | (BRR_Fraction);

		MUSART2 -> CR1.OVER8 = 0;

		MUSART2 -> CR1.M = 0;

		MUSART2 -> CR1.PCE = 0;

		CLR_BIT(MUSART2 -> CR2, 12);
		CLR_BIT(MUSART2 -> CR2, 13);

		MUSART2 -> CR1.TE = 1;

		MUSART2 -> CR1.RE = 1;

		MUSART2 -> CR1.RXNEIE = 1;
		break;
	case USART6:
		MUSART6 -> BRR = (BRR_value << 4) | (BRR_Fraction);

		MUSART6 -> CR1.OVER8 = 0;

		MUSART6 -> CR1.M = 0;

		MUSART6 -> CR1.PCE = 0;

		CLR_BIT(MUSART6 -> CR2, 12);
		CLR_BIT(MUSART6 -> CR2, 13);

		MUSART6 -> CR1.TE = 1;

		MUSART6 -> CR1.RE = 1;

		MUSART6 -> CR1.RXNEIE = 1;
		break;
	default:
		break;
	}
}

/*******************************************************************************************************/
/*                                     02- MUSART_voidSendData                                         */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to transmit data through UART				                   */
/* 2- Function Input       -> 1- USART Number          												   */
/* 							  2- Data  		                                                           */
/* 							  3- Data Length  		                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MUSART_voidSendData(USARTx X, u8* Copy_u8Data, u8 Copy_u8Len){
	switch(X){
	case USART1:
		for (u8 Copy_u8Iterator = 0; Copy_u8Iterator < Copy_u8Len; Copy_u8Iterator++ ){
			MUSART1 -> DR = Copy_u8Data[Copy_u8Iterator];
			while(MUSART1 -> SR.TXE == 0);
		}
		break;
	case USART2:
		for (u8 Copy_u8Iterator = 0; Copy_u8Iterator < Copy_u8Len; Copy_u8Iterator++ ){
			MUSART2 -> DR = Copy_u8Data[Copy_u8Iterator];
			while(MUSART2 -> SR.TXE == 0);
		}
		break;
	case USART6:
		for (u8 Copy_u8Iterator = 0; Copy_u8Iterator < Copy_u8Len; Copy_u8Iterator++ ){
			MUSART6 -> DR = Copy_u8Data[Copy_u8Iterator];
			while(MUSART6 -> SR.TXE == 0);
		}
		break;
	default:
		break;
	}

}

/*******************************************************************************************************/
/*                                    03- MUSART_voidSendString                                        */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to transmit string through UART				                   */
/* 2- Function Input       -> 1- USART Number          												   */
/* 							  2- String  		                                                       */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MUSART_voidSendString(USARTx X, u8* Copy_u8Data){
	u8 iterator = 0;
	switch(X){
	case USART1:
		while(Copy_u8Data[iterator] != '\0'){
			MUSART1 -> DR = Copy_u8Data[iterator];
			while(MUSART1 -> SR.TC == 0);
			iterator++;
		}
		break;
	case USART2:
		while(Copy_u8Data[iterator] != '\0'){
			MUSART2 -> DR = Copy_u8Data[iterator];
			while(MUSART2 -> SR.TC == 0);
			iterator++;
		}
		break;
	case USART6:
		while(Copy_u8Data[iterator] != '\0'){
			MUSART6 -> DR = Copy_u8Data[iterator];
			while(MUSART6 -> SR.TC == 0);
			iterator++;
		}
		break;
	default:
		break;
	}

}

/*******************************************************************************************************/
/*                                      04- MUSART_u8ReadData                                          */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to receive data through UART					                   */
/* 2- Function Input       -> USART Number          												   */
/* 3- Function Return      -> Received Data                                                            */
/*******************************************************************************************************/

u8 MUSART_u8ReadData(USARTx X){
	u16 local_u16Timeout = 0;
	u8  local_u8ReceivedData = 0;
	switch(X){
	case USART1:
		while(MUSART1 -> SR.RXNE == 0){
			local_u16Timeout++;
			if(local_u16Timeout == 10000){
				local_u8ReceivedData = 255;
				break;
			}
		}
		local_u8ReceivedData = (u8) MUSART1 -> DR;
		return local_u8ReceivedData;
		break;
	case USART2:
		while(MUSART2 -> SR.RXNE == 0){
			local_u16Timeout++;
			if(local_u16Timeout == 10000){
				local_u8ReceivedData = 255;
				break;
			}
		}
		local_u8ReceivedData = (u8) MUSART2 -> DR;
		return local_u8ReceivedData;
		break;
	case USART6:
		while(MUSART6 -> SR.RXNE == 0){
			local_u16Timeout++;
			if(local_u16Timeout == 10000){
				local_u8ReceivedData = 255;
				break;
			}
		}
		local_u8ReceivedData = (u8) MUSART6 -> DR;
		return local_u8ReceivedData;
		break;
	default:
		return 0;
		break;
	}

}

/*******************************************************************************************************/
/*                                      05- MUSART_voidEnable                                          */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to enable UART								                   */
/* 2- Function Input       -> USART Number          												   */
/* 3- Function Return      -> Nothing 	                                                               */
/*******************************************************************************************************/

void MUSART_voidEnable(USARTx X){
	switch(X){
	case USART1:
		MUSART1 -> CR1.UE = 1;
		break;
	case USART2:
		MUSART2 -> CR1.UE = 1;
		break;
	case USART6:
		MUSART6 -> CR1.UE = 1;
		break;
	default:
		break;
	}
}

/*******************************************************************************************************/
/*                                      06- MUSART_voidDisable                                         */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to disable UART								                   */
/* 2- Function Input       -> USART Number          												   */
/* 3- Function Return      -> Nothing 	                                                               */
/*******************************************************************************************************/

void MUSART_voidDisable(USARTx X){
	switch(X){
	case USART1:
		MUSART1 -> CR1.UE = 0;
		break;
	case USART2:
		MUSART2 -> CR1.UE = 0;
		break;
	case USART6:
		MUSART6 -> CR1.UE = 0;
		break;
	default:
		break;
	}
}

/*******************************************************************************************************/
/*                                      07- MUSART_voidCallBack                                        */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to set the callback function to a certain UART	               */
/* 2- Function Input       -> 1- USART Number          												   */
/* 							  2- Pointer to function of user                                           */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MUSART_voidCallBack(USARTx X, void(*Fptr)(void)){
	switch (X){
	case USART1:
		USART1_Callback = Fptr;
		break;
	case USART2:
		USART2_Callback = Fptr;
		break;
	case USART6:
		USART6_Callback = Fptr;
		break;
	default:
		break;
	}
}

void USART1_IRQHandler (void){
	USART1_Callback();

}

void USART2_IRQHandler (void){
	USART2_Callback();

}

void USART6_IRQHandler (void){
	USART6_Callback();

}
