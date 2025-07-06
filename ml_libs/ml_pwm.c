#include "headfile.h"


//sysconfig �趨 gPWM_motorConfig.period = 32500
const float DUTY_SCALE = 32500 / MAX_DUTY;

//-------------------------------------------------------------------------------------------------------------------
// @brief		PWMռ�ձȸ���
// @param	  gptimer		ѡ��ʱ��
// @param	  ccIndex		ѡ��ʱ��ͨ��
// @param	  duty    		���¹���
// @return		void  
// Sample usage:	pwm_update(PWM_motor_INST,DL_TIMER_CC_0_INDEX,0);     
//-------------------------------------------------------------------------------------------------------------------
void pwm_update(GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex, uint16_t duty)
{
	uint32_t value = 32500 - duty * DUTY_SCALE;			//32500 - 32500 * (duty/50000)
	DL_Timer_setCaptureCompareValue(gptimer, value, ccIndex);
//	DL_TimerA_setCaptureCompareValue(PWM_motor_INST, 62, DL_TIMER_CC_0_INDEX);
}


