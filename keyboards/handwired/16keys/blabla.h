#pragma once

#include_next <mcuconf.h>

#define USE_ADCV1


// #define RP2040_MCUCONF

// #define RP_I2C_USE_I2C0 FALSE
// #define RP_I2C_USE_I2C1 FALSE

#define STM32_ADC_USE_ADC3 TRUE
#define STM32_ADC_USE_ADC2 TRUE

// #define RP_SPI_USE_SPI0                     TRUE
// #define RP_SPI_USE_SPI1                     FALSE

// #define RP_SPI_SPI0_RX_DMA_CHANNEL          RP_DMA_CHANNEL_ID_ANY
// #define RP_SPI_SPI0_TX_DMA_CHANNEL          RP_DMA_CHANNEL_ID_ANY
// #define RP_SPI_SPI1_RX_DMA_CHANNEL          RP_DMA_CHANNEL_ID_ANY
// #define RP_SPI_SPI1_TX_DMA_CHANNEL          RP_DMA_CHANNEL_ID_ANY
// #define RP_SPI_SPI0_DMA_PRIORITY            1
// #define RP_SPI_SPI1_DMA_PRIORITY            1

// #define RP_IRQ_SYSTICK_PRIORITY             2
// #define RP_IRQ_TIMER_ALARM0_PRIORITY        2
// #define RP_IRQ_TIMER_ALARM1_PRIORITY        2
// #define RP_IRQ_TIMER_ALARM2_PRIORITY        2
// #define RP_IRQ_TIMER_ALARM3_PRIORITY        2
// #define RP_IRQ_UART0_PRIORITY               3
// #define RP_IRQ_UART1_PRIORITY               3
// #define RP_IRQ_SPI0_PRIORITY                2
// #define RP_IRQ_SPI1_PRIORITY                2
// #define RP_IRQ_USB0_PRIORITY                3
// #define RP_IRQ_I2C0_PRIORITY                2
// #define RP_IRQ_I2C1_PRIORITY                2

#define ADC_COUNT 2
