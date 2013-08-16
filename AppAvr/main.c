/**************************************************
 *
 * This is a LED chaser example program for the AVR
 * STK500 starter kit evaluation board. This program
 * works for all AVRs.
 *
 * Description:
 * This program will turn on the User LEDs one at
 * a time and circulate this procedure in a forever
 * loop.
 *
 * Copyright 1996-2005,2008 IAR Systems AB. All rights reserved.
 *
 * $Revision: 6759 $
 *
 **************************************************/


/* Include I/O definition file */
#include <ioavr.h>
#include "LCD12864.h"
#include "drawnumber.h"
#include "dispstamachine.h"
//extern unsigned char const num[];
void port_init(void)
{
    PORTA = 0x00;
    DDRA  = 0xFF;
    PORTB = 0x00;
    DDRB  = 0xFF;
    PORTC = 0xF8; //m103 output only
    DDRC  = 0x01;
    PORTD = 0x1C;
    DDRD  = 0x41;
}
int main( void )
{

     //stop errant interrupts until set up
     //disable all interrupts
     //asm("cli");// CLI();
     port_init();
     //timer0_init();
     //MCUCR = 0x02;
     //GICR  = 0x40;
     //TIMSK = 0x01; //timer interrupt sources
     //SEI(); //re-enable interrupts
     //asm("sei");
     //all peripherals are now initialized

    LCD_Init();
    LCD_GClear();
    LCD_Clear();
    while(1)
    {
        StateProcedure(POWERON);
    }
}
