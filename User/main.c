#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

int main(void)
{
	OLED_Init();
	Serial_Initilize();
	
	while(1)
	{
		Serial_SendByte(0x41);
		Delay_ms(10000);
	}
}
