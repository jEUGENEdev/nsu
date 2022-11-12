#include "string.c"
#include "stringArray.c"
#include <stdio.h>

int main() {
    StringArray* lines = stringArrayOf();
    char* PATH = "C:/Users/genya/Desktop/file.txt";
    FILE* file = fopen(PATH, "r");
    int ch;
    String* line = stringOf("");
    while((ch = getc(file)) != EOF) {
        if (ch == '\n') {
            strArrAdd(lines, line);
            line = stringOf("");
            continue;
        }
        stringAddChar(line, (char) ch);
    }
    if(line->length != 0) {
        strArrAdd(lines, line);
    }
    stringArrayWriteLine(lines);
    return 0;
}
