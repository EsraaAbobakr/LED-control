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
#include <stdint.h>
#include <stdlib.h>
#include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#define NumberOfPorts  8  
#define NumberOfPins   8

#define CORE_PERI_BASE                         0xE000E000
#define APINT                                  (*((volatile uint32*)(CORE_PERI_BASE+0xD0C)))
#define VECTKEY_APINT                          0x05FA
#define GROUP_TYPE                GROUP_XXY 
#define NVIC_IQR_ACTIVE_NO         4
#define ACTIVATED_PERPH_GATES  3
#define RST_CTRL_BASE                          0x400FE000
#define STCTRL_OFFSET                          0x10 
#define STRELOAD_OFFSET                        0x14 
#define STCURRENT_OFFSET                       0x18 

#define RCC_OFFSET                             0x60
#define RCC2_OFFSET                            0x70
#define RIS_OFFSET                             0x50
#define RCGCWD_OFFSET                          0x600
#define RCGCGPIO_OFFSET                        0x608
#define PLLMIS_BITOFFSET                       0x6
#define PLL_STATUS           PLL_NOT_USED	
#define XTAL_CLOCK           XTAL_CLOCK_16MHZ  
#define OSCILLATOR_SOURCE    OSCSRC_MOSC
#define XTAL_CLOCK_KHZ       16000


#define STCTRL                                 (*((volatile STCTRL_BF*) (CORE_PERI_BASE+STCTRL_OFFSET)))
#define STCURRENT                              (*((volatile uint32*)(CORE_PERI_BASE+STCURRENT_OFFSET)))
#define STRELOAD                               (*((volatile uint32*)(CORE_PERI_BASE+STRELOAD_OFFSET)))
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define RCGCGPIOww						(*(( volatile uint32_t *)0x400FE608))
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
(uint32*)((PortA)+(GPIO_O_DATA)+(0x3fc)),   /*// Data register for port A*/
(uint32*)((PortB)+(GPIO_O_DATA)+(0x3fc)),   /*// Data register for port B*/
(uint32*)((PortC)+(GPIO_O_DATA)+(0x3fc)),   /*// Data register for port C*/
(uint32*)((PortD)+(GPIO_O_DATA)+(0x3fc)),   /*// Data register for port D*/
(uint32*)((PortE)+(GPIO_O_DATA)+(0x3fc)),   /*// Data register for port E*/
(uint32*)((PortF)+(GPIO_O_DATA)+(0x3fc)),   /*// Data register for port F*/
};

/*//------------------------------------------------------------------------------------*/
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





 //Systick
typedef struct
{
uint32
	        EN        :1  ,
	        INTEN     :1  ,
	        CLK_SRC   :1  ,
	                  :13 ,
	        COUNT     :1  ,
	                  :15 ;
	
}STCTRL_BF;

typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;

//RCC

typedef struct
{
uint32
  MOSCDIS    :1,
	           :3,
	OSCSRC     :2,
	XTAL       :5,
	BYPASS     :1,
	           :1,
	PWRDN      :1,
	           :3,
	PWMDIV     :3,
	USEPWMDIV  :1,
	           :1,
	USESYSDIV  :1,
	SYSDIV     :4,
	ACG        :1,
	           :4;
	
}RCC_BF ;	

typedef union
{
	uint32 R ;
	RCC_BF B ;
	
}RCC_Tag;	


//RCC2

typedef struct 
{
uint32
	           :4,
	OSCSRC2    :3,
             :4,
  BYPASS2    :1,
	           :1,
	PWRDN2     :1,
	USBPWRDN   :1,
	           :7,	
	SYSDIV2LSB :1,
	SYSDIV2    :6,
	           :1,
	DIV400     :1,
	USERCC2    :1;
	
}RCC2_BF ;	

typedef union
{
     uint32 R  ;
     RCC2_BF B ;
}RCC2_Tag ;
#define RCC                                    (*((volatile RCC_Tag*) (RST_CTRL_BASE+RCC_OFFSET)))	
#define RCC2                                   (*((volatile RCC2_Tag*)(RST_CTRL_BASE+RCC2_OFFSET)))
 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/