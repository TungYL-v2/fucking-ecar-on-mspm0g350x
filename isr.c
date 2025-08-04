#include "ti_msp_dl_config.h" // Device header
#include "ml_libs/headfile.h"

volatile uint8_t rx_data;

//                                帧头(2)            编号         方向        转动的步(2)       校验     帧尾(2)
volatile uint8_t rx_order[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xFF, 0xFA};

volatile uint8_t last_data = 0x00;
volatile uint8_t pt = 0x00;

int straight = 0;
int if_stop;
int transformation = 0;
int if_black = 0;

// 以下为定时器中断服务函数
/*
 * Using __attribute__((interrupt, fully_populate_jump_tables)) in TI CLANG
 * compiler can eliminate non-deterministic control flow by using fully
 * populated jump tables to implement switch statements.
 *
 * NOTE: This attribute may negatively impact code size depending on the size
 * of the jump table
 */

// #if defined(__TI_COMPILER_VERSION__)
// __attribute__((interrupt, fully_populate_jump_tables))
// #endif
volatile uint8_t num = 0;
extern struct STEP_MOTOR step_motor_lr;
extern struct STEP_MOTOR step_motor_ud;

void TIMER_0_INST_IRQHandler(void)
{
    switch (DL_TimerG_getPendingInterrupt(TIMER_0_INST))
    {
    case DL_TIMERG_IIDX_ZERO:
        // 中断代码
        {   
            //step(&step_motor_ud,1);
            if(step_motor_lr.remain_steps > 0)
            {
                step(&step_motor_lr, 1);
                step_motor_lr.remain_steps --;
            }
            else if(step_motor_lr.remain_steps < 0)
            {
                step(&step_motor_lr, -1);
                step_motor_lr.remain_steps ++;
            }   

            if(step_motor_ud.remain_steps > 0)
            {
                step(&step_motor_ud, 1);
                step_motor_ud.remain_steps --;
            }
            else if(step_motor_ud.remain_steps < 0)
            {
                step(&step_motor_ud, -1);
                step_motor_ud.remain_steps ++;
            }   
            break;
        }
    case DL_TIMERG_IIDX_LOAD:
    case DL_TIMERG_IIDX_CC0_DN:
    case DL_TIMERG_IIDX_CC1_DN:
    case DL_TIMERG_IIDX_CC0_UP:
    case DL_TIMERG_IIDX_CC1_UP:
    case DL_TIMERG_IIDX_OVERFLOW:
    default:
        break;
    }
}

// #if defined(__TI_COMPILER_VERSION__)
// __attribute__((interrupt, fully_populate_jump_tables))
// #endif

// void TIMER_1_INST_IRQHandler(void)
// {
//     switch (DL_TimerG_getPendingInterrupt(TIMER_1_INST))
//     {
//     case DL_TIMERG_IIDX_ZERO:
//         // 中断代码

//         break;
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

// volatile uint8_t gEchoData = 0;

// 以下为串口中断服务函数
void UART1_rx_dataframe()
{
    rx_data = DL_UART_receiveData(UART_1_INST);
    if(last_data == rx_data && rx_data == 0xAA)
    {
        pt = 2;
        rx_order[0] = 0xAA;
        rx_order[1] = 0xAA;
    }
    else if(last_data == rx_data && rx_data == 0xFF)
    {
        if(rx_order[2] + rx_order[3] + rx_order[4] + rx_order[5] == rx_order[6])
        {
            if(rx_order[2] == 0)
            {
                if(rx_order[3] == 0)    //0是正转，1是反转
                {
                    step_motor_lr.remain_steps = (uint32_t) rx_order[4] * 256 + (uint32_t) rx_order[5];
                    step_motor_ud.remain_steps = step_motor_lr.remain_steps;
                    
                }
                if(rx_order[3] == 1)
                {
                    step_motor_lr.remain_steps = -(uint32_t) rx_order[4] * 256 - (uint32_t) rx_order[5];
                    step_motor_ud.remain_steps = step_motor_lr.remain_steps;
                }
            }
            // else if(rx_order[2] == 1)
            // {
            //     if(rx_order[3] == 0)
            //     {
            //         step_motor_ud.remain_steps = (uint32_t) rx_order[4] * 256 + (uint32_t) rx_order[5];

            //     }
            //     if(rx_order[3] == 1)
            //     {
            //         step_motor_ud.remain_steps = -(uint32_t) rx_order[4] * 256 - (uint32_t) rx_order[5];
            //     }
            // }
            
        }
    }
    else 
    {
        rx_order[pt] = rx_data;
        pt ++;
        pt %= 9;
    }
    last_data = rx_data;

}

void UART_0_INST_IRQHandler(void)
{
    switch (DL_UART_Main_getPendingInterrupt(UART_0_INST)) {
        case DL_UART_MAIN_IIDX_RX:
            // uart_sendbyte(UART_0_INST, gz);
            // UART0_rx_dataframe();
            // send_char(UART_0_INST, rx_data);
            DL_UART_clearInterruptStatus(UART_1_INST, DL_UART_MAIN_IIDX_RX);
            break;
        default:
            break;
    }
}

volatile uint8_t gEchoData = 0;

