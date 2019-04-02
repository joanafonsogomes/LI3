CFLAGS = -g -ansi -pedantic -O2 -Wall
TARGET = myproj
CC = gcc


default:myproj

myproj: main.o Vendas.o validaProdutoseClientes.o lerficheiros.o estruturas.o CatProdutos.o CatClientes.o FactGlobal.o filial1.o filial2.o filial3.o
	$(CC) $(CFLAGS) -o myproj main.o  Vendas.o validaProdutoseClientes.o lerficheiros.o estruturas.o CatProdutos.o CatClientes.o FactGlobal.o filial1.o filial2.o filial3.o

main.o: main.c FactGlobal.h filial1.h filial2.h filial3.h validaProdutoseClientes.h
Vendas.o:Vendas.c Vendas.h estruturas.h lerficheiros.h validaProdutoseClientes.h
validaProdutoseClientes.o:validaProdutoseClientes.c validaProdutoseClientes.h lerficheiros.h
lerficheiros.o:lerficheiros.c lerficheiros.h
estruturas.o:estruturas.c estruturas.h
CatProdutos.o:CatProdutos.c CatProdutos.h estruturas.h validaProdutoseClientes.h
CatClientes.o:CatClientes.c CatClientes.h estruturas.h validaProdutoseClientes.h
FactGlobal.o:FactGlobal.c FactGlobal.h CatProdutos.h Vendas.h estruturas.h
filial1.o:filial1.c filial1.h estruturas.h Vendas.h
filial2.o:filial2.c filial2.h estruturas.h Vendas.h
filial3.o:filial3.c filial3.h estruturas.h Vendas.h

clean:
		$(RM) myproj *.o
