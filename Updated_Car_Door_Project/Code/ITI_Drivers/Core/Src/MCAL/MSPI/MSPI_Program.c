/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : SPI_Driver
File    : Program File
Version : 1.0
Date	: 24/8/2023
********************************************************************************************************
********************************************************************************************************/

/*****************************************************************/
/************************** Includes *****************************/
/*****************************************************************/

#include "MSPI_Config.h"
#include "MSPI_Interface.h"
#include "MSPI_Private.h"

/*****************************************************************/
/********************** Callback Functions ***********************/
/*****************************************************************/

static void (* SPI1_Callback)(void) = NULL_ptr;

static void (* SPI2_Callback)(void) = NULL_ptr;

static void (* SPI3_Callback)(void) = NULL_ptr;

static void (* SPI4_Callback)(void) = NULL_ptr;

/*****************************************************************/
/******************** Function Definitions ***********************/
/*****************************************************************/

/*******************************************************************************************************/
/*                                       01- MSPI1_voidInit                                            */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to initialize SPI1 with specified Configurations		           */
/* 2- Function Input       -> Nothing          												   		   */
/* 3- Function Return      -> Nothing                                                                  */
/*******************************************************************************************************/

void MSPI1_voidInit 			(       void	  ){
#if 	MSPI1_CLOCK_MODE == MSPI_MODE0

	MSPI1 -> CR1.CPOL = 0; MSPI1 -> CR1.CPHA = 0;

#elif 	MSPI1_CLOCK_MODE == MSPI_MODE1

	MSPI1 -> CR1.CPOL = 0; MSPI1 -> CR1.CPHA = 1;

#elif 	MSPI1_CLOCK_MODE == MSPI_MODE2

	MSPI1 -> CR1.CPOL = 1; MSPI1 -> CR1.CPHA = 0;

#elif 	MSPI1_CLOCK_MODE == MSPI_MODE3

	MSPI1 -> CR1.CPOL = 1; MSPI1 -> CR1.CPHA = 1;

#endif

#if		MSPI1_MASTER_SLAVE == MSPI_MASTER

	MSPI1 -> CR1.MSTR = 1;

#elif	MSPI1_MASTER_SLAVE == MSPI_SLAVE
#endif

#if		MSPI1_DATA_ORDER == MSPI_MSB_FIRST
#elif	MSPI1_DATA_ORDER == MSPI_LSB_FIRST

	MSPI1 -> CR1.LSBFIRST = 1;

#endif

#if		MSPI1_SS_MANAGE == HW_SLAVE_MANAGEMENT
#elif	MSPI1_SS_MANAGE == SW_SLAVE_MANAGEMENT

	MSPI1 -> CR1.SSM = 1;

#endif

#if 	MSPI1_DATA_SIZE == MSPI_8BIT_DATA
#elif	MSPI1_DATA_SIZE == MSPI_16BIT_DATA

	MSPI1 -> CR1.DFF = 1;

#endif

#if		MSPI1_INT_STATUS == MSPI_INT_DISABLE
#elif	MSPI1_INT_STATUS == MSPI_TXE_INT_ENABLE

	SET_BIT(MSPI1 -> CR2, 7);

#elif	MSPI1_INT_STATUS == MSPI_RXNE_INT_ENABLE

	SET_BIT(MSPI1 -> CR2, 6);

#endif

#if		MSPI1_PRESCALER == MSPI_FPCLK_2
#elif	MSPI1_PRESCALER == MSPI_FPCLK_4

	MSPI1 -> CR1.BR = 1;

#elif	MSPI1_PRESCALER == MSPI_FPCLK_8

	MSPI1 -> CR1.BR = 2;

#elif	MSPI1_PRESCALER == MSPI_FPCLK_16

	MSPI1 -> CR1.BR = 3;

#elif	MSPI1_PRESCALER == MSPI_FPCLK_32

	MSPI1 -> CR1.BR = 4;

#elif	MSPI1_PRESCALER == MSPI_FPCLK_64

	MSPI1 -> CR1.BR = 5;

#elif	MSPI1_PRESCALER == MSPI_FPCLK_128

	MSPI1 -> CR1.BR = 6;

#elif	MSPI1_PRESCALER == MSPI_FPCLK_256

	MSPI1 -> CR1.BR = 7;

#endif

#if		MSPI1_STATUS == MSPI_DISABLE
#elif	MSPI1_STATUS == MSPI_ENABLE
	MSPI1 -> CR1.SPE = 1;
#endif
}

