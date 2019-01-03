/*
tc * ADS7816.h
 *
 *  Created on: ? ÂÈÇä ???? åž.Ô.
 *      Author: pr
 */

#ifndef ADS7816_H_
#define ADS7816_H_
#include "stm32f1xx_hal.h"

#define ADS_Data_PIN					GPIO_PIN_15
#define ADS_Data_PORT					GPIOA

#define ADS_CLK_PIN						GPIO_PIN_14
#define ADS_CLK_PORT					GPIOA

#define ADS_CS_PIN						GPIO_PIN_10
#define ADS_CS_PORT						GPIOC

#define HIGH							GPIO_PIN_SET
#define LOW								GPIO_PIN_RESET


//#define ADS_DATA						ADS_Data_PORT##,##ADS_Data_PIN
//#define ADS_CLK					    ADS_CLK_PORT##,##ADS_CLK_PIN
//#define ADS_CS						ADS_CS_PORT##,##ADS_CS_PORT

#define NAN 							-100

#define ADS_CS_HIGH						digitalWrite(ADS_CS_PORT,ADS_CS_PIN, HIGH)
#define ADS_CS_LOW						digitalWrite(ADS_CS_PORT,ADS_CS_PIN, LOW)

#define CLK_HIGH						digitalWrite(ADS_CLK_PORT,ADS_CLK_PIN, HIGH)
#define CLK_LOW							digitalWrite(ADS_CLK_PORT,ADS_CLK_PIN, LOW)
#define DataPIN_read()					digitalRead(ADS_Data_PORT,ADS_Data_PIN)


#define digitalWrite(PORT,PIN,VALUE)			HAL_GPIO_WritePin(PORT,PIN,VALUE)
#define digitalRead(PORT,PIN)					HAL_GPIO_ReadPin(PORT,PIN)


uint16_t read_ADS7816S(uint8_t channel);
void Init_ADS7816(void);
uint16_t read_ADS7816();
uint16_t Dataread(void);

#endif /* ADS7816_H_ */
