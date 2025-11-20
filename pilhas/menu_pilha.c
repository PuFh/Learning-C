#include <stdio.h>
#include <stdlib.h>

#define TAMA_PILHA 20

typedef struct {
    int vet_p[TAMA_PILHA];
    int topo;
}Pilha;

//prototipo das funcaoes
void empilhar(int valor, Pilha *pilha);
void desempilhar(Pilha *pilha);
int isCheia(Pilha *pilha);
int isVazia(Pilha *pilha);
void imprimePilha(Pilha *pilha);

//----------FUNCAO PRINCIPAL----------------
int main(){
    Pilha p;//dekcara uma pilha
    p.topo = 0;

    char opcao;
    int valor;
    //--------MENU
    

    

    while (opcao != 'x'){
        printf("\n");
        printf("\t a: adiciona elemento\n\t r: remove elemento\n\t s: exibe elementos\n\t t: exibe o numero de elementos\n\t x: encerra o programa\n");
        scanf(" %c",&opcao);
        switch (opcao)
        {
        case 'a'://adiciona
            printf("Valor: ");
            scanf("%d",&valor);

            empilhar(valor, &p);

        break;

        case 'r'://remove
            
            desempilhar(&p);
        break;

        case 's'://exibe elementos
            printf("---Pilha----\n");
            imprimePilha(&p);
        break;

        case 't'://exibe o numero de elementos
            printf("Elementos: %d",p.topo);
        break;

        case 'x': //encerra
            return 1;
        break;

        default:
            printf("Opcao invalida, digite outra letra.");
            break;
        }

    }
    
}
//Funcao empilhar
void empilhar(int valor, Pilha *pilha){
    
    //verifica se a pilha esta cheia
    if(TAMA_PILHA > pilha->topo){
        //empilhar
        pilha->vet_p[pilha->topo] = valor;
        pilha->topo++;

    }
    else{
        printf("Nao ha mais espaco naa pilha!");
    }

}
//Funcao desempilhar
void desempilhar(Pilha *pilha){
    
    //testa se a pilha esta vazia
    if(pilha->topo >0){
        pilha->topo--;//vc n realmente tirou algo, mais voltou uma posicao, isso faz com que a proximo valor digitado seja escrito em cima do valor que vc deseja retirar
        printf("Elemento retirado: %d\n", pilha->vet_p[pilha->topo]);
    }
    else{
        printf("A pilha esta vazia!");
    }
}

//verificar se esta cheia
int isCheia(Pilha *pilha){
    if(pilha->topo >= TAMA_PILHA){
        return 1;
    }
    else{
        return 0;
    }
}
//verificar se esta vazia
int isVazia(Pilha *Pilha){
    if(Pilha->topo == 0){
        return 1;
    }else{
        return 0;
    }
}
//imprime a pilha
void imprimePilha(Pilha *pilha){
    int i;
    for(i = pilha->topo-1; i >= 0; i--){//começa de cima para baixo
        printf("%d\n",pilha->vet_p[i]);
    }
}