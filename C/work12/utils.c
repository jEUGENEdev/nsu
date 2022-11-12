#include <stdlib.h>
#include <stdio.h>

void* nullCheck(void* notNull) {
    if(notNull == NULL) {
        printf("OutOfMemoryException");
        exit(1);
    }
    return notNull;
}

void interrupt() {
    printf("ProgramExecutingException");
    exit(1);
}

void fileNullCheck(FILE* file) {
    if(file == NULL) {
        printf("OpeningStreamFailedException");
        exit(1);
    }
}