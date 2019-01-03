/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "colormonitor.h"

#include "GlabalVar.h"
#include "stm32f1xx_hal.h"
#include "stm32f10x_type.h"
#include "ADS7816.h"
#include "Termo.h"
#include "stdio.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
ErrorStatus HSEStartUpStatus;
u16 VarValue = 0;
//hal FLASH_Status FlashStatus;

/* Virtual address defined by the user: 0xFFFF value is prohibited */
//hal u16 VirtAddVarTab[NumbOfVar] = { 0x5555, 0x6666, 0x7777 };
unsigned char cun2, kd = 20, mmc_command = 0, mmc_respond, tempcommand;
unsigned long int hpriod;
unsigned long int avrage[6], tempreture[5];

unsigned char echostring[100];
unsigned int variable[10], recive, lowr, b0, b1, b2, b3, b4, b5, ruler2, in[8],
timebase, passcun;
unsigned char cul, row, keycode, s, number, oldpage, line, id[3], id_counter,
timediv, chanel;
bool lockkey, lockkey1, keypress, refresh, numberchange, action, automode,

finish, timeflag, autokey2, refresh2, ehteyatkey = 0, semiauto2, auto3,
mmc_key_active;
char temprecive, imagekey, timefull, hitreal, keywait,keycodelog;
unsigned char perv1, perv2, perv3, perv4, perv5, perv6, perv7, perv8, perv9,
perv10, perv11, perv12, perv13, perv14, perv19;
unsigned char speedehteyat, speedv1, speedv2, speedv3, speedv4, speedv5,

speedv6, speedv7, speedv8, speedv9, speedv10, speedv11, speedv12, speedv13,
speedv14, speedv19, timemax;
unsigned int ruler3p1, ruler3p2, ruler3p3, ruler3p4, ruler1p7, ruler1p4,

ruler1p5, ruler1p6, ruler2p4, ritime1, ritime2, ritime3, oiltime, totaltime,
timep, tedad;
unsigned char delay1, delay2, delay3, delay4, delay5, wait, pnum, timer1,
s4051 = 0, c4051 = 3;
bool silehteyat, mkeshact, pbri, pmri, pbri1, pmri1, mode, pepm1, pepm,

hightemp, timestart, govein, goveout, darbaz, darbasteh, auto4, fffk, numin;
/*flash*/unsigned char cyclea[] = { 14, 8, 1, 2, 3, 10, 9, 0, 11, 5, 6, 12, 4,
		6, 14, 7, 15 };
unsigned char reccun, ristate, bristate, i3old, oldlgr, oldlgf, yekst, tempp;
unsigned char rx_wr_index, rx_rd_index, rx_counter, outputa = 0, outputb = 0,
		outputc = 0, read1, read2, read3, speed, per, color_refresh;
int alaki2, errorc;
// This flag is set on USART Receiver buffer overflow
int rx_buffer_overflow, systemonleft, systemonright, beepcounter;
bool pmc, pmc1, pmo, pmo1, puf1, puf = 0, pub = 0, pub1, pgb = 0, pgb1, peb1,
		peb = 0, pef1, pef = 0, pco1, pco, pci1, pci = 0, rollswitch = 0,
		cycleex, mavad2, tempr1, oldi8;
int page, waitfortemp = 100, timer, timer2, hitok, ritime;
unsigned int ruler1, ruler1a, ruler3;
unsigned long int temptemp;

unsigned int secend, ruler1p2, ruler1p3, ruler1p1, ruler1m, ruler2m, ruler3m,
ruler2p1, ruler2p2, ruler2p3, oiltemp, delaycun;
unsigned char secbase, n, j, d2, memseg = 10, errorcode = 0, staten, oilnumber =
		0;
int z, x, y, x1, y1, m, v1 = 50, k, a, q, u, t, c, x1line = 15, x2line = 30,
		y1line = 16, y2line = 32, line2, conter;
unsigned long int temp;
unsigned char led, state, state2, delaytaghe;
bool temp111, pri1, pri, automatic, semiauto, protection, offbit, moto, oil,

