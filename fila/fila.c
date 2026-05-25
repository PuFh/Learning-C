#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int valor;
    struct no* prox;
}no;

typedef  struct fila{
    struct no* primeiro;
    struct no* ultimo;
}fila;

fila* inicializacao();
no* criaNo(int);
fila* enqueue(fila*,int);
fila* dequeue(fila*);
void imprime(fila*);


int main(){
    fila* queue = inicializacao();

    queue = enqueue(queue,12);
    queue = enqueue(queue,32);
    queue = enqueue(queue,43);
    imprime(queue);
    queue = dequeue(queue);
    imprime(queue);

    return 0;
}
no* criaNo(int v){
    no* novo = (no*)malloc(sizeof(no));

    novo->valor = v;
    novo->prox = NULL;
    return novo;
}
fila* enqueue(fila* que, int v){
    //lista vazia
    if (que->primeiro == NULL){
        no* novo = criaNo(v);
        que->primeiro = novo;
        que->ultimo = novo;
        return que;
    }

    no* novo = criaNo(v);

   que->ultimo->prox = novo;
   que->ultimo = novo;

   return que;
}

fila* dequeue(fila* que){
    if(que->primeiro == NULL){
        printf("Fila vazia\n");
        return que;
    }
    //faço a ponteiro inicio receber um valor atras
    no* temp = que->primeiro;
    que->primeiro = que->primeiro->prox;

    free(temp);
    return que;
}

void imprime(fila* que){
    no* aux = que->primeiro;

    while(aux != NULL){
        printf("%d -->", aux->valor);
        aux = aux->prox;
    }
    printf("-->NULL\n");
}
fila* inicializacao(){
    fila* queue = (fila*)malloc(sizeof(fila));
    queue->primeiro = NULL;
    queue->ultimo = NULL;
    return queue;
}