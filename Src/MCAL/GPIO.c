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
void GPIO_Init (uint32 e, uint32 h,uint32 r,uint32 t){

	
	
	
	Bit_Band_Access(0x400FE608,0X02,1) ;

		/*(*(( volatile uint32_t *)0x400FE608)) |= (1 << e);*/
	/*if (r == 1)*/
			/*pin is output pin*/
			/**GpioDataDIR[e] |= (1 << h);
	else*/
			/*pin is input*/
			/**GpioDataDIR[e] &= ~(1 << h);*/
	
/*digital enable for the pin in this port */
		/**GpioDEN[e] |= (1 << h);*/


		/*set state of the pin*/
		/*if (t == 1)*/
			/*set pin high*/
			/**GpioDataReg[e] |= (1 << h);
		else
			*GpioDataReg[e] |= (1 << h);*/

}
void Gpio_Dir_set(uint8 port, uint8 pin, uint8 direction) {
		Bit_Band_Access(0x400FE608,0X02,1) ;

	if (direction == 0)
		*GpioDataDIR[port] |= (1 << pin);
	else
		*GpioDataDIR[port] &= ~(1 << pin);
}
void Gpio_PinWrite(uint8 port, uint8 pin, uint8 level) {
	if (level == 1)
		*GpioDataReg[port] |= (1 << pin);
	else
		*GpioDataReg[port] &= ~(1 << pin);
}
/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/