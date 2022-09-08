#include <stdio.h>
#include <stdio.h>
#include "TadBloco.h"
#include "empilha.h"
#include "move.h"

/**
* Função que move o bloco para o bloco b retornando todos os blocos sobre os dois para suas posições originais
*/
int moveOnto(TLista **l,int b1, int b2, int n){
    TBloco *p1, *p2;
    int pos1,pos2;
    p1 = encontraBloco(l,b1,n,&pos1);   /*Encontrando bloco1*/
    p2 = encontraBloco(l,b2,n,&pos2);   /*Encontrando bloco 2*/
    if(pos1 == pos2)    /*Verificando se os dois blocos estão na mesma posição, se estiver a função retorna zero*/
        return 0;
    if(p2->next==NULL){
        p2->next = p1;
        if(p1->next != NULL)
            retornaBloco(l,p1); /*Chama função que retorna os blocos para suas posições originais*/
        retiraBloco(l,pos1,p1);  /*Chama função que retira o bloco da posição onde ele foi encontrado*/
        l[pos2]->fim = p1;
    }
    else{
        retornaBloco(l,p2);  /*Chama função que retorna os blocos para suas posições originais*/
        p2->next = p1;
        if(p1->next != NULL)
            retornaBloco(l,p1);  /*Chama função que retorna os blocos para suas posições originais*/
        retiraBloco(l,pos1,p1);  /*Chama função que retira o bloco da posição onde ele foi encontrado*/
        l[pos2]->fim = p1;
    }
    return 1;
}

/**
* Função que move o bloco a para o bloco b retornando todos os blocos sobre a para suas posições originais
*/
int moveOver(TLista **l, int b1, int b2, int n){
    TBloco *p1, *p2;
    int pos1, pos2;
    p1 = encontraBloco(l,b1,n,&pos1);   /*Encontrando bloco 1*/
    p2 = encontraBloco(l,b2,n,&pos2);   /*Encontrando bloco 2*/
    if(pos1 == pos2)    /*Verificando se os dois blocos estão na mesma posição, se estiver a função retorna zero*/
        return 0;
    if(p1->next != NULL){
        retornaBloco(l,p1);  /*Chama função que retorna os blocos para suas posições originais*/
        empilha(l,p2,p1);   /*Chama função que irá empilhar os blocos*/
        retiraBloco(l,pos1,p1);  /*Chama função que retira o bloco da posição onde ele foi encontrado*/
    }
    else{
        if(p2->next == NULL)
            p2->next = p1;
        else
            empilha(l,p2,p1);   /*Chama função que irá empilhar os blocos*/
        retiraBloco(l,pos1,p1);  /*Chama função que retira o bloco da posição onde ele foi encontrado*/
        l[pos2]->fim = p1;
    }
    return 1;
}
