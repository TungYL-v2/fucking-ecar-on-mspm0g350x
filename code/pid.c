#include "pid.h"

pid_t motorA;
pid_t motorB;
pid_t angle;
//float yaw_gyro;

// void datavision_send()  // 上位机波形发送函数
// {
// 	// 数据包头
// 	uart_sendbyte(UART_1, 0x03);
// 	uart_sendbyte(UART_1, 0xfc);

// 	// 发送数据
// 	uart_sendbyte(UART_1, (uint8_t)motorA.target);  
// 	uart_sendbyte(UART_1, (uint8_t)motorA.now);
// //	uart_sendbyte(UART_1, (uint8_t)motorB.target);  
// //	uart_sendbyte(UART_1, (uint8_t)motorB.now);
// 	// 数据包尾
// 	uart_sendbyte(UART_1, 0xfc);
// 	uart_sendbyte(UART_1, 0x03);
// }


void pid_init(pid_t *pid, uint32_t mode, float p, float i, float d)
{
	pid->pid_mode = mode;
	pid->p = p;
	pid->i = i;
	pid->d = d;
}

void motor_target_set(uint16_t spe1, uint16_t spe2)
{

	if(spe1 >= 0)
	{
		motorA_dir = 1;
		motorA.target = spe1;
	}
	else
	{
		motorA_dir = 0;
		motorA.target = -spe1;
	}
	
	if(spe2 >= 0)
	{
		motorB_dir = 1;
		motorB.target = spe2;
	}
	else
	{
		motorB_dir = 0;
		motorB.target = -spe2;
	}
}


void pid_control_line(uint16_t spe1,uint16_t spe2)
{
	if(spe1 >= 0)
	{
		motorA_dir = 1;
		motorA.target = spe1;
	}
	else
	{
		motorA_dir = 0;
		motorA.target = -spe1;
	}
	
	if(spe2 >= 0)
	{
		motorB_dir = 1;
		motorB.target = spe2;
	}
	else
	{
		motorB_dir = 0;
		motorB.target = -spe2;
	}
	if(motorA_dir){motorA.now = Encoder_count1;}else{motorA.now = -Encoder_count1;}
	if(motorB_dir){motorB.now = Encoder_count2;}else{motorB.now = -Encoder_count2;}
	Encoder_count1 = 0;
	Encoder_count2 = 0;
	// 电机状态输入pid控制器(传入结构体地址)
	pid_cal(&motorA);
	pid_cal(&motorB);
	// 电机输出限幅
	pidout_limit(&motorA);
	pidout_limit(&motorB);
	// 输入PID输出值
	motorA_duty(motorA.out);
	motorB_duty(motorB.out);
	
	//datavision_send();
}

void pid_control()
{
	// 灰度传感器调节速度
	track();

	if(motorA_dir){motorA.now = Encoder_count1;}else{motorA.now = -Encoder_count1;}
	if(motorB_dir){motorB.now = Encoder_count2;}else{motorB.now = -Encoder_count2;}
	Encoder_count1 = 0;
	Encoder_count2 = 0;

	pid_cal(&motorA);
	pid_cal(&motorB);

	pidout_limit(&motorA);
	pidout_limit(&motorB);

	motorA_duty(motorA.out);
	motorB_duty(motorB.out);
	
	//datavision_send();
}

void pid_control_angle(int ang)
{

	// 设定目标角度
    angle.target = ang;
	// 传入当前角度
    angle.now = yaw_gyro;
	// 传入PID控制器
    pid_cal(&angle);
    // motor_target_set(-angle.out, angle.out);
	if(angle.out >= 0)
	{
		motorA_dir = 0;
		motorA.target =angle.out;
		motorB_dir = 1;
		motorB.target = angle.out;
	}
	else
	{
		motorA_dir = 1;
		motorA.target = -angle.out;
		motorB_dir = 0;
		motorB.target = -angle.out;
	}

    if(motorA_dir){motorA.now = Encoder_count1;}else{motorA.now = -Encoder_count1;}
    if(motorB_dir){motorB.now = Encoder_count2;}else{motorB.now = -Encoder_count2;}
    Encoder_count1 = 0;
    Encoder_count2 = 0;

    pid_cal(&motorA);
    pid_cal(&motorB);
    // 限幅
//    pidout_limit(&motorA);
//    pidout_limit(&motorB);
    pidout_limit_angle(&motorA);
    pidout_limit_angle(&motorB);
    // 4.PID结果反馈给电机
    motorA_duty(motorA.out);
    motorB_duty(motorB.out);
    
    //datavision_send();
}



void pid_cal(pid_t *pid)
{
	// 计算当前误差，存入error[0]
	pid->error[0] = pid->target - pid->now;

	// 计算输出
	if(pid->pid_mode == DELTA_PID)  // 增量式
	{
		pid->pout = pid->p * (pid->error[0] - pid->error[1]);
		pid->iout = pid->i * pid->error[0];
		pid->dout = pid->d * (pid->error[0] - 2 * pid->error[1] + pid->error[2]);
		pid->out += pid->pout + pid->iout + pid->dout;
	}
	else if(pid->pid_mode == POSITION_PID)  // 位置式
	{
		pid->pout = pid->p * pid->error[0];
		pid->iout += pid->i * pid->error[0];
		pid->dout = pid->d * (pid->error[0] - pid->error[1]);
		pid->out = pid->pout + pid->iout + pid->dout;
	}

	// 记录前两次偏差
	pid->error[2] = pid->error[1];
	pid->error[1] = pid->error[0];

	// 输出限幅
//	if(pid->out>=MAX_DUTY)	
//		pid->out=MAX_DUTY;
//	if(pid->out<=0)	
//		pid->out=0;
	
}

void pidout_limit(pid_t *pid)
{
	// 输出限幅
	if(pid->out>=MAX_DUTY)	
		pid->out=MAX_DUTY;
	if(pid->out<=0)	
		pid->out=0;
}

void pidout_limit_angle(pid_t *pid)
{
	// 输出限幅
	if(pid->out>=13000)	
		pid->out=13000;
	if(pid->out<=0)	
		pid->out=0;
}
