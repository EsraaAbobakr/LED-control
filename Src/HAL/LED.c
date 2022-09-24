#include "Std_Types.h"
#include "LED.h"

 GpioConfiguration *tt;
  GpioConfiguration *ss;
void Led_TurnOn(DIO_CONFIG_PORTA_PIN0 LedChannel)
{GpioPinDirection hi=gpio_output;
	GpioPinLevel rr= gpio_high;
	
	tt->port=LedChannel.b;
	tt->pin=LedChannel.c;
	tt->level=rr;
	tt->direction=hi ;


}
void Led_Turnoff(DIO_CONFIG_PORTA_PIN0 LedChannel)
{GpioPinDirection hi=gpio_output;
	GpioPinLevel rr= gpio_high;
	
	ss->port=LedChannel.b;
	ss->pin=LedChannel.c;
	ss->level=rr;
	ss->direction=hi ;

	
}

void Led_control(uint16 TicksOn , uint16 TicksOff)
{
		
	static uint16 ledStatus = 0 ;
	
	
	if(ledStatus ==  0)
	{
			Dio_WriteChannel(ss);
		Systick_Start(TicksOff) ;
		ledStatus = 1 ;
	}
	
	
	// Led ON for TicksOn
	if(ledStatus == 1 && (Systick_GetTicksElapsed() == TicksOff))
	{
			Dio_WriteChannel(tt);
		Systick_Start(TicksOn) ;
		ledStatus = 0;
	}
	
	
	// Led off for TicksOff
	
	if(ledStatus == 0 && (Systick_GetTicksElapsed() == TicksOn))
	{
			Dio_WriteChannel(ss);
		Systick_Start(TicksOff) ;
		ledStatus = 1;
	}
	
	
	
}


