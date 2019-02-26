#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXBUFFCLIENT 32
#define MAXBUFFPROD 64
#define MAXBUFFVENDAS 128


char** lerprodutos () {

FILE *fp;
char** strarray = NULL;
int i=0; int strcount=0;
char line[1024];
char* token;


//abrir ficheiro para ler
fp = fopen ("Produtos.txt", "r");
if (fp ==NULL) {
  perror ("Error opening file");
}

while (fgets(line,MAXBUFFPROD,fp)) {
  token = strtok(line,"\r\n");
  strarray = (char**) realloc (strarray,(strcount+1)*sizeof(char*));
  strarray[strcount++]=strdup(token);
}

fclose(fp);


return strarray;
}



char** lerclientes () {

FILE *fp;
char** strarray = NULL;
int i=0; int strcount=0;
char line [1024];
char* token;


//abrir ficheiro para ler
fp = fopen ("Clientes.txt", "r");
if (fp ==NULL) {
perror ("Error opening file");
}

while (fgets(line,MAXBUFFCLIENT,fp)) {
token = strtok(line,"\r\n");
strarray = (char**) realloc (strarray,(strcount+1)*sizeof(char*));
strarray[strcount++]=strdup(token);
}

fclose(fp);


  return strarray;
  }


char** lerVendas () {

FILE *fp;
char** strarray = NULL;
int i=0; int strcount=0;
char line [1024];
char* token;


//abrir ficheiro para ler
fp = fopen ("Vendas_1M.txt", "r");
if (fp ==NULL) {
  perror ("Error opening file");
}

while (fgets(line,MAXBUFFVENDAS,fp)) {
  token = strtok(line,"\r\n");
  strarray = (char**) realloc (strarray,(strcount+1)*sizeof(char*));
  strarray[strcount++]=strdup(token);
}

fclose(fp);


return strarray;
}
