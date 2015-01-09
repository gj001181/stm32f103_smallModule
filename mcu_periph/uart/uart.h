#ifndef __UART_H
#define __UART_H

#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "stdio.h"

#define USART2_MAX_RECV_LEN		50	//bytes							

extern uint8_t  USART2_RX_BUF[USART2_MAX_RECV_LEN]; 				
extern uint16_t USART2_RX_STA;   						

/*Function Prototype*/
void Usart1_Init(uint32_t baudrate);
void Usart2_Init(uint32_t baudrate);
#endif

