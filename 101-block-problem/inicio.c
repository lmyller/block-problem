#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "inicio.h"
#include "TadBloco.h"
#include "empilha.h"
#include "move.h"

/**
* Função que verfifica se o foi aberto ou não, retornando zero se não foi aberto e um se for aberto
*/
int verificaArquivo(FILE *arq){
    if(!arq){
        printf("\nArquivo não pode ser aberto\n");
        return 0;
    }
    return 1;
}

/**
* Função que inicia o programa
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
    saida = fopen("saida.txt", "w"); /*Criando arquivo de saída*/
    if(!verificaArquivo(entrada))
        return 0;
    if(!verificaArquivo(saida))  /*Verificando se o arquivo foi aberto*/
        return 0;
    fscanf(entrada, "%d", &n);  /*Lendo a quantidade de blocos que será criado no arquivo de entrada*/
    TLista **l;
    l = criaLista(n);   /*Chama função que irá criar os blocos*/
    imprimeBlocos(l,n);   /*Chama a função que mostra os blocos*/
    do{
        fscanf(entrada, "%s %d %s %d", comando1, &bloco1, comando2, &bloco2); /*Lendo os comandos no arquivo de entrada*/
        if(bloco1 != bloco2 && (bloco1 < n || bloco2 < n)){   /*Verifica se o bloco 1 é diferente de b2 e se os comandos são válidos*/
            if((comando1[0] == 'm') && (comando2[1] == 'n')){   /*Verifica quais são os comandos*/
                printf("\n%s  %d  %s  %d\n", comando1,bloco1,comando2,bloco2);  /*Mostra os comando recebidos no arquivo de entrada*/
                if(moveOnto(l, bloco1, bloco2, n)==0)   /*Chama a função moveOnto*/
                    printf("\nComando Inválido\n");
                imprimeBlocos(l,n);
            }
            if((comando1[0] == 'p') && (comando2[1] == 'v')){   /*Verifica quais são os comandos*/
                printf("\n%s  %d  %s  %d\n", comando1,bloco1,comando2,bloco2);  /*Mostra os comando recebidos no arquivo de entrada*/
                if(pileOver(l, bloco1, bloco2, n)==0)   /*Chama função pileOver*/
                    printf("\nComando Inválido\n");
                imprimeBlocos(l,n);
            }
            if((comando1[0] == 'p') && (comando2[1] == 'n')){   /*Verifica quais são os comandos*/
                printf("\n%s  %d  %s  %d\n", comando1,bloco1,comando2,bloco2);  /*Mostra os comando recebidos no arquivo de entrada*/
                if(pileOnto(l, bloco1, bloco2, n)==0)   /*Chama função pileOnto*/
                    printf("\nComando Inválido\n");
                imprimeBlocos(l,n);
            }
            if((comando1[0] == 'm') && (comando2[1] == 'v')){   /*Verifica quais são os comandos*/
                printf("\n%s  %d  %s  %d\n", comando1,bloco1,comando2,bloco2);  /*Mostra os comando recebidos no arquivo de entrada*/
                if(moveOver(l, bloco1, bloco2, n)==0)   /*Chama função moveOver*/
                    printf("\nComando Inválido\n");
                imprimeBlocos(l,n);
            }
        }
        else
            printf("Comando inválido");
    }while(feof(entrada)==0);   /*Sairá do loop no fim do arquivo*/
    imprimeArquivo(saida,l,n);  /*Chama função que imprime os blocos no arquivo de saída*/
    return 0;
}
