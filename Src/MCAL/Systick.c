#include "Std_Types.h"
#include "Systick.h"
#include "LED.h"
#include "Systick_Cfg.h"

#define XTAL_CLOCK_KHZ       16000
#define SYSTEM_CLOCK_KHZ     DEFAULT_SYSTEM_CLOCK	
#define NULL 0


extern void (*callbackptr)(void)=NULL;
 static volatile Systick_TicksType currTicks ;  
static Systick_TicksType desiredTicks ;
const SysCtr_CLockType SystemClock = SYSTEM_CLOCK_KHZ ; // KHz

void Systick_Init(void)
{
	STCTRL.EN = 0 ; /* Disable Timer Until configuration completed */
	STCURRENT = 0 ; /*Write dummy vale to clear systick current reg */
	STCTRL.CLK_SRC = SystickCfg.ClockSource ;/*Select clock source for systick */
	STCTRL.INTEN = SystickCfg.IntrMode  ;	/*Select disable/enable for systick */
	/* Set Preload value */
	STRELOAD = 15999999;/*SystickCfg.TickFreq * SystickCfg.SystemClock -1 ;*/
}

void Systick_Start(Systick_TicksType Ticks)
{
	STCURRENT = 0 ; 	/*Write dummy vale to clear systick current reg */
	desiredTicks = Ticks ;
	STCTRL.EN = 1 ;   /*trigger systick timer now*/
}

void Systick_Disable(void) 
{
	STCTRL.EN = 0 ;
}


Systick_TicksType Systick_GetTicksElapsed(void)
{
	return currTicks ;
}


Systick_TicksType Systick_GetTicksRemaining(void)
{
	return desiredTicks - currTicks ;
}



void callback (void (*ptr)())
{
	callbackptr=ptr;
}

void SysTick_Handler(void)
{ currTicks ++ ;
	if(callbackptr!=NULL)
	callbackptr();
}

