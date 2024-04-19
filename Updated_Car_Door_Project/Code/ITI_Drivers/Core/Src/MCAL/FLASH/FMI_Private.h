/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : FLASH_Driver
File    : Private File
Version : 1.0
Date	: 3/9/2023
********************************************************************************************************
********************************************************************************************************/

#ifndef FMI_PRIVATE_H_
#define FMI_PRIVATE_H_

/******************************** FLASH BASE ADDRESS **********************************/

#define FLASH_BASE_ADDRESS		(0x40023C00)

/********************************** USART REGISTERS ***********************************/

typedef struct{
	u32		EOP  	:1;
	u32		OPERR	:1;
	u32		Res1	:2;
	u32		WRPERR	:1;
	u32		PGAERR	:1;
	u32		PGPERR	:1;
	u32		PGSERR	:1;
	u32		RDERR	:1;
	u32		Res2	:7;
	u32		BSY		:1;
}SR_T;

typedef struct{
	u32 	PG   	:1;
	u32		SER  	:1;
	u32		MER  	:1;
	u32		SNB  	:1;
	u32		Res1 	:1;
	u32		PSIZE	:2;
	u32		Res2 	:6;
	u32		STRT 	:1;
	u32		Res3 	:7;
	u32		EOPIE	:1;
	u32		ERRIE	:1;
	u32		Res4 	:5;
	u32		LOCK 	:1;
}CR_T;

typedef struct{
	u32		ACR    ;
	u32		KEYR   ;
	u32		OPTKEYR;
	SR_T	SR	   ;
	CR_T	CR	   ;
	u32		OPTCR  ;
}FLASH_T;

#define FLASH		((volatile FLASH_T*)(FLASH_BASE_ADDRESS))


#endif /* FMI_PRIVATE_H_ */
