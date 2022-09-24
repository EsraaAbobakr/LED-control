#include "App.h"

#define T_ON_SEC    5U
#define T_OFF_SEC   1U
int main(void)
{
	  IntCrtl_Init() ;	       // Configure Exceptions controls
  SysCtrl_ClockInit() ;   // Configure System clock
Systick_Init() ;  
LED_1 lede;
	uint16 TicksON  = (T_ON_SEC  *1000 ) / 60000 ;
	uint16 TicksOFF = (T_OFF_SEC *1000 ) / 60000 ;
	while(1)
	{
		
		/* There will be a red blink forever with the entered ON and OFF Periods */
		
		 /*Led_TurnOn(Led_LedChannelType LedChannel);*/
 
	/*	 Led_TurnOff(Led_LedChannelType LedChannel);*/
		Led_TurnOn(lede);
		Led_control(TicksON,TicksOFF);
	}

	return 0;
}
