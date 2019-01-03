#include "Termo.h"
#include "ADG508T.h"
#include "max6675.h"
void Init_Termo(void)
{
	Init_max6675();
	Init_ADG508_termo();
}

uint16_t read_Temp()
{
	return readCelsius();
}
void setChannel_Termo(uint8_t num)
{
	setChannelTermo(num);
}

