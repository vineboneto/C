#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int (*t_my_func)(int, int);

int foo(int x, int y) { return x * y; }

bool p(int x) { return x % 2 == 0; }

void print_if(int xs[10], bool (*predicate)(int)) {
    for (int i = 0; i < 10; i++) {
        if (predicate(xs[i])) {
            printf("%d\n", xs[i]);
        }
    }
}

int compar(const void *x1, const void *x2) {
    return (*(int *)x1) - (*(int *)x2);
}

int main() {
    int xs[] = {1, 3, 2, 5, 4, 6, 8, 7, 9, 10};

    for (int i = 0; i < 10; i++) {
        printf("%d\n", xs[i]);
    }
    printf("-----------------\n");
    qsort(xs, 10, sizeof(int), compar);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", xs[i]);
    }

    t_my_func f = foo;

    printf("%d\n", f(3, 4));

    return 0;
}