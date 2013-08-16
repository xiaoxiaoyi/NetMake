/*
 * =====================================================================================
 *
 *       Filename:  drawnumber.h
 *
 *    Description:  ������ͷ�ļ�
 *
 *        Version:  1.0
 *        Created:  2013-8-11 22:00:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yiluoyang (), gfcocos@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#ifndef DRAWNUMBER_H
#define DRAWNUMBER_H
#include "common.h"


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  dispxyset
 *  Description:  �Ի�������ĳһ������Ϊ�ڵ�
 * =====================================================================================
 */
inline void dispxyset(unsigned char x,unsigned char y);

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  dispxyclr
 *  Description:  �Ի�������ĳһ������Ϊ����
 * =====================================================================================
 */
inline void dispxyclr(unsigned char x,unsigned char y);

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  getpoint
 *  Description:  ��ȡnum�е�ĳһ��
 *        Brief:  �Ż��Ѿ�ɾ���˶δ���
 * =====================================================================================
 */
//INT8U getpoint(const UCHAR num[],INT8U x,INT8U y);


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  dispnum
 *  Description:  ��ʾ����
 *        Brief:
 *     flag = 1:  ������ʾ
 *     flag = 0:  ������ʾ
 * =====================================================================================
 */
void dispnum(const UCHAR num[],unsigned char x,unsigned char y,UCHAR flag);



/*
 * ===  FUNCTION  ================================================== ====================
 *         Name:  dispot
 *  Description:  ���
 * =====================================================================================
 */
void dispdot(UCHAR x,UCHAR y,UCHAR flag);

/*

*/
#define dis_vall(val,flag) dispnum(num+16*(val),8,0,flag)
#define dis_valr(val,flag) dispnum(num+16*(val),18,0,flag)
#define dis_dot(flag)          dispdot(16,12,flag)

//void dis_intval(INT8U val,UCAHR flag)
//{
//   dis_vall(val/10,flag);
//   dis_valr(val%10,flag);
//}
//
//void dis_floatval(INT8U val,UCHAR flag)
//{
//   dis_vall(val/10,flag);
//   dis_valr(val%10,flag);
//}

void disp_paramval(UCHAR index,UCHAR numberindex);
/*
 * ===  FUNCTION  ======================================================================
 *         Name:  drivetest
 *  Description:  ��������
 * =====================================================================================
 */
//dispdot(16,12);
//dispnum(num,8,0,1);
//dispnum(num+16*9,18,0,1);

#endif /* end of include guard: DRAWNUMBER_H */
