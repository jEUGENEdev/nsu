#include <stdio.h>
#include <inttypes.h>

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
    int a = INT32_MIN;
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] > a) {
            a = arr[i];
        }
    }
    printf("%d\n", a);
}

int findInArr(int* arr, size_t arrSize, int x) {
    for(size_t i = 0; i < arrSize; i++) {
        if(arr[i] == i) {
            return (int) i;
        }
    }
    return -1;
}

int main() {
    size_t arrLen = 4;
    int array[arrLen];
    scanArr(array, arrLen);
    printArr(array, arrLen);
    revertArr(array, arrLen);
    printArr(array, arrLen);
    maxInArr(array, arrLen);
    printf("%d\n", findInArr(array, arrLen, 5));
    return 0;
}