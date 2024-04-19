/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : SPI_Driver
File    : Interface File
Version : 1.0
Date	: 24/8/2023
********************************************************************************************************
********************************************************************************************************/

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"


/************************ Peripheral Status ***********************/

#define MSPI_DISABLE			0
#define MSPI_ENABLE				1

/*************************** Clock Mode ***************************/

#define MSPI_MODE0 				0
#define MSPI_MODE1 				1
#define MSPI_MODE2 				2
#define MSPI_MODE3				3

/************************** Master/Slave **************************/

#define MSPI_MASTER 			0
#define MSPI_SLAVE				1

/*************************** Data Order ***************************/

#define MSPI_MSB_FIRST 			0
#define MSPI_LSB_FIRST 			1

/************************* SS Management **************************/

#define HW_SLAVE_MANAGEMENT 	0
#define SW_SLAVE_MANAGEMENT		1

/**************************** Data Size ***************************/

#define MSPI_8BIT_DATA 			0
#define MSPI_16BIT_DATA			1

/************************* Interrupt Status ***********************/

#define MSPI_INT_DISABLE  		0
#define MSPI_TXE_INT_ENABLE 	1
#define MSPI_RXNE_INT_ENABLE	2

/************************* SPI Frequency ***********************/

#define MSPI_FPCLK_2			0
#define MSPI_FPCLK_4			1
#define MSPI_FPCLK_8			2
#define MSPI_FPCLK_16			3
#define MSPI_FPCLK_32			4
#define MSPI_FPCLK_64			5
#define MSPI_FPCLK_128			6
#define MSPI_FPCLK_256			7

/************************** SPI1 ******************************/

void MSPI1_voidInit 			(       void	  );

u8	 MSPI1_u8SendData		(  u8 Copy_u8Data );

void MSPI1_voidSetCallBack	(void(*Cptr)(void));

/************************** SPI2 ******************************/

void MSPI2_voidInit 			(       void	  );

u8	 MSPI2_u8SendData		(  u8 Copy_u8Data );

void MSPI2_voidSetCallBack	(void(*Cptr)(void));

/************************** SPI3 ******************************/

void MSPI3_voidInit 			(       void	  );

u8	 MSPI3_u8SendData		(  u8 Copy_u8Data );

void MSPI3_voidSetCallBack	(void(*Cptr)(void));

/************************** SPI4 ******************************/

void MSPI4_voidInit 			(       void	  );

u8	 MSPI4_u8SendData		(  u8 Copy_u8Data );

void MSPI4_voidSetCallBack	(void(*Cptr)(void));

#endif /* MSPI_INTERFACE_H_ */
