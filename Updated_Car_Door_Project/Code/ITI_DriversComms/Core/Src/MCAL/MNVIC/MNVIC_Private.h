/*******************************************************************************************************
 * *****************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : NVIC_Driver
File    : Private File
Version : 1.0
Date	: 13/8/2023
********************************************************************************************************
********************************************************************************************************/

#ifndef MNVIC_PRIVATE_H_
#define MNVIC_PRIVATE_H_

#define REGISTER_BITS		32

/************************** NVIC BASE ADDRESS  *****************************/
#define MNVIC_BASE_ADDRESS (0xE000E100)

/************************** NVIC REGISTERS  ********************************/
typedef struct {
	u32 ISER[8];
	u32 Reserved1[24];
	u32 ICER[8];
	u32 Reserved2[24];
	u32 ISPR[8];
	u32 Reserved3[24];
	u32 ICPR[8];
	u32 Reserved4[24];
	u32 IABR[8];
	u32 Reserved5[56];
	u8  IPR[240];
	u32 Reserved6[580];
	u32 STIR;
}MNVIC_T;

#define VECTKEY	0x05FA0000

#define NVIC 	((volatile MNVIC_T*)(MNVIC_BASE_ADDRESS))

#define AIRCR	(*(volatile u32 *)0xE000ED0C)			/*SCB + offset for AIRCR*/

#endif /* MNVIC_PRIVATE_H_ */
