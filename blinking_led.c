#include <msp430.h>
main()
{
	int i;
	P1DIR = 1;
	while(1){
		P1OUT = 1;
		for(i=0;i<10000;i++);
		P1OUT = 0;
		for(i=0;i<10000;i++);
		}
} 

