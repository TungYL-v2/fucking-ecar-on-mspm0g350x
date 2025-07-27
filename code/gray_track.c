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
        if((DD4 == 0)&&(DD5 == 0))        //1110 0111
        {
            motor_target_set(25,25);
        }
        else if((DD4 == 0)&&(DD5 != 0))   //1110 1111
        {
            motor_target_set(24,25);
        }
        else if((DD4 != 0)&&(DD5 == 0))   //1111 0111
        {
            motor_target_set(25,24);  
        }
        else if((DD3 != 0)&&(DD4 == 0))   //1100 1111
        {
            motor_target_set(24,25);
        }
        else if((DD5 == 0)&&(DD6 == 0))   //1111 0011
        {
            motor_target_set(25,24);
        }
        else if((DD3 == 0)&&(DD4 != 0))   //1101 1111
        {
            motor_target_set(24,26);
        }
        else if((DD5 != 0)&&(DD6 == 0))   //1111 1011
        {
            motor_target_set(26,24);
        }
        else if((DD2 == 0)&&(DD3 == 0))   //1001 1111
        {
            motor_target_set(23,27);
        }
        else if((DD6 == 0)&&(DD7 == 0))   //1111 1001
        {
            motor_target_set(27,23);
        }
        else if((DD2 == 0)&&(DD3 != 0))   //1011 1111
        {
            motor_target_set(23,28);
        }
        else if((DD6 != 0)&&(DD7 == 0))   //1111 1101
        {
            motor_target_set(28,23);
        }
        else if((DD1 == 0)&&(DD2 == 0))   //0011 1111
        {
            motor_target_set(20,29);
        }
        else if((DD7 == 0)&&(DD8 == 0))   //1111 1100
        {
            motor_target_set(29,20);
        }
        else if((DD1 == 0)&&(DD2 != 0))   //0111 1111
        {
            motor_target_set(6,32);
        }    
        else if((DD7 !=0)&&(DD8 == 0))    //1111 1110
        {
            motor_target_set(32,6);
        }
        else                            //1111 1111
        {
            motor_target_set(25,25);
        }
}

// void track() {
//     if ((DD4 == 0) && (DD5 == 0)) {         // 居中
//         motor_target_set(200, 200);
//     } else if ((DD4 == 0) && (DD5 == 1)) {  // 轻微右偏
//         motor_target_set(195, 200);
//     } else if ((DD4 == 1) && (DD5 == 0)) {  // 轻微左偏
//         motor_target_set(200, 195);
//     } else if ((DD3 == 0) && (DD4 == 1)) {  // 中度右偏
//         motor_target_set(180, 200);
//     } else if ((DD5 == 1) && (DD6 == 0)) {  // 中度左偏
//         motor_target_set(200, 180);
//     } else if ((DD2 == 0) && (DD3 == 1)) {  // 严重右偏
//         motor_target_set(125, 190);
//     } else if ((DD6 == 1) && (DD7 == 0)) {  // 严重左偏
//         motor_target_set(190, 125);
//     } else if ((DD1 == 0) && (DD2 == 1)) {  // 极右偏
//         motor_target_set(90, 165);
//     } else if ((DD7 == 1) && (DD8 == 0)) {  // 极左偏
//         motor_target_set(165, 90);
//     } else {                                // 其他情况（如脱线）
//         motor_target_set(200, 200);             // 停转或自定义搜索逻辑
//     }
// }

// void track() {								//计算速度代码放在定时器里
//     if ((DD4 == 0) && (DD5 == 0)) {         // 居中
//         motor_target_set(35, 35);            // 40→35 (-5)
//     } else if ((DD4 == 0) && (DD5 == 1)) {  // 轻微右偏
//         motor_target_set(35, 35);            // 40→35 (-5)
//     } else if ((DD4 == 1) && (DD5 == 0)) {  // 轻微左偏
//         motor_target_set(35, 35);            // 40→35 (-5)
//     } else if ((DD3 == 0) && (DD4 == 1)) {  // 中度右偏
//         motor_target_set(34, 35);            // 39→34 (-5), 40→35 (-5)
//     } else if ((DD5 == 1) && (DD6 == 0)) {  // 中度左偏
//         motor_target_set(35, 34);            // 40→35 (-5), 39→34 (-5)
//     } else if ((DD2 == 0) && (DD3 == 1)) {  // 严重右偏
//         motor_target_set(25, 37);            // 30→25 (-5), 42→37 (-5)
//     } else if ((DD6 == 1) && (DD7 == 0)) {  // 严重左偏
//         motor_target_set(37, 25);            // 42→37 (-5), 30→25 (-5)
//     } else if ((DD1 == 0) && (DD2 == 1)) {  // 极右偏
//         motor_target_set(17, 40);            // 22→17 (-5), 45→40 (-5)
//     } else if ((DD7 == 1) && (DD8 == 0)) {  // 极左偏
//         motor_target_set(40, 17);            // 45→40 (-5), 22→17 (-5)
//     } else {                                // 其他情况（如脱线）
//         motor_target_set(40, 40);            // 40→35 (-5)
//     }
// }

// void track() {									//计算速度代码放在pid里
//     if ((DD4 == 0) && (DD5 == 0)) {         // 居中
//         motor_target_set(35, 35);            // 40→35 (-5)
//     } else if ((DD4 == 0) && (DD5 == 1)) {  // 轻微右偏
//         motor_target_set(35, 35);            // 40→35 (-5
//     } else if ((DD4 == 1) && (DD5 == 0)) {  // 轻微左偏
//         motor_target_set(35, 35);            // 40→35 (-5
//     } else if ((DD3 == 0) && (DD4 == 1)) {  // 中度右偏
//         motor_target_set(33, 35);            // 39→34 (-5), 40→35 (-5)
//     } else if ((DD5 == 1) && (DD6 == 0)) {  // 中度左偏
//         motor_target_set(35, 33);            // 40→35 (-5), 39→34 (-5)
//     } else if ((DD2 == 0) && (DD3 == 1)) {  // 严重右偏
//         motor_target_set(34, 37);            // 30→25 (-5), 42→37 (-5)
//     } else if ((DD6 == 1) && (DD7 == 0)) {  // 严重左偏
//         motor_target_set(37, 34);            // 42→37 (-5), 30→25 (-5)
//     } else if ((DD1 == 0) && (DD2 == 1)) {  // 极右偏
//         motor_target_set(17, 40);            // 22→17 (-5), 45→40 (-5)
//     } else if ((DD7 == 1) && (DD8 == 0)) {  // 极左偏
//         motor_target_set(40, 17);            // 45→40 (-5), 22→17 (-5)
//     } else {                                // 其他情况（如脱线）
//         motor_target_set(35, 35);            // 40→35 (-5)
//     }
// }

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

