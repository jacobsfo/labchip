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

 

    
    while (1) {
       
         tmpA = PINA;
         tmpA = ~PINA & 0x0F;
         
         
    switch(state)
    {   
        case start:
        state = init;
        break;

        case init:

          if(tmpA != 0x01 && tmpA!= 0x02 )
            state = init;
            if(tmpA == 0x02)
            {
                state = dec;
            }
            if(tmpA == 0x01)
            {
                state = inc;
            }
           
            break;

        case inc:
            if(tmpA == 0x01)
            {
               
          PORTC = 0x00;
            state = inc;
            
            }
        
            else{state = reset;}
    
        
            break;
        case dec:
            if(tmpA == 0x02)
            {
                state = init;
            }  
            
            else
            {   
               
                state = reset;
                
            }
       		 break;
        
        
        
        case reset:
            if(tmpA == 0x01)
            {
                state = wait;
            }

	    if(tmpA == 0x02)
	{
		state = wait;	
	}    
		else
		{
		state = reset;
		}
        break;
case wait:
if(tmpA == 0x01)
{ state = inc;}
if(tmpA == 0x02)
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

    }




return 0;

}
