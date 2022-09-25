#ifndef GPIO_H
#define GPIO_H
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Port_regs.h"

#define PORTA		0X01
#define PORTB		0X02
#define PORTC		0X04
#define PORTD		0X08
#define PORTE		0X10
#define PORTF		0X20
#define Bit_Band_Reg(Addr,Bit)        ( ((Addr) & 0xF0000000) + 0x2000000 + (((Addr) &0xFFFFF) << 5) + ((Bit)<<2) )	
#define Bit_Band_Access(Addr , Bit , Value)           (*((volatile uint32 *)Bit_Band_Reg( (Addr),(Bit))) = (Value))


extern void GPIO_Init (uint32 port, uint32 pin,uint32 direction,uint32 level);
extern void Gpio_Dir_set(uint8 port, uint8 pin,uint8 direction);
extern void Gpio_PinWrite(uint8 port, uint8 pin, uint8 level);

#endif  