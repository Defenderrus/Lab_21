#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"


int main (void) {
    string str = new(str, 13);
    strncpy(str.data, "Hello, world!", 14);
    printf("%s\n", substring(str, 7, 11).data);
    printf("%s\n", upper(str).data);
    printf("%s\n", lower(str).data);

    clear(&str);

    string str1 = new(str1, 5);
    string str2 = new(str2, 8);
    strncpy(str1.data, "Hello", 6);
    strncpy(str2.data, ", world!", 9);
    printf("%s\n", concatenation(str1, str2).data);

    clear(&str1);
    clear(&str2);

    return 0;
}
