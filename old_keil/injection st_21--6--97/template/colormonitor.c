//================variables 

#include "math.h"

 #define BLACK 0
#define RED 0xf800
#define GREEN 0x07e0
#define BLUE 0x1f
#define WHITE 0xffff



unsigned int
 picnumber,bufpointer,bufsize,textpointer,itemp,maxbufsize=0,brightcun=1000;
  float ftemp;

//unsigned long int
 unsigned char str[20]="mehdi";
 unsigned  int color1,color2=0xf801;
unsigned char lcdbuf[550],picbuf[300],transmit=1,varselect,cheshmak,
bright=0x40,oldbright=0,picpast_add=0x0b,lcdbus,timebase2,oldpageco,
receive_data[18],r_d_pointer;

unsigned int
  key_y,
   key_x,
old[97],oldc[96],
  x_sine=0,
    y_sine=0,
    x2_sine=15,
    y2_sine=15,

    x_dis=100,
    y_dis=100,
    x_dis_shift=150,
    y_dis_shift=30,
    picpast_flag,
  sine[5],old_sine[5];
 /*flash*/ const unsigned int xpos[]={ 45 ,45,185,145,20 ,20, 20, 20, 480,465,405,680,343,343,343,343,343,343                      }
            , ypos[]={103, 128, 60,128,162,195,225,455,162,400,455,455 ,305,333,362,392,423,450                    };

 /*flash*/ const unsigned char strl[]={3,3,3,4,4,5,5,3,5,5,
                            3,4,5,4,4,5,4,4,3,5,
                            3,11,11,5,5,5,5,5,5,5,
                            5,11,5,5,5,5,5,5,5,5,
                            5,5,5,5,11,5,5,5,5,5,
                            5,5,5,5,5,5,5,5,5,5,
                            5,5,5,5,5,5,5,5,5,5,
                            5,5,5,5,5,5,5,5,5,5,
                            5,5,5,5,5,5,5,5,5,5,
                            5,5,5,5,5,5,5,5,5,5

                            };
                               //29
/*flash*/const  unsigned char var_valid[]={
                                1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,1,1,1,1,1
                               ,0,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,1,1,1,1,1
                               ,0,0,1,1, 0,1,1,1, 1,1,1,1, 1,0,1,1, 0,1,1,1, 1,1,1,1,1,1,1,1,1
                               ,0,0,1,1, 1,0,1,1, 0,1,1,1, 0,1,1,1, 0,1,1,1, 1,1,1,1,1,1,1,1,1
                               ,0,1,1,1, 0,1,1,1, 1,0,0,0, 1,1,1,1, 1,1,1,1, 1,1,1,1,1,1,1,1,1
                               ,1,1,1,1, 0,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,1,1,1,1,1
                               ,1,1,1,1, 1,1,1,1, 1,0,1,1, 0,0,0,0, 1,0,0,0, 1,1,1,1,1,1,1,1,1
                               ,1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,1,1,1,1,1
                               ,1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,1,1,1,1,1
                               ,1,1,1,1, 1,1,1,1, 0,0,1,1, 0,0,1,1, 1,1,1,1, 1,1,1,1,1,1,1,1,1
                               ,1,1,1,1, 1,0,0,0, 1,0,0,0, 1,0,0,0, 1,0,0,0, 1,1,1,1,1,1,1,1,1
                               ,1,1,1,1, 1,1,1,1, 1,1,1,1, 0,0,1,1, 1,1,1,1, 1,1,1,1,1,1,1,1,1
                            };


/*flash*/ const unsigned int op_x[]={270,270,270,270,270,270,270,270,270,270,270,270,270,270,270 }
                 ,
                   op_y[]={ 30, 450, 90,120,150,180,210,240,270,300,330,360,390,420,60}
                  ,op_x_dif=170,op_y_dif=30;
/*flash*/ const unsigned int er_x[]={270,440,270,270,270,270,270,270,270,270,270,270,270,270,270,16,17,18,609,100,21,270,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,440,42,43,44,45,46,47,48,49,50,51,52,53,54,55 }
                 ,
                   er_y[]={ 30, 300, 90,120,150,180,210,240,270,300,330,360,390,420,450,30,60,90,63,150,180,210,240,270,300,330,360,390,420,30,60,90,120,150,180,210,240,270,300,330,360,390,420 }




                  ,er_x_dif=170,er_y_dif=30;

/*flash*/ const unsigned char touch_command[]={0xA5,0x5A,0x03,0x81,0x07,4,0xa5,0x5a,0x03,0x80,0x07,0xff,0xa5,0x5a,0x03,0x80,0x05,0x00 };
unsigned char touch_command_pointer=18,serial_data_valid;
                  //  x,y,x1,y1  keycode
/*flash*/ const unsigned int all_page_key[]={
                       0  ,  0,400,280,   1,
                       0  ,280,400,480,   2,
           //            400,0  ,800,280,   3,
                       400,280,800,480,   4,
                       0xffff
};
int touch_key;

//==================functions=============
void ftoa(float num,char point,unsigned char* strp)
{
	int i=0,n;
	num=num*pow(10,point);
	n=num;
	num=n;
	sprintf(strp,"%f",num);
	//send_string(strp);
	
	
}

