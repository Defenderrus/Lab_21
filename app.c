#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "app.h"


string new(string line, int n) {
    if (n > 0){
        line.data = (char*)malloc((n+1)*sizeof(char));
        line.len = n;
        return line;
    }
    printf("Incorrect input data!\n");
    exit(-1);
}

string concatenation(string first, string second) {
    string result = new(result, first.len+second.len);
    memcpy(result.data, first.data, first.len);
    memcpy(result.data+first.len, second.data, second.len+1);
    return result;
}

string substring(string original, int i, int j) {
    if (i >= 0 && i <= j && j < original.len) {
        int interval = j-i+1;
        string result = new(result, interval);
        memcpy(result.data, original.data+i, interval);
        result.data[interval] = '\0';
        return result;
    }
    printf("Interval is out of range!\n");
    exit(-1);
}

string upper(string original) {
    string result;
    result = new(result, original.len);
    for (int i = 0; i < original.len; i++) {
        result.data[i] = toupper(original.data[i]);
    }
    result.data[original.len] = '\0';
    return result;
}

string lower(string original) {
    string result;
    result = new(result, original.len);
    for (int i = 0; i < original.len; i++) {
        result.data[i] = tolower(original.data[i]);
    }
    result.data[original.len] = '\0';
    return result;
}

void clear(string *line) {
    free(line->data);
    line->data = NULL;
    line->len = 0;
}
