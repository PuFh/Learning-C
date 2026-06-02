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
void in_ordem(No*);
void imprime(No*);


int main(){
    No* BST = NULL;

    BST = insere(BST, 6);
    BST = insere(BST, 8);
    BST = insere(BST, 9);
    BST = insere(BST, 5);
    busca(BST, 12);// BST n pode receber
    imprime(BST);

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
        printf("Valor %d ja existe na arvore;\n", v);
    }
    return raiz;
}
No* busca(No* raiz, int v){
    if(raiz == NULL){
        printf("Valor nao existe\n");
        return  raiz;   
    }

    if(raiz->valor == v){
        printf("valor encontrado\n");
        return raiz;
    }else if (v < raiz->valor){
        return busca(raiz->esq, v);
    }else if (v > raiz->valor){
        return busca(raiz->dir, v);
    }
    return raiz;
}

void in_ordem(No* raiz){
    //impressao in_ordem
    if(raiz == NULL) return;
    // 1. vai para a esquerda
    in_ordem(raiz->esq);
    // 2. imprime a raiz
    printf(" %d ",raiz->valor);
    // 3. vai para a direita
    in_ordem(raiz->dir);
}
void imprime(No* raiz){
    printf("[");
    in_ordem(raiz);
    printf("]");
}

