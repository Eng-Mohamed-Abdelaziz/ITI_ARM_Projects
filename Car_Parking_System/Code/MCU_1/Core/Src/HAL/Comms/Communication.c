/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
LAYER   : HAL
DRIVER  : Communication Driver
File    : Source File
Version : 1.0
Date	: 3/9/2023
********************************************************************************************************
********************************************************************************************************/

/*****************************************************************/
/************************** Includes *****************************/
/*****************************************************************/

#include "Communication.h"

/*****************************************************************/
/******************** Function Definitions ***********************/
/*****************************************************************/


void Comms_Init(Type_Comms Comms_Type, u16 Baudrate){
	switch(Comms_Type){
	case USART_1:
		MRCC_vEnableClock(AHB1, RCC_GPIOA_EN);
		MRCC_vEnableClock(APB2, RCC_USART1_EN);

		MGPIO_voidSetPinMode(_GPIOA_PORT,  _PIN_9, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOA_PORT,  _PIN_9, _ALTFN_7);

		MGPIO_voidSetPinMode(_GPIOA_PORT,  _PIN_10, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOA_PORT,  _PIN_10, _ALTFN_7);

		MUSART_voidInit(Baudrate);
		break;
	/*case USART_2:
		MRCC_vEnableClock(AHB1, RCC_GPIOA_EN);
		MRCC_vEnableClock(APB1, RCC_USART2_EN);

		MGPIO_voidSetPinMode(_GPIOA_PORT,  _PIN_1, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOA_PORT,  _PIN_1, _ALTFN_7);

		MGPIO_voidSetPinMode(_GPIOA_PORT,  _PIN_2, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOA_PORT,  _PIN_2, _ALTFN_7);

		MUSART_voidInit(USART2, Baudrate);
		break;
	case USART_6:
		MRCC_vEnableClock(AHB1, RCC_GPIOA_EN);
		MRCC_vEnableClock(APB2, RCC_USART6_EN);

		MGPIO_voidSetPinMode(_GPIOA_PORT,  _PIN_11, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOA_PORT,  _PIN_11, _ALTFN_8);

		MGPIO_voidSetPinMode(_GPIOA_PORT,  _PIN_12, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOA_PORT,  _PIN_12, _ALTFN_8);

		MUSART_voidInit(USART6, Baudrate);
		break;
	case SPI_1:
		MRCC_vEnableClock(AHB1, RCC_GPIOA_EN);
		MRCC_vEnableClock(APB2, RCC_SPI1_EN);

		MGPIO_voidSetPinMode(_GPIOA_PORT,  _PIN_4, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOA_PORT,  _PIN_4, _ALTFN_5);

		MGPIO_voidSetPinMode(_GPIOA_PORT,  _PIN_5, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOA_PORT,  _PIN_5, _ALTFN_5);

		MGPIO_voidSetPinMode(_GPIOA_PORT,  _PIN_6, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOA_PORT,  _PIN_6, _ALTFN_5);

		MGPIO_voidSetPinMode(_GPIOA_PORT,  _PIN_7, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOA_PORT,  _PIN_7, _ALTFN_5);

		MSPI1_voidInit();
		break;
	case SPI_2:
		MRCC_vEnableClock(AHB1, RCC_GPIOB_EN);
		MRCC_vEnableClock(APB1, RCC_SPI2_EN);

		MGPIO_voidSetPinMode(_GPIOB_PORT,  _PIN_12, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOB_PORT,  _PIN_12, _ALTFN_5);

		MGPIO_voidSetPinMode(_GPIOB_PORT,  _PIN_13, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOB_PORT,  _PIN_13, _ALTFN_5);

		MGPIO_voidSetPinMode(_GPIOB_PORT,  _PIN_14, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOB_PORT,  _PIN_14, _ALTFN_5);

		MGPIO_voidSetPinMode(_GPIOB_PORT,  _PIN_15, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOB_PORT,  _PIN_15, _ALTFN_5);

		MSPI2_voidInit();
		break;
	case SPI_3:
		MRCC_vEnableClock(AHB1, RCC_GPIOA_EN);
		MRCC_vEnableClock(AHB1, RCC_GPIOB_EN);
		MRCC_vEnableClock(APB1, RCC_SPI3_EN);

		MGPIO_voidSetPinMode(_GPIOA_PORT,  _PIN_15, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOA_PORT,  _PIN_15, _ALTFN_6);

		MGPIO_voidSetPinMode(_GPIOB_PORT,  _PIN_3, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOB_PORT,  _PIN_3, _ALTFN_6);

		MGPIO_voidSetPinMode(_GPIOB_PORT,  _PIN_4, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOB_PORT,  _PIN_4, _ALTFN_6);

		MGPIO_voidSetPinMode(_GPIOB_PORT,  _PIN_5, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOB_PORT,  _PIN_5, _ALTFN_6);

		MSPI3_voidInit();
		break;
	case SPI_4:
		MRCC_vEnableClock(AHB1, RCC_GPIOE_EN);
		MRCC_vEnableClock(APB2, RCC_SPI4_EN);

		MGPIO_voidSetPinMode(_GPIOE_PORT,  _PIN_11, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOE_PORT,  _PIN_11, _ALTFN_5);

		MGPIO_voidSetPinMode(_GPIOE_PORT,  _PIN_12, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOE_PORT,  _PIN_12, _ALTFN_5);

		MGPIO_voidSetPinMode(_GPIOE_PORT,  _PIN_13, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOE_PORT,  _PIN_13, _ALTFN_5);

		MGPIO_voidSetPinMode(_GPIOE_PORT,  _PIN_14, _MODE_ALTF);
		MGPIO_voidSetPinAltFn(_GPIOE_PORT,  _PIN_14, _ALTFN_5);

		MSPI4_voidInit();
		break;*/
	default:
		break;
	}
}

