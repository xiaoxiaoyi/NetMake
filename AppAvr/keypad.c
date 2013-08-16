/*
 * =====================================================================================
 *
 *       Filename:  keypad.c
 *
 *    Description:  keypad c file
 *
 *        Version:  1.0
 *        Created:  2013-8-11 9:15:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yiluoyang (), gfcocos@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include "keypad.h"
/*
 * \brief
 * get key
 *
 * \return
 *
*/
UCHAR getkey(void)
{
    UCHAR tempkey=0;
    if(~((PINC&0xf8)|0x07))
    {
        delay_xms(100);
        if(~((PINC&0xf8)|0x07))
        {
            tempkey = ~((PINC&0xf8)|0x07);
            //这句话,视乎有问题,请唐总检查一下
            //while(~((PINC&0xf8)|0x07));
        }
    }
    return tempkey;
}
