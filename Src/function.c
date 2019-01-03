/*
 * function.c
 *
 *  Created on: ? Ø¯? ???? Ù‡â€�.Ø´.
 *      Author: pr
 */

#include "stm32f1xx_hal.h"
#include "function.h"
#include "GlabalVar.h"
#include "colormonitor.h"
#include "main.h"
#include "stdio.h"


void fordelay(int i)
{
	int d;
for(d=0;d<i;d++);
}
void FLASH_ErasePage(u32 address){
	__disable_irq();
	FLASH_PageErase(address);
	CLEAR_BIT(FLASH->CR,(FLASH_CR_PER));
	fordelay(500);
	__enable_irq();
}
void FLASH_ProgramHalfWord(u32 address, int data)
{
//#define localecho 1
//	HAL_StatusTypeDef status1;

	__disable_irq();
//HAL_FLASH_Unlock();

HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD,address,data );
//	FLASH_Program_HalfWord(address, data);

//HAL_FLASH_Lock();
//fordelay(1000);
__enable_irq();
	//if(status1)echo "error"
	//	sendecho;


}


int getkey (void){



	return 0;
}
int getkey2 (void){
	return 0;
}

void send_string(char *str)
{
	HAL_UART_Transmit(&huart1, str, strlen(str), 200);
}


void jtag_Disable(void) {
	RCC->APB2ENR |= 1;
	AFIO->MAPR &= ~((long int) (3 << 24));
	AFIO->MAPR |= (long int) (1 << 26);
}

void controll(void) //ok1
{

	char ccc;
	unsigned long int ttttt;
	//st bit tempb=0;
	char tempb = 0; //st

	for (ccc = 0; ccc < 5; ccc++) {
		if (ehteyatkey)
			ttttt = var2[8][16] << 1;
		else
			ttttt = var[8][ccc] << 1;

		if (tempreture[ccc] < ttttt) {
			zone = 0;
			aaa = tempreture[ccc];
			aaa = aaa * 100;
			while (aaa > (hz[zone] * ttttt))
				zone++;
			outon[ccc] = selz[zone];

		} else
			outon[ccc] = 0;

		if (var[8][0] > var[8][6])
			temptemp = (var[8][0] - var[8][6]) << 1;
		else
			temptemp = 0;
		if ((tempreture[0] < ((var[8][0] + var[8][5]) << 1))
				&& (tempreture[0] > (temptemp)))
			hit1ok = 1;
		else
			hit1ok = 0;
		if (var[8][0] < 40)
			hit1ok = 1;

		if (var[8][1] > var[8][6])
			temptemp = (var[8][1] - var[8][6]) << 1;
		else
			temptemp = 0;
		if ((tempreture[1] < ((var[8][1] + var[8][5]) << 1))
				&& (tempreture[1] > (temptemp)))
			hit2ok = 1;
		else
			hit2ok = 0;
		if (var[8][1] < 40)
			hit2ok = 1;

		if (var[8][2] > var[8][6])
			temptemp = (var[8][2] - var[8][6]) << 1;
		else
			temptemp = 0;
		if ((tempreture[2] < ((var[8][2] + var[8][5]) << 1))
				&& (tempreture[2] > (temptemp)))
			hit3ok = 1;
		else
			hit3ok = 0;
		if (var[8][2] < 40)
			hit3ok = 1;

		if (var[8][3] > var[8][6])
			temptemp = (var[8][3] - var[8][6]) << 1;
		else
			temptemp = 0;
		if ((tempreture[3] < ((var[8][3] + var[8][5]) << 1))
				&& (tempreture[3] > (temptemp)))
			hit4ok = 1;
		else
			hit4ok = 0;
		if (var[8][3] < 40)
			hit4ok = 1;

		if (var[8][4] > var[8][6])
			temptemp = (var[8][4] - var[8][6]) << 1;
		else
			temptemp = 0;
		if ((tempreture[4] < ((var[8][4] + var[8][5]) << 1))
				&& (tempreture[4] > (temptemp)))
			hit5ok = 1;
		else
			hit5ok = 0;
		if (var[8][4] < 40)
			hit5ok = 1;

		if (hit1ok && hit2ok && hit3ok && hit4ok)
			hitok = 1;
		else
			hitok = 0;
		if (var[8][0] < 40)
			tempreture[0] = var[8][0] + 8;
		if (var[8][1] < 40)
			tempreture[1] = var[8][1] + 8;
		if (var[8][2] < 40)
			tempreture[2] = var[8][2] + 8;
		if (var[8][3] < 40)
			tempreture[3] = var[8][3] + 8;
		if (var[8][4] < 40)
			tempreture[4] = var[8][4] + 8;

		if ((tempreture[0] > ((var[8][0] + var[8][5]) << 1))
				|| (tempreture[1] > ((var[8][1] + var[8][5]) << 1))
				|| (tempreture[2] > ((var[8][2] + var[8][5]) << 1))
				|| (tempreture[3] > ((var[8][3] + var[8][5]) << 1)))
			hightemp = 1;
		else
			hightemp = 0;

		tempr1 = 0;
		if (var[8][0] > var[8][6])
			temptemp = (var[8][0] - var[8][6]) << 1;
		else
			temptemp = 0;
		if (tempreture[0] < temptemp) {
			if (var[8][0] > 40)
				tempr1 = 1;
		}
		if (var[8][1] > var[8][6])
			temptemp = (var[8][1] - var[8][6]) << 1;
		else
			temptemp = 0;
		if (tempreture[1] < temptemp) {
			if (var[8][1] > 40)
				tempr1 = 1;
		}

		if (var[8][2] > var[8][6])
			temptemp = (var[8][2] - var[8][6]) << 1;
		else
			temptemp = 0;
		if (tempreture[2] < temptemp) {
			if (var[8][2] > 40)
				tempr1 = 1;
		}

		if (var[8][3] > var[8][6])
			temptemp = (var[8][3] - var[8][6]) << 1;
		else
			temptemp = 0;
		if (tempreture[3] < temptemp) {
			if (var[8][3] > 40)
				tempr1 = 1;
		}

		lowtemp = tempr1;

		/* if(  (tempreture[0]<((var[8][0]+var[8][5])<<1)) && (tempreture[0]>((var[8][0]-var[8][6])<<1)))hit1ok=1;else hit1ok=0;
		 if(  (tempreture[1]<((var[8][1]+var[8][5])<<1)) && (tempreture[1]>((var[8][1]-var[8][6])<<1)))hit2ok=1;else hit2ok=0;
		 if(  (tempreture[2]<((var[8][2]+var[8][5])<<1)) && (tempreture[2]>((var[8][2]-var[8][6])<<1)))hit3ok=1;else hit3ok=0;
		 if(  (tempreture[3]<((var[8][3]+var[8][5])<<1)) && (tempreture[3]>((var[8][3]-var[8][6])<<1)))hit4ok=1;else hit4ok=0;
		 if(  (tempreture[4]<((var[8][4]+var[8][5])<<1)) && (tempreture[4]>((var[8][4]-var[8][6])<<1)))hit5ok=1;else hit5ok=0;
		 if(hit1ok && hit2ok && hit3ok && hit4ok)hitok=1; else hitok=0;
		 if( (tempreture[0]>((var[8][0]+var[8][5])<<1)) ||  (tempreture[1]>((var[8][1]+var[8][5])<<1))  || (tempreture[2]>((var[8][2]+var[8][5])<<1)) || (tempreture[3]>((var[8][3]+var[8][5])<<1)) )hightemp =1;
		 else hightemp=0;
		 if( (tempreture[0]<((var[8][0]-var[8][6])<<1)) ||  (tempreture[1]<((var[8][1]-var[8][6])<<1)) || (tempreture[2]<((var[8][2]-var[8][6])<<1)) || (tempreture[3]<((var[8][3]-var[8][6])<<1)) ) lowtemp=1;
		 else lowtemp=0;
		 */

	}

}

void tempctl(void) //port
{
	hpriod++;
	if (hpriod > 99)
		hpriod = 0;
	//st if(outon[0]>hpriod)PORTE.7=0;else PORTE.7=1;
	//st if(outon[1]>hpriod)PORTE.6=0;else PORTE.6=1;
	//st if(outon[2]>hpriod)PORTE.5=0;else PORTE.5=1;
	//st if(outon[3]>hpriod)PORTE.4=0;else PORTE.4=1;
	//st if(outon[4]>hpriod)PORTE.3=0;else PORTE.3=1;

	if (outon[0] > hpriod)
		tempcommand &= 0xfe;
	else
		tempcommand |= 1;
	if (outon[1] > hpriod)
		tempcommand &= 0xfd;
	else
		tempcommand |= 2;
	if (outon[2] > hpriod)
		tempcommand &= 0xfb;
	else
		tempcommand |= 4;
	if (outon[3] > hpriod)
		tempcommand &= 0xf7;
	else
		tempcommand |= 8;
	if (outon[4] > hpriod)
		tempcommand &= 0xef;
	else
		tempcommand |= 0x10;

}	//end

void cond(void)	//ok1
{
}

