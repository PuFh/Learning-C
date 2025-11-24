#include <stdio.h>
#include <stdlib.h>


void imprimirVetor(int *v, int tam){
    int i;

    for(i = 0; i < tam; i++){
        printf("%d ", *(v + i));
    }

}

int main(){

    int i, vet[10] = {0,1,2,3,4,5,6,7,8,9};

    //printf("%p\t%p\n", vet, &vet[1]);

    imprimirVetor(vet, 10);

    // for(i = 0; i<10; i++){
    //     printf("%d ", *(vet + i));
    // }



    return 0;
}