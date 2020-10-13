#ifndef __REMOTERKEY_H
#define __REMOTERKEY_H
#endif // !__REMOTERKEY_H

#include "sys.h"

/*signal for recv*/
#define LOCK_CAR_BTN				PEin(0) //ɲ��
#define ADD_CAR_GEAR_BTN			PEin(1) //�ӵ�
#define SUBTRACT_CAR_GEAR_BTN		PEin(2)//����
#define TURN_LEFT_BTN				PEin(3)//��ת
#define TURN_RIGHT_BTN				PEin(4)//��ת
#define SWITCH_SPEED_MODE_BTN		PFin(0)//�ߵ���ģʽ�л�
#define CYLINDER_UP_BTN				PFin(1)//�͸�����
#define CYLINDER_DOWN_BTN			PFin(2)//�͸��½�
#define CAPSTAN_IN_BTN				PFin(3)//������
#define CAPSTAN_OUT_BTN				PFin(4)//���̷�
#define BACK_MOTOR_FORWARD_BTN		PFin(5)//���������ת
#define BACK_MOTOR_BACKWARD_BTN		PFin(6)//������ﷴת
#define ACCELERATOR_UP_BTN			PEin(11)//���żӵ�
#define ACCELERATOR_DOWN_BTN		PEin(12)//���ż���
#define PARKING_BTN					PFin(7)//פ��
#define LOST_POWER_BTN				PFin(8)//ң�ص���

/*��������*/
#define EN_LOCK_CAR  LOCK_CAR_BTN == 0//ɲ��
#define DIS_LOCK_CAR LOCK_CAR_BTN == 1//δɲ��
#define EN_ADD_CAR_GEAR ADD_CAR_GEAR_BTN == 0//�ӵ�
#define EN_SUBTRACT_CAR_GEAR SUBTRACT_CAR_GEAR_BTN == 0//����
#define EN_TURN_LEFT TURN_LEFT_BTN == 0//��ת
#define EN_TURN_RIGHT TURN_RIGHT_BTN == 0//��ת
#define EN_HIGH_SPEED_MODE SWITCH_SPEED_MODE_BTN == 0//����ģʽ
#define EN_LOW_SPEED_MODE SWITCH_SPEED_MODE_BTN == 1//����ģʽ
#define EN_CYLINDER_UP CYLINDER_UP_BTN == 0//�͸�����
#define EN_CYLINDER_DOWN CYLINDER_DOWN_BTN == 0//�͸��½�
#define EN_CAPSTAN_IN CAPSTAN_IN_BTN == 0//������
#define EN_CAPSTAN_OUT CAPSTAN_OUT_BTN == 0//���̷�
#define EN_BACK_MOTOR_FORWARD BACK_MOTOR_FORWARD_BTN == 0//���������ת
#define EN_BACK_MOTOR_BACKWARD	BACK_MOTOR_BACKWARD_BTN	== 0//������ﷴת
#define EN_ACCELERATOR_UP ACCELERATOR_UP_BTN == 0//���żӵ�
#define EN_ACCELERATOR_DOWN ACCELERATOR_DOWN_BTN == 0//���ż���
#define EN_PARKING PARKING_BTN == 0//פ��
#define DIS_PARKING PARKING_BTN == 1//δפ��
#define EN_LOST_POWER LOST_POWER_BTN == 0//ң�ص���
//���巵�ؼ�ֵ�ĺ���

//IO��ʼ��
void REMOTER_KEY_Init(void);