void UART_1_INST_IRQHandler(void)
{
    switch (DL_UART_Main_getPendingInterrupt(UART_1_INST)) 
    {
        case DL_UART_MAIN_IIDX_RX:
            UART1_rx_dataframe();
            DL_UART_clearInterruptStatus(UART_1_INST, DL_UART_MAIN_IIDX_RX);
            break;
        default:
            break;
    }
    
}


extern volatile uint8_t N_target;
////以下为外部中断服务函数
void GROUP1_IRQHandler(void)
{
    /*
     * Get the pending interrupt for the GPIOA port and store for
     * comparisons later
     */
    uint32_t gpioA = DL_GPIO_getEnabledInterruptStatus(motor_E1A_PORT, motor_E1A_PIN);
    uint32_t gpioB = DL_GPIO_getEnabledInterruptStatus(motor_E2A_PORT, motor_E2A_PIN);
    uint32_t gpioc = DL_GPIO_getEnabledInterruptStatus(STEP_KEY_QUAN_PORT, STEP_KEY_QUAN_PIN);

    /*
     * Bitwise AND the pending interrupt with the pin you want to check,
     * then check if it is equal to the pins. Clear the interrupt status.
     */


    if ((gpioA & motor_E1A_PIN) == motor_E1A_PIN)
    {
        if(gpio_get(motor_E1B_PORT, motor_E1B_PIN))
			Encoder_count1 --;
		else
			Encoder_count1 ++;
        DL_GPIO_clearInterruptStatus(motor_E1A_PORT, motor_E1A_PIN);
    }

    // else if ((gpioA & motor_E1B_PIN) == motor_E1B_PIN)
    // {
    //     if(gpio_get(motor_E1A_PORT, motor_E1A_PIN))
	// 		Encoder_count1 ++;
	// 	else
	// 		Encoder_count1 --;
    //     DL_GPIO_clearInterruptStatus(motor_E1A_PORT, motor_E1B_PIN);
    // }
    
    

    if ((gpioB & motor_E2A_PIN) == motor_E2A_PIN)
    {
        if(gpio_get(motor_E2B_PORT, motor_E2B_PIN))
			Encoder_count2 ++;
		else
			Encoder_count2 --;
        DL_GPIO_clearInterruptStatus(motor_E2A_PORT, motor_E2A_PIN);
    }

    if ((gpioc & STEP_KEY_QUAN_PIN) == STEP_KEY_QUAN_PIN)
    {
        if (!DL_GPIO_readPins(STEP_KEY_QUAN_PORT, STEP_KEY_QUAN_PIN)) 
        {
            N_target ++;
            if(N_target >= 5)
            {
                N_target = 5;
            }
        }
        DL_GPIO_clearInterruptStatus(motor_E1A_PORT, motor_E1A_PIN);
    }
    // else if ((gpioB & motor_E2B_PIN) == motor_E2B_PIN)
    // {
    //     if(gpio_get(motor_E2A_PORT, motor_E2A_PIN))
	// 		Encoder_count2 --;
	// 	else
	// 		Encoder_count2 ++;
    //     DL_GPIO_clearInterruptStatus(motor_E2A_PORT, motor_E2B_PIN);
    // }

    
}


// void EXTI2_IRQHandler(void) // PA2/PB2/PC2
//{
//	if(EXTI->PR&(1<<2))
//	{
//		//此处编写中断代码
//		if(gpio_get(GPIO_A, Pin_3))
//			Encoder_count1 --;
//		else
//			Encoder_count1 ++;
//

//		EXTI->PR = 1<<2; //清除标志位
//
//
//	}
//}
// void EXTI3_IRQHandler(void) // PA3/PB3/PC3
//{
//	if(EXTI->PR&(1<<3))
//	{
//		//此处编写中断代码
//
//		EXTI->PR = 1<<3; //清除标志位
//	}
//}

// void EXTI4_IRQHandler(void) // PA4/PB4/PC4
//{
//	if(EXTI->PR&(1<<4))
//	{
//		//此处编写中断代码
//		if(gpio_get(GPIO_A, Pin_5))
//			Encoder_count2 ++;
//		else
//			Encoder_count2 --;
//		EXTI->PR = 1<<4; //清除标志位
//	}
// }

// void EXTI9_5_IRQHandler(void)
//{
//	if(EXTI->PR&(1<<5))   //EXTI5  PA5/PB5/PC5
//	{
//		//此处编写中断代码

//		EXTI->PR = 1<<5; //清除标志位
//	}
//
//	if(EXTI->PR&(1<<6))   //EXTI6  PA6/PB6/PC6
//	{
//		//此处编写中断代码
//
//		EXTI->PR = 1<<6; //清除标志位
//	}
//
//	if(EXTI->PR&(1<<7))   //EXTI7  PA7/PB7/PC7
//	{
//		//此处编写中断代码
//
//
//		EXTI->PR = 1<<7; //清除标志位
//	}
//
//	if(EXTI->PR&(1<<8))   //EXTI8
//	{
//		//此处编写中断代码
//
//		EXTI->PR = 1<<8; //清除标志位
//	}
//
//	if(EXTI->PR&(1<<9))   //EXTI9
//	{
//		//此处编写中断代码
//
//		EXTI->PR = 1<<9; //清除标志位
//	}
//}
