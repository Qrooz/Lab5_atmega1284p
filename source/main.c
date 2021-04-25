/*	Author:Cruz Ramirez -  crami119
 *  Partner(s) Name: 
 *	Lab Section:022
 *	Assignment: Lab 5  Exercise 3
 *	Exercise Description: [optional - include for your own benefit]
 *	Lights switch from alterating to all on
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif



enum LED_States{LED_L1, LED_L1Wait, LED_L2, LED_L2Wait, LED_L3, LED_L3Wait}LED_State;



void TickFct_LED(){

	unsigned char temp = ~PINA;

        switch(LED_State){ //transition state
		
		case LED_L1:
			if(temp == 0x00){
				LED_State = LED_L1Wait;
			}
			else{
				LED_State = LED_L1;
			}
			break;

		case LED_L1Wait:
			if(temp == 0x01){
				LED_State = LED_L2;
			}
			else{
				LED_State = LED_L1Wait;
			}
			break;

		case LED_L2:
			if(temp == 0x00){
				LED_State = LED_L2Wait;
			}
			else{
				LED_State = LED_L2;
			}
			break;

		case LED_L2Wait:
			if(temp == 0x01){
				LED_State = LED_L3;
			}
			else{
				LED_State = LED_L2Wait;
			}
			break;

		case LED_L3:
			if(temp == 0x00){
				LED_State = LED_L3Wait;
			}
			else{
				LED_State = LED_L3;
			}
			break;

		case LED_L3Wait:
			if(temp == 0x01){
				LED_State = LED_L1;
			}
			else{
				LED_State = LED_L3Wait;
			}
			break;

		default:
			break;
        }

	switch(LED_State){ //state actions
		
		case LED_L1:
			PORTB = 0x2A;
			break;

		case LED_L2:
			PORTB = 0x15;
			break;

		case LED_L3:
			PORTB = 0x3F;
			break;

		case LED_L1Wait:
		case LED_L2Wait:
		case LED_L3Wait:
		default:
			break;
	}

}


int main(void) {
    
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF;

	LED_State = LED_L1;
	PORTB = 0x2A;

    while (1) {

	TickFct_LED();

    }
    return 1;
}
