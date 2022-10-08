#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

void notNull(int* a) {
    if(a == NULL) {
        printf("OutOfMemory");
        exit(1);
    }
}

//// Removes an element from the array by its index
void delete(int* arr, size_t index, size_t size) {
    if(index < 0 || index >= size) return;
    for(size_t i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    realloc(arr, sizeof(int) * (size - 1));
    notNull(arr);
}

int* fastDymArrInit(int* stackArr, size_t size) {
    int* a = malloc(sizeof(int) * size);
    for(size_t i = 0; i < size; i++) {
        a[i] = stackArr[i];
    }
    return a;
}

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
        if(arr[i] == x) {
            return (int) i;
        }
    }
    return -1;
}

void extractDigits(int* arr, size_t arrSize, int x) {
    int cp[arrSize];
    for(size_t i = 0; i < arrSize; i++) {
        cp[i] = arr[i];
    }
    int i = 0;
    while(x != 0) {
        cp[i] = x % 10;
        x /= 10;
        i++;
    }
    revertArr(cp, arrSize);
    printArr(cp, arrSize);
}

int compareArrays(int* arr1, int* arr2, size_t size1, size_t size2) {
    if(size1 < size2) return -1;
    else if(size1 > size2) return 1;
    for(size_t i = 0; i < size1; i++) {
        if(arr1[i] != arr2[i]) {
            if(arr1[i] > arr2[i]) return 1;
            else return -1;
        }
    }
    return 0;
}