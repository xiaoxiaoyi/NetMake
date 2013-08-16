/*
 * =====================================================================================
 *
 *       Filename:  LCD12864.c
 *
 *    Description:  LCD12864 C File
 *
 *        Version:  1.0
 *        Created:  2013-8-11 0:06:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yiluoyang (), gfcocos@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include "LCD12864.h"
#include "delay.h"
#include "global.h"
/* static */ void LCD_WriteCMD(UCHAR ucCmd)
{
	CLR_CS;
	SET_EN;
	delay_xus(100);
	DATA_PORT = ucCmd;
	delay_xus(100);
	CLR_EN;
}

/* static */ void LCD_WriteData(UCHAR ucData)
{
	SET_CS;
	SET_EN;
	delay_xus(100);
	DATA_PORT = ucData;
	delay_xus(100);
	CLR_EN;
}


void LCD_Init(void)
{

    delay_xms(4);
    LCD_WriteCMD(0X30);
    delay_xms(4);
    LCD_WriteCMD(0X30);
    delay_xms(10);
    LCD_WriteCMD(0X0C);
    delay_xms(10);
    LCD_WriteCMD(0X01);
    delay_ms();
    LCD_WriteCMD(0X06);
    //LCD_Blink();
}

void LCD_SetXY(short x,short y)		
{

    if(x<0 || x >15 || y <0 || y >3)
        return ;
	switch(y)
	{
		   case 0:
		    LCD_WriteCMD(0X80+x);break;
		   case 1:
		    LCD_WriteCMD(0X90+x);break;
		   case 2:
		    LCD_WriteCMD(0X88+x);break;
		   case 3:
		    LCD_WriteCMD(0X98+x);break;
		   default:break;
	}
}

void LCD_WriteCharXY(CHAR x,CHAR y,UCHAR ucData)
{
     LCD_SetXY(x,y);	
	 LCD_WriteData(ucData);
}



void LCD_WriteStrXY(CHAR x,CHAR y,const CHAR *pStr)
{
	 LCD_SetXY(x,y);			
     do
     {
	    LCD_WriteData(*pStr++);	
     }
     while(*pStr);
}


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  LCD_GCLear
 *  Description:  清除GCROM的内容，如果不清除会出现花屏现象
 *                向GCROM中写入0x00来清除内容
 * =====================================================================================
 */
void LCD_GClear(void)
{
	UCHAR i , j , k;
	LCD_Eextend();
    LCD_DrawOff();
	
	for(i = 0; i < 2; i ++)
	{
		for(j = 0; j < 32; j ++)
		{
			LCD_WriteCMD(0X80+j);
			if(i == 0)
			{
				LCD_WriteCMD(0x80);
			}
			else
			{
				LCD_WriteCMD(0X88);
			}
			for(k = 0; k < 16; k ++)
			{
				LCD_WriteData(0X00);
				LCD_WriteData(0X00);
			}
		}
	}
	LCD_DrawOn();
	LCD_Basic();
}


void LCD_DrawMap(UCHAR x,UCHAR y)
{
	LCD_Eextend();
    LCD_DrawOff();
    for(int i=0;i<16;i++)
    {
        LCD_WriteCMD(x+i);//hang
        LCD_WriteCMD(y);//lie
        for(int j=0;j<4;j++)
        {
            LCD_WriteData(map[i*4+j]);
        }
    }
    LCD_DrawOn();
    LCD_Basic();
}
