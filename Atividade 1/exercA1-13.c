#include <stdio.h>

int main()
{
	int qtd_consul,qtd_vendida;
	float salario_min, preco_maquina, salario_consul, comissao, preco_fin;
	float valor_total,lucro_liq;
	
	printf("Quantidade de consultores: ");
	scanf(" %d",&qtd_consul);
	
	printf("Valor atual do salario minimo: ");
	scanf(" %f",&salario_min);
	
	printf("Preco de custo de cada maquina: ");
	scanf(" %f",&preco_maquina);
	
	printf("Quantidade de maquinas vendidas: ");
	scanf(" %d",&qtd_vendida);
	
	preco_fin = ((preco_maquina * 0.5) + preco_maquina);
	
	valor_total = (preco_fin * qtd_vendida);
	
	comissao = ((preco_maquina * 0.1) * qtd_vendida)/qtd_consul;
	
	salario_consul = ((salario_min * 2) + (comissao));
	
	lucro_liq = (valor_total - ((salario_consul * qtd_consul)+(preco_maquina * qtd_vendida)));
	
	printf("-----------------------------\n");
	printf("O salario de cada empregado e de R$%.2f \nO lucro liquido da loja e R$%.2f ", salario_consul,lucro_liq);
	
	return 0;
}

