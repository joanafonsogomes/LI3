/* Programa em C para design da shell no Linux*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
#include "CatProdutos.h"
#include "filial1.h"
#include "filial2.h"
#include "filial3.h"
#include "FactGlobal.h"
#include "Vendas.h"
#include "queries.h"

/*relacionados com o aspeto*/
#define MAG  "\x1B[35m"
#define BMAG  "\x1B[1;35m"
#define BLUE "\x1B[34m"
#define BBLUE "\x1B[1;34m"
#define YEL "\x1B[33m"
#define BYEL "\x1B[1;33m"
#define GREEN "\x1B[32m"
#define BGREEN "\x1B[1;32m"
#define RESET "\x1B[0m"

#define MAXCOM 1000 /* máximo de numero de letras suportadas*/
#define MAXLIST 100 /* máximo comandos suportados*/

/*clear da shell*/
#define clear() printf("\033[H\033[J")

/*Pop-up de boas-vindas inicial*/
void init_shell()
{
    clear();
    printf("\n\n\n\n%s******************"
        "**********************************************************",BGREEN);
    printf("\n\n\n\t\t       ******SGV LI3******%s",RESET);
    printf("\n\n%s   -para ajuda ou informações adicionais, escreva 'help' na linha de comandos-%s",GREEN,RESET);
    printf("\n\n\n\n%s******************"
        "**********************************************************%s",BGREEN,RESET);
    char* username = getenv("USER");
    printf("\n\n\n%sUtilizador: @%s%s",MAG,username,RESET);
    printf("\n");
    sleep(1);
    clear();
}

void showQueries()
{
    clear();
    printf("\n\n\n\n%s******************"
        "************************************************************",BGREEN);
    printf("\n\n                                QUERIES:                           \n");
    printf("\n 2%s - %sDeterminar a lista e o número total de produtos cujo código se inicia por\n",RESET,GREEN);
    printf("uma dada letra (maiúscula);%s\n",RESET);
    printf("\n%s 3%s - %sDado um mês e um código de produto determinar e apresentar o número total\n",BGREEN,RESET,GREEN);
    printf("de vendas (nº de registos de venda) e o total facturado com esse produto em tal\n");
    printf("mês, distinguindo os totais em modo N e os totais em modo P. O utilizador deverá\n");
    printf("decidir se pretende o resultado global ou os resultados filial a filial para\n");
    printf("todas as 3 filiais;%s\n",RESET);
    printf("\n%s 4%s - %sDeterminar a lista ordenada dos códigos dos produtos (e o seu número total)\n",BGREEN,RESET,GREEN);
    printf("que ninguém comprou, podendo o utilizador decidir igualmente se pretende\n");
    printf("valores totais ou divididos pelas filiais. %s\n",RESET);
    printf("\n%s 5%s - %sDeterminar a lista ordenada de códigos de clientes que realizaram compras\n",BGREEN,RESET,GREEN);
    printf("em todas as filiais; %s\n",RESET);
    printf("\n%s 8%s - %sDado um intervalo fechado de meses determinar o total de vendas (nº de\n",BGREEN, RESET,GREEN);
    printf("registos de venda) registadas nesse intervalo e o total facturado;\n");
    /*printf("\n%s 3%s - %sDeterminar a lista e o número total de produtos cujo código se inicia\n",BMAG,RESET,MAG);
    /printf("por uma dada letra (maiúscula);%s\n",RESET);*/
    printf("\n%s******************"
        "************************************************************%s",BGREEN,RESET);
    printf("\n");
}

/*Recebe o input*/
int takeInput(char* str)
{
    char* buf;

    buf = readline("\n>>> ");
    if (strlen(buf) != 0) {
        add_history(buf);
        strcpy(str, buf);
        return 0;
    } else {
        return 1;
    }
}

/*Imprime a diretoria atual*/
void printDir()
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("\nDir: %s", cwd);
}

void instructions(){
    puts("\n### CLEAN; OTHER QUERIE; ANOTHER FUNCTION ON THIS QUERIE ###");
}

/*Function where the system command is executed*/
void execArgs(char** parsed)
{
    /* Forking a child*/
    pid_t pid = fork();

    if (pid == -1) {
        printf("\nFailed forking child..");
        return;
    } else if (pid == 0) {
        if (execvp(parsed[0], parsed) < 0) {
            printf("\nCould not execute command..");
        }
        exit(0);
    } else {
        /* waiting for child to terminate*/
        wait(NULL);
        return;
    }
}

/* Function where the piped system commands is executed*/
void execArgsPiped(char** parsed, char** parsedpipe)
{
    /* 0 is read end, 1 is write end*/
    int pipefd[2];
    pid_t p1, p2;

    if (pipe(pipefd) < 0) {
        printf("\nPipe could not be initialized");
        return;
    }
    p1 = fork();
    if (p1 < 0) {
        printf("\nCould not fork");
        return;
    }

    if (p1 == 0) {
        /* Child 1 executing..
         It only needs to write at the write end*/
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        if (execvp(parsed[0], parsed) < 0) {
            printf("\nCould not execute command 1..");
            exit(0);
        }
    } else {
        /* Parent executing*/
        p2 = fork();

        if (p2 < 0) {
            printf("\nCould not fork");
            return;
        }

        /* Child 2 executing..
        / It only needs to read at the read end*/
        if (p2 == 0) {
            close(pipefd[1]);
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);
            if (execvp(parsedpipe[0], parsedpipe) < 0) {
                printf("\nCould not execute command 2..");
                exit(0);
            }
        } else {
            /* parent executing, waiting for two children*/
            wait(NULL);
            wait(NULL);
        }
    }
}

/*Comandos de ajuda*/
void openHelp()
{
    puts("\n***AJUDA***\n"
        "\n->Para fazer isto (...) faça isto (...)"
        "\n->Para fazer isto (...) faça isto (...)"
        "\n->Para fazer isto (...) faça isto (...)"
        "\n->Para fazer isto (...) faça isto (...)"
        "\n->Para fazer isto (...) faça isto (...)"
        "\n->COMANDOS SUPORTADOS:"
        "\n  >cd"
        "\n  >ls"
        "\n  >exit"
        "\n  >todos os outros comandos gerais UNIX shell");

    return;
}

