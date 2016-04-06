#include <stdio.h>

void main()
{
	int copias, temp;
	int vl_a, vl_b, vl_c;
	do{
		copias = 0;
		vl_a = 0;
		vl_b = 0;
		vl_c = 0;
		scanf("%d", &copias);
		//b
		vl_b = copias*10;
		//a
		if(copias <= 150)
		{
			vl_a = copias*9;
		}else{
			vl_a = -1;
		}
		//c
		temp = copias;
		for(temp = copias; temp >= 0; temp--)
		{
			if(temp >= 0 && temp < 50)
			{
				vl_c += 15;
			}else if(temp >= 51 && temp < 100)
			{
				vl_c += 10;
			}else if(temp >= 100){
				vl_c += 6;
			}
		}
		if(vl_a > 0)
		{
			if(vl_a <= vl_b && vl_a <= vl_c)
			{
				printf("A \n");
			}else if(vl_b <= vl_a && vl_b <= vl_c)
			{
				printf("B \n");
			}else if(vl_c <= vl_b && vl_c <= vl_a)
			{
				printf("C \n");
			}
		}else{
			printf("B: %d C: %d \n", vl_b , vl_c);
			if(vl_b <= vl_c)
			{
				printf("B \n");
			}else if(vl_c <= vl_b)
			{
				printf("C \n");
			}else{
				printf("* \n");
			}
		}




	}while(copias >= 1 && copias <= 1000000);

}
