#include<stdio.h>
#include<stdlib.h>

void main()
{
	int* x;
	int* y;

	x = malloc(sizeof(int));

	*x = 42;
//	*y = 13;
	y = x;
	*y = 13;

}
