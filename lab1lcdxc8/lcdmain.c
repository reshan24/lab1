/*  01:42 28 April 2013
*
*   E:\Electronics\PIC Projects\MCP Forum\XLCD\Source Files\XLCD Main.c
*
*   xc8 v1.12
*
*   PIC18F2420
*
*   Tested ok on 2 x 16 LCD
*
*/


#include <xc.h>
#include "lcd.h"
/*------------------------------------------------------------------------*/


#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

/*------------------------------------------------------------------------*/

#define _XTAL_FREQ (4000000)    /* Not using xtal, only to make delays work as
                                    it won't compile without this */


void DelayFor18TCY(void);
void DelayPORXLCD(void);
void DelayXLCD(void);

/*------------------------------------------------------------------------*/

void main (void)
{
    OSCCON = 0b01100010;            // Fosc = 4MHz (Inst. clk = 1MHz)
    ADCON1 = 0xF;                   // No analog, all digital i/o
    TRISA = 0x00;
    TRISB = 0x0;
    TRISC = 0x0;
    LATB = 0x0;


while(1)
{

    OpenXLCD(FOUR_BIT & LINES_5X7 & CURSOR_ON & BLINK_ON);
    while(BusyXLCD());

    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());

    WriteDataXLCD('A');
    while(BusyXLCD());

    WriteDataXLCD('t');
    while(BusyXLCD());

    WriteDataXLCD(' ');
    while(BusyXLCD());

    putrsXLCD( "last! XLCD," );
    while(BusyXLCD());

    WriteCmdXLCD(0xC0);
    while(BusyXLCD());

    putrsXLCD( "thanks Ian" );
    while(BusyXLCD());

    while(1);

    }

 }
/*------------------------------------------------------------------------*/
void DelayFor18TCY(void)
{
    __delay_us(18);

    }

/*------------------------------------------------------------------------*/
void DelayPORXLCD(void)
{
     __delay_ms(15);

    }
/*------------------------------------------------------------------------*/
void DelayXLCD(void)
{
    __delay_ms(5);

    }
/*------------------------------------------------------------------------*/
