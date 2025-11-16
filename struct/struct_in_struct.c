#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct de struct
typedef struct{
    int dia, mes, ano;
}DataNas;

typedef struct{
    DataNas dataNas;
    int idade;
    char sexo;
    char nome[100];

}Pessoa;

int main() {
    Pessoa pessoa;

    //leitura dos dados
    printf("Digite seu nome: ");
    fgets(pessoa.nome, 100, stdin); //file get string
    printf("Digite a sua idade: ");
    scanf("%d,", &pessoa.idade);
    printf("Digite f ou m o seu sexo: ");
    scanf(" %c",&pessoa.sexo);
    printf("Digite a sua data de nascimento no formado dd mm aaaa: ");
    scanf("%d%d%d",&pessoa.dataNas.dia, &pessoa.dataNas.mes, &pessoa.dataNas.ano);

    printf("\nNome: %sIdade: %d\nSexo: %c",pessoa.nome, pessoa.idade, pessoa.sexo);
    printf("Data de Nas: %d/%d/%d\n",pessoa.dataNas.dia,pessoa.dataNas.mes,pessoa.dataNas.ano);
    
    return 0;
}

