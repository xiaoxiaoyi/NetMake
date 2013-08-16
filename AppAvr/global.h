/*
 * =====================================================================================
 *
 *       Filename:  global.h
 *
 *    Description:  系统全局变量
 *
 *        Version:  1.0
 *        Created:  2013-8-14 20:57:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yiluoyang (), gfcocos@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef GLOBAL_H
#define GLOBAL_H
#include "common.h"

//数字缓冲区
extern INT8U map[];

extern INT8U pram[8];
extern const INT8U pram_float;

//数字字模
#define NUMBER_SIZEH 8
#define NUMBER_SIZEV 16
extern unsigned char const num[];

//开机画面
extern const CHAR bootimg[][17];

#endif /* end of include guard: GLOBAL_H */

