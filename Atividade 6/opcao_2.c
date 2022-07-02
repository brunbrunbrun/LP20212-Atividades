#include <stdio.h>
#include "modulos.h"

void opcao_2()
{
    //salario minimo no momento R$1.212
    //float salario_minimo = 1.212;
    FILE *Funcionarios_dat = fopen("Funcionarios.dat", "rb");

    Funcionarios funcionario_atual;


    while(fread(&funcionario_atual, sizeof(Funcionarios), 1, Funcionarios_dat))
    {
        printf("\n%s %s %.2f %d\n",funcionario_atual.nome,funcionario_atual.cargo,funcionario_atual.salario,funcionario_atual.dependentes);    
    }

    fclose(Funcionarios_dat);

}
