#include "Blink.h"
#include "LED.h"
#include "Systick.h"

uint16 on;
uint16 off; 

void Turnonoff (void)
{
	static uint16 CurrTicks=0;
	CurrTicks++;
	static uint16 Status=0;
	if((CurrTicks == off)&&(Status == 0)) /*starting with off time*/
	{		 
		Led_TurnOn();
		Systick_Start(off) ;
		Status=1;
	}
	if((CurrTicks == (on+off))&&(Status == 1))
	{
		Led_Turnoff();
		Systick_Start(on);
		CurrTicks = 0;
		Status=0;
	}	
}

void Blink_Led(uint16 TickON,uint16 TickOFF)
{
	static init = 0;
	if (init ==0)
	{ on=TickON;
		off=TickOFF;
		callback(&Turnonoff);
		Init_led();
		Systick_Init();
		Systick_Start(off);
		init=1;
	}
}


