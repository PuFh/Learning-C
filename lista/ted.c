#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>
#include <time.h>   

 
#define MAX_SIZE 10000
#define NUM_TESTES 10#include <iostream>

typedef struct {
    int dados[MAX_SIZE];
    int qtd;
} ListaEstatica;

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct NoDuplo {
    int valor;
    struct NoDuplo *prox;
    struct NoDuplo *ant;
} NoDuplo;

void iniciar_timer(struct tms *t) {
    times(t);
}
#include <iostream>
double parar_timer(struct tms *t_ini, struct tms *t_fim) {
    times(t_fim);
    long clk_tck = sysconf(_SC_CLK_TCK);
    return (double)(t_fim->tms_utime - t_ini->tms_utime +
                    t_fim->tms_stime - t_ini->tms_stime) / clk_tck;
}

void le_inicializa(ListaEstatica *l) {
    l->qtd = 0;
}

void le_insere_inicio(ListaEstatica *l, int v) {
    if (l->qtd >= MAX_SIZE) return;
    for (int i = l->qtd; i > 0; i--) {
        l->dados[i] = l->dados[i-1];
    }
    l->dados[0] = v;
    l->qtd++;
}

void le_insere_fim(ListaEstatica *l, int v) {
    if (l->qtd >= MAX_SIZE) return;
    l->dados[l->qtd] = v;
    l->qtd++;
}

void le_insere_pos(ListaEstatica *l, int v, int pos) {
    if (l->qtd >= MAX_SIZE || pos < 0 || pos > l->qtd) return;
    for (int i = l->qtd; i > pos; i--) {
        l->dados[i] = l->dados[i-1];
    }
    l->dados[pos] = v;
    l->qtd++;
}

void ld_insere_inicio(No **cabeca, int v) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = v;
    novo->prox = *cabeca;
    *cabeca = novo;
}

void ld_insere_fim(No **cabeca, int v) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = v;
    novo->prox = NULL;
    if (*cabeca == NULL) {
        *cabeca = novo;
    } else {
        No *aux = *cabeca;
        while (aux->prox != NULL) aux = aux->prox;
        aux->prox = novo;
    }
}

void ld_insere_pos(No **cabeca, int v, int pos) {
    if (pos == 0) {
        ld_insere_inicio(cabeca, v);
        return;
    }
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = v;
    No *aux = *cabeca;
    for (int i = 0; i < pos - 1 && aux != NULL; i++) {
        aux = aux->prox;
    }
    if (aux != NULL) {
        novo->prox = aux->prox;
        aux->prox = novo;
    } else {
        free(novo);
    }
}

void ld_libera(No **cabeca) {
    No *aux = *cabeca;
    while (aux != NULL) {
        No *prox = aux->prox;
        free(aux);
        aux = prox;
    }
    *cabeca = NULL;
}

void ldd_insere_inicio(NoDuplo **cabeca, int v) {
    NoDuplo *novo = (NoDuplo*) malloc(sizeof(NoDuplo));
    novo->valor = v;
    novo->prox = *cabeca;
    novo->ant = NULL;
    if (*cabeca != NULL) (*cabeca)->ant = novo;
    *cabeca = novo;
}

void ldd_insere_fim(NoDuplo **cabeca, int v) {
    NoDuplo *novo = (NoDuplo*) malloc(sizeof(NoDuplo));
    novo->valor = v;
    novo->prox = NULL;
    if (*cabeca == NULL) {
        novo->ant = NULL;
        *cabeca = novo;
    } else {
        NoDuplo *aux = *cabeca;
        while (aux->prox != NULL) aux = aux->prox;
        aux->prox = novo;
        novo->ant = aux;
    }
}

void ldd_insere_pos(NoDuplo **cabeca, int v, int pos) {
    if (pos == 0) {
        ldd_insere_inicio(cabeca, v);
        return;
    }
    NoDuplo *aux = *cabeca;
    for (int i = 0; i < pos - 1 && aux != NULL; i++) {
        aux = aux->prox;
    }
    if (aux != NULL) {
        NoDuplo *novo = (NoDuplo*) malloc(sizeof(NoDuplo));
        novo->valor = v;
        novo->prox = aux->prox;
        novo->ant = aux;
        if (aux->prox != NULL) aux->prox->ant = novo;
        aux->prox = novo;
    }
}

