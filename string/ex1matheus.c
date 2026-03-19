#include <stdio.h>

int main(){
    char string[] = "Matheus";
    int i = 0;
    int tamanho = 0;
    while(string[i] != '\0'){
        tamanho++;
    }
    printf("tamanho: %d", tamanho);
}