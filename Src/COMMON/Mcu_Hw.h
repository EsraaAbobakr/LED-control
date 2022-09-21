/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

#include "GPIO_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define RCGCGPIO						*(*(( volatile uint32 *)0x400FE608))
#define GPIO_O_DATA             0x00000000  /* GPIO Data*/
#define GPIO_O_DIR              0x00000400  /*GPIO Direction*/
#define GPIO_O_DEN              0x0000051C  /*GPIO Digital Enable*/


#define PortA    0x40004000    /*portA base address*/
#define PortB    0x40005000    /*portB base address*/
#define PortC    0x40006000    /*PortC base address*/
#define PortD    0x40007000    /*portD base address*/
#define PortE    0x40024000    /*PortE base address*/
#define PortF    0x40025000    /*portF base address*/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
static volatile uint32 * const GpioDataReg[NumberOfPorts]={
(uint32*)((PortA)+(GPIO_O_DATA)+(0x3fc)),   // Data register for port A
(uint32*)((PortB)+(GPIO_O_DATA)+(0x3fc)),   // Data register for port B
(uint32*)((PortC)+(GPIO_O_DATA)+(0x3fc)),   // Data register for port C
(uint32*)((PortD)+(GPIO_O_DATA)+(0x3fc)),   // Data register for port D
(uint32*)((PortE)+(GPIO_O_DATA)+(0x3fc)),   // Data register for port E
(uint32*)((PortF)+(GPIO_O_DATA)+(0x3fc)),   // Data register for port F
};

//------------------------------------------------------------------------------------
static volatile uint32_t * const GpioDEN [NumberOfPorts]={
(uint32_t*)((PortA)+(GPIO_O_DEN)),   // Digital Enable  register for port A
(uint32_t*)((PortB)+(GPIO_O_DEN)),   // Digital Enable  register for port B
(uint32_t*)((PortC)+(GPIO_O_DEN)),   // Digital Enable  register for port C
(uint32_t*)((PortD)+(GPIO_O_DEN)),   // Digital Enable  register for port D
(uint32_t*)((PortE)+(GPIO_O_DEN)),   // Digital Enable  register for port E
(uint32_t*)((PortF)+(GPIO_O_DEN)),   // Digital Enable  register for port F
};


/**
 * The following are pointer array that maps to the data direction register of every Gpio port
 *
 */
static volatile uint32 * const GpioDataDIR[NumberOfPorts]={
(uint32*)((PortA)+(GPIO_O_DIR)),   // Data direction register for port A
(uint32*)((PortB)+(GPIO_O_DIR)),   // Data direction register for port B
(uint32*)((PortC)+(GPIO_O_DIR)),   // Data direction register for port C
(uint32*)((PortD)+(GPIO_O_DIR)),   // Data direction register for port D
(uint32*)((PortE)+(GPIO_O_DIR)),   // Data direction register for port E
(uint32*)((PortF)+(GPIO_O_DIR)),   // Data direction register for port F
};
 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/