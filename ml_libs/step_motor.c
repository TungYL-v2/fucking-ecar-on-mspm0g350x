#include "step_motor.h"

// 驱动ULN2003步进电机驱动

//0号电机左右转动
volatile struct STEP_MOTOR step_motor_lr = {0, 0, 0};
//1号电机上下转动
volatile struct STEP_MOTOR step_motor_ud = {0,0, 1};
void step(struct STEP_MOTOR *step_motor, int8_t dir)
{
    if(step_motor->number==0)
    {
        step_motor->current_step += 4;
        step_motor->current_step += dir;
        step_motor->current_step %= 4;
        if(step_motor->current_step == 0)
        {
            DL_GPIO_setPins(STEP_MOTOR_LR_LR_IN1_PORT, STEP_MOTOR_LR_LR_IN1_PIN);
            DL_GPIO_setPins(STEP_MOTOR_LR_LR_IN2_PORT, STEP_MOTOR_LR_LR_IN2_PIN);
            DL_GPIO_clearPins(STEP_MOTOR_LR_LR_IN3_PORT, STEP_MOTOR_LR_LR_IN3_PIN);
            DL_GPIO_clearPins(STEP_MOTOR_LR_LR_IN4_PORT, STEP_MOTOR_LR_LR_IN4_PIN);
        }
        else if(step_motor->current_step == 1)
        {
            DL_GPIO_clearPins(STEP_MOTOR_LR_LR_IN1_PORT, STEP_MOTOR_LR_LR_IN1_PIN);
            DL_GPIO_setPins(STEP_MOTOR_LR_LR_IN2_PORT, STEP_MOTOR_LR_LR_IN2_PIN);
            DL_GPIO_setPins(STEP_MOTOR_LR_LR_IN3_PORT, STEP_MOTOR_LR_LR_IN3_PIN);
            DL_GPIO_clearPins(STEP_MOTOR_LR_LR_IN4_PORT, STEP_MOTOR_LR_LR_IN4_PIN);
        }
        else if(step_motor->current_step == 2)
        {
            DL_GPIO_clearPins(STEP_MOTOR_LR_LR_IN1_PORT, STEP_MOTOR_LR_LR_IN1_PIN);
            DL_GPIO_clearPins(STEP_MOTOR_LR_LR_IN2_PORT, STEP_MOTOR_LR_LR_IN2_PIN);
            DL_GPIO_setPins(STEP_MOTOR_LR_LR_IN3_PORT, STEP_MOTOR_LR_LR_IN3_PIN);
            DL_GPIO_setPins(STEP_MOTOR_LR_LR_IN4_PORT, STEP_MOTOR_LR_LR_IN4_PIN);
        }
        else if(step_motor->current_step == 3)
        {
            DL_GPIO_setPins(STEP_MOTOR_LR_LR_IN1_PORT, STEP_MOTOR_LR_LR_IN1_PIN);
            DL_GPIO_clearPins(STEP_MOTOR_LR_LR_IN2_PORT, STEP_MOTOR_LR_LR_IN2_PIN);
            DL_GPIO_clearPins(STEP_MOTOR_LR_LR_IN3_PORT, STEP_MOTOR_LR_LR_IN3_PIN);
            DL_GPIO_setPins(STEP_MOTOR_LR_LR_IN4_PORT, STEP_MOTOR_LR_LR_IN4_PIN);
        }
    }

    if(step_motor->number==1)
    {
        step_motor->current_step += 4;
        step_motor->current_step += dir;
        step_motor->current_step %= 4;
        if(step_motor->current_step == 0)
        {
            DL_GPIO_setPins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN1_PIN);
            DL_GPIO_setPins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN2_PIN);
            DL_GPIO_clearPins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN3_PIN);
            DL_GPIO_clearPins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN4_PIN);
        }
        else if(step_motor->current_step == 1)
        {
            DL_GPIO_clearPins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN1_PIN);
            DL_GPIO_setPins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN2_PIN);
            DL_GPIO_setPins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN3_PIN);
            DL_GPIO_clearPins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN4_PIN);
        }
        else if(step_motor->current_step == 2)
        {
            DL_GPIO_clearPins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN1_PIN);
            DL_GPIO_clearPins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN2_PIN);
            DL_GPIO_setPins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN3_PIN);
            DL_GPIO_setPins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN4_PIN);
        }
        else if(step_motor->current_step == 3)
        {
            DL_GPIO_setPins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN1_PIN);
            DL_GPIO_clearPins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN2_PIN);
            DL_GPIO_clearPins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN3_PIN);
            DL_GPIO_setPins(STEP_MOTOR_UD_PORT, STEP_MOTOR_UD_UD_IN4_PIN);
        }
    }
}

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

// 当前为lr电机与ud电机均平放，两电机同转，只接受x指令

// void UART1_rx_dataframe()
// {
//     rx_data = DL_UART_receiveData(UART_1_INST);
//     if(last_data == rx_data && rx_data == 0xAA)
//     {
//         pt = 2;
//         rx_order[0] = 0xAA;
//         rx_order[1] = 0xAA;
//     }
//     else if(last_data == rx_data && rx_data == 0xFF)
//     {
//         if(rx_order[2] + rx_order[3] + rx_order[4] + rx_order[5] == rx_order[6])
//         {
//             if(rx_order[2] == 0)
//             {
//                 if(rx_order[3] == 0)    //0是正转，1是反转
//                 {
//                     step_motor_lr.remain_steps = (uint32_t) rx_order[4] * 256 + (uint32_t) rx_order[5];
//                     step_motor_ud.remain_steps = step_motor_lr.remain_steps;
                    
//                 }
//                 if(rx_order[3] == 1)
//                 {
//                     step_motor_lr.remain_steps = -(uint32_t) rx_order[4] * 256 - (uint32_t) rx_order[5];
//                     step_motor_ud.remain_steps = step_motor_lr.remain_steps;
//                 }
//             }
//             // else if(rx_order[2] == 1)
//             // {
//             //     if(rx_order[3] == 0)
//             //     {
//             //         step_motor_ud.remain_steps = (uint32_t) rx_order[4] * 256 + (uint32_t) rx_order[5];

//             //     }
//             //     if(rx_order[3] == 1)
//             //     {
//             //         step_motor_ud.remain_steps = -(uint32_t) rx_order[4] * 256 - (uint32_t) rx_order[5];
//             //     }
//             // }
            
//         }
//     }
//     else 
//     {
//         rx_order[pt] = rx_data;
//         pt ++;
//         pt %= 9;
//     }
//     last_data = rx_data;

// }
