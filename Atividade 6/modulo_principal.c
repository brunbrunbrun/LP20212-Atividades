#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "modulos.h"


int main()
{
  bool SAIR = false;

  //loop do menu principal
  while(SAIR==false)
  {
    int opcao_principal;

    //menu
    printf("--------------------\n");
    printf("\nOPCAO 1\nOPCAO 2\nOPCAO 3\nOPCAO 0(saida)\n");
    printf("\nDigite o numero da opcao escolhida: ");
    scanf(" %d",&opcao_principal);
    printf("\n--------------------\n");

    //escolha da opcao
    switch(opcao_principal)
    {
      case 0: SAIR = true;
      break;

      case 1: opcao_1();
      break;

      case 2: opcao_2();
      break;

      case 3: opcao_3();
      break;

      default : printf("Opcao Invalida\n");
      break;
    }

  }

  exit(1);
}
