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
//             motor_target_set(525,525);      
//         }
//         else if((DD4 == 0)&&(DD5 != 0))   //1110 1111
//         {
//             motor_target_set(515,525);       
//         }
//         else if((DD4 != 0)&&(DD5 == 0))   //1111 0111
//         {
//             motor_target_set(525,515);       
//         }
//         else if((DD3 != 0)&&(DD4 == 0))   //1100 1111
//         {
//             motor_target_set(508,520);        
//         }
//         else if((DD5 == 0)&&(DD6 == 0))   //1111 0011
//         {
//             motor_target_set(520,500);        
//         }
//         else if((DD3 == 0)&&(DD4 != 0))   //1101 1111
//         {
//             motor_target_set(500,520);        
//         }
//         else if((DD5 != 0)&&(DD6 == 0))   //1111 1011
//         {
//             motor_target_set(520,500);        
//         }
//         else if((DD2 == 0)&&(DD3 == 0))   //1001 1111
//         {
//             motor_target_set(440,550);        
//         }
//         else if((DD6 == 0)&&(DD7 == 0))   //1111 1001
//         {
//             motor_target_set(550,440);        
//         }
//         else if((DD2 == 0)&&(DD3 != 0))   //1011 1111
//         {
//             motor_target_set(430,570);        
//         }
//         else if((DD6 != 0)&&(DD7 == 0))  //1111 1101
//         {
//             motor_target_set(570,430);         
//         }
//         else if((DD1 == 0)&&(DD2 == 0))   //0011 1111
//         {
//             motor_target_set(380,580);         
//         }
//         else if((DD7 == 0)&&(DD8 == 0))   //1111 1100
//         {
//             motor_target_set(600,330);        
//         }
//         else if((DD1 == 0)&&(DD2 != 0))   //0111 1111
//         {
//             motor_target_set(350,570);         
//         }    
//         else if((DD7 !=0)&&(DD8 == 0))    //1111 1110
//         {
//             motor_target_set(570,90);         
//         }
//         else                            //1111 1111
//         {
//             motor_target_set(525,525);        
//         }
// }

// void track()                        //1234 5678
// {
//         if((DD4 == 0)&&(DD5 == 0))        //1110 0111
//         {
//             motor_target_set(200,200);      
//         }
//         else if((DD4 == 0)&&(DD5 != 0))   //1110 1111
//         {
//             motor_target_set(196,200);       
//         }
//         else if((DD4 != 0)&&(DD5 == 0))   //1111 0111
//         {
//             motor_target_set(200,196);       
//         }
//         else if((DD3 != 0)&&(DD4 == 0))   //1100 1111
//         {
//             motor_target_set(193,198);        
//         }
//         else if((DD5 == 0)&&(DD6 == 0))   //1111 0011
//         {
//             motor_target_set(198,190);        
//         }
//         else if((DD3 == 0)&&(DD4 != 0))   //1101 1111
//         {
//             motor_target_set(190,198);        
//         }
//         else if((DD5 != 0)&&(DD6 == 0))   //1111 1011
//         {
//             motor_target_set(198,190);        
//         }
//         else if((DD2 == 0)&&(DD3 == 0))   //1001 1111
//         {
//             motor_target_set(168,209);        
//         }
//         else if((DD6 == 0)&&(DD7 == 0))   //1111 1001
//         {
//             motor_target_set(209,168);        
//         }
//         else if((DD2 == 0)&&(DD3 != 0))   //1011 1111
//         {
//             motor_target_set(164,217);        
//         }
//         else if((DD6 != 0)&&(DD7 == 0))  //1111 1101
//         {
//             motor_target_set(217,164);         
//         }
//         else if((DD1 == 0)&&(DD2 == 0))   //0011 1111
//         {
//             motor_target_set(145,221);         
//         }
//         else if((DD7 == 0)&&(DD8 == 0))   //1111 1100
//         {
//             motor_target_set(229,126);        
//         }
//         else if((DD1 == 0)&&(DD2 != 0))   //0111 1111
//         {
//             motor_target_set(133,217);         
//         }    
//         else if((DD7 !=0)&&(DD8 == 0))    //1111 1110
//         {
//             motor_target_set(217,34);         
//         }
//         else                            //1111 1111
//         {
//             motor_target_set(200,200);        
//         }
// }
void track()                        //1234 5678
{
        if((DD5 == 1)&&(DD4 == 1))        //0001 1000
        {
            motor_target_set(374,374);      
        }
        else if((DD5 != 1)&&(DD4 == 1))   //0000 1000
        {
            motor_target_set(374,370);       
        }
        else if((DD5 == 1)&&(DD4 != 1))   //0001 0000
        {
            motor_target_set(370,374);       
        }
        else if((DD4 == 1)&&(DD3 == 1))   //0000 1100
        {
            motor_target_set(375,355);        
        }
        else if((DD6 == 1)&&(DD5 == 1))   //0011 0000
        {
            motor_target_set(325,390);        
        }
        else if((DD4 == !1)&&(DD3 == 1))   //0000 0100
        {
            motor_target_set(375,355);        
        }
        else if((DD6 == 1)&&(DD5 != 1))   //0010 0000
        {
            motor_target_set(335,395);        
        }
        else if((DD3 == 1)&&(DD2 == 1))   //0000 0110
        {
            motor_target_set(391,314);        
        }
        else if((DD7 == 1)&&(DD6 == 1))   //0110 0000
        {
            motor_target_set(314,391);        
        }
        else if((DD3 != 1)&&(DD2 == 1))   //0000 0010
        {
            motor_target_set(406,307);        
        }
        else if((DD7 == 1)&&(DD6 != 1))  //0100 0000
        {
            motor_target_set(280,406);      
        }
        else if((DD2 == 1)&&(DD1 == 1))   //0000 0011
        {
            motor_target_set(413,272);         
        }
        else if((DD8 == 1)&&(DD7 == 1))   //1100 0000
        {
            motor_target_set(236,445);        
        }
        else if((DD2 != 1)&&(DD1 == 1))   //0000 0001
        {
            motor_target_set(390,74);         
        }    
        else if((DD8 == 1)&&(DD7 !=1))    //1000 0000
        {
            motor_target_set(74,390);         
        }
        else                            //1111 1111
        {
            motor_target_set(374,374);        
        }
}

