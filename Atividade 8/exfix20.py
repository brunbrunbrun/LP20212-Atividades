# import numpy as np
# ^ ainda não usada no codigo

lista_altura_M = [] * 4
# não entendi pq desse * 4, é pra delimitar o tamanho maximo da lista?
lista_altura_F = [] * 4
i = 0

while (i < 4):
    print("---------------")
    altura = float(input("Digite a altura do aluno: "))
    sexo = str(input("Qual o sexo do aluno? (M/F): "))

    if(sexo == 'M'):
        lista_altura_M.append(altura)
    else:
        lista_altura_F.append(altura)

    i += 1

print(lista_altura_M)
print(lista_altura_F)
