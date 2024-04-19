/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
LAYER   : HAL
DRIVER  : Communication Driver
File    : Header File
Version : 1.0
Date	: 3/9/2023
********************************************************************************************************
********************************************************************************************************/

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

/*******************************************************************************************************/
/**************************************** DRIVER INCLUDES **********************************************/
/*******************************************************************************************************/

#include "../../MCAL/MRCC/MRCC_Int.h"
#include "../../MCAL/MGPIO/MGPIO_Interface.h"
#include "../../MCAL/MNVIC/MNVIC_Int.h"
#include "../../MCAL/MUSART/MUSART_Int.h"
#include "../../MCAL/MSPI/MSPI_Interface.h"

#define DISABLE					0
#define ENABLE					1

#define READ					0
#define WRITE					1

typedef enum{
	USART_1,
	USART_2,
	USART_6,
	SPI_1,
	SPI_2,
	SPI_3,
	SPI_4
}Type_Comms;

void Comms_Init(Type_Comms Comms_Type, u16 Baudrate);

void Comms_Enable_Disable(Type_Comms Comms_Type, u8 Enable_Disable);

u8 Comms_Read_Write(Type_Comms Comms_Type, u8* USART_Data, u8 Len, /*u8 SPI_Data,*/ u8 W_R);

void Comms_SetCallBack(Type_Comms Comms_Type, void(*Uptr)(void));

#endif /* COMMUNICATION_H_ */
