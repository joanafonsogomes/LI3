CFLAGS = -g -ansi -O2 -Wall
TARGET = myproj
CC = gcc


default:myproj

myproj: main.o Vendas.o validaProdutoseClientes.o lerficheiros.o estruturas.o CatProdutos.o CatClientes.o FactGlobal.o
	$(CC) $(CFLAGS) -o myproj main.o  Vendas.o validaProdutoseClientes.o lerficheiros.o estruturas.o CatProdutos.o CatClientes.o FactGlobal.o

main.o: main.c FactGlobal.h
Vendas.o:Vendas.c Vendas.h estruturas.h lerficheiros.h validaProdutoseClientes.h
validaProdutoseClientes.o:validaProdutoseClientes.c validaProdutoseClientes.h lerficheiros.h
lerficheiros.o:lerficheiros.c lerficheiros.h
estruturas.o:estruturas.c estruturas.h
CatProdutos.o:CatProdutos.c CatProdutos.h estruturas.h validaProdutoseClientes.h
CatClientes.o:CatClientes.c CatClientes.h estruturas.h validaProdutoseClientes.h
FactGlobal.o:FactGlobal.c FactGlobal.h CatProdutos.h Vendas.h estruturas.h



clean:
		$(RM) myproj *.o
