#include <stdio.h>
#include <stdlib.h>
#include "app.h"


void main () {
    string str;
    str = new(str, 13);
    str.data = "Hello, world!";
    printf("%s\n", substring(str, 7, 11).data);
    printf("%s\n", upper(str).data);
    printf("%s\n", lower(str).data);

    string str1, str2;
    str1 = new(str1, 4);
    str2 = new(str2, 8);
    str1.data = "Hello";
    str2.data = ", world!";
    printf("%s\n", concatenation(str1, str2).data);
}
