#include <stdarg.h>
#include <stdio.h>

int sum_all(int count, ...) {
    va_list ap;
    va_start(ap, count);

    int sum = 0;
    for (int i = 0; i < count; i++) {
        int x = va_arg(ap, int);
        sum += x;
    }

    va_end(ap);

    return sum;
}

int main(void) {
    printf("%d, %d", 1, 2);

    printf("%d", sum_all(1, 2, 3, 4));

    return 0;
}