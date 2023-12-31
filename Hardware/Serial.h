#ifndef SERIAL_H
#define SERIAL_H
#include "stdio.h"
void Serial_Initilize(void);
void Serial_SendByte(uint8_t data);
void Serial_SendString(uint8_t *str);
void Serial_SendArray(uint8_t *array, uint16_t length);
void Serial_SendNumber(uint32_t Number,uint8_t Length);
void Serial_Printf(char *format,...);
#endif