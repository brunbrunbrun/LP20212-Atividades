menu: modulo_principal opcao_1 opcao_3
	gcc modulo_principal.o opcao_1.o opcao_3.o -o menu

modulo_principal: modulo_principal.c
	gcc modulo_principal.c -c

opcao_1: opcao_1.c modulos.h
	gcc opcao_1.c -c

opcao_3: opcao_3.c modulos.h
	gcc opcao_3.c -c

clean:
	rm *.o
