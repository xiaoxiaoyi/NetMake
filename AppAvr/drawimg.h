/*
 * =====================================================================================
 *
 *       Filename:  drawimg.h
 *
 *    Description:  画图
 *                  开机动画等.....
 *
 *        Version:  1.0
 *        Created:  2013-8-14 21:25:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yiluoyang (), gfcocos@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef DRAWIMG_H
#define DRAWIMG_H
#include "common.h"
#include "global.h"
#include "LCD12864.h"

#define DRAW_BOOTIMG() draw_Img(0,0,4)
#define DRAW_MANULIMG() LCD_Clear();draw_Img(0,2,2)
#define PRAM_SETINGIMG() draw_Img(0,3,2)
#define DRAW_PRAMIMG(start) draw_Img(2,start,2)
#define DRAW_SAVE() draw_Img(0,8,4);
#define DRAW_AUTOIMG()
void draw_Img(UCHAR y,UCHAR start ,UCHAR len);

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  DRVIE TEST
 *  Description:
 *
 *  DRAW_BOOTIMG()
 *  DRAW_MANULIMG()
 * =====================================================================================
 */


#endif /* end of include guard: DRAWIMG_H */

