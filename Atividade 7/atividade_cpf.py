import numpy as np

cpf_9 = str(input("Digite os 9 primeiros digitos do CPF:"))

lista_cpf = [int(d) for d in str(cpf_9)]
nova_lista = np.zeros(9)


multiplicado = 0
digitu_1 = 0

for i in range(9):
    nova_lista[i] = lista_cpf[i] * (10 - i)
    multiplicado += nova_lista[i]

restu = multiplicado % 11

print(nova_lista)
print(multiplicado)
print(restu)

if (restu >= 2):
    digitu_1 = 11 - restu
elif ((restu == 1) or (restu == 0)):
    digitu_1 = 0

print(digitu_1)

lista_cpf.append(int(digitu_1))
print(lista_cpf)

# digito 2

digitu_2 = 0
multiplicado_2 = 0
nova_nova_lista = np.zeros(10)

for i in range(10):
    nova_nova_lista[i] = lista_cpf[i] * (11 - i)
    multiplicado_2 += nova_nova_lista[i]

restu_2 = multiplicado_2 % 11

if (restu_2 >= 2):
    digitu_2 = 11 - restu_2
else:
    digitu_2 = 0

lista_cpf.append(int(digitu_2))
print(lista_cpf)

listona_cpf = ''

for i in range(11):
    listona_cpf += str(lista_cpf[i])

print(listona_cpf)
