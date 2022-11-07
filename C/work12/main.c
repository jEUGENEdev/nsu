#include <stdio.h>
#include <stdlib.h>
#include "string.c"

int main() {
    String a = stringOf("Hello World!");
    printf("%zu", stringIndexOf(a, 'l'));
    return 0;
}
