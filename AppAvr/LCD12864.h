/*
 * =====================================================================================
 *
 *       Filename:  LCD12864.h
 *
 *    Description:  LCD12864 Header File
 *
 *        Version:  1.0
 *        Created:  2013-8-10 23:35:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yiluoyang,
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef LCD12864_H
#define LCD12864_H

#include <ioavr.h>
#include "common.h"


#define SET_CS PORTC |= BIT0
#define CLR_CS PORTC &= ~BIT0
#define SET_EN PORTD |= BIT6
#define CLR_EN PORTD &= ~BIT6
#define DATA_PORT PORTB

void LCD_Init(void);                            // LCD Init
void LCD_SetXY(short x,short y);
void LCD_WriteCharXY(CHAR x,CHAR y,UCHAR ucData);
void LCD_WriteStrXY(CHAR x,CHAR y,const CHAR *pStr); // 我是中文
void LCD_WriteCMD(UCHAR ucCmd);
/*
 * ===  FUNCTION  ======================================================================
 *         Name:  LCD_WriteData(UCHAR ucData)
 *  Description:  LCD 写数据
 * =====================================================================================
 */
void LCD_WriteData(UCHAR ucData);
/*
 * ===  FUNCTION  ======================================================================
 *         Name:  void LCD_GClear(void)
 *  Description: LCD12864 绘图清屏函数
 * =====================================================================================
 */
void LCD_GClear(void);


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  void LCD_TEST()
 *  Description:
 * =====================================================================================
 */
void LCD_DrawMap(UCHAR x,UCHAR y);

#define LCD_Clear() LCD_WriteCMD(0X01)
#define LCD_Blink() LCD_WriteCMD(0X0F)
#define LCD_Eextend() LCD_WriteCMD(0x34)
#define LCD_Basic() LCD_WriteCMD(0X30)
#define LCD_DrawOn() LCD_WriteCMD(0X36)
#define LCD_DrawOff() LCD_WriteCMD(0X34)
#define LCD_DrawLine1() LCD_DrawMap(0X80,0X8C)
#define LCD_DrawLine2() LCD_DrawMap(0X90,0X8C)

#if 0
void LCD_ClearXY(UCHAR x,UCHAR y); 			
void LCD_LCDClear(UCHAR y); 						
#endif
#endif /* end of include guard: LCD12864_H */
