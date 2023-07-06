#ifndef __CONFIG_H
#define __CONFIG_H
#include "delay.h"
#include "sys.h"
#include "led.h"
#include "Key.h"
#include "usart.h"	 	
#include "wdg.h"
#include "timer.h"
#include "as608.h"
#include "usart3.h"
#include "zw_user.h"
#include "wkup.h"
#include "oled.h"
#include "stdio.h"
#include "string.h"
#include "count.h"
#include "Servo.h"
void TIM3_Int_Init(u16 arr,u16 psc);
//void Home();
//void Gly();

//ָ��1
unsigned char gImage_Finger1[] = { /* 0X00,0X10,0X41,0X00,0X41,0X00,0X01,0X1B, */

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x40,0x40,0x40,0x40,0x40,
0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0xC0,0x50,0x50,
0x50,0x54,0xAA,0xAA,0xAA,0x2A,0x22,0xE2,0x5A,0x57,0x55,0x55,0x55,0x55,0x55,0x55,
0x54,0x44,0x45,0x55,0x55,0x55,0x55,0x57,0x5F,0x7A,0xAA,0xAA,0xAA,0xA8,0xA8,0xE0,
0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x50,0x4A,0x8A,0xAA,0xB5,0x15,
0x55,0x55,0xAA,0xAA,0xAA,0xAA,0xFE,0x55,0x55,0x55,0x55,0x55,0x95,0x95,0xD5,0xF5,
0xF5,0xF5,0xF5,0xF5,0xD5,0xD5,0x51,0x55,0x55,0x55,0xDF,0xAA,0xAA,0xAA,0xAA,0xFF,
0x55,0x55,0x15,0x28,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0xB0,0xDA,0x6B,0x0D,0x97,0xDE,0x6A,0x2F,
0xBD,0xD7,0xDF,0xFA,0xFB,0xFF,0x7F,0xFD,0xB7,0x37,0x17,0x13,0x5B,0x7B,0x78,0x38,
0x3B,0xFB,0xEB,0xA3,0xA3,0xA3,0xEE,0x7C,0x5F,0xD5,0xB5,0xAF,0x6E,0xCA,0xDE,0xF7,
0xF5,0xAD,0x6B,0xDA,0xD6,0xB4,0x68,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x31,0x1C,0xC6,0x73,0x19,0x8C,0x06,0x9B,
0xED,0x36,0x9B,0xCD,0x77,0x1A,0x0F,0xCD,0xF8,0x1C,0xE6,0xF3,0x9B,0xCD,0x06,0xDE,
0xEA,0x2B,0xAE,0x2A,0xEA,0xDF,0x37,0xED,0x9B,0xF2,0xE6,0x1D,0xF3,0x06,0x3D,0xF3,
0x0E,0xF9,0xC3,0x1E,0xF8,0x01,0x03,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x03,0x7C,0x0F,0xF0,0xBE,0x03,
0x00,0xFE,0x07,0x00,0xFC,0xFF,0x60,0xF3,0x3F,0xF8,0xCF,0x3F,0xF1,0x9F,0x7C,0xE7,
0x9F,0x70,0xCF,0x9E,0x73,0xCF,0xBC,0x63,0xCF,0xB8,0x23,0x08,0x91,0xB7,0x6C,0x5B,
0xD6,0xAC,0x2B,0x3A,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x00,
0x00,0x0F,0x1C,0x00,0x03,0x1F,0x38,0xE3,0x8F,0x1C,0x31,0x67,0xCE,0x99,0xB3,0x26,
0x6D,0xDB,0xB6,0x61,0x53,0xD6,0xA4,0x28,0x5A,0x14,0x35,0x2B,0x0A,0x16,0x05,0x01,
0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x01,0x01,
0x02,0x02,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};

