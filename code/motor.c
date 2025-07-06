#include "motor.h"

#define MOTOR_AIN1_PIN Pin_6	//PA6
#define MOTOR_AIN2_PIN Pin_7	//PA7
#define MOTOR_BIN1_PIN Pin_0	//PB0
#define MOTOR_BIN2_PIN Pin_1	//PB1

uint8_t motorA_dir = 1; // 1为正转 0为反转
uint8_t motorB_dir = 1;

int Encoder_count1 = 0;
int Encoder_count2 = 0;

int speed_now;


void motor_init()
{
	//启动PWM计时器
	DL_TimerG_startCounter(PWM_motor_INST);
	
	//pwm_init(TIM_2,TIM2_CH1,1000);   //电机1
	//pwm_init(TIM_2,TIM2_CH2,1000);   //电机2
}

//-------------------------------------------------------------------------------------------------------------------
// @brief		控制转速
// @param	  duty	  pwm占比，max50000
// @return		void  
//-------------------------------------------------------------------------------------------------------------------
void motorA_duty(int duty)   //MOTOR_LEFT
{ 
	pwm_update(PWM_motor_INST,DL_TIMER_CC_0_INDEX,duty);  
	gpio_set(motor_AIN1_PORT,motor_AIN1_PIN,motorA_dir);
	gpio_set(motor_AIN2_PORT,motor_AIN2_PIN,!motorA_dir);
}

void motorB_duty(int duty)   //MOTOR_RIGHT
{
	pwm_update(PWM_motor_INST,DL_TIMER_CC_1_INDEX,duty);  
	gpio_set(motor_BIN1_PORT,motor_BIN1_PIN,motorB_dir);
	gpio_set(motor_BIN2_PORT,motor_BIN2_PIN,!motorB_dir);
}

void motor_stop(void)
{
	gpio_set(motor_AIN1_PORT,motor_AIN1_PIN,1);
	gpio_set(motor_AIN2_PORT,motor_AIN2_PIN,1);
	gpio_set(motor_BIN1_PORT,motor_BIN1_PIN,1);
	gpio_set(motor_BIN2_PORT,motor_BIN2_PIN,1);
}
// 编码器IO初始化
 void encoder_init()
 {
 	NVIC_EnableIRQ(motor_INT_IRQN);  

 }
