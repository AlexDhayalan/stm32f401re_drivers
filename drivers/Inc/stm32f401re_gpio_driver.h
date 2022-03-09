/*
 * stm32f401re_gpio_driver.h
 *
 *  Created on: 22-Feb-2022
 *      Author: alex
 */

#ifndef INC_STM32F401RE_GPIO_DRIVER_H_
#define INC_STM32F401RE_GPIO_DRIVER_H_

#include "stm32f401RE.h"

typedef struct{
	uint8_t GPIO_PinNumber;					/* possible values from @GPIO_PIN_NUMBERS */
	uint8_t GPIO_PinMode;					/* possible values from @GPIO_PIN_MODES */
	uint8_t GPIO_PinSpeed;					/* possible values from @GPIO_PIN_SPEED */
	uint8_t GPIO_PinPuPdControl;			/* possible values from @GPIO_PIN_PUPDCTRL */
	uint8_t GPIO_PinOPType;					/* possible values from @GPIO_OP TYPES */
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;


typedef struct{

	GPIO_RegDef_t *pGPIOx;			//Holds the base address of the GPIO port of the pin
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;

/*
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0		0
#define GPIO_PIN_NO_1		1
#define GPIO_PIN_NO_2		2
#define GPIO_PIN_NO_3		3
#define GPIO_PIN_NO_4		4
#define GPIO_PIN_NO_5		5
#define GPIO_PIN_NO_6		6
#define GPIO_PIN_NO_7		7
#define GPIO_PIN_NO_8		8
#define GPIO_PIN_NO_9		9
#define GPIO_PIN_NO_10		10
#define GPIO_PIN_NO_11		11
#define GPIO_PIN_NO_12		12
#define GPIO_PIN_NO_13		13
#define GPIO_PIN_NO_14		14
#define GPIO_PIN_NO_15		15


/*
 * @GPIO_PIN_MODES
 * GPIO pin possible mode
 */
#define GPIO_MODE_IN		0
#define GPIO_MODE_OUT 		1
#define GPIO_MODE_ALTFN		2
#define GPIO_MODE_ANALOG	3
#define GPIO_MODE_IT_FT		4
#define GPIO_MODE_IT_RT		5
#define GPIO_MODE_IT_RFT	6

/*
 * @GPIO_OP TYPES
 * GPIO Output modes
 */

#define GPIO_OP_TYPE_PP		0
#define GPIO_OP_TYPE_OD		1


/*
 * @GPIO_PIN_SPEED
 * GPIO pin output speeds
 */
#define GPIO_OP_SPEED_LOW	0
#define GPIO_OP_SPEED_MED	1
#define GPIO_OP_SPEED_HIGH	2
#define GPIO_OP_SPEED_VHIGH	3

/*
 * @GPIO_PIN_PUPDCTRL
 * GPIO pin pull up pull down
 */
#define GPIO_NOPUPD			0
#define GPIO_PU				1
#define GPIO_PD				2

/*
 *
 */


/*
 * Peripheral clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
 * GPIO Init Deinit setup
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Data read and write setup
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * IRQ Configuration and ISR Handling
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);


#endif /* INC_STM32F401RE_GPIO_DRIVER_H_ */
