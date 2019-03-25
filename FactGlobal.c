#define _SVID_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "estruturas.h"
#include "FactGlobal.h"
#include "Vendas.h"
#include "CatProdutos.h"


int numero_total_deVendas (int a, char*b){
  char** produto; int f;
  int* mes; int p=0;
  produto=produto1();
  mes=mes1();
  for(f=0; mes[f];f++){
  if(mes[f]==a && (strcmp(produto[f],b)==0)) p++;
}
return p;
  }


char** produtosNAOvendidos(){
  int sizevendas=numero_val();
  char** produtosNvend =NULL;
  char** produtoVendas; int f=0; int s=0;
  produtoVendas = produto1();
  sort(produtoVendas,sizevendas);
  char** catprod;
  catprod = CatProdutos();
  for(f=0;catprod[f];f++){
      if((binarySearch(produtoVendas,catprod[f],sizevendas))==-1){
      produtosNvend = (char**) realloc (produtosNvend,(s+1)*sizeof(char*));
      produtosNvend[s++]= strdup(catprod[f]);
    }
  }
  produtosNvend[s]='\0';
  return produtosNvend;
}


int numero_produtosNAOvendidos (){
  int sizevendas=numero_val();
  char** produtoVendas; int f=0; int s=0;
  produtoVendas = produto1();
  sort(produtoVendas,sizevendas);
  char** catprod;
  catprod = CatProdutos();
  for(f=0;catprod[f];f++){
      if((binarySearch(produtoVendas,catprod[f],sizevendas))==-1) s++;
  }
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
  return temp;
}


float totalFaturado_Intervalo (int a, int b){
  int f;
  float w=0;
  float* preco;
  preco=preco1();
  int* quant;
  quant =quant1();
  int *mes;
  mes =mes1();
  for(f=0;mes[f];f++) {
    if(mes[f]>=a && mes[f]<=b) w = w + preco[f] * quant[f];
  }
  return w;
}
