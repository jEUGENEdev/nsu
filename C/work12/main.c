#include <stdio.h>
#include <stdlib.h>
#include "string.c"

int main() {
    String a = newString("Hello World!");
    String b = stringCopy(a);
    toString(b);
    return 0;
}
