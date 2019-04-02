#define _SVID_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include "estruturas.h"
#include "FactGlobal.h"
#include "filial1.h"
#include "filial2.h"
#include "filial3.h"
#include "validaProdutoseClientes.h"
#include "Vendas.h"


  int main (){
  int i;
  char** nao_vendidos1;
  char** nao_vendidos2;
  char** nao_vendidos3;

  clock_t start, end;
  double cpu_time_used;
  start = clock();

  nao_vendidos1=numero_produtosNAOvendidos_filial1();
  nao_vendidos2=numero_produtosNAOvendidos_filial2();
  nao_vendidos3=numero_produtosNAOvendidos_filial3();
  for(i=0;nao_vendidos1[i];i++)
  printf("%s\n",nao_vendidos1[i] );
  for(i=0;nao_vendidos2[i];i++)
  printf("%s\n",nao_vendidos2[i] );
  for(i=0;nao_vendidos3[i];i++)
  printf("%s\n",nao_vendidos3[i] );



  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("CPU Time:%f\n", cpu_time_used );
  return 0;
}
