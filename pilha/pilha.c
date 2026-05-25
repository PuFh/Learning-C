#include <stdlib.h>
#include <stdio.h>

typedef struct No{
    int valor;
    struct No* prox;
}No;

No* criaNo(int);
//push, empilhar no topo
No* push(No*, int);
//pop, remover do topo
No* pop(No*);
//imprime
void imprime(No*);


int main(){
    No* pilha = NULL;

    pilha = push(pilha, 14);
    pilha = push(pilha, 17);
    pilha = push(pilha, 12);
    imprime(pilha);
    pilha = pop(pilha);
    imprime(pilha);

    return 0;
}

No* criaNo(int v){

    No* novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro ao alocar memoria!");
        return NULL;
    }
    novo->valor = v;
    novo->prox = NULL;

    return novo;
}
No* push(No* topo, int v){
    
    No* novo = criaNo(v);

    novo->prox = topo;

    return novo;//virou o topo agora

}

No* pop(No* topo){
    //pilha vazia
    if(topo ==  NULL){
        printf("Nao ha valores dentro da pilha.");

        return topo;
    }
    No* atual = topo;

    atual = topo->prox;
    free(topo);
    return atual;
}

void imprime(No* topo){
    if(topo ==  NULL){
        printf("Lista vazia");
        return;
    }
    while(topo != NULL){
        printf("%d -->", topo->valor);
        topo = topo->prox;
    }
    printf("NULL\n");
    return;
}