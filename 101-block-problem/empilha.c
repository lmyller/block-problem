#include <stdio.h>
#include <stdio.h>
#include "TadBloco.h"
#include "empilha.h"

/**
* Fun��o que move o bloco a para o bloco b mantendo os blocos em cima dos dois
*/
int pileOver(TLista **l, int b1, int b2, int n){
    TBloco *p1, *p2;
    int pos1, pos2;
    p1 = encontraBloco(l,b1,n,&pos1);   /*Encontrando bloco 1*/
    p2 = encontraBloco(l,b2,n,&pos2);   /*Encontrando bloco 2*/
    if(pos1 == pos2)    /*Verificando se os dois blocos est�o na mesma posi��o, se estiver a fun��o retorna zero*/
        return 0;
    empilha(l,p2,p1);   /*Chama fun��o que ir� empilhar os blocos*/
    retiraBloco(l,pos1,p1);  /*Chama fun��o que retira o bloco da posi��o onde ele foi encontrado*/
    return 1;
}

/**
* Fun��o que move o bloco a para o bloco b retornando todos os blocos sobre b para suas posi��es originais
*/
int pileOnto(TLista **l, int b1, int b2, int n){
    TBloco *p1, *p2;
    int pos1, pos2;
    p1 = encontraBloco(l,b1,n,&pos1);   /*Encontrando bloco 1*/
    p2 = encontraBloco(l,b2,n,&pos2);   /*Encontrando bloco 2*/
    if(pos1 == pos2)    /*Verificando se os dois blocos est�o na mesma posi��o, se estiver a fun��o retorna zero*/
        return 0;
    if(p2->next != NULL){
        retornaBloco(l,p2);  /*Chama fun��o que retorna os blocos para suas posi��es originais*/
        empilha(l,p2,p1);   /*Chama fun��o que ir� empilhar os blocos*/
        retiraBloco(l,pos1,p1);  /*Chama un��o que retira o bloco da posi��o onde ele foi encontrado*/
    }
    else{
        empilha(l,p2,p1);   /*Chama fun��o que ir� empilhar os blocos*/
        retiraBloco(l,pos1,p1);  /*Chama fun��o que retira o bloco da posi��o onde ele foi encontrado*/
    }
    return 1;
}

/**
* Fun��o que empilha os blocos
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
