#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include </home/joana/Desktop/LI3/parsing.c>

int main () {

FILE *fp;
char** strarray = NULL;
int i=0; //int strcount=0;
char line[10000];
int r=0; int j=0;
int validacao=0;

//abrir ficheiro para ler
strarray = lerprodutos();

for (i=0;strarray[i];i++){
int innerValidacao = 0;
	printf("strarray[%d]==%s",i,strarray[i]);

	char myChar = *strarray[i];
//VALIDACAO DAS PRIMEIRAS DUAS MAISCULAS
	for(j=0; j<2; j++){
		char myChar1 = *(strarray[i]+j);
		if ((myChar1>='A')&&(myChar1<='Z')){}
		else{ 
		printf("\nCODIGO INVÁLIDO\n"); //(BREAK)
		validacao=1;
		innerValidacao=1;
		}
	}

//VALIDACAO DOS 3 ULTIMOS NUMEROS DOS PRODUTOS
//validacao do primeiro numero dos produtos
    char myChar2 = *(strarray[i]+2);
	if (myChar2=='1'){}
		else{ 
		printf("\nCODIGO INVÁLIDO\n"); //(BREAK)
		validacao=1;
		innerValidacao=1;
		}
////validacao dos ultimos tres numeros dos produtos
	for(j=3; j<6; j++){
		char myChar3 = *(strarray[i]+j);
//		char myChar4 = *(strarray[i]+(j+1));
		if ((myChar3>='0')&&(myChar3<='9')){}
//			printf("%c", myChar3);
//		}
		else{ 
		printf("\nCODIGO INVÁLIDO\n");
		validacao=1;
		innerValidacao=1;
		}
	}
//Saber se o produto é válido ou inválido (para cada um dos produtos).
if (innerValidacao==0) printf("\nCODIGO VALIDO\n");
else printf("\nCODIGO INVALIDO\n");
}
//Saber se existem produtos invalidos.
if (validacao==1) printf("\n\n~~~ATENÇÃO! HÁ PRODUTOS INVÁLIDOS.~~~\n");
else printf("\n~~~TODOS OS PRODUTOS SÃO VÁLIDOS.~~~\n");
}