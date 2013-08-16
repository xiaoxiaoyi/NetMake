/*
 * =====================================================================================
 *
 *       Filename:  delay.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2013-8-11 9:36:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yiluoyang (), gfcocos@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include "delay.h"

#define CPU_73728MHZ
#ifdef CPU_73728MHZ
void delay_us(void)
{
	BYTE t=0;
	for(t=2;t>0;t--);
}

void delay_xus(BYTE t)
{
	for( ;t>0;t--)
	{
		delay_us();
	}
}

void delay_ms(void)
{
	BYTE i,j,k;
	for(i=1;i>0;i--)
		for(j=254;j>0;j--)
			for(k=13;k>0;k--);
}

void delay_xms(BYTE t)
{
	for( ;t>0;t--)
	{
		delay_ms();
	}

}

void delay_xs(BYTE t)
{
    for(UINT i=0;i<t*4;i++)
        delay_xms(250);
}

#endif

