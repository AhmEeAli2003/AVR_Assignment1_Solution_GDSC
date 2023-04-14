/**
 ****************************************************************************************
 *   @file          : main.c
 *   @author        : Ahmed Ali
 *   @date          : 14 April 2023
 *   @brief         : Assignment 1 solution.
 ****************************************************************************************
*/

/* ****************************** Includes Section Start **************************** */
#include <util/delay.h>
/* ****************************** Includes Section End   **************************** */

/* ****************************** Macros Section Start   **************************** */
typedef unsigned char u8;

#define DDRA	*((volatile u8*) 0x3A)
#define PORTA	*((volatile u8*) 0x3B)

#define SET_BIT(reg,bit)	reg|=(1<<bit)
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)    reg^=(1<<bit)
#define GET_BIT(reg,bit)    ((reg & (1<<bit))) >> bit
/* ****************************** Macros Section End     **************************** */
int main(void)
{
	/* 1- Write a C code to turn on the LED on Pin A0 for 1 second and then turn it off */
	/*
	//Pin A0 is output
	SET_BIT(DDRA ,0);
	//Pin A0 is high [turn on LED]
	SET_BIT(PORTA,0);

	while(1)
	{
		//Toggle pin A0 state [Toggle LED state]
		TOG_BIT(PORTA, 0);
		//Delay one second
		_delay_ms(1000);
	}
	*/

	/* 2- Write a C code that apply some LED animations (Snake effect) */
	// This is not best solution but fastest in code.

	//Set PORTA as output
	DDRA = 0xff;

	while(1)
	{
		//Set all pins in PORTA consequently.
		for(u8 iterator = 0; iterator < 8; iterator++)
		{
			SET_BIT(PORTA, iterator);
			_delay_ms(250);
		}
		//Clear all pins in PORTA consequently.
		for(u8 iterator = 0; iterator < 8; iterator++)
		{
			CLR_BIT(PORTA, iterator);
			_delay_ms(250);
		}
	}

	return 0;
}

