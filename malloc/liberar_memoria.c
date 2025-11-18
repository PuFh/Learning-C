#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Como aumentar o tamanho de um vetor com a função realloc?

int main(){
    int i, tam, *vet;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    srand(time(NULL));//sortei numeros de acordo com o horario do SO

    vet = malloc(tam * sizeof(int));

    if (vet){
        //atribuição de valores
        for(i = 0; i < tam; i++){
            *(vet + i) = rand() % 100;
        }
        for(i = 0; i < tam; i++){
            printf(" %d ", *(vet +i ));
        }
        printf("\n");

        printf("Digite o novo tamanho do vetor: ");
        scanf("%d", &tam);

        vet = realloc(vet, tam);

        for(i = 0; i < tam; i++){
            *(vet + i) = rand() % 100;
        }
        for(i = 0; i < tam; i++){
            printf(" %d ", *(vet +i ));
        }
        printf("\n");
        
        free(vet);

        for(i = 0; i < tam; i++){
            printf(" %d ", *(vet +i ));
        }
    }else{
        printf("Erro ao alocar memoria\n");
    }
    


    return 0;
}