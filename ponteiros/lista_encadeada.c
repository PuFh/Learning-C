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

void inserirInicio(Lista *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;//(*novo).valor = valor(valor do parametro)
    novo->proximo = lista->inicio;
    


}

int main() {
    Lista lista;

    lista.inicio = NULL;
    lista.tam = 0;



    return 0;
}