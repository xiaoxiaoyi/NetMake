/*
 * =====================================================================================
 *
 *       Filename:  eeprom.h
 *
 *    Description:  eeprom∂¡–¥ µœ÷
 *
 *        Version:  1.0
 *        Created:  2013-8-16 22:02:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yiluoyang (), gfcocos@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef EEPROM_H
#define EEPROM_H
#include "common.h"

unsigned char EEPROM_read(unsigned int uiAddress);
void EEPROM_write(unsigned int uiAddress, unsigned char ucData);

#endif /* end of include guard: EEPROM_H */
