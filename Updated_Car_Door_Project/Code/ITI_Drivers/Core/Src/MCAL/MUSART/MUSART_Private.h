/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : USART_Driver
File    : Private File
Version : 1.0
Date	: 23/8/2023
********************************************************************************************************
********************************************************************************************************/

#ifndef MUSART_PRIVATE_H_
#define MUSART_PRIVATE_H_

#define SYSCLK_HSI					16000000

#define SYSCLK_HSE					8000000

/******************************** USART BASE ADDRESS **********************************/

#define MUSART1_BASE_ADDRESS		(0x40011000)
#define MUSART2_BASE_ADDRESS		(0x40004400)
#define MUSART6_BASE_ADDRESS		(0x40011400)

/********************************** USART REGISTERS ***********************************/

typedef struct{
	u32 PE			:1 ;
	u32 FE			:1 ;
	u32 NF			:1 ;
	u32 ORE			:1 ;
	u32 IDLE		:1 ;
	u32 RXNE		:1 ;
	u32 TC			:1 ;
	u32 TXE			:1 ;
	u32 LBD			:1 ;
	u32 CTS			:1 ;
	u32 RESERVED	:22;
}USART_SR;

typedef struct{
	u32 SBK			:1 ;
	u32 RWU			:1 ;
	u32 RE			:1 ;
	u32 TE			:1 ;
	u32 IDLEIE		:1 ;
	u32 RXNEIE		:1 ;
	u32 TCIE		:1 ;
	u32 TXEIE		:1 ;
	u32 PEIE		:1 ;
	u32 PS			:1 ;
	u32 PCE			:1 ;
	u32 WAKE		:1 ;
	u32 M			:1 ;
	u32 UE			:1 ;
	u32 RESERVED1	:1 ;
	u32 OVER8		:1 ;
	u32 RESERVED2	:16;
}USART_CR1;

typedef struct{
	USART_SR 	SR  ;
	u32 		DR  ;
	u32 		BRR ;
	USART_CR1 	CR1 ;
	u32 		CR2 ;
	u32 		CR3 ;
	u32 		GTPR;
}USART_T;


#define MUSART1  ((volatile USART_T*)(MUSART1_BASE_ADDRESS))

#define MUSART2  ((volatile USART_T*)(MUSART2_BASE_ADDRESS))

#define MUSART6  ((volatile USART_T*)(MUSART6_BASE_ADDRESS))

#endif /* MUSART_PRIVATE_H_ */
