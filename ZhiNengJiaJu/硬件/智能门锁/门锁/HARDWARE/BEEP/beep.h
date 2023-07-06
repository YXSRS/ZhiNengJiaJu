#ifndef __beep_H
#define __beep_H	 
#include "sys.h"
#include "delay.h"


#define BEEP PCout(6)	// BEEP,蜂鸣器接口		   
void BEEP_Init(void);//初始化
		 				    
#endif

