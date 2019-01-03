
#ifndef ADG508_H_
#define ADG508_H_
#include "stm32f1xx_hal.h"

#define IN1_PORT						GPIOB
#define IN1_PIN							GPIO_PIN_3

#define IN2_PORT						GPIOC
#define IN2_PIN							GPIO_PIN_12

#define IN3_PORT						GPIOC
#define IN3_PIN							GPIO_PIN_11


#define HIGH							GPIO_PIN_SET
#define LOW								GPIO_PIN_RESET

#define digitalWrite3(PORT,PIN,VALUE)	HAL_GPIO_WritePin(PORT,PIN,VALUE)

void Init_ADG508(void);
void setOut(uint8_t outPutnumber);
#endif /* 74ADG508_H_ */
