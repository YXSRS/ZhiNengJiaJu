#ifndef __LED_H
#define __LED_H	 
#include "sys.h"

void LED_Init(void);//≥ı ºªØRed_LED  Yellow_LED
void jidianqi(void);
#define ji  PBout(2)
#define Red_LED  PBout(12)
#define Yellow_LED  PBout(13)	
#define Bute_LED  PBout(14)
#endif
