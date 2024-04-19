/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : DMA_Driver
File    : Program File
Version : 1.0
Date	: 29/8/2023
********************************************************************************************************
********************************************************************************************************/

/*****************************************************************/
/************************** Includes *****************************/
/*****************************************************************/

#include "MDMA_Config.h"
#include "MDMA_Interface.h"
#include "MDMA_Private.h"

/*****************************************************************/
/******************** Function Definitions ***********************/
/*****************************************************************/

void DMA_Configuration(Stream_No Stream_ID){
	/*Step1 : Before Any Configuration The Bit OF EN must be = 0 */
	MDMA2 -> S[Stream_ID].CR.EN = 0;
	/*Step 2 : Select The Channel(Used for Connect Peripheral To memory) In Stream but From M2M Not Used*/
	/*MDMA2 -> S0.CR.CHSEL ;*/
	/*Step 3 : Set SoftWare Priority Stream : {LOW - Medium - High - Very High} Bit (16 , 17) --> very High*/
	MDMA2 -> S[Stream_ID].CR.PL = 0b11;
	/*Step 4 : Set DIR Mode : {(MTM) , (PTM), (MTP)} --> BIT(6,7)  -->DIR [MTM -->(0,1)]*/
	MDMA2 -> S[Stream_ID].CR.DIR = 0b10;
	/*Step 5 : Select Circular Mode  BIT(8) */
	MDMA2 -> S[Stream_ID].CR.CIRC = 1;
	/*Step 6 : Set Source Size and Destination Size for Elements : {Byte - HalfWord - Word}*/
	/*As word 32 for source  as Memory*/
	/*As word 32 for Destination as memory*/
	MDMA2 -> S[Stream_ID].CR.MSIZE = 0b10;
	MDMA2 -> S[Stream_ID].CR.PSIZE = 0b10;
	/*Step 7 : Disable Direct Mode*/
	MDMA2 -> S[Stream_ID].FCR.DMDIS = 1;
	/*Step 8 : Set Threshold (1/4),(1/2),(3/4),(4/4)}*/
	MDMA2 -> S[Stream_ID].FCR.FTH = 3;
	/*Step 8 : SRC & DIS Increment for Both*/
	MDMA2 -> S[Stream_ID].CR.MINC = 1;
	MDMA2 -> S[Stream_ID].CR.PINC = 1;
	/*Step 9 : Enable Interrupt of Transfer Complete*/
	MDMA2 -> S[Stream_ID].CR.TCIE = 1;
}


