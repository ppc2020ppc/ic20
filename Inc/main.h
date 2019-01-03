/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 ** This notice applies to any and all portions of this file
 * that are not between comment pairs USER CODE BEGIN and
 * USER CODE END. Other portions of this file, whether
 * inserted by the user or by software development tools
 * are owned by their respective copyright owners.
 *
 * COPYRIGHT(c) 2018 STMicroelectronics
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */
#include "stm32f1xx_hal.h"
#include "stm32f10x_type.h"
/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define  usart_buffer_size 40 //actual buffer size = buffer size -1
#define  RS485_buffer_size 40 //actual buffer size = buffer size -1
#define  max_data 100
#define RelayOn {GPIOA->ODR|=(1<<1 );}
#define RelayOff {GPIOA->ODR&=~(1<<1);}
#define RelayToggle {GPIOA->ODR^=(1<<1);}
#define RelayToggle1 {GPIOA->ODR^=(1<<2);}
#define led_on {GPIOA->ODR|=1<<11;}
#define led_off {GPIOA->ODR&=~(1<<11);}
#define led_toggle {GPIOA->ODR^=(1<<11);}

#define DRIVER_RX_DISABLE {GPIOA->ODR|=1<<4;} //low to enable recieving data from driver
#define DRIVER_RX_ENABLE {GPIOA->ODR&=~(1<<4);}
#define DRIVER_TX_ENABLE {GPIOA->ODR|=1<<5;}//HI to enable recieving data from driver
#define DRIVER_TX_DISABLE {GPIOA->ODR&=~(1<<5);}

#define RS485_RX_DISABLE	{GPIOB->ODR|=1<<12;} //low to enable recieving data from driver
#define RS485_RX_ENABLE		{GPIOB->ODR&=~(1<<12);}
#define RS485_TX_ENABLE		{GPIOB->ODR|=1<<13;}//HI to enable recieving data from driver
#define RS485_TX_DISABLE	{GPIOB->ODR&=~(1<<13);}

#define DACDATA_HIGH {GPIOA->ODR|=(1<<7 );}
#define DACDATA_LOW {GPIOA->ODR&=~(1<<7);}
#define DACCLK_HIGH {GPIOA->ODR|=(1<<5 );}
#define DACCLK_LOW {GPIOA->ODR&=~(1<<5);}
#define DACCS_HIGH {GPIOB->ODR|=(1<<1 );}
#define DACCS_LOW {GPIOB->ODR&=~(1<<1);}

#define DS0 ((GPIOA->IDR&(1<<7))>>7) //pa7 ds0
#define DS1 ((GPIOB->IDR&(1<<0))>>0) //pb0 ds1
#define DS2 ((GPIOB->IDR&(1<<1))>>1) //pb1 ds2
#define DS3 ((GPIOA->IDR&(1<<6))>>6) //pa6 ds3
#define DS4 ((GPIOB->IDR&(1<<14))>>14) //pb14 ds4
#define DS5 ((GPIOB->IDR&(1<<15))>>15) //pb15 ds5
#define DS6 ((GPIOB->IDR&(1<<3))>>3) //pb3 ds6

#define PULSE_HI {GPIOB->ODR|=(1<<8 );}
#define PULSE_LOW {GPIOB->ODR&=~(1<<8);}
#define PULSE_TOGGLE {GPIOB->ODR^=(1<<8 );}
#define DIRECTION_HI {GPIOB->ODR|=(1<<9 );}
#define DIRECTION_LOW {GPIOB->ODR&=~(1<<9);}
#define DIRECTION_TOGGLE {GPIOB->ODR^=(1<<9 );}

#define Mosfet1On {GPIOB->ODR|=(1<<4 );}
#define Mosfet1Off {GPIOB->ODR&=~(1<<4);}
#define Mosfet1Toggle {GPIOB->ODR^=(1<<4 );}
#define Mosfet2On {GPIOB->ODR|=(1<<6 );}
#define Mosfet2Off {GPIOB->ODR&=~(1<<6);}
#define Mosfet2Toggle {GPIOB->ODR^=(1<<6 );}
#define Mosfet3On {GPIOB->ODR|=(1<<7 );}
#define Mosfet3Off {GPIOB->ODR&=~(1<<7);}
#define Mosfet3Toggle {GPIOB->ODR^=(1<<7 );}

#define Key ((GPIOA->IDR&(1<<12))>>12) //pa12 input key
#define MaxPosition 500
//===============================defines=============
#define rollerpos 0
#define speed1    1
#define pre       2
#define output    4

#define cs PORTC.2
#define rd PORTC.2
#define cd PORTC.2
#define wr PORTC.2
//#define lcdbus PORTD
#define latch PORTD.4
/*
 #define cs PORTD.5
 #define rd PORTB.5
 #define cd PORTB.7
 #define wr PORTB.6
 #define lcdbus PORTC
 #define latch PORTD.4
 */
