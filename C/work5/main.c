#include <stdio.h>

void scanArr(int* arr, size_t arrSize) {
    for(size_t i = 0; i < arrSize; i++) {
        scanf("%d", &arr[i]);
    }
}

void printArr(int* arr, size_t arrSize) {
    for(size_t i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void revertArr(int* arr, size_t arrSize) {
    for(size_t i = 0; i < arrSize / 2; i++) {
        int a = arr[i];
        arr[i] = arr[arrSize - 1 - i];
        arr[arrSize - 1 - i] = a;
    }
}

void maxInArr(int* arr, size_t arrSize) {
}

int main() {
    size_t arrLen = 5;
    int array[arrLen];
    scanArr(array, arrLen);
    printArr(array, arrLen);
    revertArr(array, arrLen);
    printArr(array, arrLen);
    return 0;
}