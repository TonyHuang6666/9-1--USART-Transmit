#ifndef SERIAL_H
#define SERIAL_H
void Serial_Initilize(void);
void Serial_SendByte(uint8_t data);
void Serial_SendString(uint8_t *str);
void Serial_SendArray(uint8_t *array);
#endif