#include "ml_libs/headfile.h"


uint8_t count;
uint8_t data;
volatile uint8_t gEchoData = 0;
char txbuf[100];

int main(void) {
    SysTick_Init();
    SYSCFG_DL_init();
    LSM6DSV16X_Init();
    OLED_Init();

    uart_init(UART_0_INST_INT_IRQN);
    uart_init(UART_1_INST_INT_IRQN);
    

    while (1) 
	{
        //OLED_ShowChar(5, 5, '6', 8);
        // data = LSM6DSV16X_Read(LSM6DSV16X_WHO_AM_I);
        uint8_t data_h, data_l;
        data_h = LSM6DSV16X_Read(LSM6DSV16X_OUTZ_H_G);
        data_l = LSM6DSV16X_Read(LSM6DSV16X_OUTZ_L_G);
        gz = (data_h << 8) | data_l;
        delay_ms(200);
        count++;
        // printf("gz:%d/r/n",gz);
        // uart_sendbyte(UART_0_INST, gz);
            
    }
}


void UART_0_INST_IRQHandler(void)
{
    switch (DL_UART_Main_getPendingInterrupt(UART_0_INST)) {
        case DL_UART_MAIN_IIDX_RX:
            // uart_sendbyte(UART_0_INST, gz);
            
            break;
        default:
            break;
    }
}



void UART_1_INST_IRQHandler(void)
{
    switch (DL_UART_Main_getPendingInterrupt(UART_1_INST)) 
    {
        case DL_UART_MAIN_IIDX_RX:
            gEchoData = DL_UART_receiveDataBlocking(UART_1_INST);
            //sprintf(txbuf,"%c\r\n", gEchoData);
            //DL_UART_Main_transmitDataBlocking(UART_0_INST, gEchoData);
            switch (gEchoData) 
            {
                case 'l':
                    printf("turn left\r\n");
                    break;
                case 'r':
                    printf("turn right\r\n");
                    break;
                default:
                    break;
            }
            
            // uart_sendbyte(UART_0_INST,gEchoData);
            OLED_ShowChar(5, 5, gEchoData, 8);
            break;
        default:
            break;
    }
}

void SysTick_Handler(void) {
    tick_ms++;  // 每 1ms 自动递增
}

