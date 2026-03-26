#include "stdio.h"
#include "stdlib.h"

typedef struct no{
    int valor;
    struct no* prox;
}no;

//prototipos
no* inserirInicio(int, no*);
void imprime(no*);
no* alocaNo(int, no*);

int main(){
    no* lista;

    lista = alocaNo(10, NULL);
    lista = alocaNo(25, lista);
    lista = alocaNo(7, lista);

    //agora iremos adicioar no inicio
    lista = inserirInicio(99, lista);

    imprime(lista);
}

no* alocaNo(int v, no* l){
    no* temp = (no*)malloc(sizeof(no));

    if(temp == NULL){
        printf("Error");
        return NULL;
    }
    temp->valor = v;
    temp->prox = l;
    return temp;
}
void imprime(no* l){
    if(l == NULL){
        printf("Fim da Lista!");
        return;
    }
    printf("%d\n",l->valor);
    imprime(l->prox);
}

no* inserirInicio(int v, no* l){
    no* inicio = (no*)malloc(sizeof(no));

    if(inicio == NULL){
        printf("Error");
        return NULL;
    }
    inicio->valor = v;
    inicio->prox = NULL;
    return inicio;
}