void picpast(int picturen,int x1,int y1,int sizex ,int sizey,int x2,int y2)
{
 if(!picnumber)
    {
     picbuf[0]=0xa5;
     picbuf[1]=0x5a;
     //picbuf[2]=0x22;
     picbuf[3]=0x82;
     picbuf[4]=picpast_add;
     picbuf[5]=0x00;
     picbuf[6]=0;
     picbuf[7]=0x06;

    }


    picbuf[10+(picnumber*14)]=((picturen &0xff00)>>8);
    picbuf[11+(picnumber*14)]=(picturen &0xff);
    picbuf[12+(picnumber*14)]=((x1 &0xff00)>>8);
    picbuf[13+(picnumber*14)]=(x1 &0xff);
    picbuf[14+(picnumber*14)]=((y1 &0xff00)>>8);
    picbuf[15+(picnumber*14)]=(y1 &0xff);
    picbuf[16+(picnumber*14)]=((sizex &0xff00)>>8);
    picbuf[17+(picnumber*14)]=(sizex &0xff);
    picbuf[18+(picnumber*14)]=((sizey &0xff00)>>8);
    picbuf[19+(picnumber*14)]=(sizey &0xff);
    picbuf[20+(picnumber*14)]=((x2 &0xff00)>>8);
    picbuf[21+(picnumber*14)]=(x2 &0xff);
    picbuf[22+(picnumber*14)]=((y2 &0xff00)>>8);
    picbuf[23+(picnumber*14)]=(y2 &0xff);



    picnumber++;
    picbuf[2]=picnumber*14+7;
    picbuf[8]=((picnumber &0xff00)>>8);
    picbuf[9]=(picnumber &0xff);
    picpast_flag=1;


}
/*
interrupt [USART0_TXC] void usart0_tx_isr(void)
{
char status,data;
status=UCSR0A;


if(touch_command_pointer<6){

                               UDR0=touch_command[touch_command_pointer];touch_command_pointer++;
                               serial_data_valid=0;
                               r_d_pointer=0;
                              }
                              else
                               if(touch_command_pointer<18 && serial_data_valid)
                               {

                               UDR0=touch_command[touch_command_pointer];touch_command_pointer++;

                              }



else
//if(touch_command_pointer==18 && transmit)
{
 if(bufpointer<=bufsize){UDR0=lcdbuf[bufpointer];bufpointer++;transmit=1;} else {transmit=0;colorm();}
 if(bufsize>maxbufsize)maxbufsize=bufsize;

}

}

*/

void makebuf(void)
{
int i,j;
//j=picnumber*14+11;
j=picnumber*14+10;
for(i=0;i<j;i++)lcdbuf[i+bufsize]=picbuf[i];
bufpointer=0;
bufsize+=j;
textpointer=bufsize+1;

//UDR0=0;
//transmit=1;

}
void pageid(char page)
{
lcdbuf[bufsize]=0xa5;
bufsize++;
lcdbuf[bufsize]=0x5a;
bufsize++;
lcdbuf[bufsize]=4;
bufsize++;
lcdbuf[bufsize]=0x80;
bufsize++;
lcdbuf[bufsize]=0x03;
bufsize++;
lcdbuf[bufsize]=0;
bufsize++;
lcdbuf[bufsize]=page;
bufsize++;





}

void  lcd_beep(char time)//time*40 msec beep
{

lcdbuf[bufsize]=0xa5;
bufsize++;
lcdbuf[bufsize]=0x5a;
bufsize++;
lcdbuf[bufsize]=3;
bufsize++;
lcdbuf[bufsize]=0x80;
bufsize++;
lcdbuf[bufsize]=0x02;
bufsize++;
lcdbuf[bufsize]=time;
bufsize++;
  




}





void brightness(char page)
{
lcdbuf[bufsize]=0xa5;
bufsize++;
lcdbuf[bufsize]=0x5a;
bufsize++;
lcdbuf[bufsize]=3;
bufsize++;
lcdbuf[bufsize]=0x80;
bufsize++;
lcdbuf[bufsize]=0x01;
bufsize++;
lcdbuf[bufsize]=page;
bufsize++;





}


void cleart(char it)
{
char i;

for(i=0;i<strl[it];i++)
  {
   str[i]=' ';
  }
  str[i]=0;



 }

void cleartext(void )
{
  int i;
  i=0;
 while(str[i]!=0)
 {str[i]=' ';
 i++;
 }


 }

 void puttext(unsigned char x,int textbox,char *strm)
 {
 int i=0;
 while(strm[i]!=0)
 {
  str[x+i]=strm[i];
  i++;
  }
  }
void putnumber(unsigned char x,int textbox,float num,char point)
 {
 int i=0,len;
 unsigned char strp[20];
  len=x;
if(point<7)
 {

  ftoa(num,point,strp);
 while(strp[i]!=0 && str[x+i]!=0)
 {
  str[x+i]=strp[i];
  i++;

  }
 //str[i+x]=0;
 }
 else
  {
  
   ftoa(num,point,strp);
 while(strp[i]!=0 && str[x+i]!=0)
 {
  str[x+i]=' ';
  i++;

  }
  

  }


 }
