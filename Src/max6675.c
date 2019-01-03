#include "max6675.h"
#include <stdlib.h>


void Init_max6675(void)
{
	//define pin modes
	GPIO_InitTypeDef GPIO_InitStruct;

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOB_CLK_ENABLE();
	/*Configure GPIO pins : SCLK_PIN */
	GPIO_InitStruct.Pin = SCLK_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(SCLK_PORT, &GPIO_InitStruct);

	/*Configure GPIO pins : CS_PIN */
	GPIO_InitStruct.Pin = CS_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(CS_PORT, &GPIO_InitStruct);

	/*Configure GPIO pin : MISO_PIN */
	GPIO_InitStruct.Pin = MISO_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(MISO_PORT, &GPIO_InitStruct);
}



float readFahrenheit() {
	return readCelsius() * 9.0/5.0 + 32;
}

uint16_t readCelsius() {

	uint16_t v=0;
	digitalWrite(CS, HIGH);
	digitalWrite(CS, LOW);
	v = SPIread();
	v <<= 8;
	v |= SPIread();
	digitalWrite(CS, HIGH);
	if (v & 0x04) {
		// oh oh, no Thermocouple attached!
		return NAN;
		//return -100;
	}

	v >>= 3;
	return v;

}

uint8_t SPIread(void) {
	int i;
	uint8_t d = 0;
	for (i=7; i>=0; i--)
	{
		digitalWrite(SCLK, LOW);
		if (digitalRead(MISO)) {
			//set the bit to 0 no matter what
			d |= (1 << i);
		}
		digitalWrite(SCLK, HIGH);
	}
	return d;
}
