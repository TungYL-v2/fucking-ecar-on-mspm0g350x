#include "headfile.h"



//-------------------------------------------------------------------------------------------------------------------
//���´�����Ӻ� ����ʹ��printf���� ��Ҫ��ʼ������UART_1
//-------------------------------------------------------------------------------------------------------------------
#if 1
// �ض���fputc����

int fputc(int ch, FILE *f)
{
	DL_UART_transmitDataBlocking(UART_0_INST, ch);
	return (ch);
}

// �ض���fputs����
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


// �ض���puts����
int puts(const char* _ptr)
{
    int count = fputs(_ptr,stdout);
    count += fputs("\n",stdout);
    return count;
}

#endif

//-------------------------------------------------------------------------------------------------------------------
// @brief		�������ó�ʼ��
// @param		IRQn				ѡ�񴮿�
// @param		UART_0_BAUD_RATE	���ڲ�������sysconfig�����ã���ѯ�궨��UART_0_BAUD_RATE
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
    // ��С����Little-Endian������
    uart_sendbyte(uart, (uint8_t)(data >> 0));   // ��������ֽ�
    uart_sendbyte(uart, (uint8_t)(data >> 8));
    uart_sendbyte(uart, (uint8_t)(data >> 16));
    uart_sendbyte(uart, (uint8_t)(data >> 24));  // ��������ֽ�
}


//-------------------------------------------------------------------------------------------------------------------
// @brief		���ڷ����ֽ�
// @param		uartn		ѡ�񴮿�
// @param		Byte    ���͵��ֽ�
// @return		void  
// Sample usage:		uart_sendbyte(UART_0_INST,0x01);
//-------------------------------------------------------------------------------------------------------------------
void uart_sendbyte(UART_Regs *uart, uint8_t data)  
{
	DL_UART_transmitDataBlocking(uart , data);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief		���ڷ����ַ���
// @param		uartn		ѡ�񴮿�
// @param		str    ���͵��ַ���
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
// @brief		���ڽ����ֽ�(�ڴ����ж������)
// @param		uartn		ѡ�񴮿�
// @param		data    ���յ��ֽڴ洢��data����(��Ҫ�Լ�����һ��data����)
// @return		void  
// Sample usage:	uint8_t dat = uart_getbyte(UART_0_INST);
//-------------------------------------------------------------------------------------------------------------------
uint8_t uart_getbyte(UART_Regs *uart)
{
		   //�����ݼĴ����ж�ȡ����
	return DL_UART_receiveDataBlocking(uart);
}










