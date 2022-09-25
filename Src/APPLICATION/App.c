#include "App.h"

int main(void)
{
	Data_types_Ticks TicksON  = 0x01;/*(T_ON_SEC  *1000);*/
	Data_types_Ticks TicksOFF = (T_OFF_SEC *1000);
	while(1)
	{
		Blink_Led(TicksON,TicksOFF);
	}

}
