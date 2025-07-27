#include "ml_libs/headfile.h"


uint8_t count;
uint8_t data;

char txbuf[100];

uint8_t det_medicine(void)
{
	if (gpio_get(far_red_PORT,  far_red_PIN_2_PIN) != 0)
		return 0;
	else 
		return 1;		
}

void car_stop()
{
	gpio_set(motor_PORT,motor_AIN1_PIN,1);
	gpio_set(motor_PORT,motor_AIN2_PIN,1);
	gpio_set(motor_PORT,motor_BIN1_PIN,1);
	gpio_set(motor_PORT,motor_BIN2_PIN,1);
	motorA_duty(0);
	motorB_duty(0);
}

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
    
    pid_init(&motorA, DELTA_PID, 15, 18, 20);
    pid_init(&motorB, DELTA_PID, 15, 18, 20);
	pid_init(&angle, POSITION_PID, 2, 0, 1);

    uart_init(UART_0_INST_INT_IRQN);
    uart_init(UART_1_INST_INT_IRQN);
    
    tim_interrupt_ms_init(TIMER_0_INST_INT_IRQN, TIMER_0_INST, 0);
    
    volatile uint8_t  count = 0;
    // motor_target_set(50, 50);

    // pwm_update(PWM_motor_INST,DL_TIMER_CC_0_INDEX,2000); 
    //DL_Timer_setCaptureCompareValue(PWM_motor_INST, 32000, DL_TIMER_CC_0_INDEX);
    delay_ms(1000);
    // while (1) 
	// {
    //     //  pid_control_angle(90);
    // //     pid_control_line(300,300);
    //     delay_ms(10);
    //     JY61P_GetData();
    // }
    volatile int flag = 0;
    // motorA_duty(20000);
    // motorB_duty(20000);
    // delay_ms(300);
    for(int i=0;i<450;i++)
    {
        // 
        //pid_control_line(35, 35);
        pid_control();
        delay_ms(10);
    }
    while(flag == 0)
    {
        if(fabs(yaw_gyro-270)<2)
            {
                car_stop();
                flag = 1;
            }
        else
            {
                JY61P_GetData();
                pid_control_angle(270); 
                delay_ms(5);
            } 
    }
    while(1)
    {   
        car_stop();
    }


    
    // if(flag == 0)
    // {
    //     for(int i= 0 ;i<50;i++)
    //     {
    //        pid_control();
    //         delay_ms(100);
    //     }
    //     flag = 1;
    // }
    // car_stop();
    // while(flag==1)
    // {
    //     ;
    // }

}


