//
// Created by admin on 19.11.2022.
//

#ifndef WORK12_STRING_H
#define WORK12_STRING_H
#include "utils.h"
#include <string.h>

typedef struct {
    char* str;
    size_t length;
    size_t capacity;
} String;

String* stringOf(char* str) {
    String* string = nullCheck(malloc(sizeof(String)));
    string->length = strlen(str);
    string->capacity = string->length * 2 + 1;
    string->str = nullCheck(malloc(sizeof(char) * string->capacity));
    strcpy(string->str, str);
    return string;
}

void stringWriteLine(String* str) {
    printf("%s", str->str);
    printf("\n");
}

void stringConcat(String* str, String src) {
    size_t newLen = str->length + src.length;
    if(str->capacity < newLen) {
        str->capacity = newLen * 2 + 1;
        str->str = nullCheck(realloc(str->str, sizeof(char) * str->capacity));
    }
    for(size_t i = 0; i <= src.length; i++) {
        str->str[i + str->length] = src.str[i];
    }
    str->length = newLen;
}

void stringAddChar(String* str, char ch) {
    if(str->capacity < str->length + 1) {
        str->capacity = (str->length + 1) * 2 + 1;
        str->str = nullCheck(realloc(str->str, sizeof(char) * str->capacity));
    }
    str->str[str->length++] = ch;
    str->str[str->length] = '\0';
}

String* stringCopy(String src) {
    String* str = stringOf("");
    strcpy(str->str, src.str);
    return str;
}

char stringCharAt(String src, size_t index) {
    if(index >= src.length) interrupt();
    return src.str[index];
}

size_t stringIndexOf(String src, char ch) {
    for(size_t i = 0; i < src.length; i++) {
        if(src.str[i] == ch) {
            return i;
        }
    }
    return -1;
}

void stringFree(String* str) {
    free(str->str);
    free(str);
}
#endif //WORK12_STRING_H
