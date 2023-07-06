#include "Config.h"

u16 *ValidN1;//获取指纹个数
u8 flag=0;   //0 识别状态 1 管理员状态
u8 ID=0;//管理员ID存储
u8  key_get=0;//获取按键的值
u8 stat_flag=0;//接受内机发送过来的信号判断开关门
u8 press_count=0;//管理员验证次数
void GLY()//管理员界面
{
	OLED_Print(20,0,"管理员模式");
	OLED_Print(0,2,"添加指纹:K3");
	OLED_Print(0,4,"删除指纹:K4");
	OLED_Print(0,6,"退    出:K2");
}
void ZW_gn()//指纹功能模块
{	
	
	if(key_get==1)//进入管理员模式
	{
		flag=1;
		key_get=0;
	}
	switch(flag)
	{
		case 0:
			if(stat_flag == 0)
			{
				OLED_Print(20,0,"Hello home");
				OLED_Print(38,2,"欢迎你");
				OLED_Print(20,4,"指 纹 解 锁");
			}
			if(stat_flag == 1)
			{
				OLED_Print(20,0,"Hello home");
				OLED_Print(38,2,"欢迎你");
				OLED_Print(20,4,"门 已 打 开");
			}
			if(GanYing==1)//感应到有人按指纹	
			{
					GY_IN=0;//控制引脚三极管导通
					press_FR();
			}
			else{
				GY_IN=1;		
			}
		break;
		case 1:
			OLED_Clear();
			OLED_Print(0,0,"管理员模式");
			delay_ms(500);
			OLED_Clear();
			OLED_Print(0,0,"验证管理员身份");		
		    delay_ms(1500);
		    press_count=0;
L:		    GY_IN=0;//控制引脚三极管导通
	        press_FR();
			GY_IN=1;//控制引脚三极管导通		
			while(1)
			{
				key_get = KEY_Scanf();
				printf("key_get : %d\r\n",key_get);
				if(ID==5)
				{
					GLY();	
					if(key_get == 2)//添加指纹
					{
						OLED_Clear();
						Add_FR();
					}
					if(key_get == 3)//删除指纹
					{
							OLED_Clear();
							Del_FR();
					}
					if(key_get == 1)//退出管理员
					{
						OLED_Clear();
						flag=0;
						break;
					}
					//break;
				}
				else{
					press_count++;
					if(press_count>=10)
					{
						OLED_Print(10,2,"即将返回主页！");
						OLED_DrawBMP(96,4,128,8,klt1);
						delay_ms(1500);
						OLED_Clear();
						press_count=0;
						flag=0;
						break;
					}
					else{
						OLED_Print(10,2,"验证身份失败");
						OLED_Print(10,4,"再刷一次");
						OLED_DrawBMP(96,4,128,8,klt1);
						delay_ms(1500);
						OLED_Clear();
						goto L;
					}
				}	
			}
			key_get=0;
		break;
			
	}
			
}
void LED_gn()//LED模块
{
	if(stat_flag==0)//门关闭状态,红灯亮，绿灯灭
	{
		Bute_LED=1;
		Red_LED=0;
	}
	else if(stat_flag==1)//门打开状态,红灯灭，绿灯亮
	{
		Bute_LED=0;
		Red_LED=1;
	}
	
}
u8 door_flag = 1;
u8 time2=0;
u8 time10=0;
u8 last=0;
u8 mode=0;
u8 open=1;
u8 rx_xcpai=0;
void xcpai(void);
void duoji(void);
int main(void)
{	
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
		delay_init();	    	        //延时函数初始化
		SystemInit();		
		Uart_Init(115200);//串口1初始化
		usart3_init(57600);//指纹串口初始化  
		zndguang();//外部接口
		Key_Init();//按键初始化
		WKUP_Init(); //待机唤醒初始化
		LED_Init();
		jidianqi();//继电器
		ji=0;
		OLED_Init();//OLED初始化
		OLED_Clear();//开始先清屏
		PS_StaGPIO_Init();       //低功耗初始化--指纹
		PS_ValidTempleteNum(ValidN1);//读取一共有多少个指纹
		Servo_Init();
		delay_ms(10);
		
		//kong_flag=0;   //告诉esp8266 
		if(open_flag==1)
		{
			kong_flag=1;
			Servo_SetAngle(10);
			ji=1;//开启继电器
			delay_ms(1000);delay_ms(1000);delay_ms(1000);delay_ms(1000);;
			ji=0;//关闭继电器	
			stat_flag=1;
			last = open_flag;
		}
		TIM3_Int_Init(999,7199); 
		while(1)
		{
			LED_gn();				//led灯反应门的状态
			key_get = KEY_Scanf();
			ZW_gn();
			if(rx_xcpai==0)
			duoji();
			else xcpai();
		}
	 
}

void duoji()
{
	if(time2==1)
	{
		time2=0;
		if(mode==1)//开门
		{
			kong_flag=1;
			stat_flag=1;
			Servo_SetAngle(10);
			ji=1;//开启继电器
			printf("gello\r\n");
			delay_ms(1000);delay_ms(1000);delay_ms(1000);delay_ms(1000);
			ji=0;//
		}
		if(mode==2)//关门
		{
			time10=0;
			kong_flag=0;
			stat_flag=0;
			Servo_SetAngle(360);
			ji=1;//开启继电器
			delay_ms(1000);delay_ms(1000);delay_ms(1000);delay_ms(1000);delay_ms(500);
			ji=0;//
		}
		if(open_flag==1)//开门
		{
			if(open_flag!=last) mode=1;
			else mode=0;
			last = open_flag;
		}
		if(open_flag==0)// 关门
		{
			if(open_flag!=last) mode=2;
			else mode=0;
			last = open_flag;
		}
	}
}

void xcpai(void)
{
	if(mode==1)//开门
	{
		mode=0;rx_xcpai=0;last=1;
		kong_flag=1;
		stat_flag=1;
		Servo_SetAngle(10);
		ji=1;//开启继电器
		delay_ms(1000);delay_ms(1000);delay_ms(1000);delay_ms(500);
		ji=0;//
	}
}
