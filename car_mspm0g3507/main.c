#include "ml_libs/headfile.h"


uint8_t count;
uint8_t data;

char txbuf[100];

int main(void) 
{

    SysTick_Init();
    SYSCFG_DL_init();
    // LSM6DSV16X_Init();
    // OLED_Init();
    JY901S_Init();
    Delay_us(100);
    encoder_init();
    motor_init();
    
    pid_init(&motorA, DELTA_PID, 10, 15, 5);
	pid_init(&motorB, DELTA_PID, 10, 15, 5);
	pid_init(&angle, POSITION_PID, 2, 0, 1);

    uart_init(UART_0_INST_INT_IRQN);
    uart_init(UART_1_INST_INT_IRQN);
    
    tim_interrupt_ms_init(TIMER_0_INST_INT_IRQN, TIMER_0_INST, 0);
    
    volatile uint8_t  count = 0;
    // motor_target_set(50, 50);

    // pwm_update(PWM_motor_INST,DL_TIMER_CC_0_INDEX,2000); 
    //DL_Timer_setCaptureCompareValue(PWM_motor_INST, 32000, DL_TIMER_CC_0_INDEX);
    delay_ms(500);
    while (1) 
	{
        // pid_control_line(40,40);
        // pid_control_angle(90);
        // pid_control();
         delay_ms(100);
        //OLED_ShowChar(5, 5, '6', 8);
        // data = LSM6DSV16X_Read(LSM6DSV16X_WHO_AM_I);
        // uint8_t data_h, data_l;
        // data_h = LSM6DSV16X_Read(LSM6DSV16X_OUTZ_H_G);
        // data_l = LSM6DSV16X_Read(LSM6DSV16X_OUTZ_L_G);
        // gz = (data_h << 8) | data_l;
        // delay_ms(200);
        // count++;.
        printf("red:%d\r\n",gpio_get(far_red_PORT,  GPIO_scl_PIN_1_PIN));
        JY61P_GetData();
        printf("yaw_gyro:%.1f\r\n",yaw_gyro);
        // printf("read:%d\r\n",JY901S_Read(JY901_REG_YAW));
        // uart_sendbyte(UART_0_INST, gz);     
    }


}


