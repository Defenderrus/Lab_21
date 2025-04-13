#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

typedef struct {
    char* data;
    int len;
} string;
string new(char* line);
string concatenation(string first, string second);
string substring(string original, int i, int j);
string upper(string original);
string lower(string original);
void clear(string *line);
int run_tests(void);

#endif // APP_H_INCLUDED