//ָ��2
unsigned char gImage_Finger2[] = { 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x40,0x40,0x40,0x00,0xA0,0xA0,0xA0,0xA0,0xA0,
0xA0,0xA0,0xA0,0xA0,0xA0,0x00,0x40,0x40,0x40,0x80,0x80,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x90,0x48,0x24,
0x96,0x4A,0x69,0xA5,0x94,0x52,0x2A,0xA9,0x95,0x55,0x55,0x54,0x4A,0x2A,0x2A,0x2A,
0xAA,0x2A,0x2A,0x46,0x54,0x55,0x95,0xA5,0x2B,0x4A,0x52,0x94,0x25,0x49,0x12,0x34,
0x2C,0x48,0x90,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xF0,0x0C,0xE3,0x38,0x86,0x73,
0x19,0xC6,0x33,0x0D,0xE6,0x12,0x81,0x60,0x12,0xCA,0x69,0x25,0x95,0x55,0x54,0x54,
0x54,0x54,0x55,0x95,0x25,0x4A,0x92,0x34,0x25,0x19,0x32,0xC4,0x19,0x72,0xC4,0x18,
0xE2,0x0C,0x71,0xC2,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x7F,0x00,0xFF,0x00,
0x00,0x7F,0x00,0xCF,0x00,0x00,0xF7,0x00,0xFF,0x00,0x3C,0x3F,0x00,0xFE,0x01,0xF9,
0x01,0x03,0xFE,0x00,0xFF,0x00,0x01,0x8E,0x00,0xFF,0x00,0xFF,0x00,0x00,0xFF,0x00,
0x73,0xFF,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0xFC,0x80,0x7F,0xC0,
0x00,0xFE,0x00,0x7F,0xC0,0x00,0xE3,0x00,0x3F,0xC0,0x0E,0xF8,0x00,0x3F,0x00,0x1B,
0x70,0x00,0x38,0x80,0x1F,0x70,0x80,0x3F,0xC0,0x1F,0x30,0x03,0x1C,0x20,0x04,0x18,
0x80,0x8F,0x18,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x3C,0xE1,0x8F,0x70,0xC7,
0x1C,0x61,0x8F,0x38,0xC7,0x1C,0x71,0xC7,0x18,0x63,0x8C,0x10,0x02,0x98,0x30,0x46,
0x98,0x33,0x4E,0x99,0x23,0x04,0x01,0xE0,0xF0,0xFC,0xFC,0xFE,0xFE,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0xBF,0xFE,0xFC,0xFC,0xF0,0xE0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,
0x03,0x04,0x19,0x16,0x0C,0x13,0x26,0x48,0x33,0x26,0x48,0x93,0x24,0x48,0x93,0xB6,
0x2C,0x49,0x92,0x24,0x68,0x40,0x00,0x0F,0x3F,0x7F,0x7F,0xFF,0xFF,0xFF,0xFB,0xF7,
0xF7,0xFB,0xFD,0xFC,0xFE,0xFF,0xFF,0xFF,0xFF,0x7F,0x3F,0x0F,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x03,
0x03,0x03,0x03,0x03,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};




//ָ��ʧ��ͼƬ
unsigned char gImage_Finger3[] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x40,0x40,0x40,0x40,
0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x50,0x50,
0x50,0x54,0xAA,0xAA,0xAA,0x2A,0x22,0x22,0x52,0x54,0x55,0x55,0x55,0x55,0x55,0x54,
0x54,0x44,0x45,0x55,0x55,0x55,0x55,0x55,0x56,0x4A,0xAA,0xAA,0xAA,0xA8,0xA8,0xA0,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x50,0x4A,0x8A,0xAA,0xA5,0x15,
0x15,0x55,0xAA,0xAA,0xAA,0xAA,0x6A,0x55,0x55,0x55,0x55,0x55,0x15,0x85,0x95,0xF5,
0xB5,0xB5,0xF5,0xD5,0x55,0x51,0x51,0x55,0x55,0x55,0x54,0xAA,0xAA,0xAA,0xAA,0x40,
0x55,0x55,0x15,0x28,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0xB0,0xDA,0x4B,0x0D,0x95,0xD6,0x4A,0x2A,
0xB5,0xD5,0x5C,0xEA,0xAA,0xFA,0x7D,0xFD,0xB5,0x35,0x15,0x11,0x53,0x73,0x60,0x08,
0x0A,0x8A,0x2A,0x22,0x23,0xA1,0x84,0x54,0x55,0xD5,0xB5,0xAA,0x6A,0xCA,0xDA,0x75,
0xF5,0xAD,0x6A,0x5A,0x96,0xB4,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x31,0x1C,0xC6,0x63,0x19,0x8C,0x06,0x9B,
0xED,0x36,0x9B,0xCD,0x36,0x1A,0x0B,0x05,0xF8,0x0C,0xE6,0x72,0x09,0xC4,0x06,0xDA,
0xEA,0x20,0xA0,0x20,0xCA,0x9A,0x35,0xE5,0x19,0xF2,0xC6,0x19,0xF3,0x06,0x3C,0xE3,
0x0E,0xF9,0x83,0x0E,0xF0,0x01,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x03,0x7C,0x07,0xE0,0xBE,0x03,
0x00,0xFC,0x07,0x00,0xF8,0xFF,0x00,0xF0,0x1F,0x70,0xC7,0x3F,0xE0,0x8F,0x38,0xE7,
0x9F,0x70,0xC7,0x9C,0x71,0xCF,0x98,0x63,0xCE,0x98,0x23,0x08,0x91,0xA7,0x6C,0x5B,
0x56,0xA4,0x2B,0x0A,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x00,
0x00,0x07,0x1C,0x00,0x01,0x0F,0x38,0xE1,0x87,0x1C,0x31,0x63,0x4E,0x99,0x93,0x24,
0x49,0xDB,0xB6,0x21,0x43,0xD6,0xA4,0x28,0x1A,0x14,0x35,0x2B,0x0A,0x12,0xE5,0xF9,
0x1F,0x3C,0x76,0xE2,0xC2,0xC2,0xE2,0x76,0x3C,0x1C,0x38,0xE0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x01,0x01,
0x02,0x02,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x1F,
0x38,0x7C,0x6E,0x47,0x43,0x43,0x47,0x6E,0x7C,0x38,0x3C,0x0F,0x00,0x00,0x00,0x00,};

