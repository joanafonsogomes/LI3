#define _SVID_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "filial3.h"
#include "estruturas.h"
#include "Vendas.h"
#include "CatProdutos.h"
#include "CatClientes.h"




char** produtosNAOvendidos_filial3(){
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
      if(filials[f]==3 && (binarySearch(produtoVendas,catprod[f],sizevendas))==-1){
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


int numero_produtosNAOvendidos_filial3(){
  int* filials; int s=0; int i;
  int sizevendas=numero_val();
  char** produtoVendas; int f=0;
  char** catprod;

  filials =filial1();
  produtoVendas = produto1();
  sort(produtoVendas,sizevendas);
  catprod = CatProdutos();

  for(f=0;catprod[f];f++){
      if(filials[f]==3 && (binarySearch(produtoVendas,catprod[f],sizevendas))==-1) s++;
  };
  free (filials);
  for(i=0;produtoVendas[i];i++)
  free (produtoVendas[i]);
  free (produtoVendas);
  for(i=0;catprod[i];i++)
  free (catprod[i]);
  free (catprod);
  return s;
}
