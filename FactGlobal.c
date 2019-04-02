#define _SVID_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "estruturas.h"
#include "FactGlobal.h"
#include "Vendas.h"
#include "CatProdutos.h"


int numero_total_deVendas (int a, char*b){
  char** produto; int f; int i;
  int* mes; int p=0;
  produto=produto1();
  mes=mes1();
  for(f=0; mes[f];f++){
  if(mes[f]==a && (strcmp(produto[f],b)==0)) p++;
}
for(i=0;produto[i];i++)
free(produto[i]);
free (produto);
free (mes);
return p;
  }


float numero_totalfaturado (int a, char*b) {
  char** produto; int f; int i;
  int* mes; float w=0;
  float* preco;   int* quant;

  produto=produto1();
  mes=mes1();
  preco=preco1();
  quant =quant1();

  for(f=0; mes[f];f++){
    if(mes[f]==a && (strcmp(produto[f],b)==0)) w = w + preco[f] * quant[f];
}
for(i=0;produto[i];i++)
free(produto[i]);
free (produto);
free (mes);
free (quant);
return w;
}


char** produtosNAOvendidos(){
  int sizevendas;
  int i;
  char** produtosNvend =NULL;
  char** produtoVendas; int f=0; int s=0;
  char** catprod;

  sizevendas=numero_val();
  produtoVendas = produto1();
  sort(produtoVendas,sizevendas);
  catprod = CatProdutos();

  for(f=0;catprod[f];f++){
      if((binarySearch(produtoVendas,catprod[f],sizevendas))==-1){
      produtosNvend = (char**) realloc (produtosNvend,(s+1)*sizeof(char*));
      produtosNvend[s++]= strdup(catprod[f]);
    }
  }
  produtosNvend[s]='\0';
  for(i=0;produtoVendas[i];i++)
  free(produtoVendas[i]);
  free (produtoVendas);
  for(i=0;catprod[i];i++)
  free(catprod[i]);
  free (catprod);
  return produtosNvend;
}


int numero_produtosNAOvendidos (){
  int sizevendas=numero_val(); int i;
  char** produtoVendas; int f=0; int s=0;
  char** catprod;

  produtoVendas = produto1();
  sort(produtoVendas,sizevendas);
  catprod = CatProdutos();

  for(f=0;catprod[f];f++){
      if((binarySearch(produtoVendas,catprod[f],sizevendas))==-1) s++;
  }
  for(i=0;produtoVendas[i];i++)
  free(produtoVendas[i]);
  free (produtoVendas);
  for(i=0;catprod[i];i++)
  free(catprod[i]);
  free (catprod);
  return s;
}


int numero_Vendas_Intervalo (int a, int b){
  int f;
  int temp=0;
  int* mes;
  mes=mes1();
  for(f=0;mes[f];f++) {
  if(mes[f]>=a && mes[f]<=b) temp++;
  }
  free (mes);
  return temp;
}


float totalFaturado_Intervalo (int a, int b){
  int f;
  float w=0;
  float* preco;
  int* quant;
  int *mes;

  preco=preco1();
  quant =quant1();
  mes =mes1();
  for(f=0;mes[f];f++) {
    if(mes[f]>=a && mes[f]<=b) w += preco[f] * quant[f];
  }
  free (preco);
  free (quant);
  free (mes);
  return w;
}
