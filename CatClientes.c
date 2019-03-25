#define _SVID_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "CatClientes.h"
#include "lerficheiros.h"
#include "estruturas.h"


char** CatClientes() {
  char **strarray; int i; int p=0;
  strarray = lerclientes ();
  for(i=0;strarray[i];i++) p++;
  sort(strarray,p);
return strarray;
}

int CatClientes_Numero() {
  char **strarray;
  int p=0; int i;
  strarray = lerclientes ();
  for (i=0;strarray[i];i++)
  p++;
return p;
}
