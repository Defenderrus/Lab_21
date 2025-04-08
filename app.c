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
    string result;
    result = new(result, first.len+second.len);
    strcpy(result.data, first.data);
    strcat(result.data, second.data);
    return result;
}

string substring(string original, int i, int j) {
    if (i >= 0 && i <= j && j < original.len) {
        string result;
        result = new(result, j-i+1);
        strncpy(result.data, original.data+i, j-i+1);
        return result;
    }
    printf("Incorrect input data!\n");
    exit(-1);
}

string upper(string original) {
    string result;
    result = new(result, original.len);
    for (int i = 0; i < original.len; i++) {
        result.data[i] = toupper(original.data[i]);
    }
    return result;
}

string lower(string original) {
    string result;
    result = new(result, original.len);
    for (int i = 0; i < original.len; i++) {
        result.data[i] = tolower(original.data[i]);
    }
    return result;
}
