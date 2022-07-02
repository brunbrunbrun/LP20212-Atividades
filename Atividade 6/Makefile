menu: modulo_principal.o opcao_1.o opcao_2.o opcao_3.o
	gcc modulo_principal.o opcao_1.o opcao_2.o opcao_3.o -o menu

modulo_principal.o: modulo_principal.c
	gcc modulo_principal.c -c

opcao_1.o: opcao_1.c modulos.h
	gcc opcao_1.c -c

opcao_2.o: opcao_2.c modulos.h
	gcc opcao_2.c -c

opcao_3.o: opcao_3.c modulos.h
	gcc opcao_3.c -c

clean:
	rm *.o
