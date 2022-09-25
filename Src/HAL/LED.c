#include "Std_Types.h"
#include "LED.h"
#include "Compiler.h"
 GpioConfiguration *ss;
 GpioConfiguration * le;
void Init_led(void)
{
	 le=SET_CONFIG(&ss);

	GPIO_Init(le->port,le->pin,le->direction,le->level);
	Gpio_Dir_set(le->port,le->pin,le->direction); 
}

void Led_TurnOn(void)
{
	Gpio_PinWrite(le->port,le->pin,gpio_high) ;
}
void Led_Turnoff(void)
{
	Gpio_PinWrite(le->port,le->pin,gpio_low) ;
}



