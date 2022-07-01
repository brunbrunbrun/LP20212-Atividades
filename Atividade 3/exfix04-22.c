#include <stdio.h>

int main()
{
	int entrada[5][5];
	int condensada[25][3];
	int contador = 0;
	
	printf("\n---------\n");
	
	//recebendo a matriz de entrada
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			 printf("\nValor [%d][%d]: ",i,j);
			 scanf("%d",&entrada[i][j]);
		}
	}
	
	printf("\n----------");
	
	//processamento e alocacao da condensada
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if((entrada[i][j]) != 0)
			{
				condensada[contador][0]= entrada[i][j];
				condensada[contador][1]= i;
				condensada[contador][2]= j;
				contador++;
			}
		}
	}
	
	printf("\n|Valor|Linha|Coluna|");
	//mostrar a matriz condensada
	for(int i = 0; i < contador; i++)
	{
		printf("\n| %d | %d | %d |",condensada[i][0],condensada[i][1],condensada[i][2]);
	}
	return 0;
}

