#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "lerficheiros.c"


int main () {

char** strarray = NULL;
strarray = lerVendas();

//imprimir o array de strings
for (int i=0;strarray[i];i++)
printf("strarray[%d]==%s\n",i,strarray[i]);



//libertar o array de strings
//primeiro libertar o array de cada strings

for (int i=0;strarray[i];i++) free(strarray[i]);
free(strarray);

return 0;
}
