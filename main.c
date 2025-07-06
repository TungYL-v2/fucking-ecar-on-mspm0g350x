#include "headfile.h"





int main(void) {
	SYSCFG_DL_init();
	SYSCFG_DL_initPower();
	SYSCFG_DL_GPIO_init();
	SYSCFG_DL_SYSCTL_init();
	SYSCFG_DL_PWM_motor_init();
	SYSCFG_DL_TIMER_0_init();
	SYSCFG_DL_TIMER_1_init();
	SYSCFG_DL_I2C_0_init();


    bool last_button_state = false;  
    bool current_button_state;       

    while (1) 
	{
        
    }
}


