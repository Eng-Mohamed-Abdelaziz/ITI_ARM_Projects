/*******************************************************************************************************
 * *****************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : USART_Driver
File    : Interface File
Version : 1.0
Date	: 23/8/2023
********************************************************************************************************
********************************************************************************************************/

#ifndef MUSART_INTERFACE_H_
#define MUSART_INTERFACE_H_

typedef enum{
	USART1,
	USART2,
	USART6
}USARTx;

void MUSART_voidInit(USARTx X, u16 Copy_u8BaudRate);

void MUSART_voidSendData(USARTx X, u8* copy_u8Data, u8 Copy_u8Len);

void MUSART_voidSendString(USARTx X, u8* copy_u8Data);

u8 MUSART_u8ReadData(USARTx X);

void MUSART_voidEnable(USARTx X);

void MUSART_voidDisable(USARTx X);

void MUSART_voidCallBack(USARTx X, void(*Fptr)(void));

#endif /* MUSART_INTERFACE_H_ */
