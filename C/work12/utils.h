//
// Created by admin on 19.11.2022.
//

#ifndef WORK12_UTILS_H
#define WORK12_UTILS_H
#include <stdlib.h>
#include <stdio.h>

#define CONTAINER(T)    \
typedef struct {        \
    T* data;            \
    size_t length;      \
    size_t capacity;    \
} ##T;

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
#endif //WORK12_UTILS_H
