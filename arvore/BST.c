#include <stdlib.h>
#include <stdio.h>

//BST = binary search tree
typedef struct No{
    int valor;
    struct No *esq;
    struct No *dir;
}No;

No* criaNo(int);
No* insere(No*,int);
No* busca(No*, int);


int main(){
    No* BST = NULL;


    return 0;
}

No* criaNo(int v){
    No* novo = (No*)malloc(sizeof(No));

    novo->valor = v;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* insere(No* raiz, int v){
    //arvore vazia
    if(raiz ==  NULL){
        No* novo = criaNo(v);
        return novo;
    }
    //valor menor que a raiz
    if(v < raiz->valor){
        raiz->esq = insere(raiz->esq,v);
    }
    else if(v > raiz->valor){
        raiz->dir = insere(raiz->dir, v);
    }else{
        printf("Nao foi possivel alocar valor;");
        return NULL;
    }
    return raiz;
}
No* busca(No* raiz, int v){
    if(raiz == NULL){
        printf("Valor nao existe");
        return  raiz;   
    }

    if(raiz->valor == v){
        printf("valor encontrado");
        return raiz;
    }else if (v < raiz->valor){
        return busca(raiz->esq, v);
    }else if (v > raiz->valor){
        return busca(raiz->dir, v);
    }
    return raiz;
}

