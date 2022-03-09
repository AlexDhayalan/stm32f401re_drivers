/*
 * stm32f401RE.h
 *
 *  Created on: Feb 21, 2022
 *      Author: alex
 */

#ifndef INC_STM32F401RE_H_
#define INC_STM32F401RE_H_

#include <stdint.h>

#define __vo volatile

#define FLASH_BASEADDR			0x08000000U
#define SRAM1_BASEADDR			0X20000000U
#define ROM						0x1FFF0000U

#define PERIPH_BASE				0x40000000U
#define APB1PERIPH_BASE			PERIPH_BASE
#define APB2PERIPH_BASE			0x40010000U
#define AHB1PERIPH_BASE			0X40020000U
#define AHB2PERIPH_BASE			0X50000000U

/*
 * AHB1 PERIPHERALS
 */
#define GPIOA_BASEADDR			(AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASEADDR			(AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASEADDR			(AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR			(AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR			(AHB1PERIPH_BASE + 0x1000)
#define GPIOH_BASEADDR			(AHB1PERIPH_BASE + 0x1C00)\

#define RCC_BASEADDR			(AHB1PERIPH_BASE + 0x3800)

/*
 * APB1 PERIPHERALS
 */

#define I2C1_BASEADDR			(APB1PERIPH_BASE + 0x5400)
#define I2C2_BASEADDR			(APB1PERIPH_BASE + 0x5800)
#define I2C3_BASEADDR			(APB1PERIPH_BASE + 0x5C00)

#define SPI2_BASEADDR			(APB1PERIPH_BASE + 0x3800)
#define SPI3_BASEADDR			(APB1PERIPH_BASE + 0x3C00)

#define USART2_BASEADDR			(APB1PERIPH_BASE + 0x4400)

/*
 * APB2_PERIPHERALS
 */

#define USART1_BASEADDR			(APB2PERIPH_BASE + 0x1000)
#define USART6_BASEADDR			(APB2PERIPH_BASE + 0x1400)

#define SPI1_BASEADDR			(APB2PERIPH_BASE + 0x3000)
#define SPI4_BASEADDR			(APB2PERIPH_BASE + 0x3400)

#define EXTI_BASEADDR			(APB2PERIPH_BASE + 0x3C00)
#define SYSCFG_BASEADDR			(APB2PERIPH_BASE + 0x3800)

   /*
    * Peripheral Register definition
    */

typedef struct{
	__vo uint32_t MODER;				/*Port mode							Address Offset : 0x00*/
	__vo uint32_t OTYPER;				/*Port Output type					Address Offset : 0x04*/
	__vo uint32_t OSPEEDR;				/*Port Output Speed type			Address Offset : 0x08*/
	__vo uint32_t PUPDR;				/*Port pull up/ pull down register	Address Offset : 0x0c*/
	__vo uint32_t IDR;					/*Input Data mode					Address Offset : 0x10*/
	__vo uint32_t ODR;					/*Output Data mode					Address Offset : 0x14*/
	__vo uint32_t BSRR;					/*Port Bit set/reset Register		Address Offset : 0x18*/
	__vo uint32_t LCKR;					/*Port Configuration Lock Register	Address Offset : 0x1c*/
	__vo uint32_t AFR[2];				/*Port Alternate Function Register  Address Offset : 0x20 - 0x24 | AFR[0] = AFRL AFR[1] = AFRH*/
}GPIO_RegDef_t;

typedef struct{
	__vo uint32_t CR; 					/*Clock Control Register			Address Offset : 0x00*/
	__vo uint32_t PLLCFGR; 				/*PLL Configuration Register		Address Offset : 0x04*/
	__vo uint32_t CFGR; 				/*Clock Configuration Register		Address Offset : 0x08*/
	__vo uint32_t CIR; 					/*Clock Interrupt Register			Address Offset : 0x0c*/
	__vo uint32_t AHB1RSTR; 			/*AHB1 Peripheral Reset Register	Address Offset : 0x10*/
	__vo uint32_t AHB2RSTR; 			/*AHB2 Peripheral Reset Register	Address Offset : 0x14*/
	__vo uint32_t RES[2]; 				/*RESERVED							Address Offset : 0x18 - 0x1c*/
	__vo uint32_t APB1RSTR; 			/*APB1 Peripheral Reset Register	Address Offset : 0x20*/
	__vo uint32_t APB2RSTR; 			/*APB2 Peripheral Reset Register	Address Offset : 0x24*/
	__vo uint32_t RES1[2]; 				/*RESERVED   						Address Offset : 0x28 - 0x2c*/
	__vo uint32_t AHB1ENR; 				/*AHB1 Clock Enable Register		Address Offset : 0x30*/
	__vo uint32_t AHB2ENR; 				/*AHB2 Clock Enable Register		Address Offset : 0x34*/
	__vo uint32_t RES2[2]; 				/*RESERVED							Address Offset : 0x38 - 0x3c*/
	__vo uint32_t APB1ENR; 				/*APB1 Clock Enable Register		Address Offset : 0x40*/
	__vo uint32_t APB2ENR; 				/*APB2 Clock Enable Register		Address Offset : 0x44*/
	__vo uint32_t RES3[2]; 				/*RESERVED			`				Address Offset : 0x48 - 0x4c*/
	__vo uint32_t AHB1LPENR; 			/*AHB1 Clk Enable Low pwr Register	Address Offset : 0x50*/
	__vo uint32_t AHB2LPENR; 			/*AHB2 Clk Enable Low pwr Register	Address Offset : 0x54*/
	__vo uint32_t RES4[2]; 				/*RESERVED							Address Offset : 0x58 - 0x5c*/
	__vo uint32_t APB1LPENR; 			/*APB1 Clk Enable Low pwr Register	Address Offset : 0x60*/
	__vo uint32_t APB2LPENR; 			/*APB2 Clk Enable Low pwr Register	Address Offset : 0x64*/
	__vo uint32_t RES5[2]; 				/*RESERVED							Address Offset : 0x68 - 0x6c*/
	__vo uint32_t BDCR; 				/*Backup Domain Control Register	Address Offset : 0x70*/
	__vo uint32_t CSR; 					/*Clock Control and Status Register	Address Offset : 0x74*/
	__vo uint32_t RES6[2]; 				/*RESERVED							Address Offset : 0x78 - 0x7c*/
	__vo uint32_t SSCGR; 				/*Spread Spectrum Clk Gen Register	Address Offset : 0x80*/
	__vo uint32_t PLLI2SCFGR; 			/*PLLI2S Configuration Register		Address Offset : 0x84*/
	__vo uint32_t RES7; 				/*RESERVED							Address Offset : 0x88*/
	__vo uint32_t DCKCFGR; 				/*Dedicated Clock Config Register	Address Offset : 0x8c*/
}RCC_RegDef_t;

