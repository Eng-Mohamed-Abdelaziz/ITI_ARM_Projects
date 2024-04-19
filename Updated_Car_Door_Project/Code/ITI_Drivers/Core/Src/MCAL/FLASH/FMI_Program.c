/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : FLASH_Driver
File    : Program File
Version : 1.0
Date	: 3/9/2023
********************************************************************************************************
********************************************************************************************************/

/*****************************************************************/
/************************** Includes *****************************/
/*****************************************************************/

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "FMI_Config.h"
#include "FMI_Interface.h"
#include "FMI_Private.h"

/*****************************************************************/
/******************** Function Definitions ***********************/
/*****************************************************************/

void FMI_vEraseAppArea(void)
{
	/* 1- Wait if Flash is Busy (BSY) */
	while(FLASH -> SR . BSY == 0);
	/* 2- Unlock Flash Register using KEYR */
	FLASH -> KEYR |= (KEY1) | (KEY2 << 16);
	/* 3- Select Mass Erase operation */
	FLASH -> CR . MER = 1;
	/* 4- Start erase operation */
	FLASH -> CR . STRT = 1;
	/* 5- Wait for Busy Flag */
	while(FLASH -> SR . BSY == 0);
	/* 6- Clear EOP flag */
	FLASH -> SR . EOP = 1;
	/* 7- De-select Mass Erase Operation */
	FLASH -> CR . MER = 0;
}

void FMI_vSectorErase(u8 A_u8SectorNo)
{
	/* 1- Wait if Flash is Busy (BSY) */
	while(FLASH -> SR . BSY == 0);
	/* 2- Unlock Flash Register using KEYR */
	FLASH -> KEYR |= (KEY1) | (KEY2 << 16);
	/* 3- select Sector Number to erase */
	FLASH -> CR . SNB = 0;
	FLASH -> CR . SNB = A_u8SectorNo;
	/* 4- Select Erase operation */
	FLASH -> CR . SER = 1;
	/* 5- Start erase operation  */
	FLASH -> CR . STRT = 1;
	/* 6- Wait for Busy Flag    */
	while(FLASH -> SR . BSY == 0);
	/* 7- Clear EOP flag   */
	FLASH -> SR . EOP = 1;
	/* 8- DeSelect Erase Operation (reverse of step 4) */
	FLASH -> CR . SER = 0;
}

void FMI_vFlashWrite(u32 A_u32Address, u16* A_pu16Data, u16  A_u16Length)
{
	/* 1- Wait if Flash is Busy (BSY) */
	while(FLASH -> SR . BSY == 0);
	/* 2- Unlock Flash Register using KEYR */
	FLASH -> KEYR |= (KEY1) | (KEY2 << 16);
	/* 3- Select element size (PSIZE)  */
	FLASH -> CR . PSIZE = 1;
	/* 4- Activate Programming Mode (PG bit) */
	FLASH -> CR . PG = 1;
	/* 5- Write Data Array on Flash address */
	for (u16 i = 0 ; i < A_u16Length ; i++){
		*((volatile u16*)A_u32Address) = A_pu16Data[i];
		A_u32Address += 2;
	}
	/* 6- Wait for Busy Flag    */
	while(FLASH -> SR . BSY == 0);
	/* 7- Clear EOP flag   */
	FLASH -> SR . EOP = 1;
	/* 8- deactivate programming mode */
	FLASH -> CR . PG = 0;
}
