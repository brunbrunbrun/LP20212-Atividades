#include <stdio.h>
#include <stdlib.h>
#include "modulos.h"

void opcao_3()
{
  Funcionarios novo;
  FILE *Funcionarios_dat;
  Funcionarios_dat = fopen("Funcionarios.dat","ab+");


  printf("Informe os dados do novo funcionario\n");

  printf("Nome: ");
  scanf(" %[^\n]s",novo.nome);

  printf("Cargo: ");
  scanf(" %[^\n]s",novo.cargo);

  printf("Salario: ");
  scanf(" %f",&novo.salario);

  printf("Quantidade de dependentes: ");
  scanf(" %d",&novo.dependentes);


  fwrite(&novo,sizeof(Funcionarios),1,Funcionarios_dat);
  fclose(Funcionarios_dat);


}
