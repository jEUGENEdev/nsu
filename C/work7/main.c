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

void mallocNotNull(int* a) {
    if(a == NULL) {
        printf("OutOfMemory");
        exit(1);
    }
}

void task2() {
    int* array = NULL;
    size_t size = 0;
    int n = 1;
    while(n != 0) {
        scanf("%d", &n);
        int* arr = (int*) malloc(sizeof(int) * ++size);
        for(size_t i = 0; i < (size - 1); i++) {
            arr[i] = array[i];
        }
        free(array);
        array = arr;
        array[size - 1] = n;
    }
    printArr(array, size);
}

int main() {
//    task1();
    task2();
    return 0;
}
