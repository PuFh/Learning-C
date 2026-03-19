#include <stdio.h>

int main(){
    int array[10] = {3, 15, 8, 42, 4, 16, 23, 7, 99, 1};

    int maior= array[0];
    int indice=0;
    int i =0;

    while(i < 10){
        if(array[i] > maior){
            maior = array[i];
            indice = i;
        }
        i++;
    }
    printf("maximo %d\n", maior);
    printf("indice: %d\n",indice);

}