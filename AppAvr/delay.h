/*
 * =====================================================================================
 *
 *       Filename:  delay.h
 *
 *    Description:  常用延时函数定义
 *
 *        Version:  1.0
 *        Created:  2013-8-11 19:16:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yiluoyang (), gfcocos@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#ifndef DELAY_H
#define DELAY_H

#include "common.h"


void delay_us(void);
void delay_xus(BYTE t);
void delay_ms(void);
void delay_xms(BYTE t);
void delay_xs(BYTE t);
#endif /* end of include guard: DELAY_H */
