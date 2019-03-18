#define _SVID_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "lerficheiros.c"


struct venda {
  char* produto;
  float preco;
  int quant;
  char promonorm;
  char *cliente;
  int mes;
  int filial;
};

typedef struct venda* Venda;
Venda criaVenda (char* linha);

char** val () {

  int strcount=0;

  char **clientes;
  clientes =lerclientes();

  char **produtos;
  produtos =lerprodutos();

  char** starray;
  starray = lerVendas();

  char** valVENDAS=NULL;

  int j; int r; int d;

  for(j=0;starray[j]!=NULL;j++){
  r=0; d=0;
  Venda a = (Venda) malloc (sizeof( struct venda));
  char* linha= strdup (starray[j]);
  a = criaVenda (linha);


  while ((   (clientes[r]!=NULL) && (strcmp(clientes[r],(a->cliente))!=0)  ) ) r++;

  if( clientes[r]==NULL) continue;


  while  ((produtos[d]!=NULL) &&(strcmp(produtos[d],(a->produto))!=0) ) d++;

  if (produtos[d]==NULL) continue;


  if ( ((a->promonorm)!='P' && (a->promonorm)!='N') || ((a->filial)>3) || ((a->filial)<1)||
  ((a->quant)>200) || ((a->quant)<0) || ((a->mes)>12) || ((a->mes)<1) || ((a->preco)<0.00) || ((a->preco)>999.99)) continue;

  valVENDAS = (char**) realloc (valVENDAS,(strcount+1)*sizeof(char*));
  valVENDAS[strcount++]= strdup (starray[j]);
  
}
  return valVENDAS;
}



Venda criaVenda (char* linha) {

Venda v = (Venda) malloc (sizeof(struct venda));

char* token = strtok(linha," ");
int j;
char **tokens =(char**) malloc (7*sizeof(char*));

for (j=0; token !=NULL ;j++) {
tokens[j]=strdup(token);
token = strtok(NULL," ");
};



v->cliente =strdup(tokens[4]);
v->produto =strdup (tokens[0]);
v->promonorm =(tokens[3][0]);
v->filial =atoi(tokens[6]);
v->mes =atoi(tokens[5]);
v->quant =atoi(tokens[2]);
v->preco =atof(tokens[1]);
return v;

}
