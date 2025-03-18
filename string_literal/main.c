#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *literal = "string literal, readonly";
    char array[] = "string array";
    char *s = strdup(literal);
    array[0] = '#';
    s[0] = '#';

    printf("%s\n", literal);
    printf("%s\n", s);
    printf("%s\n", array);

    free(s);
    printf("%s\n", literal);
    printf("%s\n", s);

    return 0;
}