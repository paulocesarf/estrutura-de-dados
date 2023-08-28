#include <stdio.h>

void multiplica_array(int arr1[], int arr2[], int size, int result[]) {
    for (int i = 0; i < size; i++) {
        result[i] = arr1[i] * arr2[i];
    }
}

int main() {
    int arr1[] = {5, 7, 9, 6};
    int arr2[] = {5, 7, 9, 6};
    int size = sizeof(arr1) / sizeof(arr1[0]);

    int result[size];
    multiplica_array(arr1, arr2, size, result);

    printf("Resultado: [");
    for (int i = 0; i < size; i++) {
        printf("%d", result[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
