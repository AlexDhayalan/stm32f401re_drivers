/*
 * 002led_button.c
 *
 *  Created on: 09-Mar-2022
 *      Author: alex
 */


#include "stm32f401RE.h"

void delay(void){
	for(uint32_t i = 0; i < 500000; i++);
}



int main(void){
	GPIO_Handle_t gpioLed, gpioBtn;

	gpioLed.pGPIOx = GPIOA;
	gpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	gpioLed.GPIO_PinConfig.GPIO_PinMode  =  GPIO_MODE_OUT;
	gpioLed.GPIO_PinConfig.GPIO_PinSpeed  = GPIO_OP_SPEED_HIGH;
	gpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NOPUPD;

    GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&gpioLed);

	gpioBtn.pGPIOx = GPIOC;
	gpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	gpioBtn.GPIO_PinConfig.GPIO_PinMode  =  GPIO_MODE_IN;
	gpioBtn.GPIO_PinConfig.GPIO_PinSpeed  = GPIO_OP_SPEED_HIGH;
	gpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NOPUPD;

	GPIO_PeriClockControl(GPIOC, ENABLE);
	GPIO_Init(&gpioBtn);

	while(1){
		if(GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == DISABLE){
			delay();
			GPIO_TogglePin(GPIOA, GPIO_PIN_NO_5);

		}
	}
	return 0;
}
