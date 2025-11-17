#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//tipo ELETRÔNICO com TYPEDEF STRUCT

//Struct de struct

typedef struct{
    char tipo[100];
    char marca[50];
    char modelo[25];
    char energia;
    char descricao[500];
    int quantidade;
    int codigo;

}Eletronico;

void imprimirEletronico(Eletronico e){
    printf("\tTipo: %s", e.tipo);
    printf("\tMarca: %s", e.marca);
    printf("\tModelo: %s",e.modelo);
    printf("\tEnergia: %c\tQuantidade: %d",e.energia, e.quantidade);
    printf("\tDescricao: %s", e.descricao);

}
//funcao que le os dados de uma pessoa e torna pra quem chamou
Eletronico lerEletronico(){
    Eletronico e;
    printf("\nDigite o tipo: ");
    fgets(e.tipo, 100, stdin); 
    printf("Digite a marca: ");
    fgets(e.marca, 50, stdin);
    printf("Digite o modelo: ");
    fgets(e.modelo, 25, stdin);
    printf("Eficiencia energetica:");
    scanf("%c", &e.energia);
    scanf("%c");
    printf("Descricao: ");
    fgets(e.descricao, 500, stdin);
    printf("Quantidade e Codigo: ");
    scanf("%d%d", &e.quantidade, &e.codigo);

    return e;
}

int main() {
    Eletronico ele;

    ele = lerEletronico();
    imprimirEletronico(ele);
    
    

    return 0;
}

