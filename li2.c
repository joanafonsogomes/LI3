#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main () {

FILE *fp;
char** strarray = NULL;
int i=0; int strcount=0;
char line[1024];
int r=0; int j=0;

//abrir ficheiro para ler
fp = fopen ("Produtos.txt", "r");
if (fp ==NULL) {
  perror ("Error opening file");
  return (-1);
}

while (fgets(line,1024,fp)) {
  strarray = (char**) realloc (strarray,(strcount+1)*sizeof(char*));
  strarray[strcount++]=strdup(line);
}




//imprimir o array de strings
for (i=0;i<strcount;i++)
printf("strarray[%d]==%s",i,strarray[i]);




//libertar o array de strings
//primeiro libertar o array de cada strings

for (i=0;i<strcount;i++) free(strarray[i]);
free(strarray);

return 0;
}
