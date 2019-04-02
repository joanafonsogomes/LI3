#define _SVID_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "estruturas.h"
#include "filial1.h"
#include "Vendas.h"
#include "CatProdutos.h"
#include "CatClientes.h"


char** produtosNAOvendidos_filial1(){
  int* filials; int i;
  int sizevendas=numero_val();
  char** produtosNvend =NULL;
  char** produtoVendas; int f=0; int s=0;
  char** catprod;

  filials =filial1();
  produtoVendas = produto1();
  sort(produtoVendas,sizevendas);
  catprod = CatProdutos();

  for(f=0;catprod[f];f++){
      if(filials[f]==1 && (binarySearch(produtoVendas,catprod[f],sizevendas))==-1){
      produtosNvend = (char**) realloc (produtosNvend,(s+1)*sizeof(char*));
      produtosNvend[s++]= strdup(catprod[f]);
    }
  }
  produtosNvend[s]='\0';
  free (filials);
  for(i=0;produtoVendas[i];i++)
  free (produtoVendas[i]);
  free (produtoVendas);
  for(i=0;catprod[i];i++)
  free (catprod[i]);
  free (catprod);
  return produtosNvend;
}


int numero_produtosNAOvendidos_filial1(){
  int* filials; int s=0; int i;
  int sizevendas=numero_val();
  char** produtoVendas; int f=0;
  char** catprod;

  filials =filial1();
  produtoVendas = produto1();
  sort(produtoVendas,sizevendas);
  catprod = CatProdutos();

  for(f=0;catprod[f];f++){
      if(filials[f]==1 && (binarySearch(produtoVendas,catprod[f],sizevendas))==-1) s++;
  }
  free (filials);
  for(i=0;produtoVendas[i];i++)
  free (produtoVendas[i]);
  free (produtoVendas);
  for(i=0;catprod[i];i++)
  free (catprod[i]);
  free (catprod);
  return s;
}

char** clientes_nao_compraram_filial1(){
  int* filials; int i;
  int sizevendas=numero_val();
  char** clienteVendas; int f=0; int s=0;
  char** catcliente;
  char** clientesNaocomp =NULL;

  filials =filial1();
  clienteVendas = cliente1();
  sort(clienteVendas,sizevendas);
  catcliente = CatClientes();


  for(f=0;catcliente[f];f++){
      printf("%s\n",catcliente[f]);
      if(filials[f]==1 && (binarySearch(clienteVendas,catcliente[f],sizevendas)==-1)) {
      clientesNaocomp = (char**) realloc (clientesNaocomp,(s+1)*sizeof(char*));
      clientesNaocomp[s++]= strdup(catcliente[f]);
    }
  }
  clientesNaocomp[s]='\0';
  free (filials);
  for(i=0;clienteVendas[i];i++)
  free (clienteVendas[i]);
  free (clienteVendas);
  for(i=0;catcliente[i];i++)
  free (catcliente[i]);
  free (catcliente);
  return clientesNaocomp;

}
