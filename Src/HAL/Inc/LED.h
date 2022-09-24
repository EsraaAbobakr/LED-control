#ifndef LED_H_
#define LED_H_
#define 	LED_1			DIO_CONFIG_PORTA_PIN0

/**********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "Std_Types.h"
#include "GPIO_Cfg.h"
#include "Std_Types.h"
#include "IntCtrl.h"
#include "SysCtrl.h"
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
void Led_Turnoff(DIO_CONFIG_PORTA_PIN0 LedChannel);
 void Led_control(uint16,uint16);
 
 #endif /* LED_H_ */
 /**********************************************************************************************************************
 *  END OF FILE: Led.h
 *********************************************************************************************************************/
