#include "led.h"
#include "zw_user.h"
#include "delay.h"
#include "sys.h"
#include "Key.h"
#include "usart.h"	 	
#include "timer.h"
#include "as608.h"
#include "usart3.h"
#include "oled.h"
#include "count.h"
extern unsigned char gImage_Finger3[];
extern unsigned char gImage_Finger2[];
extern unsigned char gImage_Finger1[];
extern unsigned char klt1[];//骷髅头
extern u8 key_get;//存储按键的值
extern char num;//矩阵键盘读数
void PS_StaGPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //使能GPIOB时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;		  //PA5设置感应指纹触摸引脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;	  //输入下拉模式
	GPIO_Init(GPIOB, &GPIO_InitStructure);			  //初始化GPIO
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;//配置PB1，控制指纹电源控制引脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		       //S推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		       //IO口速度为50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	GPIO_SetBits(GPIOB,GPIO_Pin_1);
	
}

/**********************************************************************
* @Function      ：void Add_FR(void)
* @Features      ：添加指纹
* @InportFunction：No                
* @ExportFunction：No
* @Author        ：TXD
* @ModifiedDate  ：2020.12.29
* @Remarks       ：No
**********************************************************************/

void Add_FR(void)
{
  u8 i, ensure, processnum = 0;
  u8 ID_NUM = 0;
	char str[20];
	GY_IN=0;//控制引脚三极管导通
	
  while(1)
  {
    switch (processnum)
    {
    case 0:
      i++;
		  printf("请按手指\r\n");
			OLED_Print(40,0,"添加指纹");
			OLED_Print(6,2,"请按指纹");
      ensure = PS_GetImage();
      if(ensure == 0x00)
      {
        ensure = PS_GenChar(CharBuffer1); //生成特征
        if(ensure == 0x00)
        {
					delay_ms(1500);
          i = 0;
          processnum = 1;                 //跳到第二步
        }
        else ShowErrMessage(ensure);
      }
      else
			{				
				ShowErrMessage(ensure);
			}
      break;

    case 1:
      i++;
			OLED_Clear();
			OLED_Print(40,0,"添加指纹");
			OLED_Print(6,2,"请再按一次");
		  printf("请再按一次 \r\n");
		  delay_ms(500);
      ensure = PS_GetImage();
      if(ensure == 0x00)
      {
        ensure = PS_GenChar(CharBuffer2);    //生成特征
        if(ensure == 0x00)
        {
					printf("指纹正常 \r\n");
					OLED_Clear();
					OLED_Print(40,0,"添加指纹");
					OLED_Print(6,2,"指纹正常");
					delay_ms(500);
          i = 0;
          processnum = 2;                    //跳到第三步
        }
        else ShowErrMessage(ensure);
      }
      else ShowErrMessage(ensure);
      break;

    case 2:
			printf("对比两次指纹 \r\n");
			OLED_Clear();
			OLED_Print(40,0,"添加指纹");
			OLED_Print(6,2,"对比两次指纹");
      ensure = PS_Match(); 
      if(ensure == 0x00)
      {
				delay_ms(500);
				printf("对比成功 \r\n");
				OLED_Clear();
				OLED_Print(40,0,"添加指纹");
				OLED_Print(6,2,"对比成功");
        processnum = 3; //跳到第四步
      }
      else
      {
				printf("对比失败 \r\n");
				OLED_Clear();
				OLED_Print(40,0,"添加指纹");
				OLED_Print(6,2,"对比两次失败");
				delay_ms(500);
        ShowErrMessage(ensure);
        i = 0;
        processnum = 0; //跳回第一步
      }
      delay_ms(500);
      break;

    case 3:
			printf("生成指纹模板 \r\n");
			OLED_Clear();
		OLED_Print(40,0,"添加指纹");
			OLED_Print(6,2,"生成指纹模板");
		  delay_ms(1500);
      ensure = PS_RegModel();
      if(ensure == 0x00)
      {
				delay_ms(100);
				printf("生成指纹模板成功 \r\n");
				OLED_Clear();
				OLED_Print(40,0,"添加指纹");
				OLED_Print(0,2,"生成指纹模板成功");				
				delay_ms(500);
        processnum = 4; //跳到第五步
      }
      else
      {
        processnum = 0;
        ShowErrMessage(ensure);
      }
      delay_ms(500);
      break;

    case 4:
			OLED_Clear();
			OLED_Print(40,0,"添加指纹");
			OLED_Print(6,2,"按K4加,按K3减");
			OLED_Print(6,4,"按K2保存");
      while(key_get != 1)
      {
        key_get = KEY_Scanf();
		  printf("key_num is %d",key_get);
        if(key_get == 2)
        {
          key_get = 0;
          if(ID_NUM > 0)
            ID_NUM--;
        }
        if(key_get == 3)
        {
          key_get = 0;
          if(ID_NUM < 99)
            ID_NUM++;
        }
				printf("ID = %d \r\n",ID_NUM);
				sprintf(str, " 指纹ID: %d ",ID_NUM);	
				OLED_Print(6,6,"指纹ID:");
				OLED_ShowNum(60,6,ID_NUM,4,16);
      }
      key_get = 0;
			delay_ms(500);
			printf("储存模板 \r\n");
			printf("ID = %d \r\n",ID_NUM);
      ensure = PS_StoreChar(CharBuffer2, ID_NUM); //储存模板
      if(ensure == 0x00)
      {				
				OLED_Clear();
				OLED_Print(40,0,"添加指纹");
				OLED_Print(6,2,"录入指纹成功");
				printf("录入指纹成功 \r\n");
				delay_ms(100);
				OLED_Clear();
				GY_IN = 1;
        return ;
      }
      else
      {
        processnum = 0;
        ShowErrMessage(ensure);
      }
      break;
    }
    delay_ms(400);
    if(i == 10)                            //超过5次没有按手指则退出
    {
			OLED_Clear();
			OLED_Print(40,0,"添加指纹");
			OLED_Print(6,2,"验证超时");
			delay_ms(100);
			OLED_Clear();
			GY_IN=1;//控制引脚三极管断开
      break;
    }
  }
}

