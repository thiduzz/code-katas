#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFF_S 255

float round_flt(float temp, int dec_arrendondar)
{
	float d_rtn, i_div, i_mlt;
	int mei = 5;
	if(temp<0) mei = -5;
	i_div = mei/pow(10,dec_arrendondar+1);
	i_mlt = pow(10, dec_arrendondar);
	d_rtn = (temp + i_div)*(i_mlt)/(i_mlt);
	return d_rtn;
}

void main_8()
{
	char words[BUFF_S];
	float notas[12] = {  100.00, 50.00, 20.00, 10.00, 5.00, 2.00, 1.00, 0.50, 0.25, 0.10, 0.05, 0.01 };
	char seps[] = " ";
	char* token;
	float total, dinheiro;
	int i = 0;
	int j = 0;
	int options = sizeof(notas)/sizeof(notas[0]);
		do{
			fgets( words, BUFF_S, stdin );
		}while(words[0] == '\n');

		token = strtok (words, seps);
		while (token != NULL)
		{
			if(i == 0)
			{
				sscanf (token, "%f", &total);
			}else if(i == 1)
			{
				sscanf (token, "%f", &dinheiro);
			}

			token = strtok (NULL, seps);
			i++;
		}
		printf("Total: %.2f Dinheiro: %.2f \n", total, dinheiro);
		if(dinheiro != 0 && total != 0)
		{
			float troco = dinheiro - total;
			if(troco >= 0)
			{
				printf("%.2f \n", troco);
					int troco_qty[12] = {0};
					float troco_temp = 0.00;
					int temp = 0;
					for(i = 0; i <= options;i++)
					{
						troco_temp = troco;
						for(j = 0; j <= options; j++)
						{
							troco_temp = troco_temp - (troco_qty[j]*notas[j]);
						}
						if(notas[i] <= 1)
						{
							temp = round_flt(troco_temp/notas[i], 2);
							if(temp >= 1)
							{
								troco_qty[i] = troco_qty[i] + temp;
								troco_temp = troco_temp - (temp*notas[i]);
							}
						}else{

							temp = floorf(troco_temp/notas[i]);
							if(temp >= 1)
							{
								troco_qty[i] = troco_qty[i] + temp;
								troco_temp = troco_temp - (temp*notas[i]);
							}
						}
					}
					if(roundf(troco_temp) == 0)
					{
						for(i = 0; i < options;i++)
						{
							printf(" %ld ", troco_qty[i]);
						}
						printf("\n");
					}else{
						printf("*\n");
					}

			}else{
				printf("Dinheiro insuficiente\n");
			}
		}

}

