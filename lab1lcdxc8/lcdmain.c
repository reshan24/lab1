

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

void init_XLCD( void )
{
 // configure external LCD
OpenXLCD(FOUR_BIT & LINES_5X7);
while( BusyXLCD() );
WriteCmdXLCD( FOUR_BIT & LINES_5X7 );
while( BusyXLCD() );
WriteCmdXLCD( BLINK_ON );
while( BusyXLCD() );
WriteCmdXLCD( SHIFT_DISP_LEFT );


}
/*------------------------------------------------------------------------*/

void main (void)
{
    OSCCON = 0b01100010;            // Fosc = 4MHz (Inst. clk = 1MHz)
    ADCON1 = 0xF;                   // No analog, all digital i/o
    TRISA = 0x00;
    TRISD = 0x00;
    TRISB = 0x0;
    TRISC = 0x0;
    LATB = 0x0;
    LATD = 0x0;
init_XLCD(); //Call the Initialize LCD display function
 while( BusyXLCD() );
 SetDDRamAddr(0x43); //shift cursor to fourth space of second line
 putrsXLCD("Hello World"); //Display "Hello World"
 while(1)
 {
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
