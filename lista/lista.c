#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
}No;


//inserir inicio
int inserirIn(No **cabeca, int v){

    No *novo = (No*)malloc(sizeof(No));

    if(novo != NULL){
        novo->valor = v;
        novo->prox = (*cabeca);
        (*cabeca) = novo;

        return 1;

    }
    return 0;
}
int inserirFim(No **cabeca, int v){
    No *novo = (No*)malloc(sizeof(No));

    No *auxiliar;
    //lista eh vazia?
    if((*cabeca) = NULL){
        auxiliar->valor = v;
        auxiliar->prox = NULL;

        return 1;
    }
    //nao eh vaziar, agora iremos percorrer ate o final

    auxiliar = *cabeca;
    while(auxiliar->prox != NULL){
        auxiliar = auxiliar->prox;
    }
    // auxiliar->valor = v; 
    // auxiliar->prox = NULL;
    
    auxiliar->valor = v;
    auxiliar->prox = (*cabeca);
    (*cabeca)->prox = NULL;

}

void imprimir(No *lista_temp){
    No *auxiliar;
    auxiliar = lista_temp;
    //conferindo se existe um endereco no auxiliar
    if(auxiliar == NULL){
        printf("Nao existe valores nesta lista!");
    }

    while(auxiliar != NULL){
        printf(" |%d| \n",auxiliar->valor);
        auxiliar = auxiliar->prox;
    }

}

int main(){
    No *lista;
    lista = NULL;


    inserirIn(&lista, 15);
    inserirIn(&lista, 21);
    inserirIn(&lista, 24);
    printf("teste0");
    imprimir(lista);
    inserirFim(&lista, 12);
    imprimir(lista);

    return 0;
}