/*
 * ADS7816.c
 *
 *  Created on: ? ÂÈÇä ???? åž.Ô.
 *      Author: pr
 */
#include "ADS7816.h"
#include "ADG508.h"



void Init_ADS7816(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(ADS_CLK_PORT, ADS_CLK_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(ADS_CS_PORT, ADS_CS_PIN, GPIO_PIN_RESET);

	/*Configure GPIO pins : Clock pin  */
	GPIO_InitStruct.Pin = ADS_CLK_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(ADS_CLK_PORT, &GPIO_InitStruct);

	/*Configure GPIO pins : chip select pin  */
	GPIO_InitStruct.Pin = ADS_CS_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(ADS_CS_PORT, &GPIO_InitStruct);

	/*Configure GPIO pin : data pin */
	GPIO_InitStruct.Pin = ADS_Data_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(ADS_Data_PORT, &GPIO_InitStruct);

	Init_ADG508();
	setOut(0);
}

uint16_t read_ADS7816S(uint8_t channel)
{
	setOut(channel);
	return read_ADS7816();
}


uint16_t read_ADS7816()
{
	uint16_t v=0;
	digitalWrite(ADS_CS_PORT,ADS_CS_PIN,HIGH);
	digitalWrite(ADS_CS_PORT,ADS_CS_PIN,LOW);
	CLK_HIGH;
	for(char i=0;i<2;i++)
	{
		CLK_LOW;
		//HAL_Delay(1);
		CLK_HIGH;
		//HAL_Delay(1);
		if(!DataPIN_read())
		{
			v = Dataread();
			CLK_LOW;
			digitalWrite(ADS_CS_PORT,ADS_CS_PIN,HIGH);
			break;
		}
	}
	return v;
}


uint16_t Dataread(void) {
	int i;
	uint16_t d = 0;
	for (i=11; i>=0; i--)
	{
		CLK_LOW;
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		//HAL_Delay(1);
		CLK_HIGH;
		asm("NOP");
		asm("NOP");
		//HAL_Delay(1);
		if (digitalRead(ADS_Data_PORT,ADS_Data_PIN)) {
			//set the bit to 0 no matter what
			d |= (1 << i);
		}
	}
	return d-1;
}
