#include "timer.h"
#include "usart3.h"
#include "wkup.h"
#include "zw_user.h"
#include "oled.h"
#include "count.h"
#include "usart.h"
#include "stdio.h"
u8 key_num = 0;
extern vu16 USART3_RX_STA;

/**********************************************************************
* @Function      ：void TIM3_Int_Init(u16 arr,u16 psc)
* @Features      ：通用定时器3中断初始化
* @InportFunction：arr：自动重装值。psc：时钟预分频数
* @ExportFunction：No
* @Author        ：TanXiaoDong
* @ModifiedDate  ：2020.12.24
* @Remarks       ：这里时钟选择为APB1的2倍，而APB1为36M
**********************************************************************/
void TIM3_Int_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);                 //时钟使能
	
	//定时器TIM3初始化
	TIM_TimeBaseStructure.TIM_Period = arr;                              //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =psc;                            //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;              //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;          //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);                      //根据指定的参数初始化TIMx的时间基数单位
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE );                            //使能指定的TIM3中断,允许更新中断

	//中断优先级NVIC设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;                      //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;            //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;                   //从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                      //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);                                      //初始化NVIC寄存器

	TIM_Cmd(TIM3, ENABLE);                                               //使能TIMx					 
}

/**********************************************************************
* @Function      ：void TIM2_Int_Init(u16 arr,u16 psc)
* @Features      ：TIM2中断服务程序
* @InportFunction：No
* @ExportFunction：No
* @Author        ：TanXiaoDong
* @ModifiedDate  ：2020.12.24
* @Remarks       ：这里时钟选择为APB1的2倍，而APB1为36M
**********************************************************************/
void TIM2_Int_Init(u16 arr,u16 psc)
{	
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//TIM2时钟使能    
	
	//定时器TIM2初始化
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位
 
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE ); //使能指定的TIM2中断,允许更新中断
	
	TIM_Cmd(TIM2,ENABLE);//开启定时器7
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0 ;//抢占优先级0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		//子优先级2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
	
}
/**********************************************************************
* @Function      ：void TIM3_IRQHandler(void)   //TIM3中断
* @Features      ：TIM3中断服务程序
* @InportFunction：No
* @ExportFunction：No
* @Author        ：TanXiaoDong
* @ModifiedDate  ：2020.12.24
* @Remarks       ：这里时钟选择为APB1的2倍，而APB1为36M

**********************************************************************/
extern u8 key_get;
extern u8 flag;
u16 count=0;     //计数值  
u8 wx_flag=0;    //1 ：开始计数
u8 show=0;
extern u8 stat_flag;
int time3=0;//关门
int time_io=0;//读取i0
extern u8 stat_flag;
u8 time3off=0;
extern u8 last;
extern u8 mode;
extern u8 time10;
extern u8 time2;
u8 xcpai_num=0;
extern u8 rx_xcpai;
void TIM3_IRQHandler(void)   //TIM3中断 0.1s
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //检查TIM3更新中断发生与否
	{	
	  TIM_ClearITPendingBit(TIM3, TIM_IT_Update);     //清除TIMx更新中断标志	
		if(key_get||GanYing==1||flag==1)      //按键按下 感应到指纹识别 管理员模式
		{
			wx_flag=0;
			count=0;
		}
		else{
			wx_flag=1;
		}	
		if(wx_flag==1)
		{
			count++;
		}
		else{
			count=0;
		}
		if(stat_flag==1)
		{
			time10++; if(time10>100) {mode=2;time10=0;}
			
		}
		time3++; if(time3>=20){printf("%d",stat_flag);printf("%d",time10);  time2=1;time3=0;}
		//人脸识别方向
		if(xcp==0)
		{
			xcpai_num++; 
			printf("a");
			if(xcpai_num>=2) {mode=1;xcpai_num=0;rx_xcpai=1;}
		}
		if(xcp==1)
		{
			xcpai_num=0;
			printf("b");
		}

	}
}

/**********************************************************************
* @Function      ：void TIM3_IRQHandler(void)   //TIM3中断
* @Features      ：TIM3中断服务程序
* @InportFunction：No
* @ExportFunction：No
* @Author        ：TanXiaoDong
* @ModifiedDate  ：2020.12.24
* @Remarks       ：这里时钟选择为APB1的2倍，而APB1为36M
**********************************************************************/    
void TIM2_IRQHandler(void)
{ 	
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)//是更新中断
	{	 			   
		USART3_RX_STA |= 1<<15;	//标记接收完成
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update  );  //清除TIM2更新中断标志    
		TIM_Cmd(TIM2, DISABLE);  //关闭TIM2
	}	    
}












