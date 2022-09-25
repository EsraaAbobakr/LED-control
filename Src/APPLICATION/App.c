#include "App.h"

int main(void)
{
	Data_types_Ticks TicksON  = 0x03;/*(T_ON_SEC  *1000);*/
	Data_types_Ticks TicksOFF = 0x03;/*(T_OFF_SEC *1000);*/
	while(1)
	{
		Blink_Led(TicksON,TicksOFF);
	}

}
