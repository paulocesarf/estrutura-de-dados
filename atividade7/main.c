#include <stdio.h>
#include "pilha.h"
#include "fila.h"

int main() {
    Pilha* pilha_desfazer = criarPilha(10);
    Fila* fila_fazer = criarFila(10);

    // simulando a adição de tarefas
    for (int i = 1; i <= 5; i++) {
        printf("Adicionando tarefa %d...\n", i);
        enfileirar(fila_fazer, i);
    }

    // simulando a remoção de tarefas
    int tarefa_desfeita = desenfileirar(fila_fazer);
    printf("Tarefa %d concluída e desfeita.\n", tarefa_desfeita);
    empilhar(pilha_desfazer, tarefa_desfeita);

    // desfazendo a tarefa
    if (!pilhaVazia(pilha_desfazer)) {
        tarefa_desfeita = desempilhar(pilha_desfazer);
        printf("Desfazendo tarefa %d.\n", tarefa_desfeita);
        enfileirar(fila_fazer, tarefa_desfeita);
    } else {
        printf("Nada para desfazer.\n");
    }

    // liberando recursos
    destruirPilha(pilha_desfazer);
    destruirFila(fila_fazer);

    return 0;
}
