#include "Std_Types.h"
#include "Systick.h"

#define SYSTEM_CLOCK_KHZ     DEFAULT_SYSTEM_CLOCK

static volatile Systick_TicksType currTicks ;  // currTick +=1 every systic timer wrap [ count =1]
static Systick_TicksType desiredTicks ;
 
 const Systick_ConfigType SystickCfg = 
 {
	  SYSTIC_FREQ_1KHZ     ,
	  SYTICK_SYSTEM_CLK ,
	  DEFAULT_SYSTEM_CLOCK ,
	 SYSTIC_INTERRUPT_ENABLE
 } ; 
  const SysCtrl_PeripheralGateType PeriGate_cfg[ACTIVATED_PERPH_GATES] = 
 {
	  GPIOA_GATE , 
	  GPIOF_GATE ,
	  TIMR0_16_32 
  
 } ;
  const SysCtr_CLockType SystemClock = SYSTEM_CLOCK_KHZ ; // KHz

void Systick_Init(void)
{
	STCTRL.EN = 0 ; 
	STCURRENT = 0 ; 
	STCTRL.CLK_SRC = SystickCfg.ClockSource ;
	STCTRL.INTEN = SystickCfg.IntrMode  ;	
	STRELOAD = SystickCfg.TickFreq * SystickCfg.SystemClock -1 ;
	
}



void Systick_Start(Systick_TicksType Ticks)
{
	/*Write dummy vale to clear systick current reg */
	
	STCURRENT = 0 ; 
	currTicks = 0 ;
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
}