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
extern unsigned char klt1[];//����ͷ
extern u8 key_get;//�洢������ֵ
extern char num;//������̶���
void PS_StaGPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //ʹ��GPIOBʱ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;		  //PA5���ø�Ӧָ�ƴ�������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;	  //��������ģʽ
	GPIO_Init(GPIOB, &GPIO_InitStructure);			  //��ʼ��GPIO
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;//����PB1������ָ�Ƶ�Դ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		       //S�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		       //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	GPIO_SetBits(GPIOB,GPIO_Pin_1);
	
}

/**********************************************************************
* @Function      ��void Add_FR(void)
* @Features      �����ָ��
* @InportFunction��No                
* @ExportFunction��No
* @Author        ��TXD
* @ModifiedDate  ��2020.12.29
* @Remarks       ��No
**********************************************************************/

void Add_FR(void)
{
  u8 i, ensure, processnum = 0;
  u8 ID_NUM = 0;
	char str[20];
	GY_IN=0;//�������������ܵ�ͨ
	
  while(1)
  {
    switch (processnum)
    {
    case 0:
      i++;
		  printf("�밴��ָ\r\n");
			OLED_Print(40,0,"���ָ��");
			OLED_Print(6,2,"�밴ָ��");
      ensure = PS_GetImage();
      if(ensure == 0x00)
      {
        ensure = PS_GenChar(CharBuffer1); //��������
        if(ensure == 0x00)
        {
					delay_ms(1500);
          i = 0;
          processnum = 1;                 //�����ڶ���
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
			OLED_Print(40,0,"���ָ��");
			OLED_Print(6,2,"���ٰ�һ��");
		  printf("���ٰ�һ�� \r\n");
		  delay_ms(500);
      ensure = PS_GetImage();
      if(ensure == 0x00)
      {
        ensure = PS_GenChar(CharBuffer2);    //��������
        if(ensure == 0x00)
        {
					printf("ָ������ \r\n");
					OLED_Clear();
					OLED_Print(40,0,"���ָ��");
					OLED_Print(6,2,"ָ������");
					delay_ms(500);
          i = 0;
          processnum = 2;                    //����������
        }
        else ShowErrMessage(ensure);
      }
      else ShowErrMessage(ensure);
      break;

    case 2:
			printf("�Ա�����ָ�� \r\n");
			OLED_Clear();
			OLED_Print(40,0,"���ָ��");
			OLED_Print(6,2,"�Ա�����ָ��");
      ensure = PS_Match(); 
      if(ensure == 0x00)
      {
				delay_ms(500);
				printf("�Աȳɹ� \r\n");
				OLED_Clear();
				OLED_Print(40,0,"���ָ��");
				OLED_Print(6,2,"�Աȳɹ�");
        processnum = 3; //�������Ĳ�
      }
      else
      {
				printf("�Ա�ʧ�� \r\n");
				OLED_Clear();
				OLED_Print(40,0,"���ָ��");
				OLED_Print(6,2,"�Ա�����ʧ��");
				delay_ms(500);
        ShowErrMessage(ensure);
        i = 0;
        processnum = 0; //���ص�һ��
      }
      delay_ms(500);
      break;

    case 3:
			printf("����ָ��ģ�� \r\n");
			OLED_Clear();
		OLED_Print(40,0,"���ָ��");
			OLED_Print(6,2,"����ָ��ģ��");
		  delay_ms(1500);
      ensure = PS_RegModel();
      if(ensure == 0x00)
      {
				delay_ms(100);
				printf("����ָ��ģ��ɹ� \r\n");
				OLED_Clear();
				OLED_Print(40,0,"���ָ��");
				OLED_Print(0,2,"����ָ��ģ��ɹ�");				
				delay_ms(500);
        processnum = 4; //�������岽
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
			OLED_Print(40,0,"���ָ��");
			OLED_Print(6,2,"��K4��,��K3��");
			OLED_Print(6,4,"��K2����");
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
				sprintf(str, " ָ��ID: %d ",ID_NUM);	
				OLED_Print(6,6,"ָ��ID:");
				OLED_ShowNum(60,6,ID_NUM,4,16);
      }
      key_get = 0;
			delay_ms(500);
			printf("����ģ�� \r\n");
			printf("ID = %d \r\n",ID_NUM);
      ensure = PS_StoreChar(CharBuffer2, ID_NUM); //����ģ��
      if(ensure == 0x00)
      {				
				OLED_Clear();
				OLED_Print(40,0,"���ָ��");
				OLED_Print(6,2,"¼��ָ�Ƴɹ�");
				printf("¼��ָ�Ƴɹ� \r\n");
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
    if(i == 10)                            //����5��û�а���ָ���˳�
    {
			OLED_Clear();
			OLED_Print(40,0,"���ָ��");
			OLED_Print(6,2,"��֤��ʱ");
			delay_ms(100);
			OLED_Clear();
			GY_IN=1;//�������������ܶϿ�
      break;
    }
  }
}

SysPara AS608Para;//ָ��ģ��AS608����
/**********************************************************************
* @Function      ��void press_FR(void)
* @Features      ��ˢָ��
* @InportFunction��No                
* @ExportFunction��No
* @Author        ��TXD
* @ModifiedDate  ��2020.12.29
* @Remarks       ��No
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
	printf("�밴��ָ \r\n");
	OLED_Clear();
	OLED_DrawBMP(26,0,90,8,gImage_Finger1);
	OLED_DrawBMP(96,4,128,8,klt1);
  while(key_get != 1)
  {
		printf("��ȡͼ�� \r\n");
    key_get = KEY_Scanf();
    ensure = PS_GetImage();
		j++;
    if(ensure == 0x00) 
    {
			j=0;
			printf("��ȡͼ��ɹ� \r\n");
      ensure = PS_GenChar(CharBuffer1);
			j++;
      if(ensure == 0x00) 
      {
				j=0;
				printf("���������ɹ� \r\n");
        ensure = PS_HighSpeedSearch(CharBuffer1, 0, 99, &seach);
        if(ensure == 0x00) 
        {
					printf("��֤�ɹ� \r\n");
					OLED_Clear();
          sprintf(str, " ָ��ID:%d  ", seach.pageID);
					printf("ָ��ID:%d",seach.pageID);
					OLED_DrawBMP(26,0,90,8,gImage_Finger2);
					OLED_DrawBMP(96,4,128,8,klt1);
					OLED_Print(0,0,"��");
					OLED_Print(0,2,"֤");
					OLED_Print(0,4,"��");
					OLED_Print(0,6,"��");
					//USART_SendData(USART2,'O');//���ڻ����Ϳ����ź�
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
					printf("��֤ʧ�� \r\n");
					OLED_Clear();
					OLED_DrawBMP(60,0,124,8,gImage_Finger3);
			    OLED_Print(20,0,"��");
					OLED_Print(20,2,"֤");
					OLED_Print(20,4,"ʧ");
					OLED_Print(20,6,"��");
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
				OLED_Print(6,2,"��ʱ");
				delay_ms(1500);
				OLED_Clear();
			break;
		}
  }
}



/**********************************************************************
* @Function      ��void press_FR(void)
* @Features      ��ɾ��ָ��
* @InportFunction��No                
* @ExportFunction��No
* @Author        ��TXD
* @ModifiedDate  ��2020.12.29
* @Remarks       ��No
**********************************************************************/
void Del_FR(void)
{
  u8  ensure;
  u16 ID_NUM = 0;
	char DelStr[20];
	OLED_Clear();
	OLED_Print(40,0,"ɾ��ָ��");
	OLED_Print(6,2,"��K4��,��K3��");
	OLED_Print(6,4,"��K4����");
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
		sprintf(DelStr, "ָ��ID: %d ",ID_NUM);	
		printf("ID_NUM = %d \r\n",ID_NUM);
		OLED_Print(6,6,"ָ��ID:");
		OLED_ShowNum(80,6,ID_NUM,4,16);
	}
  ensure = PS_DeletChar(ID_NUM, 1); //ɾ������ָ��
  if(ensure == 0)
  {
		sprintf(DelStr, "ɾ��ָ��ID: %d ",ID_NUM);	
		OLED_Clear();
		printf("ɾ���ɹ� \r\n");
		delay_ms(1500);
		delay_ms(1500);
  }
  else
    ShowErrMessage(ensure);
    delay_ms(1500);
}
