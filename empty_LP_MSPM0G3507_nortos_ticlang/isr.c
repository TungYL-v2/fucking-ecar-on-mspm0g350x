#include "ti_msp_dl_config.h" // Device header
#include "ml_libs/headfile.h"

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

#if defined(__TI_COMPILER_VERSION__)
__attribute__((interrupt, fully_populate_jump_tables))
#endif
void TIMER_0_INST_IRQHandler(void)
{
    switch (DL_TimerG_getPendingInterrupt(TIMER_0_INST))
    {
    case DL_TIMERG_IIDX_ZERO:
        // 中断代码

        break;
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

#if defined(__TI_COMPILER_VERSION__)
__attribute__((interrupt, fully_populate_jump_tables))
#endif

void TIMER_1_INST_IRQHandler(void)
{
    switch (DL_TimerG_getPendingInterrupt(TIMER_1_INST))
    {
    case DL_TIMERG_IIDX_ZERO:
        // 中断代码

        break;
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

volatile uint8_t gEchoData = 0;

// 以下为串口中断服务函数
// void UART_0_INST_IRQHandler(void)
// {
//     switch (DL_UART_Main_getPendingInterrupt(UART_0_INST)) {
//         case DL_UART_MAIN_IIDX_RX:
//             gEchoData = DL_UART_Main_receiveData(UART_0_INST);
//             DL_UART_Main_transmitData(UART_0_INST, gEchoData);
//             break;
//         default:
//             break;
//     }
// }



////以下为外部中断服务函数
void GROUP1_IRQHandler(void)
{
    /*
     * Get the pending interrupt for the GPIOA port and store for
     * comparisons later
     */
    uint32_t gpioA = DL_GPIO_getEnabledInterruptStatus(GPIOA, motor_E1A_PIN | motor_E2A_PIN);

    /*
     * Bitwise AND the pending interrupt with the pin you want to check,
     * then check if it is equal to the pins. Clear the interrupt status.
     */
    if ((gpioA & motor_E1A_PIN) != 0)
    {
        if(gpio_get(motor_E1B_PORT, motor_E1B_PIN))
			Encoder_count1 --;
		else
			Encoder_count1 ++;
    }

    if ((gpioA & motor_E2A_PIN) != 0)
    {
        if(gpio_get(motor_E2B_PORT, motor_E2B_PIN))
			Encoder_count2 --;
		else
			Encoder_count2 ++;
    }

    /* Repeat with GPIOB Port */
//    uint32_t gpioB = DL_GPIO_getEnabledInterruptStatus(
//        GPIOB, GPIO_SWITCHES_USER_SWITCH_2_PIN);

//    if ((gpioB & GPIO_SWITCHES_USER_SWITCH_2_PIN) ==
//        GPIO_SWITCHES_USER_SWITCH_2_PIN)
//    {
//        DL_GPIO_togglePins(
//            GPIO_LEDS_USER_LED_2_PORT, GPIO_LEDS_USER_LED_2_PIN);
//        DL_GPIO_clearInterruptStatus(GPIOB, GPIO_SWITCHES_USER_SWITCH_2_PIN);
//    }
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
