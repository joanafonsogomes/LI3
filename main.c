#define _SVID_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include "FactGlobal.h"


int main (){
  clock_t start, end;
  double cpu_time_used;
  start = clock();
  float s;
  s =totalFaturado_Intervalo (1, 12);
  printf("%f\n",s);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("CPU Time:%f\n", cpu_time_used );
  return 0;
}
