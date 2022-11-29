//
// Created by admin on 19.11.2022.
//

#ifndef WORK12_STRINGARRAY_H
#define WORK12_STRINGARRAY_H
#include "string.h"
#include "utils.h"

typedef struct {
    String** arr;
    size_t length;
    size_t capacity;
} StringArray;



StringArray* stringArrayOf() {
    StringArray* arr = malloc(sizeof(StringArray));
    arr->arr = malloc(sizeof(String*));
    arr->length = 0;
    arr->capacity = 0;
    return arr;
}

void strArrAdd(StringArray* arr, String* el) {
    if(arr->length + 1 > arr->capacity) {
        arr->arr = realloc(arr->arr, sizeof(String*) * (arr->length + 1) * 2);
        arr->capacity = (arr->length + 1) * 2;
    }
    arr->arr[arr->length] = el;
    arr->length += 1;
}

void stringArrayWriteLine(StringArray* arr) {
    for(size_t i = 0; i < arr->length; i++) {
        stringWriteLine(arr->arr[i]);
    }
}
#endif //WORK12_STRINGARRAY_H
