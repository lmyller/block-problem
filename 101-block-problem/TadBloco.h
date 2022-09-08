#ifndef TADBLOCO_H_INCLUDED
#define TADBLOCO_H_INCLUDED

/*Estrutura dos blocos*/
typedef struct Bloco{
    int numero;
    struct Bloco *next;
}TBloco;

/*Estrutura da lista*/
typedef struct{
    TBloco *inicio, *fim;
    int numero;
}TLista;

TLista** criaLista(int);
void imprimeBlocos(TLista **,int);
TBloco* encontraBloco(TLista **,int,int,int *);
void retornaBloco(TLista **,TBloco *);
void retiraBloco(TLista **,int,TBloco *);
void imprimeArquivo(FILE *,TLista**,int);

#endif // TADBLOCO_H_INCLUDED
