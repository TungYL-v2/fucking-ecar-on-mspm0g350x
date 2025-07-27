#include "ml_libs/headfile.h"


volatile uint8_t count;
volatile uint8_t data;

extern struct STEP_MOTOR step_motor_lr;
extern struct STEP_MOTOR step_motor_ud;

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

    // uart_init(UART_0_INST_INT_IRQN);
    // uart_init(UART_1_INST_INT_IRQN);
    // LSM6DSV16X_Init();
    // OLED_Init();

    // JY901S_Init();
    // Delay_us(100);
    // encoder_init();
    // motor_init();
    
    // pid_init(&motorA, DELTA_PID, 10, 12, 5);
    // pid_init(&motorB, DELTA_PID, 10, 12, 5);
    // pid_init(&angle, POSITION_PID, 5, 2, 2);


    // uart_init(UART_1_INST_INT_IRQN);
    
    tim_interrupt_ms_init(TIMER_0_INST_INT_IRQN, TIMER_0_INST, 0);
    
    volatile uint8_t  count = 0;

    delay_ms(500);
   
    volatile int flag = 0;
    //step_motor_lr.remain_steps = -500;
    // step_motor_ud.remain_steps = -500;
    while(1)
     {   
        // step_motor_ud.remain_steps = -500;
        // delay_ms(3000); 
        // step_motor_lr.remain_steps = -500;
        // delay_ms(3000); 

        if(DL_GPIO_readPins(STEP_KEY_L_PORT,STEP_KEY_L_PIN) == 0)
            step_motor_lr.remain_steps = -2;
        else if(DL_GPIO_readPins(STEP_KEY_R_PORT,STEP_KEY_R_PIN) == 0)
            step_motor_lr.remain_steps = 2;

        if(DL_GPIO_readPins(STEP_KEY_U_PORT,STEP_KEY_U_PIN) == 0)
            step_motor_ud.remain_steps = -2;
        else if(DL_GPIO_readPins(STEP_KEY_D_PORT,STEP_KEY_D_PIN) == 0)
            step_motor_ud.remain_steps = 2;
    }
    
    // for(int i=0;i<450;i++)
    // {
    //     // 
    //     //pid_control_line(35, 35);
    //     pid_control();
    //     delay_ms(15);
    // }
    // while(flag == 0)
    // {
    //     if(fabs(yaw_gyro-270)<2)
    //         {
    //             car_stop();
    //             flag = 1;
    //         }
    //     else
    //         {
    //             JY61P_GetData();
    //             pid_control_angle(270); 
    //             delay_ms(5);
    //         } 
    // }
    // while(1)
    // {   
    //     car_stop();
    // }

}


