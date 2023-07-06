#ifndef _KEY_H
#define	_KEY_H
#include "sys.h"


#define KEY1 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11)//读取按键0
#define KEY2 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12)//读取按键0
#define KEY3 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15)//读取按键0



//#define KEY0 PEin(4)
//#define KEY1 PEin(3)
//#define KEY2 PEin(2)
#define WK_UP PAin(0)

//#define KEY0_PRES	1
//#define KEY1_PRES	2
//#define KEY2_PRES	3
//#define WKUP_PRES	4

void Key_Init(void);//初始化
u8 KEY_Scanf(void);

#endif
