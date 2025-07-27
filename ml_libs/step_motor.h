#ifndef STEP_MOTOR_H_
#define STEP_MOTOR_H_

#include "ti_msp_dl_config.h"
#include "./ml_libs/clock.h"

struct STEP_MOTOR
{
    //当前步
    volatile uint8_t current_step;

    //剩余步
    volatile int remain_steps;

    //电机编号
    volatile uint8_t number;
};

void step(struct STEP_MOTOR *step_motor, int8_t dir);

#endif
