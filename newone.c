#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <string.h>
#include <math.h>
#include <time.h>
#include "lerficheiros.c"


//função que converte uma string (char *) num char
char trim(char *s) {
  char l; int i;
  for (i=0;s[i]!=0;i++)
  if (s[i]!=0) return s[i];
}

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

int val () {

  char **clientes;
  clientes = (char**) malloc (1*sizeof(char*));
  clientes =lerclientes();

  char **produtos;
  produtos = (char**) malloc (1*sizeof(char*));
  produtos =lerprodutos();

  char **starray;
  starray =  (char**) malloc (1*sizeof(char*));
  starray = lerVendas();


  int j; int p=0;
  for(j=0;starray[j]!=NULL;j++){

  Venda a = (Venda) malloc (sizeof( struct venda));
  char* linhas= strdup (starray[j]);
  a = criaVenda (linhas);

  int r=0;

  while (((clientes[r]!=NULL) && (strcmp(clientes[r],(a->cliente))!=0))) r++;

  if( clientes[r]==NULL) continue;

  int d=0;
  while  ((produtos[d]!=NULL) &&(strcmp(produtos[d],(a->produto))!=0) ) d++;

  if (produtos[d]==NULL) continue;


  if ( ((a->promonorm)!='P' && (a->promonorm)!='N') || ((a->filial)>3) || ((a->filial)<1)||
 ((a->quant)>200) || ((a->quant)<0) || ((a->mes)>12) || ((a->mes)<1) || ((a->preco)<0.00) || ((a->preco)>999.99)) continue;

  p++;
  printf("venda válida:%i\n",j);

}
  //printf("%i\n",p );
  return p;
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


//copia e aloca memória
v->cliente =strdup(tokens[4]);
v->produto =strdup (tokens[0]);
v->promonorm =trim(tokens[3]);
//converte para inteiro
v->filial =atoi(tokens[6]);
//converte para inteiro
v->mes =atoi(tokens[5]);
v->quant =atoi(tokens[2]);
//converte para float
v->preco =atof(tokens[1]);
return v;

}

// ler CPU Time
int main(int argc,  const char* argv[]) {
  clock_t start, end;
  int p;
  double cpu_time_used;
  start = clock();
  p=val();
  printf("%i\n",p );
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("CPU Time:%f\n", cpu_time_used );
  return 0;
}
