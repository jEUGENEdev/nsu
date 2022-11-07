#include "utils.c"
#include <string.h>

typedef struct {
    char* str;
    size_t length;
    size_t capacity;
} String;

String stringOf(const char* str) {
    String string;
    size_t i = strlen(str);
    string.length = i;
    string.str = malloc(sizeof(char) * (i * 2 + 1));
    nullCheck(string.str);
    string.capacity = i * 2 + 1;
    for(size_t j = 0; j <= i; j++) {
        string.str[j] = str[j];
    }
    return string;
}

void toString(String str) {
    for(size_t i = 0; i < str.length; i++) {
        printf("%c", str.str[i]);
    }
    printf("\n");
}

void stringConcat(String* str, String src) {
    size_t newLen = str->length + src.length;
    if(str->capacity < newLen) {
        str->str = realloc(str->str, sizeof(char) * (newLen * 2 + 1));
        nullCheck(str->str);
        str->capacity = newLen * 2 + 1;
    }
    for(size_t i = 0; i <= src.length; i++) {
        str->str[i + str->length] = src.str[i];
    }
    str->length = newLen;
}

String stringCopy(String src) {
    String str;
    str.length = 0;
    stringConcat(&str, src);
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