/*******************************************************************************************************/
/*                                       02- MSPI2_voidInit                                            */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to initialize SPI3 with specified Configurations		           */
/* 2- Function Input       -> Nothing          												   		   */
/* 3- Function Return      -> Nothing                                                                  */
/*******************************************************************************************************/

void MSPI2_voidInit 			(       void	  ){
#if 	MSPI2_CLOCK_MODE == MSPI_MODE0

	MSPI2 -> CR1.CPOL = 0; MSPI2 -> CR1.CPHA = 0;

#elif 	MSPI2_CLOCK_MODE == MSPI_MODE1

	MSPI2 -> CR1.CPOL = 0; MSPI2 -> CR1.CPHA = 1;

#elif 	MSPI2_CLOCK_MODE == MSPI_MODE2

	MSPI2 -> CR1.CPOL = 1; MSPI2 -> CR1.CPHA = 0;

#elif 	MSPI2_CLOCK_MODE == MSPI_MODE3

	MSPI2 -> CR1.CPOL = 1; MSPI2 -> CR1.CPHA = 1;

#endif

#if		MSPI2_MASTER_SLAVE == MSPI_MASTER

	MSPI2 -> CR1.MSTR = 1;

#elif	MSPI2_MASTER_SLAVE == MSPI_SLAVE
#endif

#if		MSPI2_DATA_ORDER == MSPI_MSB_FIRST
#elif	MSPI2_DATA_ORDER == MSPI_LSB_FIRST

	MSPI2 -> CR1.LSBFIRST = 1;

#endif

#if		MSPI2_SS_MANAGE == HW_SLAVE_MANAGEMENT
#elif	MSPI2_SS_MANAGE == SW_SLAVE_MANAGEMENT

	MSPI2 -> CR1.SSM = 1;

#endif

#if 	MSPI2_DATA_SIZE == MSPI_8BIT_DATA
#elif	MSPI2_DATA_SIZE == MSPI_16BIT_DATA

	MSPI2 -> CR1.DFF = 1;

#endif

#if		MSPI2_INT_STATUS == MSPI_INT_DISABLE
#elif	MSPI2_INT_STATUS == MSPI_TXE_INT_ENABLE

	SET_BIT(MSPI2 -> CR2, 7);

#elif	MSPI2_INT_STATUS == MSPI_RXNE_INT_ENABLE

	SET_BIT(MSPI2 -> CR2, 6);

#endif

#if		MSPI2_PRESCALER == MSPI_FPCLK_2
#elif	MSPI2_PRESCALER == MSPI_FPCLK_4

	MSPI2 -> CR1.BR = 1;

#elif	MSPI2_PRESCALER == MSPI_FPCLK_8

	MSPI2 -> CR1.BR = 2;

#elif	MSPI2_PRESCALER == MSPI_FPCLK_16

	MSPI2 -> CR1.BR = 3;

#elif	MSPI2_PRESCALER == MSPI_FPCLK_32

	MSPI2 -> CR1.BR = 4;

#elif	MSPI2_PRESCALER == MSPI_FPCLK_64

	MSPI2 -> CR1.BR = 5;

#elif	MSPI2_PRESCALER == MSPI_FPCLK_128

	MSPI2 -> CR1.BR = 6;

#elif	MSPI2_PRESCALER == MSPI_FPCLK_256

	MSPI2 -> CR1.BR = 7;

#endif

#if		MSPI2_STATUS == MSPI_DISABLE
#elif	MSPI2_STATUS == MSPI_ENABLE
	MSPI2 -> CR1.SPE = 1;
#endif
}

