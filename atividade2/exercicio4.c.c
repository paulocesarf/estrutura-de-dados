#include <stdio.h>

int conta_int_array(int arr[], int size, int busca) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == busca) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {5, 7, 9, 6, 7, 11, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int busca = 7;

    int result = conta_int_array(arr, size, busca);
    printf("Quantidade de ocorrências: %d\n", result);

    return 0;
}
