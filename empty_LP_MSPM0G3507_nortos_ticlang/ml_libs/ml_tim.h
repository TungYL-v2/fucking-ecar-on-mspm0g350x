#ifndef _tim_h_
#define _tim_h_

#include "headfile.h"


void tim_interrupt_ms_init(IRQn_Type IRQn, GPTIMER_Regs *gptimer, uint32_t priority);

#endif
