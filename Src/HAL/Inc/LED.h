#ifndef LED_H_
#define LED_H_

/**********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "Std_Types.h"
#include "GPIO_Cfg.h"
/**********************************************************************************************************************
*  GLOBAL DATA PROTOTYPES
*********************************************************************************************************************/
static GpioPorts b=PORTF;
static GpioPins c=pin1;
typedef struct {
	  GpioPorts b;
	GpioPins c;
} DIO_CONFIG_PORTA_PIN0;

void Led_TurnOn(DIO_CONFIG_PORTA_PIN0 LedChannel);
 
 
 #endif /* LED_H_ */
 /**********************************************************************************************************************
 *  END OF FILE: Led.h
 *********************************************************************************************************************/
