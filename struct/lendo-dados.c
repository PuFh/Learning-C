#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Criando um novo tipo de dados em C com Typedef struct

//segue o exemplo da AULA PASSADA
typedef struct{ 
    int idade;
    char sexo;
    char nome[100];

}Pessoa;

int main() {
    Pessoa pessoa1;

    //leitura dos dados
    printf("Digite seu nome: ");
    fgets(pessoa1.nome, 100, stdin); //file get string
    printf("Digite a sua idade:");
    scanf("%d,", &pessoa1.idade);
    printf("Digite f ou m o seu sexo: ");
    scanf(" %c",&pessoa1.sexo);

    printf("\nNome: %sIdade: %d\nSexo: %c",pessoa1.nome, pessoa1.idade, pessoa1.sexo);
    
    return 0;
}

