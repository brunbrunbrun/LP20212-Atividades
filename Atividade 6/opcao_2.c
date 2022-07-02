#include <stdio.h>
#include <string.h>
#include "modulos.h"

void opcao_2()
{
    //salario minimo no momento R$1212
    float salario_minimo = 1212;
    FILE *Funcionarios_dat = fopen("Funcionarios.dat", "rb");

    Funcionarios funcionario_atual;


    while(fread(&funcionario_atual, sizeof(Funcionarios), 1, Funcionarios_dat))
    {
        if((funcionario_atual.dependentes >= 1) && (funcionario_atual.salario <= (salario_minimo*2)) )
        {
            int tec = strcmp(funcionario_atual.cargo, "TECNICO EM ELETRONICA");
            if(tec == 0)
            {
                printf("\n%s\n",funcionario_atual.nome);
            }
        }
    }

    fclose(Funcionarios_dat);

}
