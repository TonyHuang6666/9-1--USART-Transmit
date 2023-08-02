#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

int main(void)
{
	OLED_Init();
	OLED_ShowString(1, 1, "Hi!");
	Serial_Initilize();
	
	while(1)
	{
		Serial_SendByte(0x41);
		Delay_ms(1000);
	}
}
