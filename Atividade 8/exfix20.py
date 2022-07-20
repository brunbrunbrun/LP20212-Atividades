import numpy as np

# define a quantidade de dados a serem lidos
dados = 20

# inicialização de listas e dicionarios
Alturas_Lista = []
Alturas_Lista_Mulheres = []

Notas_Lista_Homens = []
Notas_Lista_Mulheres = []

Nascimentos_Dic = {}

# loop para inserir todos os dados
for i in range(dados):

    print(f"Insira os dados do #{i+1} aluno.")

    Altura = float(input("Altura: "))
    Nota = float(input("Nota: "))
    Nascimento = int(input("Ano do nascimento: "))
    sexo = input("Sexo (M ou F): ")
    print("\n")

    # adiciona as variaveis do aluno nas listas
    Alturas_Lista.append(Altura)
    if (sexo == 'F'):
        Alturas_Lista_Mulheres.append(Altura)
        Notas_Lista_Mulheres.append(Nota)
    else:
        Notas_Lista_Homens.append(Nota)

    if (Nascimento in Nascimentos_Dic):
        Nascimentos_Dic[Nascimento] += 1
    else:
        Nascimentos_Dic[Nascimento] = 1

# separação em um vetor para poder executar as funçoes do numpy
array_Alturas = np.array(Alturas_Lista)

# media e acima da media com o numpy
Media_Altura_Molier = (np.array(Alturas_Lista_Mulheres)).mean()
qtd_Molier = 0

for Altura in Alturas_Lista_Mulheres:
    if (Altura > Media_Altura_Molier):
        qtd_Molier += 1
Media_Nota_Molier = (np.array(Notas_Lista_Mulheres)).mean()

# notas dos homi
qtd_Homi = 0
for Nota in Notas_Lista_Homens:
    if (Nota < Media_Nota_Molier):
        qtd_Homi += 1


# print dos resultados
print("\n---------------------\n")

print(f"Maior altura da turma: {array_Alturas.max()}")
print(f"Menor altura da turma: {array_Alturas.min()}\n")

print(f"Quantidade de mulheres com altura acima da média\
das alturas das mulheres: {qtd_Molier}\n")

print(f"Quantidade de homens com nota inferior a média\
das notas das mulheres: {qtd_Homi}\n")

# loop para cada um dos anos
# fora de ordem
print("Percentual de pessoas que nasceram em cada ano inserido: ")
for ano in Nascimentos_Dic:
    print(f"{ano} -- {(Nascimentos_Dic[ano] * 100 / dados):.2f}%")
