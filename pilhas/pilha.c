#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    Data data;
    char nome[50];

}Pessoa;

typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;

Pessoa ler_pessoa(){
    Pessoa p;
    scanf("%d%d%d",&p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

void imprimirPessoa(Pessoa p){
    printf("\tData nas: %d/%d/%d\n\n",p.data.dia, p.data.mes, p.data.ano);
}

//FUncao de empilhar
*** empilhar(No *topo){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->p = ler_pessoa();
        novo->proximo = topo;

        return novo;
    }else{
        printf("\nErro ao alocar memoria...\n");

        return NULL;
    }
}

int main(){
    No *topo = NULL;
    int opcao;

    do{
        printf("\n) - Sair\n1 - Empilha\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d",&opcao);
        getchar();

        switch(opcao){
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            default:

                break;;
        }
    }
}