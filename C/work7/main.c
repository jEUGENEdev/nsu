#include <stdio.h>
#include <stdlib.h>
#include "../work5/funcarr.c"

int main() {
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
    return 0;
}
