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

int main(void) {
    /* Insert DDR and PORT initializations */
        DDRA = 0x00; PORTA = 0xFF;
        DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    while (1) {

	PORTC = 0x00;
	unsigned char fuelLvl = PINA & 0x0F;
	if(fuelLvl == 1 | fuelLvl == 2){
	PORTC = PORTC | 0x20;
	}
	else if(fuelLvl == 3 | fuelLvl == 4){
	PORTC = PORTC | 0x30;
	}
	else if(fuelLvl == 5 | fuelLvl == 6){
	PORTC = PORTC | 0x38;
	}
	else if(fuelLvl == 7 | fuelLvl == 8 | fuelLvl == 9){
	PORTC = PORTC | 0x3C;
	}
	else if(fuelLvl == 10 | fuelLvl == 11 | fuelLvl == 12){
	PORTC = PORTC | 0x3E;
	}
	else if(fuelLvl == 13 | fuelLvl == 14 | fuelLvl == 15){
	PORTC = PORTC | 0x3F;
	}
	
	if(fuelLvl < 5){
	PORTC = PORTC | 0x40;
	}
}
    return 0;
}
