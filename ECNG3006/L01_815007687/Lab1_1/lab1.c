/* Lab 1 first file - ID number 96013952 */
#include <p18f452.h>

/* Set configuration bits for use with ICD2 */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

void main (void)
{
    int count = 1;
    TRISB = 0;
    while (count <= 15)
    {
        PORTB = count;
        count++;
    }
}
