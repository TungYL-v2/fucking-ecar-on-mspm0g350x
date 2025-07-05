#include "mspm0_i2c.h"


void I2C_Init(void)
{
	SYSCFG_DL_I2C_0_init();
//    // 1. ʹ��I2C��Դ
//    DL_I2C_enablePower(I2C_0_INST);
//    
//    // 2. ����ʱ��Դ�ͷ�Ƶ
//    DL_I2C_ClockConfig clockConfig = {
//        .clockSel = DL_I2C_CLOCK_BUSCLK,  // ʹ��BUSCLK��Ϊʱ��Դ
//        .divideRatio = DL_I2C_CLOCK_DIVIDE_4  // 4��Ƶ
//    };
//    DL_I2C_setClockConfig(I2C_0_INST, &clockConfig);
//    
//    // 3. ����SCLʱ������ (��׼ģʽ100kHz)
//    DL_I2C_setTimerPeriod(I2C_0_INST, 0x13);  // ����ʵ��ʱ�Ӽ���
//    
//    // 4. ����I2C������
//    DL_I2C_enableController(I2C_0_INST);
//    
//    // 5. ����ʱ������(��ѡ)
//    DL_I2C_enableControllerClockStretching(I2C_0_INST);
}

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
        while(DL_I2C_isControllerRXFIFOEmpty(I2C_0_INST));
        data[i] = DL_I2C_receiveControllerData(I2C_0_INST);
    }
}


