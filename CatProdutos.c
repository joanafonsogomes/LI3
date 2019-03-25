#define _SVID_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "CatProdutos.h"
#include "lerficheiros.h"
#include "estruturas.h"


#define SIZEPROD 171008


char** CatProdutos() {
  char **strarray; int i; int p=0;
  strarray = lerprodutos();
  for(i=0;strarray[i];i++) p++;
  sort(strarray,p);
return strarray;
}

int CatProdutos_Numero() {
  char **strarray;
  int p=0; int i;
  strarray = lerprodutos ();
  for (i=0;strarray[i];i++)
  p++;
return p;
}


char** listainicLetra(char a){
  char **strarray;
  strarray = CatProdutos();

  char** array =NULL;
  int i=0; int strcount=0;

  for(i=0;strarray[i];i++) {
    if (strarray[i][0]<a) continue;
    if (strarray[i][0]==a){
    array= (char**) realloc (array,(strcount+1)*sizeof(char*));
    array [strcount++]=strdup (strarray[i]);
    }
    else break;
  }
  array [strcount] ='\0';
  return array;
}

int listainicLetraNumero_Produtos(char a){
  char **strarray;
  strarray = CatProdutos ();
  int i; int p=0;;
  for(i=0;strarray[i];i++) {
    if (strarray[i][0]<a) continue;
    if (strarray[i][0]==a)
    p++;
    else break;
  }
  return p;
}
