#include "led.h"

void UserLED_Init(void)
{
	GPIO_InitTypeDef GPIO_Parameter;//GPIO��ʼ���ṹ������

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOE, ENABLE);//ʹ��GPIOB|GPIOE

	GPIO_Parameter.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Parameter.GPIO_Pin = GPIO_Pin_5;
	GPIO_Parameter.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Parameter);
	SET_PB5LED_OFF;


	//GPIO_Parameter.GPIO_Pin = GPIO_Pin_7;
	//GPIO_Init(GPIOB, &GPIO_Parameter);


	//���ú�GPIOB��ȫһ�������ﲻд
	GPIO_Init(GPIOE, &GPIO_Parameter);
	SET_PE5LED_OFF;



}

void FluentLEDs(void)
{
	if (PB5LED_Off) {
		SET_PB5LED_ON;
		delay_ms(100);
	}
	else {
		SET_PB5LED_OFF;
		delay_ms(100);
	}

	if (PE5LED_Off) {
		SET_PE5LED_ON;
		delay_ms(100);
	}
	else {
		SET_PE5LED_OFF;
		delay_ms(100);
	}
}