void colorm(void)	//ok1
{
	int ffff, j;
	char i;
	errorcode=0;//aft

	varselect = 0;
	picnumber = 0;
	if (!transmit) {
		//touch_command_pointer=0;
		//UDR0=0;
		bufpointer = 0;
		bufsize = 0;
		textpointer = 0;
		//cheshmak^=1;


		picpast_flag = 0;
		picpast_add = 0x18;
		//if(state2<14) picpast(45,op_x[state2],op_y[state2],op_x[state2]+op_x_dif,op_y[state2]+op_y_dif,407,8); //Â�Ã­Ã‘Ã¥ ÃˆÃ“ÃŠÃ¥ 1
		//  if(errorcode)picpast(35,er_x[state2],er_y[state2],er_x[state2]+er_x_dif,er_y[state2]+er_y_dif,63,6);
		//keycode=66;
	//	cpp(0, 1, 0, keycodelog, 0);
		//makebuf();
		if (color_refresh < 80)
			color_refresh++;
		else
			color_refresh = 0;
		old[color_refresh] += 1;

		if (page == 13) {
			sine[0] = outputa;
			sine[1] = outputb;
			sine[2] = outputc;
			sine[3] = read1;
			sine[3] = ((sine[3] << 4) | (read2 & 0xf)) ^ 0xffff;
			sine[4] = read3;
			sine[4] = ((sine[4] << 4) | ((read2 >> 4) & 0xf)) ^ 0xffff;
			// sine[3]=0xfff;

			x_sine = 0;
			y_sine = 0;
			x2_sine = 15;
			y2_sine = 15;

			x_dis = 125;
			y_dis = 190;
			x_dis_shift = 120;
			y_dis_shift = 23;
			//picpast_add=0x0c;
			//if(sine[i]!=old_sine[i])
			for (i = 0; sine[i] == old_sine[i] && i < 6; i++)
				;
			if (i < 5) {
				old_sine[i] = sine[i];
				picpast_add += i + 1;
				x_dis += i * x_dis_shift;
				j = 0x1;
				do {
					if (sine[i] & j)
						picpast(35, x_sine, y_sine, x2_sine, y2_sine, x_dis,
								y_dis);
					if (!sine[i])
						picpast(35, x_sine, y_sine, x2_sine, y2_sine, 0, 470);

					y_dis += y_dis_shift;

					j = j << 1;
				} while (j < 0x1000);

			}

		}

		picpast_add = 0x18;
		if (!picpast_flag)
			// if(0)
		{

			picpast_add = 0x18;
			if (errorcode) {
				picpast(46, er_x[errorcode], er_y[errorcode],
						er_x[errorcode] + er_x_dif, er_y[errorcode] + er_y_dif,
						402, 3);
				brightcun = 1000;
			} else {
				if (state2 < 14)
					picpast(45, op_x[state2], op_y[state2],
							op_x[state2] + op_x_dif, op_y[state2] + op_y_dif,
							402, 3); //Â�Ã­Ã‘Ã¥ ÃˆÃ“ÃŠÃ¥ 1
			}
			//picpast(35,0,0,15,15,100,100);
			//picpast(35,0,0,15,15,100,50);
			//picpast(35,0,0,15,15,100,390);

		}

		// tik(line2,5,8,var2[9][5],105,308); // max cycle time
		//tik(line2,6,8,var2[9][6],105,344); // max cycle time
		//tik(line2,7,8,var2[9][7],105,380); // max cycle time

		color1 = BLACK;
		color1 = 0;

		if (cheshmak & 1)
			color2 = RED;
		else
			color2 = GREEN;
		//textpointer=bufsize+1;

		// oft if (!errorcode)


		cpp(0, 1, 0,22.3, 1);
		//oft else
			//oft cpp(0, 1, 0, errorcode, 0);

		//ftemp=receive_data[10];
		 cpp(0,1,1,per,0);
		//	USART1->DR=timebase;

		cpp(0, 1, 2, speed, 0);
	//	cpp(0, 1, 2, 66, 0);
		//cpp(0,1,2,page,0);
		//if(((ruler1+31)>=ruler1p6))cpp(0,1,1,1,0);else cpp(0,1,1,1,0);
		//cpp(0,1,1,page,0);
		//cpp(0,1,2,ruler1/100,0);
		//cpp(0,1,16,0,9);
		//cpp(0,1,6,0,9);

		//if(state2==4 ||state2==3 || state2==5)putnumber(0,2,ritime,0);
		//    else  if(state2==14)putnumber(0,2,timefull,0);
		//                               else putnumber(0,2,timer,0);

		//    else putnumber(0,2,timer,0);

		ftemp = timemax;
//oft		cpp(1, 0, 3, ftemp / 10, 1);
		cpp(1, 0, 3, 22.5, 1);

		if (!hitreal) {
			if (var[8][0] < 40)
				tempreture[0] = var[8][0] + 8;
			if (var[8][1] < 40)
				tempreture[1] = var[8][1] + 8;
			if (var[8][2] < 40)
				tempreture[2] = var[8][2] + 8;
			if (var[8][3] < 40)
				tempreture[3] = var[8][3] + 8;
			if (var[8][12] < 40)
				tempreture[4] = var[8][12] + 8;
			//st    if(PORTE.7)cpp(1,0,7, tempreture[0]>>1,0); else ; cpp(1,0,7, tempreture[0]>>1,0);
			cpp(1, 0, 7, tempreture[0] >> 1, 0);		//st
			//st               if(PORTE.6) cpp(1,17,4, tempreture[1]>>1,0);  else cpp(1,17,4, tempreture[1]>>1,0);
			cpp(1, 17, 4, tempreture[1] >> 1, 0);			//st
			//st                if(PORTE.5) cpp(1,23,10, tempreture[2]>>1,0); else cpp(1,23,10, tempreture[2]>>1,0);
			cpp(1, 23, 10, tempreture[2] >> 1, 0);
			ftemp = tempreture[3] >> 1;
			//ftemp=175;
			//st              if(PORTE.4) cpp(1,28,14, ftemp,0); else cpp(1,28,14, ftemp,0);
			cpp(1, 28, 14, ftemp, 0);			//st
			//st               if(PORTE.3) cpp(1,34,20, tempreture[4]>>1,0); else  cpp(1,34,20, tempreture[4]>>1,0);
			cpp(1, 34, 20, tempreture[4] >> 1, 0);			//st

		} else {
			cpp(1, 12, 7, var[8][0], 0);
			cpp(1, 27, 4, var[8][1], 0);
			cpp(1, 23, 10, var[8][2], 0);
			cpp(1, 28, 14, var[8][3], 0);
			cpp(1, 34, 20, var[8][4], 0);

		}

		if (state2 == 4 || state2 == 3 || state2 == 5) {
			ftemp = ritime;
			 cpp(1, 8, 8, ftemp / 10, 1);
			// cpp(1, 8, 8, 22.3, 1);
		} else if (state2 == 14) {
			ftemp = timefull;
			cpp(1, 8, 8, ftemp / 10, 1);
		} else {
			ftemp = timer;
			cpp(1, 8, 8, ftemp / 10, 1);
		}
		cpp(1, 14, 15, var2[9][0], 0);
		cpp(1, 19, 12, var2[9][1], 0);
		cpp(1, 28, 13, ruler1m, 0);
		//   cpp(1,28,13,maxbufsize,0);
		cpp(1, 38, 17, ruler2m, 0);
		if (!RULER_SELECT1) {
			cpp(1, 38, 16, ruler3m, 0);
		} else {
			cpp(1, 38, 16, ruler3m, 9);
		}
		if (!RULER_SELECT) {
			cpp(1, 38, 6, ruler3m, 0);
		} else {
			cpp(1, 38, 6, ruler3m, 9);
		}
		//cpp(1,0,21,temp,0); // max cycle time

		if (page == 0) {
			cpp(1, 0, 40, tedad, 0); // max cycle time
			// cpp(1,0,40,ruler3p2,0); // max cycle time
			cpp(1, 0, 21, ccunter, 0); // component per hour
			// cpp(1,0,21,ruler3,0); // component per hour

			cpp(1, 0, 9, timep, 0); // max cycle time
			//cpp(1,0,21,ccunter,0); // max cycle time
			//cpp(1,0,21,justtest,0); // max cycle time
			cpp(1, 0, 22, temp, 0); // max cycle time
			//printl(22,char * error_msg[res]);
			cpp(1, 0, 43, tempreture[4] >> 1, 0); // max cycle time
			cpp(1, 0, 41, hour, 0); // max cycle time
			ftemp = timep;

			cpp(1, 0, 11, ftemp / 10, 1); // max cycle time

		}

		if (page == 2) {

			ftemp = var2[0][20];
			cpp(line2, 20, 11, ftemp / 10, 1);

			cpp(line2, 4, 28, var2[0][4], 0); // max cycle time

			cpp(line2, 1, 25, ruler1m, 0); // max cycle time
			cpp(line2, 2, 26, var2[0][2], 0); // max cycle time
			cpp(line2, 3, 27, var2[0][3], 0); // max cycle time

			cpp(line2, 5, 29, var2[0][5], 0); // max cycle time
			cpp(line2, 6, 30, var2[0][6], 0); // max cycle time
			cpp(line2, 7, 31, var2[0][7], 0); // max cycle time
			//cpp(1ine2,6,31,var2[0][7],0); // max cycle time
			ftemp = var2[0][8];
			cpp(line2, 8, 32, ftemp / 10, 1); // max cycle time
			cpp(line2, 9, 33, var2[0][9], 0); // max cycle time
			cpp(line2, 10, 34, var2[0][10], 0); // max cycle time
			cpp(line2, 11, 35, var2[0][11], 0); // max cycle time

			ftemp = var2[0][12];
			cpp(line2, 12, 36, ftemp / 10, 1); // max cycle time
			cpp(line2, 13, 37, var2[0][13], 0); // max cycle time
			cpp(line2, 14, 38, var2[0][14], 0); // max cycle time
			cpp(line2, 15, 39, var2[0][15], 0); // max cycle time

			cpp(line2, 16, 40, var2[0][16], 0); // max cycle time
			cpp(line2, 17, 41, var2[0][17], 0); // max cycle time
			cpp(line2, 18, 42, var2[0][18], 0); // max cycle time
			cpp(line2, 19, 43, var2[0][19], 0); // max cycle time
			//tik(line2,21,88,var2[0][21],100,308); // max cycle time

		}

		if (page == 3) {

			ftemp = var2[1][20];
			cpp(line2, 20, 11, ftemp, 0);

			cpp(line2, 1, 25, var2[1][1], 0); // max cycle time
			cpp(line2, 2, 26, var2[1][2], 0); // max cycle time
			cpp(line2, 3, 27, var2[1][3], 0); // max cycle time

			ftemp = var2[1][4];
			cpp(line2, 4, 28, ftemp / 10, 1); // max cycle time
			cpp(line2, 5, 29, var2[1][5], 0); // max cycle time
			cpp(line2, 6, 30, var2[1][6], 0); // max cycle time
			cpp(line2, 7, 31, var2[1][7], 0); // max cycle time

			ftemp = var2[1][8];
			cpp(line2, 8, 32, ftemp / 10, 0); // max cycle time
			cpp(line2, 9, 33, var2[1][9], 0); // max cycle time
			cpp(line2, 10, 34, var2[1][10], 0); // max cycle time
			cpp(line2, 11, 35, var2[1][11], 0); // max cycle time

			ftemp = var2[1][12];
			cpp(line2, 12, 36, ftemp / 10, 0); // max cycle time
			cpp(line2, 13, 37, var2[1][13], 0); // max cycle time
			cpp(line2, 14, 38, var2[1][14], 0); // max cycle time
			cpp(line2, 15, 39, var2[1][15], 0); // max cycle time

			//cpp(line2,0,15,page,0); // max cycle time

			cpp(line2, 16, 40, var2[1][16], 0); // max cycle time
			cpp(line2, 17, 41, var2[1][17], 0); // max cycle time
			cpp(line2, 18, 42, var2[1][18], 0); // max cycle time
			cpp(line2, 19, 43, var2[1][19], 0); // max cycle time

		}

		if (page == 4) {

			tik(line2, 13, 88, var2[2][13], 105, 452);
			//tik(line2,5,87,var2[2][5],105,378);
			//tik(line2,1,87,var2[2][1],105,308);
			ftemp = var2[2][12];
			//cpp(line2,12,11,ftemp/10,1);
			cpp(line2, 12, 11, ftemp / 10, 1);
			cpp(line2, 12, 5, 10, 9);

			cpp(line2, 0, 24, var2[2][0], 9); // max cycle time
			cpp(line2, 1, 25, var2[2][1], 0); // max cycle time
			cpp(line2, 2, 26, var2[2][2], 0); // max cycle time
			cpp(line2, 3, 27, var2[2][3], 0); // max cycle time
			ftemp = var2[2][4];
			cpp(line2, 4, 32, ftemp / 10, 9); // max cycle time
			cpp(line2, 5, 33, var2[2][5], 0); // max cycle time
			cpp(line2, 6, 34, var2[2][6], 0); // max cycle time
			cpp(line2, 7, 35, var2[2][7], 0); // max cycle time

			ftemp = var2[2][8];
			cpp(line2, 8, 40, ftemp / 10, 1); // max cycle time
			cpp(line2, 9, 41, var2[2][9], 9); // max cycle time
			cpp(line2, 10, 42, var2[2][10], 9); // max cycle time
			cpp(line2, 11, 43, var2[2][11], 9); // max cycle time

		}
		if (page == 5) {
			ftemp = var2[3][11];
			cpp(line2, 11, 5, ftemp / 10, 1);

			ftemp = var2[3][10];
			cpp(line2, 10, 11, ftemp / 10, 1);

			ftemp = var2[3][0];
			cpp(line2, 0, 24, ftemp, 0); // max cycle time
			cpp(line2, 1, 25, var2[3][1], 0); // max cycle time
			cpp(line2, 2, 26, var2[3][2], 0); // max cycle time
			cpp(line2, 3, 27, var2[3][3], 0); // max cycle time

			//cpp(line2,0,11,line,0); // max cycle time

			ftemp = var2[3][8];
			cpp(line2, 40, 32, ftemp, 0); // max cycle time
			cpp(line2, 48, 34, var2[3][5], 9); // max cycle time
			cpp(line2, 44, 35, var2[3][6], 9); // max cycle time
			// cpp(line2,19,13,var2[3][7],0); // max cycle time

			ftemp = var2[3][4];
			cpp(line2, 4, 36, ftemp / 10, 1); // max cycle time
			cpp(line2, 5, 37, var2[3][5], 0); // max cycle time
			cpp(line2, 6, 38, var2[3][6], 0); // max cycle time
			cpp(line2, 7, 39, var2[3][7], 0); // max cycle time

			ftemp = var2[3][8];
			cpp(line2, 8, 40, ftemp, 0); // max cycle time

			tik(line2, 8, 88, var2[3][8], 105, 378); // max cycle time
			tik(line2, 9, 88, var2[3][9], 105, 415); // max cycle time

			// cpp(line2,8,15,var2[3][13],0); // max cycle time
			// cpp(line2,14,15,var2[1][14],0); // max cycle time
			//cpp(line2,19,15,var2[1][15],0); // max cycle time

			//cpp(line2,0,15,page,0); // max cycle time
			// cpp(line2,0,16,var2[1][16],0); // max cycle time
			// cpp(line2,8,16,var2[1][17],0); // max cycle time
			// cpp(line2,14,16,var2[1][18],0); // max cycle time
			// cpp(line2,19,16,var2[1][19],0); // max cycle time

		}
		if (page == 6) {
			ftemp = var2[4][16];
			cpp(line2, 16, 11, ftemp / 10, 1);

			ftemp = var2[4][10];
			//cpp(line2,0,5,ftemp/10,1);
			ftemp = var2[4][11];
			//cpp(line2,0,6,ftemp/10,1);

			ftemp = var2[4][0];
			cpp(line2, 0, 24, ftemp / 10, 1); // max cycle time
			cpp(line2, 1, 25, var2[4][1], 0); // max cycle time
			cpp(line2, 2, 26, var2[4][2], 0); // max cycle time
			cpp(line2, 3, 27, var2[4][3], 0); // max cycle time
			//cpp(line2,0,11,line,0); // max cycle time
			ftemp = var2[4][4];
			cpp(line2, 4, 28, ftemp / 10, 1); // max cycle time
			cpp(line2, 5, 29, var2[4][5], 0); // max cycle time
			cpp(line2, 6, 30, var2[4][6], 0); // max cycle time
			cpp(line2, 7, 31, var2[4][7], 0); // max cycle time

			ftemp = var2[4][8];
			cpp(line2, 8, 32, ftemp / 10, 1); // max cycle time
			cpp(line2, 9, 33, var2[4][9], 0); // max cycle time
			cpp(line2, 10, 34, var2[4][10], 0); // max cycle time
			cpp(line2, 11, 35, var2[4][11], 0); // max cycle time

			ftemp = var2[4][12];
			cpp(line2, 35, 36, ftemp / 10, 9); // max cycle time
			cpp(line2, 35, 37, var2[4][13], 9); // max cycle time
			cpp(line2, 35, 38, var2[4][14], 9); // max cycle time
			cpp(line2, 35, 39, var2[4][15], 9); // max cycle time
			cpp(line2, 35, 40, var2[4][15], 9); // max cycle time
			cpp(line2, 35, 41, var2[4][15], 9); // max cycle time
			cpp(line2, 35, 42, var2[4][15], 9); // max cycle time
			cpp(line2, 35, 43, var2[4][15], 9); // max cycle time
			cpp(line2, 35, 44, var2[4][15], 9); // max cycle time

			//cpp(line2,0,15,page,0); // max cycle time
			// cpp(line2,0,16,var2[4][16],0); // max cycle time
			// cpp(line2,8,16,var2[4][17],0); // max cycle time
			// cpp(line2,14,16,var2[4][18],0); // max cycle time
			// cpp(line2,19,16,var2[4][19],0); // max cycle time

			//cpp(line2,0,17,temp,0); // max cycle time

		}

		if (page == 7) {
			//ftemp=var2[5][8];
			//cpp(line2,8,9,ftemp,0);
			//ftemp=var2[5][9];
			//cpp(line2,9,5,ftemp,0);

			ftemp = var2[5][11];
			cpp(line2, 11, 11, ftemp / 10, 1);
			ftemp = var2[5][10];
			cpp(line2, 10, 19, ftemp, 0);

			tik(line2, 8, 88, var2[5][8], 105, 307); // max cycle time
			tik(line2, 9, 88, var2[5][9], 105, 380); // max cycle time

			ftemp = var2[5][0];
			cpp(line2, 0, 24, ftemp / 10, 1); // max cycle time
			cpp(line2, 1, 25, var2[5][1], 0); // max cycle time
			cpp(line2, 2, 26, var2[5][2], 0); // max cycle time
			cpp(line2, 3, 27, var2[5][3], 0); // max cycle time

			//cpp(line2,0,11,line,0); // max cycle time
			// cpp(line2,0,13,ftemp/10,1); // max cycle time
			// cpp(line2,8,13,var2[5][5],0); // max cycle time
			// cpp(line2,14,13,var2[5][6],0); // max cycle time
			// cpp(line2,19,13,var2[5][7],0); // max cycle time

			ftemp = var2[5][4];
			cpp(line2, 4, 28, ftemp / 10, 1); // max cycle time
			cpp(line2, 5, 29, var2[5][5], 0); // max cycle time
			cpp(line2, 6, 30, var2[5][6], 0); // max cycle time
			cpp(line2, 7, 31, var2[5][7], 0); // max cycle time

			cpp(line2, 37, 32, var2[5][7], 9); // max cycle time

			cpp(line2, 47, 33, var2[5][7], 9); // max cycle time
			cpp(line2, 47, 34, var2[5][7], 9); // max cycle time
			cpp(line2, 47, 35, var2[5][7], 9); // max cycle time
			cpp(line2, 47, 36, var2[5][7], 9); // max cycle time
			cpp(line2, 47, 38, var2[5][7], 9); // max cycle time
			cpp(line2, 47, 39, var2[5][7], 9); // max cycle time

			//cpp(line2,0,15,ftemp/10,1); // max cycle time
			// cpp(line2,8,15,var2[5][13],0); // max cycle time
			// cpp(line2,14,15,var2[5][14],0); // max cycle time
			//cpp(line2,19,15,var2[5][15],0); // max cycle time

			//cpp(line2,0,15,page,0); // max cycle time
			// cpp(line2,0,16,var2[5][16],0); // max cycle time
			// cpp(line2,8,16,var2[5][17],0); // max cycle time
			// cpp(line2,14,16,var2[5][18],0); // max cycle time
			// cpp(line2,19,16,var2[5][19],0); // max cycle time

		}

		if (page == 8) {
			ftemp = var2[6][16];
			//cpp(line2,16,11,ftemp,0);
			tik(line2, 16, 88, var2[6][16], 105, 308); // max cycle time
			tik(line2, 17, 88, var2[6][17], 105, 380); // max cycle time

			ftemp = var2[6][17];
			//cpp(line2,17,5,ftemp,0);
			ftemp = var2[6][10];
			//cpp(line2,0,6,ftemp/10,1);

			ftemp = var2[6][0];
			cpp(line2, 0, 24, ftemp / 10, 1); // max cycle time
			cpp(line2, 1, 25, var2[6][1], 0); // max cycle time
			cpp(line2, 2, 26, var2[6][2], 0); // max cycle time
			cpp(line2, 3, 27, var2[6][3], 0); // max cycle time
			//cpp(line2,0,11,line,0); // max cycle time
			ftemp = var2[6][4];
			cpp(line2, 4, 28, ftemp / 10, 1); // max cycle time
			cpp(line2, 5, 29, var2[6][5], 0); // max cycle time
			cpp(line2, 6, 30, var2[6][6], 0); // max cycle time
			cpp(line2, 7, 31, var2[6][7], 0); // max cycle time

			ftemp = var2[6][8];
			cpp(line2, 8, 32, ftemp / 10, 1); // max cycle time
			cpp(line2, 8, 11, ftemp / 10, 1); // max cycle time
			cpp(line2, 9, 33, var2[6][9], 0); // max cycle time
			cpp(line2, 10, 34, var2[6][10], 0); // max cycle time
			cpp(line2, 11, 35, var2[6][11], 0); // max cycle time

			ftemp = var2[6][12];
			cpp(line2, 12, 36, ftemp / 10, 1); // max cycle time
			cpp(line2, 13, 37, var2[6][13], 0); // max cycle time
			cpp(line2, 14, 38, var2[6][14], 0); // max cycle time
			cpp(line2, 15, 39, var2[6][15], 0); // max cycle time

			//cpp(line2,0,15,page,0); // max cycle time

		}
		if (page == 9) {
			ftemp = var2[7][16];
			cpp(line2, 46, 11, ftemp, 9);

			ftemp = var2[7][17];
			//cpp(line2,17,5,ftemp,0);

			tik(line2, 16, 88, var2[7][16], 105, 380); // max cycle time
			tik(line2, 17, 88, var2[7][17], 105, 308); // max cycle time

			ftemp = var2[7][0];
			cpp(line2, 0, 24, ftemp / 10, 1); // max cycle time
			cpp(line2, 1, 25, var2[7][1], 0); // max cycle time
			cpp(line2, 2, 26, var2[7][2], 0); // max cycle time
			cpp(line2, 3, 27, var2[7][3], 0); // max cycle time

			ftemp = var2[7][4];
			cpp(line2, 4, 28, ftemp / 10, 1); // max cycle time
			cpp(line2, 5, 29, var2[7][5], 0); // max cycle time
			cpp(line2, 6, 30, var2[7][6], 0); // max cycle time
			cpp(line2, 7, 31, var2[7][7], 0); // max cycle time

			ftemp = var2[7][8];
			cpp(line2, 8, 32, ftemp / 10, 1); // max cycle time
			cpp(line2, 9, 33, var2[7][9], 0); // max cycle time
			cpp(line2, 10, 34, var2[7][10], 0); // max cycle time
			cpp(line2, 11, 35, var2[7][11], 0); // max cycle time

			ftemp = var2[7][12];
			cpp(line2, 12, 36, ftemp / 10, 1); // max cycle time
			cpp(line2, 13, 37, var2[7][13], 0); // max cycle time
			cpp(line2, 14, 38, var2[7][14], 0); // max cycle time
			cpp(line2, 15, 39, var2[7][15], 0); // max cycle time

		}
		if (page == 10) {
			ftemp = var2[8][20];
			cpp(line2, 17, 11, ftemp, 0);

			ftemp = var2[8][21];
			cpp(line2, 18, 5, ftemp, 0);
			ftemp = var2[8][10];
			//cpp(line2,0,6,ftemp/10,1);

			ftemp = var2[8][0];
			cpp(line2, 0, 44, ftemp, 0); // max cycle time
			cpp(line2, 1, 45, var2[8][1], 0); // max cycle time
			cpp(line2, 2, 46, var2[8][2], 0); // max cycle time
			cpp(line2, 3, 47, var2[8][3], 0); // max cycle time

			ftemp = var2[8][4];
			cpp(line2, 4, 48, ftemp, 0);
			ftemp = var2[8][8];
			cpp(line2, 8, 49, ftemp, 0);
			cpp(line2, 8, 50, ftemp, 0);
			cpp(line2, 8, 51, ftemp, 0);

			//cpp(line2,8,13,var2[8][5],0); // max cycle time
			//cpp(line2,14,13,var2[8][6],0); // max cycle time
			//cpp(line2,19,13,var2[8][7],0); // max cycle time

			cpp(line2, 8, 52, var2[8][8], 0); // max cycle time
			cpp(line2, 8, 53, ftemp, 0); // max cycle time
			cpp(line2, 12, 54, var2[8][12], 0); // max cycle time
			cpp(line2, 12, 55, var2[8][12], 0); // max cycle time

			ftemp = var2[8][12];
			cpp(line2, 12, 56, ftemp, 0); // max cycle time
			cpp(line2, 12, 57, ftemp, 0); // max cycle time
			cpp(line2, 12, 58, ftemp, 0); // max cycle time
			ftemp = var2[8][16];
			cpp(line2, 16, 59, ftemp, 0); // max cycle time

			//cpp(line2,0,15,page,0); // max cycle time

			cpp(line2, 16, 60, var2[8][16], 0); // max cycle time
			cpp(line2, 16, 61, var2[8][16], 0); // max cycle time
			cpp(line2, 16, 62, var2[8][16], 0); // max cycle time
			cpp(line2, 16, 63, var2[8][16], 0); // max cycle time

		}
		if (page == 11) {
			//ftemp=var2[9][20];
			cpp(line2, 0, 11, var2[9][0], 0);
			cpp(line2, 1, 5, var2[9][1], 0);
			cpp(line2, 2, 25, var2[9][2], 0);
			cpp(line2, 3, 29, var2[9][3], 0);
			cpp(line2, 4, 33, var2[9][4], 0);
			cpp(line2, 44, 37, var2[9][4], 9);
			tik(line2, 5, 88, var2[9][5], 105, 308); // max cycle time
			tik(line2, 6, 88, var2[9][6], 105, 344); // max cycle time
			tik(line2, 7, 88, var2[9][7], 105, 380); // max cycle time
			cpp(line2, 8, 37, var2[9][8], 0);
			cpp(line2, 9, 41, var2[9][9], 0);
			//ftemp=var2[9][21];
			//cpp(line2,0,5,ftemp,0);
			//ftemp=var2[9][10];
			//cpp(line2,0,6,ftemp/10,1);

			//cpp(line2,0,7,temp,0);

			ftemp = var2[9][0];
			//cpp(line2,0,12,ftemp,0); // max cycle time
			// cpp(line2,8,12,var2[8][1],0); // max cycle time
			// cpp(line2,14,12,var2[8][2],0); // max cycle time
			//cpp(line2,19,12,var2[9][0],0); // max cycle time
			//cpp(line2,0,11,line,0); // max cycle time
			ftemp = var2[9][1];
			//cpp(line2,19,13,ftemp,0); // max cycle time
			//cpp(line2,8,13,var2[8][5],0); // max cycle time
			//cpp(line2,14,13,var2[8][6],0); // max cycle time
			//cpp(line2,19,13,var2[8][7],0); // max cycle time

			ftemp = var2[9][2];
			// cpp(line2,19,14,ftemp,0); // max cycle time
			// cpp(line2,8,14,var2[8][8],0); // max cycle time
			//cpp(line2,14,14,var2[8][8],0); // max cycle time
			//cpp(line2,19,14,var2[8][8],0); // max cycle time

			ftemp = var2[8][12];
			//cpp(line2,0,15,ftemp,0); // max cycle time
			//cpp(line2,8,15,ftemp,0); // max cycle time
			//cpp(line2,14,15,ftemp,0); // max cycle time
			//cpp(line2,19,15,ftemp,0); // max cycle time

			//cpp(line2,0,15,page,0); // max cycle time
			//cpp(line2,17,16,var2[9][3],0); // max cycle time
			//cpp(line2,8,16,var2[8][16],0); // max cycle time
			//cpp(line2,14,16,var2[8][16],0); // max cycle time
			//cpp(line2,19,16,var2[8][16],0); // max cycle time

			// cpp(line2,17,17,var2[9][4],0); // max cycle time

		}

		if (page == 14) {

			tik(line2, 0, 88, var2[12][0], 105, 308); // max cycle time
			tik(line2, 1, 88, var2[12][1], 105, 322); // max cycle time

		}

		ftemp = receive_data[0];
		ftemp = ftemp * 256 + receive_data[1];

		if (page && page != 14)
			cpp(1, 0, 21, temp, 0);
		//cpp(1,0,21,ruler2,0);
		if (picpast_flag)
			makebuf();
		if (oldpageco != page) {
			pageid(page);
			oldpageco = page;
		} else

			if (bright != oldbright) {
				oldbright = bright;
				brightness(bright);
			}
		if (beepcounter) {
			lcd_beep(beepcounter);
			beepcounter = 0;
		}
		if (brightcun < 0x40)
			bright = brightcun;
		else
			bright = 0x40;
		//if(touch_command_pointer>17)UDR0=0;
		//touch_command_pointer=20;
		//    key_x=receive_data[7];
		if (receive_data[0] == 0xa5 && receive_data[1] == 0x5a
				&& receive_data[2] == 0x7 && receive_data[3] == 0x81
				&& receive_data[4] == 0x7 && receive_data[5] == 0x4
				&& r_d_pointer == 10) {
			serial_data_valid = 1;
			receive_data[0] = 0;
			if (receive_data[6] != 0xff) {
				key_x = receive_data[6];
				key_x = key_x * 256 + receive_data[7];
				key_y = receive_data[8];
				key_y = (key_y << 8) | receive_data[9];
				//st    touch_key=key_code();
			}
		} else {
			serial_data_valid = 0;

		}

		if (!serial_data_valid) {
			touch_command_pointer = 0;
			receive_data[0] = 0;
		}
		//halHAL_UART_Transmit_IT(&huart2,"0", 1);//afst
		USART2->DR=1;
		//st UDR0=0;
		//if(!(cheshmak &0xf))

		transmit = 1;

	}
}

