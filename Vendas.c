#define _SVID_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "validaVendas.h"
#include "lerficheiros.h"
#include "estruturas.h"
#include "validaProdutoseClientes.h"


struct venda {
  char* produto;
  float preco;
  int quant;
  char promonorm;
  char *cliente;
  int mes;
  int filial;
};


Venda criaVenda (char* linha);

char** val () {
  int sizecliente= numero_client ();
  int sizeprod=numero_prod ();
  int strcount=0;

  char **clientes;
  clientes =validaClientes();
  sort(clientes,sizecliente);

  char **produtos;
  produtos =validaProdutos();
  sort(produtos,sizeprod);

  char** starray;
  starray = lerVendas();

  char** valVENDAS=NULL;

  int j;

  for(j=0;starray[j]!=NULL;j++){
  Venda a = (Venda) malloc (sizeof( struct venda));
  char* linha= strdup (starray[j]);
  a = criaVenda (linha);


  if (binarySearch(clientes,(a->cliente),sizecliente)==-1) continue;


  if (binarySearch(produtos,(a->produto),sizeprod)==-1) continue;



  if ( ((a->promonorm)!='P' && (a->promonorm)!='N') || ((a->filial)>3) || ((a->filial)<1)||
  ((a->quant)>200) || ((a->quant)<0) || ((a->mes)>12) || ((a->mes)<1) || ((a->preco)<0.00) || ((a->preco)>999.99)) continue;

  valVENDAS = (char**) realloc (valVENDAS,(strcount+1)*sizeof(char*));
  valVENDAS[strcount++]= strdup (starray[j]);

} valVENDAS[strcount]='\0';
  return valVENDAS;
}

int numero_val () {
int i; int p=0;
char** ven;
ven= val();
for (i=0;ven[i];i++) p++;
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



v->cliente =strdup(tokens[4]);
v->produto =strdup (tokens[0]);
v->promonorm =(tokens[3][0]);
v->filial =atoi(tokens[6]);
v->mes =atoi(tokens[5]);
v->quant =atoi(tokens[2]);
v->preco =atof(tokens[1]);
return v;

}


char** produto1() {
int f;
char** vendas;
vendas =val();

char** produtos=NULL;

for(f=0;vendas[f];f++){

Venda a = (Venda) malloc (sizeof(Venda));
a = criaVenda (vendas[f]);

produtos = (char**) realloc (produtos,(f+1)*sizeof(char*));
produtos[f]=strdup(a->produto);
}
produtos[f]='\0';
return produtos;
}


float* preco1() {
int f;
char** vendas;
vendas =val();

float* precos=NULL;

for(f=0;vendas[f];f++){

Venda a = (Venda) malloc (sizeof(Venda));
a = criaVenda (vendas[f]);

precos = (float*) realloc (precos,(f+1)*sizeof(float));
precos[f]=(a->preco);
}
precos[f]='\0';
return precos;
}


int* quant1() {
int f;
char** vendas;
vendas =val();

int* quants=NULL;

for(f=0;vendas[f];f++){

Venda a = (Venda) malloc (sizeof(Venda));
a = criaVenda (vendas[f]);

quants = (int*) realloc (quants,(f+1)*sizeof(int));
quants[f]=(a->quant);
}
quants[f]='\0';
return quants;
}


char* promonorm1() {
int f;
char** vendas;
vendas =val();

char* promonorms=NULL;

for(f=0;vendas[f];f++){

Venda a = (Venda) malloc (sizeof(Venda));
a = criaVenda (vendas[f]);

promonorms = (char*) realloc (promonorms,(f+1)*sizeof(char));
promonorms[f]=a->promonorm;
}
promonorms[f]='\0';
return promonorms;
}

int* mes1() {
int f;
char** vendas;
vendas =val();

int* meses=NULL;

for(f=0;vendas[f];f++){

Venda a = (Venda) malloc (sizeof(Venda));
a = criaVenda (vendas[f]);

meses = (int*) realloc (meses,(f+1)*sizeof(int));
meses[f]=(a->mes);
}
meses[f]='\0';
return meses;
}


int* filial1() {
int f;
char** vendas;
vendas =val();

int* filials=NULL;

for(f=0;vendas[f];f++){

Venda a = (Venda) malloc (sizeof(Venda));
a = criaVenda (vendas[f]);

filials= (int*) realloc (filials,(f+1)*sizeof(int));
filials[f]=(a->filial);
}
filials[f]='\0';
return filials;
}


void Vendas_1MValidas (){

int i; int j;

char **strarray;
strarray = val();

FILE *fp = NULL;
fp = fopen("Vendas_1MValidas.txt" ,"w");


for (i=0;strarray[i]!=NULL;i++){
fprintf(fp,"%s\n",strarray[i]);
}


for (j=0;strarray[j];j++) free(strarray[j]);
free(strarray);

fclose(fp);
}
