#include "task.h"

void car_stop()
{
    // gpio_set(motor_PORT,motor_AIN1_PIN,1);
    // gpio_set(motor_PORT,motor_AIN2_PIN,1);
    // gpio_set(motor_PORT,motor_BIN1_PIN,1);
    // gpio_set(motor_PORT,motor_BIN2_PIN,1);
    motorA_duty(0);
    motorB_duty(0);
}

volatile uint8_t N_target = 1;
void task_1()
{   
    volatile uint8_t flag;
    volatile uint8_t N_now;
    N_now = 1;
    while(N_now <= N_target)
    {   
        flag = 0;
        while(flag == 0)   
        {
            pid_control();
            delay_ms(15); 
            
            if(DD8 && DD7)        //DD1在黑色区域，表示到路口
            {
                car_stop();
                flag = 1;
            }         
        }

        if(flag == 1)
        {
           for(int i=0;i<50;i++)
           {
                pid_control_line(50,210);
                delay_ms(15);
           }
           flag = 2;
        }

        while(flag == 2)
        {
            pid_control_line(50,210);
            delay_ms(15);
            if(DD6)
            {
                car_stop();
                flag = 3;
            }
        }

        for(int i=0;i<60;i++)
        {
            pid_control();
            delay_ms(15);
        }

        while(flag == 3)   
        {
            pid_control();
            delay_ms(15); 
            
            if(DD8 && DD7)        //DD1在黑色区域，表示没到路口
            {
                car_stop();
                flag = 4;
            }         
        }

        if(flag == 4)
        {
           for(int i=0;i<50;i++)
           {
                pid_control_line(50,210);
                delay_ms(15);
           }
           flag = 5;
        }

        
        while(flag == 5)
        {
            pid_control_line(50,210);
            delay_ms(15);
            if(DD6)
            {
                car_stop();
                flag = 6;
            }
        }

        for(int i=0;i<60;i++)
        {
            pid_control();
            delay_ms(15);
        }

        while(flag == 6)   
        {
            pid_control();
            delay_ms(15); 
            
            if(DD8 && DD7)        //DD1在黑色区域，表示没到路口
            {
                car_stop();
                flag = 7;
            }         
        }

        if(flag == 7)
        {
           for(int i=0;i<50;i++)
           {
                pid_control_line(50,210);
                delay_ms(15);
           }
           flag = 8;
        }

        
        while(flag == 8)
        {
            pid_control_line(50,210);
            delay_ms(15);
            if(DD6)
            {
                car_stop();
                flag = 9;
            }
        }

        for(int i=0;i<60;i++)
        {
            pid_control();
            delay_ms(15);
        }

        while(flag == 9)   
        {
            pid_control();
            delay_ms(15); 
            
            if(DD8 && DD7)        //DD1在黑色区域，表示到路口
            {
                car_stop();
                flag = 10;
            }         
        }

        if(flag == 10)
        {
           for(int i=0;i<50;i++)
           {
                pid_control_line(50,210);
                delay_ms(15);
           }
           flag = 11;
        }        
        
        while(flag ==11 )
        {
            pid_control_line(50,210);
            delay_ms(15);
            if(DD6)
            {
                car_stop();
                flag = 12;
            }
        }

        if(flag == 12)
        {
            car_stop();
            N_now = N_now + 1;
        }
    }
}