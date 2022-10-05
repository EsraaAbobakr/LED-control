#ifndef SYSTICK_H
#define SYSTICK_H

#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "SysCtrl.h"   // toget system clock


/*system tick has three regiters SysTick Control and Status (STCTRL):, SysTick Reload Value (STRELOAD): sysTick Current Value (STCURRENT): T*/


	
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


#define CORE_PERI_BASE                         0xE000E000 /*Cortex-M4F Peripherals (SysTick, NVIC, MPU, FPU and SCB)*/




#define STCTRL_OFFSET                          0x10 /*SysTick Control and Status Register*/
#define STRELOAD_OFFSET                        0x14 /*SysTick Reload Value Register*/
#define STCURRENT_OFFSET                       0x18 /*SysTick Current Value Register*/
/*regiters stsem tick*/
#define STCTRL                                 (*((volatile STCTRL_BF*)(CORE_PERI_BASE+STCTRL_OFFSET)))
#define STCURRENT                              (*((volatile uint32*)(CORE_PERI_BASE+STCURRENT_OFFSET)))
#define STRELOAD                               (*((volatile uint32*)(CORE_PERI_BASE+STRELOAD_OFFSET)))



typedef enum
{
	SYSTIC_FREQ_1KHZ  =    1   ,
	SYSTIC_FREQ_100HZ =    10  ,
	SYSTIC_FREQ_10HZ  =    100 
}Systick_FreqType ;

typedef enum 
{
	SYTICK_PIOSC_DIV4_CLK = 0 , /*Precision internal oscillator (PIOSC) divided by 4*/
	SYTICK_SYSTEM_CLK     /*System clock*/
}Systick_ClKSourceType ;

typedef enum
{
	SYSTIC_INTERRUPT_DISABLE  = 0 ,
	SYSTIC_INTERRUPT_ENABLE
}Systick_InterruptModeType ;


typedef uint32 Systick_TicksType ;

typedef struct
{
	Systick_FreqType           TickFreq    ;
	Systick_ClKSourceType      ClockSource ;
	SysCtr_CLockType           SystemClock ;
	Systick_InterruptModeType  IntrMode    ;
}Systick_ConfigType ;


extern const Systick_ConfigType SystickCfg ;


void Systick_Init(void) ;
void Systick_Start(Systick_TicksType Ticks) ;
void Systick_Disable(void) ;
/*void SysTick_Handler(void (*ptr)());*/
void callback(void (*)() );
void SysTick_Handler(void);
void A(void);
Systick_TicksType Systick_GetTicksElapsed(void);
Systick_TicksType Systick_GetTicksRemaining(void);
 
#endif  /* SYSTICK_H */
