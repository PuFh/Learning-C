#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

void inserirInicio(Lista *lista, int v){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = v;
    novo->proximo = lista->inicio;

    //fazendo que o iniciio seja apontado para este novoo no
    lista->inicio = novo;
    lista->tam++;


}

void inserirFim(Lista *lista, int v){
    No *ax,*novo = (No*)malloc(sizeof(No));
    novo->valor = v;

    novo->proximo= NULL;
    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->tam++;
    }else{
        ax = ax->proximo;
        while(ax->proximo != NULL){
            ax = ax->proximo;
        }
        
    }

}

int main() {
    Lista lista;

    lista.inicio = NULL;
    lista.tam = 0;



    return 0;
}