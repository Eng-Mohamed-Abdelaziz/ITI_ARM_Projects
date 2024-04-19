/*******************************************************************************************************
 * *****************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : EXTI_Driver
File    : Private File
Version : 1.0
Date	: 14/8/2023
********************************************************************************************************
********************************************************************************************************/

#ifndef MEXTI_PRIVATE_H_
#define MEXTI_PRIVATE_H_

#define REGISTER_BITS		32

/************************** EXTI & SYSCFG BASE ADDRESS  *****************************/

#define MEXTI_BASE_ADDRESS 		(0x40013C00)

#define MSYSCFG_BASE_ADDRESS	(0x40013808) //For External Interrupts Configuration

#define EXTI_CONFG_MASK1		0xFFFFFFF0UL
#define EXTI_CONFG_MASK2		0xFFFFFF0FUL
#define EXTI_CONFG_MASK3		0xFFFFF0FFUL
#define EXTI_CONFG_MASK4		0xFFFF0FFFUL

/************************** EXTI & SYSCFG REGISTERS  ********************************/
typedef struct {
	u32 IMR;					/* Interrupt Mask Register */
	u32 EMR;					/* Event Mask Register */
	u32 RSTR;					/* Rising Trigger Selection Register */
	u32 FSTR;					/* Falling Trigger Selection Register */
	u32 SWIER;					/* Software Interrupt Event Register */
	u32 PR;						/* Pending Register */
}MEXTI_T;

typedef struct {
	u32 EXTICR1;				/* SYSCFG External Interrupt Configuration Register 1 */
	u32 EXTICR2;				/* SYSCFG External Interrupt Configuration Register 2 */
	u32 EXTICR3;				/* SYSCFG External Interrupt Configuration Register 3 */
	u32 EXTICR4;				/* SYSCFG External Interrupt Configuration Register 4 */
}MSYSCFG_T;

#define EXTI 	((volatile MEXTI_T*)(MEXTI_BASE_ADDRESS))

#define SYSCFG	((volatile MSYSCFG_T*)(MSYSCFG_BASE_ADDRESS))

#endif /* MEXTI_PRIVATE_H_ */
