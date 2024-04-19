/*
 * MRCC_Int.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Mostafa Ashraf
 */

#ifndef MCAL_MRCC_INT_H_
#define MCAL_MRCC_INT_H_

typedef enum {
	AHB1, AHB2, APB1, APB2,
}RCC_ENR;

typedef enum {

	/************************* AHBx ****************************/
	RCC_GPIOA_EN, RCC_GPIOB_EN, RCC_GPIOC_EN, RCC_GPIOD_EN, RCC_GPIOE_EN,
	RCC_GPIOH_EN = 7, RCC_OTGFS_EN = 7, RCC_CRC_EN = 12, RCC_DMA1_EN = 21, RCC_DMA2_EN,

	/************************* APB1 ****************************/
	RCC_TIM2_EN = 0, RCC_TIM3_EN, RCC_TIM4_EN,  RCC_TI5M_EN, RCC_WWDG_EN = 11, RCC_SPI2_EN = 14,
	RCC_SPI3_EN, RCC_USART2_EN = 17, RCC_I2C1_EN = 21, RCC_I2C2_EN, RCC_I2C3_EN, RCC_PWR_EN = 28,

	/************************* APB2 ****************************/
	RCC_TIM1_EN = 0, RCC_USART1_EN = 4, RCC_USART6_EN, RCC_ADC1_EN = 8, RCC_SDIO_EN = 11,RCC_SPI1_EN,
	RCC_SPI4_EN, RCC_SYSCFG_EN, RCC_TIM9_EN = 16, RCC_TIM10_EN, RCC_TIM11_EN

}RCC_Peripheral;

void MRCC_vInit(void) ;
void MRCC_vEnableClock(RCC_ENR REG, RCC_Peripheral PER);
void MRCC_vDisableClock(RCC_ENR REG, RCC_Peripheral PER);


#endif /* MCAL_MRCC_INT_H_ */
