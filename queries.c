#define _SVID_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "queries.h"
#include "FactGlobal.h"
#include "CatProdutos.h"
#include "filial1.h"
#include "filial2.h"
#include "filial3.h"
#include "Vendas.h"
#include "estruturas.h"


/*querie 2
Determinar a lista e Apresentar tal lista ao utilizador e permitir que o mesmo
navegue na mesma, página a página, sendo tal lista apresentada por ordem
alfabética; */
char** querie2_lista;
querie2_lista= listainicLetra(char a);
/* DETERMINE o nº total de produtos cujo código se inicia por uma dada
letra (maiúscula); */
int querie2;
querie2= listainicLetraNumero_Produtos (char a);

/*querie 8
Dado um intervalo fechado de meses, por exemplo [1..3], determinar o total de
vendas (nº de registos de venda) registadas nesse intervalo*/
int querie8;
querie8 = numero_Vendas_Intervalo (int a, int b);
/*Dado um intervalo fechado de meses, por exemplo [1..3], determinar o total facturado;/*
float querie_8;
querie_8 = totalFaturado_Intervalo (int a, int b);

/*querie4*/
/*total
char **produtototalNaovendido;
produtototalNaovendido =produtosNAOvendidos();
int produtotal;*/
produtotal =numero_produtosNAOvendidos ();
/*filial1:*/
char** Nao_vendidos1;
Nao_vendidos1= produtosNAOvendidos_filial1();
int numero_Nao_vendidos1;
numero_Nao_vendidos1=numero_produtosNAOvendidos_filial1();
/*filial2:*/
char** Nao_vendidos2;
Nao_vendidos2= produtosNAOvendidos_filial2();
int numero_Nao_vendidos2;
numero_Nao_vendidos2=numero_produtosNAOvendidos_filial2();
/*filial3:*/
char** Nao_vendidos3;
Nao_vendidos2= produtosNAOvendidos_filial3();
int numero_Nao_vendidos3;
numero_Nao_vendidos3=numero_produtosNAOvendidos_filial3();

/*querie5-ainda nao esta acabada*/
char** clientes=NULL;
char** nao_compradores1=clientes_nao_compraram_filial1();
char** nao_compradores2=clientes_nao_compraram_filial2();
char** nao_compradores3=clientes_nao_compraram_filial3();
int i=0; int s=0;
int sizevendas=numero_val();
char** clienteVendas= cliente1();
sort(clienteVendas,sizevendas);
for(i=0;clienteVendas[i];i++){
  if (binarySearch(nao_compradores1,clienteVendas[i],sizevendas) ==-1 && binarySearch(nao_compradores2,clienteVendas[i],sizevendas) ==-1 && binarySearch(nao_compradores2,clienteVendas[i],sizevendas) ==-1) {
    clientes = (char**) realloc (clientes,(s+1)*sizeof(char*));
    clientes[s++]= strdup(clienteVendas[i]);
  }
  clientes[s]="\0";
}
