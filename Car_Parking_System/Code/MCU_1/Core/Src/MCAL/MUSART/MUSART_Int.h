/*********************************************************************************************************
**********************************************************************************************************
AUTHOR  : Mohanad Hany
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : USART_Driver
File    : Interface File
Version :1.0
********************************************************************************************************
*******************************************************************************************************/

#ifndef MCAL_MUSART_MUSART_INT_H_
#define MCAL_MUSART_MUSART_INT_H_

/**************************************** Functions prototypes ***************************************/
/*****************************************************************************************************/

void MUSART_voidInit(u32 copy_u32BaudRate);

void MUSART_voidSendData(u8* copy_u8Data,u8 copy_u8Len);

void MUSART_voidSendString(u8* copy_u8Data);

u8 MUSART_u8ReadData(void);

void MUSART_voidEnable(void);

void MUSART_voidDisable(void);

void MUSART_voidCallBack(void(*Fptr)(void));

#endif /* MCAL_MUSART_MUSART_INT_H_ */
