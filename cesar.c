#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFF_S 255

int main_4()
{
	int offset, i, j, new_c_pos;
	new_c_pos = 0;
	char words[BUFF_S];
	char alf[26] = { 'a', 'b' ,'c' ,'d' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j' ,'k' ,'l' ,'m' ,'n' ,'o' ,'p' ,'q' ,'r' ,'s' ,'t' ,'u' ,'v' ,'w' ,'x' ,'y' ,'z'};
	printf("Entre com offset do alfabeto: \n");
	scanf("%d", &offset);
	printf("Entre com seu texto: \n");
	do{
		fgets( words, BUFF_S, stdin );
	}while(words[0] == '\n');


	printf("\n");
	if(strlen(words) > 0 && words[0] != '0')
	{
		for(i = 0; i < strlen(words);i++)
		{
			words[i] = tolower(words[i]);
			printf("%c", words[i] );
		}
		for(i = 0; i <= strlen(words);i++)
		{
			if(isspace(words[i]))
			{
				printf(" ");
			}else if(words[i] == '.')
			{
				printf(".");
			}else{
				for(j = 0; j < strlen(alf);j++)
				{
					if(words[i] == alf[j])
					{
						if((j + offset) >= sizeof(alf))
						{
							new_c_pos = (j + offset);
							do{
								new_c_pos = new_c_pos - sizeof(alf);
							}while(new_c_pos >= sizeof(alf));
							printf("%c", toupper(alf[new_c_pos]) );
						}else{
							printf("%c", toupper(alf[(j+offset)]) );
						}
					}
				}
			}
		}
	}

}


