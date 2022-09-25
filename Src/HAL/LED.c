#include "Std_Types.h"
#include "LED.h"

 GpioConfiguration *ss;
 
void Init_led(void)
{
	GpioConfiguration * le =SET_CONFIG(ss);
	GPIO_Init(le->port,le->pin,le->direction,le->level);
	Gpio_Dir_set(le->port,le->pin,le->direction); 
}

void Led_TurnOn(void)
{
	Gpio_PinWrite(ss->port,ss->pin,gpio_high) ;
}
void Led_Turnoff(void)
{
	Gpio_PinWrite(ss->port,ss->pin,gpio_low) ;
}



