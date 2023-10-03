#ifndef FILA_H
#define FILA_H

struct Fila;

typedef struct Fila Fila;

Fila* criarFila(int capacidade);
void destruirFila(Fila* fila);
int filaVazia(Fila* fila);
int filaCheia(Fila* fila);
void enfileirar(Fila* fila, int valor);
int desenfileirar(Fila* fila);

#endif
