#include <stdio.h>

int main() {
    int a[4][4];
    for(size_t i = 0; i < 4; i++) {
        for(size_t j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(size_t i = 1; i < 4; i++) {
        for(size_t j = 0; j < i; j++) {
            int b = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = b;
        }
    }
    for(size_t i = 0; i < 4; i++) {
        for(size_t j = 0; j < 4; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
