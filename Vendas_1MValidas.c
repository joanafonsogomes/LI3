#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "lerficheiros.c"



void criaFILE_vendas_val() {

char** strarray = NULL;
//ainda está o ficheiro de ler todas as vendas e não apenas
//as válidas porque falta a valida
strarray = lerVendas();

FILE *fp = NULL;
fp = fopen("Vendas_1MValidas.txt" ,"w");


//imprimir o array de strings
for (int i=0;strarray[i];i++)
fprintf(fp,"%s\n",strarray[i]);


//libertar o array de strings
//primeiro libertar o array de cada strings

for (int i=0;strarray[i];i++) free(strarray[i]);
free(strarray);


}
