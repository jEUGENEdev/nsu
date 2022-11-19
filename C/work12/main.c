#include "string.h"
#include "stringArray.h"
#include <stdio.h>

StringArray* readFileLines(const char* pathFile) {
    StringArray* lines = stringArrayOf();
    FILE* file = fopen(pathFile, "r");
    fileNullCheck(file);
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
    return lines;
}

int main(int argc, char *argv[]) {
    if(argc < 1) {
        interrupt();
    }
    StringArray* lines = readFileLines(argv[1]);
    stringArrayWriteLine(lines);
    return 0;
}
