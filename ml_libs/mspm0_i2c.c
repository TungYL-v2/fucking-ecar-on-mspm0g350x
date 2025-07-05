#include "mspm0_i2c.h"


void I2C_Init(void)
{
	SYSCFG_DL_I2C_0_init();
//    // 1. 使能I2C电源
//    DL_I2C_enablePower(I2C_0_INST);
//    
//    // 2. 配置时钟源和分频
//    DL_I2C_ClockConfig clockConfig = {
//        .clockSel = DL_I2C_CLOCK_BUSCLK,  // 使用BUSCLK作为时钟源
//        .divideRatio = DL_I2C_CLOCK_DIVIDE_4  // 4分频
//    };
//    DL_I2C_setClockConfig(I2C_0_INST, &clockConfig);
//    
//    // 3. 配置SCL时钟周期 (标准模式100kHz)
//    DL_I2C_setTimerPeriod(I2C_0_INST, 0x13);  // 根据实际时钟计算
//    
//    // 4. 启用I2C控制器
//    DL_I2C_enableController(I2C_0_INST);
//    
//    // 5. 启用时钟拉伸(可选)
//    DL_I2C_enableControllerClockStretching(I2C_0_INST);
}

void I2C_Write(uint8_t devAddr, uint8_t reg, uint8_t *data, uint16_t len)
{
    // 1. 准备发送缓冲区 (寄存器地址+数据)
    uint8_t buffer[len + 1];
    buffer[0] = reg;
    memcpy(&buffer[1], data, len);
    
    // 2. 启动传输
    DL_I2C_startControllerTransfer(I2C_0_INST, devAddr, 
        DL_I2C_CONTROLLER_DIRECTION_TX, len + 1);
    
    // 3. 填充TX FIFO
    DL_I2C_fillControllerTXFIFO(I2C_0_INST, buffer, len + 1);
    
    // 4. 等待传输完成
    while(!(DL_I2C_getControllerStatus(I2C_0_INST) & 
           DL_I2C_CONTROLLER_STATUS_IDLE));
}

void I2C_Read(uint8_t devAddr, uint8_t reg, uint8_t *data, uint16_t len)
{
    // 1. 先写入寄存器地址
    DL_I2C_startControllerTransfer(I2C_0_INST, devAddr, 
        DL_I2C_CONTROLLER_DIRECTION_TX, 1);
    DL_I2C_transmitControllerData(I2C_0_INST, reg);
    
    // 等待传输完成
    while(!(DL_I2C_getControllerStatus(I2C_0_INST) & 
           DL_I2C_CONTROLLER_STATUS_IDLE));
    
    // 2. 启动读取
    DL_I2C_startControllerTransfer(I2C_0_INST, devAddr, 
        DL_I2C_CONTROLLER_DIRECTION_RX, len);
    
    // 3. 读取数据
    for(uint16_t i = 0; i < len; i++) {
        while(DL_I2C_isControllerRXFIFOEmpty(I2C_0_INST));
        data[i] = DL_I2C_receiveControllerData(I2C_0_INST);
    }
}


