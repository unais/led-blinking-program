#include<stdio.h>

void B(int* worthRef){
	*worthRef = *worthRef + 1;
}

void A(){
	int netWorth;
	netWorth = 55;

	printf("Value before calling   %d\n",netWorth);
	B(&netWorth);
	printf("Value after calling   %d\n",netWorth);
}

main()
{
	A();
}
