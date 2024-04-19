/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : DMA_Driver
File    : Interface File
Version : 1.0
Date	: 29/8/2023
********************************************************************************************************
********************************************************************************************************/

#ifndef MDMA_INTERFACE_H_
#define MDMA_INTERFACE_H_

/*****************************************************************/
/************************** Includes *****************************/
/*****************************************************************/

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

/*****************************************************************/
/************************* Definitions ***************************/
/*****************************************************************/

typedef enum{
	Stream0,
	Stream1,
	Stream2,
	Stream3,
	Stream4,
	Stream5,
	Stream6,
	Stream7
}Stream_No;

/*****************************************************************/
/******************** Function Prototypes ************************/
/*****************************************************************/

void DMA_Configuration(Stream_No Stream_ID);

#endif /* MDMA_INTERFACE_H_ */