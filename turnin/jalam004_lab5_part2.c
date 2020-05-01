/*	Author: jalam004
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 5  Exercise 2
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
enum States{start,init,inc,dec,reset,wait} state;
DDRA = 0x00; PORTA = 0xFF;
DDRC = 0xFF; PORTC = 0x00;
unsigned char tmpA = 0x00;
unsigned char tmpB = 0x00;
 
state = start;
    
    while (1) {
       
         //tmpA = PINA;
         tmpA = ~PINA & 0x01;
         tmpB = ~PINA & 0x02;
         
    switch(state)
    {   
        case start:
        state = init;
        break;

        case init:

          if((tmpA && tmpB) || (!tmpA && !tmpB))
            state = init;
            if(tmpB)
            {
                state = dec;
            }
            if(tmpA)
            {
                state = inc;
            }
           
            break;

        case inc:
            if(tmpA)
            {
               
//          PORTC = 0x00;
            state = inc;
            
            }
        
            else{state = reset;}
    
        
            break;
        case dec:
            if(tmpB)
            {
             state = init;
	     //state = dec;
            }  
            
            else
            {   
               
                state = reset;
                
            }
       		 break;
        
        
        
        case reset:
            if(tmpA)
            {
                state = wait;
            }

	    if(tmpB)
	{
		state = wait;	
	}    
		else
		{
		state = reset;
		}
        break;
case wait:
if(tmpA )
{ state = inc;}
if(tmpB)
{ state = dec;}
break;

        default:
        state = start;
        break;
    }
        
    switch(state)
    {
        case start:

        break;

        case init:
        PORTC = 0x00;
        break;

        case dec:
        if(PORTC != 0x00)
        {PORTC = PORTC - 1;}
	
        break;

        case inc:
       if(PORTC!=0x09)
        {PORTC = PORTC + 1;}
        break;

        case reset:
        
     {PORTC = 0x01;}
      
        break;
        default:
     case wait:
   
        break;



    }
//continue;
  }




return 0;

}
