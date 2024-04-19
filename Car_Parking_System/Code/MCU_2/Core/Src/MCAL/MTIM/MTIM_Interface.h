/*
 * timer_priv.h
 *
 *  Created on: Sep 12, 2023
 *      Author: ahmed essam mohamed
 */

#ifndef MTIM_INTERFACE_H_
#define MTIM_INTERFACE_H_

#include "../../LIB/STD_Types.h"

/********************************************** CR1 register bits *********************/
#define CR1_CKD1 0x0200 //clk division bit 9
#define CR1_CKD2 0x0100 // clk division cit 8
#define CR1_ARPE 0x0080 // auto-reload preload enable bit 7
#define CR1_CMS1 0x0040 // center aligned mode selection bit 6
#define CR1_CMS2 0x0020 // center aligned mode selection bit 5
#define CR1_DIR  0x0010 // direction bit 4 to select up/down count
#define CR1_OPM  0x0008 // one pulse mode bit 3
#define CR1_URS  0x0004 // update request source bit 2
#define CR1_UDIS 0x0002 // update disable bit 1
#define CR1_CEN  0x0002 // counter enable bit 0

/******************************************************************************************/

/********************************************** DIER_ register bits *********************/
#define DIER_TDE   0x4000    //Trigger DMA request enable bit 14
#define DIER_CC4DE 0x1000    //  Capture/Compare 4 DMA request enable bit 12
#define DIER_CC3DE 0x0800    //  Capture/Compare 3 DMA request enable bit 11
#define DIER_CC2DE 0x0400    // Capture/Compare 2 DMA request enable bit 10
#define DIER_CC1DE 0x0200    // Capture/Compare 1 DMA request enable bit 9
#define DIER_UDE   0x0100    // Update DMA request enable bit 8
#define DIER_TIE   0x0040    // Trigger interrupt enable bit 6
#define DIER_CC4IE 0x0010    //  Capture/Compare 4 interrupt enable bit 4
#define DIER_CC3IE 0x0008    // Capture/Compare 3 interrupt enable bit 3
#define DIER_CC2IE 0x0004    // Capture/Compare 2 interrupt enable bit 2
#define DIER_CC1IE 0x0002    // Capture/Compare 1 interrupt enable bit 1
#define DIER_UIE   0x0001    // Update interrupt enable bit 0

/***************************************************************************************/

/********************************************** SR_ register bits *********************/
#define SR_CC4OF 0x1000 // Capture/Compare 4 over-capture flag bit 12
#define SR_CC3OF 0x0800 // Capture/Compare 3 over-capture flag bit 11
#define SR_CC2OF 0x0400 // Capture/Compare 2 over-capture flag bit 10
#define SR_CC1OF 0x0200 // Capture/Compare 1 over-capture flag bit 9
#define SR_TIF   0x0040 // Trigger interrupt flag bit 6
#define SR_CC4IF 0x0010 // Capture/compare 4 interrupt flag bit 4
#define SR_CC3IF 0x0008 // Capture/compare 3 interrupt flag bit 3
#define SR_CC2IF 0x0004 // Capture/compare 2 interrupt flag bit 2
#define SR_CC1IF 0x0002 // Capture/compare 1 interrupt flag bit 1
#define SR_UIF   0x0001 // update interrupt flag bit 0

/***************************************************************************************/

typedef enum {
	TIM_2,
	TIM_3,
	TIM_4,
	TIM_5
}TIM_x;

void TIMx_INIT(u64 prescaler);

void TIMx_DISABLE(TIM_x Timer);

void TIMx_ENABLE(TIM_x Timer);

#endif /* MTIM_INTERFACE_H_ */
