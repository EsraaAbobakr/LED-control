#include "App.h"

int main(void)
{
	Data_types_Ticks TicksON  = 2;/*Time in seconds*//*this means 3 seocnd*/
	Data_types_Ticks TicksOFF = 5;/*Time in seconds*//*this means 5 seocnd*/
	while(1)
	{
		Blink_Led(TicksON,TicksOFF);
	}

}
