#include "Config.h"

u16 *ValidN1;//��ȡָ�Ƹ���
u8 flag=0;   //0 ʶ��״̬ 1 ����Ա״̬
u8 ID=0;//����ԱID�洢
u8  key_get=0;//��ȡ������ֵ
u8 stat_flag=0;//�����ڻ����͹������ź��жϿ�����
u8 press_count=0;//����Ա��֤����
void GLY()//����Ա����
{
	OLED_Print(20,0,"����Աģʽ");
	OLED_Print(0,2,"���ָ��:K3");
	OLED_Print(0,4,"ɾ��ָ��:K4");
	OLED_Print(0,6,"��    ��:K2");
}
void ZW_gn()//ָ�ƹ���ģ��
{	
	
	if(key_get==1)//�������Աģʽ
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
				OLED_Print(38,2,"��ӭ��");
				OLED_Print(20,4,"ָ �� �� ��");
			}
			if(stat_flag == 1)
			{
				OLED_Print(20,0,"Hello home");
				OLED_Print(38,2,"��ӭ��");
				OLED_Print(20,4,"�� �� �� ��");
			}
			if(GanYing==1)//��Ӧ�����˰�ָ��	
			{
					GY_IN=0;//�������������ܵ�ͨ
					press_FR();
			}
			else{
				GY_IN=1;		
			}
		break;
		case 1:
			OLED_Clear();
			OLED_Print(0,0,"����Աģʽ");
			delay_ms(500);
			OLED_Clear();
			OLED_Print(0,0,"��֤����Ա���");		
		    delay_ms(1500);
		    press_count=0;
L:		    GY_IN=0;//�������������ܵ�ͨ
	        press_FR();
			GY_IN=1;//�������������ܵ�ͨ		
			while(1)
			{
				key_get = KEY_Scanf();
				printf("key_get : %d\r\n",key_get);
				if(ID==5)
				{
					GLY();	
					if(key_get == 2)//���ָ��
					{
						OLED_Clear();
						Add_FR();
					}
					if(key_get == 3)//ɾ��ָ��
					{
							OLED_Clear();
							Del_FR();
					}
					if(key_get == 1)//�˳�����Ա
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
						OLED_Print(10,2,"����������ҳ��");
						OLED_DrawBMP(96,4,128,8,klt1);
						delay_ms(1500);
						OLED_Clear();
						press_count=0;
						flag=0;
						break;
					}
					else{
						OLED_Print(10,2,"��֤���ʧ��");
						OLED_Print(10,4,"��ˢһ��");
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
void LED_gn()//LEDģ��
{
	if(stat_flag==0)//�Źر�״̬,��������̵���
	{
		Bute_LED=1;
		Red_LED=0;
	}
	else if(stat_flag==1)//�Ŵ�״̬,������̵���
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
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
		delay_init();	    	        //��ʱ������ʼ��
		SystemInit();		
		Uart_Init(115200);//����1��ʼ��
		usart3_init(57600);//ָ�ƴ��ڳ�ʼ��  
		zndguang();//�ⲿ�ӿ�
		Key_Init();//������ʼ��
		WKUP_Init(); //�������ѳ�ʼ��
		LED_Init();
		jidianqi();//�̵���
		ji=0;
		OLED_Init();//OLED��ʼ��
		OLED_Clear();//��ʼ������
		PS_StaGPIO_Init();       //�͹��ĳ�ʼ��--ָ��
		PS_ValidTempleteNum(ValidN1);//��ȡһ���ж��ٸ�ָ��
		Servo_Init();
		delay_ms(10);
		
		//kong_flag=0;   //����esp8266 
		if(open_flag==1)
		{
			kong_flag=1;
			Servo_SetAngle(10);
			ji=1;//�����̵���
			delay_ms(1000);delay_ms(1000);delay_ms(1000);delay_ms(1000);;
			ji=0;//�رռ̵���	
			stat_flag=1;
			last = open_flag;
		}
		TIM3_Int_Init(999,7199); 
		while(1)
		{
			LED_gn();				//led�Ʒ�Ӧ�ŵ�״̬
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
		if(mode==1)//����
		{
			kong_flag=1;
			stat_flag=1;
			Servo_SetAngle(10);
			ji=1;//�����̵���
			printf("gello\r\n");
			delay_ms(1000);delay_ms(1000);delay_ms(1000);delay_ms(1000);
			ji=0;//
		}
		if(mode==2)//����
		{
			time10=0;
			kong_flag=0;
			stat_flag=0;
			Servo_SetAngle(360);
			ji=1;//�����̵���
			delay_ms(1000);delay_ms(1000);delay_ms(1000);delay_ms(1000);delay_ms(500);
			ji=0;//
		}
		if(open_flag==1)//����
		{
			if(open_flag!=last) mode=1;
			else mode=0;
			last = open_flag;
		}
		if(open_flag==0)// ����
		{
			if(open_flag!=last) mode=2;
			else mode=0;
			last = open_flag;
		}
	}
}

void xcpai(void)
{
	if(mode==1)//����
	{
		mode=0;rx_xcpai=0;last=1;
		kong_flag=1;
		stat_flag=1;
		Servo_SetAngle(10);
		ji=1;//�����̵���
		delay_ms(1000);delay_ms(1000);delay_ms(1000);delay_ms(500);
		ji=0;//
	}
}
