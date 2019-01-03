
#ifndef ADG508T_H_
#define ADG508T_H_
#include "stm32f1xx_hal.h"

#define IN_PORT							GPIOB
#define IN1_PIN							GPIO_PIN_7
#define IN2_PIN							GPIO_PIN_9
#define IN3_PIN							GPIO_PIN_8


#define HIGH							GPIO_PIN_SET
#define LOW								GPIO_PIN_RESET

#define digitalWrite3(PORT,PIN,VALUE)	HAL_GPIO_WritePin(PORT,PIN,VALUE)

void Init_ADG508_termo(void);
void setChannelTermo(uint8_t outPutnumber);
#endif /* 74ADG508T_H_ */
