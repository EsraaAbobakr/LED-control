#include "GPIO_Cfg.h"


extern GpioConfiguration *LED_2;


GpioConfiguration* SET_CONFIG( GpioConfiguration* LED_2)
{
	LED_2->direction=55;/*gpio_output;*/
	LED_2->port=Porf;
	LED_2->pin =pin2;
	return LED_2;
}
