/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : FLASH_Driver
File    : Interface File
Version : 1.0
Date	: 3/9/2023
********************************************************************************************************
********************************************************************************************************/

#ifndef FMI_INTERFACE_H_
#define FMI_INTERFACE_H_

#define		SECTOR_0		0b0000
#define		SECTOR_1		0b0001
#define		SECTOR_2		0b0010
#define		SECTOR_3		0b0011
#define		SECTOR_4		0b0100
#define		SECTOR_5		0b0101
#define		SECTOR_6		0b0110
#define		SECTOR_7		0b0111

#define 	KEY1	 		0x45670123
#define 	KEY2			0xCDEF89AB

void FMI_vEraseAppArea(void);

void FMI_vSectorErase(u8 A_u8SectorNo);

void FMI_vFlashWrite(u32 A_u32Address, u16* A_pu16Data, u16  A_u16Length);

#endif /* FMI_INTERFACE_H_ */
