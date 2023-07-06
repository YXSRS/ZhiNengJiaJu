#ifndef __ZW_USER_H
#define __ZW_USER_H	 

#define GanYing   PBin(0)//读指纹模块状态引脚
#define GY_IN     PBout(1)//继电器控制引脚
#define Zw_LED    PBout(5)//读指纹模块状态引脚
void PS_StaGPIO_Init(void);

void Add_FR(void);//添加指纹

void press_FR(void);//刷指纹

void Del_FR(void);//删除指纹
		 				    
#endif
