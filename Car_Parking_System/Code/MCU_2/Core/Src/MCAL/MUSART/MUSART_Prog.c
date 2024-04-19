/*********************************************************************************************************
**********************************************************************************************************
AUTHOR  : Mohanad Hany
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : USART_Driver
File    : Program File
Version :1.0
********************************************************************************************************
*******************************************************************************************************/

/***************************************** INCLUDES ************************************************
 ***************************************************************************************************/

#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_Math.h"

#include"MUSART_Config.h"
#include"MUSART_Int.h"
#include"MUSART_Private.h"

/************************************** DECLERATIONS ***********************************************
 ***************************************************************************************************/
static void (*USART_CallBack)(void)=NULL;

/***************************************************************************************************
 ***************************************************************************************************/

/*
Return type = void
Input parameters = u16 copy_u16BaudRate
Functionality : Initializes USART1
*/

void MUSART_voidInit(u32 copy_u32BaudRate){

	/* Configure baud rate */
	float BRR_floatvalue, BRR_fractionvalue;
	u16 BRR_value;
	u8  BRR_Fraction;
#ifdef UART_HSI
	BRR_floatvalue = UART_HSI / (16 * copy_u32BaudRate);
#endif
#ifdef UART_HSE
	BRR_floatvalue = UART_HSE / (16 * copy_u32BaudRate);
#endif
	BRR_value = (u16) BRR_floatvalue;
	BRR_fractionvalue = BRR_floatvalue - BRR_value;
	BRR_Fraction = BRR_fractionvalue * 16;

	MUSART1 -> BRR = (BRR_value << 4) | (BRR_Fraction);

	CLR_BIT(MUSART1->CR1,OVER8);		/*Over sampling by 16*/
	CLR_BIT(MUSART1->CR1,M);
	CLR_BIT(MUSART1->CR1,PCE);
	CLR_BIT(MUSART1->CR2,12);
	CLR_BIT(MUSART1->CR2,13);

	SET_BIT(MUSART1->CR1,TE);
	SET_BIT(MUSART1->CR1,RE);
	SET_BIT(MUSART1->CR1,RXNEIE);


}

/***************************************************************************************************
 ***************************************************************************************************/

/*
Return type = void
Input parameters = u8* copy_u8Data,u8 copy_u8Len
Functionality : Sends data when transmitter data register is not empty
*/

void MUSART_voidSendData(u8* copy_u8Data,u8 copy_u8Len){

	for(u8 i=0;i<copy_u8Len;i++){
		MUSART1->DR=copy_u8Data[i];
		while(GET_BIT(MUSART1->SR,7)==0);
	}

}


/***************************************************************************************************
 ***************************************************************************************************/

/*
Return type = void
Input parameters = u8* copy_u8Data
Functionality : Sends string when transmission data register is not empty
*/

void MUSART_voidSendString(u8* copy_u8Data){
	u8 i=0;
	while(copy_u8Data[i]!='\0'){
		MUSART1->DR=copy_u8Data[i];
		while(GET_BIT(MUSART1->SR,6)==0);
		i++;
	}

}

/***************************************************************************************************
 ***************************************************************************************************/

/*
Return type = u8
Input parameters = void
Functionality : Reads data when read data register is not empty
*/

u8 MUSART_u8ReadData(void){
	//u16 local_u16Timeout=0;
	u8 local_u8RecieveData=0;
	while(GET_BIT(MUSART1->SR,5)==0);
	local_u8RecieveData=(u8) MUSART1->DR;
	return local_u8RecieveData;
}


/***************************************************************************************************
 ***************************************************************************************************/

/*
Return type = void
Input parameters = void
Functionality : Enables USART1
*/

void MUSART_voidEnable(void){
	SET_BIT(MUSART1->CR1,UE);
}

/***************************************************************************************************
 ***************************************************************************************************/

/*
Return type = void
Input parameters = void
Functionality : Disables USART1
*/

void MUSART_voidDisable(void){
	CLR_BIT(MUSART1->CR1,UE);
}

/***************************************************************************************************
 ***************************************************************************************************/

/*
Return type = void
Input parameters = void(*Fptr)(void)
Functionality : Initiates callback for USART1
*/

void MUSART_voidCallBack(void(*Fptr)(void)){
	USART_CallBack=Fptr;
}

/***************************************************************************************************
 ***************************************************************************************************/

/*
Return type = void
Input parameters = void
Functionality : ISR of USART1
*/

void USART1_IRQHandler(void){
	USART_CallBack();
}
