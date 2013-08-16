/*
 * =====================================================================================
 *
 *       Filename:  dispstamachine.h
 *
 *    Description:  ÏÔÊ¾×´Ì¬»ú
 *
 *        Version:  1.0
 *        Created:  2013-8-14 8:25:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yiluoyang (), gfcocos@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#ifndef DISPSTAMACHINE_H
#define DISPSTAMACHINE_H

typedef enum
{
    POWERON,
    DELAY,
    GETMODE,
    DISPAUTO,
    WAITESET,
    PARMSET,
    SAVEORNOT,
}EventType;

void StateProcedure(EventType event);

#endif /* end of include guard: DISPSTAMACHINE_H */
