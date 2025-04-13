#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

typedef struct {
    char* data;
    int len;
} string;
string new(string line, int n);
string concatenation(string first, string second);
string substring(string original, int i, int j);
string upper(string original);
string lower(string original);
void clear(string *line);

#endif // APP_H_INCLUDED