void write_ppi(unsigned char dataa, unsigned char addr) {
	//st DDRA=0xff;
	//st PORTA=addr;
	//PORTA=0x0;
	//st PORTD.4=1;
	//st PORTD.4=0;
	//st PORTA=dataa;
	//PORTA=0x55;
	//st PORTD.6=0;
	//st PORTD.6=1;
}

unsigned char read_ppi(unsigned char addr) {
	unsigned char in;
	//st DDRA=0xff;
	//st PORTA=addr;
	//st PORTD.4=1;
	//st PORTD.4=0;
	//st DDRA=0;
	//st PORTD.7=0;
	//st PORTA=0xff;
	//st PORTA=0xff;
	//st in=PINA;

	//st PORTD.7=1;
	return in;
}

void defalt(void)	//ok1
{
	int i, j;

	for (i = 0; i < 132; i++)
		for (j = 0; j < 24; j++)
			memvar[i][j] = 0;
	t1cul = 200;
	t2cul = 200;
	t3cul = 200;
	t4cul = 200;
	t5cul = 200;

	ccunter = 0;
	hour1 = hour = 0;

	pass1 = 1356;
	pass2 = 1647;
	pass3 = 1110;
	maxcomponent = 0;
	lock2 = 1;
	maxruler1 = 450;
	maxruler2 = 300;
	maxruler3 = 200;
	//page0
	// space[0][0]=1;
	var2[0][0] = 0;
	var2[0][1] = 0;

	var2[0][2] = 80;
	var2[0][3] = 60;
	var2[0][4] = 0;
	var2[0][5] = 300;
	var2[0][6] = 40;
	var2[0][7] = 41;
	var2[0][8] = 60;
	var2[0][9] = 100;
	var2[0][10] = 30;
	var2[0][11] = 31;
	var2[0][12] = 0;
	var2[0][13] = 0;
	var2[0][14] = 40;
	var2[0][15] = 30;
	var2[0][16] = 0;
	var2[0][18] = 90;
	var2[0][19] = 90;
	var2[0][17] = 65;
	var[0][7] = 8030;
	var[0][8] = 10;
	var2[0][20] = 0;
	//page1
	var2[1][0] = 0;
	var2[1][1] = 0;
	var2[1][2] = 30;
	var2[1][3] = 60;
	var2[1][4] = 0;
	var2[1][5] = 0;
	var2[1][6] = 40;
	var2[1][7] = 40;
	var2[1][8] = 0;
	var2[1][9] = 70;
	var2[1][10] = 50;
	var2[1][11] = 50;
	var2[1][12] = 0;
	var2[1][13] = 300;
	var2[1][14] = 40;
	var2[1][15] = 60;

	var2[1][16] = 0;
	var2[1][17] = 400;
	var2[1][18] = 30;
	var2[1][19] = 25;

	var2[1][20] = 0;

	var[1][0] = 80;
	var[1][1] = 25;
	var[1][2] = 200;
	var[1][3] = 30;
	var[1][4] = 70;
	var[1][5] = 500;
	var[1][6] = 35;
	var[1][7] = 20;
	var[1][8] = 700;
	//page2

	var2[2][0] = 0;
	var2[2][1] = 10;
	var2[2][2] = 40;
	var2[2][3] = 25;
	var2[2][4] = 0;
	var2[2][5] = 200;
	var2[2][6] = 40;
	var2[2][7] = 25;
	var2[2][8] = 10;
	var2[2][9] = 0;
	var2[2][10] = 0;
	var2[2][11] = 0;
	var2[2][12] = 0;
	var2[2][13] = 0;

	var[2][0] = 21;
	var[2][1] = 21;
	var[2][2] = 50;
	var[2][3] = 22;
	var[2][4] = 22;
	var[2][5] = 800;
	var[2][6] = 20;
	var[2][7] = 5;
	var[2][8] = 0;
	//page3

	var2[3][0] = 600;
	var2[3][1] = 141;
	var2[3][2] = 99;
	var2[3][3] = 99;
	var2[3][4] = 1;
	var2[3][5] = 142;
	var2[3][6] = 30;
	var2[3][7] = 30;
	var2[3][8] = 0;
	var2[3][9] = 1;
	var2[3][10] = 0;
	var2[3][11] = 0;

	var[3][0] = 23;
	var[3][1] = 23;
	var[3][2] = 60;
	var[3][3] = 24;
	var[3][4] = 24;
	var[3][5] = 24;
	var[3][6] = 50;
	var[3][7] = 5;
	var[3][8] = 1;

	//page4                   //tazrigh

	var2[4][0] = 20;
	var2[4][1] = 50;
	var2[4][2] = 70;
	var2[4][3] = 70;
	var2[4][4] = 20;
	var2[4][5] = 40;
	var2[4][6] = 60;
	var2[4][7] = 60;
	var2[4][8] = 30;
	var2[4][9] = 0;
	var2[4][10] = 0;
	var2[4][11] = 0;
	var2[4][12] = 0;
	var2[4][13] = 0;
	var2[4][14] = 0;
	var2[4][15] = 0;
	var2[4][16] = 0;

	var[4][0] = 3030;
	var[4][1] = 30;
	var[4][2] = 200;
	var[4][3] = 2525;
	var[4][4] = 20;
	var[4][5] = 2020;
	var[4][6] = 20;
	var[4][7] = 10;
	var[4][8] = 20;

	//page5                  //paran
	var2[5][0] = 20;
	var2[5][1] = 0;
	var2[5][2] = 30;
	var2[5][3] = 31;
	var2[5][4] = 20;
	var2[5][5] = 0;
	var2[5][6] = 20;
	var2[5][7] = 21;
	var2[5][8] = 0;
	var2[5][9] = 0;
	var2[5][10] = 10;
	var2[5][11] = 3;

	var[5][0] = 15;
	var[5][1] = 15;
	var[5][2] = 5;
	var[5][3] = 16;
	var[5][4] = 16;
	var[5][5] = 20;
	var[5][6] = 2;
	var[5][7] = 2;
	var[5][8] = 1;
	//page6//sombe kesh

	var2[6][0] = 20;
	var2[6][1] = 0;
	var2[6][2] = 40;
	var2[6][3] = 41;
	var2[6][4] = 20;
	var2[6][5] = 0;
	var2[6][6] = 30;
	var2[6][7] = 31;
	var2[6][8] = 3;
	var2[6][9] = 0;
	var2[6][10] = 0;
	var2[6][11] = 0;
	var2[6][12] = 0;
	var2[6][13] = 0;
	var2[6][14] = 0;
	var2[6][15] = 0;
	var2[6][16] = 0;
	var2[6][17] = 0;

	var[6][0] = 17;
	var[6][1] = 17;
	var[6][2] = 2;
	var[6][3] = 18;
	var[6][4] = 18;
	var[6][5] = 20;
	var[6][6] = 5;
	var[6][7] = 1;
	var[6][8] = 1;
	//page7//girbox
	var2[7][0] = 20;
	var2[7][1] = 0;
	var2[7][2] = 30;
	var2[7][3] = 31;
	var2[7][4] = 20;
	var2[7][5] = 0;
	var2[7][6] = 40;
	var2[7][7] = 41;
	var2[7][8] = 0;
	var2[7][9] = 0;
	var2[7][10] = 60;
	var2[7][11] = 61;
	var2[7][12] = 0;
	var2[7][13] = 0;
	var2[7][14] = 50;
	var2[7][15] = 51;
	var2[7][16] = 0;
	var2[7][17] = 0;

	var[7][0] = 19;
	var[7][1] = 19;
	var[7][2] = 10;
	var[7][3] = 10;
	var[7][4] = 10;
	var[7][5] = 11;
	var[7][6] = 11;
	var[7][7] = 5;
	var[7][8] = 1;
	//page8     //hararat
	var2[8][0] = 210;
	var2[8][1] = 215;
	var2[8][2] = 205;
	var2[8][3] = 195;
	var2[8][4] = 70;
	var2[8][5] = 70;
	var2[8][6] = 40;
	var2[8][7] = 0;
	var2[8][8] = 70;
	var2[8][9] = 0;
	var2[8][10] = 0;
	var2[8][11] = 0;
	var2[8][12] = 40;
	var2[8][13] = 0;
	var2[8][14] = 0;
	var2[8][15] = 0;
	var2[8][16] = 100;
	var2[8][17] = 0;
	var2[8][18] = 0;
	var2[8][19] = 0;
	var2[8][20] = 0;

	var[8][0] = 150;
	var[8][1] = 150;
	var[8][2] = 150;
	var[8][3] = 150;
	var[8][4] = 150;
	var[8][5] = 80;
	var[8][6] = 80;
	var[8][7] = 30;
	var[8][8] = 100;
	//page9//motefaraeghe
	var2[9][0] = 50;
	var2[9][1] = 20;
	var2[9][2] = 0;
	var2[9][3] = 2000;
	var2[9][4] = 1000;
	var2[9][5] = 1;
	var2[9][6] = 1;
	var2[9][7] = 1;

	var[9][0] = 50;
	var[9][1] = 200;
	var[9][2] = 20;
	var[9][3] = 1000;
	var[9][4] = 30000;
	var[9][5] = 500;
	var[9][6] = 6000;
	var[9][7] = 0;
	var[9][8] = 1;

	//page10
	var2[10][0] = 0;
	var2[10][1] = 1;
	var2[10][2] = 0;
	var2[10][3] = 0;
	var2[10][4] = 0;
	var2[10][5] = 0;
	var2[10][6] = 0;
	var2[10][7] = 500;
	var2[10][5] = 700;

	//for(i=0;i<15;i++)for(j=0;j<9;j++)var[i][j]=0;

}
void ftable(void) {
	//girebashteh
	var[0][0] = var2[0][2] * 100 + var2[0][3];
	var[0][1] = var2[0][6] * 100 + var2[0][7];
	var[0][2] = var2[0][5];
	var[0][3] = var2[0][9];
	var[0][4] = var2[0][10];
	var[0][5] = var2[0][18] * 100 + var2[0][19];
	var[0][6] = var2[0][17];
	var[0][7] = 1112;
	//girebaz
	var[1][0] = var2[1][10];
	var[1][1] = var2[1][11];
	var[1][2] = var2[1][9];
	var[1][3] = var2[1][14];
	var[1][4] = var2[1][15];
	var[1][5] = var2[1][13];
	var[1][6] = var2[1][18];
	var[1][7] = var2[1][19];
	var[1][8] = var2[1][17];

	// silandr
	var[2][0] = var2[2][2];
	var[2][1] = var2[2][3];
	var[2][2] = var2[2][1];
	var[2][4] = var2[2][6];
	var[2][3] = var2[2][7];
	var[2][5] = var2[2][5];
	var[2][6] = var2[2][8];
	var[2][7] = var2[5][11] / 10;  //var2[2][12];
	var[2][8] = var2[2][13];
	//mavadgiri
	var[3][0] = var2[3][2];
	var[3][1] = var2[3][3];
	var[3][2] = var2[3][1];
	var[3][3] = var2[3][0];
	var[3][4] = var2[3][6];
	var[3][5] = var2[3][7];
	var[3][6] = var2[3][5];
	var[3][7] = var2[3][11];
	var[3][8] = var2[3][9];
	//var[3][9]=var2[3][10];
	//var[3][10]=var2[3][4];

	//tazrigh
	var[4][0] = var2[4][2] * 100 + var2[4][3];
	var[4][1] = var2[4][0];
	var[4][2] = var2[4][1];
	var[4][4] = var2[4][4];
	var[4][3] = (var2[4][6] * 100) + var2[4][7];
	var[4][6] = var2[4][8];
	var[4][5] = var2[4][10] * 100 + var2[4][11];
	var[4][7] = var2[4][16];
	var[4][8] = var2[4][5];
	// paran
	var[5][0] = var2[5][2];
	var[5][1] = var2[5][3];
	var[5][2] = var2[5][0];
	var[5][3] = var2[5][6];
	var[5][4] = var2[5][7];
	var[5][5] = var2[5][4];
	var[5][6] = var2[5][9];
	var[5][7] = var2[5][10];
	var[5][8] = var2[5][8];
	// sonbelesh
	var[6][0] = var2[6][2];
	var[6][1] = var2[6][3];
	var[6][2] = var2[6][0];
	var[6][3] = var2[6][6];
	var[6][4] = var2[6][7];
	var[6][5] = var2[6][4];
	var[6][6] = var2[6][8];
	var[6][7] = var2[6][16];
	var[6][8] = var2[6][17];
	//girboxghaleb
	var[7][0] = var2[7][2];
	var[7][1] = var2[7][3];
	var[7][2] = var2[7][0];
	var[7][3] = var2[0][14];
	var[7][4] = var2[0][15];
	var[7][5] = var2[1][6];
	var[7][6] = var2[1][7];
	var[7][7] = 1;	//nemidoonam
	var[7][8] = var2[7][17];

	//            hararat
	var[8][0] = var2[8][0];
	var[8][1] = var2[8][1];
	var[8][2] = var2[8][2];
	var[8][3] = var2[8][3];

	var[8][4] = var2[8][4];
	var[8][5] = var2[8][8];
	var[8][6] = var2[8][12];
	var[8][7] = var2[8][16];
	// motefareghe

	var[9][0] = var2[9][0];
	var[9][1] = var2[9][1];
	var[9][2] = var2[9][2];
	var[9][3] = var2[9][3];
	var[9][4] = 94;
	var[9][5] = 95;
	var[9][6] = 9600;
	var[9][7] = var2[9][7];
	var[9][8] = var2[9][6];

}
void limit(void) {
	if (page == 2) {
		if (var2[0][1] > 999)
			var2[0][1] = 999;
		if (var2[0][5] > 999)
			var2[0][5] = 999;
		if (var2[0][9] > 999)
			var2[0][9] = 999;
		if (var2[0][13] > 999)
			var2[0][13] = 999;
		if (var2[0][17] > 999)
			var2[0][17] = 999;
		if (var2[0][2] > 99)
			var2[0][2] = 99;
		if (var2[0][3] > 99)
			var2[0][3] = 99;
		if (var2[0][6] > 99)
			var2[0][6] = 99;
		if (var2[0][7] > 99)
			var2[0][7] = 99;
		if (var2[0][10] > 99)
			var2[0][10] = 99;
		if (var2[0][11] > 99)
			var2[0][11] = 99;
		if (var2[0][14] > 99)
			var2[0][14] = 99;
		if (var2[0][15] > 99)
			var2[0][15] = 99;
		if (var2[0][18] > 99)
			var2[0][18] = 99;
		if (var2[0][19] > 99)
			var2[0][19] = 99;

	}
	if (page == 3) {
		if (var2[1][1] > 999)
			var2[1][1] = 999;
		if (var2[1][5] > 999)
			var2[1][5] = 999;
		if (var2[1][9] > 999)
			var2[1][9] = 999;
		if (var2[1][13] > 999)
			var2[1][13] = 999;
		if (var2[1][17] > 999)
			var2[1][17] = 999;
		if (var2[1][2] > 99)
			var2[1][2] = 99;
		if (var2[1][3] > 99)
			var2[1][3] = 99;
		if (var2[1][6] > 99)
			var2[1][6] = 99;
		if (var2[1][7] > 99)
			var2[1][7] = 99;
		if (var2[1][10] > 99)
			var2[1][10] = 99;
		if (var2[1][11] > 99)
			var2[1][11] = 99;
		if (var2[1][14] > 99)
			var2[1][14] = 99;
		if (var2[1][15] > 99)
			var2[1][15] = 99;
		if (var2[1][18] > 99)
			var2[1][18] = 99;
		if (var2[1][19] > 99)
			var2[1][19] = 99;

	}
	if (page == 4) {
		if (var2[2][1] > 999)
			var2[2][1] = 999;
		if (var2[2][5] > 999)
			var2[2][5] = 999;
		if (var2[2][9] > 999)
			var2[2][9] = 999;
		if (var2[2][2] > 99)
			var2[2][2] = 99;
		if (var2[2][3] > 99)
			var2[2][3] = 99;
		if (var2[2][6] > 99)
			var2[2][6] = 99;
		if (var2[2][7] > 99)
			var2[2][7] = 99;
		if (var2[2][10] > 99)
			var2[2][10] = 99;
		if (var2[2][11] > 99)
			var2[2][11] = 99;

		if (var2[2][12] > 999)
			var2[2][12] = 999;
		if (var2[2][13] > 1)
			var2[2][13] = 1;

	}

	if (page == 5) {
		if (var2[3][1] > 999)
			var2[3][1] = 999;
		if (var2[3][5] > 999)
			var2[3][5] = 999;

		if (var2[3][2] > 99)
			var2[3][2] = 99;
		if (var2[3][3] > 99)
			var2[3][3] = 99;
		if (var2[3][6] > 99)
			var2[3][6] = 99;
		if (var2[3][7] > 99)
			var2[3][7] = 99;

	}

	if (page == 6) {
		if (var2[4][1] > 999)
			var2[4][1] = 999;
		if (var2[4][5] > 999)
			var2[4][5] = 999;
		if (var2[4][9] > 999)
			var2[4][9] = 999;
		if (var2[4][13] > 999)
			var2[4][13] = 999;
		if (var2[4][17] > 999)
			var2[4][17] = 999;
		if (var2[4][2] > 99)
			var2[4][2] = 99;
		if (var2[4][3] > 99)
			var2[4][3] = 99;
		if (var2[4][6] > 99)
			var2[4][6] = 99;
		if (var2[4][7] > 99)
			var2[4][7] = 99;
		if (var2[4][10] > 99)
			var2[4][10] = 99;
		if (var2[4][11] > 99)
			var2[4][11] = 99;
		if (var2[4][14] > 99)
			var2[4][14] = 99;
		if (var2[4][15] > 99)
			var2[4][15] = 99;
		if (var2[4][18] > 99)
			var2[4][18] = 99;
		if (var2[4][19] > 99)
			var2[4][19] = 99;

	}

	if (page == 7) {
		if (var2[5][1] > 999)
			var2[5][1] = 999;
		if (var2[5][5] > 999)
			var2[5][5] = 999;
		if (var2[5][2] > 99)
			var2[5][2] = 99;
		if (var2[5][3] > 99)
			var2[5][3] = 99;
		if (var2[5][6] > 99)
			var2[5][6] = 99;
		if (var2[5][7] > 99)
			var2[5][7] = 99;

	}
	if (page == 8) {
		if (var2[6][1] > 999)
			var2[6][1] = 999;
		if (var2[6][5] > 999)
			var2[6][5] = 999;
		if (var2[6][9] > 999)
			var2[6][9] = 999;
		if (var2[6][13] > 999)
			var2[6][13] = 999;
		if (var2[6][2] > 99)
			var2[6][2] = 99;
		if (var2[6][3] > 99)
			var2[6][3] = 99;
		if (var2[6][6] > 99)
			var2[6][6] = 99;
		if (var2[6][7] > 99)
			var2[6][7] = 99;
		if (var2[6][10] > 99)
			var2[6][10] = 99;
		if (var2[6][11] > 99)
			var2[6][11] = 99;
		if (var2[6][14] > 99)
			var2[6][14] = 99;
		if (var2[6][15] > 99)
			var2[6][15] = 99;

	}

	if (page == 9) {
		if (var2[7][1] > 999)
			var2[7][1] = 999;
		if (var2[7][5] > 999)
			var2[7][5] = 999;
		if (var2[7][9] > 999)
			var2[7][9] = 999;
		if (var2[7][13] > 999)
			var2[7][13] = 999;
		if (var2[7][2] > 99)
			var2[7][2] = 99;
		if (var2[7][3] > 99)
			var2[7][3] = 99;
		if (var2[7][6] > 99)
			var2[7][6] = 99;
		if (var2[7][7] > 99)
			var2[7][7] = 99;
		if (var2[7][10] > 99)
			var2[7][10] = 99;
		if (var2[7][11] > 99)
			var2[7][11] = 99;
		if (var2[7][14] > 99)
			var2[7][14] = 99;
		if (var2[7][15] > 99)
			var2[7][15] = 99;

	}
	if (page == 10) {
		if (var2[8][0] > 600)
			var2[8][0] = 600;
		if (var2[8][1] > 600)
			var2[8][1] = 600;
		if (var2[8][2] > 600)
			var2[8][2] = 600;
		if (var2[8][3] > 600)
			var2[8][3] = 600;
		if (var2[8][4] > 600)
			var2[8][4] = 600;
		if (var2[8][5] > 600)
			var2[8][5] = 600;
		if (var2[8][6] > 600)
			var2[8][6] = 600;
		if (var2[8][7] > 600)
			var2[8][7] = 600;
		if (var2[8][8] > 600)
			var2[8][8] = 600;
		if (var2[8][9] > 600)
			var2[8][9] = 600;
		if (var2[8][10] > 600)
			var2[8][10] = 600;
		if (var2[8][11] > 600)
			var2[8][11] = 600;
		if (var2[8][12] > 600)
			var2[8][12] = 600;
		if (var2[8][13] > 600)
			var2[8][13] = 600;
		if (var2[8][14] > 600)
			var2[8][14] = 600;
		if (var2[8][15] > 600)
			var2[8][15] = 600;
		if (var2[8][16] > 600)
			var2[8][16] = 600;
		if (var2[8][17] > 600)
			var2[8][17] = 600;
		if (var2[8][18] > 600)
			var2[8][18] = 600;
		if (var2[8][19] > 600)
			var2[8][19] = 600;
		if (var2[8][20] > 600)
			var2[8][20] = 600;
		if (var2[8][21] > 600)
			var2[8][21] = 600;
		if (var2[8][22] > 600)
			var2[8][22] = 600;
		if (var2[8][23] > 600)
			var2[8][23] = 600;

	}
	if (page == 11) {
		if (var2[9][0] > 200)
			var2[9][0] = 200;
		if (var2[9][0] < 10)
			var2[9][0] = 10;
		if (var2[9][1] < 5)
			var2[9][1] = 5;

	}

}

