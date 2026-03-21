#include "stdio.h"

int main(){

    int a = 42;
    int* p = &a;

    printf("Valor de a: %d\n",*p);

    //mudando variavel a
    *p = 100;

    printf("Valor de a: %d\n",a);

}