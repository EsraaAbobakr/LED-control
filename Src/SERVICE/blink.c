#include "Blink.h"
#include "LED.h"
#include "IntCtrl.h"
#include "SysCtrl.h"
#include "Systick.h"
LED_1 lede;
void Blink_Led(uint16 TicksON,uint16 TicksOFF)
{
	static init =0;
	if (init ==0)
	{ 
	/*	TicksON  = TicksON/ SystickCfg.TickFreq ;
		TicksOFF = TicksOFF/ SystickCfg.TickFreq  ;
		IntCrtl_Init() ;	       // Configure Exceptions controls
		SysCtrl_ClockInit() ;   // Configure System clock
		Systick_Init() ;  */
		Init_led();
		init=1;
		
	}

	

	
	static uint16 ledStatuss = 0 ;
	if(ledStatuss ==  0)
	{
		Led_Turnoff();
		Systick_Start(TicksOFF) ;
		ledStatuss = 1 ;
	}
	if(ledStatuss == 1 && (Systick_GetTicksElapsed() == TicksOFF))
	{
		Led_TurnOn();
		Systick_Start(TicksON) ;
		ledStatuss = 0;
	}
	if(ledStatuss == 0 && (Systick_GetTicksElapsed() == TicksON))
	{
		Led_Turnoff();
		Systick_Start(TicksOFF) ;
		ledStatuss = 1;
	}
	
}