#include <stdio.h>

int soma_array(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[] = {5, 7, 9, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = soma_array(arr, size);
    printf("Soma dos elementos: %d\n", result);

    return 0;
}
