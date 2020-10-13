#include "PWM.h"
#include "sys.h"
#include "delay.h"

	
///****************************************************************************                 
/// @brief   :����������PWM4��CH2/CH3 �������������ȵ���PWM_Init()������
///			  ������ʹ��	TIM_SetComparex(TIMx,uin16_t num_CNT);��������ռ�ձ�
///****************************************************************************


	
///****************************************************************************
/// @data    :                                                                 
/// @input   :
///				arr -- �Զ���װֵ
///				psc -- ʱ��Ԥ��Ƶ��                                                                
/// @output  :	null                                                             
/// @brief   :
///				��ʼ��PWM TIM4,TIM4Ϊ72MHz 
///				PWM��Ƶ��  PWMƵ��=72000000/(arr+1)*(psc+1) 
///				TIMx ��Ƶ��Ϊ 72000000/(psc+1)				
///****************************************************************************
void PWM_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIO_Parameter;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseParameter;
	TIM_OCInitTypeDef TIM_OCInitStructure;

	//ʹ����ص�GPIO�Ͷ�ʱ����TIM���Լ����ù��ܣ�AFIO��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//ʹ�ܶ�ʱ��4,��ʹ��CH2->PB7 CH3->PB8
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ʹ��PB,AFIO
	TIM_DeInit(TIM4);
	

	//��ʼ��PB7
	GPIO_Parameter.GPIO_Mode = GPIO_Mode_AF_PP;//�������
	GPIO_Parameter.GPIO_Pin = GPIO_Pin_7;//TIM4_CH2�����
	GPIO_Parameter.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Parameter);

	//��ʼ��PB8
	GPIO_Parameter.GPIO_Mode = GPIO_Mode_AF_PP;//�������
	GPIO_Parameter.GPIO_Pin = GPIO_Pin_9;//TIM4_CH4�����
	GPIO_Parameter.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Parameter);

	//��ʼ��TIM4,����PWM��Ƶ��
	TIM_TimeBaseParameter.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseParameter.TIM_Prescaler = psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ 
	TIM_TimeBaseParameter.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseParameter.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseParameter); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

	//��ʼ��TIM4 Channel2 PWMģʽ
	TIM_OCInitStructure.TIM_Pulse = 300;
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);  //����ָ���Ĳ�����ʼ������TIM4 OC2

	//��ʼ��TIM4 Channel2 PWMģʽ
	TIM_OCInitStructure.TIM_Pulse = 300;
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);  //����ָ���Ĳ�����ʼ������TIM4 OC4

	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);  //ʹ��TIM4��CCR2�ϵ�Ԥװ�ؼĴ���
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);  //ʹ��TIM4��CCR3�ϵ�Ԥװ�ؼĴ���

	TIM_Cmd(TIM4, ENABLE);  //ʹ��TIM4
	
	TIM_SetCompare2(TIM4,0);
	TIM_SetCompare4(TIM4, 0);

}


//PWM_Init(719, 4);//����PWMΪ20KHZ
//u16 led0pwmval = 0;

//////while (1)
//////{

//////	switch (KEY_Scan(1))
//////	{
//////	case KEY0_PRES:
//////		led0pwmval += 5;
//////		break;
//////	default:
//////		break;
//////	}

//////	TIM_SetCompare2(TIM4, led0pwmval);
//////	TIM_SetCompare4(TIM4, led0pwmval);
//////}
