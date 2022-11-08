typedef struct {
    String* arr;
    size_t length;
    size_t capacity;
} StringArray;

StringArray stringArrayOf() {
    StringArray arr;
    arr.length = 0;
    arr.capacity = 0;
    return arr;
}

void strArrAdd(StringArray* arr, String el) {
    if(arr->length + 1 > arr->capacity) {
        arr->arr = realloc(arr->arr, sizeof(String) * (arr->length + 1) * 2);
        arr->capacity = (arr->length + 1) * 2;
    }
    arr->arr[arr->length] = el;
    arr->length += 1;
}

void arrayToString(StringArray arr) {
    for(size_t i = 0; i < arr.length; i++) {
        toString(arr.arr[i]);
    }
}