/*********************************************************************************************************
**********************************************************************************************************
AUTHOR  : Mohanad Hany
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : USART_Driver
File    : Configuration File
Version :1.0
********************************************************************************************************
*******************************************************************************************************/

#ifndef MCAL_MUSART_MUSART_CONFIG_H_
#define MCAL_MUSART_MUSART_CONFIG_H_

#include"../../LIB/BIT_Math.h"
#include"MUSART_Private.h"

/*
#define TRANSMIT			0
//#define RECIEVE			1
//#define TRANSMIT_RECIEVE	2

#ifdef TRANSMIT
SET_BIT(MUSART1->CR1,TE);
CLR_BIT(MUSART1->CR1,RE);
#endif

#ifdef RECIEVE
SET_BIT(MUSART1->CR1,RE);
CLR_BIT(MUSART1->CR1,RE);
#endif

#ifdef TRANSMIT_RECIEVE
SET_BIT(MUSART1->CR1,TE);
SET_BIT(MUSART1->CR1,RE);
#endif
*/

#endif /* MCAL_MUSART_MUSART_CONFIG_H_ */
