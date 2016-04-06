#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFF_S 255

void main_5()
{
	char words[BUFF_S];
	float notas[4] = {  100.00, 50.00, 20.00, 10.00 };
	char seps[] = " ";
	char* token;
	int var;
	int i = 0;
	int j = 0;
	int qtys[4];
	int options = sizeof(notas)/sizeof(notas[0]);
	do{
		fgets( words, BUFF_S, stdin );
	}while(words[0] == '\n');

	token = strtok (words, seps);
	while (token != NULL)
	{
	    sscanf (token, "%d", &var);
	    qtys[i++] = var;

	    token = strtok (NULL, seps);
	}
		for(i = 0; i < options;i++)
		{
			printf("Notas: %.2f Qtd: %ld \n", notas[i], qtys[i]);
		}
	float total_saque = 0.00;
	do{
		float total_disp = 0;
		scanf("%f", &total_saque);

		for(i = 0; i < options;i++)
		{
			total_disp += qtys[i]*notas[i];
		}
		printf("Total Disponivel: %.2f \n", total_disp);
		printf("Valor Saque Desejado: %.2f \n", total_saque);
		if(total_disp >= total_saque)
		{
			int saque_qty[4] = {0};
			float saque_temp = 0.00;
			int temp = 0;
			for(i = 0; i < options;i++)
			{
				saque_temp = total_saque;
				if(qtys[i] > 0)
				{
					for(j = 0; j < options; j++)
					{
						saque_temp = saque_temp - (saque_qty[j]*notas[j]);
					}
					temp = floor(saque_temp/notas[i]);
					if(temp >= 1)
					{
						if(temp > qtys[i])
						{
							temp = qtys[i];
						}
						saque_qty[i] = saque_qty[i] + temp;
						saque_temp = saque_temp - (temp*notas[i]);
					}
				}
			}
			if(saque_temp == 0)
			{
				for(i = 0; i < options;i++)
				{
					qtys[i] = qtys[i] - saque_qty[i];
					printf(" %ld ", saque_qty[i]);
				}
				printf("\n");
			}else{
				printf("*\n");
			}
		}else{
			//sem saldo
			printf("*\n");
		}

	}while(total_saque != 0);
}
