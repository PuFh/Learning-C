#include "stdio.h"
#include "stdlib.h"

typedef struct No{
    int valor;
    struct No* proximo;
}No;

No* alocaNo(int);
void imprimeNo(No*);

int main(){
    No* lista;

    lista = alocaNo(42);
    imprimeNo(lista);
    free(lista);

}

No* alocaNo(int v){
    No* temp = (No*)malloc(sizeof(No));

    if(temp ==NULL){
        printf("Error");
        return NULL;
    }
    temp->valor = v;
    temp->proximo = NULL;

    return temp;
}

void imprimeNo(No* l){
    if(l == NULL){
        printf("Fim da lista");
        return;
    }
    printf("%d\n", l->valor);
    imprimeNo(l->proximo);
}
