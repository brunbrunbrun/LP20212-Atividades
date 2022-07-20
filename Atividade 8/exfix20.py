import numpy as np

# define a quantidade de dados a serem lidos
dados = 20

Alturas_Lista = []
Alturas_Lista_Mulheres = []
listaNotasMulheres = []
listaNotasHomens = []
dicionarioAnosNascimentos = {}


for i in range(dados):
    altura = float(input('Altura: '))
    nota = float(input('Nota: '))
    anoNascimento = int(input('Ano de nascimento: '))
    sexo = input('Código do sexo ("M" ou "F"): ')
    Alturas_Lista.append(altura)
    if sexo == 'F':
        Alturas_Lista_Mulheres.append(altura)
        listaNotasMulheres.append(nota)
    else:
        listaNotasHomens.append(nota)
    if anoNascimento in dicionarioAnosNascimentos:
        dicionarioAnosNascimentos[anoNascimento] += 1
    else:
        dicionarioAnosNascimentos[anoNascimento] = 1

vetorAlturas = np.array(Alturas_Lista)
mediaAlturasMulheres = (np.array(Alturas_Lista_Mulheres)).mean()
quantidadeMulheres = 0
for altura in Alturas_Lista_Mulheres:
    if altura > mediaAlturasMulheres:
        quantidadeMulheres += 1
mediaNotasMulheres = (np.array(listaNotasMulheres)).mean()
quantidadeHomens = 0
for nota in listaNotasHomens:
    if nota < mediaNotasMulheres:
        quantidadeHomens += 1

print(f'\nMaior altura da turma: {vetorAlturas.max()}')
print(f'Menor altura da turma: {vetorAlturas.min()}')
print(f'Quantidade de mulheres com altura acima da média\
        das alturas das mulheres: {quantidadeMulheres}')
print(f'Quantidade de homens com nota inferior a média\
        das notas das mulheres: {quantidadeHomens}')
print('Percentual de pessoas que nasceram em cada ano inserido: ')
for ano in dicionarioAnosNascimentos:
    print(f'{ano} - {(dicionarioAnosNascimentos[ano] * 100 / dados):.2f}%')
