#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFF_S 255

void main_6()
{
	int botas;
	printf("Entre com o numero de botas: \n");
	scanf("%d", &botas);

	if(botas % 2 != 0 || botas < 2 || botas > 10000)
	{
		abort();
	}

	char words[BUFF_S];
	char side;
	char seps[] = " ";
	char* token;
	int var;
	int i = 0;
	int j = 0;
	int count = 0;
	char calcado[botas][2];
	do{
		words[BUFF_S];
		do{
			fgets( words, BUFF_S, stdin );
		}while(words[0] == '\n');

		token = strtok (words, seps);
		j = 0;
		i++;
		while (token != NULL)
		{
			if(j == 0)
			{
				sscanf (token, "%d", &var);
				if(var >= 30 && var <= 60)
				{
					calcado[i][j] = var;
				}else{
					abort();
				}
			}else{
				sscanf (token, "%c", &side);
				if(side == 'E' || side == 'D' )
				{
					calcado[i][j] = side;
				}else{
					abort();

				}
			}
			token = strtok (NULL, seps);
			j++;
		}
		count++;
	}while(count < botas);



	for(i = 1;i <= botas; i++)
	{
		for(j = 0; j <= 1; j++)
		{
			if(j == 1)
			{
				printf("%c", calcado[i][j]);
			}else{
				printf("%d ", calcado[i][j]);
			}
		}
		printf("\n");
	}

	count = 0;
	int pares = 0;
	while(count < botas)
	{
		for(i = 1;i <= botas; i++)
		{
			if(calcado[count][0] != NULL)
			{
				if(calcado[count][0] == calcado[i][0])
				{
					if((calcado[count][1] == 'D' && calcado[i][1] == 'E') || (calcado[count][1] == 'E' && calcado[i][1] == 'D'))
					{
						pares++;
						calcado[count][0] = NULL;
						calcado[i][0] = NULL;
					}
				}
			}
		}
		count++;
	}
	printf("\n");
	printf("PARES: %d ", pares);


}
