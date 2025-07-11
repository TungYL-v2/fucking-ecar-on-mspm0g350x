#include "mspm0_i2c.h"

//���赥������init
void I2C_Init(void)
{
	SYSCFG_DL_I2C_0_init();
}

/*
�������к���ֻ���I2C_0,�ݶ�����Ϊ��JY901S�ȵ�һ�豸��ȡ����
*/
void I2C_Write(uint8_t devAddr, uint8_t reg, uint8_t *data, uint16_t len)
{
    // 1. ׼�����ͻ����� (�Ĵ�����ַ+����)
    uint8_t buffer[len + 1];
    buffer[0] = reg;
    memcpy(&buffer[1], data, len);
    
    // 2. ��������
    DL_I2C_startControllerTransfer(I2C_0_INST, devAddr, 
        DL_I2C_CONTROLLER_DIRECTION_TX, len + 1);
    
    // 3. ���TX FIFO
    DL_I2C_fillControllerTXFIFO(I2C_0_INST, buffer, len + 1);
    
    // 4. �ȴ��������
    while(!(DL_I2C_getControllerStatus(I2C_0_INST) & 
           DL_I2C_CONTROLLER_STATUS_IDLE));
}

void I2C_Read(uint8_t devAddr, uint8_t reg, uint8_t *data, uint16_t len)
{
    // 1. ��д��Ĵ�����ַ
    DL_I2C_startControllerTransfer(I2C_0_INST, devAddr, 
        DL_I2C_CONTROLLER_DIRECTION_TX, 1);
    DL_I2C_transmitControllerData(I2C_0_INST, reg);
    
    // �ȴ��������
    while(!(DL_I2C_getControllerStatus(I2C_0_INST) & 
           DL_I2C_CONTROLLER_STATUS_IDLE));
    
    // 2. ������ȡ
    DL_I2C_startControllerTransfer(I2C_0_INST, devAddr, 
        DL_I2C_CONTROLLER_DIRECTION_RX, len);
    
    // 3. ��ȡ����
    for(uint16_t i = 0; i < len; i++) {
        while(DL_I2C_isControllerRXFIFOEmpty(I2C_0_INST))
        {
            uint32_t status = DL_I2C_getControllerStatus(I2C_0_INST);
            printf("status:%x\r\n",status);
            // uart_send_uint32(UART_0_INST, status);
            // uart_sendstr(UART_0_INST, "\r\n");
        }

        data[i] = DL_I2C_receiveControllerData(I2C_0_INST);
    }
}


