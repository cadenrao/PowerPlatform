#ifndef __POWERPLATFORMACTION_H
#define __POWERPLATFORMACTION_H


#include "OUTPUT.h"//ִ�еĶ�������Ӯ�������
#include "sys.h"//λ������֧�֡���Ƭ��ͷ�ļ�����
#include "PWM.h"//�������֧��
#include "DAC.h"//ģ�������

//������������ PP_������PP => PowerPlatform��

void PP_StayStill(void);
void PP_SpotTurnLeft(void);
void PP_SpotTurnRight(void);
void PP_GoForward(void);
void PP_Go_TurnLeft(void);
void PP_Go_TurnRight(void);
////



#endif // !__POWERPLATFORMACTION_H
