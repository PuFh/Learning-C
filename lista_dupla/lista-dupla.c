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

    lista_dupla = criaNo(8);
    lista_dupla = insereOrdem(lista_dupla, 5);
    lista_dupla = insereOrdem(lista_dupla, 15);
    lista_dupla = insereOrdem(lista_dupla, 12);
    imprimeLista(lista_dupla);

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
    // lista vazia ou chegou no fim
    if(li == NULL){
        return criaNo(v);
    }

    // novo nó vai antes de li
    if(v < li->valor){
        no* novo = criaNo(v);
        novo->prox = li;
        li->ant = novo;
        return novo;
    }

    // continua procurando a posição
    li->prox = insereOrdem(li->prox, v);
    if(li->prox != NULL){
        li->prox->ant = li;
    }
    return li;
}

void imprimeLista(no* li) {
    no* aux = li;
    printf("Lista: ");
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}