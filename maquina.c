#include <stdio.h>

void main_3()
{
	int conn1[5], conn2[5], teste[5], pos, result=0;
	for(pos=0; pos<5; pos++)
	{
		printf("Entre com o primeiro conector - posicao %d \n", pos);
		scanf("%d", &conn1[pos]);
	}
	printf("\n Voce entrou com o conector1:\n %d  %d  %d  %d  %d \n", conn1[0], conn1[1], conn1[2], conn1[3], conn1[4]);
	for(pos=0; pos<5; pos++)
	{
		printf("Entre com o segundo conector - posicao  %d \n", pos);
		scanf("%d", &conn2[pos]);
	}
	printf("\n Conector 1: %d  %d  %d  %d  %d \n", conn1[0], conn1[1], conn1[2], conn1[3], conn1[4]);

	printf("\n Conector 2: %d  %d  %d  %d  %d \n", conn2[0], conn2[1], conn2[2], conn2[3], conn2[4]);

	int naaa = 0;
	for(pos=0; pos<5; pos++)
	{
		if(conn1[pos] == conn2[pos])
		{
			naaa = 1;
		}
	}
	if(naaa == 1)
	{
	printf("\n\nN\n\n");
	}
	else
	printf("\n\nY\n\n");
}


