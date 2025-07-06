#include "headfile.h"



//-------------------------------------------------------------------------------------------------------------------
// @brief		启动定时器中断
// @param	  gptimer		选择定时器
// @param	  IRQn			定时器中断请求号
// @param	  priority    	优先级
// @return		void  
// Sample usage:	tim_interrupt_ms_init(TIMER_0_INST_INT_IRQN, TIMER_0_INST, 0);     
//-------------------------------------------------------------------------------------------------------------------
void tim_interrupt_ms_init(IRQn_Type IRQn, GPTIMER_Regs *gptimer, uint32_t priority)
{	
	
	NVIC_SetPriority(IRQn, priority);		//设置优先级
    NVIC_EnableIRQ(IRQn);					//使能定时器中断
    DL_TimerG_startCounter(gptimer);	//开启定时器
	
	//定时器周期在sysconfig里TIMER的Desired Timer Period设置
}



