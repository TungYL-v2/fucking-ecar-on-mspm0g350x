#include "headfile.h"



//-------------------------------------------------------------------------------------------------------------------
//以下代码添加后 可以使用printf函数 需要初始化串口UART_1
//-------------------------------------------------------------------------------------------------------------------
#if 1
// 重定向fputc函数

int fputc(int ch, FILE *f)
{
	DL_UART_transmitDataBlocking(UART_0_INST, ch);
	return (ch);
}

// 重定向fputs函数
int fputs(const char* restrict s, FILE* restrict stream) 
{
    uint16_t i,len;
    len = strlen(s);
    for(i=0;i<len;i++)
    {
        DL_UART_transmitDataBlocking(UART_0_INST, s[i]);
    }
    return len;
}


// 重定向puts函数
int puts(const char* _ptr)
{
    int count = fputs(_ptr,stdout);
    count += fputs("\n",stdout);
    return count;
}

#endif

//-------------------------------------------------------------------------------------------------------------------
// @brief		串口配置初始化
// @param		IRQn				选择串口
// @param		UART_0_BAUD_RATE	串口波特率在sysconfig中配置，查询宏定义UART_0_BAUD_RATE
// @return		void  
// Sample usage:		uart_init(UART_0_INST_INT_IRQN);
//-------------------------------------------------------------------------------------------------------------------
void uart_init(IRQn_Type IRQn)
{
	NVIC_ClearPendingIRQ(IRQn);
    NVIC_EnableIRQ(IRQn);
}

void uart_send_uint32(UART_Regs *uart, uint32_t data) 
{
    // 按小端序（Little-Endian）发送
    uart_sendbyte(uart, (uint8_t)(data >> 0));   // 发送最低字节
    uart_sendbyte(uart, (uint8_t)(data >> 8));
    uart_sendbyte(uart, (uint8_t)(data >> 16));
    uart_sendbyte(uart, (uint8_t)(data >> 24));  // 发送最高字节
}


//-------------------------------------------------------------------------------------------------------------------
// @brief		串口发送字节
// @param		uartn		选择串口
// @param		Byte    发送的字节
// @return		void  
// Sample usage:		uart_sendbyte(UART_0_INST,0x01);
//-------------------------------------------------------------------------------------------------------------------
void uart_sendbyte(UART_Regs *uart, uint8_t data)  
{
	DL_UART_transmitDataBlocking(uart , data);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief		串口发送字符串
// @param		uartn		选择串口
// @param		str    发送的字符串
// @return		void  
// Sample usage:		uart_sendstr(UART_0_INST,"error");
//-------------------------------------------------------------------------------------------------------------------
void uart_sendstr(UART_Regs *uart, char* str)
{
	while(*str != '\0')
	{
		DL_UART_transmitDataBlocking(uart , *str++);
	}
}


//-------------------------------------------------------------------------------------------------------------------
// @brief		串口接收字节(在串口中断里调用)
// @param		uartn		选择串口
// @param		data    接收的字节存储在data变量(需要自己定义一个data变量)
// @return		void  
// Sample usage:	uint8_t dat = uart_getbyte(UART_0_INST);
//-------------------------------------------------------------------------------------------------------------------
uint8_t uart_getbyte(UART_Regs *uart)
{
		   //从数据寄存器中读取数据
	return DL_UART_receiveDataBlocking(uart);
}










