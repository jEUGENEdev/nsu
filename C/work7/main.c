#include <stdio.h>
#include <stdlib.h>
#include "../work5/funcarr.c"

void task1() {
    int N;
    scanf("%d", &N);
    int* b = malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &b[i]);
    }
    printArr(b, N);
    scanArr(b, N);
    printArr(b, N);
    revertArr(b, N);
    maxInArr(b, N);
    printf("%d\n", findInArr(b, N, 3));
    extractDigits(b, N, 1234);
    printf("%d", compareArrays(b, b, N, N));
    free(b);
}

void copy(int* arr, int* cp, size_t size) {
    for(size_t i = 0; i < size; i++) {
        cp[i] = arr[i];
    }
}

// Allocates a little bit of memory
void pickUp(int* arr, size_t size) {
    int* g = malloc(sizeof(int) * (size - 1));
    copy(arr, g, size - 1);
    free(arr);
    arr = malloc(sizeof(int) * size);
    copy(g, arr, size - 1);
    free(g);
}

void task2() {
    int n;
    scanf("%d", &n);
    size_t size = 0;
    int* m = malloc(sizeof(int));
    while(n != 0) {
        size++;
        pickUp(m, size);
        m[size - 1] = n;
        scanf("%d", &n);
    }
    printArr(m, size);
}

int main() {
//    task1();
    task2();
    return 0;
}
