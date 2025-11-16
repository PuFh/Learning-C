#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//um preocedimento que recebe uma struct como parametro

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

void imprimirPessoa(Pessoa p){
    printf("\tNome: %s",p.nome);
    printf("\tIdade: %d\n", p.idade);
    printf("\tSexo: %c\n",p.sexo);
    printf("\tData nas: %d/%d/%d",p.dataNas.dia, p.dataNas.mes, p.dataNas.ano);
}

int main() {
    Pessoa pessoa;
    DataNas data;
   
    //leitura dos dados
    printf("Digite seu nome: ");
    fgets(pessoa.nome, 100, stdin); //file get string
    printf("Digite a sua idade: ");
    scanf("%d,", &pessoa.idade);
    printf("Digite f ou m o seu sexo: ");
    scanf(" %c",&pessoa.sexo);
    printf("Digite a sua data de nascimento no formado dd mm aaaa: ");
    scanf("%d%d%d",&pessoa.dataNas.dia, &pessoa.dataNas.mes, &pessoa.dataNas.ano);

    imprimirPessoa(pessoa);

    return 0;
}

