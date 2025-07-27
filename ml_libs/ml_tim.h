#ifndef _ml_tim_h_
#define _ml_tim_h_

#include "ti_msp_dl_config.h"


void tim_interrupt_ms_init(IRQn_Type IRQn, GPTIMER_Regs *gptimer, uint32_t priority);

#endif
