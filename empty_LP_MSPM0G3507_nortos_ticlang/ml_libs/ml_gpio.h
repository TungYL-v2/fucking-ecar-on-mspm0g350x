// ml_gpio.h
#ifndef ML_GPIO_H
#define ML_GPIO_H

#include "ti_msp_dl_config.h"

typedef enum {
    ML_GPIO_MODE_INPUT,
    ML_GPIO_MODE_OUTPUT_PP,  // �������
    ML_GPIO_MODE_OUTPUT_OD,  // ��©���
    ML_GPIO_MODE_AF_PP,      // ��������
    ML_GPIO_MODE_AF_OD,      // ���ÿ�©
    ML_GPIO_MODE_ANALOG,
    ML_GPIO_MODE_IT_RISING,  // �ж������ش���
    ML_GPIO_MODE_IT_FALLING, // �ж��½��ش���
    ML_GPIO_MODE_IT_BOTH     // �ж�˫���ش���
} ML_GPIO_Mode;

// �������ŵ�ƽ
void gpio_set(GPIO_Regs* gpio, uint32_t pins, uint8_t mode);

// ��ȡ���ŵ�ƽ
uint32_t gpio_get(GPIO_Regs* gpio, uint32_t pins);

// �л����ŵ�ƽ
void gpio_toggle(GPIO_Regs* gpio, uint32_t pins);

#endif // ML_GPIO_H
