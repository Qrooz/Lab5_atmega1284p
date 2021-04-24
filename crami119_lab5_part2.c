/*	Author: crami119
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



enum B_States{B_Incr, B_IncrWait, B_Decr, B_DecrWait, B_Wait, B_Zero}B_State;



void TickFct_B(){

	unsigned char temp = ~PINA;



        switch(B_State){ //transition state

        case B_Wait:
        if(temp == 0x01){
        B_State = B_Incr;
        }
	else if(temp == 0x02){
	B_State = B_Decr;
	}
	else if(temp == 0x03){
	B_State = B_Zero;
	}
        break;

        case B_Incr:
	if(temp == 0x03){
	B_State = B_Zero;
	}
	else if(temp == 0x02){
	B_State = B_Decr;
	}
	else if(temp == 0x00){
	B_State = B_Wait;
	}
	else{
	B_State = B_IncrWait;
	}
        break;

	case B_IncrWait:
	if(temp == 0x00){
	B_State = B_Wait;
	}
	else if(temp == 0x02){
	B_State = B_Decr;
	}
	else if(temp == 0x03){
	B_State = B_Zero;
	}
	break;

        case B_Decr:
	if(temp == 0x03){
	B_State = B_Zero;
	}
	else if(temp == 0x01){
	B_State = B_Incr;
	}
	else if(temp == 0x00){
	B_State = B_Wait;
	}
	else{
	B_State = B_DecrWait;
	}
        break;

	case B_DecrWait:
	if(temp == 0x00){
	B_State = B_Wait;
	}
	else if(temp == 0x01){
	B_State = B_Incr;
	}
	else if (temp == 0x03){
	B_State = B_Zero;
	}
	break;

        case B_Zero:
        B_State = B_Wait;
	
	if(temp == 0x01){
        B_State = B_Incr;
        }
        else if(temp == 0x02){
        B_State = B_Decr;
        }
        else if(temp == 0x03){
        B_State = B_Zero;
        }
        break;

        default:
        break;
        }

	switch(B_State){ //state actions

	case B_Incr:
	if(PORTC < 9){
	++PORTC;
	}
	break;

	case B_Decr:
	if(PORTC > 0){
	--PORTC;
	}
	break;

	case B_Zero:
	PORTC = 0x00;
	break;

	case B_Wait:
	case B_IncrWait:
	case B_DecrWait:
	default:
	break;

	}

}


int main(void) {
    
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF;

	PORTC = 0x07;
	B_State = B_Wait;

    while (1) {

	TickFct_B();

    }
    return 1;
}
