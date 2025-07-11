#include "gray_track.h"

//void gray_init()
//{
//	gpio_init(GPIO_B, Pin_12, IU);   // D1
//	gpio_init(GPIO_B, Pin_13, IU);   // D2
//	gpio_init(GPIO_B, Pin_14, IU);   // D3
//	gpio_init(GPIO_B, Pin_15, IU);   // D4
//	gpio_init(GPIO_A, Pin_8 , IU);   // D5
//	gpio_init(GPIO_C, Pin_13, IU);   // D6
//	gpio_init(GPIO_C, Pin_14, IU);   // D7
//	gpio_init(GPIO_C, Pin_15, IU);   // D8
//}

void track()                        //1234 5678
{
        if((D4 == 0)&&(D5 == 0))        //1110 0111
        {
            motor_target_set(225,225);
        }
        else if((D4 == 0)&&(D5 != 0))   //1110 1111
        {
            motor_target_set(150,180);
        }
        else if((D4 != 0)&&(D5 == 0))   //1111 0111
        {
            motor_target_set(180,150);  
        }
        else if((D3 != 0)&&(D4 == 0))   //1100 1111
        {
            motor_target_set(135,195);
        }
        else if((D5 == 0)&&(D6 == 0))   //1111 0011
        {
            motor_target_set(195,135);
        }
        else if((D3 == 0)&&(D4 != 0))   //1101 1111
        {
            motor_target_set(135,195);
        }
        else if((D5 != 0)&&(D6 == 0))   //1111 1011
        {
            motor_target_set(195,135);
        }
        else if((D2 == 0)&&(D3 == 0))   //1001 1111
        {
            motor_target_set(120,225);
        }
        else if((D6 == 0)&&(D7 == 0))   //1111 1001
        {
            motor_target_set(225,120);
        }
        else if((D2 == 0)&&(D3 != 0))   //1011 1111
        {
            motor_target_set(120,225);
        }
        else if((D6 != 0)&&(D7 == 0))   //1111 1101
        {
            motor_target_set(225,120);
        }
        else if((D1 == 0)&&(D2 == 0))   //0011 1111
        {
            motor_target_set(90,300);
        }
        else if((D7 == 0)&&(D8 == 0))   //1111 1100
        {
            motor_target_set(300,90);
        }
        else if((D1 == 0)&&(D2 != 0))   //0111 1111
        {
            motor_target_set(60,300);
        }    
        else if((D7 !=0)&&(D8 == 0))    //1111 1110
        {
            motor_target_set(330,60);
        }
        else                            //1111 1111
        {
            motor_target_set(225,225);
        }
}

unsigned char digtal(unsigned char channel)//1-8	  获取X通道数字值
{
	uint8_t value = 0;
	switch(channel) 
	{
		case 1:  
			if(gpio_get(track_PIN_1_PORT, track_PIN_1_PIN) == 1) value = 1;
			else value = 0;  
			break;  
		case 2: 
			if(gpio_get(track_PIN_2_PORT, track_PIN_2_PIN) == 1) value = 1;
			else value = 0;  
			break;  
		case 3: 
			if(gpio_get(track_PIN_3_PORT, track_PIN_3_PIN) == 1) value = 1;
			else value = 0;  
			break;   
		case 4:  
			if(gpio_get(track_PIN_4_PORT, track_PIN_4_PIN) == 1) value = 1;
			else value = 0;  
			break;   
		case 5:
			if(gpio_get(track_PIN_5_PORT, track_PIN_5_PIN) == 1) value = 1;
			else value = 0;  
			break;
		case 6:  
			if(gpio_get(track_PIN_6_PORT, track_PIN_6_PIN) == 1) value = 1;
			else value = 0;  
			break;  
		case 7: 
			if(gpio_get(track_PIN_7_PORT, track_PIN_7_PIN) == 1) value = 1;
			else value = 0;  
			break;  
 		case 8: 
 			if(gpio_get(track_PIN_8_PORT, track_PIN_8_PIN) == 1) value = 1;
 			else value = 0;  
 			break;   
	}
	return value; 
}

