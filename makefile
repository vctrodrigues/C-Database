STD = -std=c99
# -std=c99: padrao C99 da linguagem C
# -ansi:    padrao C90 da linguagem C

OPTIONS = -Wall -Wpedantic -Wno-unused-result -O0 -g
# -O0: nao otimiza o codigo ao compilar
# -g:  prepara o terreno para que o gdb possa verificar bugs
itp : main.c BD.h BD.c view.h view.c
	gcc $(STD) $(OPTIONS) main.c BD.c view.c -o itp