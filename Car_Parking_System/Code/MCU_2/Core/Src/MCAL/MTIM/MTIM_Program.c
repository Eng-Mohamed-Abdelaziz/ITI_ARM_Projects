/*
 * timer.c
 *
 *  Created on: Sep 12, 2023
 *      Author: ahmed essam mohamed
 */

#include "MTIM_Interface.h"
#include "MTIM_Private.h"
#include "MTIM_Config.h"
#include "../MRCC/MRCC_Int.h"
#include "../MNVIC/MNVIC_Int.h"

u8 park1 = 0;
u8 park2 = 0;
u8 park3 = 0;

#if TIMER2 == ENABLE
void TIM2_IRQHandler(void)
{
	if((TIM2 -> SR) & SR_UIF)  // means Overflow occurred
	{
		park1 ++;
		(TIM2 -> SR) &= ~(SR_UIF);
	}

}
#endif

#if TIMER3 == ENABLE
void TIM3_IRQHandler(void)
{
	if((TIM3 -> SR) & SR_UIF) // means Overflow occurred
	{
		park2 ++;
		(TIM3 -> SR) &= ~(SR_UIF);
	}

}
#endif

#if TIMER4 == ENABLE
void TIM4_IRQHandler(void)
{
	if((TIM4 -> SR) & SR_UIF) // means Overflow occurred
	{
		park3++;
		(TIM4 -> SR) &= ~(SR_UIF);
	}

}
#endif

#if TIMER5 == ENABLE
void TIM5_IRQHandler(void)
{
	if((TIM5 -> SR) & SR_UIF) // means Overflow occurred
	{
		(TIM5 -> SR) &= ~(SR_UIF);
	}

}
#endif

/*
 * 1- Function Description -> intialize timer                                                  */
/*
 * first: enable internal clk for timer
 * second:set the prescaler value
 * third : set the auto reload value
 * fourth: enable timer interrupt and timer interrupt in NVIC
 * last : enable counter (timer to start)
   2- Function Input       -> - prescale		from 1 to 65536                                                                     */
/* 3- Function Return      -> No Thing
 */

void TIMx_INIT(u64 prescaler )
{
	if(prescaler >=65536)
	{
		prescaler =65536;
	}
#if TIMER2 == ENABLE
	/*
	 *  enable clk for timer2
	 */

	MRCC_vEnableClock(APB1,RCC_TIM2_EN);

	// Configure the prescaler and period for desired timebase
	TIM2->PSC = prescaler - 1;  // Prescaler value (16 MHz / 16000 = 1 kHz)
	u64 timer_freq_TIM2 =  16000000 / ( (TIM2->PSC)+1);
	TIM2->ARR = timer_freq_TIM2 - 1;   // Auto-reload value (1 kHz / 1000 = 1 second)

	// Enable the update interrupt
	TIM2->DIER |= DIER_UIE;

	/*
	 * enable timer2 interrupt in NVIC
	 */
	MNVIC_vSetGroupMode(MNVIC_G4_SG4);
	MNVIC_vSetInterruptPriority(TIM2_IRQ, 0, 0);
	MNVIC_vInterruptSetEnable(TIM2_IRQ);

	// Start the timer
	TIM2->CR1 |= CR1_CEN;
#endif

#if TIMER3 == ENABLE
	/*
	 *  enable clk for timer3
	 */

	MRCC_vEnableClock(APB1,RCC_TIM3_EN);

	// Configure the prescaler and period for desired timebase
	TIM3->PSC = prescaler - 1;  // Prescaler value (16 MHz / 16000 = 1 kHz)
	u64 timer_freq_TIM3 =  16000000 / ( TIM3->PSC+1);
	TIM3->ARR = timer_freq_TIM3 - 1;   // Auto-reload value (1 kHz / 1000 = 1 second)

	// Enable the update interrupt
	TIM3->DIER |= DIER_UIE;

	/*
	 * enable timer3 interrupt in NVIC
	 */
	MNVIC_vSetGroupMode(MNVIC_G4_SG4);
	MNVIC_vSetInterruptPriority(TIM3_IRQ, 0, 0);
	MNVIC_vInterruptSetEnable(TIM3_IRQ);

	// Start the timer
	TIM3->CR1 |= CR1_CEN;
#endif

#if TIMER4 == ENABLE
	/*
	 *  enable clk for timer 4
	 */

	MRCC_vEnableClock(APB1,RCC_TIM4_EN);

	// Configure the prescaler and period for desired timebase
	TIM4->PSC = prescaler - 1;  // Prescaler value (16 MHz / 16000 = 1 kHz)
	u64 timer_freq_TIM4 =  16000000 / ( TIM4->PSC+1);
	TIM4->ARR = timer_freq_TIM4 - 1;   // Auto-reload value (1 kHz / 1000 = 1 second)

	// Enable the update interrupt
	TIM4->DIER |= DIER_UIE;

	/*
	 * enable timer4 interrupt in NVIC
	 */
	MNVIC_vSetGroupMode(MNVIC_G4_SG4);
	MNVIC_vSetInterruptPriority(TIM4_IRQ, 0, 0);
	MNVIC_vInterruptSetEnable(TIM4_IRQ);
	// Start the timer
	TIM4->CR1 |= CR1_CEN;
#endif

#if TIMER5 == ENABLE
	/*
	 *  enable clk for timer5
	 */

	MRCC_vEnableClock(APB1,RCC_TIM5_EN);

	// Configure the prescaler and period for desired timebase
	TIM5->PSC = prescaler - 1;  // Prescaler value (16 MHz / 16000 = 1 kHz)
	u64 timer_freq_TIM5 =  16000000 / ( TIM5->PSC+1);
	TIM5->ARR = timer_freq_TIM5 - 1;   // Auto-reload value (1 kHz / 1000 = 1 second)

	// Enable the update interrupt
	TIM5->DIER |= DIER_UIE;

	/*
	 * enable timer5 interrupt in NVIC
	 */
	MNVIC_vSetGroupMode(MNVIC_G4_SG4);
	MNVIC_vSetInterruptPriority(TIM5_IRQ, 0, 0);
	MNVIC_vInterruptSetEnable(TIM5_IRQ);

	// Start the timer
	TIM5->CR1 |= CR1_CEN;
#endif
}

void TIMx_DISABLE(TIM_x Timer)
{
	switch(Timer){
	case TIM_2:
		TIM2->CR1 &= ~CR1_CEN;
		break;
	case TIM_3:
		TIM3->CR1 &= ~CR1_CEN;
		break;
	case TIM_4:
		TIM4->CR1 &= ~CR1_CEN;
		break;
	case TIM_5:
		TIM5->CR1 &= ~CR1_CEN;
		break;
	default:
		break;
	}
}

void TIMx_ENABLE(TIM_x Timer)
{
	switch(Timer){
	case TIM_2:
		TIM2->CR1 |= CR1_CEN;
		break;
	case TIM_3:
		TIM3->CR1 |= CR1_CEN;
		break;
	case TIM_4:
		TIM4->CR1 |= CR1_CEN;
		break;
	case TIM_5:
		TIM5->CR1 |= CR1_CEN;
		break;
	default:
		break;
	}
}
