/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPIO.c
 *        \brief  GPIO Driver
 *
 *      \details  The Driver Configure All ports and pins in tivac
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "GPIO.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void GPIO_Init (const GpioConfiguration* const cnfg_1)
{
	RCGCGPIO = (1 << cnfg_1->port);
	if (cnfg_1->direction == gpio_output)
			/*pin is output pin*/
			*GpioDataDIR[cnfg_1->port] |= (1 << cnfg_1->pin);
	else
			/*pin is input*/
			*GpioDataDIR[cnfg_1->port] &= ~(1 << cnfg_1->pin);
	
/*digital enable for the pin in this port */
		*GpioDEN[cnfg_1->port] |= (1 << cnfg_1->pin);


		//set state of the pin
		if (cnfg_1->level == gpio_high)
			//set pin high
			*GpioDataReg[cnfg_1->port] |= (1 << cnfg_1->pin);
		else
			*GpioDataReg[cnfg_1->port] |= (1 << cnfg_1->pin);

	

}
void Gpio_Dir_set(GpioPorts port, GpioPins pin, GpioPinDirection direction) {
	if (direction == gpio_input)
		*GpioDataDIR[port] |= (1 << pin);
	else
		*GpioDataDIR[port] &= ~(1 << pin);
}
void Gpio_PinWrite(GpioPorts port, GpioPins pin, GpioPinLevel level) {
	if (level == gpio_high)
		*GpioDataReg[port] |= (1 << pin);
	else
		*GpioDataReg[port] &= ~(1 << pin);
}
/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/