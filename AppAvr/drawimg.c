/*
 * =====================================================================================
 *
 *       Filename:  drawimg.c
 *
 *    Description:  »­Í¼
 *
 *        Version:  1.0
 *        Created:  2013-8-14 21:27:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yiluoyang (), gfcocos@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include "drawimg.h"
#include "common.h"
#include "global.h"

void draw_Img(UCHAR y,UCHAR start ,UCHAR len)
{
    for(int i=0;i<len;i++)
    {
        LCD_WriteStrXY(0,y+i,bootimg[2*start+i]);
    }
}