void querieTime(){
Cat_Prodd catprodutos;
catprodutos = inicializa_CatProdutos();
Factt factur;
factur = inicializa_fact();
showQueries();
printf("\n%s>>> Insira o número da querie que deseja:%s ", BMAG, RESET);
int querie_num, querie2_num, querie3_num, querie4_num, querie8_num;
int opt2a, opt2b, opt8a, opt8b, mes1, mes2, mesa, mesb;
int ctrl=0;
scanf("%d",&querie_num);
while(querie_num!=0){
        switch(querie_num){
        /*QUERIE 1*/
        case 1:
            printf("Ola");
            querie_num = 1;
        /*QUERIE 2*/
        case 2:
            printf("\n%s-------------------------%s",MAG,RESET);
            printf("\n\n%sO que pretende? \n%s ", BMAG, RESET);
            printf("\n%s 1%s - Saber os produtos inicializados por uma determinada letra.\n",BMAG,RESET);
            printf("%s 2%s - Saber o número de produtos inicializados por uma determinada letra\n",BMAG,RESET);
            printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
            scanf("%d",&querie2_num);
            /*OPCAO 1*/
            if (querie2_num==1){
                jump1:
                printf("\n%s>>> Insira a letra por que quer que comecem os produtos:%s ", BMAG, RESET);
                char letra2;
                scanf(" %c",&letra2);
                printincLetra_Produtos(catprodutos,letra2);
                /*FALTA METÊ-LOS POR PAGINAS*/
                sleep(2);
                printf("\n%s-------------------------%s",MAG,RESET);
                printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                printf("\n%s 1%s - Saber o número de produtos inicializados pela mesma letra.\n",BMAG,RESET);
                printf("%s 2%s - Ver os produtos inicializados por uma outra letra.\n",BMAG,RESET);
                printf("%s 3%s - Saber o número de produtos inicializados por outra letra.\n",BMAG,RESET);
                printf("%s 4%s - Ir para outra querie.\n ",BMAG,RESET);
                printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                scanf("%d",&opt2a);
                    switch(opt2a){
                        case 1:{
                            int result1;
                            result1 = listainicLetraNumero_Produtos(catprodutos,letra2);
                            printf("\nO número de produtos começados pela letra %s%c%s é ", GREEN, letra2, RESET);
                            printf("%s%d%s.\n",BGREEN,result1,RESET);
                            sleep(2);
                            goto jump;
                        }
                        case 2:
                            goto jump1;
                        case 3:
                            goto jump2;
                        case 4:
                            querieTime();
                    }
            }
            /*OPCAO 2*/
            else{
                jump2:
                printf("\n%s>>> Insira a letra por que quer que comecem os produtos:%s ", BMAG, RESET);
                char letra22;
                scanf(" %c",&letra22);
                int result;
                result = listainicLetraNumero_Produtos(catprodutos,letra22);
                printf("\nO número de produtos começados pela letra %s%c%s é ", GREEN, letra22, RESET);
                printf("%s%d%s.\n",BGREEN,result,RESET);
                sleep(2);
                jump:
                printf("\n%s-------------------------%s",MAG,RESET);
                printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                printf("\n%s 1%s - Ver os produtos inicializados pela mesma letra.\n",BMAG,RESET);
                printf("%s 2%s - Saber o número de produtos inicializados por outra letra.\n",BMAG,RESET);
                printf("%s 3%s - Ver os produtos inicializados por outra letra.\n",BMAG,RESET);
                printf("%s 4%s - Ir para outra querie.\n ",BMAG,RESET);
                printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                scanf("%d",&opt2b);
                    switch(opt2b){
                        case 1:{
                            int result2;
                            result2 = listainicLetraNumero_Produtos(catprodutos,letra22);
                            printf("\nO número de produtos começados pela letra %s%c%s é ", GREEN, letra22, RESET);
                            printf("%s%d%s.\n",BGREEN,result2,RESET);
                        }
                        case 2:
                            goto jump2;
                        case 3:
                            goto jump1;
                        case 4: querieTime();
                    }

            }
    /*QUERIE 3*/
    case 3:
        printf("\n%s-------------------------%s",MAG,RESET);
        printf("\n\n%sO que pretende? \n%s ", BMAG, RESET);
        printf("\n%s 1%s - Saber o número total de registos de vendas de um produto num dado mês.\n",BMAG,RESET);
        printf("%s 2%s - Saber o total fraturado com um produto num dado mês.\n",BMAG,RESET);
        printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
        scanf("%d",&querie3_num);
        printf("\n%s>>> Apresente o código do produto:%s ", BMAG, RESET);
        char codigoPro[6];
        scanf("%s",codigoPro);
        jump10:
        printf("\n%s>>> Indique o mês pretendido [1-12]:%s ", BMAG, RESET);
        int mes3;
        scanf("%d",&mes3);
        printf("\n%s>>> Pretende o resultado global(%sG%s) ou o resultado filial a filial(%sF%s):%s ", BMAG, BGREEN, BMAG, BGREEN, BMAG, RESET);
        char gf;
        scanf(" %c",&gf);
        /*OPCAO 1 (REGISTOS DE VENDAS)*/
        if (querie3_num==1){
                /*global*/
                if(gf=='G'){
                    jump13:
                    printf("\n%s>>> Pretende o resultado em modo Normal (%sN%s) ou em modo Promoção (%sP%s):%s ", BMAG, BGREEN, BMAG, BGREEN, BMAG, RESET);
                    char tipo;
                    scanf(" %c",&tipo);
                        if(tipo=='N'){
                           int totalVendasGN = numero_total_deVendas_ModoN(factur,mes3,codigoPro);
                           jump11:
                           printf("\nO número total de vendas do produto %s%s%s, sem promoção, no mês %s%d%s é %s%d%s.\n",GREEN,codigoPro,RESET,GREEN,mes3,RESET,BGREEN,totalVendasGN,RESET);
                           sleep(2);
                                printf("\n%s-------------------------%s",MAG,RESET);
                                printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                                printf("\n%s 1%s - Ver o resultado em modo Promoção.\n",BMAG,RESET);
                                printf("%s 2%s - Ver o número total de registos de venda filial a filial.\n",BMAG,RESET);
                                printf("%s 3%s - Saber o total facturado.\n",BMAG,RESET);
                                printf("%s 4%s - Analisar o mesmo produto noutro mês.\n",BMAG,RESET);
                                printf("%s 5%s - Ir para outra querie.\n",BMAG,RESET);
                                printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                                int opt3a;
                                scanf("%d",&opt3a);
                                    switch(opt3a){
                                        case 1:
                                            goto jump7;
                                        case 2:
                                            goto jump8;
                                        case 3:
                                            goto jump9;
                                        case 4:
                                            goto jump10;
                                        case 5:
                                            querieTime();
                                        }
                        }
                        else{
                            int totalVendasGP = numero_total_deVendas_ModoP(factur,mes3,codigoPro);
                            jump7:
                            printf("\nO número total de vendas do produto %s%s%s, com %spromoção%s, no mês %s%d%s é %s%d%s.\n",GREEN,codigoPro,RESET,GREEN,RESET,GREEN,mes3,RESET,BGREEN,totalVendasGP,RESET);
                            sleep(2);
                                printf("\n%s-------------------------%s",MAG,RESET);
                                printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                                printf("\n%s 1%s - Ver o resultado em modo sem promoção.\n",BMAG,RESET);
                                printf("%s 2%s - Ver o número total de registos de venda filial a filial.\n",BMAG,RESET);
                                printf("%s 3%s - Saber o total facturado.\n",BMAG,RESET);
                                printf("%s 4%s - Analisar o mesmo produto noutro mês.\n",BMAG,RESET);
                                printf("%s 5%s - Ir para outra querie.\n",BMAG,RESET);
                                printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                                int opt3b;
                                scanf("%d",&opt3b);
                                    switch(opt3b){
                                        case 1:
                                            goto jump11;
                                        case 2:
                                            goto jump8;
                                        case 3:
                                            goto jump9;
                                        case 4:
                                            goto jump10;
                                        case 5:
                                            querieTime();
                                        }
                        }
                    }
            /*filiais*/
            else{
                jump8:
                printf("\n%s>>> Pretende o resultado em que filial: %s1%s, %s2%s ou %s3%s?%s ", BMAG, BGREEN, BMAG, BGREEN, BMAG, BGREEN, BMAG, RESET);
                int filial;
                scanf("%d",&filial);
                switch(filial){
                    case 1:{
                        jump26:
                        printf("\n%s>>> Pretende o resultado em modo Normal (%sN%s) ou em modo Promoção (%sP%s):%s ", BMAG, BGREEN, BMAG, BGREEN, BMAG, RESET);
                        char tipof1;
                        scanf(" %c",&tipof1);
                        if(tipof1=='N'){
                            float totalVendasF1N = numero_total_deVendas_ModoN_Filial1(factur,mes3,codigoPro);
                            jump15:
                            printf("\nO número de vendas do produto %s%s%s, sem promoção, na %sfilial 1%s, no mês %s%d%s é %s%f%s€.\n",GREEN,codigoPro,RESET,GREEN,RESET,GREEN,mes3,RESET,BGREEN,totalVendasF1N,RESET);
                            sleep(2);
                                printf("\n%s-------------------------%s",MAG,RESET);
                                printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                                printf("\n%s 1%s - Ver o resultado em modo Promoção.\n",BMAG,RESET);
                                printf("%s 2%s - Ver o número total de registos de venda noutra filial.\n",BMAG,RESET);
                                printf("%s 3%s - Ver o número total de registos de venda a nível global.\n",BMAG,RESET);
                                printf("%s 4%s - Saber o total facturado.\n",BMAG,RESET);
                                printf("%s 5%s - Analisar o mesmo produto noutro mês.\n",BMAG,RESET);
                                printf("%s 6%s - Ir para outra querie.\n",BMAG,RESET);
                                printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                                int opt3c;
                                scanf("%d",&opt3c);
                                    switch(opt3c){
                                        case 1:
                                            goto jump12;
                                        case 2:
                                            goto jump8;
                                        case 3:
                                            goto jump13;
                                        case 4:
                                            goto jump14;
                                        case 5:
                                            goto jump10;
                                        case 6:
                                            querieTime();
                                        }
                        }
                        else{
                            float totalVendasF1P = numero_total_deVendas_ModoP_Filial1(factur,mes3,codigoPro);
                            jump12:
                            printf("\nO número total de vendas do produto %s%s%s, com %spromoção%s, na %sfilial 1%s, no mês %s%d%s é %s%f%s€.\n",GREEN,codigoPro,RESET,GREEN,RESET,GREEN,RESET,GREEN,mes3,RESET,BGREEN,totalVendasF1P,RESET);
                            sleep(2);
                                printf("\n%s-------------------------%s",MAG,RESET);
                                printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                                printf("\n%s 1%s - Ver o resultado em modo sem promoção.\n",BMAG,RESET);
                                printf("%s 2%s - Ver o número total de registos de venda noutra filial.\n",BMAG,RESET);
                                printf("%s 3%s - Ver o número total de registos de venda a nível global.\n",BMAG,RESET);
                                printf("%s 4%s - Saber o total facturado.\n",BMAG,RESET);
                                printf("%s 5%s - Analisar o mesmo produto noutro mês.\n",BMAG,RESET);
                                printf("%s 6%s - Ir para outra querie.\n",BMAG,RESET);
                                printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                                int opt3d;
                                scanf("%d",&opt3d);
                                    switch(opt3d){
                                        case 1:
                                            goto jump15;
                                        case 2:
                                            goto jump8;
                                        case 3:
                                            goto jump13;
                                        case 4:
                                            goto jump14;
                                        case 5:
                                            goto jump10;
                                        case 6:
                                            querieTime();
                                        }
                        }
                    }
                    case 2:{
                        jump28:
                        printf("\n%s>>> Pretende o resultado em modo Normal (%sN%s) ou em modo Promoção (%sP%s):%s ", BMAG, BGREEN, BMAG, BGREEN, BMAG, RESET);
                        char tipof2;
                        scanf(" %c",&tipof2);
                        if(tipof2=='N'){
                            int totalVendasF2N = numero_total_deVendas_ModoN_Filial2(factur,mes3,codigoPro);
                            jump18:
                            printf("\nO número total de vendas do produto %s%s%s, sem promoção, na %sfilial 2%s, no mês %s%d%s é %s%d%s.\n",GREEN,codigoPro,RESET,GREEN,RESET,GREEN,mes3,RESET,BGREEN,totalVendasF2N,RESET);
                            sleep(2);
                                printf("\n%s-------------------------%s",MAG,RESET);
                                printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                                printf("\n%s 1%s - Ver o resultado em modo Promoção.\n",BMAG,RESET);
                                printf("%s 2%s - Ver o número total de registos de venda noutra filial.\n",BMAG,RESET);
                                printf("%s 3%s - Ver o número total de registos de venda a nível global.\n",BMAG,RESET);
                                printf("%s 4%s - Saber o total facturado.\n",BMAG,RESET);
                                printf("%s 5%s - Analisar o mesmo produto noutro mês.\n",BMAG,RESET);
                                printf("%s 6%s - Ir para outra querie.\n",BMAG,RESET);
                                printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                                int opt3e;
                                scanf("%d",&opt3e);
                                    switch(opt3e){
                                        case 1:
                                            goto jump16;
                                        case 2:
                                            goto jump8;
                                        case 3:
                                            goto jump13;
                                        case 4:
                                            goto jump17;
                                        case 5:
                                            goto jump10;
                                        case 6:
                                            querieTime();
                                        }
                        }
                        else{
                            int totalVendasF2P = numero_total_deVendas_ModoP_Filial2(factur,mes3,codigoPro);
                            jump16:
                            printf("\nO número total de vendas do produto %s%s%s, com %spromoção%s, na %sfilial 2%s, no mês %s%d%s é %s%d%s.\n",GREEN,codigoPro,RESET,GREEN,RESET,GREEN,RESET,GREEN,mes3,RESET,BGREEN,totalVendasF2P,RESET);
                            sleep(2);
                                printf("\n%s-------------------------%s",MAG,RESET);
                                printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                                printf("\n%s 1%s - Ver o resultado em modo sem promoção.\n",BMAG,RESET);
                                printf("%s 2%s - Ver o número total de registos de venda noutra filial.\n",BMAG,RESET);
                                printf("%s 3%s - Ver o número total de registos de venda a nível global.\n",BMAG,RESET);
                                printf("%s 4%s - Saber o total facturado.\n",BMAG,RESET);
                                printf("%s 5%s - Analisar o mesmo produto noutro mês.\n",BMAG,RESET);
                                printf("%s 6%s - Ir para outra querie.\n",BMAG,RESET);
                                printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                                int opt3f;
                                scanf("%d",&opt3f);
                                    switch(opt3f){
                                        case 1:
                                            goto jump18;
                                        case 2:
                                            goto jump8;
                                        case 3:
                                            goto jump13;
                                        case 4:
                                            goto jump17;
                                        case 5:
                                            goto jump10;
                                        case 6:
                                            querieTime();
                                        }
                        }
                    }
                    case 3:{
                        jump32:
                        printf("\n%s>>> Pretende o resultado em modo Normal (%sN%s) ou em modo Promoção (%sP%s):%s ", BMAG, BGREEN, BMAG, BGREEN, BMAG, RESET);
                        char tipof3;
                        scanf(" %c",&tipof3);
                        if(tipof3=='N'){
                            int totalVendasF3N = numero_totalfaturado_ModoN_Filial3(factur,mes3,codigoPro);
                            jump21:
                            printf("\nO número de vendas do produto %s%s%s, sem promoção, na %sfilial 3%s, no mês %s%d%s é %s%d%s.\n",GREEN,codigoPro,RESET,GREEN,RESET,GREEN,mes3,RESET,BGREEN,totalVendasF3N,RESET);
                            sleep(2);
                            printf("\n%s-------------------------%s",MAG,RESET);
                                printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                                printf("\n%s 1%s - Ver o resultado em modo Promoção.\n",BMAG,RESET);
                                printf("%s 2%s - Ver o número total de registos de venda noutra filial.\n",BMAG,RESET);
                                printf("%s 3%s - Ver o número total de registos de venda a nível global.\n",BMAG,RESET);
                                printf("%s 4%s - Saber o total facturado.\n",BMAG,RESET);
                                printf("%s 5%s - Analisar o mesmo produto noutro mês.\n",BMAG,RESET);
                                printf("%s 6%s - Ir para outra querie.\n",BMAG,RESET);
                                printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                                int opt3g;
                                scanf("%d",&opt3g);
                                    switch(opt3g){
                                        case 1:
                                            goto jump19;
                                        case 2:
                                            goto jump8;
                                        case 3:
                                            goto jump13;
                                        case 4:
                                            goto jump20;
                                        case 5:
                                            goto jump10;
                                        case 6:
                                            querieTime();
                                        }
                        }
                        else{
                            int totalVendasF3P = numero_totalfaturado_ModoP_Filial3(factur,mes3,codigoPro);
                            jump19:
                            printf("\nO número total de vendas do produto %s%s%s, com %spromoção%s, na %sfilial 3%s, no mês %s%d%s é %s%d%s.\n",GREEN,codigoPro,RESET,GREEN,RESET,GREEN,RESET,GREEN,mes3,RESET,BGREEN,totalVendasF3P,RESET);
                            sleep(2);
                            printf("\n%s-------------------------%s",MAG,RESET);
                                printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                                printf("\n%s 1%s - Ver o resultado em modo sem promoção.\n",BMAG,RESET);
                                printf("%s 2%s - Ver o número total de registos de venda noutra filial.\n",BMAG,RESET);
                                printf("%s 3%s - Ver o número total de registos de venda a nível global.\n",BMAG,RESET);
                                printf("%s 4%s - Saber o total facturado.\n",BMAG,RESET);
                                printf("%s 5%s - Analisar o mesmo produto noutro mês.\n",BMAG,RESET);
                                printf("%s 6%s - Ir para outra querie.\n",BMAG,RESET);
                                printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                                int opt3h;
                                scanf("%d",&opt3h);
                                    switch(opt3h){
                                        case 1:
                                            goto jump21;
                                        case 2:
                                            goto jump8;
                                        case 3:
                                            goto jump13;
                                        case 4:
                                            goto jump20;
                                        case 5:
                                            goto jump10;
                                        case 6:
                                            querieTime();
                                        }
                        }
                    }
                }
            }
        }
    /*OPCAO 2 (FATURADO)*/
    else{
        /*global*/
        if(gf=='G'){
            jump9:
            printf("\n%s>>> Pretende o resultado em modo Normal (%sN%s) ou em modo Promoção (%sP%s):%s ", BMAG, BGREEN, BMAG, BGREEN, BMAG, RESET);
            char tipo2;
            scanf(" %c",&tipo2);
                if(tipo2=='N'){
                   float totalVendasGN = numero_totalfaturado_ModoN(factur,mes3,codigoPro);
                   jump24:
                   printf("\nO total facturado com a venda do produto %s%s%s, sem promoção, no mês %s%d%s é de %s%f%s€.\n",GREEN,codigoPro,RESET,GREEN,mes3,RESET,BGREEN,totalVendasGN,RESET);
                    sleep(2);
                    printf("\n%s-------------------------%s",MAG,RESET);
                        printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                        printf("\n%s 1%s - Ver o resultado em modo Promoção.\n",BMAG,RESET);
                        printf("%s 2%s - Saber o total facturado filial a filial.\n",BMAG,RESET);
                        printf("%s 3%s - Ver o número total de registos de venda.\n",BMAG,RESET);
                        printf("%s 4%s - Analisar o mesmo produto noutro mês.\n",BMAG,RESET);
                        printf("%s 5%s - Ir para outra querie.\n",BMAG,RESET);
                        printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                        int opt3i;
                        scanf("%d",&opt3i);
                            switch(opt3i){
                                case 1:
                                    goto jump22;
                                case 2:
                                    goto jump23;
                                case 3:
                                    goto jump13;
                                case 4:
                                    goto jump10;
                                case 5:
                                    querieTime();
                                }
                }
                else{
                    float totalVendasGP = numero_totalfaturado_ModoP(factur,mes3,codigoPro);
                    jump22:
                    printf("\nO total facturado com a venda do produto %s%s%s, com %spromoção%s, no mês %s%d%s é de %s%f%s€.\n",GREEN,codigoPro,RESET,GREEN,RESET,GREEN,mes3,RESET,BGREEN,totalVendasGP,RESET);
                    sleep(2);
                        printf("\n%s-------------------------%s",MAG,RESET);
                        printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                        printf("\n%s 1%s - Ver o resultado em modo sem promoção.\n",BMAG,RESET);
                        printf("%s 2%s - Saber o total facturado filial a filial.\n",BMAG,RESET);
                        printf("%s 3%s - Ver o número total de registos de venda.\n",BMAG,RESET);
                        printf("%s 4%s - Analisar o mesmo produto noutro mês.\n",BMAG,RESET);
                        printf("%s 5%s - Ir para outra querie.\n",BMAG,RESET);
                        printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                        int opt3j;
                        scanf("%d",&opt3j);
                            switch(opt3j){
                                case 1:
                                    goto jump24;
                                case 2:
                                    goto jump23;
                                case 3:
                                    goto jump13;
                                case 4:
                                    goto jump10;
                                case 5:
                                    querieTime();
                                }
                }
        }
        /*filiais*/
        else{
            jump23:
            printf("\n%s>>> Pretende o resultado em que filial: %s1%s, %s2%s ou %s3%s?%s ", BMAG, BGREEN, BMAG, BGREEN, BMAG, BGREEN, BMAG, RESET);
            int filial;
            scanf("%d",&filial);
            switch(filial){
                case 1:{
                    jump14:
                    printf("\n%s>>> Pretende o resultado em modo Normal (%sN%s) ou em modo Promoção (%sP%s):%s ", BMAG, BGREEN, BMAG, BGREEN, BMAG, RESET);
                    char tipoof1;
                    scanf(" %c",&tipoof1);
                    if(tipoof1=='N'){
                        float totalVendasF1N = numero_totalfaturado_ModoN_Filial1(factur,mes3,codigoPro);
                        jump27:
                        printf("\nO total facturado com a venda do produto %s%s%s, sem promoção, na %sfilial 1%s, no mês %s%d%s é de %s%f%s€.\n",GREEN,codigoPro,RESET,GREEN,RESET,GREEN,mes3,RESET,BGREEN,totalVendasF1N,RESET);
                        sleep(2);
                        printf("\n%s-------------------------%s",MAG,RESET);
                                printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                                printf("\n%s 1%s - Ver o resultado em modo Promoção.\n",BMAG,RESET);
                                printf("%s 2%s - Saber o total facturado noutra filial.\n",BMAG,RESET);
                                printf("%s 3%s - Saber o total facturado a nível global.\n",BMAG,RESET);
                                printf("%s 4%s - Ver o número total de registos de venda.\n",BMAG,RESET);
                                printf("%s 5%s - Analisar o mesmo produto noutro mês.\n",BMAG,RESET);
                                printf("%s 6%s - Ir para outra querie.\n",BMAG,RESET);
                                printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                                int opt3k;
                                scanf("%d",&opt3k);
                                    switch(opt3k){
                                        case 1:
                                            goto jump25;
                                        case 2:
                                            goto jump23;
                                        case 3:
                                            goto jump9;
                                        case 4:
                                            goto jump26;
                                        case 5:
                                            goto jump10;
                                        case 6:
                                            querieTime();
                                        }
                    }
                    else{
                        float totalVendasF1P = numero_totalfaturado_ModoP_Filial1(factur,mes3,codigoPro);
                        jump25:
                        printf("\nO total facturado com a venda do produto %s%s%s, com %spromoção%s, na %sfilial 1%s, no mês %s%d%s é de %s%f%s€.\n",GREEN,codigoPro,RESET,GREEN,RESET,GREEN,RESET,GREEN,mes3,RESET,BGREEN,totalVendasF1P,RESET);
                        sleep(2);
                                printf("\n%s-------------------------%s",MAG,RESET);
                                printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                                printf("\n%s 1%s - Ver o resultado em modo sem promoção.\n",BMAG,RESET);
                                printf("%s 2%s - Saber o total facturado noutra filial.\n",BMAG,RESET);
                                printf("%s 3%s - Saber o total facturado a nível global.\n",BMAG,RESET);
                                printf("%s 4%s - Ver o número total de registos de venda.\n",BMAG,RESET);
                                printf("%s 5%s - Analisar o mesmo produto noutro mês.\n",BMAG,RESET);
                                printf("%s 6%s - Ir para outra querie.\n",BMAG,RESET);
                                printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                                int opt3l;
                                scanf("%d",&opt3l);
                                    switch(opt3l){
                                        case 1:
                                            goto jump27;
                                        case 2:
                                            goto jump23;
                                        case 3:
                                            goto jump9;
                                        case 4:
                                            goto jump26;
                                        case 5:
                                            goto jump10;
                                        case 6:
                                            querieTime();
                                        }
                    }
                }
                case 2:{
                    jump17:
                    printf("\n%s>>> Pretende o resultado em modo Normal (%sN%s) ou em modo Promoção (%sP%s):%s ", BMAG, BGREEN, BMAG, BGREEN, BMAG, RESET);
                    char tipoof2;
                    scanf(" %c",&tipoof2);
                    if(tipoof2=='N'){
                        float totalVendasF2N = numero_totalfaturado_ModoN_Filial2(factur,mes3,codigoPro);
                        jump30:
                        printf("\nO total facturado com a venda do produto %s%s%s, sem promoção, na %sfilial 2%s, no mês %s%d%s é de %s%f%s€.\n",GREEN,codigoPro,RESET,GREEN,RESET,GREEN,mes3,RESET,BGREEN,totalVendasF2N,RESET);
                        sleep(2);
                                printf("\n%s-------------------------%s",MAG,RESET);
                                printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                                printf("\n%s 1%s - Ver o resultado em modo Promoção.\n",BMAG,RESET);
                                printf("%s 2%s - Saber o total facturado noutra filial.\n",BMAG,RESET);
                                printf("%s 3%s - Saber o total facturado a nível global.\n",BMAG,RESET);
                                printf("%s 4%s - Ver o número total de registos de venda.\n",BMAG,RESET);
                                printf("%s 5%s - Analisar o mesmo produto noutro mês.\n",BMAG,RESET);
                                printf("%s 6%s - Ir para outra querie.\n",BMAG,RESET);
                                printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                                int opt3m;
                                scanf("%d",&opt3m);
                                    switch(opt3m){
                                        case 1:
                                            goto jump29;
                                        case 2:
                                            goto jump23;
                                        case 3:
                                            goto jump9;
                                        case 4:
                                            goto jump28;
                                        case 5:
                                            goto jump10;
                                        case 6:
                                            querieTime();
                                        }
                    }
                    else{
                        float totalVendasF2P = numero_totalfaturado_ModoP_Filial2(factur,mes3,codigoPro);
                        jump29:
                        printf("\nO total facturado com a venda do produto %s%s%s, com %spromoção%s, na %sfilial 2%s, no mês %s%d%s é de %s%f%s€.\n",GREEN,codigoPro,RESET,GREEN,RESET,GREEN,RESET,GREEN,mes3,RESET,BGREEN,totalVendasF2P,RESET);
                        sleep(2);
                                printf("\n%s 1%s - Ver o resultado em modo sem promoção.\n",BMAG,RESET);
                                printf("%s 2%s - Saber o total facturado noutra filial.\n",BMAG,RESET);
                                printf("%s 3%s - Saber o total facturado a nível global.\n",BMAG,RESET);
                                printf("%s 4%s - Ver o número total de registos de venda.\n",BMAG,RESET);
                                printf("%s 5%s - Analisar o mesmo produto noutro mês.\n",BMAG,RESET);
                                printf("%s 6%s - Ir para outra querie.\n",BMAG,RESET);
                                printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                                int opt3n;
                                scanf("%d",&opt3n);
                                    switch(opt3n){
                                        case 1:
                                            goto jump30;
                                        case 2:
                                            goto jump23;
                                        case 3:
                                            goto jump9;
                                        case 4:
                                            goto jump28;
                                        case 5:
                                            goto jump10;
                                        case 6:
                                            querieTime();
                                        }
                    }
                }
                case 3:{
                    jump20:
                    printf("\n%s>>> Pretende o resultado em modo Normal (%sN%s) ou em modo Promoção (%sP%s):%s ", BMAG, BGREEN, BMAG, BGREEN, BMAG, RESET);
                    char tipoof3;
                    scanf(" %c",&tipoof3);
                    if(tipoof3=='N'){
                        float totalVendasF3N = numero_totalfaturado_ModoN_Filial3(factur,mes3,codigoPro);
                        jump33:
                        printf("\nO total facturado com a venda do produto %s%s%s, sem promoção, na %sfilial 3%s, no mês %s%d%s é de %s%f%s.\n",GREEN,codigoPro,RESET,GREEN,RESET,GREEN,mes3,RESET,BGREEN,totalVendasF3N,RESET);
                        sleep(2);
                                printf("\n%s 1%s - Ver o resultado em modo Promoção.\n",BMAG,RESET);
                                printf("%s 2%s - Saber o total facturado noutra filial.\n",BMAG,RESET);
                                printf("%s 3%s - Saber o total facturado a nível global.\n",BMAG,RESET);
                                printf("%s 4%s - Ver o número total de registos de venda.\n",BMAG,RESET);
                                printf("%s 5%s - Analisar o mesmo produto noutro mês.\n",BMAG,RESET);
                                printf("%s 6%s - Ir para outra querie.\n",BMAG,RESET);
                                printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                                int opt3o;
                                scanf("%d",&opt3o);
                                    switch(opt3o){
                                        case 1:
                                            goto jump31;
                                        case 2:
                                            goto jump23;
                                        case 3:
                                            goto jump9;
                                        case 4:
                                            goto jump32;
                                        case 5:
                                            goto jump10;
                                        case 6:
                                            querieTime();
                                        }
                    }
                    else{
                        float totalVendasF3P = numero_totalfaturado_ModoP_Filial1(factur,mes3,codigoPro);
                        jump31:
                        printf("\nO total facturado com a venda do produto %s%s%s, com %spromoção%s, na %sfilial 3%s, no mês %s%d%s é de %s%f%s€.\n",GREEN,codigoPro,RESET,GREEN,RESET,GREEN,RESET,GREEN,mes3,RESET,BGREEN,totalVendasF3P,RESET);
                        sleep(2);
                                printf("\n%s 1%s - Ver o resultado em modo Promoção.\n",BMAG,RESET);
                                printf("%s 2%s - Saber o total facturado noutra filial.\n",BMAG,RESET);
                                printf("%s 3%s - Saber o total facturado a nível global.\n",BMAG,RESET);
                                printf("%s 4%s - Ver o número total de registos de venda.\n",BMAG,RESET);
                                printf("%s 5%s - Analisar o mesmo produto noutro mês.\n",BMAG,RESET);
                                printf("%s 6%s - Ir para outra querie.\n",BMAG,RESET);
                                printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                                int opt3p;
                                scanf("%d",&opt3p);
                                    switch(opt3p){
                                        case 1:
                                            goto jump33;
                                        case 2:
                                            goto jump23;
                                        case 3:
                                            goto jump9;
                                        case 4:
                                            goto jump32;
                                        case 5:
                                            goto jump10;
                                        case 6:
                                            querieTime();
                                        }
                    }
                }
            }
        }
    }
/*QUERIE 4*/
case 4:
    printf("\n%s-------------------------%s",MAG,RESET);
    printf("\n\n%sO que pretende? \n%s ", BMAG, RESET);
    printf("\n%s 1%s - Ver a lista dos produtos não vendidos.\n",BMAG,RESET);
    printf("%s 2%s - Saber o número de produtos não vendidos.\n",BMAG,RESET);
    printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
    scanf("%d",&querie4_num);
    //lista
    if (querie4_num==1){
        printf("\n%s>>> Pretende ver a lista a nível global(%sG%s) ou a nível de filiais(%sF%s)?%s ", BMAG, BGREEN, BMAG, BGREEN, BMAG, RESET);
        char gt4a;
        scanf(" %c",&gt4a);
            if(gt4a=='G'){
                /*printprodutosNAOvendidos(factur);*/
                jump37:
                printf("faz de conta que isto e a lista\n");
                sleep(2);
                    printf("\n%s-------------------------%s",MAG,RESET);
                    printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                    printf("\n%s 1%s - Ver a lista dos produtos não vendidos a nível das filiais.\n",BMAG,RESET);
                    printf("%s 2%s - Saber o número de produtos não vendidos.\n",BMAG,RESET);
                    printf("%s 3%s - Ir para outra querie.\n",BMAG,RESET);
                    printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                    int opt4a;
                    scanf("%d",&opt4a);
                        switch(opt4a){
                            case 1:
                                goto jump34;
                            case 2:
                                goto jump35;
                            case 3:
                                querieTime();
                        }
            }
            else{
                jump34:
                printf("\n%s>>> Pretende ver a lista de produtos não vendidos em que filial: %s1%s, %s2%s ou %s3%s?%s ", BMAG, BGREEN, BMAG, BGREEN, BMAG, BGREEN, BMAG, RESET);
                int filial4b;
                scanf("%d",&filial4b);
                switch(filial4b){
                    case 1:
                        /*printprodutosNAOvendidos_Filial1(Fill1 filial1);*/
                        jump41:
                        printf("pr prod n v filial1\n");
                        sleep(2);
                            printf("\n%s-------------------------%s",MAG,RESET);
                            printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                            printf("\n%s 1%s - Ver a lista dos produtos não vendidos a nível de outra filial.\n",BMAG,RESET);
                            printf("%s 2%s - Saber o número de produtos não vendidos.\n",BMAG,RESET);
                            printf("%s 3%s - Ver a lista dos produtos não vendidos a nível global.\n",BMAG,RESET);
                            printf("%s 4%s - Ir para outra querie.\n",BMAG,RESET);
                            printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                            int opt4b;
                            scanf("%d",&opt4b);
                                switch(opt4b){
                                    case 1:
                                        goto jump34;
                                    case 2:
                                        goto jump36;
                                    case 3:
                                        goto jump37;
                                    case 4:
                                        querieTime();
                                }
                    case 2:
                        /*printprodutosNAOvendidos_Filial2(Fill2 filial2);*/
                        jump42:
                        printf("pr prod n v filial2\n");
                        sleep(2);
                            printf("\n%s-------------------------%s",MAG,RESET);
                            printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                            printf("\n%s 1%s - Ver a lista dos produtos não vendidos a nível de outra filial.\n",BMAG,RESET);
                            printf("%s 2%s - Saber o número de produtos não vendidos.\n",BMAG,RESET);
                            printf("%s 3%s - Ver a lista dos produtos não vendidos a nível global.\n",BMAG,RESET);
                            printf("%s 4%s - Ir para outra querie.\n",BMAG,RESET);
                            printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                            int opt4c;
                            scanf("%d",&opt4c);
                                switch(opt4c){
                                    case 1:
                                        goto jump34;
                                    case 2:
                                        goto jump38;
                                    case 3:
                                        goto jump37;
                                    case 4:
                                        querieTime();
                                }
                    case 3:
                        /*printprodutosNAOvendidos_Filial3(Fill3 filial3);*/
                        jump43:
                        printf("pr prod n v filial3\n");
                        sleep(2);
                            printf("\n%s-------------------------%s",MAG,RESET);
                            printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                            printf("\n%s 1%s - Ver a lista dos produtos não vendidos a nível de outra filial.\n",BMAG,RESET);
                            printf("%s 2%s - Saber o número de produtos não vendidos.\n",BMAG,RESET);
                            printf("%s 3%s - Ver a lista dos produtos não vendidos a nível global.\n",BMAG,RESET);
                            printf("%s 4%s - Ir para outra querie.\n",BMAG,RESET);
                            printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                            int opt4d;
                            scanf("%d",&opt4d);
                                switch(opt4d){
                                    case 1:
                                        goto jump34;
                                    case 2:
                                        goto jump39;
                                    case 3:
                                        goto jump37;
                                    case 4:
                                        querieTime();
                                }
                }
            }
    }
    /*nr de produtos*/
    else{
        printf("\n%s>>> Pretende saber o número de produtos não vendidos a nível global(%sG%s) ou a nível de filiais(%sF%s)?%s ", BMAG, BGREEN, BMAG, BGREEN, BMAG, RESET);
        char gt4b;
        scanf(" %c",&gt4b);
            if(gt4b=='G'){
                int nrNVG = numero_produtosNAOvendidos(factur);
                jump35:
                printf("O número de produtos não vendidos a nível global é %s%d%s.\n",BGREEN,nrNVG,RESET);
                sleep(2);
                    printf("\n%s-------------------------%s",MAG,RESET);
                    printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                    printf("\n%s 1%s - Saber o número de produtos não vendidos a nível das filiais.\n",BMAG,RESET);
                    printf("%s 2%s - Ver a lista dos produtos não vendidos.\n",BMAG,RESET);
                    printf("%s 3%s - Ir para outra querie.\n",BMAG,RESET);
                    printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                    int opt4a;
                    scanf("%d",&opt4a);
                        switch(opt4a){
                            case 1:
                                goto jump40;
                            case 2:
                                goto jump37;
                            case 3:
                                querieTime();
                        }
            }
            else{
                jump40:
                printf("\n%s>>> Pretende saber o número de produtos não vendidos em que filial: %s1%s, %s2%s ou %s3%s?%s ", BMAG, BGREEN, BMAG, BGREEN, BMAG, BGREEN, BMAG, RESET);
                int filial4b;
                scanf("%d",&filial4b);
                switch(filial4b){
                    case 1:
                        /*int nrNVF1 = numero_produtosNAOvendidos_Filial1(Fill1 filial1);
                        printf("O número de produtos não vendidos na filial 1 é %d.\n", nrNVF1);*/
                        jump36:
                        printf("O número de produtos não vendidos na filial 1 é isto\n");
                        sleep(2);
                            printf("\n%s-------------------------%s",MAG,RESET);
                            printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                            printf("\n%s 1%s - Saber o número de produtos não vendidos a nível de outra filial.\n",BMAG,RESET);
                            printf("%s 2%s - Ver a lista dos produtos não vendidos\n",BMAG,RESET);
                            printf("%s 3%s - Saber o número de produtos não vendidos a nível global.\n",BMAG,RESET);
                            printf("%s 4%s - Ir para outra querie.\n",BMAG,RESET);
                            printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                            int opt4b;
                            scanf("%d",&opt4b);
                                switch(opt4b){
                                    case 1:
                                        goto jump40;
                                    case 2:
                                        goto jump41;
                                    case 3:
                                        goto jump35;
                                    case 4:
                                        querieTime();
                                }
                    case 2:
                        /*int nrNVF2 = numero_produtosNAOvendidos_Filial2(Fill2 filial2);
                        printf("O número de produtos não vendidos na filial 2 é %d.\n", nrNVF2);*/
                        jump38:
                        printf("O número de produtos não vendidos na filial 2 é isto");
                        sleep(2);
                            printf("\n%s-------------------------%s",MAG,RESET);
                            printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                            printf("\n%s 1%s - Saber o número de produtos não vendidos a nível de outra filial.\n",BMAG,RESET);
                            printf("%s 2%s - Ver a lista dos produtos não vendidos\n",BMAG,RESET);
                            printf("%s 3%s - Saber o número de produtos não vendidos a nível global.\n",BMAG,RESET);
                            printf("%s 4%s - Ir para outra querie.\n",BMAG,RESET);
                            printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                            int opt4c;
                            scanf("%d",&opt4c);
                                switch(opt4c){
                                    case 1:
                                        goto jump40;
                                    case 2:
                                        goto jump42;
                                    case 3:
                                        goto jump35;
                                    case 4:
                                        querieTime();
                                }
                    case 3:
                        /*int nrNVF3 = numero_produtosNAOvendidos_Filial3(Fill3 filial3);
                        printf("O número de produtos não vendidos na filial 3 é %d.\n", nrNVF3);*/
                        jump39:
                        printf("O número de produtos não vendidos na filial 3 é isto");
                        sleep(2);
                            printf("\n%s-------------------------%s",MAG,RESET);
                            printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
                            printf("\n%s 1%s - Saber o número de produtos não vendidos a nível de outra filial.\n",BMAG,RESET);
                            printf("%s 2%s - Ver a lista dos produtos não vendidos\n",BMAG,RESET);
                            printf("%s 3%s - Saber o número de produtos não vendidos a nível global.\n",BMAG,RESET);
                            printf("%s 4%s - Ir para outra querie.\n",BMAG,RESET);
                            printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
                            int opt4d;
                            scanf("%d",&opt4d);
                                switch(opt4d){
                                    case 1:
                                        goto jump40;
                                    case 2:
                                        goto jump43;
                                    case 3:
                                        goto jump35;
                                    case 4:
                                        querieTime();
                                }
            }
    }

/*QUERIE 5*/
case 5:{
  void printcodigos_ordenados(){
  int f; int i; int p=0; int p1=0; int p2=0; int p3=0;
  Fil1 filial1=inicializa_filial_1();
  Fil2 filial2=inicializa_filial_2();
  Fil3 filial3=inicializa_filial_3();
  Vendas_Val x=inicializa_val();
  char** val=val_clientes(x);
  char **d = clientes_compraram_filial1(filial1);
  char **e =clientes_compraram_filial2(filial2);
  char **g =clientes_compraram_filial3(filial3);
  for(i=0;val[i];i++) p++;
  sort(val,p);
  for(i=0;d[i];i++) p1++;
  sort(d,p1);
  for(i=0;e[i];i++) p2++;
  sort(e,p2);
  for(i=0;g[i];i++) p3++;
  sort(g,p3);
  printf("%s\n",val[0]);
  for(f=1; val[f];f++){
    if(strcmp(val[f],val[f-1])!=0 && (binarySearch(d,val[f],p1))==0 && (binarySearch(e,val[f],p2))==0 && (binarySearch(g,val[f],p3))==0)
    printf("%s\n",val[f]);
    }
}
}
/*QUERIE 6*/
case 6:
    break;
/*QUERIE 7*/
case 7:
    break;
/*QUERIE 8*/
case 8:
    printf("\n%s-------------------------%s",MAG,RESET);
    printf("\n\n%sO que pretende? \n%s ", BMAG, RESET);
    printf("\n%s 1%s - Determinar o total de registos de vendas num intervalo fechado de meses.\n",BMAG,RESET);
    printf("%s 2%s - Determinar o total facturado num intervalo fechado de meses.\n",BMAG,RESET);
    printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
    scanf("%d",&querie8_num);
    if (querie8_num==1){
        jump4:
        printf("%s\nSendo que os meses vão de 1 a 12,%s\n ",MAG,RESET);
        printf("\n%s>>> Digite qual o intervalo fechado de meses que pretende%s",BMAG,RESET);
        printf("\n\n%sDesde o mês: %s ",MAG,RESET);
        scanf("%d",&mes1);
        printf("%sAté ao mês:%s ",MAG,RESET);
        scanf("%d",&mes2);
        int nrVendas;
        nrVendas = numero_Vendas_Intervalo(factur,mes1,mes2);
        printf("\nO número de registos de vendas desde o mês %s%d%s até ao mês %s%d%s é %s%d%s.\n",GREEN,mes1,RESET,GREEN,mes2,RESET,BGREEN,nrVendas,RESET);
        sleep(2);
        jump6:
            printf("\n%s-------------------------%s",MAG,RESET);
            printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
            printf("\n%s 1%s - Determinar o total facturado no mesmo intervalo fechado de meses.\n",BMAG,RESET);
            printf("%s 2%s - Determinar o total de registos de vendas noutro intervalo fechado de meses.\n",BMAG,RESET);
            printf("%s 3%s - Determinar o total facturado noutro intervalo fechado de meses.\n",BMAG,RESET);
            printf("%s 4%s - Ir para outra querie.\n ",BMAG,RESET);
            printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
            scanf("%d",&opt8a);
        switch(opt8a){
            case 1:{
                float result8a;
                result8a = totalFaturado_Intervalo(factur,mes1,mes2);
                printf("\nO total faturado desde o mês %s%d%s até ao mês %s%d%s é de %s%f€%s.\n",GREEN,mes1,RESET,GREEN,mes2,RESET,BGREEN,result8a,RESET);
                sleep(2);
                goto jump3;
            }
            case 2:
                goto jump4;
            case 3:
                goto jump5;
            case 4:
                querieTime();
        }
    }
    else{
        jump5:
        printf("%s\nSendo que os meses vão de 1 a 12,%s\n ",MAG,RESET);
        printf("\n%s>>> Digite qual o intervalo fechado de meses que pretende%s",BMAG,RESET);
        printf("\n\n%sDesde o mês: %s ",MAG,RESET);
        scanf("%d",&mesa);
        printf("%sAté ao mês:%s ",MAG,RESET);
        scanf("%d",&mesb);
        float totalFat;
        totalFat = totalFaturado_Intervalo(factur,mesa,mesb);
        printf("\nO total faturado desde o mês %s%d%s até ao mês %s%d%s é de %s%f€%s.\n",GREEN,mesa,RESET,GREEN,mesb,RESET,BGREEN,totalFat,RESET);
        sleep(2);
        jump3:
            printf("\n%s-------------------------%s",MAG,RESET);
            printf("\n\n%sO que pretende agora? \n%s", BMAG, RESET);
            printf("\n%s 1%s - Determinar o total de registos de vendas no mesmo intervalo fechado de meses.\n",BMAG,RESET);
            printf("%s 2%s - Determinar o total facturado noutro intervalo fechado de meses.\n",BMAG,RESET);
            printf("%s 3%s - Determinar o total de registos de vendas noutro intervalo fechado de meses.\n",BMAG,RESET);
            printf("%s 4%s - Ir para outra querie.\n ",BMAG,RESET);
            printf("\n%s>>> Insira o número da opção pretendida:%s ", BMAG, RESET);
            scanf("%d",&opt8b);
        switch(opt8b){
            case 1:{
                int nrVendas2;
                nrVendas2 = numero_Vendas_Intervalo(factur,mesa,mesb);
                printf("\nO número de registos de vendas desde o mês %s%d%s até ao mês %s%d%s é %s%d%s.\n",GREEN,mesa,RESET,GREEN,mesb,RESET,BGREEN,nrVendas2,RESET);
                sleep(2);
                goto jump6;
            }
            case 2:
                goto jump5;
            case 3:
                goto jump4;
            case 4:
                querieTime();
    }
}
/*QUERIE 9*/
case 9:
    break;
//QUERIE 10
case 10:
    break;
//QUERIE 11
case 11:
    break;
//QUERIE 12
case 12:
    break;
}
}
}
}

