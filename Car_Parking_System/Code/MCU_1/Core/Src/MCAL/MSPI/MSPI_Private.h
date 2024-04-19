/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : SPI_Driver
File    : Private File
Version : 1.0
Date	: 24/8/2023
********************************************************************************************************
********************************************************************************************************/

#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_

/********************************** SPI BASE ADDRESS **********************************/

#define MSPI1_BASE_ADDRESS		(0x40013000)
#define MSPI2_BASE_ADDRESS		(0x40003800)
#define MSPI3_BASE_ADDRESS		(0x40003C00)
#define MSPI4_BASE_ADDRESS		(0x40013400)

/************************************ SPI REGISTERS ***********************************/

typedef struct{
	u32 CPHA		:1;
	u32 CPOL		:1;
	u32 MSTR		:1;
	u32 BR			:3;
	u32 SPE			:1;
	u32 LSBFIRST	:1;
	u32 SSI			:1;
	u32 SSM			:1;
	u32 RXONLY		:1;
	u32 DFF			:1;
	u32 CRCNEXT		:1;
	u32 CRCEN		:1;
	u32 BIDIOE		:1;
	u32 BIDIMODE	:1;
}SPI_CR1;

typedef struct{
	SPI_CR1 	CR1    ;
	u32 		CR2    ;
	u32		 	SR     ;
	u32 		DR     ;
	u32 		CRCPR  ;
	u32			RXCRCR ;
	u32			TXCRCR ;
	u32 		I2SCFGR;
	u32 		I2SPR  ;
}SPI_T;

#define MSPI1  ((volatile SPI_T*)(MSPI1_BASE_ADDRESS))

#define MSPI2  ((volatile SPI_T*)(MSPI2_BASE_ADDRESS))

#define MSPI3  ((volatile SPI_T*)(MSPI3_BASE_ADDRESS))

#define MSPI4  ((volatile SPI_T*)(MSPI4_BASE_ADDRESS))

#endif /* MSPI_PRIVATE_H_ */
