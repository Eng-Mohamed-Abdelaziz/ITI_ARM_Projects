/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : DMA_Driver
File    : Private File
Version : 1.0
Date	: 29/8/2023
********************************************************************************************************
********************************************************************************************************/

#ifndef MDMA_PRIVATE_H_
#define MDMA_PRIVATE_H_


/********************************* DMA BASE ADDRESS ***********************************/

#define MDMA1_BASE_ADDRESS		(0x40026000)
#define MDMA2_BASE_ADDRESS		(0x40026400)

/*********************************** DMA REGISTERS ************************************/

typedef struct{
	u32 		FEIF		:1;
	u32 		Reserved	:1;
	u32 		DMEIF		:1;
	u32 		TEIF		:1;
	u32 		HTIF		:1;
	u32 		TCIF		:1;
}DMA_SRx;

typedef struct{
	DMA_SRx		X		;
	DMA_SRx		X1		;
	u32 		Reserved;
	DMA_SRx		X2		;
	DMA_SRx		X3		;
}DMA_SR;

typedef struct{
	u32 		CFEIF		:1;
	u32 		Reserved	:1;
	u32 		CDMEIF		:1;
	u32 		CTEIF		:1;
	u32 		CHTIF		:1;
	u32 		CTCIF		:1;
}DMA_CRx;

typedef struct{
	DMA_CRx		X		;
	DMA_CRx		X1		;
	u32 		Reserved;
	DMA_CRx		X2		;
	DMA_CRx		X3		;
}DMA_CR;

typedef struct{
	u32			EN			:1;
	u32			DMEIE		:1;
	u32			TEIE		:1;
	u32			HTIE		:1;
	u32			TCIE		:1;
	u32			PFCTRL		:1;
	u32			DIR			:2;
	u32			CIRC		:1;
	u32			PINC		:1;
	u32			MINC		:1;
	u32			PSIZE		:2;
	u32			MSIZE		:2;
	u32			PINCOS		:1;
	u32			PL			:2;
	u32			DBM			:1;
	u32			CT			:1;
	u32			Reserved	:1;
	u32			PBURST		:2;
	u32			MBURST		:2;
	u32			CHSEL		:3;
}DMA_SxCR;

typedef struct{
	u32			FTH			:2;
	u32			DMDIS		:1;
	u32			FS			:3;
	u32			Reserved	:1;
	u32			FEIE		:1;
}DMA_SxFCR;

typedef struct{
	DMA_SxCR	CR  ;
	u32			NDTR;
	u32			PAR ;
	u32			M0AR;
	u32			M1AR;
	DMA_SxFCR	FCR ;
}DMA_Sx;

typedef struct{
	DMA_SR		LISR ;
	DMA_SR		HISR ;
	DMA_CR		LIFCR;
	DMA_CR		HIFCR;
	DMA_Sx		S[8]   ;
}DMA_T;

#define MDMA1  ((volatile DMA_T*)(MDMA1_BASE_ADDRESS))

#define MDMA2  ((volatile DMA_T*)(MDMA2_BASE_ADDRESS))

#endif /* MDMA_PRIVATE_H_ */
