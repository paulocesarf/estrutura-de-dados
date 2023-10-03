#ifndef PILHA_H
#define PILHA_H

struct Pilha;

typedef struct Pilha Pilha;

Pilha* criarPilha(int capacidade);
void destruirPilha(Pilha* pilha);
int pilhaVazia(Pilha* pilha);
int pilhaCheia(Pilha* pilha);
void empilhar(Pilha* pilha, int valor);
int desempilhar(Pilha* pilha);

#endif
