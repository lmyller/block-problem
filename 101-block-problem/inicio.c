#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "inicio.h"
#include "TadBloco.h"
#include "empilha.h"
#include "move.h"

/**
* Fun��o que verfifica se o foi aberto ou n�o, retornando zero se n�o foi aberto e um se for aberto
*/
int verificaArquivo(FILE *arq){
    if(!arq){
        printf("\nArquivo n�o pode ser aberto\n");
        return 0;
    }
    return 1;
}

/**
* Fun��o que inicia o programa
*/
int iniciar(){
    FILE *entrada, *saida;
    setlocale(LC_ALL, "portuguese");
    char comando1[5];
    char comando2[5];
    int bloco1;
    int bloco2;
    int n;
    entrada = fopen("entrada.txt", "rt"); /*Abrindo arquivo de entrada*/
    saida = fopen("saida.txt", "w"); /*Criando arquivo de sa�da*/
    if(!verificaArquivo(entrada))
        return 0;
    if(!verificaArquivo(saida))  /*Verificando se o arquivo foi aberto*/
        return 0;
    fscanf(entrada, "%d", &n);  /*Lendo a quantidade de blocos que ser� criado no arquivo de entrada*/
    TLista **l;
    l = criaLista(n);   /*Chama fun��o que ir� criar os blocos*/
    imprimeBlocos(l,n);   /*Chama a fun��o que mostra os blocos*/
    do{
        fscanf(entrada, "%s %d %s %d", comando1, &bloco1, comando2, &bloco2); /*Lendo os comandos no arquivo de entrada*/
        if(bloco1 != bloco2 && (bloco1 < n || bloco2 < n)){   /*Verifica se o bloco 1 � diferente de b2 e se os comandos s�o v�lidos*/
            if((comando1[0] == 'm') && (comando2[1] == 'n')){   /*Verifica quais s�o os comandos*/
                printf("\n%s  %d  %s  %d\n", comando1,bloco1,comando2,bloco2);  /*Mostra os comando recebidos no arquivo de entrada*/
                if(moveOnto(l, bloco1, bloco2, n)==0)   /*Chama a fun��o moveOnto*/
                    printf("\nComando Inv�lido\n");
                imprimeBlocos(l,n);
            }
            if((comando1[0] == 'p') && (comando2[1] == 'v')){   /*Verifica quais s�o os comandos*/
                printf("\n%s  %d  %s  %d\n", comando1,bloco1,comando2,bloco2);  /*Mostra os comando recebidos no arquivo de entrada*/
                if(pileOver(l, bloco1, bloco2, n)==0)   /*Chama fun��o pileOver*/
                    printf("\nComando Inv�lido\n");
                imprimeBlocos(l,n);
            }
            if((comando1[0] == 'p') && (comando2[1] == 'n')){   /*Verifica quais s�o os comandos*/
                printf("\n%s  %d  %s  %d\n", comando1,bloco1,comando2,bloco2);  /*Mostra os comando recebidos no arquivo de entrada*/
                if(pileOnto(l, bloco1, bloco2, n)==0)   /*Chama fun��o pileOnto*/
                    printf("\nComando Inv�lido\n");
                imprimeBlocos(l,n);
            }
            if((comando1[0] == 'm') && (comando2[1] == 'v')){   /*Verifica quais s�o os comandos*/
                printf("\n%s  %d  %s  %d\n", comando1,bloco1,comando2,bloco2);  /*Mostra os comando recebidos no arquivo de entrada*/
                if(moveOver(l, bloco1, bloco2, n)==0)   /*Chama fun��o moveOver*/
                    printf("\nComando Inv�lido\n");
                imprimeBlocos(l,n);
            }
        }
        else
            printf("Comando inv�lido");
    }while(feof(entrada)==0);   /*Sair� do loop no fim do arquivo*/
    imprimeArquivo(saida,l,n);  /*Chama fun��o que imprime os blocos no arquivo de sa�da*/
    return 0;
}
