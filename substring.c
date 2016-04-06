#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFF_S 255

void main_7()
{


	char words[BUFF_S];
	char side;
	char seps[] = " ";
	char* token;
	int var;
	int i = 0;
	int j = 0;
	int x = 0;
	int start = 0;
	int offset = 0;

	char palavra[30];
	do{
		words[BUFF_S];
		do{
			fgets( words, BUFF_S, stdin );
		}while(words[0] == '\n');

		token = strtok (words, seps);
		j = 0;
		do
		{
			if(j == 1)
			{
				sscanf (token, "%d", &var);
				start = var;
			}
			else if(j == 2){
				sscanf (token, "%d", &var);
				offset = var;

			}else{

				for(x = 0; x < strlen(token); x++)
				{
					palavra[x] = token[x];
				}
			}
			token = strtok (NULL, seps);
			j++;
		}while(token != NULL);
		if(palavra[0] == 'X' &&  palavra[1] == 'X' && start == 0 && offset == 0 )
		{
			abort();
		}else{
			for(x = start; x <= offset; x++)
			{
				printf("%c", palavra[x]);
			}
			printf("\n");
		}

	}while(i == 0);

}
