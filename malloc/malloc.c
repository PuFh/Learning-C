#include <stdio.h>
#include <stdlib.h>

    //Retorna um ponteiro para a região de memória alocada ou NULL.
int main(){
    int *x;

    x = malloc(sizeof(int));

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