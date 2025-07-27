#ifndef _CLOCK_H_
#define _CLOCK_H_

extern volatile unsigned long tick_ms;

int mspm0_delay_ms(unsigned long num_ms);
int delay_ms(unsigned long num_ms);
int delay_s(unsigned long num_s);
int mspm0_get_clock_ms(unsigned long *count);
void SysTick_Init(void);

#endif  /* #ifndef _CLOCK_H_ */