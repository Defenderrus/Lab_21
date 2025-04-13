#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "app.h"


string new(char* line) {
    string str;
    if (line) {
        str.len = strlen(line);
        str.data = (char*)malloc((str.len+1)*sizeof(char));
        memcpy(str.data, line, str.len+1);
    } else {
        str.len = 0;
        str.data = (char*)malloc(sizeof(char));
        str.data = "\0";
    }
    return str;
}

string concatenation(string first, string second) {
    int len = first.len+second.len;
    char* data = (char*)malloc((len+1)*sizeof(char));
    memcpy(data, first.data, first.len);
    memcpy(data+first.len, second.data, second.len+1);
    string result = new(data);
    return result;
}

string substring(string original, int i, int j) {
    if (i >= 0 && i <= j && j < original.len) {
        int len = j-i+1;
        char* data = (char*)malloc((len+1)*sizeof(char));
        memcpy(data, original.data+i, len);
        data[len] = '\0';
        string result = new(data);
        return result;
    }
    return new(NULL);
}

string upper(string original) {
    int len = original.len;
    char* data = (char*)malloc((len+1)*sizeof(char));
    for (int i = 0; i < len; i++) {
        data[i] = toupper(original.data[i]);
    }
    data[len] = '\0';
    string result = new(data);
    return result;
}

string lower(string original) {
    int len = original.len;
    char* data = (char*)malloc((len+1)*sizeof(char));
    for (int i = 0; i < len; i++) {
        data[i] = tolower(original.data[i]);
    }
    data[len] = '\0';
    string result = new(data);
    return result;
}

void clear(string* line) {
    if (line->len) {
        free(line->data);
        line->data = NULL;
        line->len = 0;
    }
}