hitteron, autokey, lock, lock1, hit1ok, hit2ok, hit3ok, hit4ok, hit5ok, lowtemp,
oilcycle, refresh3;
char soundf;

unsigned char outon[6], hss[] = { 10, 5, 1, 1, 1 }, selz[] = { 99, 85, 80, 60 },
		zone;
unsigned int add[] = { 5, 2, 5, 2, 1 }, mmc, mmcflag, justtest;
unsigned long int aaa;
unsigned long int hz[] = { 75, 80, 99, 100 };
unsigned int var[15][9], tempgo;
unsigned char sound[1][1], kvar, kflag, speed2, kkkk = 200;
//=========================================end of variables====================
//========================================constant variable====================

/*flash*/unsigned int dc[] = { 0, 0, 21, 21, 14, 12, 17, 12, 18, 18, 20, 10, 6,
		6, 5, 2 };

//========================================eeprom variables=====
/* eeprom*/unsigned long int maxcomponent;
/* eeprom*/unsigned long int t1cul, t2cul, t3cul, t4cul, t5cul;
/* eeprom*/int pass1, pass2, pass3, passtry, lock2;
/* eeprom*/int lockpos = 150, molpos = 170, s2pos = 250, s1pos = 700, limitrmo =
		800;
/* eeprom*/unsigned char lockspeed = 60, lockpre = 80, molprop = 60, molpros =
		120, s2 = 70, p2 = 60, s1 = 120, p1 = 60;
/* eeprom*/unsigned char memvar[132][24];
/* eeprom*/unsigned int maxruler1 = 255, maxruler2 = 300, maxruler3 = 300,
		marrid, whour = 100, ccunter;
/* eeprom*/unsigned int hour, hour1;

/*eeprom */unsigned int var2[16][22];

//=========================eeprom emoulation================================
u32 var_page_address;
u32 var_next_address;
u16 var2i = 16, var2j = 22;
u32 addresspage = 0x08010000; // start address of variable page address oft
//u32 addresspage=0x08011800;// start address of variable page address

char command[30], command_index = 0;
char beep;

int usart_buffer_index;
u8 usart_buffer[usart_buffer_size];

int RS485_buffer_index;
char RS485_buffer[RS485_buffer_size];

int Value;

char tempasd[70];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_SPI2_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM2_Init(void);

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 *
 * @retval None
 */
int main(void) {
	/* USER CODE BEGIN 1 */
	int mADS;
	char h_mADS,l_mADS;
	uint16_t temp1,temp2,temp3;


#define localecho 1
	int gosfand;
	int alaki, i3i;
	char memactive;
	/*st float */float cul1, var1, var2a, cul;
	int kkkk = 200, i;

	char out1[2] ={0x55,0x55};
	char out2[2] ={0xaa,0xaa};

	char tempasd[30];
	u16 stt;
	u32 Address = 0x0801040f;
	/* USER CODE END 1 */

	/* MCU Configuration----------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();
	/* USER CODE BEGIN Init */
	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals*/
	MX_GPIO_Init();
	MX_USART1_UART_Init();
	MX_USART2_UART_Init();
	MX_USART3_UART_Init();

	MX_TIM3_Init();
	MX_TIM1_Init();
	MX_TIM2_Init();
	/* USER CODE BEGIN 2*/
	Init_ADS7816();
	Init_Termo();
	HAL_TIM_Base_Start(&htim1);

	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
	HAL_TIM_Base_Start_IT(&htim1);
	HAL_TIM_Base_Start_IT(&htim2);

	jtag_Disable();

	__HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);
	__HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);
	__HAL_UART_ENABLE_IT(&huart2, UART_IT_TXE);
	MX_SPI2_Init();
