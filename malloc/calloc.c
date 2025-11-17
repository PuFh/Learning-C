#include <stdio.h>
#include <stdlib.h>

    //alocacao dinamica de memoria com a funcao calloc.
int main(){
    int *x;

    //x = malloc(sizeof(int));
    x = calloc(1, sizeof(int));//quantidade parametro que recebe(quantidade de elementos, quantidade de elemento)

    if(x){
        printf("Memoria alocada com sucesso!\n");
        printf("x: %d\n", *x);
        *x = 50;
        printf("x: %d\n", *x);
    }
    else{
        printf("Erro ao alocar memoria!\n");
    }
    return 0;
}