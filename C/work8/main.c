#include <stdio.h>
#include <stdlib.h>
#include "../work5/funcarr.c"

void concat(int* arr1, int* arr2, size_t size1, size_t size2, int** newArr, size_t* newSize) {
    arr1 = (int*) realloc(arr1, sizeof(int) * (size1 + size2));
    notNull(arr1);
    for(size_t i = size1; i < size1 + size2; i++) {
        arr1[i] = arr2[i - size1];
    }
    *newArr = arr1;
    *newSize = size1 + size2;
}

//// Is the sub array a subarray of the arr array
size_t findSubArr(int* arr, int* sub, size_t size1, size_t size2) {
    if(size2 > size1) return -1;
    if(size1 == size2) return 0;
    char check = 0;
    for(size_t i = 0; i < size1 - size2 + 1; i++) {
        for(size_t j = 0; j < size2; j++) {
            if(sub[j] != arr[i + j]) {
                check = 0;
                break;
            }
            else {
                check = 1;
            }
        }
        if(check) {
            return i;
        }
    }
    return -1;
}

void removeSubArr(int* arr, int* remove, size_t size1, size_t size2, size_t* newSize) {
    size_t n;
    while((n = findSubArr(arr, remove, size1, size2)) != -1) {
        for(size_t i = n; i < n + size2; i++) {
            // View in ../work5/funcarr.c
            delete(arr, n, size1--);
        }
    }
    *newSize = size1;
}

// scanArr already exists in funcarr.c
void arrScan(int* arr, size_t* size, size_t* capacity) {
    int n = -1;
    *size = 1, *capacity = 1;
    scanf("%d", &n);
    arr = malloc(sizeof(int));
    arr[0] = n;
    while(n != 0) {
        scanf("%d", &n);
        if(size >= capacity) {
            arr = realloc(arr, sizeof(int) * *size * 2);
            notNull(arr);
            *capacity = *size * 2;
        }
        *size = *size + 1;
        arr[*size - 1] = n;
    }
    printf("%d\n", arr[0]);
}

int main() {
//    int array1[] = {0, 1, 2, 3, 1, 2, 4}, array2[] = {1, 2};
//    int* concatArr;
//    size_t concatArrSize;
//    concat(fastDymArrInit(array1, 6), fastDymArrInit(array2, 4), 6, 4, &concatArr, &concatArrSize);
//    printArr(concatArr, concatArrSize);

//    printf("%d", (int) findSubArr(fastDymArrInit(array1, 6), fastDymArrInit(array2, 6), 6, 6));

//    int* arr = fastDymArrInit(array1, 7);
//    int* arr1 = fastDymArrInit(array2, 2);
//    size_t newSize;
//    removeSubArr(arr, arr1, 7, 2, &newSize);
//    printf("%d\n", (int) newSize);
//    printArr(arr, newSize);

    int* arr;
    size_t size, capacity;
    arrScan(arr, &size, &capacity);
    printf("%d / %d", (int) size, (int) capacity);
    printArr(arr, size);
}
