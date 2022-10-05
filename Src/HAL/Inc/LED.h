#ifndef LED_H_
#define LED_H_
#define LED_1			DIO_CONFIG_PORTA_PIN0


#include "Std_Types.h"
#include "GPIO_Cfg.h"

extern void Init_led(void);
extern void Led_TurnOn(void);
extern void Led_Turnoff(void);

 
#endif 
