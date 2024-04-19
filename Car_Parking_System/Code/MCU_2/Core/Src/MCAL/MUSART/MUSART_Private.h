/*********************************************************************************************************
**********************************************************************************************************
AUTHOR  : Mohanad Hany
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : USART_Driver
File    : Private File
Version :1.0
********************************************************************************************************
*******************************************************************************************************/

#ifndef MCAL_MUSART_MUSART_PRIVATE_H_
#define MCAL_MUSART_MUSART_PRIVATE_H_

/************************************8*** Base Addresses ********************************************
****************************************************************************************************/

#define USART1_BASE_ADDRESS		0x40011000
#define USART2_BASE_ADDRESS		0x40004400
#define USART6_BASE_ADDRESS		0x40011400

/********************************** Struct for UART registers *************************************
****************************************************************************************************/

typedef struct{

	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;

}USART_t;

/********************************** Struct for CR bits *************************************
****************************************************************************************************/

typedef enum{
	SBK,
	RWU,
	RE,
	TE,
	IDLEIE,
	RXNEIE,
	TCIE,
	TXEIE,
	PEIE,
	PS,
	PCE,
	WAKE,
	M,
	UE,
	Reserved1,
	OVER8

}USART_CR1;

/********************************** Pointers to base address ***************************************/
/***************************************************************************************************/

#define MUSART1	((volatile USART_t*)USART1_BASE_ADDRESS)
#define MUSART2	((volatile USART_t*)USART2_BASE_ADDRESS)
#define MUSART6	((volatile USART_t*)USART6_BASE_ADDRESS)

#define UART_HSI		16000000


#endif /* MCAL_MUSART_MUSART_PRIVATE_H_ */
