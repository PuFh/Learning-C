#include "stdio.h"
#include "stdlib.h"

int main(){
    int* p = (int*)malloc(sizeof(int));

    *p = 77;

    printf("Valor: %d",*p);

    free(p);

    p= NULL; 

}