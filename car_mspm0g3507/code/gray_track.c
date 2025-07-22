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

// void track()                        //1234 5678
// {
//         if((DD4 == 0)&&(DD5 == 0))        //1110 0111
//         {
//             motor_target_set(14,14);
//         }
//         else if((DD4 == 0)&&(DD5 != 0))   //1110 1111
//         {
//             motor_target_set(12,22);
//         }
//         else if((DD4 != 0)&&(DD5 == 0))   //1111 0111
//         {
//             motor_target_set(17,12);  
//         }
//         else if((DD3 != 0)&&(DD4 == 0))   //1100 1111
//         {
//             motor_target_set(13,24);
//         }
//         else if((DD5 == 0)&&(DD6 == 0))   //1111 0011
//         {
//             motor_target_set(18,13);
//         }
//         else if((DD3 == 0)&&(DD4 != 0))   //1101 1111
//         {
//             motor_target_set(13,24);
//         }
//         else if((DD5 != 0)&&(DD6 == 0))   //1111 1011
//         {
//             motor_target_set(18,13);
//         }
//         else if((DD2 == 0)&&(DD3 == 0))   //1001 1111
//         {
//             motor_target_set(14,27);
//         }
//         else if((DD6 == 0)&&(DD7 == 0))   //1111 1001
//         {
//             motor_target_set(20,14);
//         }
//         else if((DD2 == 0)&&(DD3 != 0))   //1011 1111
//         {
//             motor_target_set(14,25);
//         }
//         else if((DD6 != 0)&&(DD7 == 0))   //1111 1101
//         {
//             motor_target_set(20,14);
//         }
//         else if((DD1 == 0)&&(DD2 == 0))   //0011 1111
//         {
//             motor_target_set(10,25);
//         }
//         else if((DD7 == 0)&&(DD8 == 0))   //1111 1100
//         {
//             motor_target_set(22,10);
//         }
//         else if((DD1 == 0)&&(DD2 != 0))   //0111 1111
//         {
//             motor_target_set(7,25);
//         }    
//         else if((DD7 !=0)&&(DD8 == 0))    //1111 1110
//         {
//             motor_target_set(25,7);
//         }
//         else                            //1111 1111
//         {
//             motor_target_set(14,14);
//         }
// }


void track()                        //1234 5678
{
        if((DD4 == 0)&&(DD5 == 0))        //1110 0111
        {
            motor_target_set(14.00,14.00);      
        }
        else if((DD4 == 0)&&(DD5 != 0))   //1110 1111
        {
            motor_target_set(13.73,14.00);       
        }
        else if((DD4 != 0)&&(DD5 == 0))   //1111 0111
        {
            motor_target_set(14.00,13.73);       
        }
        else if((DD3 != 0)&&(DD4 == 0))   //1100 1111
        {
            motor_target_set(13.53,13.87);        
        }
        else if((DD5 == 0)&&(DD6 == 0))   //1111 0011
        {
            motor_target_set(13.87,13.33);        
        }
        else if((DD3 == 0)&&(DD4 != 0))   //1101 1111
        {
            motor_target_set(13.33,13.87);        
        }
        else if((DD5 != 0)&&(DD6 == 0))   //1111 1011
        {
            motor_target_set(13.87,13.33);        
        }
        else if((DD2 == 0)&&(DD3 == 0))   //1001 1111
        {
            motor_target_set(11.73,14.67);        
        }
        else if((DD6 == 0)&&(DD7 == 0))   //1111 1001
        {
            motor_target_set(14.00,11.73);        
        }
        else if((DD2 == 0)&&(DD3 != 0))   //1011 1111
        {
            motor_target_set(11.47,15.20);        
        }
        else if((DD6 != 0)&&(DD7 == 0))  //1111 1101
        {
            motor_target_set(15.20,11.47);         
        }
        else if((DD1 == 0)&&(DD2 == 0))   //0011 1111
        {
            motor_target_set(10.13,15.47);         
        }
        else if((DD7 == 0)&&(DD8 == 0))   //1111 1100
        {
            motor_target_set(16.00,8.80);        
        }
        else if((DD1 == 0)&&(DD2 != 0))   //0111 1111
        {
            motor_target_set(9.33,15.20);         
        }    
        else if((DD7 !=0)&&(DD8 == 0))    //1111 1110
        {
            motor_target_set(15.20,2.40);         
        }
        else                            //1111 1111
        {
            motor_target_set(14.00,14.00);        
        }
}


unsigned char digtal(unsigned char channel)//1-8	  ��ȡXͨ������ֵ
{
	uint8_t value = 0;
	switch(channel) 
	{
		case 1:  
			if(gpio_get(GRAY_D1_PORT, GRAY_D1_PIN) ) value = 1;
			else value = 0;  
			break;  
		case 2: 
			if(gpio_get(GRAY_D2_PORT, GRAY_D2_PIN) ) value = 1;
			else value = 0;  
			break;  
		case 3: 
			if(gpio_get(GRAY_D3_PORT, GRAY_D3_PIN) ) value = 1;
			else value = 0;  
			break;   
		case 4:  
			if(gpio_get(GRAY_D4_PORT, GRAY_D4_PIN) ) value = 1;
			else value = 0;  
			break;   
		case 5:
			if(gpio_get(GRAY_D5_PORT, GRAY_D5_PIN) ) value = 1;
			else value = 0;  
			break;
		case 6:  
			if(gpio_get(GRAY_D6_PORT, GRAY_D6_PIN) ) value = 1;
			else value = 0;  
			break;  
		case 7: 
			if(gpio_get(GRAY_D7_PORT, GRAY_D7_PIN) ) value = 1;
			else value = 0;  
			break;  
 		case 8: 
 			if(gpio_get(GRAY_D8_PORT, GRAY_D8_PIN) ) value = 1;
 			else value = 0;  
 			break;   
	}
	return value; 
}

