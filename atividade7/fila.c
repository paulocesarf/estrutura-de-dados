#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct Fila {
    int capacidade;
    int frente;
    int tras;
    int* elementos;
};

Fila* criarFila(int capacidade) {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->capacidade = capacidade;
    fila->frente = fila->tras = -1;
    fila->elementos = (int*)malloc(sizeof(int) * capacidade);
    return fila;
}

void destruirFila(Fila* fila) {
    free(fila->elementos);
    free(fila);
}

int filaVazia(Fila* fila) {
    return (fila->frente == -1);
}

int filaCheia(Fila* fila) {
    return ((fila->tras + 1) % fila->capacidade == fila->frente);
}

void enfileirar(Fila* fila, int valor) {
    if (filaCheia(fila)) {
        printf("Erro: Fila cheia\n");
        return;
    }
    if (filaVazia(fila)) {
        fila->frente = fila->tras = 0;
    } else {
        fila->tras = (fila->tras + 1) % fila->capacidade;
    }
    fila->elementos[fila->tras] = valor;
}

int desenfileirar(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Erro: Fila vazia\n");
        return -1;
    }
    int valor = fila->elementos[fila->frente];
    if (fila->frente == fila->tras) {
        fila->frente = fila->tras = -1;
    } else {
        fila->frente = (fila->frente + 1) % fila->capacidade;
    }
    return valor;
}
