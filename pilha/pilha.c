#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia, mes, ano;

}Data;

typedef struct{
    char nome[50];
    Data data;
}Pessoa;

typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;

