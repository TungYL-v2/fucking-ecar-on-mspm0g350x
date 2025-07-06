#include "headfile.h"


//sysconfig 设定 gPWM_motorConfig.period = 32500
const float DUTY_SCALE = 32500 / MAX_DUTY;

//-------------------------------------------------------------------------------------------------------------------
// @brief		PWM占空比更新
// @param	  gptimer		选择定时器
// @param	  ccIndex		选择定时器通道
// @param	  duty    		更新功率
// @return		void  
// Sample usage:	pwm_update(PWM_motor_INST,DL_TIMER_CC_0_INDEX,0);     
//-------------------------------------------------------------------------------------------------------------------
void pwm_update(GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex, uint16_t duty)
{
	uint32_t value = 32500 - duty * DUTY_SCALE;			//32500 - 32500 * (duty/50000)
	DL_Timer_setCaptureCompareValue(gptimer, value, ccIndex);
//	DL_TimerA_setCaptureCompareValue(PWM_motor_INST, 62, DL_TIMER_CC_0_INDEX);
}


