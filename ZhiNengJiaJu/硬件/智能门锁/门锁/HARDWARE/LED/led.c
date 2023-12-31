#include "led.h"
#include "delay.h"

//初始化PE13/PE14为输出口.并使能这两个口的时钟		    
//LED IO初始化
void LED_Init(void)
{

	 GPIO_InitTypeDef  GPIO_InitStructure;	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	     //使能PE端口时钟
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14;//配置LED 0.1.2
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		       //推挽输出
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		       //IO口速度为50MHz
	 GPIO_Init(GPIOB, &GPIO_InitStructure);					             //根据设定参数初始化
	 GPIO_SetBits(GPIOB,GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14);
	
	
}

void jidianqi()
{
	 GPIO_InitTypeDef  GPIO_InitStructure;	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	     //使能PE端口时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;//配置LED 0.1.2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		       //推挽输出
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		       //IO口速度为50MHz
	 GPIO_Init(GPIOB, &GPIO_InitStructure);					             //根据设定参数初始化
	GPIO_ResetBits(GPIOB,GPIO_Pin_2);
	
}
	