/*Função que executa os "built-in" commands (podemos criar comandos personalizados)*/
int ownCmdHandler(char** parsed){

    int NoOfOwnCmds = 5, i, switchOwnArg = 0;
    char* ListOfOwnCmds[NoOfOwnCmds];
    char* username;

    ListOfOwnCmds[0] = "exit";
    ListOfOwnCmds[1] = "cd";
    ListOfOwnCmds[2] = "help";
    ListOfOwnCmds[3] = "hello";
    ListOfOwnCmds[4] = "init";
    /*ListOfOwnCmds[5] = "same";*/

    for (i = 0; i < NoOfOwnCmds; i++) {
        if (strcmp(parsed[0], ListOfOwnCmds[i]) == 0) {
            switchOwnArg = i + 1;
            break;
        }
    }

    switch (switchOwnArg) {
    case 1:
        printf("\nAdeus (término da API)\n");
        exit(0);
    case 2:
        chdir(parsed[1]);
        return 1;
    case 3:
        openHelp();
        return 1;
    case 4:
        username = getenv("USER");
        printf("\nOlá %s.\nIsto é o svg de Laboratórios de Informática 3."
            "\nUse ajuda para saber mais.\n",
            username);
        return 1;
    case 5:
        querieTime();
    default:
       break;
    }
return 0;
}

