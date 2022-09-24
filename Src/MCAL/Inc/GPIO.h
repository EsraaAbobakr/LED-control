/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCrtl.h
 *       Module:  IntCrtl
 *
 *  Description:  header file for IntCrtl Module    
 *  
 *********************************************************************************************************************/
#ifndef GPIO_H
#define GPIO_H
#include "Std_Types.h"
#include "Mcu_Hw.h"
/*#include "GPIO_Cfg.h""*/
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PORTA		0X01
#define PORTB		0X02
#define PORTC		0X04
#define PORTD		0X08
#define PORTE		0X10
#define PORTF		0X20
#define Bit_Band_Reg(Addr,Bit)        ( ((Addr) & 0xF0000000) + 0x2000000 + (((Addr) &0xFFFFF) << 5) + ((Bit)<<2) )	
#define Bit_Band_Access(Addr , Bit , Value)           (*((volatile uint32 *)Bit_Band_Reg( (Addr),(Bit))) = (Value))
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
extern void GPIO_Init (uint32 port, uint32 pin,uint32 direction,uint32 level);
extern void Gpio_Dir_set(uint8 port, uint8 pin,uint8 direction);
extern void Gpio_PinWrite(uint8 port, uint8 pin, uint8 level);
/*
extern void Gpio_Init(const GpioConfiguration* const cnfg_table,
		uint8_t cnfgTable_size);

extern void Gpio_Dir_set(GpioPorts port, GpioPins pin,
		GpioPinDirection_t direction);
extern GpioPinDirection_t Gpio_Dir_get(GpioPorts port, GpioPins pin);

extern void Gpio_PinWrite(GpioPorts port, GpioPins pin, GpioPinState_t state);
extern void Gpio_PinToggle(GpioPorts port, GpioPins pin);
extern int32_t Gpio_PinRead(GpioPorts port, GpioPins pin);*/
#endif  /* IntCrtl_H */

/**********************************************************************************************************************
 *  END OF FILE: GPIO.h
 *********************************************************************************************************************/