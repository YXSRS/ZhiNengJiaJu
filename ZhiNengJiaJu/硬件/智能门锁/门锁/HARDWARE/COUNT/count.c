#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "oled.h"
#include "stdio.h"
#include "string.h"
#include "count.h"


void zndguang(void)           //IO对接esp8266
{
	GPIO_InitTypeDef GPIO_Inist;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

	
	GPIO_Inist.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Inist.GPIO_Pin=(GPIO_Pin_4|GPIO_Pin_7);
	GPIO_Init(GPIOA,&GPIO_Inist);
	GPIO_SetBits(GPIOA,GPIO_Pin_4|GPIO_Pin_7);
	
	GPIO_Inist.GPIO_Pin=GPIO_Pin_1;
	GPIO_Inist.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Inist.GPIO_Speed = GPIO_Speed_50MHz;		       //IO口速度为50MHz
	GPIO_Init(GPIOA,&GPIO_Inist);
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	
	
}



void fmq(void)
{
	GPIO_InitTypeDef GPIO_Inist;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_Inist.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Inist.GPIO_Pin=GPIO_Pin_8;//k1 k2 k3 
	GPIO_Init(GPIOA,&GPIO_Inist);
	GPIO_SetBits(GPIOA,GPIO_Pin_8);
	
}