void codepro(void)	//ok1
{
	int opcode, varcode, oprand;
	if (temp / 10000000) {
		opcode = (temp / 1000000);
		oprand = (temp % 100);
		varcode = (temp / 100) % 10000;
		temp = oprand;
		m = opcode / 10;
		/*******************calbration********************************/
		if (m == 4) {

			if ((opcode % 10) == 7)
				ccunter = 0;
		}

		if (m == 3) {

			if (1) {
				m = opcode % 10;
				if (m == 0) {
					maxruler1 = varcode;
				}
				if (m == 1) {
					maxruler2 = varcode;
				}
				if (m == 2) {
					maxruler3 = varcode;
				}
				if (m == 4) {
					if (temp == 0) {
						t1cul = varcode;
					}
					if (temp == 1) {
						t2cul = varcode;
					}
					if (temp == 2) {
						t3cul = varcode;
					}
					if (temp == 3) {
						t4cul = varcode;
					}
					if (temp == 4) {
						t5cul = varcode;
					}

				}

			}

		}

		/********************************************************/

		/*******************pas********************************/
		if (m == 1) {
			if (1) {
				m = opcode % 10;
				if (m == 0) {
					if (varcode == pass1 || varcode == 2468) {
						if (oprand == 0)
							lock = 0;
						else
							lock = 1;

					}
				}

				if (m == 1 && lock == 1) {
					pass1 = varcode;
				}

				if (m == 2) {
					if (varcode == pass2) {
						if (oprand == 0)
							lock1 = 0;
						else
							lock1 = 1;

					}
				}

				if (m == 3 && lock1 == 0) {
					pass2 = varcode;
				}

				if (m == 4) {
					if ((varcode & 0xfffe) == (pass3 & 0xfffe)) {

						if (varcode & 1) {
							lock2 = 0;
							maxcomponent = 0;
						} else {
							pass3 = passcun & 0xfffe;
							lock2 = 1;
							maxcomponent = 0;
						}
						temp = pass3 ^ 0xa55;

					} else
						passtry++;

				}

			}

		}
		/********************************************************/

	}

}

