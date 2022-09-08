#include <stdio.h>
#include <stdio.h>
#include "TadBloco.h"
#include "empilha.h"

/**
* Função que move o bloco a para o bloco b mantendo os blocos em cima dos dois
*/
int pileOver(TLista **l, int b1, int b2, int n){
    TBloco *p1, *p2;
    int pos1, pos2;
    p1 = encontraBloco(l,b1,n,&pos1);   /*Encontrando bloco 1*/
    p2 = encontraBloco(l,b2,n,&pos2);   /*Encontrando bloco 2*/
    if(pos1 == pos2)    /*Verificando se os dois blocos estão na mesma posição, se estiver a função retorna zero*/
        return 0;
    empilha(l,p2,p1);   /*Chama função que irá empilhar os blocos*/
    retiraBloco(l,pos1,p1);  /*Chama função que retira o bloco da posição onde ele foi encontrado*/
    return 1;
}

/**
* Função que move o bloco a para o bloco b retornando todos os blocos sobre b para suas posições originais
*/
int pileOnto(TLista **l, int b1, int b2, int n){
    TBloco *p1, *p2;
    int pos1, pos2;
    p1 = encontraBloco(l,b1,n,&pos1);   /*Encontrando bloco 1*/
    p2 = encontraBloco(l,b2,n,&pos2);   /*Encontrando bloco 2*/
    if(pos1 == pos2)    /*Verificando se os dois blocos estão na mesma posição, se estiver a função retorna zero*/
        return 0;
    if(p2->next != NULL){
        retornaBloco(l,p2);  /*Chama função que retorna os blocos para suas posições originais*/
        empilha(l,p2,p1);   /*Chama função que irá empilhar os blocos*/
        retiraBloco(l,pos1,p1);  /*Chama unção que retira o bloco da posição onde ele foi encontrado*/
    }
    else{
        empilha(l,p2,p1);   /*Chama função que irá empilhar os blocos*/
        retiraBloco(l,pos1,p1);  /*Chama função que retira o bloco da posição onde ele foi encontrado*/
    }
    return 1;
}

/**
* Função que empilha os blocos
*/
void empilha(TLista **l, TBloco *b1, TBloco *b2){
    while(b1){
        if(b1->next == NULL){
            b1->next = b2;
            break;
        }
        b1 = b1->next;
    }
}
