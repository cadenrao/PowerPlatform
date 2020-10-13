#include "DAC.h"


///****************************************************************************
/// @brief   : ������DAC��ʼ�������͵�ѹ���ú���
/// ʹ��ʱ�ȵ���DACx_Init() -> Set_Dacx_mVol()                                  
///****************************************************************************



///****************************************************************************
/// @data    : 
/// @input   : null                                                                
/// @output  : null                                                                
/// @brief   : ��ʼ�� dac1���                                                                
///****************************************************************************
void DAC1_Init(void) {
	DAC_InitTypeDef DAC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	/*ʹ��GPIOAʱ�ӣ�DACx�����ͨ����PA4��PA5��
	* ʹ��DACͨ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);

	/*��GPIOͨ������Ϊģ�����루AIN��,��Ϊ�ڲ�DAC��GPIO������һ���
	avoid parasitic consumption */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;//����GPIOΪģ������ģʽ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;//PA4ΪDAC1���ͨ����stm32f10x�ֲ�ɲ�
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/*DACͨ��һ����*/
	DAC_InitStructure.DAC_Trigger = DAC_Trigger_None;
	DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;//����������
	DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
	DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Disable;//�������޷����0 vol
	DAC_Init(DAC_Channel_1, &DAC_InitStructure);

	/*enable dac channel1,once the channel is enabled,the PA4 pin will be automatically
	connected to the dac converter */
	DAC_Cmd(DAC_Channel_1, ENABLE);

	/*set dac channel data and initlize the output 0 vol*/
	DAC_SetChannel1Data(DAC_Align_12b_R, 0);

}

///****************************************************************************
/// @data    :                                                                 
/// @input   : null                                                                
/// @output  : null                                                                
/// @brief   : ��ʼ�� dac1���                                                                
///****************************************************************************
void DAC2_Init(void)
{
	DAC_InitTypeDef DAC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	/*ʹ��GPIOAʱ�ӣ�DACx�����ͨ����PA4��PA5��
	* ʹ��DACͨ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);

	/*��GPIOͨ������Ϊģ�����루AIN��,��Ϊ�ڲ�DAC��GPIO������һ���
	avoid parasitic consumption */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;//����GPIOΪģ������ģʽ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;//PA5ΪDAC1���ͨ����stm32f10x�ֲ�ɲ�
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/*DACͨ��һ����*/
	DAC_InitStructure.DAC_Trigger = DAC_Trigger_None;
	DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;//����������
	DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
	DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Disable;//�������޷����0 vol
	DAC_Init(DAC_Channel_2, &DAC_InitStructure);

	/*enable dac channel1,once the channel is enabled,the PA5 pin will be automatically
	connected to the dac converter */
	DAC_Cmd(DAC_Channel_2, ENABLE);

	/*set dac channel data and initlize the output 0 vol*/
	DAC_SetChannel1Data(DAC_Align_12b_R, 0);

}

///****************************************************************************
/// @data    :                                                                 
/// @input   :num_mvol ���͵�ѹֵ                                                                 
/// @output  :null                                                                 
/// @brief   :ʹdac1�����ѹ,�ο���ѹΪ3.3V �磺����2000 ��� 2v                                                                
///****************************************************************************
void Set_DAC1_mVol(float Voltage)
{
	uint16_t data;
	data = (uint16_t)((Voltage / 3.3) * 4096);
	DAC_SetChannel1Data(DAC_Align_12b_R, data);
	DAC_SoftwareTriggerCmd(DAC_Channel_1, ENABLE);
}


///****************************************************************************
/// @data    :                                                                 
/// @input   :num_mvol ���͵�ѹֵ                                                                 
/// @output  :null                                                                 
/// @brief   :ʹdac2�����ѹ                                                                 
///****************************************************************************
void Set_DAC2_mVol(float Voltage)
{
	uint16_t data;
	data = (uint16_t)((Voltage / 3.3) * 4096);
	DAC_SetChannel2Data(DAC_Align_12b_R, data);
	DAC_SoftwareTriggerCmd(DAC_Channel_2, ENABLE);
}


//while (1)
//{
//	keyState = KEY_Scan(0);	//�õ���ֵ,����֧������
//	if (keyState)
//	{
//		switch (keyState)
//		{
//			case KEY1_PRES:	//����LED0��ת	 
//				mvol += 0.05;
//				if(mvol>=3.0) mvol = 3.0;
//				printf("%f\n",mvol);
//				delay_ms(50);
//				break;
//			case KEY2_PRES:
//				mvol -= 0.05;
//				if(mvol <= 0) mvol = 0;
//				printf("%f\n",mvol);
//				delay_ms(50);
//			break;
//		}
//	}
//	else delay_ms(10); 
//	
//	Set_DAC1_mVol(mvol);
//	Set_DAC2_mVol(mvol/2);
//}