void selectprocess(void)	//ok bc
{

	if (page == 0) {
		hitreal = 1;
	}
	if (page == 11 && line2 == 9) {
		if (temp) {
			// temp=22;
			// temp=save_to_mmc(temp);
			mmc_command = SAVE_TO_MMC;
			// temp=save_var(1,3);
		}
	}
	if (page == 11 && line2 == 8)			//load to var2
	{
		if (temp) {
			//emp=load_to_mmc(temp);
			mmc_command = LOAD_TO_MMC;
		}
	}

	if (page > 1 && !(page == 11 && (line2 == 8 || line2 == 9))) {

		if (numin)
			var2[page - 2][line2] = temp;
		//temp=0;
		//st if((page-2)==10 && line2==1){if(temp<25)loadmem();}
		//st if((page-2)==10 && line2==2){if(temp<25)savemem();}
		temp = 0;

	}
	if (page == 1) {
		page = line + 2;
		line2 = 0;
		temp = 0;

	}

	/*switch( page)
	 {
	 case 0:page=1;break;
	 case 1:page=0;break;
	 default:page=0;
	 */
	//}
	mmc_key_active = 1;

}

void escprocess(void) {
	//if(page>1){page=1;}else
	//if(page==1)page=0;
	page = 0;
}

void upprocess(void) {	//page++;
}
void downprocess(void) {	//page--;
}
void r13process(void) {
}
void r56process(void) {
	if (page == 1)
		page = 0;
	else
		page = 1;
}
void lineprocess(void)	//ok1
{

	if (line < 7) {
		x1line = 15;
		x2line = 30;
	} else {
		x1line = 0;
		x2line = 15;
	}
	if (line > 6) {
		y1line = (line - 7) * 16 + 16;
		y2line = (line - 6) * 16 + 18;
	} else {
		y1line = (line) * 16 + 16;
		y2line = (line + 1) * 16 + 18;
	}

}

void read(int a) {
	int i;
	//st OCR0=0;
	soundf = 4;
	//for(i=0;i<512;i++){sound[0][i]=OCR0;sound[1][i]=OCR0;}
	//st blocknumber=firstblock[0]+(a)*dx;
	//st TCCR0=0x69;
	//st readflag=a+1;
	kflag = 1;

}

void keypross(void)

