#define _SVID_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "lerficheiros.h"


#define MAXBUFFCLIENT 32
#define MAXBUFFPROD 64
#define MAXBUFFVENDAS 128


char** lerprodutos () {

FILE *fp;
char** strarray = NULL;
int strcount=0;
char line[MAXBUFFPROD];
char* token;



fp = fopen ("Produtos.txt", "r");
if (fp ==NULL) {
  perror ("Error opening file");
}

while (fgets(line,MAXBUFFPROD,fp)) {
  token = strtok(line,"\r\n");
  strarray = (char**) realloc (strarray,(strcount+1)*sizeof(char*));
  strarray[strcount++]=strdup(token);
}
strarray[strcount]='\0';
fclose(fp);


return strarray;
}



char** lerclientes () {

FILE *fp;
char** strarray = NULL;
int strcount=0;
char line [MAXBUFFCLIENT];
char* token;



fp = fopen ("Clientes.txt", "r");
if (fp ==NULL) {
perror ("Error opening file");
}

while (fgets(line,MAXBUFFCLIENT,fp)) {
token = strtok(line,"\r\n");
strarray = (char**) realloc (strarray,(strcount+1)*sizeof(char*));
strarray[strcount++]=strdup(token);
}
strarray[strcount]='\0';
fclose(fp);


  return strarray;
  }


char** lerVendas () {

FILE *fp;
char** strarray = NULL;
int strcount=0;
char line [MAXBUFFVENDAS];
char* token;



fp = fopen ("Vendas_1M.txt", "r");
if (fp ==NULL) {
  perror ("Error opening file");
}

while (fgets(line,MAXBUFFVENDAS,fp)) {
  token = strtok(line,"\r\n");
  strarray = (char**) realloc (strarray,(strcount+1)*sizeof(char*));
  strarray[strcount++]=strdup(token);
}
strarray[strcount]='\0';
fclose(fp);


return strarray;
}
