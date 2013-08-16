#include "eeprom.h"
#include "common.h"
#include <iom16.h>

/* EEPROM Control Register */
#define    EERIE    3
#define    EEMWE    2
#define    EEWE     1
#define    EERE     0

unsigned char EEPROM_read(unsigned int uiAddress) {
    /* �ȴ���һ��д�������� */
    while(EECR & (1<<EEWE));
    /* ���õ�ַ�Ĵ���*/
    EEAR = uiAddress;
    /* ����EERE ������������*/
    EECR |= (1<<EERE);
    /* �����ݼĴ����������� */
    return EEDR;
}

void EEPROM_write(unsigned int uiAddress, unsigned char ucData) {    /* �ȴ���һ��д�������� */
    while(EECR & (1<<EEWE));
    /* ���õ�ַ�����ݼĴ���*/
    EEAR = uiAddress;
    EEDR = ucData;
    /* ��λEEMWE */
    /* ͬʱ����EEWE */
    EECR = (1<<EEMWE);
    /* ��λEEWE ������д����*/
    EECR |= (1<<EEWE);
}