unsigned char sl[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xF8,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x9E,
0x1C,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0x80,0xC0,0xC0,0xC0,0xE0,0xE0,0xE0,0xE0,0x40,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xDF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x3F,0x3F,0x1F,0x1F,0x1F,0x3F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,
0xC0,0xC0,0xE0,0xF0,0xF0,0xF8,0xF8,0xFC,0xFE,0x7F,0x3F,0x3F,0x1F,0x0F,0x0F,0x07,
0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x07,0x3F,0x7F,0x7F,0x7F,0x3F,0x2F,0x27,0x27,0x33,0x13,0x0D,0x07,0x05,0x40,
0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFB,0xF8,0xF8,
0xFC,0xFE,0xFE,0x7F,0x3F,0x3F,0x1F,0x0F,0x0F,0x07,0x03,0x03,0x01,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,
0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x40,0x00,0x20,0x00,0x00,0x10,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xE3,0xFF,0xFF,0xFF,0x09,0x0F,0xC7,
0xFF,0x5F,0x0F,0x07,0x07,0x07,0x0F,0x09,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x80,0xA0,0x80,0x00,0x00,0x00,0x02,
0x02,0x01,0x01,0x01,0x00,0x00,0x80,0xC0,0xC0,0xE0,0xF0,0xF8,0xF8,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0xE0,0xC0,0xD0,0xE0,0x30,0xB0,0xA0,
0x70,0x48,0x04,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x80,0x80,0x80,0x80,0xC0,0xC0,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x20,0x20,0x20,0x00,0x00,0x04,0x90,0x80,
0x08,0x04,0x00,0x80,0xC0,0xC0,0xE0,0xE0,0xF0,0xF8,0xF8,0xFC,0xFE,0xFE,0xFF,0xFF,
0xFF,0xFF,0xFF,0x04,0x0C,0x1C,0x3E,0x7E,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0xFF,0xFF,0xFF,0x3F,0x1F,0x0F,0x07,0x03,0x01,0x01,
0x03,0x07,0x0F,0x1E,0x3E,0x7C,0x78,0xF8,0xF0,0xE1,0xC0,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x03,0x07,0x05,0x01,0x01,
0x03,0x00,0x00,0x00,0xA4,0x06,0x5E,0x7E,0x02,0x86,0x02,0x05,0x80,0x88,0xC0,0xE0,
0xE1,0xF0,0xF8,0xFC,0xFF,0xFF,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xDF,0xDF,0xFF,0x4F,0x1B,0x07,0x07,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x03,0x07,0x07,0x0F,0x1F,0x1F,0x0F,0x0F,0x07,0x83,0xE0,0x3E,0x0F,0x03,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0xC1,0xC3,
0x47,0x3F,0x9F,0x1F,0x4E,0x4C,0x64,0x60,0x20,0x20,0x20,0x28,0x20,0x00,0x00,0x10,
0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0xF8,0xF8,0xF8,0xFC,0xFC,0xFE,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xDF,0x8F,0x87,
0x87,0xE3,0xC1,0xC1,0xD0,0xE0,0xE0,0xE2,0xE1,0xE0,0xE0,0xE0,0xC0,0x80,0x82,0x00,
0x01,0x3E,0xF8,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x20,0x8A,0x02,
0x00,0x00,0x40,0x00,0x20,0x20,0x20,0x10,0x10,0x18,0x3C,0x0C,0x0E,0x0E,0x0F,0x07,
0x07,0x03,0x03,0x03,0x01,0x00,0x00,0x00,0x04,0x00,0x02,0x00,0x01,0x00,0x01,0x00,
0x00,0x81,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};