SysPara AS608Para;//指纹模块AS608参数
/**********************************************************************
* @Function      ：void press_FR(void)
* @Features      ：刷指纹
* @InportFunction：No                
* @ExportFunction：No
* @Author        ：TXD
* @ModifiedDate  ：2020.12.29
* @Remarks       ：No
**********************************************************************/
extern u8 mode;
extern u8 ID;
extern u8 flag;
extern u8 stat_flag;
extern u8 control_flag;
u8 j=0;
void press_FR(void)
{
  SearchResult seach;
  u8 ensure;
  char str[20];
	printf("请按手指 \r\n");
	OLED_Clear();
	OLED_DrawBMP(26,0,90,8,gImage_Finger1);
	OLED_DrawBMP(96,4,128,8,klt1);
  while(key_get != 1)
  {
		printf("获取图像 \r\n");
    key_get = KEY_Scanf();
    ensure = PS_GetImage();
		j++;
    if(ensure == 0x00) 
    {
			j=0;
			printf("获取图像成功 \r\n");
      ensure = PS_GenChar(CharBuffer1);
			j++;
      if(ensure == 0x00) 
      {
				j=0;
				printf("生成特征成功 \r\n");
        ensure = PS_HighSpeedSearch(CharBuffer1, 0, 99, &seach);
        if(ensure == 0x00) 
        {
					printf("验证成功 \r\n");
					OLED_Clear();
          sprintf(str, " 指纹ID:%d  ", seach.pageID);
					printf("指纹ID:%d",seach.pageID);
					OLED_DrawBMP(26,0,90,8,gImage_Finger2);
					OLED_DrawBMP(96,4,128,8,klt1);
					OLED_Print(0,0,"验");
					OLED_Print(0,2,"证");
					OLED_Print(0,4,"成");
					OLED_Print(0,6,"功");
					//USART_SendData(USART2,'O');//向内机发送开门信号
					stat_flag=1;
					if(open_flag==0) mode=1;
					else mode=0;
					ID=seach.pageID;
					delay_ms(1500);
					OLED_Clear();
					break;
        }
        else
        {
					printf("验证失败 \r\n");
					OLED_Clear();
					OLED_DrawBMP(60,0,124,8,gImage_Finger3);
			    OLED_Print(20,0,"验");
					OLED_Print(20,2,"证");
					OLED_Print(20,4,"失");
					OLED_Print(20,6,"败");
					delay_ms(1500);
					OLED_Clear();
					break;
        }
      }
      else
			{
				 ShowErrMessage(ensure);
				 delay_ms(1500);
			}
    }
		if(j==10)
		{
				OLED_Clear();
				OLED_Print(6,2,"超时");
				delay_ms(1500);
				OLED_Clear();
			break;
		}
  }
}



/**********************************************************************
* @Function      ：void press_FR(void)
* @Features      ：删除指纹
* @InportFunction：No                
* @ExportFunction：No
* @Author        ：TXD
* @ModifiedDate  ：2020.12.29
* @Remarks       ：No
**********************************************************************/
void Del_FR(void)
{
  u8  ensure;
  u16 ID_NUM = 0;
	char DelStr[20];
	OLED_Clear();
	OLED_Print(40,0,"删除指纹");
	OLED_Print(6,2,"按K4加,按K3减");
	OLED_Print(6,4,"按K4保存");
	while(key_get != 1)
	{
		key_get = KEY_Scanf();
		if(key_get == 2)
		{
			key_get = 0;
			if(ID_NUM > 0)
				ID_NUM--;
		}
		if(key_get == 3)
		{
			key_get = 0;
			if(ID_NUM < 99)
				ID_NUM++;
		}            
		sprintf(DelStr, "指纹ID: %d ",ID_NUM);	
		printf("ID_NUM = %d \r\n",ID_NUM);
		OLED_Print(6,6,"指纹ID:");
		OLED_ShowNum(80,6,ID_NUM,4,16);
	}
  ensure = PS_DeletChar(ID_NUM, 1); //删除单个指纹
  if(ensure == 0)
  {
		sprintf(DelStr, "删除指纹ID: %d ",ID_NUM);	
		OLED_Clear();
		printf("删除成功 \r\n");
		delay_ms(1500);
		delay_ms(1500);
  }
  else
    ShowErrMessage(ensure);
    delay_ms(1500);
}
