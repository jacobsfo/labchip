//
//  Author:jalam004
/*    Partner(s) Name & E-mail:
*    Lab Section: 022
*    Assignment: Lab 5  Exercise 1
*    Exercise Description: [optional - include for your own benefit]
*
*    I acknowledge all content contained herein, excluding template
*     or example code, is my own original work.
*/

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


int main(void) {
    /* Insert DDR and PORT initializations */
DDRA = 0x00; PORTA=0xFF;
DDRC = 0xFF; PORTC=0x00;
unsigned char tmpA = 0x00;
    while(1)
    {
        tmpA = PINA;
        tmpA = ~PINA & 0x0F;
        if(tmpA <= 0x04)
        {
            PORTC = 0x40;
            if(tmpA == 0x01 || tmpA == 0x02)
            {
            PORTC = 0x60;
            }
            if(tmpA == 0x03 || tmpA == 0x04)
            {
                PORTC = 0x70;
            }
        }
        if(tmpA == 0x05 || tmpA == 0x06)
        {
            PORTC = 0x38;
        }
        if(tmpA == 0x07 || tmpA == 0x08 ||tmpA == 0x09 )
        {
            PORTC = 0x3C;
        }
        if(tmpA == 0x0A || tmpA == 0x0B ||tmpA == 0x0C )
        {
            PORTC = 0x3E;
        }
        if(tmpA == 0x0D || tmpA == 0x0E ||tmpA == 0x0F )
        {
            PORTC = 0x3F;
        }
//        if(tmpA == 0x11)
//        {
//            PORTC = 0x60;
//        }
//        if(tmpA == 0x25)
//        {
//            PORTC = 0x38;
//        }
//        if(tmpA == 0x47)
//        {
//            PORTC = 0x3C;
//        }
//        if(tmpA == 0x3F)
//        {
//            PORTC = 0xBF;
//        }
        
    }
}

