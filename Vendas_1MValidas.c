#define _SVID_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "validaVendas.c"


int main (){

int strcount=0; int i; int j;

char **strarray;
strarray = val();

FILE *fp = NULL;
fp = fopen("Vendas_1MValidas.txt" ,"w");


for (i=0;strarray[i]!=NULL;i++){
fprintf(fp,"%s\n",strarray[i]);
printf("%s\n",strarray[i]);
}


for (j=0;strarray[j];j++) free(strarray[j]);
free(strarray);

fclose(fp);
}
