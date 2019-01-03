/*
 * GlabalVar.h
 *
 *  Created on: ? Ï? ???? åž.Ô.
 *      Author: pr
 */

#ifndef GLABALVAR_H_
#define GLABALVAR_H_

#include "stm32f1xx_hal.h"


SPI_HandleTypeDef hspi2;

//TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;


#endif /* GLABALVAR_H_ */
