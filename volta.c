#include <stdio.h>

void main_2()
{
	int pv1, pv2, inicial = 0, volta_p1 = 0, volta_p2 = 0, voltas = 1;

	scanf("%d", &pv1);
	scanf("%d", &pv2);


	while(voltas <= 60)
	{

		voltas++;
		if(voltas*pv1 <= (voltas-1)*pv2)
		{

				printf("VOLTA ALCANCADA %d \n", voltas);

				break;
		}

	}
}
