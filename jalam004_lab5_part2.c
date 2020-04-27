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
enum States{start,init,inc,dec,reset,wait} state;
DDRA = 0x00; PORTA = 0xFF;
DDRC = 0xFF; PORTC = 0x00;
unsigned char tmpA = 0x00;

 //  state = start; 

    
    while (1) {
       
         tmpA = PINA;
         tmpA = ~PINA & 0x01;
         
    switch(state)
    {   
        case start:
        state = init;
        break;

        case init:
//	state = init;
          if(tmpA != 0xFE && tmpA != 0xFD )
            state = init;
            if(tmpA == 0xFD)
            {
                state = dec;
            }
            if(tmpA == 0xFE)
            {
                state = inc;
            }
           
            break;

        case inc:
            if(tmpA == 0xFE)
            {
               
          
            state = inc;
            
            }
         
            else{state = reset;}
    
        
            break;
        case dec:
            if(tmpA == 0xFD)
            {
                state = dec;
            }  
            
            else
            {   
               
                state = reset;
                
            }
       		 break;
        
        
        
        case reset:
            if(tmpA != 0xFE)
            {
                state = wait;
            }

	    if(tmpA != 0xFD)
	{
		state = wait;	
	}    
		else
		{
		state = reset;

		}
        break;
case wait:
if(tmpA == 0xFE)
{ state = wait;}
if(tmpA == 0xFD)
{ state = wait;}
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
        if(PORTC!=0x00)
        {PORTC = PORTC - 1;}
	else{PORTC = 0x00;}
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
    PORTC = PORTC;   
        break;



    }

    }


//PORTB = PORTB + 1;


return 0;
}