void settext(int textbox, unsigned char  textsize, int textcolor, int x,int y,int lenght)
{
unsigned int address;

 address=(textbox*0x60+0x31);
 lcdbuf[textpointer]=0xa5;
 textpointer++;
 bufsize++;
lcdbuf[textpointer]=0x5a;
 textpointer++;
 bufsize++;

 textpointer++;
 bufsize++;
lcdbuf[textpointer]=0x82;
 textpointer++;
 bufsize++;
lcdbuf[textpointer]=((address>>8)&0xff)|(varselect<<4);
 textpointer++;
 bufsize++;
lcdbuf[textpointer]=((address)&0xff);
 textpointer++;
 bufsize++;
lcdbuf[textpointer]=(x>>8)&0xff;   //textposition
 textpointer++;
 bufsize++;
lcdbuf[textpointer]=x&0xff;
 textpointer++;
 bufsize++;
lcdbuf[textpointer]=(y>>8) & 0xff;
 textpointer++;
 bufsize++;
lcdbuf[textpointer]=(y) & 0xff;
 textpointer++;
 bufsize++;
 lcdbuf[textpointer]=(textcolor>>8) & 0xff;
 textpointer++;
 bufsize++;
lcdbuf[textpointer]=(textcolor) & 0xff;
 textpointer++;
 bufsize++;
   //************text box****************//
 lcdbuf[textpointer]=0;
 textpointer++;
 bufsize++;
 lcdbuf[textpointer]=0;
 textpointer++;
 bufsize++;
 lcdbuf[textpointer]=0;
 textpointer++;
 bufsize++;
 lcdbuf[textpointer]=0;
 textpointer++;
 bufsize++;
 lcdbuf[textpointer]=((799)>>8)&0xff;
 textpointer++;
 bufsize++;
 lcdbuf[textpointer]=799&0xff;
 textpointer++;
 bufsize++;
 lcdbuf[textpointer]=(479 >>8) & 0xff;
 textpointer++;
 bufsize++;
 lcdbuf[textpointer]=(479) & 0xff;
 textpointer++;
 //**********text lenght*****************//
bufsize++;
lcdbuf[textpointer]=0;
 textpointer++;
 bufsize++;
lcdbuf[textpointer]=(lenght) & 0xff;
 textpointer++;
 bufsize++;
 //********************font************//
lcdbuf[textpointer]=0;
 textpointer++;
 bufsize++;

lcdbuf[textpointer]=0;
 textpointer++;
 bufsize++;
 //********************size**************//
 lcdbuf[textpointer]=textsize;
 textpointer++;
 bufsize++;
 lcdbuf[textpointer]=textsize;
 textpointer++;
lcdbuf[2]=23;

}


void setcolor(int textbox,  int textcolor)
{
unsigned int address;

 address=(textbox*0x60)+(0x33);
 lcdbuf[textpointer]=0xa5;
 textpointer++;
 bufsize++;
lcdbuf[textpointer]=0x5a;
 textpointer++;
 bufsize++;
lcdbuf[textpointer]=5;
 textpointer++;
 bufsize++;
lcdbuf[textpointer]=0x82;
 textpointer++;
 bufsize++;
lcdbuf[textpointer]=((address>>8)&0xff);
 textpointer++;
 bufsize++;
lcdbuf[textpointer]=((address)&0xff);
 textpointer++;
 bufsize++;

 lcdbuf[textpointer]=(textcolor>>8) & 0xff;
 textpointer++;
 bufsize++;
lcdbuf[textpointer]=(textcolor) & 0xff;
 textpointer++;
 bufsize++;
//lcdbuf[2]=5;

}

void printl(int textbox,char *str)
{
int i;
// bufsize+=strlen(str);

 lcdbuf[textpointer]=0xa5;
 textpointer++;
lcdbuf[textpointer]=0x5a;
 textpointer++;

 textpointer++;
lcdbuf[textpointer]=0x82;
 textpointer++;
lcdbuf[textpointer]=(((textbox*0x60)>>8)&0xff )|(varselect<<4);
 textpointer++;
lcdbuf[textpointer]=((textbox*0x60))&0xff;
 textpointer++;
 i=0;
do{
lcdbuf[textpointer]=str[i];
 textpointer++;
  i++;
  }while(str[i]!=0);
  lcdbuf[textpointer-(i+4)]=i+3;
 // bufsize+=i+6;
bufsize=textpointer;
}

void cpp(unsigned char l1,unsigned char l2,int textbox,float num,char point)
{

if(bufsize<600)
{
 if(l1==l2)

  {if(oldc[textbox]!=color2){oldc[textbox]=color2;setcolor(textbox,color2);}}

  else
  {if(oldc[textbox]!=color1){oldc[textbox]=color1;setcolor(textbox,color1);}}


	if(old[textbox]!=num)
 {




 cleart(textbox);
  putnumber(0,textbox,num,point);




	 printl(textbox,str);

 old[textbox]=num;
 }
 }
}

