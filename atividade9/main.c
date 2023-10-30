#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    float valor;
    struct No* proximo;
} No;

typedef struct Lista {
    No* primeiro;
} Lista;

void lista_inserir_no_ordenado(Lista* lista, float valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;

    if (lista->primeiro == NULL || valor < lista->primeiro->valor) {
        novoNo->proximo = lista->primeiro;
        lista->primeiro = novoNo;
    } else {
        No* atual = lista->primeiro;
        while (atual->proximo != NULL && atual->proximo->valor <= valor) {
            atual = atual->proximo;
        }
        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }
}

int main() {
    Lista lista_nao_ordenada = {NULL};
    Lista lista_ordenada = {NULL};

    // Abra o arquivo e leia os números linha por linha
    FILE* arquivo = fopen("1kk_rand_float.csv", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    char linha[10];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        float numero = strtof(linha, NULL);
        lista_inserir_no_ordenado(&lista_nao_ordenada, numero);
        lista_inserir_no_ordenado(&lista_ordenada, numero);
    }

    fclose(arquivo);

    // Realize o cálculo do tempo médio de inserção nas listas e compare os tempos

    return 0;
}