/*******************************************************************************************************/
/*                                       03- MSPI3_voidInit                                            */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to initialize SPI3 with specified Configurations		           */
/* 2- Function Input       -> Nothing          												   		   */
/* 3- Function Return      -> Nothing                                                                  */
/*******************************************************************************************************/

void MSPI3_voidInit 			(       void	  ){
#if 	MSPI3_CLOCK_MODE == MSPI_MODE0

	MSPI3 -> CR1.CPOL = 0; MSPI3 -> CR1.CPHA = 0;

#elif 	MSPI3_CLOCK_MODE == MSPI_MODE1

	MSPI3 -> CR1.CPOL = 0; MSPI3 -> CR1.CPHA = 1;

#elif 	MSPI3_CLOCK_MODE == MSPI_MODE2

	MSPI3 -> CR1.CPOL = 1; MSPI3 -> CR1.CPHA = 0;

#elif 	MSPI3_CLOCK_MODE == MSPI_MODE3

	MSPI3 -> CR1.CPOL = 1; MSPI3 -> CR1.CPHA = 1;

#endif

#if		MSPI3_MASTER_SLAVE == MSPI_MASTER

	MSPI3 -> CR1.MSTR = 1;

#elif	MSPI3_MASTER_SLAVE == MSPI_SLAVE
#endif

#if		MSPI3_DATA_ORDER == MSPI_MSB_FIRST
#elif	MSPI3_DATA_ORDER == MSPI_LSB_FIRST

	MSPI3 -> CR1.LSBFIRST = 1;

#endif

#if		MSPI3_SS_MANAGE == HW_SLAVE_MANAGEMENT
#elif	MSPI3_SS_MANAGE == SW_SLAVE_MANAGEMENT

	MSPI3 -> CR1.SSM = 1;

#endif

#if 	MSPI3_DATA_SIZE == MSPI_8BIT_DATA
#elif	MSPI3_DATA_SIZE == MSPI_16BIT_DATA

	MSPI3 -> CR1.DFF = 1;

#endif

#if		MSPI3_INT_STATUS == MSPI_INT_DISABLE
#elif	MSPI3_INT_STATUS == MSPI_TXE_INT_ENABLE

	SET_BIT(MSPI3 -> CR2, 7);

#elif	MSPI3_INT_STATUS == MSPI_RXNE_INT_ENABLE

	SET_BIT(MSPI3 -> CR2, 6);

#endif

#if		MSPI3_PRESCALER == MSPI_FPCLK_2
#elif	MSPI3_PRESCALER == MSPI_FPCLK_4

	MSPI3 -> CR1.BR = 1;

#elif	MSPI3_PRESCALER == MSPI_FPCLK_8

	MSPI3 -> CR1.BR = 2;

#elif	MSPI3_PRESCALER == MSPI_FPCLK_16

	MSPI3 -> CR1.BR = 3;

#elif	MSPI3_PRESCALER == MSPI_FPCLK_32

	MSPI3 -> CR1.BR = 4;

#elif	MSPI3_PRESCALER == MSPI_FPCLK_64

	MSPI3 -> CR1.BR = 5;

#elif	MSPI3_PRESCALER == MSPI_FPCLK_128

	MSPI3 -> CR1.BR = 6;

#elif	MSPI3_PRESCALER == MSPI_FPCLK_256

	MSPI3 -> CR1.BR = 7;

#endif

#if		MSPI3_STATUS == MSPI_DISABLE
#elif	MSPI3_STATUS == MSPI_ENABLE
	MSPI3 -> CR1.SPE = 1;
#endif
}

/*******************************************************************************************************/
/*                                       04- MSPI4_voidInit                                            */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to initialize SPI4 with specified Configurations		           */
/* 2- Function Input       -> Nothing          												   		   */
/* 3- Function Return      -> Nothing                                                                  */
/*******************************************************************************************************/