void tik(unsigned char l1,unsigned char l2,int textbox,int num,int x,int y)
{
  int x_tik,y_tik;
   int tik_size=15;
  if(!num)
      {
      x_tik=15;
      y_tik=0;

      }else
      {
       x_tik=30;
       y_tik=0;

      }




// if(1==l2))
 {




 //cleart(textbox);
 //putnumber(0,textbox,num,point);
 if(l1==l2){
            if(cheshmak & 4)picpast(35,x_tik,y_tik,x_tik+tik_size,y_tik+tik_size,x,y);
            }
  else {
        picpast(35,x_tik,y_tik,x_tik+tik_size,y_tik+tik_size,x,y);
        }

 //old[textbox]=num;
 }

}



void setlcd(void)
{

for(itemp=0;itemp<18;itemp++)
{

     bufpointer=0;
bufsize=0;
textpointer=0;

settext(itemp,22,0,xpos[itemp],ypos[itemp],strl[itemp]);
cleart(itemp);
putnumber(0,itemp,itemp,0);
printl(itemp,str);

//st UDR0=0;
transmit=1;
while(transmit);
delay_ms(10);
}


}
void setlcd2(void)
{

for(itemp=0;itemp<24;itemp++)
{

bufpointer=0;
bufsize=0;
textpointer=0;

settext(itemp,23,0x00ff,0,itemp*20,strl[itemp]);
cleart(itemp);
putnumber(0,itemp,itemp,0);
printl(itemp,str);
//st UDR0=0;
transmit=1;
while(transmit);
delay_ms(10);
}



}


