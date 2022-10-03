#include <stdio.h>
#include <stdlib.h>
#include "../work5/funcarr.c"

int* concat(int* arr1, int* arr2, size_t size1, size_t size2) {
    arr1 = (int*) realloc(arr1, sizeof(int) * (size1 + size2));
    notNull(arr1);
    for(size_t i = size1; i < size1 + size2; i++) {
        arr1[i] = arr2[i - size1];
    }
    return arr1;
}

int main() {
    int array1[] = {5, 4, 3, 2, 1, 0}, array2[] = {6, 7, 8, 9};
    printArr(concat(array1, array2, 6, 4), 10);
    return 0;
}
