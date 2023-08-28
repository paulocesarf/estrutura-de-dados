#include <stdio.h>
#include <stdlib.h>

int is_prime(int num) {
    if (num <= 1) {
        return 0; // Números menores ou iguais a 1 não são primos
    }
    
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0; // Encontrou um divisor, não é primo
        }
    }
    
    return 1; // Não encontrou divisores, é primo
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }
    
    int num = atoi(argv[1]);
    
    if (is_prime(num)) {
        printf("1 - O numero %d e primo.\n", num);
    } else {
        printf("0 - O numero %d nao e primo.\n", num);
    }
    
    return 0;
}

