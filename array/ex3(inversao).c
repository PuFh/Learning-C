#include <stdio.h>

#define TAM 6

int main(){

    int array[TAM] = {1, 2, 3, 4, 5, 6};
    int ax;
    int m = TAM-1;
    for(int i = 0; i < 3; i++){
        ax = array[i];
        array[i] = array[m];
        array[m] = ax;

       
        m--;
    }
    for(int i = 0; i < 6; i++){
         printf("%d ",array[i]);
    }
}