/*
 * =====================================================================================
 *
 *       Filename:  platform_macro.h
 *
 *    Description:  platform macro
 *
 *        Version:  1.0
 *        Created:  2013-8-11 1:11:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yiluoyang (), gfcocos@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef PLATFORM_MACRO_H
#define PLATFORM_MACRO_H

#define PLATFORM_8BIT

#ifndef BIT
#define BIT(x)	(1 << (x))
#endif

#ifdef PLATFORM_8BIT
#define BIT0    0X01
#define BIT1    0X02
#define BIT2    0X04
#define BIT3    0X08
#define BIT4    0X10
#define BIT5    0X20
#define BIT6    0X40
#define BIT7    0X80
#endif



#endif /* end of include guard: PLATFORM_MACRO_H */
