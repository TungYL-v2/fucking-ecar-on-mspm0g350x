#include "ml_libs/headfile.h"


volatile uint8_t count;
volatile uint8_t data;
volatile uint8_t D1,D2,D3,D4,D5,D6,D7,D8;


extern struct STEP_MOTOR step_motor_lr;
extern struct STEP_MOTOR step_motor_ud;
// volatile bool buttonPressed = false;
// volatile uint8_t N_target = 1;
int main(void) 
{

    SysTick_Init();
    SYSCFG_DL_init();

    // uart_init(UART_0_INST_INT_IRQN);
    // uart_init(UART_1_INST_INT_IRQN);
    // LSM6DSV16X_Init();
    // OLED_Init();

    // JY901S_Init();
    Delay_us(100);
    encoder_init();
    motor_init();
    
    pid_init(&motorA, DELTA_PID, 12, 12, 5);
    pid_init(&motorB, DELTA_PID, 12, 12, 5);
    // pid_init(&angle, POSITION_PID, 5, 2, 2);


    // uart_init(UART_1_INST_INT_IRQN);
    
    tim_interrupt_ms_init(TIMER_0_INST_INT_IRQN, TIMER_0_INST, 0);

    delay_ms(500);

    //step_motor_lr.remain_steps = -500;
    // step_motor_ud.remain_steps = -500

    // motorA_duty(20000);
    // motorB_duty(20000);
    // step_motor_lr.remain_steps = 1000;
    // step_motor_ud.remain_steps = -500;

    while(DL_GPIO_readPins(STEP_KEY_START_PORT, STEP_KEY_START_PIN))
    {
        ;
    }

    delay_ms(1000);
    
   task_1();

    while(1)
     {  
        // pid_control();
        // delay_ms(15);
        car_stop();
        // D1 = digtal(1);
        // D2 = digtal(2);
        // D3 = digtal(3);
        // D4 = digtal(4);
        // D5 = digtal(5);
        // D6 = digtal(6);
        // D7 = digtal(7);
        // D8 = digtal(8);
        // delay_ms(10);
        // if(DL_GPIO_readPins(STEP_KEY_L_PORT,STEP_KEY_L_PIN) == 0)
        //     step_motor_lr.remain_steps = 4;
        // else if(DL_GPIO_readPins(STEP_KEY_R_PORT,STEP_KEY_R_PIN) == 0)
        //     step_motor_lr.remain_steps = 4;

        // if(DL_GPIO_readPins(STEP_KEY_U_PORT,STEP_KEY_U_PIN) == 0)
        //     step_motor_ud.remain_steps = -4;
        // else if(DL_GPIO_readPins(STEP_KEY_D_PORT,STEP_KEY_D_PIN) == 0)
        //     step_motor_ud.remain_steps = 4;
    }
    
}


