#include <stdio.h>
#include "modulos.h"

typedef struct Funcionarios
{
  char nome[50];
  char cargo[50];
  float salario;
  int dependentes;
}Funcionarios;

void opcao_1()
{
  Funcionarios f[100];
  FILE *Funcionarios_dat = fopen("Funcionarios.dat","rb");
  int total_lidos = fread(&f,sizeof(Funcionarios),99,Funcionarios_dat);

  fclose(Funcionarios_dat);

  printf("A empresa tem %d funcionarios\n",total_lidos);

}
