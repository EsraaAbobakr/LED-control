#ifndef GPIO_H
#define GPIO_H
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Port_regs.h"

extern void GPIO_Init (uint32 port, uint32 pin);
extern void Gpio_Dir_set(uint8 port, uint8 pin,uint8 direction);
extern void Gpio_PinWrite(uint8 port, uint8 pin, uint8 level);

#endif  