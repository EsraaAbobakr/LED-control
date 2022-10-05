#include "GPIO.h"
#include "GPIO_Cfg.h"
#include "Port_regs.h"
void GPIO_Init(uint32 port_, uint32 pin_)
{	
	SET_BIT(RCGCGPIO, port_);
	switch(port_)
	{case 0:
		SET_BIT(GPIO_PORTA_GPIODEN,pin_);
		break;
	case 1:
		SET_BIT(GPIO_PORTB_GPIODEN,pin_);
		break;
	case 2:
		SET_BIT(GPIO_PORTC_GPIODEN,pin_);
		break;
	case 3:
		SET_BIT(GPIO_PORTD_GPIODEN,pin_);
		break;
	case 4:
		SET_BIT(GPIO_PORTE_GPIODEN,pin_);
		break;
	case 5:
		SET_BIT(GPIO_PORTF_GPIODEN,pin_);
		break;
	}
}



void Gpio_Dir_set(GpioPorts port, GpioPins pin, GpioPinDirection direction) 
{	
	if (direction == gpio_output)
	{switch(port)
		{case 0:
			SET_BIT(GPIO_PORTA_GPIODIR,pin);
			break;
		case 1:
			SET_BIT(GPIO_PORTB_GPIODIR,pin);
			break;
		case 2:
			SET_BIT(GPIO_PORTC_GPIODIR,pin);
			break;
		case 3:
			SET_BIT(GPIO_PORTD_GPIODIR,pin);
			break;
		case 4:
			SET_BIT(GPIO_PORTE_GPIODIR,pin);
			break;
		case 5:
			SET_BIT(GPIO_PORTF_GPIODIR,pin);
			break;
		}}
	else
		{switch(port)
		{case 0:
			CLEAR_BIT(GPIO_PORTA_GPIODIR,pin);
			break;
		case 1:
			CLEAR_BIT(GPIO_PORTB_GPIODIR,pin);
			break;
		case 2:
			CLEAR_BIT(GPIO_PORTC_GPIODIR,pin);
			break;
		case 3:
			CLEAR_BIT(GPIO_PORTD_GPIODIR,pin);
			break;
		case 4:
			CLEAR_BIT(GPIO_PORTE_GPIODIR,pin);
			break;
		case 5:
			CLEAR_BIT(GPIO_PORTF_GPIODIR,pin);
			break;
		}}
}



void Gpio_PinWrite(GpioPorts port, GpioPins pin, GpioPinLevel level) 
{
	if (level == gpio_high)
	{switch(port)
		{
	case 0:
			SET_BIT(GPIO_PORTF_GPIODATA,pin);
			break;
		case 1:
			SET_BIT(GPIO_PORTF_GPIODATA,pin);
			break;
		case 2:
			SET_BIT(GPIO_PORTF_GPIODATA,pin);
			break;
		case 3:
			SET_BIT(GPIO_PORTF_GPIODATA,pin);
			break;
		case 4:
			SET_BIT(GPIO_PORTF_GPIODATA,pin);
			break;
		case 5:
			SET_BIT(GPIO_PORTF_GPIODATA,pin);
			break;
	}
	}
	else
		{switch(port)
		{
	case 0:
			CLEAR_BIT(GPIO_PORTF_GPIODATA,pin);
			break;
		case 1:
			CLEAR_BIT(GPIO_PORTF_GPIODATA,pin);
			break;
		case 2:
			CLEAR_BIT(GPIO_PORTF_GPIODATA,pin);
			break;
		case 3:
			CLEAR_BIT(GPIO_PORTF_GPIODATA,pin);
			break;
		case 4:
			CLEAR_BIT(GPIO_PORTF_GPIODATA,pin);
			break;
		case 5:
			CLEAR_BIT(GPIO_PORTF_GPIODATA,pin);
			break;
	}
	}
}
