#include <msp430.h>
main()
{
P1DIR = 1;
	while(1)
	{
		while(P1IN & (1<<3) )
		{
			P1OUT=0;
		}
		P1OUT=1;
	}
}
