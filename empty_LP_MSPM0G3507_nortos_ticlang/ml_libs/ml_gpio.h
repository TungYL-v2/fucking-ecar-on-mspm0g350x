// ml_gpio.h
#ifndef ML_GPIO_H
#define ML_GPIO_H

#include "ti_msp_dl_config.h"

typedef enum {
    ML_GPIO_MODE_INPUT,
    ML_GPIO_MODE_OUTPUT_PP,  // 推挽输出
    ML_GPIO_MODE_OUTPUT_OD,  // 开漏输出
    ML_GPIO_MODE_AF_PP,      // 复用推挽
    ML_GPIO_MODE_AF_OD,      // 复用开漏
    ML_GPIO_MODE_ANALOG,
    ML_GPIO_MODE_IT_RISING,  // 中断上升沿触发
    ML_GPIO_MODE_IT_FALLING, // 中断下降沿触发
    ML_GPIO_MODE_IT_BOTH     // 中断双边沿触发
} ML_GPIO_Mode;

// 设置引脚电平
void gpio_set(GPIO_Regs* gpio, uint32_t pins, uint8_t mode);

// 读取引脚电平
uint32_t gpio_get(GPIO_Regs* gpio, uint32_t pins);

// 切换引脚电平
void gpio_toggle(GPIO_Regs* gpio, uint32_t pins);

#endif // ML_GPIO_H
