/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO_Cfg.h
 *       Module:  GPIO
 *
 *  Description:  configration file for GPIO module    
 *  
 *********************************************************************************************************************/
#ifndef GPIO_Cfg_H
#define GPIO_Cfg_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include "GPIO.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define NumberOfPorts  8  
#define NumberOfPins   8




/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*Defining all GPIO PORTS*/
typedef enum {
	PortA, PortB, PortC, PortD, PortE, PortF
} GpioPorts;


/*Defining every pin in every GPIO port*/
typedef enum {
	pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7
} GpioPins;


/*Defining levels of a GPIO pin*/
typedef enum {
	gpio_low,  /*low level (0)*/
	gpio_high  /*high level (1)*/
} GpioPinLevel;


/*Defining directions of a GPIO pin*/
typedef enum {
	gpio_input,    /*input pin (0)*/
	gpio_output    /*output pin (1)*/
} GpioPinDirection;



/*********************************************************************************
                             Configuration Table structure
*********************************************************************************/

/**
 * This is the configuration table structure that will be used
 * to set the configuration parameter of every GPIO pin by defining
 * evey entry in this structure to a specific pin and pass this table to initializing function
 */
typedef struct {
	GpioPorts port;  /**<Choose the port that you want to configure it's pin*/
	GpioPins pin;   /**<Select  the pin that you want to set it's parameters*/
	GpioPinDirection direction; /**<set the direction of the pin as input or outpt*/
	GpioPinLevel level; /**<Set the initial digital level of the pin (High,Low)*/
} GpioConfiguration;
/****************************************************************************************/



/*
************************************************************
prototype function ta return pointer to configuration table
*************************************************************/

void Dio_WriteChannel(GpioConfiguration* );

 
#endif  /* GPIO_Cfg_H */

/**********************************************************************************************************************
 *  END OF FILE: GPIO_Cfg.h
 *********************************************************************************************************************/