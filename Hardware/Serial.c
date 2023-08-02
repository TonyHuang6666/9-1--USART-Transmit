#include "stm32f10x.h"
#include "OLED.h"
void Serial_Initilize(void)
{
	//1.配置时钟
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	//2.配置GPIO。TX用复用推挽输出；RX用浮空输入或者上拉输入，因为串口空闲状态为高电平
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	//3.配置串口
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1, &USART_InitStructure);
	//4.开启串口
	USART_Cmd(USART1, ENABLE);
}

void Serial_SendByte(uint8_t data)
{
    USART_SendData(USART1, data);//data变量写入到USART1_DR寄存器中
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);//等待，直到发送完成，即TXE=1，TXE标志位置SET
    //标志位不需要手动清零，写入新数据时会自动清零
}

void Serial_SendString(uint8_t *str)
{
	while(*str != '\0')
	{
		Serial_SendByte(*str);
		str++;
	}
}

void Serial_SendArray(uint8_t *array, uint16_t length)
{
	uint16_t i,length;
	length=sizeof(array)/sizeof(array[0]);//数组的总字节数除以单个元素的字节数，就可以得到数组的长度
	OLED_ShowNum(2, 1, length, 3);
	for(i = 0; i < length; i++)
	{
		Serial_SendByte(array[i]);
	}
}