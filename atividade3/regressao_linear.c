#include <stdio.h>
#include <stdlib.h>

// Struct para armazenar os pontos (x, y)
struct Ponto {
    int x;
    float y;
};

// Função para calcular a regressão linear
void regressaoLinear(struct Ponto pontos[], int n) {
    int somaX = 0;
    float somaY = 0;
    float somaXY = 0;
    float somaXX = 0;

    for (int i = 0; i < n; i++) {
        somaX += pontos[i].x;
        somaY += pontos[i].y;
        somaXY += pontos[i].x * pontos[i].y;
        somaXX += pontos[i].x * pontos[i].x;
    }

    float mediaX = (float)somaX / n;
    float mediaY = somaY / n;

    float a = (n * somaXY - somaX * somaY) / (n * somaXX - somaX * somaX);
    float b = mediaY - a * mediaX;

    printf("Equação da regressão linear: y = %.2fx + %.2f\n", a, b);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_csv>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int maxPontos = 100; // Defina o máximo de pontos apropriado
    struct Ponto *pontos = malloc(maxPontos * sizeof(struct Ponto));

    int n = 0;
    int x;
    float y;
    while (fscanf(file, "%d,%f\n", &x, &y) == 2) {
        pontos[n].x = x;
        pontos[n].y = y;
        n++;
    }

    fclose(file);

    if (n > 0) {
        regressaoLinear(pontos, n);
    } else {
        printf("Nenhum ponto encontrado no arquivo.\n");
    }

    free(pontos);

    return 0;
}

