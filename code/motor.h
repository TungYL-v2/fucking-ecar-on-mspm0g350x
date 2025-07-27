#ifndef _motor_h
#define _motor_h
#include "ml_libs/headfile.h"

#define motor_E1A_PORT motor_PORT
#define motor_E2A_PORT motor_PORT
#define motor_E1B_PORT motor_PORT
#define motor_E2B_PORT motor_PORT

#define motor_AIN1_PORT motor_PORT
#define motor_AIN2_PORT motor_PORT
#define motor_BIN1_PORT motor_PORT
#define motor_BIN2_PORT motor_PORT

void motor_init(void);
void motorA_duty(int duty);
void motorB_duty(int duty);
void encoder_init(void);
void motor_stop(void);

extern int Encoder_count1, Encoder_count2;
extern int speed_now;
volatile extern uint8_t motorA_dir, motorB_dir;

#endif