{
	//number
#define localecho 0

	//if(keycode && localecho){

	if (keycode != 7) {

						brightcun = 1000;
					}
	echo"keycode=%d",keycode);
				sendecho
	//}
	number = 10;
	if (keycode == 18) {
		number = 1;/* //streadflag=0;/* //stTCCR0=0x00;*/
	}
	if (keycode == 26) {
		number = 2;
		read(1);
	}
	if (keycode == 34) {
		number = 3;
		read(2);
	}
	if (keycode == 17) {
		number = 4;
	}
	if (keycode == 25)
		number = 5;
	if (keycode == 33)
		number = 6;
	if (keycode == 16)
		number = 7;
	if (keycode == 24)
		number = 8;
	if (keycode == 32)
		number = 9;
	if (keycode == 35)
		number = 0;
	if (keycode == 27)
		selectprocess();
	if (keycode == 31)
		escprocess();
	if (keycode == 23)

	{
		keywait = 70;
		upprocess();

		if (line2 > 0)
			line2--;
		else
			line2 = dc[page] - 1;
		while (!var_valid[page * 29 + line2]) {
			if (line2 > 0)
				line2--;
			else
				line2 = dc[page] - 1;

		}
		lineprocess();

	}
	if (keycode == 39) {
		keywait = 70;
		downprocess();
		line2++;
		if (line2 >= dc[page])
			line2 = 0;

		while (!var_valid[page * 29 + line2]) {
			line2++;
			if (line2 >= dc[page])
				line2 = 0;
		}
		lineprocess();
	}

	if (keycode == 28) {
		keywait = 70;
		line++;
		if (line >= 13)
			line = 0;
		if (page == 2) {
			if (line2 < 16)
				line2 += 4;
			else if (line2 < 20)
				line2 = 20;
			else
				line2 = 0;
		} else if (page == 3) {
			if (line2 < 16)
				line2 += 4;
			else if (line2 < 20)
				line2 = 20;
			else
				line2 = 0;
		} else if (page == 4) {
			if (line2 < 9)
				line2 += 4;
			else if (line2 < 12)
				line2 = 12;
			else if (line2 == 12)
				line2 = 13;
			else
				line2 = 0;
		} else if (page == 5) {
			if (line2 == 9 || line2 == 10 || line2 == 8)
				line2++;
			else if (line2 < 4)
				line2 += 4;
			else if (line2 < 8)
				line2 = 8;
			else
				line2 = 0;
		} else if (page == 6) {

			if (line2 < 12)
				line2 += 4;
			else if (line2 < 16)
				line2 = 16;
			else
				line2 = 0;

		} else if (page == 7) {
			if (line2 == 9 || line2 == 10 || line2 == 8)
				line2++;
			else if (line2 < 4)
				line2 += 4;
			else if (line2 < 8)
				line2 = 8;
			else
				line2 = 0;
		} else if (page == 8 || page == 9) {
			if (line2 < 13)
				line2 += 4;
			else if (line2 < 16)
				line2 = 16;
			else if (line2 == 16)
				line2 = 17;
			else
				line2 = 0;

		} else if (page == 10) {

			if (line2 < 16)
				line2 += 4;
			else
				line2 = 0;

		} else

		{
			line2++;
			if (line2 >= dc[page])
				line2 = 0;
			lineprocess();
		}

		while (!var_valid[page * 29 + line2]) {
			line2 += 4;
			if (line2 >= dc[page])
				line2 = 0;

		}

	}

	if (keycode == 20) {
		keywait = 70;
		if (line > 0)
			line--;
		else
			line = 12;

		if (page == 2) {
			if (line2 > 3)
				line2 -= 4;
			else
				line2 = 20;
		} else if (page == 3) {
			if (line2 > 3)
				line2 -= 4;
			else
				line2 = 20;
		} else if (page == 4) {
			if (line2 == 13)
				line2 = 12;
			else if (line2 > 3)
				line2 -= 4;
			else
				line2 = 13;
		} else if (page == 5) {
			if (line2 == 9 || line2 == 10 || line2 == 11)
				line2--;
			else if (line2 > 3)
				line2 -= 4;
			else
				line2 = 11;
		} else if (page == 6) {
			if (line2 > 3)
				line2 -= 4;
			else
				line2 = 16;
		} else

			if (page == 7) {
				if (line2 == 9 || line2 == 10 || line2 == 11)
					line2--;
				else if (line2 > 3)
					line2 -= 4;
				else
					line2 = 11;
			} else if (page == 8 || page == 9) {
				if (line2 == 17)
					line2 = 16;
				else if (line2 > 3)
					line2 -= 4;
				else
					line2 = 17;

			} else if (page == 10) {

				if (line2 > 3)
					line2 -= 4;
				else
					line2 = 16;

			} else

			{
				if (line2 > 0)
					line2--;
				else
					line2 = dc[page] - 1;
				lineprocess();

			}

	}

	while (!var_valid[page * 29 + line2]) {
		line2 -= 4;
		if (line2 < 0)
			line2 = dc[page] - 1;

	}

	if (keycode == 30)
		r13process();
	if (keycode == 40) {
		govein = 1;
	}
	if (protection) {
		if (keycode == 8) {
			pmc = 1;
			state2 = 2;
			timer2 = var2[0][8];
			timer = var2[0][12];
			yekst = 1;
		}
		if (keycode == 0) {
			pmo = 1;
			state2 = 8;
			timer = var2[1][4];
		}
		if (keycode == 9) {
			pub = 1;
			state2 = 7;
		}	//r23
		if (keycode == 1) {
			puf = 1;
			timer = 7;
			state2 = 3;
		}	//r26
		if (keycode == 2) {
			pri = 1;
			ritime = 0;
			ristate = 0;
			state2 = 4;
		}	//r26
		if (keycode == 3) {
			pbri = 1;
			state2 = 5;
		}	//r26
		if (keycode == 10) {
			if (var[3][8]) {
				pmri = 1;
				state2 = 6;
			} else
				errorcode = 2;
		}	//r26
		if (keycode == 5) {
			if (var2[6][17]) {
				pepm = 1;
				state2 = 10;
			} else
				errorcode = 2;
		} //r26
		if (keycode == 13) {
			if (var[6][7]) {
				pco = 1;
				timer = var[6][5];
				state2 = 11;
			} else
				errorcode = 2;
		} //r26
		if (keycode == 11) {
			if (var[5][8]) {
				peb = 1;
				timer = var[5][5];
				state2 = 13;
			} else
				errorcode = 2;
		} //r26

		if (keycode == 14) {
			if (var[7][8]) {
				pgb = 1;
				state2 = 9;
			} else
				errorcode = 2;
		}
		if (keycode == 4) {
			if (var[5][8]) {
				pef = 1;
				state2 = 12;
				timer = var2[5][0];
			} else
				errorcode = 2;
		}
		// if(keycode==13){peb=1;state2=12;}
		// if(keycode==6)pco=1;
		if (keycode == 6) {
			if (var2[6][16]) {
				pci = 1;
				timer = var[6][2];
				state2 = 1;
			} else
				errorcode = 2;
		}
		if (keycode == 12) {
			if (var2[6][17])
				darbaz = 1;
			else
				errorcode = 2;
		}
		if (keycode == 5) {
			if (var2[6][17])
				darbasteh = 1;
			else
				errorcode = 2;
		}
		if (keycode == 31) {
			govein = 1;
		}

	}
	if (keycode == 7) {
		if (semiauto || (automatic && !state))
			auto3 = 1;
	}		//r26

	if (keycode == 29 && var2[9][5] && maxcomponent < 99998) {
		if (moto && hitteron && !i24) {
			oil = 0;
			if (i19) {
				//oil = oil;
				automatic = 1;
				protection = 0;
				ehteyatkey = 0;
			} else {
				errorcode = 18;
				moto = 0;
			}
		} else {
			if (!moto || i24)
				errorcode = 1;
			if (!var2[9][5])
				errorcode = 2;
			if (!hitteron)
				errorcode = 5;
		}
	}
	if (keycode == 21 && maxcomponent < 99998) {
		if (moto && hitteron && !i24) {
			oil = 0;
			if (i19) {
				//oil = oil;
				semiauto = 1;
				state = 0;
				finish = semiauto;
				protection = 0;
				ehteyatkey = 0;
			} else {
				moto = 0;
				errorcode = 18;
			}
		} else {
			if (!moto || i24)
				errorcode = 1;
			if (!hitteron)
				errorcode = 5;
		}
	}
	if (keycode == 22) {
		moto ^= 1;
		if (moto && !i19) {
			moto = 0;
			errorcode = 18;
		}
	}
	if (keycode == 37) {
		if (oil)
			oil = 0;
		else {
			if (protection)
				oil = 1;
		}
	}
	if (keycode == 38) {
		//oil = oil;
		protection = 1;
		semiauto = 0;
		automatic = 0;
		if (!i19)
			errorcode = 18;
	}
	if (keycode == 30)
		hitteron ^= 1;
	if (keycode == 36) {
		ehteyatkey ^= 1;
		if (!protection)
			ehteyatkey = 0;
	}
	if (keycode == 15) {
		if (oil)
			oilcycle = 0;
		else if (automatic || semiauto || protection) {
			oiltime = 0;
			oilcycle = 1;
		}
	}

	// if(page!=0)
	{
		if (keycode == 49) {
			page = 9;
			line2 = 0;
			temp = 0;
		}
		if (keycode == 42) {
			page = 3;
			line2 = 0;
			temp = 0;
		}
		if (keycode == 43) {
			page = 6;
			line2 = 0;
			temp = 0;
		}
		if (keycode == 44) {
			page = 5;
			line2 = 0;
			temp = 0;
		}
		if (keycode == 50) {
			page = 13;
			line2 = 0;
			temp = 0;
		}
		if (keycode == 51) {
			page = 14;
			line2 = 0;
			temp = 0;
		}
		if (keycode == 52) {
			page = 11;
			line2 = 0;
			temp = 0;
		}
		if (keycode == 53) {
			page = 12;
			line2 = 0;
			temp = 0;
		}
		if (keycode == 41) {
			page = 2;
			line2 = 0;
			temp = 0;
		}
		if (keycode == 45) {
			page = 4;
			line2 = 0;
			temp = 0;
		}
		if (keycode == 46) {
			page = 7;
			line2 = 0;
			temp = 0;
		}
		if (keycode == 47) {
			page = 8;
			line2 = 0;
			temp = 0;
		}
		if (keycode == 48) {
			page = 10;
			line2 = 0;
			temp = 0;
		}
	}

	// per=keycode;

	//14,8,1,2,3,10,9,0,11,5,6,12,4

	keypress = 0;
	refresh = 1;

	if (number < 10) {
		numin = 1;
		if (!numberchange) {
			temp = 0;
		}
		temp *= 10;
		temp += number;
		temp %= 100000000;
		numberchange = 1;

	} else {
		numberchange = 0;
		numin = 0;

	}

	if (!page) {
		if (temp) {
			codepro();

		}

		while (!var_valid[page * 29 + line2]) {
			line2++;
			if (line2 >= dc[page])
				line2 = 0;
		}

	}
	while (!var_valid[page * 29 + line2]) {
		line2++;
		if (line2 >= dc[page])
			line2 = 0;
	}

}

//=======================================================================================================

void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */

  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  main_timer();
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}



void TIM1_UP_IRQHandler() {
	TIM1->SR &= ~(1 << 0); ///reset it flag
	Value++;
	//sprintf(tempasd,"%d\n",Value);
	main_timer();
USART1->DR=52;
	//send_string(tempasd);

}
/*interrupt */void main_timer(void) {
	int temppp;

	//st   while ((ADCSRA & 0x10)==0);
	//st  ADCSRA|=0x10;
	if (chanel < 3) {
		//ADMUX=chanel|ADC_VREF_TYPE;
		//st                  in[chanel]= ADCW;      //khatkesh
		// in[chanel]=1000;
		// if(!chanel)if(ADCW<600)justtest=200; else{ if(justtest<500)justtest++;}
		//if(chanel==1)
		// {if(in[1]<600)justtest=200; else{ if(justtest<500)justtest++;}}
		// justtest=in[0];
		// if(chanel==0)in[chanel]=1000;
	}		// in[chanel]=1000;
	else {
		if (s4051 > 100) {
			if (chanel == c4051) {
				//st    in[c4051]=ADCW;// dama

				s4051 = 0;
				c4051++;
				if (c4051 > 7) {
					c4051 = 3;
				}

				//st  if(c4051==3){PORTF=0;
				if (errorcode && !(secend % 3))
					setout20;
				else
					clrout20;		//st}
				//st  if(c4051==4){PORTF=0x60;}
				//st if(c4051==5){PORTF=0x50;}
				//st if(c4051==6){PORTF=0x70;}
				//st if(c4051==7){PORTF=0x30;}

			}				//stelse
			//st temppp=ADCW;

		} //st else temppp=ADCW;

	}
	s4051++;
	chanel++;
	chanel &= 7;
	if (chanel < 3) {/*//st ADMUX=(chanel|ADC_VREF_TYPE) &0xff;*/
	} else {
		/*                              if(chanel==3){PORTF=0;}
		 if(chanel==4){PORTF=0x10;}
		 if(chanel==5){PORTF=0x20;}
		 if(chanel==6){PORTF=0x30;}
		 if(chanel==7){PORTF=0x50;}
		 */
		//  PORTF=0;
		//st  ADMUX=0xff &(3|ADC_VREF_TYPE);
	}

	timebase++;

	timebase2++;   //100 hz

	//st if((timebase2 & 4) && memactive ){disk_timerproc();/* //st PORTC.1=0;*/} //st else PORTC.1=1;

	alaki2--;
	//  if(timebase==100){if(timestart)totaltime++;secbase++;oiltime++;ritime1++; ritime++;timebase=0;if(timer)timer--;if(timer2)timer2--;if(timer1>1)timer1--;}
	if (timebase == 100) {

		//USART1->DR=secbase;
		if (brightcun)
			brightcun--;
		cheshmak++;
		if (timestart)
			totaltime++;
		secbase++;
		oiltime++;
		ritime1++;
		ritime++;
		timebase = 0;
		if (timer)
			timer--;
		if (timer2)
			timer2--;
		if (timer1 > 1)
			timer1--;
	}
	if (!beepcounter)
		beep = 0;
	else
		beepcounter--;
	read1 = read_ppi(0x0);
	read2 = read_ppi(0x1);
	read3 = read_ppi(0x2);
	ruler2 = in[1];
	//in[0]=1022;
	//if(chanel==1)
	ruler1 = in[0];
	ruler3 = in[2];
	//    if(ruler1<600)justtest=200; else if(justtest<500)justtest++;
	//justtest=ruler1;
	// Start the AD conversion
	//st  ADCSRA|=0x40;
	//ruler1=2000;
	cond();
	if (tempp == 1) {
		speed = var[2][1];
		per = var[2][0];
	}

	staten = state;
	//write_ppi(0x80,0x33);
	if (speed > speed2)
		if (!kkkk--) {
			kkkk = 200;
			speed2 = speed;
		}
	if (speed < speed2)
		speed2 = speed;
	if (speed == 0)
		speed2 = 0;
	write_ppi(outputa ^ 0xff, 0x0);
	write_ppi(outputb ^ 0xff, 0x1);
	write_ppi(outputc ^ 0xff, 0x2);

	if (outputa || outputb || (outputc & 0xf3))
		write_ppi(0xfe, 3);
	else
		write_ppi(0xff, 3);
	//st  PORTA=led ;
	//st PORTG=4;
	//st  PORTG=0;
	keyscan();

	write_ppi(speed2 * 2, 0x60);	//speed
	write_ppi(per * 2, 0x61);	//flew
	if (keypress) {
		refresh3 = 1;
		keypross();
		keypress = 0;
		if (protection)
			if (!lockkey)
				errorcode = 0;
	}

	if (!cycleex)
		if (!semiauto2) {
			if (automatic && auto3) {
				semiauto2 = 1;
				state = 0;
				finish = 1;
			}
		}
	//taghir

	if (fffk) {
		if (!i8 && oldi8) {
			if (var[9][8])
				if (semiauto || automatic) {
					auto4 = 1;
					fffk = 0;
				}
			oldi8 = i8;
		} else
			oldi8 = i8;
	} else {
		oldi8 = i8;
	}

}

//=======================================================================================================
// eeprom function
//#include "e2prom.c"

void show_page(int page) {
	u32 address;
	u16 i, j;
	u16 datain = 0x22;
	char string[10];

	HAL_FLASH_Unlock();
	address = addresspage + (page * 0x400);
	//for(i=0;i<var2i;i++)
	for (j = 0; j < 0x200; j++) {
		datain = *(vu16*) (address);
		address++;
		address++;
		sprintf(string, " %x", datain);
		send_string(string);
		//delay_ms(10);
	}

}

