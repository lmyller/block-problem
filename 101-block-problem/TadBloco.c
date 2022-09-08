#include <stdio.h>
#include <stdlib.h>
#include "TadBloco.h"

/**
* Função que cria o mundo dos blocos e retorna o mundo dos blocos
*/
TLista** criaLista(int n){
    int i;
    TBloco *b;
    TLista **l;
    l = (TLista**)malloc(sizeof(TLista*)*n);    /*Alocando lista*/
    for(i=0;i<n;i++){
        l[i] = (TLista*)malloc(sizeof(TLista)); /*Alocando indexadores da lista*/
        l[i]->numero = i;
        b = (TBloco*)malloc(sizeof(TBloco));    /*Alocando blocos*/
        b->numero = l[i]->numero;
        b->next = NULL;
        l[i]->inicio = b;
        l[i]->fim = b;
    }
    return l;
}


/**
* Função que retorna os blocos para suas posições originais
*/
void retornaBloco(TLista **l, TBloco *b){
    TBloco *p, *aux;
    int pos;
    p = b->next;
    b->next = NULL;
    while(p){
        pos = p->numero;
        l[pos]->inicio = p;
        l[pos]->fim = p;
        aux = p->next;
        p->next = NULL;
        p = aux;
    }
}

/**
* Função que retira os blocs na posição que eles estão
*/
void retiraBloco(TLista **l, int pos, TBloco *b){
    TBloco *p;
    if(l[pos]->inicio == b)
        l[pos]->inicio = NULL;
    else{
        p = l[pos]->inicio;
        while(p){
            if(p->next == b){
                p->next = NULL;
                l[pos]->fim = p;
            }
            p = p->next;
        }
    }
}

/**
* Função que retorna onde o bloco está e também volta a posiçã onde está
*/
TBloco* encontraBloco(TLista **l,int b, int n, int *pos){
    TBloco *p;
    int i;
    for(i=0;i<n;i++){
        p = l[i]->inicio;
        while(p){
            if(p->numero==b){
                *pos = i;
                return p;
            }
            p = p->next;
        }
    }
    return NULL;
}

/**
* Função que imprime os blocos
*/
void imprimeBlocos(TLista **l, int n){
    int i;
    TBloco *p;
    for(i=0;i<n;i++){
        p = l[i]->inicio;
        printf("%d: ", l[i]->numero);
        while(p){
            printf("%d ",p->numero);
            p = p->next;
        }
        printf("\n");
    }
}

/**
* Função que imprime o mundo dos blocos no arquivo de saída
*/
void imprimeArquivo(FILE *saida, TLista **l, int n){
    int i;
    TBloco *p;
    fprintf(saida,"\n");
    for(i=0;i<n;i++){
        p = l[i]->inicio;
        fprintf(saida, " %d: ", l[i]->numero);
        while(p){
            fprintf(saida, "%d ",p->numero);
            p = p->next;
        }
        fprintf(saida, "\n");
    }
}
