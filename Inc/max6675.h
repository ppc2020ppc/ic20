/*
 * max6675.h
 *
 *  Created on: ? ÂÈÇä ???? åž.Ô.
 *      Author: pr
 */

#ifndef MAX6675_H_
#define MAX6675_H_
#include "stm32f1xx_hal.h"


#define NAN								1
#define SCLK_PIN						GPIO_PIN_6
#define SCLK_PORT						GPIOB

#define CS_PIN							GPIO_PIN_5
#define CS_PORT							GPIOB

#define MISO_PIN						GPIO_PIN_4
#define MISO_PORT						GPIOB



#define SCLK							GPIOB,GPIO_PIN_6
#define CS								GPIOB,GPIO_PIN_5
#define MISO							GPIOB,GPIO_PIN_4


#define HIGH							GPIO_PIN_SET
#define LOW								GPIO_PIN_RESET

#define _HAL_PORT_RCC(x)				__HAL_RCC_##x##_CLK_ENABLE()
#define digitalWrite(PIN,VALUE)			HAL_GPIO_WritePin(PIN,VALUE)
#define digitalRead(PIN)				HAL_GPIO_ReadPin(PIN)


void Init_max6675(void);
float readFahrenheit() ;
uint16_t readCelsius();
uint8_t SPIread(void);

#endif /* MAX6675_H_ */
