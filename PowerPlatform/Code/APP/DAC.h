
#ifndef __DAC_H
#define __DAC_H

#include "sys.h"
#include "delay.h"

void DAC1_Init(void);
void DAC2_Init(void);

void Set_DAC1_mVol(float num_mvol);
void Set_DAC2_mVol(float num_mvol);

#endif // !__DAC_H

///****************************************************************************                 
/// @brief   :  ������������dac1 dac2 ,ʹ�÷���DACx_Init() -> DACx_Set_mVol()                                                               
///****************************************************************************
