#ifndef _pwm_h_
#define _pwm_h_
#include "headfile.h"

#define MAX_DUTY  50000


void pwm_update(GPTIMER_Regs *gptimer, DL_TIMER_CC_INDEX ccIndex, uint16_t duty);

#endif