//__HAL_uart_enable
//while(1){
    	// USART1->DR=55;
    	// HAL_Delay(500);

  //   }
	stt = 23;

	//send_string("br9600 delay\n");
	Value = 0;
	//halmemload();
	//FLASH_Unlock();

	goto ii;
	//oftsend_string("step1\n");
	//oft	FLASH_ProgramHalfWord((Address), 0xff0f);
	//FlashStatus = FLASH_ProgramHalfWord(Address + 2, VirtAddress);
	//oftsend_string("step2\n");
	//oft	stt = (*(vu16*)(Address));
	sprintf(tempasd, "\n%x", stt);

	send_string(tempasd);

	//oft	FLASH_ErasePage(Address+1);

	//oft	stt = (*(vu16*)(Address));
	sprintf(tempasd, "\n%x", stt);

	send_string(tempasd);
	ii:






	setChannel_Termo(0);
	HAL_Delay(220);
	temp1 = read_Temp();

	setChannel_Termo(1);
	HAL_Delay(220);
	temp2 = read_Temp();
 sprintf(tempasd,"termo:%c%d   %c%d\r\n",9,temp1,9,temp2);
	HAL_UART_Transmit(&huart1,tempasd,30, 500);


	mADS =read_ADS7816S(2);
	l_mADS = mADS & 0xff;
	h_mADS = mADS/256;
	sprintf(tempasd,"ruller: %x,%x\r\n",h_mADS,l_mADS);
	HAL_UART_Transmit(&huart1,tempasd, 10, 100);
	HAL_Delay(1000);


	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);




		HAL_SPI_Transmit(&hspi2, out1, 2, 100);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
		HAL_Delay(500);
		HAL_SPI_Transmit(&hspi2, out2, 2, 100);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
		HAL_Delay(500);

	send_string("ver1.20180913.0.0");

    for(i=0;i<100;i++)
    {

	echo"\ndata at 1st page is :%x",*(vu16*)(addresspage),*(vu16*)(addresspage+(i*2)));
	sendecho;
     }
	/*
	 delay_ms(400);
	 int imehdi;

	 for(imehdi=0;imehdi<250;imehdi++){inc();delay_ms(10);
	 echo"imehdi :%d",imehdi);
	 sendecho;


	 }*/
	//vartomem();
	//for(stt=0;stt<280;stt++){update_var(stt,5);}
	// *ReadData = (*(vu16*)(Address - 2));
	//memload();
	//for(stt=0;stt<122;stt++){update_var(0,stt);}
	//while(1);
	//st cs=0;
	//st   UDR0=0;
	if (maxcomponent != 0)
		maxcomponent = 0;
	page = 0;
	alaki = 2000;
	write_ppi(0x80, 0x33);
	write_ppi(0x55, 0x30);
	write_ppi(0x0, 0x31);
	write_ppi(0xff, 0x32);
	write_ppi(0x9b, 0x03);	//initialize ppi for all port is input
	write_ppi(0, 0x60);
	write_ppi(0, 0x61);
	write_ppi(outputa, 0x30);
	write_ppi(outputb, 0x31);
	write_ppi(outputc, 0x32);

	imagekey = 255;
	semiauto = 0;
	calibration();
	oldpage = 1;
	page = 0;
	if (marrid != 1) {
		marrid = 1;
		//hal //st defalt();
	}
	temp = pass3 ^ 0xa55;
	mode = 0;
	oil = 0;
	alaki2 = 30;
	cun2 = 50;

	ftable();
	memactive = 1;
	oilnumber = 0;
	oilcycle = 1;
	oiltime = 0;
	if (pass1 == 3333)
		lock = 1;
	//oil = oil;
	protection = 1;
	semiauto = 0;
	automatic = 0;
	moto = 0;
	hitteron = 0;
	if (!i19)
		errorcode = 18;
	//oil = oil;
	protection = 1;
	semiauto = 0;
	automatic = 0;
	if (!i19)
		errorcode = 18;

	colorm();
	//while(1){RelayToggle1 RelayToggle delay_ms(10);}
	//farzin sendchar2('a');

	//DACDATA_HIGH ;delay_ms(50); DACDATA_LOW;delay_ms(20);}
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {
		/* USER CODE END WHILE */
		if (mmc_key_active && memactive) {
			// mmc_key_active=0;
			// if(comp_calibrate(0)!=100)save_calibrate(0);
			// if(comp_to_mmc(0)!=100)save_to_mmc(0);

			if (mmc_command == SAVE_TO_MMC) {
				//      mmc_respond=save_to_mmc(temp);
				//     if(mmc_respond){if(mmc_respond==2)var2[9][9]=3100;else var2[9][9]=3101;mmc_command=0;temp=0;}
				//       else {mmc_command=0;if(temp>1000)temp-=1000;var2[9][9]=temp;temp=0;}
				//       var2[9][9]=temp;
				//     mmc_command=0;
				//  temp=0;
			}
			if (mmc_command == LOAD_TO_MMC) {
				// mmc_respond=load_from_mmc(temp);
				// if(mmc_respond)var2[9][8]=3100+mmc_respond;else {var2[9][8]=temp;temp=0;}
				// mmc_command=0;
				// mmc_command=0;
				// var2[9][8]=temp;
				// `temp=0;

			}

		}

		if (var2[7][16] != oil)
			var2[7][16] = oil;
		if (maxcomponent > 120000)
			maxcomponent = 0;
		if (!i8) {
			if (errorc < 210)
				errorc++;

		} else
			errorc = 0;
		if (errorc > 200)
			errorcode = 6;

		if (page) {
			if (page != 9)
				if (temp > 999) {
					if (page != 11)
						temp = 0;
					if (!lockkey && !lockkey1)
						monitorn();
				}

		}

		/*     if(readflag>0){
		 if(kflag==1)
		 {
		 kflag=0;
		 SPCR|=0x50;
		 sendmmc(blocknumber);
		 blocknumber+=512;
		 //    if(blocknumber>=(firstblock[0]+(dx)))blocknumber=firstblock[0];
		 }
		 if(blocknumber>firstblock[0]+(readflag)*dx){readflag=0;TCCR0=0x00;}
		 }

		 */
		if (page == 13 || page == 14)
			if (!lockkey && !lockkey1)
				monitorn();
		if (keycode == 20 || keycode == 28)
			if (lockkey)
				if (keywait) {
					keywait--;
					if (!keywait)
						lockkey = 0;
				}
		if (page == 2 || page == 3) {

			putdigit_xy_space(23, 3, ruler1m, 0, 4);

		}
		if (page == 5) {
			putdigit_xy_space(23, 3, ruler2m, 0, 4);

		}
		if (page == 6) {

			putdigit_xy_space(23, 3, ruler2m, 0, 4);
		}
		if (!page) {

			putdigit_xy_space(1, 6, per, 0, 2);
			putdigit_xy_space(8, 6, speed, 0, 2);
			if (state2 == 4 || state2 == 3 || state2 == 5)
				putdigit_xy(1, 37, ritime, 1);

			else if (state2 == 14)
				putdigit_xy(1, 37, timefull, 0);
			else
				putdigit_xy(1, 37, timer, 1);

			putdigit_xy_space(1, 20, ruler1m, 0, 3);
			putdigit_xy_space(16, 20, ruler2m, 0, 3);
			putdigit_xy_space(16, 37, timemax, 1, 3);

			if (errorcode && !page)
				showpic_xy(errorcode, 0, 0);
			//if(temp)showpic_xy(temp,0,0);
			else if (state2 == 8 && timer) {
			} else {
				if (state2 && !page && state2 < 14) {
					showpic_xy(25 + state2, 15, 0);
					if (state2 == 4 && memseg < 4)
						putdigit_xy(20, 6, memseg, 0);
				}
			}

		}

		if (oil)
			state2 = 0;
		if (protection && !lockkey && state2) {
			state2 = 0;
			monitorn();
		}
		gosfand = var2[3][0] * 10;
		if (state == 5 && ritime > gosfand && !mavad2) {
			errorcode = 13;
			speed = 0;
			per = 0;
			pbri1 = 0;
			clrout6;
			clrout3;
			clrout17;

			//           protection=0;semiauto=0;automatic=0;oil=1; }
		}

		if (fffk) {

			if (!LGR && oldlgr) {
				if (var[9][8])
					if (semiauto || automatic) {
						auto4 = 1;
						fffk = 0;
					}
				oldlgr = LGR;
			} else
				oldlgr = LGR;
			if (!LGF && oldlgf) {
				if (var[9][7])
					if (semiauto || automatic) {
						auto4 = 1;
						fffk = 0;
					}
				oldlgf = LGF;
			} else
				oldlgf = LGF;
		} else {
			oldlgr = LGR;
			oldlgf = LGF;

		}

		if (!state) {
			if (auto4) {
				auto4 = 0;
				auto3 = 1;
			}

		}

		rollswitch = 0;
		if (!rollswitch) {
			//       ruler2=in[1];
			//     ruler1=in[0];
		} else {
			if (!LMO) {
				ruler1a = 1023;
			} else {
				if (!LMC) {
					ruler1a = 0;
				} else
					ruler1a = var[1][5] + 1;
			}
			if (outputa & 1)	  //gire basteh
			{
				// if(ruler1=var[0][2]+1;
				if (!i2)
					ruler1a = ruler1p1 - 1;
				if (i3old && !i3)
					ruler1a = ruler1p2 - 1;  //labeyetahriki3
				if (!i3old && i3)
					ruler1a = ruler1p3 - 1;
				//        i3old=i3;

			} else if (output & 2) {
				if (!i5)
					ruler1a = ruler1p5 - 1;
				if (!i4)
					ruler1a = ruler1p6 + 1;

			}
			//ruler1=ruler1a;  movaghat

			i3old = i3;

		}

		passcun++;
		if (passcun == 9999)
			passcun = 0;
		cul = maxruler1 + 1;
		var2a = (cul / 1023) * ruler1;

		ruler1m = var2a;

		cul = maxruler3 + 1;
		var2a = (cul / 1023) * ruler3;

		ruler3m = var2a;

		cul = maxruler2 + 1;
		var2a = (cul / 1023) * ruler2;

		ruler2m = var2a;
		// speed=speedv1;
		// per=perv1;

		if (!lockkey)
			hitreal = 0;
		// if(!timer && !finish){timer=10; finish=1;}

		//error sathroghan
		if (!i21)
			clrout24;
		if (!i19) {
			moto = 0;
			if (automatic || semiauto) {
				automatic = 0;
				semiauto = 0;
				errorcode = 18;
			}
		}
		//roghankari
		if (oilcycle) {
			if (oiltime > var[9][1] * 10) {
				clrout19;
				oilcycle = 0;
			} else
				setout19;
		} else
			clrout19;
		if (oilnumber == var[9][0]) {
			oilnumber = 0;
			oilcycle = 1;
			oiltime = 0;
		}
		//ghateshomar
		if (ccunter > var[9][3]) {
			if (oil)
				errorcode = 21;
		}
		//full auto
		if (i24 && (automatic || semiauto)) {
			automatic = 0;
			semiauto = 0;
			protection = 1;
		}
		//saat kar
		if (secbase >= 10) {
			//                              if(!beepcounter)beep=0;else beepcounter--;

			if (!i24)
				secend++;
			secbase = 0;
			if (state == 14)
				timefull++;
			else
				timefull = 0;
			//                            monitorn();
			//                              monitorn();
			//  if(statetotaltime
			if (errorcode) {
				beep = 1;
				beepcounter = 40;
			}

			if (secend == 3600) {
				secend = 0;

				hour++;
				hour1++;
				if (!lock2)
					maxcomponent += 12;

				// var[9][5]++;
				// tempgo=var2[4][9];
				if (hour == var2[9][5]) {
					errorcode = 19;
					protection = 0;
					semiauto = 0;
					automatic = 0;
					//oil = oil;
				}
				if (hour > var2[9][4])
					hour = 0;

			}
		}

		if (hour == var2[9][4] && oil)
			errorcode = 19;
		//   khataye taviz roghan
		if (automatic)
			semiauto = 1;
		if (auto3) {
			if (semiauto && !automatic) {
				semiauto2 = 1;
				auto3 = 0;
				finish = 1;
				state = 0;
				lockkey1 = 0;
				timer = 0;
			}

		}
		if (!automatic && !semiauto)
			auto3 = 0;
		/*  if(auto3 )
		 {

		 if(automatic)
		 {semiauto2=1;}
		 else
		 if(semiauto){semiauto2=1;auto3=0;}
		 else
		 auto3=0;
		 }
		 */
		if (!semiauto)
			semiauto2 = 0;
		if (alaki2 < 0) {
			if (hitteron)
				tempctl();	                               //st else PORTE=0xff;
			alaki2 = 100;
			avrage[0] += in[3];
			avrage[1] += in[4];
			avrage[2] += in[5];
			avrage[3] += in[6];
			avrage[4] += in[7];

			if (!cun2--) {
				if (page == 0 && !lockkey && !lockkey1)
					monitorn();
				cun2 = 50;
			}

			calibration();
			tempreture[0] = (avrage[0]/*st/50*/) + t1cul - 200;
			if (tempreture[0] > 1500)
				tempreture[0] = 0;
			tempreture[1] = (avrage[1]/*st/50*/) + t2cul - 200;
			if (tempreture[1] > 1500)
				tempreture[1] = 0;
			tempreture[2] = (avrage[2]/*/50*/) + t3cul - 200;
			if (tempreture[2] > 1500)
				tempreture[2] = 0;
			tempreture[3] = (avrage[3]/*/50*/) + t4cul - 200;
			if (tempreture[3] > 1500)
				tempreture[3] = 0;
			tempreture[4] = (avrage[4]/*/50*/) + t5cul - 200;// st as sampleing speed is too slow
			if (tempreture[4] > 1500)
				tempreture[4] = 0;
			avrage[0] = 0;
			avrage[1] = 0;
			avrage[2] = 0;
			avrage[3] = 0;
			avrage[4] = 0;
			//oft if(page==0 && !lockkey && !lockkey1) monitorn();
			//

		}

		alaki--;
		if (protection || oil)
			if (!lockkey && errorcode) {
				errorcode = 0;
				monitorn();
			}
		if (!alaki) {

			alaki = 501;
			temprecive = 5;
			if (page == 0)
				refresh = 1;

		}

		// if(keypress)
		//            {refresh=1;keypross();monitorn();keypress=0;    if(protection )if(!lockkey)errorcode=0;  ftable();}

		//if(keypress)
		//            {refresh=1;keypross();monitorn();keypress=0;    if(protection )if(!lockkey)errorcode=0;  ftable();}

		if (automode)
			statecontroll();

		cycleex = 1;
		cycle();
		cycleex = 0;

		led = automatic * 4 + 8 * semiauto + 128 * moto + oil * 2
				+ protection * 32 + hitteron * 64 + ehteyatkey * 16
				+ ehteyatkey;
		if (page)
			limit();
		if (refresh) {
			monitorn();
			refresh = 0;
		} else
			controll();

		if (refresh2 && !page) {
			refresh2 = 0;
			if (!lockkey && !lockkey1)
				monitorn();
		}

		if (refresh3) {
			monitorn();
			refresh3 = 0;
			ftable();
			calibration();
		}

		//PWR_EnterSleepMode();

		//hal delay_ms(1000);
		/* USER CODE BEGIN 3 */

	}
	/* USER CODE END 3 */

}