/*
 * Peripheral definitions
 */

#define GPIOA					((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB					((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC					((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD					((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE					((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOH					((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define RCC						((RCC_RegDef_t*)RCC_BASEADDR)

/*
 * Clock Enable macros for GPIOs
 */
#define GPIOA_PCLK_EN()			(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()			(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()			(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()			(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()			(RCC->AHB1ENR |= (1 << 4))
#define GPIOH_PCLK_EN()			(RCC->AHB1ENR |= (1 << 7))

/*
 * Clock Enable macros for SPIs
 */
#define SPI1_PCLK_EN()			(RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()			(RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()			(RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN()			(RCC->APB2ENR |= (1 << 13))

/*
 * Clock Enable macros for I2Cs
 */
#define I2C1_PCLK_EN()			(RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()			(RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()			(RCC->APB1ENR |= (1 << 23))

/*
 * Clock Enable macros for USARTs
 */
#define USART1_PCLK_EN()			(RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN()			(RCC->APB1ENR |= (1 << 17))
#define USART6_PCLK_EN()			(RCC->APB2ENR |= (1 << 5))

/*
 * Clock Disable macros for GPIOs
 */
#define GPIOA_PCLK_DI()			(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()			(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()			(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()			(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()			(RCC->AHB1ENR &= ~(1 << 4))
#define GPIOH_PCLK_DI()			(RCC->AHB1ENR &= ~(1 << 7))

/*
 * Clock Disable macros for SPIs
 */
#define SPI1_PCLK_DI())			(RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()			(RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()			(RCC->APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI()			(RCC->APB2ENR &= ~(1 << 13))

/*
 * Clock Disable macros for I2Cs
 */
#define I2C1_PCLK_DI()			(RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()			(RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI()			(RCC->APB1ENR &= ~(1 << 23))

/*
 * Clock Disable macros for USARTs
 */
#define USART1_PCLK_DI()			(RCC->APB2ENR &= ~(1 << 4))
#define USART2_PCLK_DI()			(RCC->APB1ENR &= ~(1 << 17))
#define USART6_PCLK_DI()			(RCC->APB2ENR &= ~(1 << 5))


/*
 * GPIO reset macro
 */
#define GPIOA_REG_RESET() 		do{ (RCC->AHB1RSTR |= (1<<0)); (RCC->AHB1RSTR &= ~(1<<0)); } while(0)
#define GPIOB_REG_RESET() 		do{ (RCC->AHB1RSTR |= (1<<1)); (RCC->AHB1RSTR &= ~(1<<1)); } while(0)
#define GPIOC_REG_RESET() 		do{ (RCC->AHB1RSTR |= (1<<2)); (RCC->AHB1RSTR &= ~(1<<2)); } while(0)
#define GPIOD_REG_RESET() 		do{ (RCC->AHB1RSTR |= (1<<3)); (RCC->AHB1RSTR &= ~(1<<3)); } while(0)
#define GPIOE_REG_RESET() 		do{ (RCC->AHB1RSTR |= (1<<4)); (RCC->AHB1RSTR &= ~(1<<4)); } while(0)
#define GPIOH_REG_RESET() 		do{ (RCC->AHB1RSTR |= (1<<7)); (RCC->AHB1RSTR &= ~(1<<7)); } while(0)

#define ENABLE 					1
#define DISABLE 				0
#define SET						ENABLE
#define RESET					DISABLE
#define GPIO_PIN_SET			SET
#define GPIO_PIN_RESET			RESET

#include "stm32f401re_gpio_driver.h"

#endif /* INC_STM32F401RE_H_ */
