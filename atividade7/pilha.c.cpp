#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct Pilha {
    int capacidade;
    int topo;
    int* elementos;
};

Pilha* criarPilha(int capacidade) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->capacidade = capacidade;
    pilha->topo = -1;
    pilha->elementos = (int*)malloc(sizeof(int) * capacidade);
    return pilha;
}

void destruirPilha(Pilha* pilha) {
    free(pilha->elementos);
    free(pilha);
}

int pilhaVazia(Pilha* pilha) {
    return (pilha->topo == -1);
}

int pilhaCheia(Pilha* pilha) {
    return (pilha->topo == pilha->capacidade - 1);
}

void empilhar(Pilha* pilha, int valor) {
    if (pilhaCheia(pilha)) {
        printf("Erro: Pilha cheia\n");
        return;
    }
    pilha->elementos[++pilha->topo] = valor;
}

int desempilhar(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Erro: Pilha vazia\n");
        return -1;
    }
    return pilha->elementos[pilha->topo--];
}