// void track()                        //1234 5678
// {
//         if((DD4 == 0)&&(DD5 == 0))        //1110 0111
//         {
//             motor_target_set(525,525);      
//         }
//         else if((DD4 == 0)&&(DD5 != 0))   //1110 1111
//         {
//             motor_target_set(515,525);       
//         }
//         else if((DD4 != 0)&&(DD5 == 0))   //1111 0111
//         {
//             motor_target_set(525,515);       
//         }
//         else if((DD3 != 0)&&(DD4 == 0))   //1100 1111
//         {
//             motor_target_set(508,520);        
//         }
//         else if((DD5 == 0)&&(DD6 == 0))   //1111 0011
//         {
//             motor_target_set(520,500);        
//         }
//         else if((DD3 == 0)&&(DD4 != 0))   //1101 1111
//         {
//             motor_target_set(500,520);        
//         }
//         else if((DD5 != 0)&&(DD6 == 0))   //1111 1011
//         {
//             motor_target_set(520,500);        
//         }
//         else if((DD2 == 0)&&(DD3 == 0))   //1001 1111
//         {
//             motor_target_set(440,550);        
//         }
//         else if((DD6 == 0)&&(DD7 == 0))   //1111 1001
//         {
//             motor_target_set(550,440);        
//         }
//         else if((DD2 == 0)&&(DD3 != 0))   //1011 1111
//         {
//             motor_target_set(430,570);        
//         }
//         else if((DD6 != 0)&&(DD7 == 0))  //1111 1101
//         {
//             motor_target_set(570,430);         
//         }
//         else if((DD1 == 0)&&(DD2 == 0))   //0011 1111
//         {
//             motor_target_set(380,580);         
//         }
//         else if((DD7 == 0)&&(DD8 == 0))   //1111 1100
//         {
//             motor_target_set(600,330);        
//         }
//         else if((DD1 == 0)&&(DD2 != 0))   //0111 1111
//         {
//             motor_target_set(350,570);         
//         }    
//         else if((DD7 !=0)&&(DD8 == 0))    //1111 1110
//         {
//             motor_target_set(570,90);         
//         }
//         else                            //1111 1111
//         {
//             motor_target_set(525,525);        
//         }
// }

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

