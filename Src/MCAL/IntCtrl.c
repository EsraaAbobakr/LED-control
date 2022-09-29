#include "Std_Types.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"

#define ENABLE_SYSTEM_EXCPTIONS()       (set_FAULTMASK(0))

static __inline void set_FAULTMASK(uint32 faultMask)
{
  /*register uint32 __regFaultMask       __asm("faultmask");
  __regFaultMask = (faultMask & (uint32)1U);*/
}


void IntCrtl_Init(void)
{
	  /*ENABLE_SYSTEM_EXCPTIONS() ;*/
}
