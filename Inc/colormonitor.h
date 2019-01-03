/*
 * colormonitor.h
 *
 *  Created on: ? Ï? ???? åž.Ô.
 *      Author: pr
 */

#ifndef COLORMONITOR_H_
#define COLORMONITOR_H_

#define BLACK 0
#define RED 0xf800
#define GREEN 0x07e0
#define BLUE 0x1f
#define WHITE 0xffff
#define testmode 0
extern unsigned int picnumber, bufpointer, bufsize, textpointer, itemp,
maxbufsize, brightcun;
extern float ftemp ,old[97];//aft1 old was int and change to float to test cpp opration

extern unsigned char str[20];
extern unsigned int color1, color2;
extern unsigned char lcdbuf[550], picbuf[300], transmit, varselect, cheshmak,
bright, oldbright, picpast_add, lcdbus, timebase2, oldpageco,
receive_data[18], r_d_pointer;

extern unsigned int key_y, key_x,  oldc[96], x_sine, y_sine, x2_sine,
y2_sine, x_dis, y_dis, x_dis_shift, y_dis_shift, picpast_flag, sine[5],
old_sine[5];

extern const unsigned int xpos[],ypos[];
;

extern const unsigned char strl[];
extern const unsigned char var_valid[];

extern const unsigned int op_x[],op_y[],op_x_dif,op_y_dif;
extern const unsigned int er_x[],er_y[], er_x_dif , er_y_dif;

extern const unsigned char touch_command[];
extern unsigned char touch_command_pointer, serial_data_valid;
//  x,y,x1,y1  keycode
extern const unsigned int all_page_key[];
extern int touch_key;


void ftoa(float num, char point,  char* strp);
void picpast(int picturen, int x1, int y1, int sizex, int sizey, int x2, int y2);
void makebuf(void);
void pageid(char page);
void lcd_beep(char time);
void brightness(char page);
void cleart(char it);
void cleartext(void);
void puttext(unsigned char x, int textbox, char *strm);
void cpp(unsigned char l1, unsigned char l2, int textbox, float num, char point);
//void ftoa(float num, char point, unsigned char* strp);
//void printll(int textbox, char *str);
void printl(int textbox, char *str);
void putnumber(unsigned char x, int textbox, float num, char point);
void cleart(char it);
void setcolor(int textbox, int textcolor);





#endif /* COLORMONITOR_H_ */