void show_var(int page) {
	u32 address;
	u16 i, j;
	u16 datain = 0x22;
	char string[10];

	for (i = 0; i < var2i; i++)
		for (j = 0; j < var2j; j++) {
			datain = var2[i][j];

			sprintf(string, "\nvar[%d][%d]= %d", i, j, datain);
			send_string(string);
			HAL_Delay(1);

		}

}

void command_process(void) {
#define localecho 1
	char string[20], i, j, commandstr[15], arg[4][10];
	u16 index, datain;
	float number;
	for (i = 0; i < 30; i++) {
		//if(command[i]==0x3b)command[i]=0;

	}

	//  send_string(command);
	index = 0;
	do {

		commandstr[index] = command[index];

		index++;
	} while (index < 15 && command[index] != 0x3b && (command[index] != 0x20));
	commandstr[index] = 0;
	i = 0;
	j = 0;
	index++;
	do {
		if (command[index] == 0x20) {
			arg[i][j] = 0;
			i++;
			j = 0;
			if (i > 3)
				break;
		} else {
			arg[i][j] = command[index];
			j++;
		}
		index++;
	} while (index < 30 && command[index] != 0x3b && j < 10 && i < 4);

	commandstr[index] = 0;

	send_string(commandstr);
	if (strcmp(commandstr, "show_page") == 0) {
		show_page(atoi(arg[0]));
	}
	if (strcmp(commandstr, "page") == 0) {
		page = atoi(arg[0]);
	}
	if (strcmp(commandstr, "vartomem") == 0) {
		vartomem(0);
	}
	if (strcmp(commandstr, "show_var") == 0) {
		show_var(0);
	}
	if (strcmp(commandstr, "update_var") == 0)// update var2[i][j] in flash ,ex: update_var i j data;
	{
		update_var(atoi(arg[0]) * 22 + atoi(arg[1]), atoi(arg[2]));
		var2[atoi(arg[0])][atoi(arg[1])] = atoi(arg[2]);
		echo
		"\n commad proccess : data=%d", atoi(arg[2])
		);
		sendecho
	}
	if (strcmp(commandstr, "get_var") == 0)	//get_var i j ; return var2[i][j] from memory in decimal and hex
	{
		datain = get_var(atoi(arg[0]) * 22 + atoi(arg[1]));
		sprintf(string, "var=%d ,%x ", datain, datain);
		send_string(string);
	}

	if (strcmp(commandstr, "memload") == 0) {
		memload();
		sprintf(string, "<<memload>>");
		send_string(string);
	}

	if (strcmp(commandstr, "update_group") == 0) {
		for (i = 0; i < atoi(arg[0]); i++)
			update_var(i, atoi(arg[1]));
		sprintf(string, "<<update_group>>");
		send_string(string);
	}

	if (strcmp(commandstr, "getsum") == 0)	//sumation var2[i][j] from ...
	{
		datain = 0;
		for (i = 0; i < var2i; i++)
			for (j = 0; j < var2j; j++) {
				datain += var2[i][j];

			}
		sprintf(string, "\n SUM=%d", datain);

		send_string(string);

	}

	if (strcmp(commandstr, "STORETOMEM") == 0) {
		STORE_TO_MEM(atoi(arg[0]), string);

		sprintf(string, "\n storetomem>>");

		send_string(string);

	}
	if (strcmp(commandstr, "LOADTOVAR") == 0) {

		LOADMEM_TO_VAR(atoi(arg[0]));
		sprintf(string, "\n loadmemtovar>>");

		send_string(string);

	}
	if (strcmp(commandstr, "inc") == 0) {

		inc();
		sprintf(string, "\n inc>>");

		send_string(string);

	}
	if (strcmp(commandstr, "inc") == 0) {

		number = atoi(arg[0]);
		number = number / 1000;
		ftoa(number, atoi(arg[1]), string);
	}
	if (command[index] = 0x3b) {
		echo
		"; detected"
		);
		sendecho

		for (i = 0; i < 4; i++)
			for (j = 0; j < 10; j++)
				arg[i][j] = 0;	//debug 5

	}
}
void USART2_IRQHandler(void) {
#define localecho 0
	volatile unsigned int IIR;
	unsigned char ch;
	IIR = USART2->SR;
	if (IIR & UART_FLAG_TXE) {
		if (bufpointer <= bufsize) {
			//oftUSART_SendData(USART2, lcdbuf[bufpointer]);
			USART2->DR=lcdbuf[bufpointer];
			//halHAL_UART_Transmit(&huart2,lcdbuf[bufpointer], 1,1);
			bufpointer++;
			transmit = 1;
		} else {
			transmit = 0;
			colorm();
		}
		if (bufsize > maxbufsize)
			maxbufsize = bufsize;
	}

	if (IIR & UART_FLAG_RXNE) {
		//ch = getkey2();

         ch=USART2->DR;
//     	 USART1->DR=ch;

		 //hal  USART_SendData(USART1, ch);

		if (ch != 0x55 && ch != 0x54 && !lockkey) {
			keycode = (((ch >> 3) - 1) << 3) + (ch & 0x07);
			echo"keycode=%d",keycode);
			sendecho
			lockkey = 1;
			keycodelog=keycode;
			keypress = 1;
			beep = 1;
			beepcounter = 10;
		//if(localecho)USART1->DR=keycode;
		}

		if (ch == 0x54) {                //ON PRESS
			// keycode=0;
			//keypress=0;

		}
		if (ch == 0x55) {             //ON FREE
			lockkey = 0;

		}

	}
}
void USART1_IRQHandler(void) {
#define localecho 0
	char ch, string[10];
//if(USART1->SR & USART_SR_RXNE){
//	 (!(USART1->SR & USART_SRFLAG_RXNE));
//	USART_SR_RXNE
	//HAL_UART_IRQHandler(&huart1);
	//USART_ClearITPendingBit(USART1,USART_SR_RXNE);
	 //}
	//if(USART_GetITStatus(USART1, UART_IT_RXNE) != RESET)//enter interrupt when STM32 receice data.
	      {


		ch = getkey();
		ch=USART1->DR;
			USART1->DR=ch;
			// USART_SendData(USART1,'t');

			if (command_index > 28)
				command_index = 0;
			command[command_index] = ch;
			command_index++;

			if (ch == 0x3b) {
				echo
				"%c\n", ch
				);
				sendecho
				command_process();
				command_index = 0;

			} else {
				echo
				" %c", ch
				);
				sendecho

			}

		//	USART_ReceiveData(huart1);
		//	 huart1.RxState = HAL_UART_STATE_READY;
//HAL_UART_IRQHandler(&huart1);

//USART_ClearITPendingBit(&h huart->RxState = HAL_UART_STATE_READY;uart1, UART_IT_RXNE);
	        // USART_Temp_Data = (unsigned char) USART_ReceiveData(USART1); //receive a char
	      }
}
//====================

void update_var(int var_address, u16 data) {
#define localecho 1

	u16 i = 0, j = 0, counter;
	u32 address;
	char string[10];

	HAL_FLASH_Unlock();

	address = addresspage + 0x800;
	echo
	"\n updatevar#1 : data=%d", data
	);
	sendecho
	while (((*(vu16*) (address) != 0xffff))) {
		address += 8;

	}
	if (address == addresspage + 0xc00 - 8) {
		memload();
		vartomem(1);
		FLASH_ErasePage(addresspage + 0xc00);
	}
	if (address == addresspage + 0x1000 - 8) {
		memload();
		vartomem(1);
		FLASH_ErasePage(addresspage + 0x800);
	}

	FLASH_ProgramHalfWord((address), var_address);
	FLASH_ProgramHalfWord((address + 2), data);

	echo
	"\n updatevar#2 : data=%d", data
	);
	sendecho

}

void find_next_var_page(void) {

	u32 pageaddressmin;
	u16 i = 0, datain = 0, datainmin = 0xffff;
	HAL_FLASH_Unlock();
	findvalidpage();
	if (var_page_address == 0xffffffff)
		var_next_address = addresspage;
	else {
		if (var_page_address == addresspage)
			var_next_address = addresspage + 0x400;
		else
			var_next_address = addresspage;
	}

}
// findvalid page find the page with max. counter to read from that/ if 0xffffffff means no page avalible
void findvalidpage(void) {
# define localecho 1
	u32 pageaddressmax;
	u16 i = 0, datain, datainmax;
	HAL_FLASH_Unlock();

	if ((*(vu16*) (addresspage) == 0xffff)
			&& (*(vu16*) (addresspage + 0x400) == 0xffff)) {
		pageaddressmax = 0xffffffff;
		echo
		"1st page available"
		);
		sendecho;
	} else {
		if ((*(vu16*) (addresspage) == 0xffff))
			pageaddressmax = addresspage + 0x400;
		else {
			if ((*(vu16*) (addresspage + 0x400) == 0xffff))
				pageaddressmax = addresspage;
			else {
				if ((*(vu16*) (addresspage)) > (*(vu16*) (addresspage + 0x400)))
					pageaddressmax = addresspage;
				else
					pageaddressmax = addresspage + 0x400;
			}
		}
	}

	var_page_address = pageaddressmax;
	//FLASH_Lock();
}

//vartomem load varables (var[i][j] ) to st eeprom;

void vartomem(u16 flag)             // flag=0 then close page .
{
#define localecho 1
	u16 i = 0, j = 0, counter;
	u32 address;
	char string[100];

	findvalidpage();
	echo
	"\n vartomem\after faidvalidpage:counter = %x ,valid_page_address= %x ;", counter, address
	);
	sendecho

	address = var_page_address;             //var_page_address is loaded by
	//if(address==0xffffffff)address=addresspage;//oft
	HAL_FLASH_Unlock();

	echo
	"\n vartomem:counter = %x ,address= %x ", counter, address
	);
	sendecho

	if (address != 0xffffffff)
		counter = *(vu16*) (address);	// if address invalid micro halt
	echo
	"\n vartomem:loaded counter = %x ,address= %x ", counter, address
	);
	sendecho
	find_next_var_page(); // to find next page counter=0xffff or min value of counter
	address = var_next_address;
	echo
	"\n vartomem: next page loaded counter = %x ,address= %x ", counter, address
	);
	sendecho

	counter++;
	FLASH_ErasePage(address);

	FLASH_ProgramHalfWord((address), counter);

	for (i = 0; i < var2i; i++)
		for (j = 0; j < var2j; j++) {
			address++;
			address++;
			FLASH_ProgramHalfWord((address), var2[i][j]);

			//sprintf(string,"\n [%d][%d]=%d ",i,j,var2[i][j]);

			//send_string(string);

		}

	if (!flag)
		update_var(0xfffe, 1); // make a new change page

	echo
	"\n vartomem end of writing %x flag= %d\n", address, flag
	);

	sendecho

}

u16 STORE_TO_MEM(u16 page, char *str) {
	u16 i = 0, j = 0, counter;
	u32 address;
	char string[100];
	if (page > PageLimit)
		return 0;
	address = addresspage + 0x400 * (page + 6);
	HAL_FLASH_Unlock();
	FLASH_ErasePage(address);

	for (i = 0; i < 20; i++) {
		FLASH_ProgramHalfWord((address), str[i]);
		address++;
		address++;
	}

	for (i = 0; i < var2i; i++)
		for (j = 0; j < var2j; j++) {

			FLASH_ProgramHalfWord((address), var2[i][j]);
			address++;
			address++;

			//send_string(string);

		}

	//sprintf(string,"STORETO MEM: end of writing %x \n",address);

	// send_string(string);

}

u16 get_var(u32 var_address) {
#define localecho 0
	u16 i = 0, j = 0, counter;
	u32 address, end_address, strat_address;
	char string[150];
	address = addresspage + 0xc00 - 8; // end of page 3
	echo"\n get_var#1 :var_page_address= %x", address);
	sendecho
	HAL_FLASH_Unlock();
	if (*(vu16*) (addresspage + 0xc00 - 8) == 0xffff
			&& *(vu16*) (addresspage + 0x1000 - 8) == 0xffff) // if  end of both page is clear
	{
		//oft0.0 if(*(vu16*)(addresspage+0x800)!=0xffff)end_address=addresspage+0xc00-8;else end_address=addresspage+0x1000-8;
		if (*(vu16*) (addresspage + 0x800)/*page 2*/!= 0xffff)
			end_address = 0xc00 - 8;
		else
			end_address = 0x1000 - 8; //aft0.0
		echo
		"\n get_var#2 : end address= %x", end_address
		);
		sendecho
	} else if (*(vu16*) (addresspage + 0xc00 - 8) == 0xffff)
		end_address = 0xc00 - 8;
	else
		end_address = 0x1000 - 8;

	//
	end_address = end_address + addresspage;
	echo
	"\n get_var#3 : end address= %x", end_address
	);
	sendecho
	for (address = end_address; address > (end_address - 0x400);
			address = address - 8) {
		if (0xfffe != *(vu16*) (address)) { // if not found variable address in change page then break and read from var_page address
			if (var_address == *(vu16*) (address)) { // if found variable address in change page then return data
				//sprintf(string,"\n address=%x data=%d address=%d ",end_address,*(vu16*)(address+2),*(vu16*)(address));
				//send_string(string);
				echo
				"\n get_var #4:return word address= %x", address
				);
				sendecho

				return *(vu16*) (address + 2);
			}
		} else
			break;
	}
	//	sprintf(string,"\n not found update  ");
	//	                 send_string(string);
	findvalidpage();
	//sprintf(string,"\n getvar:var_page_address= %x ;",var_page_address);
	//      send_string(string);

	address = var_page_address + (2 * (var_address + 1));
	echo"\n get_var :return word address= %x", address
	);
	sendecho
	return *(vu16*) (address);

}

