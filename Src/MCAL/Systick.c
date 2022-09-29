#include "Std_Types.h"
#include "Systick.h"
#include "LED.h"

#define XTAL_CLOCK_KHZ       16000
#define SYSTEM_CLOCK_KHZ     DEFAULT_SYSTEM_CLOCK	

 const Systick_ConfigType SystickCfg = 
 {
	  SYSTIC_FREQ_1KHZ     ,
	  SYTICK_SYSTEM_CLK ,
	  DEFAULT_SYSTEM_CLOCK ,
	 SYSTIC_INTERRUPT_ENABLE
 } ; 
 	TicksON  = 3;/*TicksON/ SystickCfg.TickFreq ; */
	TicksOFF = 3;/*TicksOFF/ SystickCfg.TickFreq  ;*/
static volatile Systick_TicksType currTicks ;  // currTick +=1 every systic timer wrap [ count =1]
static Systick_TicksType desiredTicks ;


const SysCtr_CLockType SystemClock = SYSTEM_CLOCK_KHZ ; // KHz
void Systick_Init(void)
{
	/* Disable Timer Until configuration completed */
	
	STCTRL.EN = 0 ; 
	
	/*Write dummy vale to clear systick current reg */
	
	STCURRENT = 0 ; 
	
	/*Select clock source for systick */
	
	STCTRL.CLK_SRC = SystickCfg.ClockSource ;
	
	/*Select disable/enable for systick */
	
	STCTRL.INTEN = SystickCfg.IntrMode  ;	
	
	/* Set Preload value */
	
	//STRELOAD = SystickCfg.TickFreq * SysCtrl_GetSytemClock()  - 1 ;
	STRELOAD =15999999;/* SystickCfg.TickFreq * SystickCfg.SystemClock -1  ;*/
}
void Systick_Start(Systick_TicksType Ticks)
{
	/*Write dummy vale to clear systick current reg */
	
	STCURRENT = 0 ; 
/*	currTicks = 0 ;*/
	desiredTicks = Ticks ;
	STCTRL.EN = 1 ;       //trigger systick timer now
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
void SysTick_Handler(void)
{
	currTicks ++ ;
static uint32 statuss=0;
	static uint32 saaa=5;
/*	if((currTicks %2)==0&&statuss==0)
	{saaa++;
		Led_Turnoff();
			Systick_Start(10) ;
		currTicks = 0;
		statuss==1;
	}
	if((currTicks %2)==0&&statuss==1)
	{
		Led_TurnOn();
			Systick_Start(2) ;
		currTicks = 0;
		statuss==0;
	}*/
}

