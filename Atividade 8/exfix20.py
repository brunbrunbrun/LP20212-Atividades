# import numpy as np
# ^ sem uso ainda

lista_altura_M = [] * 4
lista_altura_F = [] * 4
i = 0

while (i < 4):
    print("---------------")
    altura = float(input("Digite a altura do aluno: "))
    sexo = str(input("Qual o sexo do aluno? (M/F): "))

    if(sexo == 'M'):
        lista_altura_M = [altura]
    else:
        lista_altura_F = [altura]

    i += 1

print(lista_altura_M)
print(lista_altura_F)
