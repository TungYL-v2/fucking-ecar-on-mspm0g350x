#include "42step_motor.h"


// 该模块无法与"step_motor.h/c"共存
// 对应脉冲驱动的42步进电机，中断中检测remain_step并执行step()
// step()检测dir并输出一次脉冲

//0号电机左右转动
volatile struct STEP_MOTOR step_motor_lr = {0, 0, 0};
//1号电机上下转动
volatile struct STEP_MOTOR step_motor_ud = {0,0, 1};
void step(struct STEP_MOTOR *step_motor, int8_t dir)
{
    switch (step_motor -> number) 
    {
        // in1 --> en
        // in2 --> step
        // in3 --> dir
        case 0:
        if(dir == 1)
            DL_GPIO_setPins(STEP_MOTOR_LR_LR_IN3_PORT, STEP_MOTOR_LR_LR_IN3_PIN);
        else
            DL_GPIO_clearPins(STEP_MOTOR_LR_LR_IN3_PORT, STEP_MOTOR_LR_LR_IN3_PIN);

        DL_GPIO_togglePins(STEP_MOTOR_LR_LR_IN2_PORT, STEP_MOTOR_LR_LR_IN2_PIN);
        delay_ms(1);
        DL_GPIO_togglePins(STEP_MOTOR_LR_LR_IN2_PORT, STEP_MOTOR_LR_LR_IN2_PIN);
        break;
        case 1:
        if(dir == 1)
            DL_GPIO_setPins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN1_PIN);
        else
            DL_GPIO_clearPins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN1_PIN);

        DL_GPIO_togglePins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN2_PIN);
        delay_ms(1);
        DL_GPIO_togglePins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN2_PIN);
        break;
        default:
        break;
    
    }
}


// 对应定时器中断如下
// void TIMER_0_INST_IRQHandler(void)
// {
//     switch (DL_TimerG_getPendingInterrupt(TIMER_0_INST))
//     {
//     case DL_TIMERG_IIDX_ZERO:
//         // 中断代码
//         {   
//             //step(&step_motor_ud,1);
//             if(step_motor_lr.remain_steps > 0)
//             {
//                 step(&step_motor_lr, 1);
//                 step_motor_lr.remain_steps --;
//             }
//             else if(step_motor_lr.remain_steps < 0)
//             {
//                 step(&step_motor_lr, -1);
//                 step_motor_lr.remain_steps ++;
//             }   

//             if(step_motor_ud.remain_steps > 0)
//             {
//                 step(&step_motor_ud, 1);
//                 step_motor_ud.remain_steps --;
//             }
//             else if(step_motor_ud.remain_steps < 0)
//             {
//                 step(&step_motor_ud, -1);
//                 step_motor_ud.remain_steps ++;
//             }   
//             break;
//         }
//     case DL_TIMERG_IIDX_LOAD:
//     case DL_TIMERG_IIDX_CC0_DN:
//     case DL_TIMERG_IIDX_CC1_DN:
//     case DL_TIMERG_IIDX_CC0_UP:
//     case DL_TIMERG_IIDX_CC1_UP:
//     case DL_TIMERG_IIDX_OVERFLOW:
//     default:
//         break;
//     }
// }