void Comms_Enable_Disable(Type_Comms Comms_Type, u8 Enable_Disable){
	if(Enable_Disable){
		MUSART_voidEnable();
	}
	else{
		MUSART_voidDisable();
	}
}

u8 Comms_Read_Write(Type_Comms Comms_Type, u8* USART_Data, u8 Len, /*u8 SPI_Data,*/ u8 W_R){
	u8 Data_Received = 0;
	switch(Comms_Type){
	case USART_1:
	case USART_2:
	case USART_6:
		if(W_R){
			MUSART_voidSendData(USART_Data, Len);
		}
		else{
			Data_Received = MUSART_u8ReadData();
		}
		break;
/*	case SPI_1:
		Data_Received = MSPI1_u8SendData(SPI_Data);
		break;
	case SPI_2:
		Data_Received = MSPI2_u8SendData(SPI_Data);
		break;
	case SPI_3:
		Data_Received = MSPI3_u8SendData(SPI_Data);
		break;
	case SPI_4:
		Data_Received = MSPI4_u8SendData(SPI_Data);
		break;*/
	default:
		break;
	}
	return	Data_Received;
}

void Comms_SetCallBack(Type_Comms Comms_Type, void(*Uptr)(void)){
	switch(Comms_Type){
	case USART_1:
		MNVIC_vSetGroupMode(MNVIC_G4_SG4);
		MNVIC_vSetInterruptPriority(37, 0, 0);
		MNVIC_vInterruptSetEnable(37);
		MUSART_voidCallBack( Uptr);
		break;
/*	case USART_2:
		MUSART_voidCallBack(Comms_Type, Uptr);
		break;
	case USART_6:
		MUSART_voidCallBack(Comms_Type, Uptr);
		break;
	case SPI_1:
		MSPI1_voidSetCallBack(Uptr);
		break;
	case SPI_2:
		MSPI2_voidSetCallBack(Uptr);
		break;
	case SPI_3:
		MSPI3_voidSetCallBack(Uptr);
		break;
	case SPI_4:
		MSPI4_voidSetCallBack(Uptr);
		break;*/
	default:
		break;
	}
}
