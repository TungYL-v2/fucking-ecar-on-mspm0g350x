#include "ti_msp_dl_config.h"

void Delay(unsigned int ms) {
    for (volatile unsigned int i = 0; i < ms * 1000; i++);
}

int main(void) {
    SYSCFG_DL_init();

    DL_GPIO_initDigitalOutput(GPIO_GRP_0_LED1_IOMUX); 
    DL_GPIO_initDigitalInput(GPIO_GRP_0_KEY1_IOMUX);  

    DL_GPIO_clearPins(GPIO_GRP_0_LED1_PORT, GPIO_GRP_0_LED1_PIN);

    bool last_button_state = false;  
    bool current_button_state;       

    while (1) {
        current_button_state = (DL_GPIO_readPins(GPIO_GRP_0_KEY1_PORT, GPIO_GRP_0_KEY1_PIN) != 0);

        if (current_button_state != last_button_state) {
            Delay(20); 
            
            current_button_state = (DL_GPIO_readPins(GPIO_GRP_0_KEY1_PORT, GPIO_GRP_0_KEY1_PIN) != 0);

            if (current_button_state != last_button_state) {
                if (current_button_state) {
                    DL_GPIO_togglePins(GPIO_GRP_0_LED1_PORT, GPIO_GRP_0_LED1_PIN);
                }
                last_button_state = current_button_state;
            }
        } else {
            last_button_state = current_button_state;
        }
    }
}


