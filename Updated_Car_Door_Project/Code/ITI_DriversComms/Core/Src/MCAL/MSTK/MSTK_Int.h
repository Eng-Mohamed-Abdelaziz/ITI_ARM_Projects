/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : STK_Driver
File    : Interface File
Version : 1.0
Date	: 15/8/2023
********************************************************************************************************
********************************************************************************************************/

#ifndef MSTK_INT_H_
#define MSTK_INT_H_

typedef enum{
	EN,
	INTEN,
	CLKSRC,
	CNTFLAG = 16
}CTRL_BIT;

void MSTK_voidInit(void);

void MSTK_voidIntState(void);

void MSTK_voidStart(u32 Copy_u8PreloadValue);

u8 MSTK_u8ReadFlag(void);

void MSTK_voidDelayUsec(u32 Copy_u8DelayUsec);

void MSTK_voidDelayMsec(u32 Copy_u8DelayMsec);

u32 MSTK_u32GetElapsedTime(void);

u32 MSTK_u32GetRemainingTime(void);

void CALLBACKSYS(void(*callback)(void));

#endif /* MSTK_INT_H_ */
