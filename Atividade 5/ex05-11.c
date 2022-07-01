#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//registro de atletas
typedef struct TAtleta
{
  int Codigo;
  char Nome[50];
  int QuantVoltas;
  float *Tempos;
  float TempoTotal;
  float TempoMedio;
  bool Vencedor;
  int AbaixoMedia;
} TAtleta;

int main()
{
  TAtleta *lista;
  int qtdeAtletas, venc = 0;
  float VoltaMaisRapida = 10000;


  //lendo e alocando os atletas
  printf("Quantidade de atletas na competicao: ");
  scanf(" %d", &qtdeAtletas);

  lista = (TAtleta*) malloc(qtdeAtletas * sizeof(TAtleta));
  if(lista != NULL)
  {
      //registrando dados de cada atleta
      for(int i = 0; i < qtdeAtletas; i++)
      {
      printf("===================\n==== Atleta #%d ====\n===================\n",i+1);

      printf("Codigo do Atleta: ");
      scanf(" %d", &lista[i].Codigo);

      printf("Nome do Atleta: ");
      scanf(" %s", lista[i].Nome);

      printf("Quantidade de voltas: ");
      scanf(" %d", &lista[i].QuantVoltas);

      //alocando memoria para o tempo de cada uma das voltas
      lista[i].Tempos = (float*) malloc(lista[i].QuantVoltas * sizeof(float));
      if(lista[i].Tempos != NULL)
      {
        for(int j = 0; j < lista[i].QuantVoltas; j++)
        {
          printf("Tempo da volta %d de %d: ", j+1, lista[i].QuantVoltas);
          scanf(" %f", &lista[i].Tempos[j]);

          //tempo total de voltas do atleta
          lista[i].TempoTotal += lista[i].Tempos[j];

          //volta mais rapida de todos
          if(lista[i].Tempos[j] < VoltaMaisRapida)
          {
              VoltaMaisRapida = lista[i].Tempos[j];
          }
        }

        //tempo medio de voltas do atleta
        lista[i].TempoMedio = (lista[i].TempoTotal)/(lista[i].QuantVoltas);

      }
      else
      {
        printf("Erro na alocacao de memoria para a QUANTIDADE de TEMPOS");
        exit(0);
      }
    }

      //Vencedor
      for(int i = 1; i < qtdeAtletas; i++)
      {
        if(lista[i].QuantVoltas >= lista[venc].QuantVoltas)
        {
          if(lista[i].QuantVoltas == lista[venc].QuantVoltas)
          {
            if(lista[i].TempoTotal < lista[venc].TempoTotal)
            {
              venc = i;
            }
          }
          else
          {
          venc = i;
          }
        }
      }
      for(int i = 0; i < qtdeAtletas; i++)
      {
        if(i == venc)
        {
          lista[i].Vencedor = true;
        }
        else
        {
          lista[i].Vencedor = false;
        }
      }

      //Voltas abaixo da media do Vencedor
      float MediaVencedor = lista[venc].TempoMedio;
      for(int i = 0; i < qtdeAtletas; i++)
      {


          lista[i].AbaixoMedia = 0;
          for(int j = 0; j < lista[i].QuantVoltas; j++)
          {
            if((lista[i].Tempos[j]) < MediaVencedor)
            {
              lista[i].AbaixoMedia++;
            }
          }

      }

      //Mostrar resultados
      printf("\n###############################\n");
      printf("Volta mais rapida entre todos: %0.2f", VoltaMaisRapida);
      printf("\n###############################\n");

      for(int i = 0; i < qtdeAtletas; i++)
      {
        printf("\n###############################\n");
        if(lista[i].Vencedor == true)
        {
          printf("\tVENCEDOR\n");
        }
        printf("%s   cod:%d\n",lista[i].Nome,lista[i].Codigo);
        printf("Tempo Total: \t%0.2f\n",lista[i].TempoTotal);
        printf("Tempo Medio: \t%0.2f\n",lista[i].TempoMedio);
        printf("Voltas Abaixo da media: %d\n",lista[i].AbaixoMedia);

        printf("###############################\n");

      }

  }
  else
  {
    printf("Erro na alocacao de memoria para a LISTA de ATLETAS");
    exit(0);
  }

  //liberar memoria apos resultados
  for(int i = 0; i < qtdeAtletas; i++)
  {
    free(lista[i].Tempos);
  }
  free(lista);

}
