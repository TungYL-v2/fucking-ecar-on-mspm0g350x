#include "headfile.h"

const float DUTY_SCALE = 125 / MAX_DUTY;

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
	uint32_t value = duty * DUTY_SCALE;
	DL_TimerA_setCaptureCompareValue(gptimer, value, ccIndex);
//	DL_TimerA_setCaptureCompareValue(PWM_motor_INST, 62, DL_TIMER_CC_0_INDEX);
}