/* function for finding pipe*/
int parsePipe(char* str, char** strpiped)
{
    int i;
    for (i = 0; i < 2; i++) {
        strpiped[i] = strsep(&str, "|");
        if (strpiped[i] == NULL)
            break;
    }

    if (strpiped[1] == NULL)
        return 0; /* returns zero if no pipe is found.*/
    else {
        return 1;
    }
}

/* function for parsing command words*/
void parseSpace(char* str, char** parsed)
{
    int i;

    for (i = 0; i < MAXLIST; i++) {
        parsed[i] = strsep(&str, " ");

        if (parsed[i] == NULL)
            break;
        if (strlen(parsed[i]) == 0)
            i--;
    }
}

int processString(char* str, char** parsed, char** parsedpipe)
{

    char* strpiped[2];
    int piped = 0;

    piped = parsePipe(str, strpiped);

    if (piped) {
        parseSpace(strpiped[0], parsed);
        parseSpace(strpiped[1], parsedpipe);

    } else {

        parseSpace(str, parsed);
    }

    if (ownCmdHandler(parsed))
        return 0;
    else
        return 1 + piped;
}

int main()
{
    char inputString[MAXCOM], *parsedArgs[MAXLIST];
    char* parsedArgsPiped[MAXLIST];
    int execFlag = 0;
    init_shell();
    showQueries();
    querieTime();

     while (1) {
        /* print shell line
        /printDir();*/
        instructions();
        /* take input*/
        if (takeInput(inputString))
            continue;
        /* process*/
        execFlag = processString(inputString,
        parsedArgs, parsedArgsPiped);
        /* execflag returns zero if there is no command
        or it is a builtin command,
        1 if it is a simple command
        2 if it is including a pipe.*/

        /*execute*/
        if (execFlag == 1)
            execArgs(parsedArgs);

        if (execFlag == 2)
            execArgsPiped(parsedArgs, parsedArgsPiped);
    }

    return 0;
}
