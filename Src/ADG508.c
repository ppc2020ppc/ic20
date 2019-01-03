#include <ADG508.h>


void Init_ADG508(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	/*Configure GPIO pins : sel_PIN */
	GPIO_InitStruct.Pin = IN1_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(IN1_PORT, &GPIO_InitStruct);
	/*Configure GPIO pins : sel_PIN */
	GPIO_InitStruct.Pin =  IN2_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(IN2_PORT, &GPIO_InitStruct);
	/*Configure GPIO pins : sel_PIN */
	GPIO_InitStruct.Pin =  IN3_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(IN3_PORT, &GPIO_InitStruct);
}

void setOut(uint8_t outPutnumber)
{
	if(outPutnumber & 0x01)digitalWrite3(IN1_PORT,IN1_PIN,HIGH);
	else digitalWrite3(IN1_PORT,IN1_PIN,LOW);
	if(outPutnumber & 0x02)digitalWrite3(IN2_PORT,IN2_PIN,HIGH);
	else digitalWrite3(IN2_PORT,IN2_PIN,LOW);
	if(outPutnumber & 0x04)digitalWrite3(IN3_PORT,IN3_PIN,HIGH);
	else digitalWrite3(IN3_PORT,IN3_PIN,LOW);
}