unsigned char klt[] = {0x00,0x00,0x00,0x80,0x80,0xF0,0x18,0x0C,0x06,0x02,0x02,0x06,0x06,0x0C,0xF8,0xE0,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xF0,0x7C,0x06,0x03,0x01,0x01,0x01,0x03,0x02,0x0C,0x78,0x40,0xC0,0x80,0x00,0x00,
0x7C,0xE6,0x81,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,
0x0C,0x98,0xF0,0x70,0x38,0x1C,0x0C,0x06,0x06,0x03,0x03,0x03,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x03,0x03,0x03,0x06,0x06,0x0C,0x1C,0x38,0x70,0xD8,0x8C,0x06,
0x03,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xC0,0x73,0x3E,
0x00,0x00,0x01,0x01,0x03,0xE3,0xE3,0xB3,0xB1,0xB1,0x9B,0x9A,0x9E,0x9C,0x9C,0x98,
0x9E,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,
0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9F,0x9E,
0x9C,0x9E,0x9A,0x9B,0x99,0x99,0xB0,0xB0,0xB1,0xE1,0xE1,0x01,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x7F,0xF8,
0x80,0x00,0x00,0xF0,0xFC,0xFC,0xFE,0xFE,0xFE,0xFE,0xFE,0xFC,0xF8,0xF0,0x00,0x00,
0x00,0xC0,0xF8,0xFC,0xFC,0xFE,0xFE,0xFE,0xFE,0xFE,0xFC,0xF8,0xF0,0x00,0x00,0x80,
0xFD,0x7F,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x07,0x1E,0x38,0x73,0xE7,0xCF,0x8F,0x0F,0x1F,0x0F,0x0F,0x0F,0x07,0x7B,0xFC,0xFC,
0xFC,0xFC,0x7B,0x07,0x0F,0x0F,0x1F,0x1F,0x8F,0x8F,0xCF,0x67,0x71,0x38,0x0E,0x07,
0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0xC0,0x60,0x30,0x10,
0x18,0x0C,0x06,0x02,0x83,0xE1,0xFF,0x99,0x91,0x12,0xFE,0x26,0x22,0x24,0x24,0xFC,
0xFC,0x24,0x24,0x22,0x3E,0xFE,0x11,0x91,0x99,0xFF,0xC1,0x83,0x02,0x06,0x0C,0x18,
0x10,0x30,0x60,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xF8,0x8C,0x06,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x01,0x00,0x00,0x00,0xC0,0x60,
0x30,0x1C,0x06,0x03,0x01,0x0F,0x1F,0x70,0x61,0xC1,0xC3,0x83,0x82,0x82,0x82,0x83,
0x83,0x82,0x82,0x82,0x83,0xC1,0xC1,0x61,0x30,0x1F,0x07,0x01,0x03,0x06,0x1C,0x30,
0x60,0xC0,0x00,0x00,0x00,0x01,0x03,0x02,0x02,0x02,0x02,0x02,0x02,0x06,0x9C,0xF8,
0x00,0x01,0x03,0x06,0x06,0x1E,0x38,0x60,0xC0,0xC0,0x80,0xC0,0xC0,0x60,0x3F,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x3F,0x60,0xC0,0xC0,0x80,0xC0,0xC0,0x60,0x38,0x1E,0x06,0x06,0x03,0x01,0x00};

unsigned char klt1[] = {0xE0,0x10,0x08,0x02,0x00,0x00,0x02,0x1C,0x20,0xC0,0xE0,0xE0,0xF0,0xF0,0xF0,0xF0,
0xF0,0xF0,0xF0,0xF0,0xE0,0xE0,0xC0,0x20,0x1E,0x01,0x01,0x81,0x02,0x0C,0x88,0x70,
0x00,0x01,0x09,0x0D,0x0D,0x0D,0x0E,0xFE,0x0F,0xCF,0xEF,0xFF,0xFF,0xEF,0xEF,0x0F,
0x0F,0xEF,0xEF,0xFF,0xEF,0xEF,0x8F,0x0F,0xFE,0x0F,0x0C,0x0C,0x0C,0x08,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x40,0x23,0x15,0x9B,0x93,0x53,0xE3,0x45,0x4E,
0x4E,0x45,0xE3,0x53,0x93,0x9B,0x14,0x23,0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x00,
0x0E,0x10,0x01,0x41,0x81,0x80,0x80,0x38,0x06,0x01,0x01,0x06,0x09,0x09,0x11,0x11,
0x11,0x11,0x09,0x09,0x06,0x01,0x01,0x06,0x38,0x80,0x80,0x81,0x41,0x01,0x10,0x0E};
int err = 0;

#endif
