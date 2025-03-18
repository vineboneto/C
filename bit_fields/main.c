#include <stdio.h>

struct foo {
    int first_4 : 4;
    int next_4 : 4;
    int alone : 5;
    int rest : 7;
};

int main(void) {
    printf("%zu", sizeof(struct foo));

    return 0;
}