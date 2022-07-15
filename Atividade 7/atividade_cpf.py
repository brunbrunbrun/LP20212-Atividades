import numpy as np

# recebe os 9 digitos iniciais
cpf_9 = str(input("Digite os 9 primeiros digitos do CPF: "))

# recebe os 2 digitos finais de controle
cpf_controle = str(input("Digite os (2) digitos de controle: "))

# separa os numeros do cpf_9 em uma lista
lista_cpf = [int(d) for d in str(cpf_9)]

# cria uma nova_lista e preenche com 0
nova_lista = np.zeros(9)
multiplicado = 0
digitu_1 = 0


# -----------------------------
# -----geração do 1 digito-----

# multiplicacao de cada digito
for i in range(9):
    nova_lista[i] = lista_cpf[i] * (10 - i)
    multiplicado += nova_lista[i]

# modulo 11 para obter o resto
restu = multiplicado % 11

# decide qual vai ser o primeiro digito baseado no resto obtido
if (restu >= 2):
    digitu_1 = 11 - restu
elif ((restu == 1) or (restu == 0)):
    digitu_1 = 0

# adiciona o primeiro digito de controle na lista_cpf
# adiciona esse digito para uma variavel propria para o digito de controle
lista_cpf.append(int(digitu_1))
digitos_controle = str(int(digitu_1))


# -----------------------------
# -----geração do 2 digito-----

# mesmo procedimento com adesão do primeiro digito de controle

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

# adiciona o segundo digito de controle na lista_cpf
lista_cpf.append(int(digitu_2))
digitos_controle += str(int(digitu_2))


# olha se o digitos_controle informado é valido, comparando com o obtido
