#include <stdio.h>

void main_1()
{
	int x, div = 2,  rest = 0;
	scanf("%d", &x);

	if(x != 0)
	{
		while((x % div) != 0)
		{
			div++;

		}

		if(x == div)
		{
			printf("1");
		}else{
			printf("0");
		}
	}
}

//gcc teste1.c -o teste1