void MSPI4_voidInit 			(       void	  ){
#if 	MSPI4_CLOCK_MODE == MSPI_MODE0

	MSPI4 -> CR1.CPOL = 0; MSPI4 -> CR1.CPHA = 0;

#elif 	MSPI4_CLOCK_MODE == MSPI_MODE1

	MSPI4 -> CR1.CPOL = 0; MSPI4 -> CR1.CPHA = 1;

#elif 	MSPI4_CLOCK_MODE == MSPI_MODE2

	MSPI4 -> CR1.CPOL = 1; MSPI4 -> CR1.CPHA = 0;

#elif 	MSPI4_CLOCK_MODE == MSPI_MODE3

	MSPI4 -> CR1.CPOL = 1; MSPI4 -> CR1.CPHA = 1;

#endif

#if		MSPI4_MASTER_SLAVE == MSPI_MASTER

	MSPI4 -> CR1.MSTR = 1;

#elif	MSPI4_MASTER_SLAVE == MSPI_SLAVE
#endif

#if		MSPI4_DATA_ORDER == MSPI_MSB_FIRST
#elif	MSPI4_DATA_ORDER == MSPI_LSB_FIRST

	MSPI4 -> CR1.LSBFIRST = 1;

#endif

#if		MSPI4_SS_MANAGE == HW_SLAVE_MANAGEMENT
#elif	MSPI4_SS_MANAGE == SW_SLAVE_MANAGEMENT

	MSPI4 -> CR1.SSM = 1;

#endif

#if 	MSPI4_DATA_SIZE == MSPI_8BIT_DATA
#elif	MSPI4_DATA_SIZE == MSPI_16BIT_DATA

	MSPI4 -> CR1.DFF = 1;

#endif

#if		MSPI4_INT_STATUS == MSPI_INT_DISABLE
#elif	MSPI4_INT_STATUS == MSPI_TXE_INT_ENABLE

	SET_BIT(MSPI4 -> CR2, 7);

#elif	MSPI4_INT_STATUS == MSPI_RXNE_INT_ENABLE

	SET_BIT(MSPI4 -> CR2, 6);

#endif

#if		MSPI4_PRESCALER == MSPI_FPCLK_2
#elif	MSPI4_PRESCALER == MSPI_FPCLK_4

	MSPI4 -> CR1.BR = 1;

#elif	MSPI4_PRESCALER == MSPI_FPCLK_8

	MSPI4 -> CR1.BR = 2;

#elif	MSPI4_PRESCALER == MSPI_FPCLK_16

	MSPI4 -> CR1.BR = 3;

#elif	MSPI4_PRESCALER == MSPI_FPCLK_32

	MSPI4 -> CR1.BR = 4;

#elif	MSPI4_PRESCALER == MSPI_FPCLK_64

	MSPI4 -> CR1.BR = 5;

#elif	MSPI4_PRESCALER == MSPI_FPCLK_128

	MSPI4 -> CR1.BR = 6;

#elif	MSPI4_PRESCALER == MSPI_FPCLK_256

	MSPI4 -> CR1.BR = 7;

#endif

#if		MSPI4_STATUS == MSPI_DISABLE
#elif	MSPI4_STATUS == MSPI_ENABLE
	MSPI4 -> CR1.SPE = 1;
#endif
}

/*******************************************************************************************************/
/*                                      05- MSPI1_u8SendData                                           */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to send the data to be transmitted and return the data to be    */
/* 							  received.		           												   */
/* 2- Function Input       -> Data to be transmitted          										   */
/* 3- Function Return      -> Nothing                                                                  */
/*******************************************************************************************************/

u8	 MSPI1_u8SendData		(  u8 Copy_u8Data ){
	/* Clear Slave Select GPIO Pin */
	while(GET_BIT(MSPI1 -> SR, 7));
	MSPI1 -> DR = (Copy_u8Data);
	while(GET_BIT(MSPI1 -> SR, 7));
	/* Set Slave Select GPIO Pin */
	return (u8) (MSPI1 -> DR);
}

