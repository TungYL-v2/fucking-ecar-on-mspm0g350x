#include "headfile.h"



//-------------------------------------------------------------------------------------------------------------------
// @brief		������ʱ���ж�
// @param	  gptimer		ѡ��ʱ��
// @param	  IRQn			��ʱ���ж������
// @param	  priority    	���ȼ�
// @return		void  
// Sample usage:	tim_interrupt_ms_init(TIMER_0_INST_INT_IRQN, TIMER_0_INST, 0);     
//-------------------------------------------------------------------------------------------------------------------
void tim_interrupt_ms_init(IRQn_Type IRQn, GPTIMER_Regs *gptimer, uint32_t priority)
{	
	
	NVIC_SetPriority(IRQn, priority);		//�������ȼ�
    NVIC_EnableIRQ(IRQn);					//ʹ�ܶ�ʱ���ж�
    DL_TimerG_startCounter(gptimer);	//������ʱ��
	
	//��ʱ��������sysconfig��TIMER��Desired Timer Period����
}