void ldd_libera(NoDuplo **cabeca) {
    NoDuplo *aux = *cabeca;
    while (aux != NULL) {
        NoDuplo *prox = aux->prox;
        free(aux);
        aux = prox;
    }
    *cabeca = NULL;
}

int main() {
    srand(time(NULL));
    struct tms t_ini, t_fim;

    long total_ini = 0, total_fim = 0, total_pos = 0;

    ListaEstatica le;
    No *ld = NULL;
    NoDuplo *ldd = NULL;

    printf("Iniciando testes (Total acumulado de %d execuções de %d itens)...\n\n", NUM_TESTES, MAX_SIZE);

    printf("%-35s | %-7s | %-7s | %-7s | %-8s | %-8s | %-8s\n",
           "Estrutura", "Tot.Ini", "Tot.Fim", "Tot.Pos", "Menor(s)", "Maior(s)", "Médio(s)");
    printf("--------------------------------------------------------------------------------------------\n");

    double total_t = 0, min_t = 9999.0, max_t = 0.0;
    total_ini = 0; total_fim = 0; total_pos = 0;

    for(int t=0; t<NUM_TESTES; t++) {
        le_inicializa(&le);

        iniciar_timer(&t_ini);
        for(int i=0; i<MAX_SIZE; i++) {
            int val = rand();
            int op = rand() % 3;
            if(op == 0) { le_insere_inicio(&le, val); total_ini++; }
            else if(op == 1) { le_insere_fim(&le, val); total_fim++; }
            else { le_insere_pos(&le, val, rand() % (le.qtd + 1)); total_pos++; }
        }
        double temp = parar_timer(&t_ini, &t_fim);

        total_t += temp;
        if(temp < min_t) min_t = temp;
        if(temp > max_t) max_t = temp;
    }

    printf("%-35s | %-7ld | %-7ld | %-7ld | %-8.4f | %-8.4f | %-8.4f\n",
           "Lista Estática", total_ini, total_fim, total_pos, min_t, max_t, total_t/NUM_TESTES);

    total_t = 0; min_t = 9999.0; max_t = 0.0;
    total_ini = 0; total_fim = 0; total_pos = 0;

    for(int t=0; t<NUM_TESTES; t++) {
        ld_libera(&ld);
        int qtd_atual = 0;

        iniciar_timer(&t_ini);
        for(int i=0; i<MAX_SIZE; i++) {
            int val = rand();
            int op = rand() % 3;
            if(op == 0) { ld_insere_inicio(&ld, val); total_ini++; }
            else if(op == 1) { ld_insere_fim(&ld, val); total_fim++; }
            else { ld_insere_pos(&ld, val, rand() % (qtd_atual + 1)); total_pos++; }
            qtd_atual++;
        }
        double temp = parar_timer(&t_ini, &t_fim);

        total_t += temp;
        if(temp < min_t) min_t = temp;
        if(temp > max_t) max_t = temp;
    }

    printf("%-35s | %-7ld | %-7ld | %-7ld | %-8.4f | %-8.4f | %-8.4f\n",
           "Lista Dinâmica Simples", total_ini, total_fim, total_pos, min_t, max_t, total_t/NUM_TESTES);

    total_t = 0; min_t = 9999.0; max_t = 0.0;
    total_ini = 0; total_fim = 0; total_pos = 0;

    for(int t=0; t<NUM_TESTES; t++) {
        ldd_libera(&ldd);
        int qtd_atual = 0;

        iniciar_timer(&t_ini);
        for(int i=0; i<MAX_SIZE; i++) {
            int val = rand();
            int op = rand() % 3;
            if(op == 0) { ldd_insere_inicio(&ldd, val); total_ini++; }
            else if(op == 1) { ldd_insere_fim(&ldd, val); total_fim++; }
            else { ldd_insere_pos(&ldd, val, rand() % (qtd_atual + 1)); total_pos++; }
            qtd_atual++;
        }
        double temp = parar_timer(&t_ini, &t_fim);

        total_t += temp;
        if(temp < min_t) min_t = temp;
        if(temp > max_t) max_t = temp;
    }

    printf("%-35s | %-7ld | %-7ld | %-7ld | %-8.4f | %-8.4f | %-8.4f\n",
           "Lista Dinâmica Dupla", total_ini, total_fim, total_pos, min_t, max_t, total_t/NUM_TESTES);

    ld_libera(&ld);
    ldd_libera(&ldd);

    return 0;
}
