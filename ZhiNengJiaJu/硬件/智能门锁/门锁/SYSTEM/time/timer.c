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
* @Function      ��void TIM3_Int_Init(u16 arr,u16 psc)
* @Features      ��ͨ�ö�ʱ��3�жϳ�ʼ��
* @InportFunction��arr���Զ���װֵ��psc��ʱ��Ԥ��Ƶ��
* @ExportFunction��No
* @Author        ��TanXiaoDong
* @ModifiedDate  ��2020.12.24
* @Remarks       ������ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
**********************************************************************/
void TIM3_Int_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);                 //ʱ��ʹ��
	
	//��ʱ��TIM3��ʼ��
	TIM_TimeBaseStructure.TIM_Period = arr;                              //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc;                            //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;              //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;          //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);                      //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE );                            //ʹ��ָ����TIM3�ж�,��������ж�

	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;                      //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;            //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;                   //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                      //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);                                      //��ʼ��NVIC�Ĵ���

	TIM_Cmd(TIM3, ENABLE);                                               //ʹ��TIMx					 
}

/**********************************************************************
* @Function      ��void TIM2_Int_Init(u16 arr,u16 psc)
* @Features      ��TIM2�жϷ������
* @InportFunction��No
* @ExportFunction��No
* @Author        ��TanXiaoDong
* @ModifiedDate  ��2020.12.24
* @Remarks       ������ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
**********************************************************************/
void TIM2_Int_Init(u16 arr,u16 psc)
{	
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//TIM2ʱ��ʹ��    
	
	//��ʱ��TIM2��ʼ��
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM2�ж�,��������ж�
	
	TIM_Cmd(TIM2,ENABLE);//������ʱ��7
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0 ;//��ռ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		//�����ȼ�2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
	
}
/**********************************************************************
* @Function      ��void TIM3_IRQHandler(void)   //TIM3�ж�
* @Features      ��TIM3�жϷ������
* @InportFunction��No
* @ExportFunction��No
* @Author        ��TanXiaoDong
* @ModifiedDate  ��2020.12.24
* @Remarks       ������ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M

**********************************************************************/
extern u8 key_get;
extern u8 flag;
u16 count=0;     //����ֵ  
u8 wx_flag=0;    //1 ����ʼ����
u8 show=0;
extern u8 stat_flag;
int time3=0;//����
int time_io=0;//��ȡi0
extern u8 stat_flag;
u8 time3off=0;
extern u8 last;
extern u8 mode;
extern u8 time10;
extern u8 time2;
u8 xcpai_num=0;
extern u8 rx_xcpai;
void TIM3_IRQHandler(void)   //TIM3�ж� 0.1s
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //���TIM3�����жϷ������
	{	
	  TIM_ClearITPendingBit(TIM3, TIM_IT_Update);     //���TIMx�����жϱ�־	
		if(key_get||GanYing==1||flag==1)      //�������� ��Ӧ��ָ��ʶ�� ����Աģʽ
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
		//����ʶ����
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
* @Function      ��void TIM3_IRQHandler(void)   //TIM3�ж�
* @Features      ��TIM3�жϷ������
* @InportFunction��No
* @ExportFunction��No
* @Author        ��TanXiaoDong
* @ModifiedDate  ��2020.12.24
* @Remarks       ������ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
**********************************************************************/    
void TIM2_IRQHandler(void)
{ 	
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)//�Ǹ����ж�
	{	 			   
		USART3_RX_STA |= 1<<15;	//��ǽ������
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update  );  //���TIM2�����жϱ�־    
		TIM_Cmd(TIM2, DISABLE);  //�ر�TIM2
	}	    
}












