#include "OUTPUT.h"

void Output_KEY_Init(void)
{

		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd(
			 RCC_APB2Periph_GPIOA|
			 RCC_APB2Periph_GPIOB|
			 RCC_APB2Periph_GPIOC|
			 RCC_APB2Periph_GPIOD, ENABLE);//ʹ��PE�˿�ʱ��

	//����PD9��PD10��PD11��PD12��PD13��PD14��PD15
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9| GPIO_Pin_10 | //���ڿ��ƺ����������ת
									  GPIO_Pin_11 | GPIO_Pin_12 | //���ƺ��ö����������������
									  GPIO_Pin_13 | GPIO_Pin_14 | //���ƽ����������ת
									  GPIO_Pin_15 ;// δ����
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//���������ʽ
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�ٶ�Ϊ50MHz
		GPIO_Init(GPIOD, &GPIO_InitStructure);//��ʼ��PD�˿�

	//����PA0��PA1��PA2��PA3
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | //���Ʊ������������
									  GPIO_Pin_2 | GPIO_Pin_3;  //�������Ŵ�С

		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//���������ʽ
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�ٶ�Ϊ50MHz
		GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��PD�˿�

	//����PB11��PB12��PB13��PB14
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12 | //�����������������ת
			                          GPIO_Pin_13 | GPIO_Pin_14;  //�����������������ת

		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//���������ʽ
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�ٶ�Ϊ50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��PD�˿�

	//����PC6��PC7��PC8
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8;  //���١�����ģʽ�л�
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//���������ʽ
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�ٶ�Ϊ50MHz
		GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��PD�˿�

}
