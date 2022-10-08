#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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

//int compareArrays(int* arr1, int* arr2, size_t size1, size_t size2) {
//    if(size1 < size2) return -1;
//    else if(size1 > size2) return 1;
//    for(size_t i = 0; i < size1; i++) {
//        if(arr1[i] != arr2[i]) {
//            if(arr1[i] > arr2[i]) return 1;
//            else return -1;
//        }
//    }
//    return 0;
//}

int compareArrays(int* arr1, int* arr2, size_t size1, size_t size2) {
    size_t min = size1 < size2 ? size1 : size2;
    for(size_t i = 0; i < min; i++) {
        if(arr1[i] > arr2[i]) {
            return 1;
        }
        else if(arr1[i] < arr2[i]) {
            return -1;
        }
    }
    if(size1 == size2) return 0;
    return size1 > size2 ? 1 : -1;
}



int main() {
//    size_t arrLen = 4;
//    int array[arrLen];
//    scanArr(array, arrLen);
//    printArr(array, arrLen);
//    revertArr(array, arrLen);
//    printArr(array, arrLen);
//    maxInArr(array, arrLen);
//    printf("%d\n", findInArr(array, arrLen, 5));
//    extractDigits(array, arrLen, 4321);

    int array1[] = {1}, array2[] = {1};
    int arr1[] = {3, 2}, arr2[] = {1, 2, 3};
    int a1[] = {1, 2, 3, 4, 5}, a2[] = {1, 2, 3};
    printf("%d\n", compareArrays(array1, array2, 1, 1));
    printf("%d\n", compareArrays(arr2, arr1, 1, 1));
    printf("%d\n", compareArrays(arr1, arr2, 2, 3));
    printf("%d\n", compareArrays(a1, a2, 5, 3));
    printf("%d", compareArrays(a2, a1, 3, 5));
    return 0;
}