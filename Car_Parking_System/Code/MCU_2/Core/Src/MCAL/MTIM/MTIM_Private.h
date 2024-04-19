/*
 * timer_priv.h
 *
 *  Created on: Sep 12, 2023
 *      Author: ahmed essam mohamed
 */

#ifndef MTIM_PRIVATE_H_
#define MTIM_PRIVATE_H_

/*******************************************************************************************************/
/*                                    Macros Base Address Of TIMx Registers                           */
/*******************************************************************************************************/

#define TIM2_BASE_ADRESS 0x40000000
#define TIM3_BASE_ADRESS 0x40000400
#define TIM4_BASE_ADRESS 0x40000800
#define TIM5_BASE_ADRESS 0x40000C00
//#define TIM9_BASE_ADRESS 0x40014000
//#define TIM10_BASE_ADRESS 0x40014400
//#define TIM11_BASE_ADRESS 0x40014800


/********************** timer register map type. *************************************************************/
typedef struct{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	volatile u32 Reserved1;
	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	volatile u32 Reserved2;
	volatile u32 DCR;
	volatile u32 DMAR;
#if TIM2 == ENABLE || TIM5 == ENABLE
	volatile u32 OR;

#endif

}TIMx;

/*******************************************************************************************************/
/*                                   Struct Macros Base Address Of TIM2                               */
/*******************************************************************************************************/
#define TIM2 ((volatile TIMx *) (TIM2_BASE_ADRESS) )


/*******************************************************************************************************/
/*                                   Struct Macros Base Address Of TIM3                               */
/*******************************************************************************************************/
#define TIM3 ((volatile TIMx *) TIM3_BASE_ADRESS )

/*******************************************************************************************************/
/*                                   Struct Macros Base Address Of TIM4                               */
/*******************************************************************************************************/
#define TIM4 ((volatile TIMx *) TIM4_BASE_ADRESS )

/*******************************************************************************************************/
/*                                   Struct Macros Base Address Of TIM5                               */
/*******************************************************************************************************/
#define TIM5 ((volatile TIMx *) TIM5_BASE_ADRESS )

/************************** TIMx interrupt number (position) in vector table ***************************/
#define TIM2_IRQ 28
#define TIM3_IRQ 29
#define TIM4_IRQ 30
#define TIM5_IRQ 50


#endif /* MTIM_PRIVATE_H_ */
