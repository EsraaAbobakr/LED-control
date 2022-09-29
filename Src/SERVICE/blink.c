#include "Blink.h"
#include "LED.h"
#include "IntCtrl.h"
#include "SysCtrl.h"

void Blink_Led(uint16 TicksON,uint16 TicksOFF)
{
	static init =0;
	if (init ==0)
	{ 
		TicksON  = 0x03;/*TicksON/ SystickCfg.TickFreq ; */
		TicksOFF = 0x03;/*TicksOFF/ SystickCfg.TickFreq  ;*/
/*IntCrtl_Init() ;*/	       // Configure Exceptions controls
		SysCtrl_ClockInit() ;   // Configure System clock
		Init_led();
		Systick_Init() ; 
		init=1;
	}

	
	static uint16 ledStatuss = 0 ;
	if(ledStatuss ==  0)
	{
		Led_TurnOn();
		Systick_Start(TicksON) ;
		ledStatuss = 1 ;
	}
	if(ledStatuss == 1 && (Systick_GetTicksElapsed() == TicksON))
	{
		/*Led_Turnoff();
		Systick_Start(TicksON) ;
		ledStatuss = 0;*/
	}
	if(ledStatuss == 0 && (Systick_GetTicksElapsed() == TicksOFF))
	{
		/*Led_TurnOn();
		Systick_Start(TicksON) ;
		ledStatuss = 1;*/
	}
}