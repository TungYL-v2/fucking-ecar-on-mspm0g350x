#include "ml_gpio.h"



uint32_t gpio_get(GPIO_Regs* gpio, uint32_t pins)
{
    return (gpio->DIN31_0 & pins);
}

void gpio_set(GPIO_Regs* gpio, uint32_t pins, uint8_t mode)
{
    if(mode)
		gpio->DOUTSET31_0 = pins;
	else
		gpio->DOUTCLR31_0 = pins;
}

void gpio_toggle(GPIO_Regs* gpio, uint32_t pins)
{
	gpio->DOUTTGL31_0 = pins;
}