void memload(void)	// var2=eeprom or var2=default
{
#define localecho 1
	char string[100];
	u16 i, j, counter;
	u32 address;
	findvalidpage(); // to find maxcounter
	echo
	"\n memload#1:findvalidpage :var_page_address= %x", var_page_address
	);
	sendecho
	if (var_page_address == 0xffffffff) {
		sprintf(string,
				"\n memload#2:variables set to defualt and write to address = %x  ",
				var_page_address);
		send_string(string);
		var_page_address = addresspage; //aft-VER1 . OK
		defalt();
		send_string("#1");
		vartomem(0);
		send_string("#2");
	} else {

		address = var_page_address + 2;
		for (i = 0; i < var2i; i++)
			for (j = 0; j < var2j; j++) {

				echo
				"\n memload#:not fffffffh :var_page_address= %x", var_page_address
				);
				sendecho
				address = address + 2;

				//		for(d=var2i*var2j+2;d<0x3ff;d+=4)
				//      {
				//     if(*(vu16*)(address)+d
				//		}
				//sprintf(string,"variables is reading from address = %x  ",var_page_address);
				//send_string(string);
				//var2[i][j]=*(vu16*)(address);
				var2[i][j] = get_var(i * 22 + j);
			}

	}

	echo
	"\n memload:end of function at address= %x", address
	);
	sendecho

}

u16 LOADMEM_TO_VAR(u16 page)				// var2=eeprom or var2=default
{
	char string[100];
	u16 i, j, counter;
	u32 address;

	if (page > PageLimit)
		return 0;
	address = addresspage + 0x400 * (page + 6);
	if (*(vu16*) (address) == 0xffff)
		return 0;

	address = address + 38;
	for (i = 0; i < var2i; i++)
		for (j = 0; j < var2j; j++) {
			address = address + 2;

			var2[i][j] = *(vu16*) (address);
		}

	update_var(0xfffe, 1);				// make a new change page

	vartomem(1);			// to store var2 in eeprom valid page to current use

}

void inc(void) {
#define localecho 1
#define IncPage addresspage+0x1000
	u32 i = 0, j = 0, counter;
	u32 address;
	char string[10];

	HAL_FLASH_Unlock();

	i = 0;
	address = IncPage;
	echo
	"\n inc : address=%x", address
	);
	//sendecho

	do {
		counter = i;
		i = *(vu16*) (address);
		j = *(vu16*) (address + 2);
		i = (j << 16) | (i & 0xffff);
		echo
		"\ninc#2 : i=%u ,counter=%u, j= %u,addr=%x", i, j, counter, address
		);
		//sendecho
		if (i != 0xffffffff)
			address += 4;
		if (address >= (IncPage + 0x400 - 4)) {
			counter = i;
			FLASH_ErasePage(IncPage);
			address = IncPage;
			i = 0xffffffff;
			echo
			"\ninc overpage: i=%x ,counter=%d, address= %x", i, counter, address
			);
			sendecho
		}
	} while (i != 0xffffffff);

	i = counter + 1;
	echo
	"\n inc:/ before save i=%d,counter=%d, address=%x", i, counter, address
	);
	sendecho

	FLASH_ProgramHalfWord((address), i & 0xffff);

	FLASH_ProgramHalfWord((address + 2), (i >> 16) & 0xffff);

	HAL_FLASH_Lock();

}
u16 getcounter(u16 address) {

}

void putdigit_xy(int x, int y, char a, int c) {

	int i;
	i = 0;

}

void showpic_xy(u32 u, char x, u32 y) {

}

void monitorn(void) {
}
void keyscan(void) {
	int i;
	/*stDDRA=0x0;
	 PORTA=0xff;
	 DDRB.7=1;
	 DDRB.6=1;
	 DDRD.0=1;
	 if(cul&1)PORTB.7=1; else PORTB.7=0;
	 if(cul&2)PORTD.0=1; else PORTD.0=0;
	 if(cul&4)PORTB.6=1; else PORTB.6=0;
	 */
	if (autokey) {
		lockkey = 0;
		autokey = 0;
	}
	for (i = 0; i < 5; i++)
		;
	//strow=PINA;
	//row=1;//aft
	if (row ^ 0xff) {
		if (!kd--) {
			if (!lockkey) {
				//autokey=0;
				//imagekey=0xff;
				if (row == 254)
					s = 0;
				if (row == 253)
					s = 1;
				if (row == 251)
					s = 2;
				if (row == 247)
					s = 3;
				if (row == 239)
					s = 4;
				if (row == 223)
					s = 5;
				if (row == 191)
					s = 6;
				if (row == 127)
					s = 7;
				//OFT lockkey=1;
				//OFT  keycode=(cul<<3)+s;
				//OFT keypress=1;
				//OFT beep=1;
				//OFT  beepcounter=40;
				if (keycode != 7) {

					brightcun = 1000;
				}
			}
		}
	} else {
		//OFT  lockkey=0;
		//OFT kd=50;
		//OFT  cul++;
		//OFT  if(cul==7)cul=0;
	}

	//stPORTD.0=1;
	//stPORTB.7=1;
	//stPORTB.6=1;
	//stDDRA=0xff;

	if (imagekey != 0xff && !lockkey) {
		keycode = imagekey;
		lockkey = 1;
		if (!autokey2) {
			keypress = 1;
		}
		autokey = 1;
		autokey2 = 1;
	} else
		autokey2 = 0;

}

void cycle(void)	//ok1
{

	if (semiauto2) {
		if (finish) {

			if (timer)
				// {imagekey=255;}
			{
				lockkey1 = 0;
			} else {
				//imagekey=cyclea[state];
				if (state == 5 && mavad2) {
					mavad2 = 0;
					state = 3;
				}
				if (state == 0) {
					if (var2[3][8])
						mavad2 = 1;
					timer = 0;
					totaltime = 0;
					timestart = 1;
					if (var2[5][10]) {
						pnum = var2[5][10] - 1;
					} else
						pnum = 0;
					if (var2[6][16]) {
						lockkey1 = 1;
						pci1 = 1;
						timer = var[6][2];
					} else
						state++;
				}
				if (state == 1) {
					if (LMC) {
						timer2 = var2[0][8];
						lockkey1 = 1;
						pmc1 = 1;
						temp111 = 1;
						yekst = 1;
					} else
						state++;
				}
				if (state == 2) {
					lockkey1 = 1;
					puf1 = 1;
				}
				if (state == 3) {
					if (mavad2)
						state++;
					else {
						lockkey1 = 1;
						pri1 = 1;
						ritime = 0;
					}
				}
				if (state == 4) {
					lockkey1 = 1;
					pbri1 = 1;
					ritime = 0;
				}
				if (state == 5) {
					clrout3;
					{
						lockkey1 = 1;
						pmri1 = 1;
					}
					tempp = 0;
				}
				if (state == 6) {
					if (var[2][8]) {
						timer = var[2][6];
						lockkey1 = 1;
						pub1 = 1;
					} else
						state++;
				}
				if (state == 7) {
					yekst = 1;
					timer = var2[1][20] * 10;
					lockkey1 = 1;
					pmo1 = 1;
					if (lock2 && maxcomponent < 1000000)
						maxcomponent++;
					ccunter++;
					oilnumber++;
				}
				if (state == 8) {
					fffk = 1;
					if (var[7][8]) {
						lockkey1 = 1;
						pgb1 = 1;
						ritime1 = 0;
					} else
						state++;
				}
				if (state == 9) {
					fffk = 1;
					if (var2[6][17]) {
						lockkey1 = 1;
						pepm1 = 1;
					} else
						state++;
				}
				if (state == 10) {
					fffk = 1;
					if (var[6][7]) {
						lockkey1 = 1;
						pco1 = 1;
						timer = var[6][5];
					} else
						state++;
				}
				if (state == 11) {
					fffk = 1;
					if (var[5][8]) {
						lockkey1 = 1;
						pef1 = 1;
						timer = var2[5][0];
					} else
						state++;
				}
				if (state == 12) {
					fffk = 1;
					if (var[5][8]) {
						lockkey1 = 1;
						peb1 = 1;
						timer = var[5][5];
					} else
						state += 2;
				}

				//    timer=60;
				if (state != 14)
					state++;
				state2 = state;
				if (state >= 13) {
					if (pnum) {
						pnum--;
						state = 11;
						state2 = 13;
					}
				}

				if (state == 14 && timefull >= var[9][2]) {
					clrout13;
					tempp = 0;
					timefull = 0;
					state = 0;
					state2 = 0;
					lockkey1 = 0;
					semiauto2 = 0;
					timestart = 0;
					timep = totaltime;
					if (timep)
						tedad = 36000 / timep;
				}	//semiauto=0;
				if (state != 14)
					finish = 0;

				autokey2 = 0;
				if (state < 14 || !(timefull % 10))
					refresh2 = 1;
			}

		}

	} else {
		finish = 0;
		state = 0;
		imagekey = 0xff;
		if (!protection) {
			timer = 0;
		}
		clrout13;
		clrout9;
		clrout24;
		clrout23;
		tempp = 0;
		clrout3;
		clrout17;
		clrout14;
		pci1 = 0;
		pmc1 = 0;
		puf1 = 0;
		pri1 = 0;
		pbri1 = 0;
		pmri1 = 0;
		pub1 = 0;
		pmo1 = 0;
		pgb1 = 0;
		pepm1 = 0;
		pco1 = 0;
		pef1 = 0;
		peb1 = 0;
	}
	//imagekey=cycl}

	mode = semiauto;

}

void calibration(void) {

	float culvar1, culvar2, culvar3, culvar4;
	//page0
	culvar1 = maxruler1;
	culvar2 = 1023;
	culvar3 = var[0][2];
	culvar4 = (culvar2 / culvar1) * culvar3;
	ruler1p1 = culvar4;
	culvar3 = var[0][3];
	culvar4 = (culvar2 / culvar1) * culvar3;
	ruler1p2 = culvar4;
	culvar3 = var[0][6];
	culvar4 = (culvar2 / culvar1) * culvar3;
	ruler1p3 = culvar4;
	speedv1 = var[0][0] % 100;
	perv1 = var[0][0] / 100;

	speedv2 = var2[0][11];

	//speedv2=var[0][1]%100;
	perv2 = var[0][1] / 100;

	speedv3 = var[0][1] % 100;
	//perv3=var[0][4];
	perv3 = var2[0][10];
	speedv19 = var[0][5] % 100;
	perv19 = var[0][5] / 100;

	speedv4 = var[0][0] % 100;
	perv4 = var[0][0] / 100;
	speedehteyat = var2[0][11];

	//page1

	perv5 = var[1][0];
	speedv5 = var[1][1];
	culvar1 = maxruler1;
	culvar2 = 1023;
	culvar3 = var[1][2];
	culvar4 = (culvar2 / culvar1) * culvar3;
	ruler1p4 = culvar4;

	perv6 = var[1][3];
	speedv6 = var[1][4];
	culvar1 = maxruler1;
	culvar2 = 1023;
	culvar3 = var[1][5];
	culvar4 = (culvar2 / culvar1) * culvar3;
	ruler1p5 = culvar4;

	perv7 = var[1][6];
	speedv7 = var[1][7];
	culvar1 = maxruler1;
	culvar2 = 1023;
	culvar3 = var[1][8];
	culvar4 = (culvar2 / culvar1) * culvar3;
	ruler1p6 = culvar4;

	culvar1 = maxruler3;
	culvar2 = 1023;
	culvar3 = var2[2][1];
	culvar4 = (culvar2 / culvar1) * culvar3;
	ruler3p1 = culvar4;

	culvar1 = maxruler3;
	culvar2 = 1023;
	culvar3 = var2[2][5];
	culvar4 = (culvar2 / culvar1) * culvar3;
	ruler3p2 = culvar4;

	culvar1 = maxruler3;
	culvar2 = 1023;
	culvar3 = var2[5][1];
	culvar4 = (culvar2 / culvar1) * culvar3;
	ruler3p3 = culvar4;

	culvar1 = maxruler3;
	culvar2 = 1023;
	culvar3 = var2[5][5];
	culvar4 = (culvar2 / culvar1) * culvar3;
	ruler3p4 = culvar4;

	culvar1 = maxruler1;
	culvar2 = 1023;
	culvar3 = var2[6][9];
	culvar4 = (culvar2 / culvar1) * culvar3;
	ruler1p7 = culvar4;

	//page2
	perv8 = var[2][0];
	speedv8 = var[2][1];
	culvar1 = maxruler2;
	culvar3 = var[2][2];
	culvar4 = (culvar2 / culvar1) * culvar3;
	//ruler3p1=culvar4;

	perv9 = var[2][3];
	speedv9 = var[2][4];
	culvar1 = maxruler2;
	culvar3 = var[2][5];
	culvar4 = (culvar2 / culvar1) * culvar3;
	//ruler3p2=culvar4;

	delay1 = var[2][6];
	delay2 = var[2][7];
	//silehteyat=var[2][8];

	//page3
	perv10 = var[3][0];
	speedv10 = var[3][1];
	culvar1 = maxruler2;
	culvar3 = var[3][2];
	culvar4 = (culvar2 / culvar1) * culvar3;
	ruler2p4 = culvar4;

	delay3 = var[3][3];

	perv11 = var[3][4];
	speedv11 = var[3][5];
	culvar1 = maxruler2;
	culvar3 = var[3][6];
	culvar4 = (culvar2 / culvar1) * culvar3;
	ruler2p3 = culvar4;

	delay4 = var[3][7];
	mkeshact = var[3][8];

	//page4

	culvar1 = maxruler2;
	culvar3 = var[4][2];
	culvar4 = (culvar2 / culvar1) * culvar3;
	ruler2p1 = culvar4;
	culvar3 = var[4][8];
	culvar4 = (culvar2 / culvar1) * culvar3;
	ruler2p2 = culvar4;

}

void statecontroll(void) {
	//switch(state)
}

void putdigit_xy_space(int x, int y, unsigned long int a, int c, char space) {

}