/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {

	RCC_OscInitTypeDef RCC_OscInitStruct;
	RCC_ClkInitTypeDef RCC_ClkInitStruct;

	/**Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = 16;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	/**Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	/**Configure the Systick interrupt time
	 */
	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 1000);

	/**Configure the Systick
	 */
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

	/* SysTick_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* SPI2 init function */
static void MX_SPI2_Init(void) {

	/* SPI2 parameter configuration*/
	hspi2.Instance = SPI2;
	hspi2.Init.Mode = SPI_MODE_MASTER;
	hspi2.Init.Direction = SPI_DIRECTION_1LINE;
	hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
	hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
	hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
	hspi2.Init.NSS = SPI_NSS_SOFT;
	hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
	hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
	hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hspi2.Init.CRCPolynomial = 10;
	if (HAL_SPI_Init(&hspi2) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

}

/* TIM1 init function */
static void MX_TIM1_Init(void) {

	TIM_ClockConfigTypeDef sClockSourceConfig;
	TIM_MasterConfigTypeDef sMasterConfig;
	TIM_OC_InitTypeDef sConfigOC;
	TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig;

	htim1.Instance = TIM1;
	htim1.Init.Prescaler = 8000;
	htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim1.Init.Period = 1000;
	htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim1.Init.RepetitionCounter =0;
	htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim1) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	if (HAL_TIM_OC_Init(&htim1) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sConfigOC.OCMode = TIM_OCMODE_TIMING;
	sConfigOC.Pulse = 500;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
	sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	if (HAL_TIM_OC_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
	sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
	sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
	sBreakDeadTimeConfig.DeadTime = 0;
	sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
	sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
	sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
	if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

}

/* TIM2 init function */
static void MX_TIM2_Init(void) {

	TIM_ClockConfigTypeDef sClockSourceConfig;
	TIM_MasterConfigTypeDef sMasterConfig;
	TIM_OC_InitTypeDef sConfigOC;

	htim2.Instance = TIM2;
	htim2.Init.Prescaler = 8000;
	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim2.Init.Period = 45;
	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
	if (HAL_TIM_Base_Init(&htim2) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	if (HAL_TIM_OC_Init(&htim2) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sConfigOC.OCMode = TIM_OCMODE_TIMING;
	sConfigOC.Pulse = 250;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if (HAL_TIM_OC_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

}

/* TIM3 init function */
static void MX_TIM3_Init(void) {

	TIM_ClockConfigTypeDef sClockSourceConfig;
	TIM_MasterConfigTypeDef sMasterConfig;
	TIM_OC_InitTypeDef sConfigOC;

	htim3.Instance = TIM3;
	htim3.Init.Prescaler = 2;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim3.Init.Period = 1000;
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim3) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	if (HAL_TIM_PWM_Init(&htim3) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 250;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sConfigOC.Pulse = 500;
	if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sConfigOC.Pulse = 100;
	if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	sConfigOC.Pulse = 750;
	if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_4)
			!= HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

	HAL_TIM_MspPostInit(&htim3);

}

/* USART1 init function */
static void MX_USART1_UART_Init(void) {

	huart1.Instance = USART1;
	huart1.Init.BaudRate = 115200;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart1) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

}

/* USART2 init function */
static void MX_USART2_UART_Init(void) {

	huart2.Instance = USART2;
	huart2.Init.BaudRate =38400;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart2) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

}

/* USART3 init function */
static void MX_USART3_UART_Init(void) {

	huart3.Instance = USART3;
	huart3.Init.BaudRate = 115200;
	huart3.Init.WordLength = UART_WORDLENGTH_8B;
	huart3.Init.StopBits = UART_STOPBITS_1;
	huart3.Init.Parity = UART_PARITY_NONE;
	huart3.Init.Mode = UART_MODE_TX_RX;
	huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart3.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart3) != HAL_OK) {
		_Error_Handler(__FILE__, __LINE__);
	}

}

/** Configure pins as 
 * Analog
 * Input
 * Output
 * EVENT_OUT
 * EXTI
 */
static void MX_GPIO_Init(void) {

	GPIO_InitTypeDef GPIO_InitStruct;

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOD_CLK_ENABLE()
	;
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);

	/*Configure GPIO pin : PB14 */
	GPIO_InitStruct.Pin = GPIO_PIN_14;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @param  file: The file name as string.
 * @param  line: The line in file as a number.
 * @retval None
 */
void _Error_Handler(char *file, int line) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	while (1) {
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
	 tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
