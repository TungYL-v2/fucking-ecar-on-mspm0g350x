#include "ti_msp_dl_config.h"
#include "clock.h"

volatile unsigned long tick_ms;
volatile uint32_t start_time;

int delay_ms(unsigned long num_ms)
{
    while(num_ms--)
    delay_cycles(CPUCLK_FREQ/1000);
    return 0;
}


int delay_s(unsigned long num_s)
{
    while(num_s--)
    delay_cycles(CPUCLK_FREQ);
    return  0;
}


int mspm0_delay_ms(unsigned long num_ms)
{
    start_time = tick_ms;
    while (tick_ms - start_time < num_ms);
    return 0;
}


int mspm0_get_clock_ms(unsigned long *count)
{
    if (!count)
        return 1;
    count[0] = tick_ms;
    return 0;
}

void SysTick_Init(void)
{
    DL_SYSTICK_config(CPUCLK_FREQ/1000);
    NVIC_SetPriority(SysTick_IRQn, 1);
}



void SysTick_Handler(void) {
    tick_ms++;  // 每 1ms 自动递增
}

