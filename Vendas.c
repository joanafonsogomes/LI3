#define _SVID_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "Vendas.h"
#include "lerficheiros.h"
#include "estruturas.h"
#include "validaProdutoseClientes.h"

#define SIZECLIEN 16384
#define SIZEPROD 171008

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

  int strcount=0;
  int i;   int j;
  char **clientes;
  char **produtos;
  char** starray;
  char** valVENDAS=NULL;

  clientes =validaClientes();
  sort(clientes,SIZECLIEN);

  produtos =validaProdutos();
  sort(produtos,SIZEPROD);

  starray = lerVendas();

  for(j=0;starray[j]!=NULL;j++){
  Venda a = (Venda) malloc (sizeof( struct venda));
  char* linha= strdup (starray[j]);
  a = criaVenda (linha);


  if (binarySearch(clientes,(a->cliente),SIZECLIEN)==-1) continue;


  if (binarySearch(produtos,(a->produto),SIZEPROD)==-1) continue;



  if ( ((a->promonorm)!='P' && (a->promonorm)!='N') || ((a->filial)>3) || ((a->filial)<1)||
  ((a->quant)>200) || ((a->quant)<0) || ((a->mes)>12) || ((a->mes)<1) || ((a->preco)<0.00) || ((a->preco)>999.99)) continue;

  valVENDAS = (char**) realloc (valVENDAS,(strcount+1)*sizeof(char*));
  valVENDAS[strcount++]= strdup (starray[j]);

} valVENDAS[strcount]='\0';
for(i=0;starray[i];i++)
free(starray[i]);
free (starray);
for(i=0;produtos[i];i++)
free(produtos[i]);
free (produtos);
for(i=0;clientes[i];i++)
free(clientes[i]);
free (clientes);
  return valVENDAS;
}

int numero_val(){
  int i; int p=0; int j;
  char **clientes;
  char **produtos;
  char** starray;

  clientes =validaClientes();
  sort(clientes,SIZECLIEN);

  produtos =validaProdutos();
  sort(produtos,SIZEPROD);

  starray = lerVendas();

  for(j=0;starray[j]!=NULL;j++){
  Venda a = (Venda) malloc (sizeof( struct venda));
  char* linha= strdup (starray[j]);
  a = criaVenda (linha);


  if (binarySearch(clientes,(a->cliente),SIZECLIEN)==-1) continue;


  if (binarySearch(produtos,(a->produto),SIZEPROD)==-1) continue;



  if ( ((a->promonorm)!='P' && (a->promonorm)!='N') || ((a->filial)>3) || ((a->filial)<1)||
  ((a->quant)>200) || ((a->quant)<0) || ((a->mes)>12) || ((a->mes)<1) || ((a->preco)<0.00) || ((a->preco)>999.99)) continue;

  p++;

}
for(i=0;starray[i];i++)
free(starray[i]);
free (starray);
for(i=0;produtos[i];i++)
free(produtos[i]);
free (produtos);
for(i=0;clientes[i];i++)
free(clientes[i]);
free (clientes);

  return p;
}


Venda criaVenda (char* linha) {
int j;
Venda v = (Venda) malloc (sizeof(struct venda));

char* token = strtok(linha," ");
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

char** cliente1() {
int f; int i;
char** vendas;
char** clientes=NULL;

vendas =val();

for(f=0;vendas[f];f++){

Venda a = (Venda) malloc (sizeof(Venda));
a = criaVenda (vendas[f]);

clientes = (char**) realloc (clientes,(f+1)*sizeof(char*));
clientes[f]=strdup(a->cliente);
}
clientes[f]='\0';
for(i=0;vendas[i];i++)
free(vendas[i]);
free(vendas);
return clientes;
}

char** produto1() {
int f; int i;
char** vendas;
char** produtos=NULL;

vendas =val();

for(f=0;vendas[f];f++){

Venda a = (Venda) malloc (sizeof(Venda));
a = criaVenda (vendas[f]);

produtos = (char**) realloc (produtos,(f+1)*sizeof(char*));
produtos[f]=strdup(a->produto);
}
produtos[f]='\0';
for(i=0;vendas[i];i++)
free(vendas[i]);
free (vendas);
return produtos;
}


float* preco1() {
int f; int i;
char** vendas;
float* precos=NULL;

vendas =val();

for(f=0;vendas[f];f++){

Venda a = (Venda) malloc (sizeof(Venda));
a = criaVenda (vendas[f]);

precos = (float*) realloc (precos,(f+1)*sizeof(float));
precos[f]=(a->preco);
}
precos[f]='\0';
for(i=0;vendas[i];i++)
free(vendas[i]);
free (vendas);
return precos;
}


int* quant1() {
int f; int i;
char** vendas;
int* quants=NULL;

vendas =val();

for(f=0;vendas[f];f++){

Venda a = (Venda) malloc (sizeof(Venda));
a = criaVenda (vendas[f]);

quants = (int*) realloc (quants,(f+1)*sizeof(int));
quants[f]=(a->quant);
}
quants[f]='\0';
for(i=0;vendas[i];i++)
free(vendas[i]);
free (vendas);
return quants;
}


char* promonorm1() {
int f; int i;
char** vendas;
char* promonorms=NULL;

vendas =val();

for(f=0;vendas[f];f++){

Venda a = (Venda) malloc (sizeof(Venda));
a = criaVenda (vendas[f]);

promonorms = (char*) realloc (promonorms,(f+1)*sizeof(char));
promonorms[f]=a->promonorm;
}
promonorms[f]='\0';
for(i=0;vendas[i];i++)
free(vendas[i]);
free (vendas);
return promonorms;
}

int* mes1() {
int f; int i;
char** vendas;
int* meses=NULL;

vendas =val();

for(f=0;vendas[f];f++){

Venda a = (Venda) malloc (sizeof(Venda));
a = criaVenda (vendas[f]);

meses = (int*) realloc (meses,(f+1)*sizeof(int));
meses[f]=(a->mes);
}
meses[f]='\0';
for(i=0;vendas[i];i++)
free(vendas[i]);
free (vendas);
return meses;
}


int* filial1() {
int f; int i;
char** vendas;
int* filials=NULL;

vendas =val();

for(f=0;vendas[f];f++){

Venda a = (Venda) malloc (sizeof(Venda));
a = criaVenda (vendas[f]);

filials= (int*) realloc (filials,(f+1)*sizeof(int));
filials[f]=(a->filial);
}
filials[f]='\0';
for(i=0;vendas[i];i++)
free(vendas[i]);
free (vendas);
return filials;
}



void Vendas_1MValidas (){

int i; int j;
FILE *fp = NULL;

char **strarray;
strarray = val();


fp = fopen("Vendas_1MValidas.txt" ,"w");


for (i=0;strarray[i]!=NULL;i++){
fprintf(fp,"%s\n",strarray[i]);
}


for (j=0;strarray[j];j++) free(strarray[j]);
free(strarray);

fclose(fp);
}
