
#include "Std_Types.h"
#include "SysCtrl.h"

static void Enable_PeriphClock(void) ;


static void Enable_PeriphClock(void)
{
	uint32 * gatesOffset = (uint32 *) (RST_CTRL_BASE +RCGCWD_OFFSET) ;
  uint8 regNum , bitNum ;	
	
	for(uint8 i = 0 ; i < ACTIVATED_PERPH_GATES ; i++)
	 {
		 regNum = PeriGate_cfg[i] /6 ;
		 bitNum = PeriGate_cfg[i] %6 ;
		 
		     *((volatile uint32 *)(regNum + gatesOffset))  |= 1 << (bitNum) ; 
	 }
	
	
}

 const SysCtrl_PeripheralGateType PeriGate_cfg[ACTIVATED_PERPH_GATES] = 
 {
	  GPIOA_GATE , 
	  GPIOF_GATE ,
	  TIMR0_16_32 
  
 } ;
void SysCtrl_ClockInit(void)
{
	 const uint32 freqNotPll[3] = { XTAL_CLOCK_KHZ , 16000 , 4000} ;
	 uint8   pllUSed = PLL_STATUS ;
	 uint32  oscSrc = OSCILLATOR_SOURCE;
	 uint32  maxClk = PLL_MAXCLOCK_KHZ;
	
	 Enable_PeriphClock() ;
	 
	 if(SystemClock == DEFAULT_SYSTEM_CLOCK) return ; //Don't Make any changes
		  
	 RCC2.B.USERCC2 = 1 ; // Enable usage of RCC2 for wide range frequencies.
	
   #if (PLL_STATUS == PLL_USED)
	      RCC2.B.BYPASS2 = 1 ;    //disable PLL until we finish initiate it
   #endif 
	
	//Oscillator Source choice
	RCC2.B.OSCSRC2 = oscSrc ;    //choose Oscillator source

	if(oscSrc == OSCSRC_MOSC)
	{
	        RCC.B.MOSCDIS = 0 ;  //The main oscillator is enabled.
	        RCC.B.XTAL     =  XTAL_CLOCK ; 
	} 
	
	   // Calculate SYSDIV2
	
  if(pllUSed == PLL_USED)
	{
	     RCC2.B.PWRDN2  =0 ;    //power PLL
	     RCC2.B.DIV400  =1 ;    //Use DIV400 [divisiors from 0-127]
			 RCC2.R |= ((maxClk/SystemClock)-1)<<22 ;
	}

  else
	{				
		RCC2.R |= ((freqNotPll[OSCILLATOR_SOURCE] / SystemClock) -1)<<23 ;
	
  }
	
  #if (PLL_STATUS == PLL_USED)
		while( (RIS & (1<<PLLMIS_BITOFFSET )) == 0); // wait until PLL is locked
       RCC2.B.BYPASS2 = 0 ;	//Now Enable PLL 
   #endif	
	
	
}



SysCtr_CLockType SysCtrl_GetSytemClock(void) 
{
	return SystemClock ;
}
