/*
 * =====================================================================================
 *
 *       Filename:  dispstamachine.c
 *
 *    Description:  显示状态机
 *
 *        Version:  1.0
 *        Created:  2013-8-14 8:26:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yiluoyang (), gfcocos@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include "dispstamachine.h"
#include "common.h"
#include "drawimg.h"
#include "keypad.h"
#include "drawnumber.h"

UCHAR getMode()
{
    return 0;
}

int parma_set()
{
    UCHAR flag = 0;
    static UCHAR index = 0;
    static UCHAR numindex = 0X00;
    UCHAR event = getkey();
    switch(event)
    {
        case KEY_SETTING:
            index++;
            if(index == 4)
            {
                index = 0;
                numindex = 0X00;
                return 1;
            }
            numindex = 0X00;
            flag = 1;
            break;
        case KEY_UP:                            // 后期对KEYUP KEYDOWN处理部分进行优化
            switch(numindex)
            {
            case 0:
                pram[index<<1] += 10;
                pram[index<<1] =  pram[index<<1]%100;
                break;
            case 1:
                if(pram[index<<1]%10 == 9)
                {
                    pram[index<<1] -= 9;
                }
                else
                {
                    pram[index<<1] += 1;
                }
                break;
            case 2:
                pram[(index<<1) + 1] += 10;
                pram[(index<<1) + 1] = pram[(index<<1) + 1] % 100;
                break;
            case 3:
                if(pram[(index<<1) + 1] % 10 == 9)
                {
                    pram[(index<<1)+1] -= 9;
                }
                else
                {
                    pram[(index<<1) + 1] -= 1;
                }
                break;
            }
            flag = 2;
            break;
        case KEY_DOWN:
            switch(numindex)
            {
            case 0:
                if(pram[index<<1]/10 == 0)
                {
                    pram[index<<1] += 90;
                }
                else
                {
                    pram[index<<1] -= 10;
                }
                break;
            case 1:
                if(pram[index<<1] % 10 == 0)
                {
                    pram[index<<1] += 9;
                }
                else
                {
                    pram[index<<1] -= 1;
                }

                break;
            case 2:
                if(pram[(index<<1) + 1] / 10 == 0)
                {
                    pram[(index<<1) + 1] += 90;
                }
                else
                {
                    pram[(index<<1) + 1] -= 10;
                }
                break;
            case 3:
                if(pram[(index<<1) + 1] %10 == 0)
                {
                    pram[(index<<1) + 1] += 9;
                }
                else
                {
                    pram[(index<<1) + 1] -= 1;
                }
                break;
            }
            flag = 2;
            break;
        case KEY_ENTER:
            numindex = (numindex+1)%4;
            flag = 2;
            break;
    }
    if(!flag)                                   // 优化绘图
        return 0;

    switch(flag)
    {
    case 0:
        //return 0;
        //
        break;                                // 添加会给出警告
    case 1:
        DRAW_PRAMIMG(index+4);
        disp_paramval(index,numindex);
        break;
    case 2:
        disp_paramval(index,numindex);
        break;
    }
    return 0;
}


void StateProcedure(EventType event)
{
    static UINT state = POWERON;
    UCHAR ret = 0;
    switch(state)
    {
        case POWERON:
            DRAW_BOOTIMG();
            state = DELAY;
            break;
        case DELAY:
            delay_xs(2);
            state = GETMODE;
            break;

        case GETMODE:
            if(getMode())//auto
            {
                //disp_autoImg();
                state = DISPAUTO;
            }
            else
            {
                DRAW_MANULIMG();
                state = WAITESET;
            }
            break;
        case DISPAUTO:
            //disp_autoImg();
            break;
        case WAITESET:
            if(getkey() == KEY_SETTING)
            {
                PRAM_SETINGIMG();
                DRAW_PRAMIMG(4);
                disp_paramval(0,0);
                state = PARMSET;
            }
            break;
        case PARMSET:
            if(parma_set() == 1)
            {
                state = SAVEORNOT;
            }
            break;
        case SAVEORNOT:
            DRAW_SAVE();
            LCD_GClear();
            ret = getkey();
            if(ret == KEY_ENTER)
            {
               DRAW_MANULIMG();
               //save_data();
               state = WAITESET;
            }
            else if(ret == KEY_QUIT)
            {
                 DRAW_MANULIMG();
                 state = WAITESET;
            }
            break;
    }
}
