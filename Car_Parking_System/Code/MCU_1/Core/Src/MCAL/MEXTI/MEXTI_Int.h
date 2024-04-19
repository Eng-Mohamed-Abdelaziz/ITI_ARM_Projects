/*******************************************************************************************************
 * *****************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : EXTI_Driver
File    : Interface File
Version : 1.0
Date	: 14/8/2023
********************************************************************************************************
********************************************************************************************************/

#ifndef MEXTI_INT_H_
#define MEXTI_INT_H_

/************************ Enumerations ***************************/
/*****************************************************************/

typedef enum {
	Rising,
	Falling,
	Any_Change
}EXTI_Trigger;

typedef enum {
	EXTI_Line_0, EXTI_Line_1, EXTI_Line_2, EXTI_Line_3, EXTI_Line_4, EXTI_Line_5,
	EXTI_Line_6, EXTI_Line_7, EXTI_Line_8, EXTI_Line_9, EXTI_Line_10,
	EXTI_Line_11, EXTI_Line_12, EXTI_Line_13, EXTI_Line_14, EXTI_Line_15,
	EXTI_Line_16, EXTI_Line_17, EXTI_Line_18, EXTI_Line_21 = 21, EXTI_Line_22
}EXTI_Line_x;

typedef enum {
	SYSCFG_PORTA, SYSCFG_PORTB, SYSCFG_PORTC, SYSCFG_PORTD,
	SYSCFG_PORTE,    RESERVED1,    RESERVED2, SYSCFG_PORTH
}SYSCFG_Port;


/*****************************************************************/
/********************* Function Prototypes ***********************/
/*****************************************************************/

/*******************************************************************************************************/
/*                                  01- MEXTI_vHWInterruptEnable                                       */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to Set the Interrupt mask on for the required Line              */
/* 2- Function Input       -> LINE                                                                     */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MEXTI_vHWInterruptEnable(EXTI_Line_x LINE);

/*******************************************************************************************************/
/*                                  02- MEXTI_vHWInterruptDisable                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to Set the Interrupt mask off for the required Line             */
/* 2- Function Input       -> LINE                         											   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MEXTI_vHWInterruptDisable(EXTI_Line_x LINE);

/*******************************************************************************************************/
/*                                   03- MEXTI_vHWEventEnable                                          */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to Set the Event mask on for the required Line                  */
/* 2- Function Input       -> LINE                                                                     */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MEXTI_vHWEventEnable(EXTI_Line_x LINE);

/*******************************************************************************************************/
/*                               	   04- MEXTI_vHWEventDisable                                       */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to Set the Event mask off for the required Line                 */
/* 2- Function Input       -> LINE                     												   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MEXTI_vHWEventDisable(EXTI_Line_x LINE);

/*******************************************************************************************************/
/*                                  05- MEXTI_vSoftwareInterrupt                                       */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to activate Software Interrupt 					               */
/* 2- Function Input       -> LINE              											           */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MEXTI_vSoftwareInterrupt(EXTI_Line_x LINE);

/*******************************************************************************************************/
/*                                    06- MEXTI_vSetTriggerType                                        */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to set the trigger type the interrupt/event will activate on    */
/* 2- Function Input       -> LINE, Trigger              											   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MEXTI_vSetTriggerType(EXTI_Line_x LINE, EXTI_Trigger Trigger);

/*******************************************************************************************************/
/*                                     07- MEXTI_vSetExtiConfig                                        */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to configure the external interrupt to a port in the            */
/*                            system configuration                                                     */
/* 2- Function Input       -> LINE, PORT              											       */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MEXTI_vSetExtiConfig(EXTI_Line_x LINE, SYSCFG_Port PORT);

/*******************************************************************************************************/
/*                                     08- MEXTI_vSetCallback                                          */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function to set the callback function to the line it will correspond to  */
/* 2- Function Input       -> LINE, *ptr()              											   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MEXTI_vSetCallback(EXTI_Line_x LINE, void(*ptr)(void));


#endif /* MEXTI_INT_H_ */
