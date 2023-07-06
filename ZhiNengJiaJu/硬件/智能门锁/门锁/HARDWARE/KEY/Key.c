#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
#include "delay.h"
#include "stdio.h"

#include "key.h"
#include "delay.h"

void Key_Init()
{
	GPIO_InitTypeDef GPIO_Inist;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_Inist.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Inist.GPIO_Pin=(GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_15);//k1 k2 k3 
	GPIO_Init(GPIOA,&GPIO_Inist);
	GPIO_SetBits(GPIOA,GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_15);
}

u8 KEY_Scanf()
{
	u8 key_num=0;
	if(KEY1==0)
	{
		delay_ms(10);
		if(KEY1==0)
		{
			key_num=1;
		}while(!KEY1);
	}
	if(KEY2==0)
	{
		delay_ms(10);
		if(KEY2==0)
		{
			key_num=2;
		}while(!KEY2);
	}
	if(KEY3==0)
	{
		delay_ms(10);
		if(KEY3==0)
		{
			key_num=3;
		}while(!KEY3);
	}
	return key_num;
}
