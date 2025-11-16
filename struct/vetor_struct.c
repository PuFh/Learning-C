#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funcao que retorna uma struct

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
//funcao que le os dados de uma pessoa e torna pra quem chamou
Pessoa lerpessoa(){
    Pessoa p;
    printf("Digite seu nome: ");
    fgets(p.nome, 100, stdin); //file get string
    printf("Digite a sua idade: ");
    scanf("%d,", &p.idade);
    printf("Digite f ou m o seu sexo: ");
    scanf(" %c",&p.sexo);
    printf("Digite a sua data de nascimento no formado dd mm aaaa: ");
    scanf("%d%d%d",&p.dataNas.dia, &p.dataNas.mes, &p.dataNas.ano);

    return p;
}

int main() {
    Pessoa pessoa;
    DataNas data;
   
    
    pessoa = lerpessoa();
    imprimirPessoa(pessoa);

    return 0;
}

