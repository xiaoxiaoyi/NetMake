#include "eeprom.h"
#include "common.h"
#include <iom16.h>

/* EEPROM Control Register */
#define    EERIE    3
#define    EEMWE    2
#define    EEWE     1
#define    EERE     0

unsigned char EEPROM_read(unsigned int uiAddress) {
    /* 等待上一次写操作结束 */
    while(EECR & (1<<EEWE));
    /* 设置地址寄存器*/
    EEAR = uiAddress;
    /* 设置EERE 以启动读操作*/
    EECR |= (1<<EERE);
    /* 自数据寄存器返回数据 */
    return EEDR;
}

void EEPROM_write(unsigned int uiAddress, unsigned char ucData) {    /* 等待上一次写操作结束 */
    while(EECR & (1<<EEWE));
    /* 设置地址和数据寄存器*/
    EEAR = uiAddress;
    EEDR = ucData;
    /* 置位EEMWE */
    /* 同时清零EEWE */
    EECR = (1<<EEMWE);
    /* 置位EEWE 以启动写操作*/
    EECR |= (1<<EEWE);
}