/*

void colorm(void)
{
int ffff,j;
char i;
varselect=0;
picnumber=0;

if(!transmit)
{
bufpointer=0;
bufsize=0;
textpointer=0;
//cheshmak^=1;

picpast_flag=0;
picpast_add=0x18;
//if(state2<14) picpast(45,op_x[state2],op_y[state2],op_x[state2]+op_x_dif,op_y[state2]+op_y_dif,407,8); //íÑå ÈÓÊå 1
//  if(errorcode)picpast(35,er_x[state2],er_y[state2],er_x[state2]+er_x_dif,er_y[state2]+er_y_dif,63,6);

//makebuf();
 if(page==13)
   {
    sine[0]=outputa;
    sine[1]=outputb;
    sine[2]=outputc;
    sine[3]=(read1<<4)|(read2&0xf);
    sine[4]=(read3<<4) |((read2>>4)&0xf);
    x_sine=0;
    y_sine=0;
    x2_sine=15;
    y2_sine=15;

    x_dis=125;
    y_dis=190;
    x_dis_shift=120;
    y_dis_shift=23;
    //picpast_add=0x0c;
    //if(sine[i]!=old_sine[i])
     for(i=0;sine[i]==old_sine[i] && i<6;i++);

     if(i<5)
       {
       old_sine[i]=sine[i];
       picpast_add+=i+1;
       x_dis+=i*x_dis_shift;
         j=0x1;
        do
          {

           if(sine[i] & j)picpast(35,x_sine,y_sine,x2_sine,y2_sine,x_dis,y_dis);
           if(!sine[i])picpast(35,x_sine,y_sine,x2_sine,y2_sine,0,470);

           y_dis+=y_dis_shift;

          j=j<<1;
          }while(j<0x1000);



       }





   }

picpast_add=0x18;
 if(!picpast_flag)
 // if(0)
    {


   picpast_add=0x18;
 if(errorcode)picpast(46,er_x[errorcode],er_y[errorcode],er_x[errorcode]+er_x_dif,er_y[errorcode]+er_y_dif,402,3);
else{
if(state2<14) picpast(45,op_x[state2],op_y[state2],op_x[state2]+op_x_dif,op_y[state2]+op_y_dif,402,3); //íÑå ÈÓÊå 1
     }
//picpast(35,0,0,15,15,100,100);
//picpast(35,0,0,15,15,100,50);
//picpast(35,0,0,15,15,100,390);

   }

 // tik(line2,5,8,var2[9][5],105,308); // max cycle time
//tik(line2,6,8,var2[9][6],105,344); // max cycle time
//tik(line2,7,8,var2[9][7],105,380); // max cycle time






color1=BLACK;
if(cheshmak & 4)color2=RED;else color2=GREEN;
//textpointer=bufsize+1;



cpp(0,1,0,line2,0);
cpp(0,1,1,file.fsize,0);
cpp(0,1,2,speed,0);
//cpp(0,1,1,maxbufsize,0);
//cpp(0,1,2,direction,0);



//if(state2==4 ||state2==3 || state2==5)putnumber(0,2,ritime,0);
  //    else  if(state2==14)putnumber(0,2,timefull,0);
    //                               else putnumber(0,2,timer,0);

                               //    else putnumber(0,2,timer,0);
         ftemp=timemax;
         cpp(1,0,3,ftemp/10,1);

                    if(!hitreal)
                          {
                    if(var[8][0]<40)tempreture[0]=var[8][0]+8;
                    if(var[8][1]<40)tempreture[1]=var[8][1]+8;
                    if(var[8][2]<40)tempreture[2]=var[8][2]+8;
                    if(var[8][3]<40)tempreture[3]=var[8][3]+8;
                    if(var[8][12]<40)tempreture[4]=var[8][12]+8;
                    if(PORTE.7)cpp(1,0,7, tempreture[0]>>1,0); else ; cpp(1,0,7, tempreture[0]>>1,0);
                                if(PORTE.6) cpp(1,17,4, tempreture[1]>>1,0);  else cpp(1,17,4, tempreture[1]>>1,0);
                                 if(PORTE.5) cpp(1,23,10, tempreture[2]>>1,0); else  cpp(1,23,10, tempreture[2]>>1,0);
                                 if(PORTE.4) cpp(1,28,14, tempreture[3]>>1,0); else  cpp(1,28,14, tempreture[3]>>1,0);
                                 if(PORTE.3) cpp(1,34,20, tempreture[4]>>1,0); else  cpp(1,34,20, tempreture[4]>>1,0);

                           }else
                           {
                               cpp(1,12,7, var[8][0],0);
                               cpp(1,27,4, var[8][1],0);
                               cpp(1,23,10, var[8][2],0);
                               cpp(1,28,14, var[8][3],0);
                               cpp(1,34,20, var[8][4],0);



                           }







if(state2==4 ||state2==3 || state2==5){ftemp=ritime;cpp(1,8,8,ftemp/10,1);}
      else  if(state2==14){ftemp=timefull;cpp(1,8,8,ftemp/10,1);}
                                   else {ftemp=timer;cpp(1,8,8,ftemp/10,1);}
     cpp(1,14,15,var2[9][0],0);
     cpp(1,19,12,var2[9][1],0);
     cpp(1,28,13,ruler1m,0);
  //   cpp(1,28,13,maxbufsize,0);
     cpp(1,38,17,ruler2m,0);
//cpp(1,0,21,temp,0); // max cycle time
if(page==0)
{
 cpp(1,0,11,timep,0); // max cycle time
 cpp(1,0,44,tedad,0); // component per hour
 cpp(1,0,9,timep,0); // max cycle time
 cpp(1,0,21,ccunter,0); // max cycle time
 cpp(1,0,22,temp,0); // max cycle time
//printl(22,char * error_msg[res]);
 cpp(1,0,37,oiltemp,0); // max cycle time



}
if(page==2)
{


ftemp=var2[0][20];
cpp(line2,20,11,ftemp/10,1);

 cpp(line2,4,28,var2[0][4],0); // max cycle time

 cpp(line2,1,25,ruler1m,0); // max cycle time
 cpp(line2,2,26,var2[0][2],0); // max cycle time
 cpp(line2,3,27,var2[0][3],0); // max cycle time

 cpp(line2,5,29,var2[0][5],0); // max cycle time
 cpp(line2,6,30,var2[0][6],0); // max cycle time
 cpp(line2,7,31,var2[0][7],0); // max cycle time
 //cpp(1ine2,6,31,var2[0][7],0); // max cycle time
 ftemp=var2[0][8];
 cpp(line2,8,32,ftemp/10,1); // max cycle time
 cpp(line2,9,33,var2[0][9],0); // max cycle time
 cpp(line2,10,34,var2[0][10],0); // max cycle time
 cpp(line2,11,35,var2[0][11],0); // max cycle time

  ftemp=var2[0][12];
 cpp(line2,12,36,ftemp/10,1); // max cycle time
 cpp(line2,13,37,var2[0][13],0); // max cycle time
 cpp(line2,14,38,var2[0][14],0); // max cycle time
 cpp(line2,15,39,var2[0][15],0); // max cycle time

 cpp(line2,16,40,var2[0][16],0); // max cycle time
 cpp(line2,17,41,var2[0][17],0); // max cycle time
 cpp(line2,18,42,var2[0][18],0); // max cycle time
 cpp(line2,19,43,var2[0][19],0); // max cycle time
 tik(line2,19,88,var2[0][19],100,100); // max cycle time



 }

 if(page==3)
{

ftemp=var2[1][20];
cpp(line2,20,11,ftemp,0);


 cpp(line2,1,25,var2[1][1],0); // max cycle time
 cpp(line2,2,26,var2[1][2],0); // max cycle time
 cpp(line2,3,27,var2[1][3],0); // max cycle time

 ftemp=var2[1][4];
 cpp(line2,4,28,ftemp/10,1); // max cycle time
 cpp(line2,5,29,var2[1][5],0); // max cycle time
 cpp(line2,6,30,var2[1][6],0); // max cycle time
 cpp(line2,7,31,var2[1][7],0); // max cycle time


 ftemp=var2[1][8];
 cpp(line2,8,32,ftemp/10,0); // max cycle time
 cpp(line2,9,33,var2[1][9],0); // max cycle time
 cpp(line2,10,34,var2[1][10],0); // max cycle time
 cpp(line2,11,35,var2[1][11],0); // max cycle time


  ftemp=var2[1][12];
 cpp(line2,12,36,ftemp/10,0); // max cycle time
 cpp(line2,13,37,var2[1][13],0); // max cycle time
 cpp(line2,14,38,var2[1][14],0); // max cycle time
 cpp(line2,15,39,var2[1][15],0); // max cycle time

 //cpp(line2,0,15,page,0); // max cycle time

 cpp(line2,16,40,var2[1][16],0); // max cycle time
 cpp(line2,17,41,var2[1][17],0); // max cycle time
 cpp(line2,18,42,var2[1][18],0); // max cycle time
 cpp(line2,19,43,var2[1][19],0); // max cycle time




 }


if(page==4)
{

tik(line2,13,88,var2[2][3],105,452);
ftemp=var2[2][12];
cpp(line2,12,11,ftemp/10,1);
cpp(line2,42,5,ftemp/10,9);






 cpp(line2,0,24,var2[2][0],9); // max cycle time
 cpp(line2,1,25,var2[2][1],0); // max cycle time
 cpp(line2,2,26,var2[2][2],0); // max cycle time
 cpp(line2,3,27,var2[2][3],0); // max cycle time
 ftemp=var2[2][4];
 cpp(line2,4,32,ftemp/10,9); // max cycle time
 cpp(line2,5,33,var2[2][5],0); // max cycle time
 cpp(line2,6,34,var2[2][6],0); // max cycle time
 cpp(line2,7,35,var2[2][7],0); // max cycle time

 ftemp=var2[2][8];
 cpp(line2,8,40,ftemp/10,1); // max cycle time
 cpp(line2,9,41,var2[2][9],9); // max cycle time
 cpp(line2,10,42,var2[2][10],9); // max cycle time
 cpp(line2,11,43,var2[2][11],9); // max cycle time



 }
if(page==5)
{
ftemp=var2[3][11];
cpp(line2,11,5,ftemp/10,1);


ftemp=var2[3][10];
cpp(line2,10,11,ftemp/10,1);

  ftemp=var2[3][0];
 cpp(line2,0,24,ftemp,0); // max cycle time
 cpp(line2,1,25,var2[3][1],0); // max cycle time
 cpp(line2,2,26,var2[3][2],0); // max cycle time
 cpp(line2,3,27,var2[3][3],0); // max cycle time

 //cpp(line2,0,11,line,0); // max cycle time

 ftemp=var2[3][8];
 cpp(line2,40,32,ftemp,0); // max cycle time
 cpp(line2,48,34,var2[3][5],9); // max cycle time
 cpp(line2,44,35,var2[3][6],9); // max cycle time
// cpp(line2,19,13,var2[3][7],0); // max cycle time

 ftemp=var2[3][4];
 cpp(line2,4,36,ftemp/10,1); // max cycle time
 cpp(line2,5,37,var2[3][5],0); // max cycle time
 cpp(line2,6,38,var2[3][6],0); // max cycle time
 cpp(line2,7,39,var2[3][7],0); // max cycle time

  ftemp=var2[3][8];
 cpp(line2,8,40,ftemp,0); // max cycle time

 tik(line2,8,88,var2[3][8],105,378); // max cycle time
 tik(line2,9,88,var2[3][9],105,415); // max cycle time



// cpp(line2,8,15,var2[3][13],0); // max cycle time
// cpp(line2,14,15,var2[1][14],0); // max cycle time
 //cpp(line2,19,15,var2[1][15],0); // max cycle time

 //cpp(line2,0,15,page,0); // max cycle time
// cpp(line2,0,16,var2[1][16],0); // max cycle time
// cpp(line2,8,16,var2[1][17],0); // max cycle time
// cpp(line2,14,16,var2[1][18],0); // max cycle time
// cpp(line2,19,16,var2[1][19],0); // max cycle time



 }
 if(page==6)
{
ftemp=var2[4][16];
cpp(line2,16,11,ftemp/10,1);

ftemp=var2[4][10];
//cpp(line2,0,5,ftemp/10,1);
ftemp=var2[4][11];
//cpp(line2,0,6,ftemp/10,1);

  ftemp=var2[4][0];
 cpp(line2,0,24,ftemp/10,1); // max cycle time
 cpp(line2,1,25,var2[4][1],0); // max cycle time
 cpp(line2,2,26,var2[4][2],0); // max cycle time
 cpp(line2,3,27,var2[4][3],0); // max cycle time
 //cpp(line2,0,11,line,0); // max cycle time
 ftemp=var2[4][4];
 cpp(line2,4,28,ftemp/10,1); // max cycle time
 cpp(line2,5,29,var2[4][5],0); // max cycle time
 cpp(line2,6,30,var2[4][6],0); // max cycle time
 cpp(line2,7,31,var2[4][7],0); // max cycle time

 ftemp=var2[4][8];
 cpp(line2,8,32,ftemp/10,1); // max cycle time
 cpp(line2,9,33,var2[4][9],0); // max cycle time
 cpp(line2,10,34,var2[4][10],0); // max cycle time
 cpp(line2,11,35,var2[4][11],0); // max cycle time

  ftemp=var2[4][12];
 cpp(line2,35,36,ftemp/10,9); // max cycle time
 cpp(line2,35,37,var2[4][13],9); // max cycle time
 cpp(line2,35,38,var2[4][14],9); // max cycle time
 cpp(line2,35,39,var2[4][15],9); // max cycle time
 cpp(line2,35,40,var2[4][15],9); // max cycle time
 cpp(line2,35,41,var2[4][15],9); // max cycle time
 cpp(line2,35,42,var2[4][15],9); // max cycle time
 cpp(line2,35,43,var2[4][15],9); // max cycle time
cpp(line2,35,44,var2[4][15],9); // max cycle time

 //cpp(line2,0,15,page,0); // max cycle time
// cpp(line2,0,16,var2[4][16],0); // max cycle time
// cpp(line2,8,16,var2[4][17],0); // max cycle time
// cpp(line2,14,16,var2[4][18],0); // max cycle time
// cpp(line2,19,16,var2[4][19],0); // max cycle time


 //cpp(line2,0,17,temp,0); // max cycle time

 }


   if(page==7)
{
//ftemp=var2[5][8];
//cpp(line2,8,9,ftemp,0);
//ftemp=var2[5][9];
//cpp(line2,9,5,ftemp,0);

ftemp=var2[5][11];
cpp(line2,11,11,ftemp/10,1);
ftemp=var2[5][10];
cpp(line2,10,19,ftemp,0);

 tik(line2,8,88,var2[5][8],105,307); // max cycle time
 tik(line2,9,88,var2[5][9],105,380); // max cycle time


  ftemp=var2[5][0];
 cpp(line2,0,24,ftemp/10,1); // max cycle time
 cpp(line2,1,25,var2[5][1],0); // max cycle time
 cpp(line2,2,26,var2[5][2],0); // max cycle time
 cpp(line2,3,27,var2[5][3],0); // max cycle time

 //cpp(line2,0,11,line,0); // max cycle time
// cpp(line2,0,13,ftemp/10,1); // max cycle time
// cpp(line2,8,13,var2[5][5],0); // max cycle time
// cpp(line2,14,13,var2[5][6],0); // max cycle time
// cpp(line2,19,13,var2[5][7],0); // max cycle time

 ftemp=var2[5][4];
 cpp(line2,4,28,ftemp/10,1); // max cycle time
 cpp(line2,5,29,var2[5][5],0); // max cycle time
 cpp(line2,6,30,var2[5][6],0); // max cycle time
 cpp(line2,7,31,var2[5][7],0); // max cycle time

cpp(line2,37,32,var2[5][7],9); // max cycle time

cpp(line2,47,33,var2[5][7],9); // max cycle time
cpp(line2,47,34,var2[5][7],9); // max cycle time
cpp(line2,47,35,var2[5][7],9); // max cycle time
cpp(line2,47,36,var2[5][7],9); // max cycle time
cpp(line2,47,38,var2[5][7],9); // max cycle time
cpp(line2,47,39,var2[5][7],9); // max cycle time

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




    if(page==8)
{
ftemp=var2[6][16];
//cpp(line2,16,11,ftemp,0);
 tik(line2,16,88,var2[6][16],105,415); // max cycle time
 tik(line2,17,88,var2[6][17],105,380); // max cycle time

ftemp=var2[6][17];
//cpp(line2,17,5,ftemp,0);
ftemp=var2[6][10];
//cpp(line2,0,6,ftemp/10,1);

  ftemp=var2[6][0];
 cpp(line2,0,24,ftemp/10,1); // max cycle time
 cpp(line2,1,25,var2[6][1],0); // max cycle time
 cpp(line2,2,26,var2[6][2],0); // max cycle time
 cpp(line2,3,27,var2[6][3],0); // max cycle time
 //cpp(line2,0,11,line,0); // max cycle time
 ftemp=var2[6][4];
 cpp(line2,4,28,ftemp/10,1); // max cycle time
 cpp(line2,5,29,var2[6][5],0); // max cycle time
 cpp(line2,6,30,var2[6][6],0); // max cycle time
 cpp(line2,7,31,var2[6][7],0); // max cycle time

 ftemp=var2[6][8];
 cpp(line2,8,32,ftemp/10,1); // max cycle time
 cpp(line2,8,11,ftemp/10,1); // max cycle time
 cpp(line2,9,33,var2[6][9],0); // max cycle time
 cpp(line2,10,34,var2[6][10],0); // max cycle time
 cpp(line2,11,35,var2[6][11],0); // max cycle time

  ftemp=var2[6][12];
 cpp(line2,12,36,ftemp/10,1); // max cycle time
 cpp(line2,13,37,var2[6][13],0); // max cycle time
 cpp(line2,14,38,var2[6][14],0); // max cycle time
 cpp(line2,15,39,var2[6][15],0); // max cycle time

 //cpp(line2,0,15,page,0); // max cycle time

 }
   if(page==9)
{
ftemp=var2[7][16];
cpp(line2,46,11,ftemp,9);

ftemp=var2[7][17];
//cpp(line2,17,5,ftemp,0);

tik(line2,16,88,var2[7][16],105,380); // max cycle time
tik(line2,17,88,var2[7][17],105,308); // max cycle time



  ftemp=var2[7][0];
 cpp(line2,0,24,ftemp/10,1); // max cycle time
 cpp(line2,1,25,var2[7][1],0); // max cycle time
 cpp(line2,2,26,var2[7][2],0); // max cycle time
 cpp(line2,3,27,var2[7][3],0); // max cycle time
 printl(12,str);

 ftemp=var2[7][4];
 cpp(line2,4,28,ftemp/10,1); // max cycle time
 cpp(line2,5,29,var2[7][5],0); // max cycle time
 cpp(line2,6,30,var2[7][6],0); // max cycle time
 cpp(line2,7,31,var2[7][7],0); // max cycle time

 ftemp=var2[7][8];
 cpp(line2,8,32,ftemp/10,1); // max cycle time
 cpp(line2,9,33,var2[7][9],0); // max cycle time
 cpp(line2,10,34,var2[7][10],0); // max cycle time
 cpp(line2,11,35,var2[7][11],0); // max cycle time

  ftemp=var2[7][12];
 cpp(line2,12,36,ftemp/10,1); // max cycle time
 cpp(line2,13,37,var2[7][13],0); // max cycle time
 cpp(line2,14,38,var2[7][14],0); // max cycle time
 cpp(line2,15,39,var2[7][15],0); // max cycle time

 }
   if(page==10)
{
ftemp=var2[8][20];
cpp(line2,17,11,ftemp,0);

ftemp=var2[8][21];
cpp(line2,18,5,ftemp,0);
ftemp=var2[8][10];
//cpp(line2,0,6,ftemp/10,1);

  ftemp=var2[8][0];
 cpp(line2,0,44,ftemp,0); // max cycle time
 cpp(line2,1,45,var2[8][1],0); // max cycle time
 cpp(line2,2,46,var2[8][2],0); // max cycle time
 cpp(line2,3,47,var2[8][3],0); // max cycle time

 ftemp=var2[8][4];
 cpp(line2,4,48,ftemp,0);
 ftemp=var2[8][8];
 cpp(line2,8,49,ftemp,0);
 cpp(line2,8,50,ftemp,0);
 cpp(line2,8,51,ftemp,0);

 //cpp(line2,8,13,var2[8][5],0); // max cycle time
 //cpp(line2,14,13,var2[8][6],0); // max cycle time
 //cpp(line2,19,13,var2[8][7],0); // max cycle time


 cpp(line2,8,52,var2[8][8],0); // max cycle time
 cpp(line2,8,53,ftemp,0); // max cycle time
 cpp(line2,12,54,var2[8][12],0); // max cycle time
 cpp(line2,12,55,var2[8][12],0); // max cycle time

 ftemp=var2[8][12];
 cpp(line2,12,56,ftemp,0); // max cycle time
 cpp(line2,12,57,ftemp,0); // max cycle time
 cpp(line2,12,58,ftemp,0); // max cycle time
  ftemp=var2[8][16];
  cpp(line2,16,59,ftemp,0); // max cycle time

 //cpp(line2,0,15,page,0); // max cycle time

 cpp(line2,16,60,var2[8][16],0); // max cycle time
 cpp(line2,16,61,var2[8][16],0); // max cycle time
 cpp(line2,16,62,var2[8][16],0); // max cycle time
 cpp(line2,16,63,var2[8][16],0); // max cycle time



 }
   if(page==11)
{
//ftemp=var2[9][20];
cpp(line2,0,11,var2[9][0],0);
cpp(line2,1,5,var2[9][1],0);
cpp(line2,2,25,var2[9][2],0);
cpp(line2,3,29,var2[9][3],0);
cpp(line2,4,33,var2[9][4],0);
cpp(line2,44,37,var2[9][4],9);
tik(line2,5,88,var2[9][5],105,308); // max cycle time
tik(line2,6,88,var2[9][6],105,344); // max cycle time
tik(line2,7,88,var2[9][7],105,380); // max cycle time

//ftemp=var2[9][21];
//cpp(line2,0,5,ftemp,0);
//ftemp=var2[9][10];
//cpp(line2,0,6,ftemp/10,1);


//cpp(line2,0,7,temp,0);



  ftemp=var2[9][0];
 //cpp(line2,0,12,ftemp,0); // max cycle time
// cpp(line2,8,12,var2[8][1],0); // max cycle time
// cpp(line2,14,12,var2[8][2],0); // max cycle time
 //cpp(line2,19,12,var2[9][0],0); // max cycle time
 //cpp(line2,0,11,line,0); // max cycle time
 ftemp=var2[9][1];
 //cpp(line2,19,13,ftemp,0); // max cycle time
 //cpp(line2,8,13,var2[8][5],0); // max cycle time
 //cpp(line2,14,13,var2[8][6],0); // max cycle time
 //cpp(line2,19,13,var2[8][7],0); // max cycle time

 ftemp=var2[9][2];
// cpp(line2,19,14,ftemp,0); // max cycle time
// cpp(line2,8,14,var2[8][8],0); // max cycle time
 //cpp(line2,14,14,var2[8][8],0); // max cycle time
 //cpp(line2,19,14,var2[8][8],0); // max cycle time

  ftemp=var2[8][12];
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












if(page)cpp(1,0,21,temp,0);
 if(picpast_flag)makebuf();
if(oldpageco!=page)
             {
             pageid(page);
             oldpageco=page;
             }
           else

             if(bright!=oldbright)
              {
              oldbright=bright;
              brightness(bright);
              }

 if(brightcun<0x40)bright=brightcun;else bright=0x40;

UDR0=0;
transmit=1;

 }
}
*/
