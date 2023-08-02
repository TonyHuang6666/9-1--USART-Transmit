#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

int main(void)
{
	OLED_Init();
	OLED_ShowString(1, 1, "Hi!");
	Serial_Initilize();
	uint8_t str[] = "Hello World!";
	uint8_t array[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
										 0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f};

	while(1)
	{
		//Serial_SendArray(array,16);
		Serial_SendString(str);
		Serial_SendNumber(123456789,10);
		printf("Num=%d\n",12345);
		Serial_Printf("Num=%d\r\n",666);
		Delay_ms(1000);
	}
}
