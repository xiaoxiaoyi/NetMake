/*
 * =====================================================================================
 *
 *       Filename:  drawnumber.c
 *
 *    Description:  画数字CPP文件
 *
 *        Version:  1.0
 *        Created:  2013-8-11 22:05:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yiluoyang (), gfcocos@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include "drawnumber.h"
#include "global.h"
#include "lcd12864.h"


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  dispxyset
 *  Description:  对缓冲区的x,y设置为亮点
 * =====================================================================================
 */
void dispxyset(unsigned char x,unsigned char y)
{
    map[((y)<<2)+(x>>3)] |= (0X80>>(x)%8);  // 优化乘除运算转换为位运算
    //map[((y)<<2)+(x>>3)] |= (1<<((x)%8));  // 优化乘除运算转换为位运算
}


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  dispxyclr
 *  Description:
 * =====================================================================================
 */
void dispxyclr(unsigned char x,unsigned char y)
{
    map[((y)<<2)+(x>>3)] &= ~(0X80>>(x)%8);  // 优化乘除运算转换为位运算
    //map[((y)<<2)+(x>>3)] &= ~(1<<((x)%8));  // 优化乘除运算转换为位运算
}

#if 0
INT8U getpoint(const UCHAR num[],INT8U x,INT8U y)
{
    if(num[y] &(0X80>>(x)))
    //if(num[y] &(1<<(x)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
#endif

void dispnum(const UCHAR num[],unsigned char x,unsigned char y,UCHAR flag)
{
    int i,j;
    for(i=0;i<NUMBER_SIZEH;i++)
    {
        for(j=0;j<NUMBER_SIZEV;j++)
        {
            //if(getpoint(num,i,j))
            if((num[j] &(1<<(i))))
            {
                if(flag)
                    dispxyset(x+i,y+j);
                else
                    dispxyclr(x+i,y+j);
            }
            else
            {
                if(flag)
                    dispxyclr(x+i,y+j);
                else
                    dispxyset(x+i,y+j);
            }
        }
    }
}

void dispdot(UCHAR x,UCHAR y,UCHAR flag)
{
    int i=x+2,j=y+2;
    for(i =x ;i <x+2;i++)
    {
        for(j = y;j<y+2;j++)
        {
            if(flag)
            map[((j)<<2)+(i>>3)] |= (0X80>>(i)%8);
            else
            map[((j)<<2)+(i>>3)] &= ~(0X80>>(i)%8);
        }
    }
}


void disp_paramval(UCHAR index,UCHAR numberindex)
{
    if(numberindex == 0)
        dis_vall(pram[index<<1]/10,0);
    else
        dis_vall(pram[index<<1]/10,1);

    if(numberindex == 1)
    dis_valr(pram[index<<1]%10,0);
    else
    dis_valr(pram[index<<1]%10,1);

    dis_dot((pram_float & BIT(index<<1)));

    LCD_DrawLine1();
    if(numberindex == 2)
    dis_vall(pram[(index<<1)+1]/10,0);
    else
    dis_vall(pram[(index<<1)+1]/10,1);

    if(numberindex == 3)
    dis_valr(pram[(index<<1)+1]%10,0);
    else
    dis_valr(pram[(index<<1)+1]%10,1);

    dis_dot((pram_float & BIT((index<<1) + 1)));
    LCD_DrawLine2();
}
