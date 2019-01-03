/*
 * function.h
 *
 *  Created on: ? Ï? ???? åž.Ô.
 *      Author: pr
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

#include "stm32f10x_type.h"

int getkey (void);
int getkey2 (void);
void send_string(char *str);
void jtag_Disable(void);
unsigned char read_ppi(unsigned char);
void keyscan(void);
void vartomem(u16);
void update_var(int, u16);
void findvalidpage(void);
void memload(void);
void inc(void);
void main_timer(void);
u16 get_var(u32);
u16 STORE_TO_MEM(u16, char *);
u16 LOADMEM_TO_VAR(u16);

#endif /* FUNCTION_H_ */