#define i9 (read2&0x1)
#define i10 (read2&0x2)
#define i11 (read2&0x4)
#define i12 (read2&0x8)
#define i13 (read2&0x10)
#define i14 (read2&0x20)
#define i15 (read2&0x40)
#define i16 (read2&0x80)
#define i17 (read3&0x1)
#define i18 (read3&0x2)
#define i19 (read3&0x4)
#define i20 (read3&0x8)
#define i21 (read3&0x10)
#define i22 (read3&0x20)
#define i23 (read3&0x40)
#define i24 (read3&0x80)
#define i1 (read1&0x1)
#define i2 (read1&0x2)
#define i3 (read1&0x4)
#define i4 (read1&0x8)
#define i5 (read1&0x10)
#define i6 (read1&0x20)
#define i7 (read1&0x40)
#define i8 (read1&0x80)

#define LMC i1
#define LSB  i10
#define LMO i4
#define  LMC2 i2
#define  LMS i3
#define  LMO3 i5
#define  LI i8
#define  RULER_SELECT i9
#define  RULER_SELECT1 i10
#define  LgI i15
#define  LgO i16
#define  LPO i17
#define  LPL i18
#define  LAL i19
#define  HET i20
#define   LGO i21
// #define  LGL i22
//#define  LGF i23
#define  MOTON i24

//#define i4 (read2&0x10)
//#define i5 (read2&0x8)
//#define i6 (read3&0x20)
//#define i7 (read3&0x10)
//#define i8 (read3&0x1)
//#define i9 (read3&0x2)
#define LUF i6 //(read3&0x4)
//#define i11 (read3&0x8)
#define LUB i7
#define LEF i11           //i11 bood
//#define i14 (read2&0x4)
//#define LEB i12
//#define i16 (read3&0x80)
//#define i17 (read1&0x1)
//#define i18 (read1&0x2)
#define LCO i14
#define LCI  i13// (read1&0x4)
#define LGR i22
//#define i22 (read1&0x40)
#define LGF i23
//st #define beep PORTD.0
//#define i24 (read1&0x10)

#define LEB  ((i12 && RULER_SELECT1) || (ruler3p4<ruler3 && !RULER_SELECT1))

#define setout1 outputa=outputa|1
#define setout2 outputa=outputa|2
#define setout3 outputa=outputa|4
#define setout4 outputa=outputa|8
#define setout5 outputa=outputa|16
#define setout6 outputa=outputa|32
#define setout7 outputa=outputa|64
#define setout8 outputa=outputa|128
#define setout9 outputb=outputb|1
#define setout10 outputb=outputb|2
#define setout11 outputb=outputb|4
#define setout12 outputb=outputb|8
#define setout13 outputb=outputb|16
#define setout14 outputb=outputb|32
#define setout15 outputb=outputb|64
#define setout16 outputb=outputb|128
#define setout17 outputc=outputc|1
#define setout18 outputc=outputc|2
#define setout19 outputc=outputc|4
#define setout20 outputc=outputc|8
#define setout21 outputc=outputc|16
#define setout22 outputc=outputc|32
#define setout23 outputc=outputc|64
#define setout24 outputc=outputc|128

#define clrout1 outputa=outputa&0xfe
#define clrout2 outputa=outputa&0xfd
#define clrout3 outputa=outputa&0xfb
#define clrout4 outputa=outputa&0xf7
#define clrout5 outputa=outputa&0xef
#define clrout6 outputa=outputa&0xdf
#define clrout7 outputa=outputa&0xbf
#define clrout8 outputa=outputa&0x7f
#define clrout9 outputb=outputb&0xfe
#define clrout10 outputb=outputb&0xfd
#define clrout11 outputb=outputb&0xfb
#define clrout12 outputb=outputb&0xf7
#define clrout13 outputb=outputb&0xef
#define clrout14 outputb=outputb&0xdf
#define clrout15 outputb=outputb&0xbf
#define clrout16 outputb=outputb&0x7f
#define clrout17 outputc=outputc&0xfe
#define clrout18 outputc=outputc&0xfd
#define clrout19 outputc=outputc&0xfb
#define clrout20 outputc=outputc&0xf7
#define clrout21 outputc=outputc&0xef
#define clrout22 outputc=outputc&0xdf
#define clrout23 outputc=outputc&0xbf
#define clrout24 outputc=outputc&0x7f

#define SAVE_TO_MMC 1
#define LOAD_TO_MMC 2
#define  echoon 1
#define echo if(echoon && localecho)sprintf(echostring,
#define sendecho if(localecho)send_string(echostring);
# define PageLimit 30	  // memory page limit number of available memory to save varable . for each mold




extern unsigned char cun2, kd, mmc_command, mmc_respond, tempcommand;
extern unsigned long int hpriod;
extern unsigned long int avrage[6], tempreture[5];

extern unsigned char echostring[100];
extern unsigned int variable[10], recive, lowr, b0, b1, b2, b3, b4, b5, ruler2,
in[8], timebase, passcun;
extern unsigned char cul, row, keycode, s, number, oldpage, line, id[3],
id_counter, timediv, chanel;
extern bool  lockkey, lockkey1, keypress, refresh, numberchange, action,

