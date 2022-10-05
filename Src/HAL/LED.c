#include "LED.h"
#include "Std_Types.h"

GpioConfiguration *Led;
GpioConfiguration *led_1;
 
 
void Init_led(void)
{

	led_1=SET_CONFIG(&Led);
	GPIO_Init(led_1->port,led_1->pin);
	Gpio_Dir_set(led_1->port,led_1->pin,led_1->direction); 
}

void Led_TurnOn(void)
{
	Gpio_PinWrite(led_1->port,led_1->pin,gpio_high) ;
}
void Led_Turnoff(void)
{
	Gpio_PinWrite(led_1->port,led_1->pin,gpio_low) ;
}



