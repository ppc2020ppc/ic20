#ifndef TERMO_H_
#define TERMO_H_
#include "stm32f1xx_hal.h"

void Init_Termo(void);
uint16_t read_Temp();
void setChannel_Termo(uint8_t num);
#endif /* TERMO_H_ */
