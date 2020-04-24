/*	Author: jalam004
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


int main(void) {
enum State{start,on,off} state;
DDRA = 0x00; PORTA=0xFF;
DDRB = 0xFF; PORTB=0x00;
unsigned char tmpA;
unsigned char tmpB = 0x01;
unsigned char cnt = 0;
unsigned char i = 1;
while(1)
{

//tmp = PORTB & 0x1F;
    
//enum State{start,on,off} state;
//DDRA = 0x00; PORTA=0xFF;
//DDRB = 0xFF; PORTB=0x00;
 tmpA = PINA;

switch(state)
{
case start:
state = off;
break;
case off:
if(tmpA == 0x00)
state = off;
else{
//if(cnt==0)
//cnt++;
// tmpA = 0x01;}
state = on;}
break;
case on:
if(tmpA == 0x01 && cnt < 7)
{
cnt++;
state = on;
}
else{state = off;}
break;
default:
break;
}

switch(state)
{
case start:
break;
case off:
PORTB = 0x00;
break;
case on:
if(cnt == 1)
PORTB = cnt;
else if(cnt == 2)
{PORTB = cnt;}
else{
//unsigned char i = 0;
while(i<cnt)
{
tmpB = 2*tmpB;
i++;

}
PORTB = tmpB;
//tmpB = 0x01;
}
// = PORTB + 1;
//break;
//state = on;

break;
default:
state = start;
break;
}		
}



//PORTB = PORTB + 1;


return 0;
}
