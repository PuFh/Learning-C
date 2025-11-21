#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int dado;
    struct lista *prox;//aloca conforme a nossa necessidade
}celula;

void imprimir();
void push(int);
void pop();

celula *top = NULL;

int main(){
    int n, opcao;

    do
    {
        printf("\nStack Menu\n1. Empilhar\n2. Desempilhar\n3. Imprimir\n0. Exit");
        printf("\nEscolha uma opcao 0-3: ");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
        case 1://push
            printf("Valor: ");
            scanf("%d",&n);
            push(n);
            break;
        case 2://pop

            break;
        case 3://print
        
            break;
        case 0://X
        
            break;
        
        default:
            printf("Valor invalido!");
            
            break;
        }
    } while (opcao !=0);
    

}

void push(int item){
    printf("======EMPILHANDO========");
    celula *novo;

    novo = malloc(sizeof(celula));
    novo->dado = item;
    novo->prox = top;//aponta para onde era o topo
    top = novo; //atualiza o novo topo, que faz com que aponte para o novo elemento

    printf("\nValor %d empilhado",novo->dado);
    printf("\n======================\n");
}
void pop(){
    printf("\n======DESEMPILHANDO========\n");
    if (top == NULL){
       printf("PIlha Vazia!");
    }else{
        celula *temp;
        temp = top;
        top = top->prox;
        printf("\n%d desempilhado ",temp->dado);
        free(temp);
    }
    printf("=====================");
}
void imprimir(){
    celula *temp;
    temp = top;
    printf("\n=====IMPRIMINDO PILHA=======\n");
    while (temp != NULL){
        printf("\n%d",temp->dado);
        temp = temp->prox;
        
    }
    
    
}

