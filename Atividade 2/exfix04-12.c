#include <stdio.h>

int main()
{
    int entrada[11];
    int cont = 0;
    int inicial = 0;


    printf("\n-------\n");

    //Vetor de entrada
    for(int i = 0; i < 10; i++)
    {
        printf("\nInsira o #%d numero de entrada: ", i);
        scanf("%d",&entrada[i]);
    }
    
    entrada[10] = -1;
    
    printf("\n---------\n|(i)|(m)|\n");

	//Processamento principal
    for(int i = 1; i < 11 ; i++)
    {
		//se o atual for menor q o ultimo
        if((entrada[i]) < (entrada[i-1]))
        {
            printf("| %d | %d | \n",inicial,(i - cont));
            inicial = i;
            cont = i;
        }
    }
    
	printf("---------\n");

    return 0;
} 
