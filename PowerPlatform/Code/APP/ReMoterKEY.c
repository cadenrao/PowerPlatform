#include "ReMoterKEY.h"


void REMOTER_KEY_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;
	//ʹ��PORTE,PORTFʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE | RCC_APB2Periph_GPIOF, ENABLE);
	//��ʼ��GPIOE�İ�������
	//--PEin(0) --ɲ��
	//--PEin(1) --�ӵ�
	//--PEin(2)--����
	//--PEin(3)--��ת

	//--PEin(4)--��ת
	//--PEin(11)--���żӵ�
	//--PEin(12)--���ż���
	GPIO_InitStructure.GPIO_Pin =   GPIO_Pin_0 | GPIO_Pin_1 |
									GPIO_Pin_2 | GPIO_Pin_3 |
									GPIO_Pin_4 | GPIO_Pin_11 |
									GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó��������루��λ��Ϊ�ߵ�ƽ��
	GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��GPIOE��ʹ�õ�IO

	//��ʼ��GPIOF�İ�������
	//--PFin(0)--�ߵ���ģʽ�л�
	//--PFin(1)--�͸�����
	//--PFin(2)--�͸�����
	//--PFin(3)--������
	//--PFin(4)--������
	//--PFin(5)--���������ת
	//--PFin(6)--������ﷴת
	//--PFin(7)--פ��
	//--PFin(8)--ң�ص���
	GPIO_InitStructure.GPIO_Pin =   GPIO_Pin_0 | GPIO_Pin_1 |
									GPIO_Pin_2 | GPIO_Pin_3 |
									GPIO_Pin_4 | GPIO_Pin_5 |
									GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó��������루��λ��Ϊ�ߵ�ƽ��
	GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ��GPIOE��ʹ�õ�IO

}



