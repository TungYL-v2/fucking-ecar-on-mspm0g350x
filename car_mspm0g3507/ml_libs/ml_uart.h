#ifndef _ml_uart_h_
#define _ml_uart_h_
#include "headfile.h"


typedef enum
{
		UART_1  =  0x00,  // PA9 -> TX     PA10 -> RX
	  UART_2  =  0x01,  // PA2 -> TX     PA3 -> RX
	  UART_3  =  0x02,  // PB10 -> TX    PB11 -> RX
}UARTn_enum;

void uart_init(IRQn_Type IRQn);
void uart_baud_config(UARTn_enum uartn,int baud);
void uart_sendbyte(UART_Regs *uart, uint8_t data);
uint8_t uart_getbyte(UART_Regs *uart);
void uart_sendstr(UART_Regs *uart, char* str);

void uart_send_uint32(UART_Regs *uart, uint32_t data);


#endif
