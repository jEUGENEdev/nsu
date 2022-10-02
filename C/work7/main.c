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
    return 0;
}
