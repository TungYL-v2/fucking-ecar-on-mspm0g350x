#include "pid.h"

pid_t motorA;
pid_t motorB;
pid_t angle;
//float yaw_gyro;

//void datavision_send()  // ��λ�����η��ͺ���
//{
//	// ���ݰ�ͷ
//	uart_sendbyte(UART_1, 0x03);
//	uart_sendbyte(UART_1, 0xfc);

//	// ��������
//	uart_sendbyte(UART_1, (uint8_t)motorA.target);  
//	uart_sendbyte(UART_1, (uint8_t)motorA.now);
////	uart_sendbyte(UART_1, (uint8_t)motorB.target);  
////	uart_sendbyte(UART_1, (uint8_t)motorB.now);
//	// ���ݰ�β
//	uart_sendbyte(UART_1, 0xfc);
//	uart_sendbyte(UART_1, 0x03);
//}


void pid_init(pid_t *pid, uint32_t mode, float p, float i, float d)
{
	pid->pid_mode = mode;
	pid->p = p;
	pid->i = i;
	pid->d = d;
}

void motor_target_set(float_t spe1, float_t spe2)
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


void pid_control_line(float_t spe1,float_t spe2)
{
	motor_target_set(spe1,spe2);
	// if(motorA_dir){motorA.now = Encoder_count1;}else{motorA.now = -Encoder_count1;}
	// if(motorB_dir){motorB.now = Encoder_count2;}else{motorB.now = -Encoder_count2;}
	// Encoder_count1 = 0;
	// Encoder_count2 = 0;
	// 3.����PID���������м���
	pid_cal(&motorA);
	pid_cal(&motorB);
	// �������޷�
	pidout_limit(&motorA);
	pidout_limit(&motorB);
	// 4.PID�����ֵ ��������
	motorA_duty(motorA.out);
	motorB_duty(motorB.out);
	
	//datavision_send();
}

void pid_control()
{
	// �ٶȻ�
	// 1.���ݻҶȴ�������Ϣ �趨Ŀ���ٶ�
	track();
	// 2.��ȡ��ǰ�ٶ�
	// if(motorA_dir){motorA.now = Encoder_count1;}else{motorA.now = -Encoder_count1;}
	// if(motorB_dir){motorB.now = Encoder_count2;}else{motorB.now = -Encoder_count2;}
	// Encoder_count1 = 0;
	// Encoder_count2 = 0;
	// 3.����PID���������м���
	pid_cal(&motorA);
	pid_cal(&motorB);
	// �������޷�
	pidout_limit(&motorA);
	pidout_limit(&motorB);
	// 4.PID�����ֵ ��������
	motorA_duty(motorA.out);
	motorB_duty(motorB.out);
	
	//datavision_send();
}

void pid_control_angle(int ang)
{
//    // �ǶȻ�
//    // 1.�趨Ŀ��Ƕ�
    angle.target = ang;
//    // 2.��ȡ��ǰ�Ƕ�
    angle.now = yaw_gyro;
//    // 3.PID�������������
    pid_cal(&angle);
    

    
    // 1.�ǶȻ�PID��� �趨Ϊ�ٶȻ���Ŀ��ֵ
//	if(fabs(angle.out)>10)
//	{
//		if(angle.out<0)	angle.out=-1;
//		else angle.out=1;
//	}
    motor_target_set(-angle.out, angle.out);
    // 2.��ȡ��ǰ�ٶ�
    // if(motorA_dir){motorA.now = Encoder_count1;}else{motorA.now = -Encoder_count1;}
    // if(motorB_dir){motorB.now = Encoder_count2;}else{motorB.now = -Encoder_count2;}
    // Encoder_count1 = 0;
    // Encoder_count2 = 0;
    // 3.����PID���������м���
    pid_cal(&motorA);
    pid_cal(&motorB);
    // �������޷�
//    pidout_limit(&motorA);
//    pidout_limit(&motorB);
    pidout_limit_angle(&motorA);
    pidout_limit_angle(&motorB);
    // 4.PID�����ֵ ��������
    motorA_duty(motorA.out);
    motorB_duty(motorB.out);
    
    //datavision_send();
}

void pid_cal(pid_t *pid)
{
	// ���㵱ǰƫ��
	pid->error[0] = pid->target - pid->now;

	// �������
	if(pid->pid_mode == DELTA_PID)  // ����ʽ
	{
		pid->pout = pid->p * (pid->error[0] - pid->error[1]);
		pid->iout = pid->i * pid->error[0];
		pid->dout = pid->d * (pid->error[0] - 2 * pid->error[1] + pid->error[2]);
		pid->out += pid->pout + pid->iout + pid->dout;
	}
	else if(pid->pid_mode == POSITION_PID)  // λ��ʽ
	{
		pid->pout = pid->p * pid->error[0];
		pid->iout += pid->i * pid->error[0];
		pid->dout = pid->d * (pid->error[0] - pid->error[1]);
		pid->out = pid->pout + pid->iout + pid->dout;
	}

	// ��¼ǰ����ƫ��
	pid->error[2] = pid->error[1];
	pid->error[1] = pid->error[0];

	// ����޷�
//	if(pid->out>=MAX_DUTY)	
//		pid->out=MAX_DUTY;
//	if(pid->out<=0)	
//		pid->out=0;
	
}

void pidout_limit(pid_t *pid)
{
	// ����޷�
	if(pid->out>=MAX_DUTY)	
		pid->out=MAX_DUTY;
	if(pid->out<=0)	
		pid->out=0;
}

void pidout_limit_angle(pid_t *pid)
{
	// ����޷�
	if(pid->out>=16000)	
		pid->out=16000;
	if(pid->out<=0)	
		pid->out=0;
}
