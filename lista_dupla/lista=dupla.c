#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
   int valor;
   struct no* prox; 
   struct no* ant; 
}no;

//prototipos
no* criaNo(int);
no* insereOrdem(no*,int);
void imprimeLista(no*);

int main(){
    no *lista_dupla;

    return 0;
}

//cria no
no* criaNo(int v){

    no* novo = (no*)malloc(sizeof(no));

    if(novo == NULL){
        printf("ERRO\n");
        return 0;
    }

    novo->valor = v;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

//insere ordem
no* insereOrdem(no* li, int v){
    //lista vazia
    if(li == NULL){
        return criaNo(v);
    }

    //percorrer ate encontrar a posicao q tem que estar
    if(v > li->valor){
        insereOrdem(li->prox, v);
    }
    no* novo = criaNo(v);

    novo->valor = v;
    novo->prox = li->prox;
    novo->ant = li;

    return li;
}