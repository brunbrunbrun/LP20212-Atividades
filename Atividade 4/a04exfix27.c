#include <stdio.h>

typedef struct Tmaterias
{
  int semestre;
  char disciplina[20];
  float nota;
  int carga_h;
  int status;
} Tmaterias;

typedef struct Taluno
{
  char nome[30];
  char RGA[9];
  int m_cursadas;
  Tmaterias mat[100];
  float CRE;
  int reprovacoes;
  int semestre_atual;
}Taluno;

int main()
{
  int n_alunos;
  float soma;
  float divison;
  int reprov;
  int melhor = 0;

  printf("Quantidade de candidatos para a bolsa: ");
  scanf(" %d",&n_alunos);

  Taluno alunos[n_alunos];

//entrada de dados para o registro de cada aluno
  for(int i=0; i<n_alunos;i++)
  {
    printf("----Candidato[%d]----\n",i+1);
    printf("Nome: ");
    scanf(" %[^\n]s", alunos[i].nome);
    printf("RGA: ");
    scanf(" %[^\n]s", alunos[i].RGA);
    printf("Quantas materias foram cursadas: ");
    scanf(" %d", &alunos[i].m_cursadas);
    printf("\n----------------\n----Materias----\n----------------\n");
    //disciplinas
    for(int w=0; w<alunos[i].m_cursadas; w++)
    {
      printf("\n---Materia[%d]---\n",w+1);
      printf("Semestre: ");
      scanf(" %d",&alunos[i].mat[w].semestre);
      printf("Disciplina: ");
      scanf(" %[^\n]s",alunos[i].mat[w].disciplina);
      printf("Nota: ");
      scanf(" %f", &alunos[i].mat[w].nota);
      printf("Carga Horaria: ");
      scanf(" %d", &alunos[i].mat[w].carga_h);

    };
    soma = 0;
    divison = 0;
    reprov = 0;
    //CRE calculo
    for(int w=0; w<alunos[i].m_cursadas; w++)
    {
      soma += (alunos[i].mat[w].nota * alunos[i].mat[w].carga_h);
      divison += (alunos[i].mat[w].carga_h);
    }

    alunos[i].CRE = soma/divison;

    //Quantidade reprovacao
    for(int w=0; w<alunos[i].m_cursadas; w++)
    {
      if(alunos[i].mat[w].nota < 5)
      {
        reprov++;
        alunos[i].mat[w].status = 1;
      }
      else
      {
        alunos[i].mat[w].status = 0;
      }
    }
    alunos[i].reprovacoes = reprov;

    //semestre atual
    alunos[i].semestre_atual = (alunos[i].mat[alunos[i].m_cursadas-1].semestre) + 1;


  };
//fim da entrada de dados para cada aluno

//coisas para mostrar
  printf("\n--------\n--------\n");

  for(int i=0; i<n_alunos;i++)
  {
    printf("----Candidato[%d]----\n",i+1);
    //CRE e Semestre atual
    printf("CRE: %0.2f\n",alunos[i].CRE);
    printf("Semestre atual: %d\n",alunos[i].semestre_atual);

    //Quantidade de reprovacao
    printf("Quantidade de reprovacoes: %d\n",alunos[i].reprovacoes);

    //Materias reprovadas no ultimo semestre

    for(int w=0; w<alunos[i].m_cursadas; w++)
    {
      if((alunos[i].mat[w].status == 1) && (alunos[i].mat[w].semestre == alunos[i].semestre_atual) - 1)
      {
        printf("--%s foi reprovado no ultimo semestre.\n",alunos[i].mat[w].disciplina);
      };
    };


  }
  //melhor CRE e menor reprova
  for(int i=1; i<n_alunos;i++)
    {
      if((alunos[i].CRE > alunos[melhor].CRE) && (alunos[i].reprovacoes < alunos[melhor].reprovacoes))
      {
        melhor = i;
      }
    }

    printf("o aluno com maior CRE e menor numero de reprovacoes e: %s",alunos[melhor].nome);


  return 0;
}
