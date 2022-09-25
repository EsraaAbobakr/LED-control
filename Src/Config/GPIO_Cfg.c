#include "GPIO_Cfg.h"



GpioConfiguration* SET_CONFIG( GpioConfiguration* LED_2)
{
	LED_2->direction=gpio_output;
	LED_2->port=Porf;
	LED_2->pin=pin2;
	LED_2->level=gpio_low;
	return LED_2;
}