automode, finish, timeflag, autokey2, refresh2, ehteyatkey, semiauto2,
auto3, mmc_key_active;
extern char temprecive, imagekey, timefull, hitreal, keywait,keycodelog;
extern unsigned char perv1, perv2, perv3, perv4, perv5, perv6, perv7, perv8,
perv9, perv10, perv11, perv12, perv13, perv14, perv19;
extern unsigned char speedehteyat, speedv1, speedv2, speedv3, speedv4, speedv5,

speedv6, speedv7, speedv8, speedv9, speedv10, speedv11, speedv12, speedv13,
speedv14, speedv19, timemax;
extern unsigned int ruler3p1, ruler3p2, ruler3p3, ruler3p4, ruler1p7, ruler1p4,

ruler1p5, ruler1p6, ruler2p4, ritime1, ritime2, ritime3, oiltime, totaltime,
timep, tedad;
extern unsigned char delay1, delay2, delay3, delay4, delay5, wait, pnum, timer1,
s4051, c4051;
bool silehteyat, mkeshact, pbri, pmri, pbri1, pmri1, mode, pepm1, pepm,

hightemp, timestart, govein, goveout, darbaz, darbasteh, auto4, fffk, numin;
/*flash*/extern unsigned char cyclea[];
extern unsigned char reccun, ristate, bristate, i3old, oldlgr, oldlgf, yekst,
tempp;
extern unsigned char rx_wr_index, rx_rd_index, rx_counter, outputa, outputb,
outputc, read1, read2, read3, speed, per, color_refresh;
extern int alaki2, errorc;
// This flag is set on USART Receiver buffer overflow
extern int rx_buffer_overflow, systemonleft, systemonright, beepcounter;
extern bool pmc, pmc1, pmo, pmo1, puf1, puf, pub, pub1, pgb, pgb1, peb1, peb,
pef1, pef, pco1, pco, pci1, pci, rollswitch, cycleex, mavad2, tempr1,
oldi8;
extern int page, waitfortemp, timer, timer2, hitok, ritime;
extern unsigned int ruler1, ruler1a, ruler3;
extern unsigned long int temptemp;

extern unsigned int secend, ruler1p2, ruler1p3, ruler1p1, ruler1m, ruler2m,
ruler3m, ruler2p1, ruler2p2, ruler2p3, oiltemp, delaycun;
extern unsigned char secbase, n, j, d2, memseg, errorcode, staten, oilnumber;
extern int z, x, y, x1, y1, m, v1, k, a, q, u, t, c, x1line, x2line, y1line,
y2line, line2, conter;
extern unsigned long int temp;
extern unsigned char led, state, state2, delaytaghe;
bool temp111, pri1, pri, automatic, semiauto, protection, offbit, moto, oil,

hitteron, autokey, lock, lock1, hit1ok, hit2ok, hit3ok, hit4ok, hit5ok, lowtemp,
oilcycle, refresh3;
extern char soundf;

extern unsigned char outon[6], hss[], selz[], zone;
extern unsigned int add[], mmc, mmcflag, justtest;
extern unsigned long int aaa;
extern unsigned long int hz[];
extern unsigned int var[15][9], tempgo;
extern unsigned char sound[1][1], kvar, kflag, speed2, kkkk;
//========================================constant variable====================

/*flash*/extern unsigned int dc[];

//========================================eeprom variables=====
/* eeprom*/extern unsigned long int maxcomponent;
/* eeprom*/extern unsigned long int t1cul, t2cul, t3cul, t4cul, t5cul;
/* eeprom*/extern int pass1, pass2, pass3, passtry, lock2;
/* eeprom*/extern int lockpos, molpos, s2pos, s1pos, limitrmo;
/* eeprom*/extern unsigned char lockspeed, lockpre, molprop, molpros, s2, p2,
s1, p1;
/* eeprom*/extern unsigned char memvar[132][24];
/* eeprom*/extern unsigned int maxruler1, maxruler2, maxruler3, marrid, whour,
ccunter;
/* eeprom*/extern unsigned int hour, hour1;

/*eeprom */extern unsigned int var2[16][22];

//=========================eeprom emoulation================================
extern u32 var_page_address;
extern u32 var_next_address;
extern u16 var2i , var2j;
extern u32 addresspage; // start address of variable page address oft
//u32 addresspage=0x08011800;// start address of variable page address

extern char command[30], command_index;
extern char beep;

extern int usart_buffer_index;
extern u8 usart_buffer[usart_buffer_size];

extern int RS485_buffer_index;
extern char RS485_buffer[RS485_buffer_size];

extern int Value;

extern char tempasd[70];

/* ########################## Assert Selection ############################## */
/**
 * @brief Uncomment the line below to expanse the "assert_param" macro in the
 *        HAL drivers code
 */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
extern "C" {
#endif
void _Error_Handler(char *, int);




#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
