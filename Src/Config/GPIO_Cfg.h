#ifndef GPIO_Cfg_H
#define GPIO_Cfg_H

#include <stdint.h>
#include <stdlib.h>
#include "GPIO.h"


#define NumberOfPorts  8  
#define NumberOfPins   8


typedef enum {Porta, Portb, Portc, Portd, Porte, Porf } GpioPorts;

typedef enum {pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7} GpioPins;

typedef enum {gpio_low, gpio_high} GpioPinLevel;

typedef enum {gpio_input,	gpio_output } GpioPinDirection;

typedef struct {
	GpioPorts port;
	GpioPins pin;
	GpioPinDirection direction;
	GpioPinLevel level;
} GpioConfiguration;

GpioConfiguration* SET_CONFIG(GpioConfiguration*);
#endif 
