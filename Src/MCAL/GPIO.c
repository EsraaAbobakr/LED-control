#include "GPIO.h"
#include "GPIO_Cfg.h"

void GPIO_Init (uint32 e, uint32 h,uint32 r,uint32 t)
{	
	SET_BIT(RCGCGPIO, e);
	SYSCTL_RCGCGPIO.BF.GPIOF = 1;
	volatile uint32* Portptr = (volatile uint32*)GPIO_PORTF_BASE_ADDRESS;
	SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODEN_OFFSET), 0X02);
	SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODIR_OFFSET), 0X02);
	/*SET_BIT(GPIO_PORTF_GPIODATA, 0X02);*/
}
void Gpio_Dir_set(GpioPorts port, GpioPins pin, GpioPinDirection direction) 
{	
	if (direction == 0)
		*GpioDataDIR[port] |= (1 << pin);
	else
		*GpioDataDIR[port] &= ~(1 << pin);
}
void Gpio_PinWrite(GpioPorts port, GpioPins pin, GpioPinLevel level) 
{
	if (level == 0)
			SET_BIT(GPIO_PORTF_GPIODATA, pin);
	else
			CLEAR_BIT(GPIO_PORTF_GPIODATA, pin);
}
