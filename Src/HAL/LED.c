#include "Std_Types.h"
#include "LED.h"

 
void Led_TurnOn(DIO_CONFIG_PORTA_PIN0 LedChannel)
{GpioPinDirection hi=gpio_output;
	GpioPinLevel rr= gpio_high;
	GpioConfiguration *tt;
	tt->port=LedChannel.b;
	tt->pin=LedChannel.c;
	tt->level=rr;
	tt->direction=hi ;

	Dio_WriteChannel(tt);
}


