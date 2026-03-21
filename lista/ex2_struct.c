#include "stdio.h"
#include "stdlib.h"

typedef struct no{
    int valor;
    struct no* prox;
}no;

//prototipos das funcoes
void imprime(no*);

int main(){
    no *lista;

    //criando 3 nós
    no* v1 = (no*)malloc(sizeof(no));
    no* v2 = (no*)malloc(sizeof(no));
    no* v3 = (no*)malloc(sizeof(no));

    lista = v1;

    //dando valor
    v1->valor = 10;
    v2->valor = 25;
    v3->valor = 7;

    //ligacao manual
    v1->prox = v2;
    v2->prox = v3;
    v3->prox = NULL;

    //imprime
    imprime(lista);

    free(v1);
    free(v2);
    free(v3);
    
}

void imprime(no* l){
    if(l == NULL){
        printf("Fim da lista\n");
        return;
    }
    printf("%d\n",l->valor);
    imprime(l->prox);
}