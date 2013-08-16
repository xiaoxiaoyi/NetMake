/*
 * =====================================================================================
 *
 *       Filename:  keypad.h
 *
 *    Description:  keypad
 *
 *        Version:  1.0
 *        Created:  2013-8-11 9:15:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yiluoyang (), gfcocos@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef KEYPAD_H
#define KEYPAD_H
#include "common.h"

#define KEY_SETTING 0X08
#define KEY_ENTER   0X10
#define KEY_UP      0X20
#define KEY_DOWN    0X40
#define KEY_QUIT    0X80

/*
 * \brief
 * get key
 *
 * \return
 * 
*/
UCHAR getkey(void);
#endif /* end of include guard: KEYPAD_H */

