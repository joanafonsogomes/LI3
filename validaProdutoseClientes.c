#define _SVID_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "validaProdutoseClientes.h"
#include "lerficheiros.h"


char** validaProdutos () {

char** strarray = NULL;
int i=0; int strcount=0;
int j=0;

char myChar1;
char myChar2;
char myChar3;

char** valProdutos=NULL;
strarray = lerprodutos();

for (i=0;strarray[i];i++){
int innerValidacao = 0;


/*VALIDACAO DAS PRIMEIRAS DUAS MAISCULAS*/
	for(j=0; j<2; j++){
		myChar1 = *(strarray[i]+j);
		if ((myChar1>='A')&&(myChar1<='Z')){}
		else{
		innerValidacao=1;
		}
	}

/*VALIDACAO DOS 3 ULTIMOS NUMEROS DOS PRODUTOS*/
/*validacao do primeiro numero dos produtos*/
    myChar2 = *(strarray[i]+2);
	if (myChar2=='1'){}
		else{
		innerValidacao=1;
		}

/*validacao dos ultimos tres numeros dos produtos*/
	for(j=3; j<6; j++){
		myChar3 = *(strarray[i]+j);
		if ((myChar3>='0')&&(myChar3<='9'));
		else{
		innerValidacao=1;
		}
	}
if (innerValidacao==0){
	valProdutos = (char**) realloc (valProdutos,(strcount+1)*sizeof(char*));
  valProdutos[strcount++]= strdup (strarray[i]);
}
}
 valProdutos[strcount] ='\0';
 for (i=0;strarray[i];i++)
 free(strarray[i]);
 free(strarray);
  return valProdutos;
}


int numero_prod (){
	char** prod; int i; int p=0;
	prod=validaProdutos ();
	for(i=0;prod[i];i++) p++;
	return p;
}



char** validaClientes () {

char** strarray;
int i=0; int strcount=0;
int j=0;

char myChar;
char myChar1;
char myChar2;

char** valClientes=NULL;
/*abrir ficheiro para ler*/
strarray = lerclientes();

for (i=0;strarray[i];i++){
int innerValidacao = 0;

/*VALIDACAO DA PRIMEIRA MAISCULA*/
	myChar = *strarray[i];

	if ((myChar<'A') || (myChar>'Z')){
		innerValidacao = 1;
	}

	myChar1 = *(strarray[i]+1);

/*VALIDACAO DO PRIMEIRO ALGARISMO*/
	if ((myChar1<'1') || (myChar1>'5')){
		innerValidacao = 1;
	}

/*VALIDACAO DOS OUTROS ALGARISMOS*/
/*Se o primeiro não for 5.*/
	else if ((myChar1>='1') && (myChar1<='4')){
		for(j=2; j<5; j++){

		myChar2 = *(strarray[i]+j);

		if ((myChar2<'0') || (myChar1>'9')){
			innerValidacao = 1;
		}
	}
	}
/*VALIDACAO DOS OUTROS ALGARISMOS*/
/*Se o primeiro for 5.*/
	else if (myChar1=='5'){
		for(j=2; j<5; j++){
			char myChar2 = *(strarray[i]+j);
			if ((myChar2!='0')&&(myChar1<='Z')){
			innerValidacao = 1;
			}
		}
	}

if (innerValidacao==0) {
	valClientes = (char**) realloc (valClientes,(strcount+1)*sizeof(char*));
  valClientes[strcount++]= strdup (strarray[i]);
}
}
 valClientes[strcount] ='\0';
 for (i=0;strarray[i];i++)
 free(strarray[i]);
 free(strarray);
  return valClientes;
}


int numero_client (){
	char** client; int i; int p=0;
	client=validaClientes ();
	for(i=0;client[i];i++) p++;
	return p;
}
