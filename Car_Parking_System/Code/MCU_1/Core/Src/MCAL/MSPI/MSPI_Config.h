/*******************************************************************************************************
 *******************************************************************************************************
AUTHOR  : MOHAMED ABDELAZIZ
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : SPI_Driver
File    : Configuration File
Version : 1.0
Date	: 24/8/2023
********************************************************************************************************
********************************************************************************************************/

#ifndef MSPI_CONFIG_H_
#define MSPI_CONFIG_H_

/********************************** SPI1 CONFIGURATIONS ***********************************/

#define MSPI1_STATUS			MSPI_ENABLE
#define MSPI1_CLOCK_MODE		MSPI_MODE3
#define MSPI1_MASTER_SLAVE		MSPI_SLAVE
#define MSPI1_PRESCALER			MSPI_FPCLK_4
#define MSPI1_DATA_ORDER		MSPI_MSB_FIRST
#define MSPI1_SS_MANAGE			HW_SLAVE_MANAGEMENT
#define MSPI1_DATA_SIZE			MSPI_8BIT_DATA
#define MSPI1_INT_STATUS		MSPI_INT_DISABLE

/********************************** SPI2 CONFIGURATIONS ***********************************/

#define MSPI2_STATUS			MSPI_DISABLE
#define MSPI2_CLOCK_MODE		MSPI_MODE3
#define MSPI2_MASTER_SLAVE		MSPI_SLAVE
#define MSPI2_PRESCALER			MSPI_FPCLK_4
#define MSPI2_DATA_ORDER		MSPI_MSB_FIRST
#define MSPI2_SS_MANAGE			HW_SLAVE_MANAGEMENT
#define MSPI2_DATA_SIZE			MSPI_8BIT_DATA
#define MSPI2_INT_STATUS		MSPI_INT_DISABLE

/********************************** SPI3 CONFIGURATIONS ***********************************/

#define MSPI3_STATUS			MSPI_DISABLE
#define MSPI3_CLOCK_MODE		MSPI_MODE3
#define MSPI3_MASTER_SLAVE		MSPI_SLAVE
#define MSPI3_PRESCALER			MSPI_FPCLK_4
#define MSPI3_DATA_ORDER		MSPI_MSB_FIRST
#define MSPI3_SS_MANAGE			HW_SLAVE_MANAGEMENT
#define MSPI3_DATA_SIZE			MSPI_8BIT_DATA
#define MSPI3_INT_STATUS		MSPI_INT_DISABLE

/********************************** SPI4 CONFIGURATIONS ***********************************/

#define MSPI4_STATUS			MSPI_DISABLE
#define MSPI4_CLOCK_MODE		MSPI_MODE3
#define MSPI4_MASTER_SLAVE		MSPI_SLAVE
#define MSPI4_PRESCALER			MSPI_FPCLK_4
#define MSPI4_DATA_ORDER		MSPI_MSB_FIRST
#define MSPI4_SS_MANAGE			HW_SLAVE_MANAGEMENT
#define MSPI4_DATA_SIZE			MSPI_8BIT_DATA
#define MSPI4_INT_STATUS		MSPI_INT_DISABLE

#endif /* MSPI_CONFIG_H_ */