/*******************************************************************************************************/
/*                                      06- MSPI2_u8SendData                                           */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to send the data to be transmitted and return the data to be    */
/* 							  received.		           												   */
/* 2- Function Input       -> Data to be transmitted          										   */
/* 3- Function Return      -> Nothing                                                                  */
/*******************************************************************************************************/

u8	 MSPI2_u8SendData		(  u8 Copy_u8Data ){
	/* Clear Slave Select GPIO Pin */
	while(GET_BIT(MSPI2 -> SR, 7));
	MSPI2 -> DR = (Copy_u8Data);
	while(GET_BIT(MSPI2 -> SR, 7));
	/* Set Slave Select GPIO Pin */
	return (u8) (MSPI2 -> DR);
}

/*******************************************************************************************************/
/*                                      07- MSPI3_u8SendData                                           */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to send the data to be transmitted and return the data to be    */
/* 							  received.		           												   */
/* 2- Function Input       -> Data to be transmitted          										   */
/* 3- Function Return      -> Nothing                                                                  */
/*******************************************************************************************************/

u8	 MSPI3_u8SendData		(  u8 Copy_u8Data ){
	/* Clear Slave Select GPIO Pin */
	while(GET_BIT(MSPI3 -> SR, 7));
	MSPI3 -> DR = (Copy_u8Data);
	while(GET_BIT(MSPI3 -> SR, 7));
	/* Set Slave Select GPIO Pin */
	return (u8) (MSPI3 -> DR);
}

/*******************************************************************************************************/
/*                                      08- MSPI4_u8SendData                                           */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to send the data to be transmitted and return the data to be    */
/* 							  received.		           												   */
/* 2- Function Input       -> Data to be transmitted          										   */
/* 3- Function Return      -> Nothing                                                                  */
/*******************************************************************************************************/

u8	 MSPI4_u8SendData		(  u8 Copy_u8Data ){
	/* Clear Slave Select GPIO Pin */
	while(GET_BIT(MSPI4 -> SR, 7));
	MSPI4 -> DR = (Copy_u8Data);
	while(GET_BIT(MSPI4 -> SR, 7));
	/* Set Slave Select GPIO Pin */
	return (u8) (MSPI4 -> DR);
}

/*******************************************************************************************************/
/*                                   09- MSPI1_voidSetCallBack                                         */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to set callback function of SPI1    							   */
/* 2- Function Input       -> Pointer to function of user          									   */
/* 3- Function Return      -> Nothing                                                                  */
/*******************************************************************************************************/

void MSPI1_voidSetCallBack	(void(*Cptr)(void)){
	SPI1_Callback = Cptr;
}

/*******************************************************************************************************/
/*                                   10- MSPI2_voidSetCallBack                                         */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to set callback function of SPI2    							   */
/* 2- Function Input       -> Pointer to function of user          									   */
/* 3- Function Return      -> Nothing                                                                  */
/*******************************************************************************************************/

void MSPI2_voidSetCallBack	(void(*Cptr)(void)){
	SPI2_Callback = Cptr;
}

/*******************************************************************************************************/
/*                                   11- MSPI3_voidSetCallBack                                         */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to set callback function of SPI3    							   */
/* 2- Function Input       -> Pointer to function of user          									   */
/* 3- Function Return      -> Nothing                                                                  */
/*******************************************************************************************************/

void MSPI3_voidSetCallBack	(void(*Cptr)(void)){
	SPI3_Callback = Cptr;
}

/*******************************************************************************************************/
/*                                   12- MSPI4_voidSetCallBack                                         */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to set callback function of SPI4    							   */
/* 2- Function Input       -> Pointer to function of user          									   */
/* 3- Function Return      -> Nothing                                                                  */
/*******************************************************************************************************/

void MSPI4_voidSetCallBack	(void(*Cptr)(void)){
	SPI4_Callback = Cptr;
}

void SPI1_IRQHandler (void){
	SPI1_Callback();
}

void SPI2_IRQHandler (void){
	SPI2_Callback();
}

void SPI3_IRQHandler (void){
	SPI3_Callback();
}

void SPI4_IRQHandler (void){
	SPI4_Callback();
}
