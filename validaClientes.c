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
strarray = lerclientes();

for (i=0;strarray[i];i++){
int innerValidacao = 0;
	printf("strarray[%d]==%s",i,strarray[i]);

//VALIDACAO DA PRIMEIRA MAISCULA
	char myChar = *strarray[i];

	if ((myChar<'A') || (myChar>'Z')){
		printf("\nCODIGO INVÁLIDO\n");
		validacao = 1;
	}

	char myChar1 = *(strarray[i]+1);

//VALIDACAO DO PRIMEIRO ALGARISMO
	if ((myChar1<'1') || (myChar1>'5')){
		printf("\nCODIGO INVÁLIDO\n");
		validacao = 1;
		innerValidacao = 1;
	}

//VALIDACAO DOS OUTROS ALGARISMOS
//Se o primeiro não for 5.
	else if ((myChar1>='1') && (myChar1<='4')){	
		for(j=2; j<5; j++){
		
		char myChar2 = *(strarray[i]+j);
		
		if ((myChar2<'0') || (myChar1>'9')){
			printf("\nCODIGO INVÁLIDO\n"); //(BREAK)
			validacao=1;
			innerValidacao = 1;
		}
	}
	}
//VALIDACAO DOS OUTROS ALGARISMOS
//Se o primeiro for 5.
	else if (myChar1=='5'){
		for(j=2; j<5; j++){
			char myChar2 = *(strarray[i]+j);
			if ((myChar2!='0')&&(myChar1<='Z')){
			printf("\nCODIGO INVÁLIDO\n");
			validacao = 1;
			innerValidacao = 1;
			}
		}
	}
//Saber se o cliente é válido ou inválido (para cada um dos clientes).
if (innerValidacao==0) printf("\nCODIGO VALIDO\n");
else printf("\nCODIGO INVALIDO\n");
}
//Saber se existem clientes invalidos.
if (validacao==1) printf("\n\n~~~ATENÇÃO! HÁ CLIENTES INVÁLIDOS~~~\n");
else printf("\n~~~TODOS OS CLIENTES SÃO VÁLIDOS~~~\n");
}